#include "run.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();

man->OpenFile("output.root");

man->CreateNtuple("Hits","Hits");
man->CreateNtupleIColumn("fEvent");
man->CreateNtupleDColumn("fX");
man->CreateNtupleDColumn("fY");
man->CreateNtupleDColumn("fZ");
man->FinishNtuple(0);

man->CreateNtuple("Scoring","Scoring");
//for(G4int i=0; i<27;i++){
man->CreateNtupleDColumn("Edep_l1");//}
man->CreateNtupleDColumn("Edep_l2");
man->CreateNtupleDColumn("Edep_l3");
man->CreateNtupleDColumn("Edep_l4");
man->CreateNtupleDColumn("Edep_l5");
man->CreateNtupleDColumn("Edep_l6");
man->CreateNtupleDColumn("Edep_l7");
man->CreateNtupleDColumn("Edep_l8");
man->CreateNtupleDColumn("Edep_l9");
man->CreateNtupleDColumn("Edep_l10");
man->CreateNtupleDColumn("Edep_l11");
man->CreateNtupleDColumn("Edep_l12");
man->CreateNtupleDColumn("Edep_l13");
man->CreateNtupleDColumn("Edep_l14");
man->CreateNtupleDColumn("Edep_l15");
man->CreateNtupleDColumn("Edep_l16");
man->CreateNtupleDColumn("Edep_l17");
man->CreateNtupleDColumn("Edep_l18");
man->CreateNtupleDColumn("Edep_l19");
man->CreateNtupleDColumn("Edep_l20");
man->CreateNtupleDColumn("Edep_l21");//}
man->CreateNtupleDColumn("Edep_l22");
man->CreateNtupleDColumn("Edep_l23");
man->CreateNtupleDColumn("Edep_l24");
man->CreateNtupleDColumn("Edep_l25");
man->CreateNtupleDColumn("Edep_l26");
man->CreateNtupleDColumn("Edep_l27");

man->FinishNtuple(1);



man->CreateNtuple("Ring","Ring");
man->CreateNtupleDColumn("Ring0");
man->CreateNtupleDColumn("Ring1");
man->CreateNtupleDColumn("Ring2");
man->CreateNtupleDColumn("Ring3");
man->CreateNtupleDColumn("Ring4");
man->CreateNtupleDColumn("Ring5");
man->CreateNtupleDColumn("Ring6");

man->FinishNtuple(2);


 // Create a 2D histogram
    fHistId2D = man->CreateH2("EnergyDeposition", "Energy Deposition vs Layer Number",
                              100, 0, 30,  // x-axis: copy number range
                              100, 0, 100); // y-axis: energy deposition range 
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();

man->Write();

man->CloseFile();


}

