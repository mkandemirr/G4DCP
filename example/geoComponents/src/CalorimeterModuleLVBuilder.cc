
#include "CalorimeterModuleLVBuilder.hh"
#include "CalorimeterModuleLVMessenger.hh"

#include "G4Material.hh"
#include "MaterialFactory.hh"

#include "G4PVPlacement.hh"


#include "G4Box.hh"


#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "RectangularPatternLVBuilder.hh"
//using namespace CLHEP;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterModuleLVBuilder::CalorimeterModuleLVBuilder(): 
VComponentBuilder(),
fMessenger{nullptr},
fModuleSizeX{10*cm},
fModuleSizeY{5*cm},
absorberMatVec(),
absorberThicknessVec(),
absorberBoxVec(),
absorberLVVec(),
absorberPVVec()        
{    
	fMessenger = new CalorimeterModuleLVMessenger(this);
  
 	G4UImanager* uImanager = G4UImanager::GetUIpointer();
  uImanager->ApplyCommand("/control/execute calorimeterModuleSettings.mac");  
 	    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterModuleLVBuilder::~CalorimeterModuleLVBuilder()
{ 
	delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* CalorimeterModuleLVBuilder::Build()
{
	
	G4int absorberNumber = absorberMatVec.size();
	
	//Set calorimeter module dimensions
  G4double moduleThickness = 0;
  for (G4int i=0; i<absorberNumber; ++i) 
  {
    moduleThickness += absorberThicknessVec.at(i);
  }
 
  //Define calorimeter module box and LV
  G4Box *moduleBox = new G4Box("CalorimeterModuleBox", 
                               fModuleSizeX/2,
                               fModuleSizeY/2,
                               moduleThickness/2
                              );

  G4LogicalVolume* moduleLV  = new G4LogicalVolume(moduleBox,      
                                 MaterialFactory::GetInstance()->Get("G4_Galactic"),   
                                "CalorimeterModule"
                                 );  
                                    
  
  //Define absorbers and place them in the calorimeter module
  G4double zfront = -0.5*moduleThickness;
  for (G4int k=0; k<absorberNumber; ++k) 
  {
  	
  	//Box
  	G4Box* absorberBox = new G4Box("AbsorberBox", 
  													 fModuleSizeX/2, 
  													 fModuleSizeY/2, 
  													 absorberThicknessVec.at(k)/2
  													 );
  													 
    absorberBoxVec.push_back(absorberBox);
    
    //LV
		G4LogicalVolume* absorberLV = new G4LogicalVolume(absorberBoxVec.at(k), //its solid
                                      absorberMatVec.at(k), //its material
                                      absorberMatVec.at(k)->GetName()
                                      );
    
    absorberLVVec.push_back(absorberLV);

		//Placement
    G4double zcenter = zfront+0.5*absorberThicknessVec.at(k);
    zfront += absorberThicknessVec.at(k);
    
    G4VPhysicalVolume* absorberPV = new G4PVPlacement(0,              
																         G4ThreeVector(0.,0.,zcenter),
																         absorberLVVec.at(k),               
																         absorberMatVec.at(k)->GetName(),
																         moduleLV,                  
																         false,                      
																         k
																         ); 
    
    absorberPVVec.push_back(absorberPV);                               

  } 
  
  return moduleLV;                                 
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CalorimeterModuleLVBuilder::AddAbsorber(const G4String& matName, G4double thickness)
{
	G4Material* pttoMaterial = MaterialFactory::GetInstance()->Get(matName);
  
  if (pttoMaterial) {
  	absorberMatVec.push_back(pttoMaterial);
  	}
  	
  absorberThicknessVec.push_back(thickness);	
  	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void CalorimeterModuleLVBuilder::SetModuleSizeX(G4double sizeX)
{
	fModuleSizeX = sizeX;
}

void CalorimeterModuleLVBuilder::SetModuleSizeY(G4double sizeY)
{
 fModuleSizeY = sizeY;
}





