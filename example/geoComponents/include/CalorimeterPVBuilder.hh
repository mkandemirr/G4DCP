#ifndef CalorimeterPVBuilder_h
#define CalorimeterPVBuilder_h 1

#include "VComponentBuilder.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4VPhysicalVolume;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CalorimeterPVBuilder : public VComponentBuilder<G4VPhysicalVolume> {

  public:
    CalorimeterPVBuilder(); 
    ~CalorimeterPVBuilder();
    
  protected:  
    virtual G4VPhysicalVolume* Build() override; 
         
};

#endif

