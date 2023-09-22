#include "RectangularPatternLVBuilder.hh"
#include "RectangularPatternLVMessenger.hh"
#include "G4Material.hh"

#include "G4PVPlacement.hh"
#include "G4Box.hh"

#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4UImanager.hh"

//using namespace CLHEP;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RectangularPatternLVBuilder::RectangularPatternLVBuilder(G4LogicalVolume* moduleLV,
																								const G4String& motherLVName,
																								G4Material* motherMaterial,		
									 															G4int numberOfModuleAlongX,
																								G4int numberOfModuleAlongY,
																								G4int numberOfModuleAlongZ,
																								G4double interModuleDistX,
																								G4double interModuleDistY,
																								G4double interModuleDistZ	
																 								):
VComponentBuilder(),
fMessenger{nullptr},																 								
fModuleLV{moduleLV},
fMotherLVName{motherLVName},
fMotherMaterial{motherMaterial},
fNumberOfModuleAlongX{numberOfModuleAlongX},	
fNumberOfModuleAlongY{numberOfModuleAlongY},	
fNumberOfModuleAlongZ{numberOfModuleAlongZ},
fInterModuleDistX{interModuleDistX},
fInterModuleDistY{interModuleDistY},		
fInterModuleDistZ{interModuleDistZ}																		  
{
	fMessenger = new RectangularPatternLVMessenger(this);
	
	G4UImanager* uImanager = G4UImanager::GetUIpointer();
  uImanager->ApplyCommand("/control/execute rpBuilderSettings.mac");   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RectangularPatternLVBuilder::~RectangularPatternLVBuilder()
{ 
	if(fMessenger)
		delete fMessenger;	
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* RectangularPatternLVBuilder::Build()
{
  G4Box* box = (G4Box*)fModuleLV->GetSolid();
  
  G4double moduleSizeX = 2*box->GetXHalfLength();
  G4double moduleSizeY = 2*box->GetYHalfLength();
  G4double moduleSizeZ = 2*box->GetZHalfLength();
  
  //set mother solid dimensions
  G4double motherBoxSizeX = fNumberOfModuleAlongX*moduleSizeX + (fNumberOfModuleAlongX-1)*fInterModuleDistX;
  G4double motherBoxSizeY = fNumberOfModuleAlongY*moduleSizeY + (fNumberOfModuleAlongY-1)*fInterModuleDistY;
  G4double motherBoxSizeZ = fNumberOfModuleAlongZ*moduleSizeZ + (fNumberOfModuleAlongZ-1)*fInterModuleDistZ;
  
  //The sama name for box and logic
  auto motherBox  = new G4Box(fMotherLVName, motherBoxSizeX*0.5, motherBoxSizeY*0.5,motherBoxSizeZ*0.5);
  auto motherLV   = new G4LogicalVolume(motherBox, fMotherMaterial, fMotherLVName); 
  
  
  //unit center position coordinates with respect to its mother.
  G4double x{}, y{}, z{};  
  G4int copyNo = 0;
  
  //----------Place Units in MainVol--------------------    	 

  for(G4int i=0; i<fNumberOfModuleAlongX; ++i)
  { 

		//x =  -moduleSizeX*(fNumberOfModuleAlongX-1)*0.5 + i*moduleSizeX;
    x =  -(moduleSizeX+fInterModuleDistX)*(fNumberOfModuleAlongX-1)*0.5 + i*(moduleSizeX+fInterModuleDistX);
   
    //xz layer       
    for(G4int j =0; j<fNumberOfModuleAlongY; ++j)
    {

      y = -(moduleSizeY+fInterModuleDistY)*(fNumberOfModuleAlongY-1)*0.5 + j*(moduleSizeY+fInterModuleDistY);

      for(G4int k =0; k<fNumberOfModuleAlongZ; ++k)
      {      

        z = -(moduleSizeZ+fInterModuleDistZ)*(fNumberOfModuleAlongZ-1)*0.5 + k*(moduleSizeZ+fInterModuleDistZ); 

        
        new G4PVPlacement(0, 
            G4ThreeVector(x,y,z), 
            fModuleLV, 
            "ModulePV", 
            motherLV, 
            false, 
            copyNo, 
            true
            );
            
       copyNo++;                                     
        
      } //k loop


    }//j loop

  }//i loop
  
  product = motherLV;
  
  return product;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RectangularPatternLVBuilder::SetGapX(G4double interModuleDistX)
{
	fInterModuleDistX = interModuleDistX;
}

void RectangularPatternLVBuilder::SetGapY(G4double interModuleDistY)
{
	fInterModuleDistY = interModuleDistY;
}

void RectangularPatternLVBuilder::SetGapZ(G4double interModuleDistZ)
{
	fInterModuleDistZ = interModuleDistZ;
}

void RectangularPatternLVBuilder::SetNumberOfModuleAlongX(G4int nx)
{
	fNumberOfModuleAlongX = nx;
}

void RectangularPatternLVBuilder::SetNumberOfModuleAlongY(G4int ny)
{
	fNumberOfModuleAlongY = ny;
}

void RectangularPatternLVBuilder::SetNumberOfModuleAlongZ(G4int nz)
{
	fNumberOfModuleAlongZ = nz;
}
