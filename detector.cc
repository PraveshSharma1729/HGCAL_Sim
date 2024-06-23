#include "detector.hh"
#include "event.hh"
MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();
	
	//track->SetTrackStatus(fStopAndKill);
	
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4ThreeVector posPhoton =preStepPoint->GetPosition();
	
	//G4cout<<"Photon position: "<<posPhoton<<G4endl;
	
	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
	G4int copyNo = touchable->GetCopyNumber();
	
	//G4cout<<"Copy number: "<<copyNo<<G4endl;
	
	G4VPhysicalVolume *physVol = touchable->GetVolume();
	G4ThreeVector posDetector = physVol->GetTranslation();
	
	//G4cout<<"Detector position: "<<posDetector<<G4endl;
	
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	if (copyNo ==1169){
	G4cout << "Event: " << evt <<G4endl;}
	G4double edep = aStep->GetTotalEnergyDeposit();
   for (G4int i=1; i < 28 ;i++){
   if (copyNo >= i*1000+0 && copyNo < i*1000+192) {
   //if (copyNo ==1084){
        //G4cout << "Event: " << evt << ", Copy number: " << copyNo << ", Energy deposition: " << edep / CLHEP::MeV << " MeV" << G4endl;//}

       /* // Use const_cast to remove const qualifier
        MyEventAction *eventAction = const_cast<MyEventAction*>(static_cast<const MyEventAction*>(G4RunManager::GetRunManager()->GetUserEventAction()));

        if (eventAction) {
            eventAction->AddEdep0(copyNo, edep);
        }*/
        
    }
    
    }
    
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0,evt);
	man->FillNtupleDColumn(1,posDetector[0]);
	man->FillNtupleDColumn(2,posDetector[1]);
	man->FillNtupleDColumn(3,posDetector[2]);
	man->AddNtupleRow(0);
	
	
	return true;
}
