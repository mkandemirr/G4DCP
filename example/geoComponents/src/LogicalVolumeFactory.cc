#include "LogicalVolumeFactory.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"

#include "CalorimeterModuleLVBuilder.hh"
#include "CalorimeterLVBuilder.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LogicalVolumeFactory* LogicalVolumeFactory::fInstance = nullptr;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LogicalVolumeFactory::LogicalVolumeFactory():
VComponentFactory()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LogicalVolumeFactory::~LogicalVolumeFactory()
{	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* LogicalVolumeFactory::Create(const G4String& name)
{
	G4LogicalVolume* lv = G4LogicalVolumeStore::GetInstance()->GetVolume(name,false);
  if(lv) return lv;

  if(name=="CalorimeterModule")
  {
  	CalorimeterModuleLVBuilder cb;
  	return cb.GetProduct();
   
  }else if(name=="Calorimeter")
  {
  	CalorimeterLVBuilder builder;
  	return builder.GetProduct();
  }
  else 
  {
    return nullptr;
  }
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LogicalVolumeFactory* LogicalVolumeFactory::GetInstance()
{
  static LogicalVolumeFactory instance;
  
  if(fInstance == nullptr)
  {
    fInstance = &instance;
  }
    
  return fInstance;
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

