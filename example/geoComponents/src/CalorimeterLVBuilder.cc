#include "CalorimeterLVBuilder.hh"
#include "G4LogicalVolume.hh"
#include "MaterialFactory.hh"
#include "LogicalVolumeFactory.hh"
#include "RectangularPatternLVBuilder.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterLVBuilder::CalorimeterLVBuilder(): 
VComponentBuilder()
{       
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterLVBuilder::~CalorimeterLVBuilder()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* CalorimeterLVBuilder::Build()
{
  //MotherLogic 
  G4int numberOfSegmentAlongX = 2;
  G4int numberOfSegmentAlongY = 3;
  G4int numberOfSegmentAlongZ = 4;  
  
  G4double gapX = 7*cm;
  G4double gapY = 2.*cm;
  G4double gapZ = 15*cm;
  
  //GetPattern
	 RectangularPatternLVBuilder rpb(LogicalVolumeFactory::GetInstance()->Get("CalorimeterModule"),
	 															 "Calorimeter",	
								                 MaterialFactory::GetInstance()->Get("G4_Galactic"),
								                 numberOfSegmentAlongX,
								                 numberOfSegmentAlongY,
								                 numberOfSegmentAlongZ,
								                 gapX,
								                 gapY,
								                 gapZ
								                 ); 
                                     
	return rpb.GetProduct();

}


