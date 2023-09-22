
#include "CalorimeterPVBuilder.hh"

#include "G4Material.hh"
#include "MaterialFactory.hh"

#include "G4PVPlacement.hh"

#include "G4Box.hh"

#include "LogicalVolumeFactory.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterPVBuilder::CalorimeterPVBuilder()     
{    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterPVBuilder::~CalorimeterPVBuilder()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* CalorimeterPVBuilder::Build()
{		
 	G4LogicalVolume* calorimeterLV = LogicalVolumeFactory::GetInstance()->Get("Calorimeter"); 
	 
	 //Define world
	G4Box* calorimeterBox = (G4Box*)calorimeterLV->GetSolid();
	
	G4double worldSizeX = 3.3*calorimeterBox->GetXHalfLength();
	G4double worldSizeY = 3.3*calorimeterBox->GetYHalfLength();
	G4double worldSizeZ = 3.3*calorimeterBox->GetZHalfLength();
  
  G4Box* worldBox = new G4Box("World", worldSizeX*0.5, worldSizeY*0.5, worldSizeZ*0.5);
  auto worldLV    = new G4LogicalVolume(worldBox,
  												MaterialFactory::GetInstance()->Get("G4_Galactic"),
  												"WorldLV"
  											);            
                                                                                                                     
  //put calorimeter in the world
   auto calPV = new G4PVPlacement(nullptr,  // no rotation
										G4ThreeVector(),       // at (0,0,0)
										calorimeterLV,               // its logical volume
										"CalorimeterPV",               // its name
										worldLV,               // its mother  volume
										false,                 // no boolean operations
										0,                     // copy number
										true);                 // checking overlaps
 
  return calPV;
		                                      
}


