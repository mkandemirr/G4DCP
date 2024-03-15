#ifndef LiquidArgonBuilder_h
#define LiquidArgonBuilder_h 1

#include "VComponentBuilder.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class LiquidArgonBuilder : public VComponentBuilder<G4Material> {

  public:
    LiquidArgonBuilder(); 
    ~LiquidArgonBuilder();
    
  protected:  
    virtual G4Material* Build() override; 
         
};

#endif

