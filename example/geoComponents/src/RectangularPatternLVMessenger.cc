#include "RectangularPatternLVMessenger.hh"
#include "RectangularPatternLVBuilder.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RectangularPatternLVMessenger::RectangularPatternLVMessenger
(
  RectangularPatternLVBuilder *builder
)
:G4UImessenger(),fBuilder(builder),
fDir(0),
fNumberOfSegmentAlongXCmd(0),
fNumberOfSegmentAlongYCmd(0),
fNumberOfSegmentAlongZCmd(0),
fInterModuleDistXCmd(0),
fInterModuleDistYCmd(0),
fInterModuleDistZCmd(0)
{ 
  fDir = new G4UIdirectory("/rpb/");
  fDir->SetGuidance("UI commands specific to this example");
  
  fNumberOfSegmentAlongXCmd = new G4UIcmdWithAnInteger(
    "/rpb/numberOfSegmentAlongX",this);
    
  fNumberOfSegmentAlongXCmd->SetGuidance("Set the number of segment along x");
  fNumberOfSegmentAlongXCmd->SetParameterName("NumberOfSegmentAlongX",false);
  //fNumberOfSegmentAlongXCmd->SetRange("Size>0.");
  fNumberOfSegmentAlongXCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fNumberOfSegmentAlongXCmd->SetToBeBroadcasted(false);
  
  fNumberOfSegmentAlongYCmd = new G4UIcmdWithAnInteger(
    "/rpb/numberOfSegmentAlongY",this);
  fNumberOfSegmentAlongYCmd->SetGuidance("Set the number of segment along y");
  fNumberOfSegmentAlongYCmd->SetParameterName("NumberOfSegmentAlongX",false);
  //fNumberOfSegmentAlongYCmd->SetRange("Size>0.");
  fNumberOfSegmentAlongYCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fNumberOfSegmentAlongYCmd->SetToBeBroadcasted(false);
  
  fNumberOfSegmentAlongZCmd = new G4UIcmdWithAnInteger(
    "/rpb/numberOfSegmentAlongZ",this);
  fNumberOfSegmentAlongZCmd->SetGuidance("Set the number of segment along z");
  fNumberOfSegmentAlongZCmd->SetParameterName("NumberOfSegmentAlongZ",false);
  //fNumberOfSegmentAlongZCmd->SetRange("Size>0.");
  fNumberOfSegmentAlongZCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fNumberOfSegmentAlongZCmd->SetToBeBroadcasted(false);
  
  fInterModuleDistXCmd = new G4UIcmdWithADoubleAndUnit(
    "/rpb/interModuleDistanceX",this);
  fInterModuleDistXCmd->SetGuidance("Set the gap between segment of along x");
  fInterModuleDistXCmd->SetParameterName("GapX",false);
  //fInterModuleDistXCmd->SetRange("Size>0.");
  fInterModuleDistXCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fInterModuleDistXCmd->SetToBeBroadcasted(false);
  
  fInterModuleDistYCmd = new G4UIcmdWithADoubleAndUnit(
    "/rpb/interModuleDistanceY",this);
  fInterModuleDistYCmd->SetGuidance("Set the gap between segment of along y");
  fInterModuleDistYCmd->SetParameterName("GapY",false);
  //fInterModuleDistXCmd->SetRange("Size>0.");
  fInterModuleDistYCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fInterModuleDistYCmd->SetToBeBroadcasted(false);
  
  fInterModuleDistZCmd = new G4UIcmdWithADoubleAndUnit(
    "/rpb/interModuleDistanceZ",this);
  fInterModuleDistZCmd->SetGuidance("Set the gap between segment of along z");
  fInterModuleDistZCmd->SetParameterName("GapZ",false);
  //fInterModuleDistZCmd->SetRange("Size>0.");
  fInterModuleDistZCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fInterModuleDistZCmd->SetToBeBroadcasted(false);
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RectangularPatternLVMessenger::~RectangularPatternLVMessenger()
{
  delete fNumberOfSegmentAlongXCmd;
  delete fNumberOfSegmentAlongYCmd;
  delete fNumberOfSegmentAlongZCmd;
  
  delete fInterModuleDistXCmd;
  delete fInterModuleDistYCmd;
  delete fInterModuleDistZCmd;
  
  delete fDir;  
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RectangularPatternLVMessenger::SetNewValue
(
  G4UIcommand* command,
  G4String newValue
)
{
  if( command == fNumberOfSegmentAlongXCmd )
  { 
    fBuilder->SetNumberOfSegmentAlongX(fNumberOfSegmentAlongXCmd->
      GetNewIntValue(newValue));
  }else if(command == fNumberOfSegmentAlongYCmd)
  {
    fBuilder->SetNumberOfSegmentAlongY(fNumberOfSegmentAlongYCmd->
      GetNewIntValue(newValue));
  }else if(command == fNumberOfSegmentAlongZCmd)
  {
    fBuilder->SetNumberOfSegmentAlongZ(fNumberOfSegmentAlongZCmd->
      GetNewIntValue(newValue));
  }else if (command == fInterModuleDistXCmd)
  {
    fBuilder->SetGapX(fInterModuleDistXCmd->GetNewDoubleValue(newValue));
  }else if (command == fInterModuleDistYCmd)
  {
    fBuilder->SetGapY(fInterModuleDistYCmd->GetNewDoubleValue(newValue));

  }else if (command == fInterModuleDistZCmd)
  {
    fBuilder->SetGapZ(fInterModuleDistZCmd->GetNewDoubleValue(newValue));
  }
      
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
