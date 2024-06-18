#include "event.hh"
#include "G4SystemOfUnits.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	fEdep = 0.;
	for (G4int i = 0; i < 192*27; ++i) {
        fEdep0[i] = 0.;
    }
	
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0.;
	
	for (G4int i = 0; i < 192*27; ++i) {
        fEdep0[i] = 0.;
    }
	//fEdep1100=0;
	
	
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();


  //G4cout << "Energy deposition in copy numbers 1 to 192:" << G4endl;
  for (G4int j=1; j < 28 ;j++){
    G4double layer_dep=0;
    for (G4int i = 1000*j+0; i < 1000*j+192; ++i) {
    //if (i ==1084){
        //G4cout << "Copy number " << (i) << ": " << fEdep0[i-1000*j+192*(j-1)] / CLHEP::MeV << " MeV" << G4endl;//}
        layer_dep=layer_dep + fEdep0[i-1000*j+192*(j-1)] ;

    }
    
        //G4cout << "layer 	"<<j<< "  Energy deposited 	"<<layer_dep<<G4endl;
        man->FillNtupleDColumn( 1,j-1, layer_dep);
    }


man->AddNtupleRow(1);

}


void MyEventAction::AddEdep0(G4int copyNo, G4double edep) {
for (G4int i=1; i < 28 ;i++){
    if (copyNo >= 1000*i+0 && copyNo < 1000*i+192) {
        fEdep0[copyNo-1000*i+192*(i-1)] += edep; // Store energy deposition in corresponding array element
    }
    
    
    
    }
    
}

