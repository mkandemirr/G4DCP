#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="e-");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  fParticleGun->SetParticleEnergy(1.*keV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	G4LogicalVolumeStore* store = G4LogicalVolumeStore::GetInstance();
	
	G4Box* world = dynamic_cast<G4Box*>(store->GetVolume("WorldLV")->GetSolid());
	
	G4double z = world->GetZHalfLength();
	
	/*
	std::vector<G4VPhysicalVolume*>::iterator pos;
   
      for(pos=store->begin(); pos!=store->end(); pos++)
     {
       if((*pos)->GetCopyNo() == 0){
        position = (*pos)->GetTranslation();
        G4cout<<"semele:"<<(*pos)->GetCopyNo();
        break;
       }
       	
     }
   */  
   
	
	
 
  fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-z));

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......




