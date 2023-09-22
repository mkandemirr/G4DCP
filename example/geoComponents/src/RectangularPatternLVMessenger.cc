#include "RectangularPatternLVMessenger.hh"



#include "RectangularPatternLVBuilder.hh"
#include "G4UIdirectory.hh"

#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RectangularPatternLVMessenger::RectangularPatternLVMessenger(RectangularPatternLVBuilder *builder)
:G4UImessenger(),fBuilder(builder),
 fDir(0),
 fNumberOfModuleAlongXCmd(0),
 fNumberOfModuleAlongYCmd(0),
 fNumberOfModuleAlongZCmd(0),
 fInterModuleDistXCmd(0),
 fInterModuleDistYCmd(0),
 fInterModuleDistZCmd(0)
{ 
  fDir = new G4UIdirectory("/rpb/");
  fDir->SetGuidance("UI commands specific to this example");
  
  fNumberOfModuleAlongXCmd = new G4UIcmdWithAnInteger("/rpb/numberOfModuleAlongX",this);
  fNumberOfModuleAlongXCmd->SetGuidance("Set the number of segment along x");
  fNumberOfModuleAlongXCmd->SetParameterName("NumberOfModuleAlongX",false);
  //fNumberOfModuleAlongXCmd->SetRange("Size>0.");
  fNumberOfModuleAlongXCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fNumberOfModuleAlongXCmd->SetToBeBroadcasted(false);
  
  fNumberOfModuleAlongYCmd = new G4UIcmdWithAnInteger("/rpb/numberOfModuleAlongY",this);
  fNumberOfModuleAlongYCmd->SetGuidance("Set the number of segment along y");
  fNumberOfModuleAlongYCmd->SetParameterName("NumberOfModuleAlongX",false);
  //fNumberOfModuleAlongYCmd->SetRange("Size>0.");
  fNumberOfModuleAlongYCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fNumberOfModuleAlongYCmd->SetToBeBroadcasted(false);
  
  fNumberOfModuleAlongZCmd = new G4UIcmdWithAnInteger("/rpb/numberOfModuleAlongZ",this);
  fNumberOfModuleAlongZCmd->SetGuidance("Set the number of segment along z");
  fNumberOfModuleAlongZCmd->SetParameterName("NumberOfModuleAlongZ",false);
  //fNumberOfModuleAlongZCmd->SetRange("Size>0.");
  fNumberOfModuleAlongZCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fNumberOfModuleAlongZCmd->SetToBeBroadcasted(false);
  
  fInterModuleDistXCmd = new G4UIcmdWithADoubleAndUnit("/rpb/interModuleDistanceX",this);
  fInterModuleDistXCmd->SetGuidance("Set the gap between segment of along x");
  fInterModuleDistXCmd->SetParameterName("GapX",false);
  //fInterModuleDistXCmd->SetRange("Size>0.");
  fInterModuleDistXCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fInterModuleDistXCmd->SetToBeBroadcasted(false);
  
  fInterModuleDistYCmd = new G4UIcmdWithADoubleAndUnit("/rpb/interModuleDistanceY",this);
  fInterModuleDistYCmd->SetGuidance("Set the gap between segment of along y");
  fInterModuleDistYCmd->SetParameterName("GapY",false);
  //fInterModuleDistXCmd->SetRange("Size>0.");
  fInterModuleDistYCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fInterModuleDistYCmd->SetToBeBroadcasted(false);
  
  fInterModuleDistZCmd = new G4UIcmdWithADoubleAndUnit("/rpb/interModuleDistanceZ",this);
  fInterModuleDistZCmd->SetGuidance("Set the gap between segment of along z");
  fInterModuleDistZCmd->SetParameterName("GapZ",false);
  //fInterModuleDistZCmd->SetRange("Size>0.");
  fInterModuleDistZCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fInterModuleDistZCmd->SetToBeBroadcasted(false);
  
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RectangularPatternLVMessenger::~RectangularPatternLVMessenger()
{
  delete fNumberOfModuleAlongXCmd;
  delete fNumberOfModuleAlongYCmd;
  delete fNumberOfModuleAlongZCmd;
  
  delete fInterModuleDistXCmd;
  delete fInterModuleDistYCmd;
  delete fInterModuleDistZCmd;
  
  delete fDir;  
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RectangularPatternLVMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  if( command == fNumberOfModuleAlongXCmd )
  { 
  	fBuilder->SetNumberOfModuleAlongX(fNumberOfModuleAlongXCmd->GetNewIntValue(newValue));
	}else if(command == fNumberOfModuleAlongYCmd)
	{
		fBuilder->SetNumberOfModuleAlongY(fNumberOfModuleAlongYCmd->GetNewIntValue(newValue));
	}else if(command == fNumberOfModuleAlongZCmd)
	{
		fBuilder->SetNumberOfModuleAlongZ(fNumberOfModuleAlongZCmd->GetNewIntValue(newValue));
	}

   
  if (command == fInterModuleDistXCmd)
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
