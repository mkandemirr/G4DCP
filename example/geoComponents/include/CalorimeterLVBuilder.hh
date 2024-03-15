#ifndef CalorimeterLVBuilder_h
#define CalorimeterLVBuilder_h 1

#include "VComponentBuilder.hh"

class G4LogicalVolume;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CalorimeterLVBuilder : public VComponentBuilder<G4LogicalVolume> {

  public:
    CalorimeterLVBuilder(); 
    ~CalorimeterLVBuilder();
    
  protected:  
    virtual G4LogicalVolume* Build() override; 
         
};

#endif

