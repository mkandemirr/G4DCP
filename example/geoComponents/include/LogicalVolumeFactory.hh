#ifndef LogicalVolumeFactory_h
#define LogicalVolumeFactory_h 1

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "VComponentFactory.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4LogicalVolume;

//singleton class
class LogicalVolumeFactory: public VComponentFactory<G4LogicalVolume>
{
  public:
    static LogicalVolumeFactory* GetInstance();
    
    //Singletons should not be cloneable.
    LogicalVolumeFactory(const LogicalVolumeFactory&) = delete;
    
    //Singletons should not be assignable.
    LogicalVolumeFactory& operator=(const LogicalVolumeFactory&) = delete;
       
  protected:  
    LogicalVolumeFactory();
    virtual ~LogicalVolumeFactory();
      
    virtual G4LogicalVolume* Create(const G4String& name) override;
      
  private:
    static LogicalVolumeFactory* fInstance;  
               
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif 
