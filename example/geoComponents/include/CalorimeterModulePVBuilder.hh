#ifndef CalorimeterModulePVBuilder_h
#define CalorimeterModulePVBuilder_h 1

#include "VComponentBuilder.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4VPhysicalVolume;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CalorimeterModulePVBuilder : public VComponentBuilder<G4VPhysicalVolume> {

  public:
    CalorimeterModulePVBuilder(); 
    ~CalorimeterModulePVBuilder();
    
  protected:  
    virtual G4VPhysicalVolume* Build() override; 
         
};

#endif

