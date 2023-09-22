#ifndef PhysicalVolumeFactory_h
#define PhysicalVolumeFactory_h 1

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "VComponentFactory.hh"

class G4VPhysicalVolume;

//singleton class
class PhysicalVolumeFactory: public VComponentFactory<G4VPhysicalVolume>
{
  public:
    static PhysicalVolumeFactory* GetInstance();
    
    //Singletons should not be cloneable.
    PhysicalVolumeFactory(const PhysicalVolumeFactory&) = delete;
    
    //Singletons should not be assignable.
    PhysicalVolumeFactory& operator=(const PhysicalVolumeFactory&) = delete;
       
  protected:  
    PhysicalVolumeFactory();
    virtual ~PhysicalVolumeFactory();
      
    virtual G4VPhysicalVolume* Create(const G4String& name) override;
      
  private:
    static PhysicalVolumeFactory* fInstance;  
               
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif 
