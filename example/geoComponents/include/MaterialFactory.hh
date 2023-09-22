#ifndef MaterialFactory_h
#define MaterialFactory_h 1

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "VComponentFactory.hh"

class G4Material;

//singleton class
class MaterialFactory: public VComponentFactory<G4Material>
{
  public:
    static MaterialFactory* GetInstance();
    
    //Singletons should not be cloneable.
    MaterialFactory(const MaterialFactory&) = delete;
    
    //Singletons should not be assignable.
    MaterialFactory& operator=(const MaterialFactory&) = delete;
       
  protected:  
    MaterialFactory();
    virtual ~MaterialFactory();
      
    virtual G4Material* Create(const G4String& name) override;
      
  private:
    static MaterialFactory* fInstance;  
               
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif 
