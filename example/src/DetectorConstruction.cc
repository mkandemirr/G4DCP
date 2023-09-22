#include "DetectorConstruction.hh"
#include "PhysicalVolumeFactory.hh"

#include "G4NistManager.hh"
#include "G4Box.hh"

#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "CalorimeterPVBuilder.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction():
G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	//G4VPhysicalVolume* pv = PhysicalVolumeFactory::GetInstance()->Get("CalorimeterModulePV");	
	G4VPhysicalVolume* pv = PhysicalVolumeFactory::GetInstance()->Get("CalorimeterPV");	
	
	//You can comment out this part.
  // Must place the World Physical volume unrotated at (0,0,0).
  auto worldPV = new G4PVPlacement(nullptr,   // no rotation
											G4ThreeVector(),        // at (0,0,0)
											pv->GetMotherLogical(), // its logical volume
											"WorldPV",              // its name
											nullptr,                // its mother  volume
											false,                  // no boolean operations
											0,                      // copy number
											true);                  // checking overlaps
	
	
	return worldPV;
}

