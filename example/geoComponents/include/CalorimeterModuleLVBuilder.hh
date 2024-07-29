#ifndef CalorimeterModuleLVBuilder_h
#define CalorimeterModuleLVBuilder_h 1

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "VComponentBuilder.hh"
#include <vector>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4LogicalVolume;
class G4Material;
class G4VPhysicalVolume;
class G4Box;
class CalorimeterModuleLVMessenger; 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CalorimeterModuleLVBuilder : public VComponentBuilder<G4LogicalVolume> {

  public:
    CalorimeterModuleLVBuilder(); 
    ~CalorimeterModuleLVBuilder();
    
  protected:  
    virtual G4LogicalVolume* Build() override; 
    
	public:
		//UI commands
		void AddAbsorber(const G4String& matName, G4double thickness);
		void SetModuleSizeX(G4double);
		void SetModuleSizeY(G4double);
				        
  private:
		CalorimeterModuleLVMessenger* fMessenger;
			
		G4double fModuleSizeX;
		G4double fModuleSizeY;
		
		std::vector<G4Material*> absorberMatVec;
		std::vector<G4double> absorberThicknessVec;
		std::vector<G4Box*> absorberBoxVec;
		std::vector<G4LogicalVolume*> absorberLVVec;
		std::vector<G4VPhysicalVolume*> absorberPVVec;
	     
};

#endif

