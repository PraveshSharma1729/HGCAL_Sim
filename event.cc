#include "event.hh"
#include "G4SystemOfUnits.hh"
#include <vector>
#include <cmath>  // For std::sqrt





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







//taking data of copy numbers for ring 0

    std::vector<int> Ring0;
    std::ifstream inputFile0("copyNumber_Ring0.txt");
    
    double value0;
    while (inputFile0 >> value0) {
        Ring0.push_back(value0);
    }
    
    inputFile0.close();
    
    
    //taking data of copy numbers for ring 1

    std::vector<int> Ring1;
    std::ifstream inputFile1("copyNumber_Ring1.txt");
    
    double value1;
    while (inputFile1 >> value1) {
        Ring1.push_back(value1);
    }
    
    inputFile1.close();
    
    
    //taking data of copy numbers for ring 2

    std::vector<int> Ring2;
    std::ifstream inputFile2("copyNumber_Ring2.txt");
    
    double value2;
    while (inputFile2 >> value2) {
        Ring2.push_back(value2);
    }
    
    inputFile2.close();
    
    
    
    //taking data of copy numbers for ring 3

    std::vector<int> Ring3;
    std::ifstream inputFile3("copyNumber_Ring3.txt");
    
    double value3;
    while (inputFile3 >> value3) {
        Ring3.push_back(value3);
    }
    
    inputFile3.close();
    
    
    
    //taking data of copy numbers for ring 4

    std::vector<int> Ring4;
    std::ifstream inputFile4("copyNumber_Ring4.txt");
    
    double value4;
    while (inputFile4 >> value4) {
        Ring4.push_back(value4);
    }
    
    inputFile4.close();
    
    
    
    //taking data of copy numbers for ring 5

    std::vector<int> Ring5;
    std::ifstream inputFile5("copyNumber_Ring5.txt");
    
    double value5;
    while (inputFile5 >> value5) {
        Ring5.push_back(value5);
    }
    
    inputFile5.close();
    
    
    
    //taking data of copy numbers for ring 6

    std::vector<int> Ring6;
    std::ifstream inputFile6("copyNumber_Ring6.txt");
    
    double value6;
    while (inputFile6 >> value6) {
        Ring6.push_back(value6);
    }
    
    inputFile6.close();
    
    
    
    
    
    
    
    
    //G4cout<<"value		"<<Ring0[1]<<G4endl;
    
   
    
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
        man->FillH2(fHistId2D, j-1, layer_dep);
    }
	man->AddNtupleRow(1);
	
	G4double ring0_dep=0;
 	for(G4int k=0; k<Ring0.size(); k++){
  	ring0_dep = ring0_dep + fEdep0[int(std::floor(Ring0[k]/1000)-1)*192+Ring0[k]%1000] ;}
	man->FillNtupleDColumn( 2,0, ring0_dep);
	
	
 	G4double ring1_dep=0;
 	for(G4int k=0; k<Ring1.size(); k++){
  	ring1_dep = ring1_dep + fEdep0[int(std::floor(Ring1[k]/1000)-1)*192+Ring1[k]%1000] ;}
	man->FillNtupleDColumn( 2,1, ring1_dep);
	
	
	
	G4double ring2_dep=0;
 	for(G4int k=0; k<Ring2.size(); k++){
  	ring2_dep = ring2_dep + fEdep0[int(std::floor(Ring2[k]/1000)-1)*192+Ring2[k]%1000] ;}
	man->FillNtupleDColumn( 2,2, ring2_dep);
	
	
	
	G4double ring3_dep=0;
 	for(G4int k=0; k<Ring3.size(); k++){
  	ring3_dep = ring3_dep + fEdep0[int(std::floor(Ring3[k]/1000)-1)*192+Ring3[k]%1000] ;}
	man->FillNtupleDColumn( 2,3, ring3_dep);
	
	
	
	G4double ring4_dep=0;
 	for(G4int k=0; k<Ring4.size(); k++){
  	ring4_dep = ring4_dep + fEdep0[int(std::floor(Ring4[k]/1000)-1)*192+Ring4[k]%1000] ;}
	man->FillNtupleDColumn( 2,4, ring4_dep);
	
	
	
	G4double ring5_dep=0;
 	for(G4int k=0; k<Ring5.size(); k++){
  	ring5_dep = ring5_dep + fEdep0[int(std::floor(Ring5[k]/1000)-1)*192+Ring5[k]%1000] ;}
	man->FillNtupleDColumn( 2,5, ring5_dep);
	
	
	G4double ring6_dep=0;
 	for(G4int k=0; k<Ring6.size(); k++){
  	ring6_dep = ring6_dep + fEdep0[int(std::floor(Ring6[k]/1000)-1)*192+Ring6[k]%1000] ;}
  	//G4cout<<"Debug	"<<fEdep0[int(std::floor(Ring6[k]/1000)-1)*192+Ring6[k]%1000]<<"		"<<int(std::floor(Ring6[k]/1000))*192+Ring6[k]%1000<<G4endl;
	man->FillNtupleDColumn( 2,6, ring6_dep);
	
	
	
	man->AddNtupleRow(2);
	
	
	//G4cout<<"ring deposition 	"<<ring6_dep<<G4endl;
	
}




void MyEventAction::AddEdep0(G4int copyNo, G4double edep) {
for (G4int i=1; i < 28 ;i++){
    if (copyNo >= 1000*i+0 && copyNo < 1000*i+192) {
        fEdep0[copyNo-1000*i+192*(i-1)] += edep; // Store energy deposition in corresponding array element
    }
    
    
    
    }
    
}

