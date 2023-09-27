

#ifndef RectangularPatternLVMessenger_h
#define RectangularPatternLVMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class RectangularPatternLVBuilder;
class G4UIdirectory;
class G4UIcommand;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class RectangularPatternLVMessenger: public G4UImessenger
{
  public:
    RectangularPatternLVMessenger(RectangularPatternLVBuilder* );
   ~RectangularPatternLVMessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);

  private:
    RectangularPatternLVBuilder*  fBuilder;

    G4UIdirectory*     fDir;

		G4UIcmdWithAnInteger* fNumberOfSegmentAlongXCmd;
		G4UIcmdWithAnInteger* fNumberOfSegmentAlongYCmd;
		G4UIcmdWithAnInteger* fNumberOfSegmentAlongZCmd;
		
		    
    G4UIcmdWithADoubleAndUnit* fInterModuleDistXCmd;
    G4UIcmdWithADoubleAndUnit* fInterModuleDistYCmd;
    G4UIcmdWithADoubleAndUnit* fInterModuleDistZCmd;
   
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

