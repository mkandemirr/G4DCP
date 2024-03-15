#include "CalorimeterModulePVBuilder.hh"
#include "MaterialFactory.hh"
#include "G4Material.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "LogicalVolumeFactory.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterModulePVBuilder::CalorimeterModulePVBuilder()     
{    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterModulePVBuilder::~CalorimeterModulePVBuilder()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* CalorimeterModulePVBuilder::Build()
{

  G4LogicalVolume* calModuleLV = LogicalVolumeFactory::GetInstance()->
                                 Get("CalorimeterModule"); 

  //Define world
  G4Box* calModuleBox = (G4Box*)calModuleLV->GetSolid();

  G4double worldSizeX = 3.3*calModuleBox->GetXHalfLength();
  G4double worldSizeY = 3.3*calModuleBox->GetYHalfLength();
  G4double worldSizeZ = 3.3*calModuleBox->GetZHalfLength();

  G4Box* worldBox = new G4Box("World", worldSizeX*0.5, worldSizeY*0.5, 
    worldSizeZ*0.5);
  
  auto worldLV = new G4LogicalVolume(worldBox,
    MaterialFactory::GetInstance()->Get("G4_Galactic"),
    "WorldLV"
    );            
                                                                                                                     
  //put calorimeter in the world
  auto calModulePV  = new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),       // at (0,0,0)
    calModuleLV,           // its logical volume
    "CaloimeterModulePV",  // its name
    worldLV,               // its mother  volume
    false,                 // no boolean operations
    0,                     // copy number
    true);                 // checking overlaps

  return calModulePV;
                                      
}


