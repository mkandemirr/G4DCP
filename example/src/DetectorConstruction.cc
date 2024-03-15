#include "DetectorConstruction.hh"
#include "PhysicalVolumeFactory.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction():
G4VUserDetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

DetectorConstruction::~DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  //G4VPhysicalVolume* pv = PhysicalVolumeFactory::GetInstance()->
  //                        Get("CalorimeterModulePV");

  G4VPhysicalVolume* pv = PhysicalVolumeFactory::GetInstance()->
                          Get("CalorimeterPV");


  auto worldPV = new G4PVPlacement(nullptr, // no rotation
    G4ThreeVector(),        // at (0,0,0)
    pv->GetMotherLogical(), // its logical volume
    "WorldPV",              // its name
    nullptr,                // its mother  volume
    false,                  // no boolean operations
    0,                      // copy number
    true);                  // checking overlaps


  return worldPV;
}

