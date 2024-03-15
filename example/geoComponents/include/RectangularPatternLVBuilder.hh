#ifndef RectangularPatternLVBuilder_h
#define RectangularPatternLVBuilder_h 1

#include "VComponentBuilder.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Material;
class RectangularPatternLVMessenger;
class G4LogicalVolume;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class RectangularPatternLVBuilder : public VComponentBuilder<G4LogicalVolume> {

  public:
    RectangularPatternLVBuilder(G4LogicalVolume* moduleLV,
      const G4String& motherLVName,
      G4Material* motherMaterial,
      G4int numberOfSegmentAlongX =1,
      G4int numberOfSegmentAlongY =1,
      G4int numberOfSegmentAlongZ =1,
      G4double interModuleDistX = 0.,
      G4double interModuleDistY = 0.,
      G4double interModuleDistZ = 0.
      );


 
  ~RectangularPatternLVBuilder();

  protected:  
    virtual G4LogicalVolume* Build() override; 
    
  public:
    //UI commands
    void SetGapX(G4double interModuleDistX);
    void SetGapY(G4double interModuleDistY);
    void SetGapZ(G4double interModuleDistZ);
    void SetNumberOfSegmentAlongX(G4int nx);
    void SetNumberOfSegmentAlongY(G4int ny);
    void SetNumberOfSegmentAlongZ(G4int nz);
    
  private:
    RectangularPatternLVMessenger* fMessenger;

    G4LogicalVolume* fModuleLV;

    G4String fMotherLVName;
    G4Material* fMotherMaterial;

    G4int fNumberOfSegmentAlongX;
    G4int fNumberOfSegmentAlongY;
    G4int fNumberOfSegmentAlongZ;

    G4double fInterModuleDistX;
    G4double fInterModuleDistY;
    G4double fInterModuleDistZ;
     
};

#endif

