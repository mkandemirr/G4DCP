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

RectangularPatternLVBuilder::RectangularPatternLVBuilder
(
  G4LogicalVolume* moduleLV,
  const G4String& motherLVName,
  G4Material* motherMaterial,
  G4int numberOfSegmentAlongX,
  G4int numberOfSegmentAlongY,
  G4int numberOfSegmentAlongZ,
  G4double interModuleDistX,
  G4double interModuleDistY,
  G4double interModuleDistZ
):
VComponentBuilder(),
fMessenger{nullptr}, 
fModuleLV{moduleLV},
fMotherLVName{motherLVName},
fMotherMaterial{motherMaterial},
fNumberOfSegmentAlongX{numberOfSegmentAlongX},
fNumberOfSegmentAlongY{numberOfSegmentAlongY},
fNumberOfSegmentAlongZ{numberOfSegmentAlongZ},
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
  G4double motherBoxSizeX = fNumberOfSegmentAlongX*moduleSizeX + 
                            (fNumberOfSegmentAlongX-1)*fInterModuleDistX;
  G4double motherBoxSizeY = fNumberOfSegmentAlongY*moduleSizeY + 
                            (fNumberOfSegmentAlongY-1)*fInterModuleDistY;
  G4double motherBoxSizeZ = fNumberOfSegmentAlongZ*moduleSizeZ + 
                            (fNumberOfSegmentAlongZ-1)*fInterModuleDistZ;
  
  //The sama name for box and logic
  auto motherBox  = new G4Box(fMotherLVName, motherBoxSizeX*0.5, 
    motherBoxSizeY*0.5,motherBoxSizeZ*0.5);
  
  auto motherLV   = new G4LogicalVolume(motherBox, fMotherMaterial, 
    fMotherLVName); 
  
  
  //unit center position coordinates with respect to its mother.
  G4double x{}, y{}, z{};  
  G4int copyNo = 0;
  
  //----------Place Units in MainVol--------------------     

  for(G4int i=0; i<fNumberOfSegmentAlongX; ++i)
  { 
    //x =  -moduleSizeX*(fNumberOfSegmentAlongX-1)*0.5 + i*moduleSizeX;
    x = -(moduleSizeX+fInterModuleDistX)*(fNumberOfSegmentAlongX-1)*0.5 + 
        i*(moduleSizeX+fInterModuleDistX);
   
    //xz layer       
    for(G4int j =0; j<fNumberOfSegmentAlongY; ++j)
    {

      y = -(moduleSizeY+fInterModuleDistY)*(fNumberOfSegmentAlongY-1)*0.5 + 
          j*(moduleSizeY+fInterModuleDistY);

      for(G4int k =0; k<fNumberOfSegmentAlongZ; ++k)
      {      

        z = -(moduleSizeZ+fInterModuleDistZ)*(fNumberOfSegmentAlongZ-1)*0.5 + 
            k*(moduleSizeZ+fInterModuleDistZ); 

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

void RectangularPatternLVBuilder::SetNumberOfSegmentAlongX(G4int nx)
{
  fNumberOfSegmentAlongX = nx;
}

void RectangularPatternLVBuilder::SetNumberOfSegmentAlongY(G4int ny)
{
  fNumberOfSegmentAlongY = ny;
}

void RectangularPatternLVBuilder::SetNumberOfSegmentAlongZ(G4int nz)
{
  fNumberOfSegmentAlongZ = nz;
}
