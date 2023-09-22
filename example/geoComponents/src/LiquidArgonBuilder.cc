#include "LiquidArgonBuilder.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LiquidArgonBuilder::LiquidArgonBuilder(): 
VComponentBuilder()
{       
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LiquidArgonBuilder::~LiquidArgonBuilder()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* LiquidArgonBuilder::Build()
{
	//This is not a real scintillator.In a real case, defining a scintillator
	//requires long lines of code.
	return G4NistManager::Instance()->FindOrBuildMaterial("G4_lAr");
}


