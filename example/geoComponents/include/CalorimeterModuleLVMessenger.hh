#ifndef CalorimeterModuleLVMessenger_h
#define CalorimeterModuleLVMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class CalorimeterModuleLVBuilder;
class G4UIdirectory;
class G4UIcommand;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CalorimeterModuleLVMessenger: public G4UImessenger
{
  public:
    CalorimeterModuleLVMessenger(CalorimeterModuleLVBuilder* );
   ~CalorimeterModuleLVMessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);

  private:
    CalorimeterModuleLVBuilder *fCalBuilder;

		G4UIdirectory *fRootDir;
    G4UIdirectory *fCmdDir;
        
    G4UIcmdWithADoubleAndUnit *fModuleSizeXCmd;
    G4UIcmdWithADoubleAndUnit *fModuleSizeYCmd;
    G4UIcommand *fAbsorCmd;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

