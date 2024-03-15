#include "CalorimeterModuleLVMessenger.hh"
#include <sstream>
#include "CalorimeterModuleLVBuilder.hh"
#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"
#include "G4UIparameter.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterModuleLVMessenger::CalorimeterModuleLVMessenger(CalorimeterModuleLVBuilder *builder)
:G4UImessenger(),
 fCalBuilder(builder),
 fRootDir(nullptr),
 fCmdDir(nullptr),
 fModuleSizeXCmd(nullptr),
 fModuleSizeYCmd(nullptr),
 fAbsorCmd(nullptr)
{ 

  G4String rootDirectory     = "/det/"; 
  G4String commandDirectory  = "/det/calorimeterModule/";
  
  if(!fRootDir)
  {
    fRootDir = new G4UIdirectory(rootDirectory);
    fRootDir->SetGuidance("UI commands specific to this example");
  }
  
  if(!fCmdDir)
  {
    fCmdDir = new G4UIdirectory(commandDirectory);
    fCmdDir->SetGuidance("detector construction commands");
  }
  
  
  //-------------Command 1---------------------------------
  G4String commandName  = "sizeX";
  G4String commandPath  = commandDirectory+commandName;
  
  fModuleSizeXCmd = new G4UIcmdWithADoubleAndUnit(commandPath,this);
  fModuleSizeXCmd->SetGuidance("Set size x of the calorimeter");
  fModuleSizeXCmd->SetParameterName("Size",false);
  fModuleSizeXCmd->SetRange("Size>0.");
  fModuleSizeXCmd->SetUnitCategory("Length");
  fModuleSizeXCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fModuleSizeXCmd->SetToBeBroadcasted(false);
  
  //-------------Command 2---------------------------------
  commandName  = "sizeY";
  commandPath  = commandDirectory+commandName;
  
  fModuleSizeYCmd = new G4UIcmdWithADoubleAndUnit(commandPath,this);
  fModuleSizeYCmd->SetGuidance("Set size y of the calorimeter");
  fModuleSizeYCmd->SetParameterName("Size",false);
  fModuleSizeYCmd->SetRange("Size>0.");
  fModuleSizeYCmd->SetUnitCategory("Length");
  fModuleSizeYCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fModuleSizeYCmd->SetToBeBroadcasted(false);
    
  //-------------Command 3---------------------------------
  commandName  = "addAbsorber";
  commandPath  = commandDirectory+commandName;  
  
  fAbsorCmd = new G4UIcommand(commandPath,this);
  fAbsorCmd->SetGuidance("matName thickness unit");
  fAbsorCmd->SetGuidance("  absor number : from 1 to NbOfAbsor");
  fAbsorCmd->SetGuidance("  material name");
  fAbsorCmd->SetGuidance("  thickness (with unit) : t>0."); 
  
//Add parameters to the command3. 
  //first parameter
  G4UIparameter* MatPrm = new G4UIparameter("material",'s',false);
  MatPrm->SetGuidance("material name");
  fAbsorCmd->SetParameter(MatPrm);
  
  //second parameter   
  G4UIparameter* ThickPrm = new G4UIparameter("thickness",'d',false);
  ThickPrm->SetGuidance("thickness of absorber");
  ThickPrm->SetParameterRange("thickness>0.");
  fAbsorCmd->SetParameter(ThickPrm);
  
  //third parameter
  G4UIparameter* unitPrm = new G4UIparameter("unit",'s',false);
  unitPrm->SetGuidance("unit of thickness");
  G4String unitList = G4UIcommand::UnitsList(G4UIcommand::CategoryOf("mm"));
  unitPrm->SetParameterCandidates(unitList);
  fAbsorCmd->SetParameter(unitPrm);
  //
  
  fAbsorCmd->AvailableForStates(G4State_PreInit,G4State_Init);
  fAbsorCmd->SetToBeBroadcasted(false);  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CalorimeterModuleLVMessenger::~CalorimeterModuleLVMessenger()
{
  if(fRootDir)
    delete fRootDir;  
  
  if(fCmdDir)
    delete fCmdDir;

  delete fModuleSizeXCmd;
  delete fModuleSizeYCmd;
  delete fAbsorCmd;
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CalorimeterModuleLVMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  if(command == fModuleSizeXCmd )
  { 
    fCalBuilder->SetModuleSizeX(fModuleSizeXCmd->GetNewDoubleValue(newValue));
  }else if(command == fModuleSizeYCmd)
  {
    fCalBuilder->SetModuleSizeY(fModuleSizeYCmd->GetNewDoubleValue(newValue));
  }else if (command == fAbsorCmd)
  {
    G4double tick;
    G4String unt, mat;

    std::istringstream is(newValue);
    is >> mat >> tick >> unt;

    G4String material = mat;
    tick *= G4UIcommand::ValueOf(unt);

    fCalBuilder->AddAbsorber(material,tick);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
