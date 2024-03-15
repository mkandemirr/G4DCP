#include "PhysicalVolumeFactory.hh"
#include "CalorimeterPVBuilder.hh"
#include "CalorimeterModulePVBuilder.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PhysicalVolumeStore.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicalVolumeFactory* PhysicalVolumeFactory::fInstance = nullptr;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicalVolumeFactory::PhysicalVolumeFactory():
VComponentFactory()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicalVolumeFactory::~PhysicalVolumeFactory()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* PhysicalVolumeFactory::Create(const G4String& name)
{
  G4VPhysicalVolume* product = G4PhysicalVolumeStore::GetInstance()->
    GetVolume(name,false);
    
  if(product) return product;

  if(name=="CalorimeterPV")
  {
    CalorimeterPVBuilder builder;
    return builder.GetProduct();
   
  }else if (name == "CalorimeterModulePV")
  {
    CalorimeterModulePVBuilder builder;
    return builder.GetProduct();
  }else
  {
    return nullptr;
  }
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicalVolumeFactory* PhysicalVolumeFactory::GetInstance()
{
  static PhysicalVolumeFactory instance;
  
  if(fInstance == nullptr)
  {
    fInstance = &instance;
  }
    
  return fInstance;
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

