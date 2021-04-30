#include <TH1F.h>
#include <TFile.h>

class categoryHistogram{
    private:
        TH1F* h_nJet;
        TH1F* h_nBJet;
        TH1F* h_nGoodLeps;
        TH1F* h_leadLepPt;
        TH1F* h_leadLepEta;
        TH1F* h_leadLepMass;
        TH1F* h_leadLepMiniIso;
        TH1F* h_leadLepPtRel;
        TH1F* h_leadLepPtRatio;
        TH1F* h_leadJetPt;
        TH1F* h_leadBPt;
        TH1F* h_leadBMass;
        TH1F* h_jetHT;
        TH1F* h_MET;
        TH1F* h_minMT;
        TH1F* h_MT_b_MET;

    public:
        /*int nJet;
        int nBJet;
        int nLep;
        int nFO;
        bool isSS;
        bool isSF;*/

        //constructor will create all histograms for each region category
        categoryHistogram(string numLep, string numJet, string numB, string sampleName){
            h_nJet = new TH1F( ("h_nJet_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "nJets", 7, -0.5, 6.5 );
            h_nBJet = new TH1F( ("h_nBJet_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "nBjets", 4, -0.5, 3.5 );
            h_nGoodLeps = new TH1F( ("h_nGoodLeps_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "nGoodLeps", 6, -0.5, 5.5 );
            h_leadLepPt = new TH1F( ("h_leadLepPt_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadLepPt", 50, 0, 500 );
            h_leadLepEta = new TH1F( ("h_leadLepEta_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadLepEta", 20, -5, 5 );
            h_leadLepMass = new TH1F( ("h_leadLepMass_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadLepMass", 500, 0, 1 );
            h_leadLepMiniIso = new TH1F( ("h_leadLepMiniIso_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadLepMiniIso", 10, 0, 0.5 );
            h_leadLepPtRel = new TH1F( ("h_leadLepPtRel_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadLepPtRel", 50, 0, 10 );
            h_leadLepPtRatio = new TH1F( ("h_leadLepPtRatio_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadLepPtRatio", 50, 0, 5 );
            h_leadJetPt = new TH1F( ("h_leadJetPt_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadJetPt", 50, 0, 500 );
            h_leadBPt = new TH1F( ("h_leadBPt_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadBPt", 50, 0, 500 );
            h_leadBMass = new TH1F( ("h_leadBMass_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "leadBMass", 50, 0, 500 );
            h_jetHT = new TH1F( ("h_jetHT_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "jetHT", 100, 0, 1000 );
            h_MET = new TH1F( ("h_MET_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "MET", 50, 0, 500 );
            h_minMT = new TH1F( ("h_minMT_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "minMT", 50, 0, 500 );
            h_MT_b_MET = new TH1F( ("h_MT_b_MET_"+numLep+"_"+numJet+"_"+numB+"_"+sampleName).c_str(), "MT_b_MET", 50, 0, 500 );
        } 
        categoryHistogram(){} 

        //methods to fill and save histograms
        void fillHistogram(vector<float> variables, float weight){
            std::cout << h_nJet->GetDirectory()->GetName() << std::endl;
            h_nJet->Fill(variables[0], weight);
            h_nBJet->Fill(variables[1], weight);
            h_nGoodLeps->Fill(variables[2], weight);
            h_leadLepPt->Fill(variables[3], weight);
            h_leadLepEta->Fill(variables[4], weight);
            h_leadLepMass->Fill(variables[5], weight);
            h_leadLepMiniIso->Fill(variables[6], weight);
            h_leadLepPtRel->Fill(variables[7], weight);
            h_leadLepPtRatio->Fill(variables[8], weight);
            h_leadJetPt->Fill(variables[7], weight);
            h_leadBPt->Fill(variables[8], weight);
            h_leadBMass->Fill(variables[11], weight);
            h_jetHT->Fill(variables[9], weight);
            h_MET->Fill(variables[10], weight);
            h_minMT->Fill(variables[14], weight);
            h_MT_b_MET->Fill(variables[15], weight);
        }

        void writeHistogram(TFile* &outfile){
            std::cout << outfile->GetName() << std::endl;
            if (outfile->IsOpen()){
                h_nJet->Write();
                h_nBJet->Write();
                h_nGoodLeps->Write();
                h_leadLepPt->Write();
                h_leadLepEta->Write();
                h_leadLepMass->Write();
                h_leadLepMiniIso->Write();
                h_leadLepPtRel->Write();
                h_leadLepPtRatio->Write();
                h_leadJetPt->Write();
                h_leadBPt->Write();
                h_leadBMass->Write();
                h_jetHT->Write();
                h_MET->Write();
                h_minMT->Write();
                h_MT_b_MET->Write();
            }
        }

};







class makeHistograms{
    private:
        categoryHistogram* trilep_2j_0b_fakes;
        categoryHistogram* trilep_2j_1b_fakes;
        categoryHistogram* trilep_2j_ge2b_fakes;
        categoryHistogram* trilep_3j_0b_fakes;
        categoryHistogram* trilep_3j_1b_fakes;
        categoryHistogram* trilep_3j_ge2b_fakes;
        categoryHistogram* trilep_ge4j_0b_fakes;
        categoryHistogram* trilep_ge4j_1b_fakes;
        categoryHistogram* trilep_ge4j_ge2b_fakes;

        categoryHistogram* SS_SF_dilep_2j_0b_fakes;
        categoryHistogram* SS_SF_dilep_2j_1b_fakes;
        categoryHistogram* SS_SF_dilep_2j_ge2b_fakes;
        categoryHistogram* SS_SF_dilep_3j_0b_fakes;
        categoryHistogram* SS_SF_dilep_3j_1b_fakes;
        categoryHistogram* SS_SF_dilep_3j_ge2b_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_0b_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_1b_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_fakes;

        categoryHistogram* SS_OF_dilep_2j_0b_fakes;
        categoryHistogram* SS_OF_dilep_2j_1b_fakes;
        categoryHistogram* SS_OF_dilep_2j_ge2b_fakes;
        categoryHistogram* SS_OF_dilep_3j_0b_fakes;
        categoryHistogram* SS_OF_dilep_3j_1b_fakes;
        categoryHistogram* SS_OF_dilep_3j_ge2b_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_0b_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_1b_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_fakes;

        categoryHistogram* OS_SF_dilep_2j_0b_fakes;
        categoryHistogram* OS_SF_dilep_2j_1b_fakes;
        categoryHistogram* OS_SF_dilep_2j_ge2b_fakes;
        categoryHistogram* OS_SF_dilep_3j_0b_fakes;
        categoryHistogram* OS_SF_dilep_3j_1b_fakes;
        categoryHistogram* OS_SF_dilep_3j_ge2b_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_0b_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_1b_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_fakes;

        categoryHistogram* OS_OF_dilep_2j_0b_fakes;
        categoryHistogram* OS_OF_dilep_2j_1b_fakes;
        categoryHistogram* OS_OF_dilep_2j_ge2b_fakes;
        categoryHistogram* OS_OF_dilep_3j_0b_fakes;
        categoryHistogram* OS_OF_dilep_3j_1b_fakes;
        categoryHistogram* OS_OF_dilep_3j_ge2b_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_0b_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_1b_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_fakes;

        categoryHistogram* onelepFO_2j_0b_fakes;
        categoryHistogram* onelepFO_2j_1b_fakes;
        categoryHistogram* onelepFO_2j_ge2b_fakes;
        categoryHistogram* onelepFO_3j_0b_fakes;
        categoryHistogram* onelepFO_3j_1b_fakes;
        categoryHistogram* onelepFO_3j_ge2b_fakes;
        categoryHistogram* onelepFO_ge4j_0b_fakes;
        categoryHistogram* onelepFO_ge4j_1b_fakes;
        categoryHistogram* onelepFO_ge4j_ge2b_fakes;

        categoryHistogram* dilepFO_2j_0b_fakes;
        categoryHistogram* dilepFO_2j_1b_fakes;
        categoryHistogram* dilepFO_2j_ge2b_fakes;
        categoryHistogram* dilepFO_3j_0b_fakes;
        categoryHistogram* dilepFO_3j_1b_fakes;
        categoryHistogram* dilepFO_3j_ge2b_fakes;
        categoryHistogram* dilepFO_ge4j_0b_fakes;
        categoryHistogram* dilepFO_ge4j_1b_fakes;
        categoryHistogram* dilepFO_ge4j_ge2b_fakes;



        categoryHistogram* trilep_2j_0b_flips;
        categoryHistogram* trilep_2j_1b_flips;
        categoryHistogram* trilep_2j_ge2b_flips;
        categoryHistogram* trilep_3j_0b_flips;
        categoryHistogram* trilep_3j_1b_flips;
        categoryHistogram* trilep_3j_ge2b_flips;
        categoryHistogram* trilep_ge4j_0b_flips;
        categoryHistogram* trilep_ge4j_1b_flips;
        categoryHistogram* trilep_ge4j_ge2b_flips;

        categoryHistogram* SS_SF_dilep_2j_0b_flips;
        categoryHistogram* SS_SF_dilep_2j_1b_flips;
        categoryHistogram* SS_SF_dilep_2j_ge2b_flips;
        categoryHistogram* SS_SF_dilep_3j_0b_flips;
        categoryHistogram* SS_SF_dilep_3j_1b_flips;
        categoryHistogram* SS_SF_dilep_3j_ge2b_flips;
        categoryHistogram* SS_SF_dilep_ge4j_0b_flips;
        categoryHistogram* SS_SF_dilep_ge4j_1b_flips;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_flips;

        categoryHistogram* SS_OF_dilep_2j_0b_flips;
        categoryHistogram* SS_OF_dilep_2j_1b_flips;
        categoryHistogram* SS_OF_dilep_2j_ge2b_flips;
        categoryHistogram* SS_OF_dilep_3j_0b_flips;
        categoryHistogram* SS_OF_dilep_3j_1b_flips;
        categoryHistogram* SS_OF_dilep_3j_ge2b_flips;
        categoryHistogram* SS_OF_dilep_ge4j_0b_flips;
        categoryHistogram* SS_OF_dilep_ge4j_1b_flips;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_flips;

        categoryHistogram* OS_SF_dilep_2j_0b_flips;
        categoryHistogram* OS_SF_dilep_2j_1b_flips;
        categoryHistogram* OS_SF_dilep_2j_ge2b_flips;
        categoryHistogram* OS_SF_dilep_3j_0b_flips;
        categoryHistogram* OS_SF_dilep_3j_1b_flips;
        categoryHistogram* OS_SF_dilep_3j_ge2b_flips;
        categoryHistogram* OS_SF_dilep_ge4j_0b_flips;
        categoryHistogram* OS_SF_dilep_ge4j_1b_flips;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_flips;

        categoryHistogram* OS_OF_dilep_2j_0b_flips;
        categoryHistogram* OS_OF_dilep_2j_1b_flips;
        categoryHistogram* OS_OF_dilep_2j_ge2b_flips;
        categoryHistogram* OS_OF_dilep_3j_0b_flips;
        categoryHistogram* OS_OF_dilep_3j_1b_flips;
        categoryHistogram* OS_OF_dilep_3j_ge2b_flips;
        categoryHistogram* OS_OF_dilep_ge4j_0b_flips;
        categoryHistogram* OS_OF_dilep_ge4j_1b_flips;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_flips;

        categoryHistogram* onelepFO_2j_0b_flips;
        categoryHistogram* onelepFO_2j_1b_flips;
        categoryHistogram* onelepFO_2j_ge2b_flips;
        categoryHistogram* onelepFO_3j_0b_flips;
        categoryHistogram* onelepFO_3j_1b_flips;
        categoryHistogram* onelepFO_3j_ge2b_flips;
        categoryHistogram* onelepFO_ge4j_0b_flips;
        categoryHistogram* onelepFO_ge4j_1b_flips;
        categoryHistogram* onelepFO_ge4j_ge2b_flips;

        categoryHistogram* dilepFO_2j_0b_flips;
        categoryHistogram* dilepFO_2j_1b_flips;
        categoryHistogram* dilepFO_2j_ge2b_flips;
        categoryHistogram* dilepFO_3j_0b_flips;
        categoryHistogram* dilepFO_3j_1b_flips;
        categoryHistogram* dilepFO_3j_ge2b_flips;
        categoryHistogram* dilepFO_ge4j_0b_flips;
        categoryHistogram* dilepFO_ge4j_1b_flips;
        categoryHistogram* dilepFO_ge4j_ge2b_flips;



        categoryHistogram* trilep_2j_0b_other;
        categoryHistogram* trilep_2j_1b_other;
        categoryHistogram* trilep_2j_ge2b_other;
        categoryHistogram* trilep_3j_0b_other;
        categoryHistogram* trilep_3j_1b_other;
        categoryHistogram* trilep_3j_ge2b_other;
        categoryHistogram* trilep_ge4j_0b_other;
        categoryHistogram* trilep_ge4j_1b_other;
        categoryHistogram* trilep_ge4j_ge2b_other;

        categoryHistogram* SS_SF_dilep_2j_0b_other;
        categoryHistogram* SS_SF_dilep_2j_1b_other;
        categoryHistogram* SS_SF_dilep_2j_ge2b_other;
        categoryHistogram* SS_SF_dilep_3j_0b_other;
        categoryHistogram* SS_SF_dilep_3j_1b_other;
        categoryHistogram* SS_SF_dilep_3j_ge2b_other;
        categoryHistogram* SS_SF_dilep_ge4j_0b_other;
        categoryHistogram* SS_SF_dilep_ge4j_1b_other;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_other;

        categoryHistogram* SS_OF_dilep_2j_0b_other;
        categoryHistogram* SS_OF_dilep_2j_1b_other;
        categoryHistogram* SS_OF_dilep_2j_ge2b_other;
        categoryHistogram* SS_OF_dilep_3j_0b_other;
        categoryHistogram* SS_OF_dilep_3j_1b_other;
        categoryHistogram* SS_OF_dilep_3j_ge2b_other;
        categoryHistogram* SS_OF_dilep_ge4j_0b_other;
        categoryHistogram* SS_OF_dilep_ge4j_1b_other;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_other;

        categoryHistogram* OS_SF_dilep_2j_0b_other;
        categoryHistogram* OS_SF_dilep_2j_1b_other;
        categoryHistogram* OS_SF_dilep_2j_ge2b_other;
        categoryHistogram* OS_SF_dilep_3j_0b_other;
        categoryHistogram* OS_SF_dilep_3j_1b_other;
        categoryHistogram* OS_SF_dilep_3j_ge2b_other;
        categoryHistogram* OS_SF_dilep_ge4j_0b_other;
        categoryHistogram* OS_SF_dilep_ge4j_1b_other;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_other;

        categoryHistogram* OS_OF_dilep_2j_0b_other;
        categoryHistogram* OS_OF_dilep_2j_1b_other;
        categoryHistogram* OS_OF_dilep_2j_ge2b_other;
        categoryHistogram* OS_OF_dilep_3j_0b_other;
        categoryHistogram* OS_OF_dilep_3j_1b_other;
        categoryHistogram* OS_OF_dilep_3j_ge2b_other;
        categoryHistogram* OS_OF_dilep_ge4j_0b_other;
        categoryHistogram* OS_OF_dilep_ge4j_1b_other;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_other;

        categoryHistogram* onelepFO_2j_0b_other;
        categoryHistogram* onelepFO_2j_1b_other;
        categoryHistogram* onelepFO_2j_ge2b_other;
        categoryHistogram* onelepFO_3j_0b_other;
        categoryHistogram* onelepFO_3j_1b_other;
        categoryHistogram* onelepFO_3j_ge2b_other;
        categoryHistogram* onelepFO_ge4j_0b_other;
        categoryHistogram* onelepFO_ge4j_1b_other;
        categoryHistogram* onelepFO_ge4j_ge2b_other;

        categoryHistogram* dilepFO_2j_0b_other;
        categoryHistogram* dilepFO_2j_1b_other;
        categoryHistogram* dilepFO_2j_ge2b_other;
        categoryHistogram* dilepFO_3j_0b_other;
        categoryHistogram* dilepFO_3j_1b_other;
        categoryHistogram* dilepFO_3j_ge2b_other;
        categoryHistogram* dilepFO_ge4j_0b_other;
        categoryHistogram* dilepFO_ge4j_1b_other;
        categoryHistogram* dilepFO_ge4j_ge2b_other;



        categoryHistogram* trilep_2j_0b;
        categoryHistogram* trilep_2j_1b;
        categoryHistogram* trilep_2j_ge2b;
        categoryHistogram* trilep_3j_0b;
        categoryHistogram* trilep_3j_1b;
        categoryHistogram* trilep_3j_ge2b;
        categoryHistogram* trilep_ge4j_0b;
        categoryHistogram* trilep_ge4j_1b;
        categoryHistogram* trilep_ge4j_ge2b;

        categoryHistogram* SS_SF_dilep_2j_0b;
        categoryHistogram* SS_SF_dilep_2j_1b;
        categoryHistogram* SS_SF_dilep_2j_ge2b;
        categoryHistogram* SS_SF_dilep_3j_0b;
        categoryHistogram* SS_SF_dilep_3j_1b;
        categoryHistogram* SS_SF_dilep_3j_ge2b;
        categoryHistogram* SS_SF_dilep_ge4j_0b;
        categoryHistogram* SS_SF_dilep_ge4j_1b;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b;

        categoryHistogram* SS_OF_dilep_2j_0b;
        categoryHistogram* SS_OF_dilep_2j_1b;
        categoryHistogram* SS_OF_dilep_2j_ge2b;
        categoryHistogram* SS_OF_dilep_3j_0b;
        categoryHistogram* SS_OF_dilep_3j_1b;
        categoryHistogram* SS_OF_dilep_3j_ge2b;
        categoryHistogram* SS_OF_dilep_ge4j_0b;
        categoryHistogram* SS_OF_dilep_ge4j_1b;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b;

        categoryHistogram* OS_SF_dilep_2j_0b;
        categoryHistogram* OS_SF_dilep_2j_1b;
        categoryHistogram* OS_SF_dilep_2j_ge2b;
        categoryHistogram* OS_SF_dilep_3j_0b;
        categoryHistogram* OS_SF_dilep_3j_1b;
        categoryHistogram* OS_SF_dilep_3j_ge2b;
        categoryHistogram* OS_SF_dilep_ge4j_0b;
        categoryHistogram* OS_SF_dilep_ge4j_1b;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b;

        categoryHistogram* OS_OF_dilep_2j_0b;
        categoryHistogram* OS_OF_dilep_2j_1b;
        categoryHistogram* OS_OF_dilep_2j_ge2b;
        categoryHistogram* OS_OF_dilep_3j_0b;
        categoryHistogram* OS_OF_dilep_3j_1b;
        categoryHistogram* OS_OF_dilep_3j_ge2b;
        categoryHistogram* OS_OF_dilep_ge4j_0b;
        categoryHistogram* OS_OF_dilep_ge4j_1b;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b;

        categoryHistogram* onelepFO_2j_0b;
        categoryHistogram* onelepFO_2j_1b;
        categoryHistogram* onelepFO_2j_ge2b;
        categoryHistogram* onelepFO_3j_0b;
        categoryHistogram* onelepFO_3j_1b;
        categoryHistogram* onelepFO_3j_ge2b;
        categoryHistogram* onelepFO_ge4j_0b;
        categoryHistogram* onelepFO_ge4j_1b;
        categoryHistogram* onelepFO_ge4j_ge2b;

        categoryHistogram* dilepFO_2j_0b;
        categoryHistogram* dilepFO_2j_1b;
        categoryHistogram* dilepFO_2j_ge2b;
        categoryHistogram* dilepFO_3j_0b;
        categoryHistogram* dilepFO_3j_1b;
        categoryHistogram* dilepFO_3j_ge2b;
        categoryHistogram* dilepFO_ge4j_0b;
        categoryHistogram* dilepFO_ge4j_1b;
        categoryHistogram* dilepFO_ge4j_ge2b;





        categoryHistogram* trilep_2j_0b_fakeCR_fakes;
        categoryHistogram* trilep_2j_1b_fakeCR_fakes;
        categoryHistogram* trilep_2j_ge2b_fakeCR_fakes;
        categoryHistogram* trilep_3j_0b_fakeCR_fakes;
        categoryHistogram* trilep_3j_1b_fakeCR_fakes;
        categoryHistogram* trilep_3j_ge2b_fakeCR_fakes;
        categoryHistogram* trilep_ge4j_0b_fakeCR_fakes;
        categoryHistogram* trilep_ge4j_1b_fakeCR_fakes;
        categoryHistogram* trilep_ge4j_ge2b_fakeCR_fakes;

        categoryHistogram* SS_SF_dilep_2j_0b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_2j_1b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_2j_ge2b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_3j_0b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_3j_1b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_3j_ge2b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_0b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_1b_fakeCR_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_fakeCR_fakes;

        categoryHistogram* SS_OF_dilep_2j_0b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_2j_1b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_2j_ge2b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_3j_0b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_3j_1b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_3j_ge2b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_0b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_1b_fakeCR_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_fakeCR_fakes;

        categoryHistogram* OS_SF_dilep_2j_0b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_2j_1b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_2j_ge2b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_3j_0b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_3j_1b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_3j_ge2b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_0b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_1b_fakeCR_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_fakeCR_fakes;

        categoryHistogram* OS_OF_dilep_2j_0b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_2j_1b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_2j_ge2b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_3j_0b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_3j_1b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_3j_ge2b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_0b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_1b_fakeCR_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_fakeCR_fakes;

        categoryHistogram* onelepFO_2j_0b_fakeCR_fakes;
        categoryHistogram* onelepFO_2j_1b_fakeCR_fakes;
        categoryHistogram* onelepFO_2j_ge2b_fakeCR_fakes;
        categoryHistogram* onelepFO_3j_0b_fakeCR_fakes;
        categoryHistogram* onelepFO_3j_1b_fakeCR_fakes;
        categoryHistogram* onelepFO_3j_ge2b_fakeCR_fakes;
        categoryHistogram* onelepFO_ge4j_0b_fakeCR_fakes;
        categoryHistogram* onelepFO_ge4j_1b_fakeCR_fakes;
        categoryHistogram* onelepFO_ge4j_ge2b_fakeCR_fakes;

        categoryHistogram* dilepFO_2j_0b_fakeCR_fakes;
        categoryHistogram* dilepFO_2j_1b_fakeCR_fakes;
        categoryHistogram* dilepFO_2j_ge2b_fakeCR_fakes;
        categoryHistogram* dilepFO_3j_0b_fakeCR_fakes;
        categoryHistogram* dilepFO_3j_1b_fakeCR_fakes;
        categoryHistogram* dilepFO_3j_ge2b_fakeCR_fakes;
        categoryHistogram* dilepFO_ge4j_0b_fakeCR_fakes;
        categoryHistogram* dilepFO_ge4j_1b_fakeCR_fakes;
        categoryHistogram* dilepFO_ge4j_ge2b_fakeCR_fakes;



        categoryHistogram* trilep_2j_0b_fakeCR_flips;
        categoryHistogram* trilep_2j_1b_fakeCR_flips;
        categoryHistogram* trilep_2j_ge2b_fakeCR_flips;
        categoryHistogram* trilep_3j_0b_fakeCR_flips;
        categoryHistogram* trilep_3j_1b_fakeCR_flips;
        categoryHistogram* trilep_3j_ge2b_fakeCR_flips;
        categoryHistogram* trilep_ge4j_0b_fakeCR_flips;
        categoryHistogram* trilep_ge4j_1b_fakeCR_flips;
        categoryHistogram* trilep_ge4j_ge2b_fakeCR_flips;

        categoryHistogram* SS_SF_dilep_2j_0b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_2j_1b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_2j_ge2b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_3j_0b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_3j_1b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_3j_ge2b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_ge4j_0b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_ge4j_1b_fakeCR_flips;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_fakeCR_flips;

        categoryHistogram* SS_OF_dilep_2j_0b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_2j_1b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_2j_ge2b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_3j_0b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_3j_1b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_3j_ge2b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_ge4j_0b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_ge4j_1b_fakeCR_flips;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_fakeCR_flips;

        categoryHistogram* OS_SF_dilep_2j_0b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_2j_1b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_2j_ge2b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_3j_0b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_3j_1b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_3j_ge2b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_ge4j_0b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_ge4j_1b_fakeCR_flips;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_fakeCR_flips;

        categoryHistogram* OS_OF_dilep_2j_0b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_2j_1b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_2j_ge2b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_3j_0b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_3j_1b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_3j_ge2b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_ge4j_0b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_ge4j_1b_fakeCR_flips;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_fakeCR_flips;

        categoryHistogram* onelepFO_2j_0b_fakeCR_flips;
        categoryHistogram* onelepFO_2j_1b_fakeCR_flips;
        categoryHistogram* onelepFO_2j_ge2b_fakeCR_flips;
        categoryHistogram* onelepFO_3j_0b_fakeCR_flips;
        categoryHistogram* onelepFO_3j_1b_fakeCR_flips;
        categoryHistogram* onelepFO_3j_ge2b_fakeCR_flips;
        categoryHistogram* onelepFO_ge4j_0b_fakeCR_flips;
        categoryHistogram* onelepFO_ge4j_1b_fakeCR_flips;
        categoryHistogram* onelepFO_ge4j_ge2b_fakeCR_flips;

        categoryHistogram* dilepFO_2j_0b_fakeCR_flips;
        categoryHistogram* dilepFO_2j_1b_fakeCR_flips;
        categoryHistogram* dilepFO_2j_ge2b_fakeCR_flips;
        categoryHistogram* dilepFO_3j_0b_fakeCR_flips;
        categoryHistogram* dilepFO_3j_1b_fakeCR_flips;
        categoryHistogram* dilepFO_3j_ge2b_fakeCR_flips;
        categoryHistogram* dilepFO_ge4j_0b_fakeCR_flips;
        categoryHistogram* dilepFO_ge4j_1b_fakeCR_flips;
        categoryHistogram* dilepFO_ge4j_ge2b_fakeCR_flips;



        categoryHistogram* trilep_2j_0b_fakeCR_other;
        categoryHistogram* trilep_2j_1b_fakeCR_other;
        categoryHistogram* trilep_2j_ge2b_fakeCR_other;
        categoryHistogram* trilep_3j_0b_fakeCR_other;
        categoryHistogram* trilep_3j_1b_fakeCR_other;
        categoryHistogram* trilep_3j_ge2b_fakeCR_other;
        categoryHistogram* trilep_ge4j_0b_fakeCR_other;
        categoryHistogram* trilep_ge4j_1b_fakeCR_other;
        categoryHistogram* trilep_ge4j_ge2b_fakeCR_other;

        categoryHistogram* SS_SF_dilep_2j_0b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_2j_1b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_2j_ge2b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_3j_0b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_3j_1b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_3j_ge2b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_ge4j_0b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_ge4j_1b_fakeCR_other;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_fakeCR_other;

        categoryHistogram* SS_OF_dilep_2j_0b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_2j_1b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_2j_ge2b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_3j_0b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_3j_1b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_3j_ge2b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_ge4j_0b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_ge4j_1b_fakeCR_other;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_fakeCR_other;

        categoryHistogram* OS_SF_dilep_2j_0b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_2j_1b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_2j_ge2b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_3j_0b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_3j_1b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_3j_ge2b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_ge4j_0b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_ge4j_1b_fakeCR_other;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_fakeCR_other;

        categoryHistogram* OS_OF_dilep_2j_0b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_2j_1b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_2j_ge2b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_3j_0b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_3j_1b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_3j_ge2b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_ge4j_0b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_ge4j_1b_fakeCR_other;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_fakeCR_other;

        categoryHistogram* onelepFO_2j_0b_fakeCR_other;
        categoryHistogram* onelepFO_2j_1b_fakeCR_other;
        categoryHistogram* onelepFO_2j_ge2b_fakeCR_other;
        categoryHistogram* onelepFO_3j_0b_fakeCR_other;
        categoryHistogram* onelepFO_3j_1b_fakeCR_other;
        categoryHistogram* onelepFO_3j_ge2b_fakeCR_other;
        categoryHistogram* onelepFO_ge4j_0b_fakeCR_other;
        categoryHistogram* onelepFO_ge4j_1b_fakeCR_other;
        categoryHistogram* onelepFO_ge4j_ge2b_fakeCR_other;

        categoryHistogram* dilepFO_2j_0b_fakeCR_other;
        categoryHistogram* dilepFO_2j_1b_fakeCR_other;
        categoryHistogram* dilepFO_2j_ge2b_fakeCR_other;
        categoryHistogram* dilepFO_3j_0b_fakeCR_other;
        categoryHistogram* dilepFO_3j_1b_fakeCR_other;
        categoryHistogram* dilepFO_3j_ge2b_fakeCR_other;
        categoryHistogram* dilepFO_ge4j_0b_fakeCR_other;
        categoryHistogram* dilepFO_ge4j_1b_fakeCR_other;
        categoryHistogram* dilepFO_ge4j_ge2b_fakeCR_other;



        categoryHistogram* trilep_2j_0b_fakeCR;
        categoryHistogram* trilep_2j_1b_fakeCR;
        categoryHistogram* trilep_2j_ge2b_fakeCR;
        categoryHistogram* trilep_3j_0b_fakeCR;
        categoryHistogram* trilep_3j_1b_fakeCR;
        categoryHistogram* trilep_3j_ge2b_fakeCR;
        categoryHistogram* trilep_ge4j_0b_fakeCR;
        categoryHistogram* trilep_ge4j_1b_fakeCR;
        categoryHistogram* trilep_ge4j_ge2b_fakeCR;

        categoryHistogram* SS_SF_dilep_2j_0b_fakeCR;
        categoryHistogram* SS_SF_dilep_2j_1b_fakeCR;
        categoryHistogram* SS_SF_dilep_2j_ge2b_fakeCR;
        categoryHistogram* SS_SF_dilep_3j_0b_fakeCR;
        categoryHistogram* SS_SF_dilep_3j_1b_fakeCR;
        categoryHistogram* SS_SF_dilep_3j_ge2b_fakeCR;
        categoryHistogram* SS_SF_dilep_ge4j_0b_fakeCR;
        categoryHistogram* SS_SF_dilep_ge4j_1b_fakeCR;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_fakeCR;

        categoryHistogram* SS_OF_dilep_2j_0b_fakeCR;
        categoryHistogram* SS_OF_dilep_2j_1b_fakeCR;
        categoryHistogram* SS_OF_dilep_2j_ge2b_fakeCR;
        categoryHistogram* SS_OF_dilep_3j_0b_fakeCR;
        categoryHistogram* SS_OF_dilep_3j_1b_fakeCR;
        categoryHistogram* SS_OF_dilep_3j_ge2b_fakeCR;
        categoryHistogram* SS_OF_dilep_ge4j_0b_fakeCR;
        categoryHistogram* SS_OF_dilep_ge4j_1b_fakeCR;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_fakeCR;

        categoryHistogram* OS_SF_dilep_2j_0b_fakeCR;
        categoryHistogram* OS_SF_dilep_2j_1b_fakeCR;
        categoryHistogram* OS_SF_dilep_2j_ge2b_fakeCR;
        categoryHistogram* OS_SF_dilep_3j_0b_fakeCR;
        categoryHistogram* OS_SF_dilep_3j_1b_fakeCR;
        categoryHistogram* OS_SF_dilep_3j_ge2b_fakeCR;
        categoryHistogram* OS_SF_dilep_ge4j_0b_fakeCR;
        categoryHistogram* OS_SF_dilep_ge4j_1b_fakeCR;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_fakeCR;

        categoryHistogram* OS_OF_dilep_2j_0b_fakeCR;
        categoryHistogram* OS_OF_dilep_2j_1b_fakeCR;
        categoryHistogram* OS_OF_dilep_2j_ge2b_fakeCR;
        categoryHistogram* OS_OF_dilep_3j_0b_fakeCR;
        categoryHistogram* OS_OF_dilep_3j_1b_fakeCR;
        categoryHistogram* OS_OF_dilep_3j_ge2b_fakeCR;
        categoryHistogram* OS_OF_dilep_ge4j_0b_fakeCR;
        categoryHistogram* OS_OF_dilep_ge4j_1b_fakeCR;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_fakeCR;

        categoryHistogram* onelepFO_2j_0b_fakeCR;
        categoryHistogram* onelepFO_2j_1b_fakeCR;
        categoryHistogram* onelepFO_2j_ge2b_fakeCR;
        categoryHistogram* onelepFO_3j_0b_fakeCR;
        categoryHistogram* onelepFO_3j_1b_fakeCR;
        categoryHistogram* onelepFO_3j_ge2b_fakeCR;
        categoryHistogram* onelepFO_ge4j_0b_fakeCR;
        categoryHistogram* onelepFO_ge4j_1b_fakeCR;
        categoryHistogram* onelepFO_ge4j_ge2b_fakeCR;

        categoryHistogram* dilepFO_2j_0b_fakeCR;
        categoryHistogram* dilepFO_2j_1b_fakeCR;
        categoryHistogram* dilepFO_2j_ge2b_fakeCR;
        categoryHistogram* dilepFO_3j_0b_fakeCR;
        categoryHistogram* dilepFO_3j_1b_fakeCR;
        categoryHistogram* dilepFO_3j_ge2b_fakeCR;
        categoryHistogram* dilepFO_ge4j_0b_fakeCR;
        categoryHistogram* dilepFO_ge4j_1b_fakeCR;
        categoryHistogram* dilepFO_ge4j_ge2b_fakeCR;





        categoryHistogram* trilep_2j_0b_flipCR_fakes;
        categoryHistogram* trilep_2j_1b_flipCR_fakes;
        categoryHistogram* trilep_2j_ge2b_flipCR_fakes;
        categoryHistogram* trilep_3j_0b_flipCR_fakes;
        categoryHistogram* trilep_3j_1b_flipCR_fakes;
        categoryHistogram* trilep_3j_ge2b_flipCR_fakes;
        categoryHistogram* trilep_ge4j_0b_flipCR_fakes;
        categoryHistogram* trilep_ge4j_1b_flipCR_fakes;
        categoryHistogram* trilep_ge4j_ge2b_flipCR_fakes;

        categoryHistogram* SS_SF_dilep_2j_0b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_2j_1b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_2j_ge2b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_3j_0b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_3j_1b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_3j_ge2b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_0b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_1b_flipCR_fakes;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_flipCR_fakes;

        categoryHistogram* SS_OF_dilep_2j_0b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_2j_1b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_2j_ge2b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_3j_0b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_3j_1b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_3j_ge2b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_0b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_1b_flipCR_fakes;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_flipCR_fakes;

        categoryHistogram* OS_SF_dilep_2j_0b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_2j_1b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_2j_ge2b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_3j_0b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_3j_1b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_3j_ge2b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_0b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_1b_flipCR_fakes;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_flipCR_fakes;

        categoryHistogram* OS_OF_dilep_2j_0b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_2j_1b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_2j_ge2b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_3j_0b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_3j_1b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_3j_ge2b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_0b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_1b_flipCR_fakes;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_flipCR_fakes;

        categoryHistogram* onelepFO_2j_0b_flipCR_fakes;
        categoryHistogram* onelepFO_2j_1b_flipCR_fakes;
        categoryHistogram* onelepFO_2j_ge2b_flipCR_fakes;
        categoryHistogram* onelepFO_3j_0b_flipCR_fakes;
        categoryHistogram* onelepFO_3j_1b_flipCR_fakes;
        categoryHistogram* onelepFO_3j_ge2b_flipCR_fakes;
        categoryHistogram* onelepFO_ge4j_0b_flipCR_fakes;
        categoryHistogram* onelepFO_ge4j_1b_flipCR_fakes;
        categoryHistogram* onelepFO_ge4j_ge2b_flipCR_fakes;

        categoryHistogram* dilepFO_2j_0b_flipCR_fakes;
        categoryHistogram* dilepFO_2j_1b_flipCR_fakes;
        categoryHistogram* dilepFO_2j_ge2b_flipCR_fakes;
        categoryHistogram* dilepFO_3j_0b_flipCR_fakes;
        categoryHistogram* dilepFO_3j_1b_flipCR_fakes;
        categoryHistogram* dilepFO_3j_ge2b_flipCR_fakes;
        categoryHistogram* dilepFO_ge4j_0b_flipCR_fakes;
        categoryHistogram* dilepFO_ge4j_1b_flipCR_fakes;
        categoryHistogram* dilepFO_ge4j_ge2b_flipCR_fakes;



        categoryHistogram* trilep_2j_0b_flipCR_flips;
        categoryHistogram* trilep_2j_1b_flipCR_flips;
        categoryHistogram* trilep_2j_ge2b_flipCR_flips;
        categoryHistogram* trilep_3j_0b_flipCR_flips;
        categoryHistogram* trilep_3j_1b_flipCR_flips;
        categoryHistogram* trilep_3j_ge2b_flipCR_flips;
        categoryHistogram* trilep_ge4j_0b_flipCR_flips;
        categoryHistogram* trilep_ge4j_1b_flipCR_flips;
        categoryHistogram* trilep_ge4j_ge2b_flipCR_flips;

        categoryHistogram* SS_SF_dilep_2j_0b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_2j_1b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_2j_ge2b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_3j_0b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_3j_1b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_3j_ge2b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_ge4j_0b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_ge4j_1b_flipCR_flips;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_flipCR_flips;

        categoryHistogram* SS_OF_dilep_2j_0b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_2j_1b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_2j_ge2b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_3j_0b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_3j_1b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_3j_ge2b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_ge4j_0b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_ge4j_1b_flipCR_flips;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_flipCR_flips;

        categoryHistogram* OS_SF_dilep_2j_0b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_2j_1b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_2j_ge2b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_3j_0b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_3j_1b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_3j_ge2b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_ge4j_0b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_ge4j_1b_flipCR_flips;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_flipCR_flips;

        categoryHistogram* OS_OF_dilep_2j_0b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_2j_1b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_2j_ge2b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_3j_0b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_3j_1b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_3j_ge2b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_ge4j_0b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_ge4j_1b_flipCR_flips;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_flipCR_flips;

        categoryHistogram* onelepFO_2j_0b_flipCR_flips;
        categoryHistogram* onelepFO_2j_1b_flipCR_flips;
        categoryHistogram* onelepFO_2j_ge2b_flipCR_flips;
        categoryHistogram* onelepFO_3j_0b_flipCR_flips;
        categoryHistogram* onelepFO_3j_1b_flipCR_flips;
        categoryHistogram* onelepFO_3j_ge2b_flipCR_flips;
        categoryHistogram* onelepFO_ge4j_0b_flipCR_flips;
        categoryHistogram* onelepFO_ge4j_1b_flipCR_flips;
        categoryHistogram* onelepFO_ge4j_ge2b_flipCR_flips;

        categoryHistogram* dilepFO_2j_0b_flipCR_flips;
        categoryHistogram* dilepFO_2j_1b_flipCR_flips;
        categoryHistogram* dilepFO_2j_ge2b_flipCR_flips;
        categoryHistogram* dilepFO_3j_0b_flipCR_flips;
        categoryHistogram* dilepFO_3j_1b_flipCR_flips;
        categoryHistogram* dilepFO_3j_ge2b_flipCR_flips;
        categoryHistogram* dilepFO_ge4j_0b_flipCR_flips;
        categoryHistogram* dilepFO_ge4j_1b_flipCR_flips;
        categoryHistogram* dilepFO_ge4j_ge2b_flipCR_flips;



        categoryHistogram* trilep_2j_0b_flipCR_other;
        categoryHistogram* trilep_2j_1b_flipCR_other;
        categoryHistogram* trilep_2j_ge2b_flipCR_other;
        categoryHistogram* trilep_3j_0b_flipCR_other;
        categoryHistogram* trilep_3j_1b_flipCR_other;
        categoryHistogram* trilep_3j_ge2b_flipCR_other;
        categoryHistogram* trilep_ge4j_0b_flipCR_other;
        categoryHistogram* trilep_ge4j_1b_flipCR_other;
        categoryHistogram* trilep_ge4j_ge2b_flipCR_other;

        categoryHistogram* SS_SF_dilep_2j_0b_flipCR_other;
        categoryHistogram* SS_SF_dilep_2j_1b_flipCR_other;
        categoryHistogram* SS_SF_dilep_2j_ge2b_flipCR_other;
        categoryHistogram* SS_SF_dilep_3j_0b_flipCR_other;
        categoryHistogram* SS_SF_dilep_3j_1b_flipCR_other;
        categoryHistogram* SS_SF_dilep_3j_ge2b_flipCR_other;
        categoryHistogram* SS_SF_dilep_ge4j_0b_flipCR_other;
        categoryHistogram* SS_SF_dilep_ge4j_1b_flipCR_other;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_flipCR_other;

        categoryHistogram* SS_OF_dilep_2j_0b_flipCR_other;
        categoryHistogram* SS_OF_dilep_2j_1b_flipCR_other;
        categoryHistogram* SS_OF_dilep_2j_ge2b_flipCR_other;
        categoryHistogram* SS_OF_dilep_3j_0b_flipCR_other;
        categoryHistogram* SS_OF_dilep_3j_1b_flipCR_other;
        categoryHistogram* SS_OF_dilep_3j_ge2b_flipCR_other;
        categoryHistogram* SS_OF_dilep_ge4j_0b_flipCR_other;
        categoryHistogram* SS_OF_dilep_ge4j_1b_flipCR_other;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_flipCR_other;

        categoryHistogram* OS_SF_dilep_2j_0b_flipCR_other;
        categoryHistogram* OS_SF_dilep_2j_1b_flipCR_other;
        categoryHistogram* OS_SF_dilep_2j_ge2b_flipCR_other;
        categoryHistogram* OS_SF_dilep_3j_0b_flipCR_other;
        categoryHistogram* OS_SF_dilep_3j_1b_flipCR_other;
        categoryHistogram* OS_SF_dilep_3j_ge2b_flipCR_other;
        categoryHistogram* OS_SF_dilep_ge4j_0b_flipCR_other;
        categoryHistogram* OS_SF_dilep_ge4j_1b_flipCR_other;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_flipCR_other;

        categoryHistogram* OS_OF_dilep_2j_0b_flipCR_other;
        categoryHistogram* OS_OF_dilep_2j_1b_flipCR_other;
        categoryHistogram* OS_OF_dilep_2j_ge2b_flipCR_other;
        categoryHistogram* OS_OF_dilep_3j_0b_flipCR_other;
        categoryHistogram* OS_OF_dilep_3j_1b_flipCR_other;
        categoryHistogram* OS_OF_dilep_3j_ge2b_flipCR_other;
        categoryHistogram* OS_OF_dilep_ge4j_0b_flipCR_other;
        categoryHistogram* OS_OF_dilep_ge4j_1b_flipCR_other;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_flipCR_other;

        categoryHistogram* onelepFO_2j_0b_flipCR_other;
        categoryHistogram* onelepFO_2j_1b_flipCR_other;
        categoryHistogram* onelepFO_2j_ge2b_flipCR_other;
        categoryHistogram* onelepFO_3j_0b_flipCR_other;
        categoryHistogram* onelepFO_3j_1b_flipCR_other;
        categoryHistogram* onelepFO_3j_ge2b_flipCR_other;
        categoryHistogram* onelepFO_ge4j_0b_flipCR_other;
        categoryHistogram* onelepFO_ge4j_1b_flipCR_other;
        categoryHistogram* onelepFO_ge4j_ge2b_flipCR_other;

        categoryHistogram* dilepFO_2j_0b_flipCR_other;
        categoryHistogram* dilepFO_2j_1b_flipCR_other;
        categoryHistogram* dilepFO_2j_ge2b_flipCR_other;
        categoryHistogram* dilepFO_3j_0b_flipCR_other;
        categoryHistogram* dilepFO_3j_1b_flipCR_other;
        categoryHistogram* dilepFO_3j_ge2b_flipCR_other;
        categoryHistogram* dilepFO_ge4j_0b_flipCR_other;
        categoryHistogram* dilepFO_ge4j_1b_flipCR_other;
        categoryHistogram* dilepFO_ge4j_ge2b_flipCR_other;



        categoryHistogram* trilep_2j_0b_flipCR;
        categoryHistogram* trilep_2j_1b_flipCR;
        categoryHistogram* trilep_2j_ge2b_flipCR;
        categoryHistogram* trilep_3j_0b_flipCR;
        categoryHistogram* trilep_3j_1b_flipCR;
        categoryHistogram* trilep_3j_ge2b_flipCR;
        categoryHistogram* trilep_ge4j_0b_flipCR;
        categoryHistogram* trilep_ge4j_1b_flipCR;
        categoryHistogram* trilep_ge4j_ge2b_flipCR;

        categoryHistogram* SS_SF_dilep_2j_0b_flipCR;
        categoryHistogram* SS_SF_dilep_2j_1b_flipCR;
        categoryHistogram* SS_SF_dilep_2j_ge2b_flipCR;
        categoryHistogram* SS_SF_dilep_3j_0b_flipCR;
        categoryHistogram* SS_SF_dilep_3j_1b_flipCR;
        categoryHistogram* SS_SF_dilep_3j_ge2b_flipCR;
        categoryHistogram* SS_SF_dilep_ge4j_0b_flipCR;
        categoryHistogram* SS_SF_dilep_ge4j_1b_flipCR;
        categoryHistogram* SS_SF_dilep_ge4j_ge2b_flipCR;

        categoryHistogram* SS_OF_dilep_2j_0b_flipCR;
        categoryHistogram* SS_OF_dilep_2j_1b_flipCR;
        categoryHistogram* SS_OF_dilep_2j_ge2b_flipCR;
        categoryHistogram* SS_OF_dilep_3j_0b_flipCR;
        categoryHistogram* SS_OF_dilep_3j_1b_flipCR;
        categoryHistogram* SS_OF_dilep_3j_ge2b_flipCR;
        categoryHistogram* SS_OF_dilep_ge4j_0b_flipCR;
        categoryHistogram* SS_OF_dilep_ge4j_1b_flipCR;
        categoryHistogram* SS_OF_dilep_ge4j_ge2b_flipCR;

        categoryHistogram* OS_SF_dilep_2j_0b_flipCR;
        categoryHistogram* OS_SF_dilep_2j_1b_flipCR;
        categoryHistogram* OS_SF_dilep_2j_ge2b_flipCR;
        categoryHistogram* OS_SF_dilep_3j_0b_flipCR;
        categoryHistogram* OS_SF_dilep_3j_1b_flipCR;
        categoryHistogram* OS_SF_dilep_3j_ge2b_flipCR;
        categoryHistogram* OS_SF_dilep_ge4j_0b_flipCR;
        categoryHistogram* OS_SF_dilep_ge4j_1b_flipCR;
        categoryHistogram* OS_SF_dilep_ge4j_ge2b_flipCR;

        categoryHistogram* OS_OF_dilep_2j_0b_flipCR;
        categoryHistogram* OS_OF_dilep_2j_1b_flipCR;
        categoryHistogram* OS_OF_dilep_2j_ge2b_flipCR;
        categoryHistogram* OS_OF_dilep_3j_0b_flipCR;
        categoryHistogram* OS_OF_dilep_3j_1b_flipCR;
        categoryHistogram* OS_OF_dilep_3j_ge2b_flipCR;
        categoryHistogram* OS_OF_dilep_ge4j_0b_flipCR;
        categoryHistogram* OS_OF_dilep_ge4j_1b_flipCR;
        categoryHistogram* OS_OF_dilep_ge4j_ge2b_flipCR;

        categoryHistogram* onelepFO_2j_0b_flipCR;
        categoryHistogram* onelepFO_2j_1b_flipCR;
        categoryHistogram* onelepFO_2j_ge2b_flipCR;
        categoryHistogram* onelepFO_3j_0b_flipCR;
        categoryHistogram* onelepFO_3j_1b_flipCR;
        categoryHistogram* onelepFO_3j_ge2b_flipCR;
        categoryHistogram* onelepFO_ge4j_0b_flipCR;
        categoryHistogram* onelepFO_ge4j_1b_flipCR;
        categoryHistogram* onelepFO_ge4j_ge2b_flipCR;

        categoryHistogram* dilepFO_2j_0b_flipCR;
        categoryHistogram* dilepFO_2j_1b_flipCR;
        categoryHistogram* dilepFO_2j_ge2b_flipCR;
        categoryHistogram* dilepFO_3j_0b_flipCR;
        categoryHistogram* dilepFO_3j_1b_flipCR;
        categoryHistogram* dilepFO_3j_ge2b_flipCR;
        categoryHistogram* dilepFO_ge4j_0b_flipCR;
        categoryHistogram* dilepFO_ge4j_1b_flipCR;
        categoryHistogram* dilepFO_ge4j_ge2b_flipCR;

    public:
        makeHistograms(string category){
            if (category == "background"){

                //***********************************************************
                //***********************************************************
                //***********************************************************
                //SR
                //***********************************************************
                //***********************************************************
                //***********************************************************
                trilep_2j_0b_fakes      = new categoryHistogram("trilep","2j","0b","fakes");
                trilep_2j_1b_fakes      = new categoryHistogram("trilep","2j","1b","fakes");
                trilep_2j_ge2b_fakes    = new categoryHistogram("trilep","2j","ge2b","fakes");
                trilep_3j_0b_fakes      = new categoryHistogram("trilep","3j","0b","fakes");
                trilep_3j_1b_fakes      = new categoryHistogram("trilep","3j","1b","fakes");
                trilep_3j_ge2b_fakes    = new categoryHistogram("trilep","3j","ge2b","fakes");
                trilep_ge4j_0b_fakes    = new categoryHistogram("trilep","ge4j","0b","fakes");
                trilep_ge4j_1b_fakes    = new categoryHistogram("trilep","ge4j","1b","fakes");
                trilep_ge4j_ge2b_fakes  = new categoryHistogram("trilep","ge4j","ge2b","fakes");

                SS_SF_dilep_2j_0b_fakes     = new categoryHistogram("SS_SF_dilep","2j","0b","fakes");
                SS_SF_dilep_2j_1b_fakes     = new categoryHistogram("SS_SF_dilep","2j","1b","fakes");
                SS_SF_dilep_2j_ge2b_fakes   = new categoryHistogram("SS_SF_dilep","2j","ge2b","fakes");
                SS_SF_dilep_3j_0b_fakes     = new categoryHistogram("SS_SF_dilep","3j","0b","fakes");
                SS_SF_dilep_3j_1b_fakes     = new categoryHistogram("SS_SF_dilep","3j","1b","fakes");
                SS_SF_dilep_3j_ge2b_fakes   = new categoryHistogram("SS_SF_dilep","3j","ge2b","fakes");
                SS_SF_dilep_ge4j_0b_fakes   = new categoryHistogram("SS_SF_dilep","ge4j","0b","fakes");
                SS_SF_dilep_ge4j_1b_fakes   = new categoryHistogram("SS_SF_dilep","ge4j","1b","fakes");
                SS_SF_dilep_ge4j_ge2b_fakes = new categoryHistogram("SS_SF_dilep","ge4j","ge2b","fakes");

                SS_OF_dilep_2j_0b_fakes     = new categoryHistogram("SS_OF_dilep","2j","0b","fakes");
                SS_OF_dilep_2j_1b_fakes     = new categoryHistogram("SS_OF_dilep","2j","1b","fakes");
                SS_OF_dilep_2j_ge2b_fakes   = new categoryHistogram("SS_OF_dilep","2j","ge2b","fakes");
                SS_OF_dilep_3j_0b_fakes     = new categoryHistogram("SS_OF_dilep","3j","0b","fakes");
                SS_OF_dilep_3j_1b_fakes     = new categoryHistogram("SS_OF_dilep","3j","1b","fakes");
                SS_OF_dilep_3j_ge2b_fakes   = new categoryHistogram("SS_OF_dilep","3j","ge2b","fakes");
                SS_OF_dilep_ge4j_0b_fakes   = new categoryHistogram("SS_OF_dilep","ge4j","0b","fakes");
                SS_OF_dilep_ge4j_1b_fakes   = new categoryHistogram("SS_OF_dilep","ge4j","1b","fakes");
                SS_OF_dilep_ge4j_ge2b_fakes = new categoryHistogram("SS_OF_dilep","ge4j","ge2b","fakes");

                OS_SF_dilep_2j_0b_fakes     = new categoryHistogram("OS_SF_dilep","2j","0b","fakes");
                OS_SF_dilep_2j_1b_fakes     = new categoryHistogram("OS_SF_dilep","2j","1b","fakes");
                OS_SF_dilep_2j_ge2b_fakes   = new categoryHistogram("OS_SF_dilep","2j","ge2b","fakes");
                OS_SF_dilep_3j_0b_fakes     = new categoryHistogram("OS_SF_dilep","3j","0b","fakes");
                OS_SF_dilep_3j_1b_fakes     = new categoryHistogram("OS_SF_dilep","3j","1b","fakes");
                OS_SF_dilep_3j_ge2b_fakes   = new categoryHistogram("OS_SF_dilep","3j","ge2b","fakes");
                OS_SF_dilep_ge4j_0b_fakes   = new categoryHistogram("OS_SF_dilep","ge4j","0b","fakes");
                OS_SF_dilep_ge4j_1b_fakes   = new categoryHistogram("OS_SF_dilep","ge4j","1b","fakes");
                OS_SF_dilep_ge4j_ge2b_fakes = new categoryHistogram("OS_SF_dilep","ge4j","ge2b","fakes");

                OS_OF_dilep_2j_0b_fakes     = new categoryHistogram("OS_OF_dilep","2j","0b","fakes");
                OS_OF_dilep_2j_1b_fakes     = new categoryHistogram("OS_OF_dilep","2j","1b","fakes");
                OS_OF_dilep_2j_ge2b_fakes   = new categoryHistogram("OS_OF_dilep","2j","ge2b","fakes");
                OS_OF_dilep_3j_0b_fakes     = new categoryHistogram("OS_OF_dilep","3j","0b","fakes");
                OS_OF_dilep_3j_1b_fakes     = new categoryHistogram("OS_OF_dilep","3j","1b","fakes");
                OS_OF_dilep_3j_ge2b_fakes   = new categoryHistogram("OS_OF_dilep","3j","ge2b","fakes");
                OS_OF_dilep_ge4j_0b_fakes   = new categoryHistogram("OS_OF_dilep","ge4j","0b","fakes");
                OS_OF_dilep_ge4j_1b_fakes   = new categoryHistogram("OS_OF_dilep","ge4j","1b","fakes");
                OS_OF_dilep_ge4j_ge2b_fakes = new categoryHistogram("OS_OF_dilep","ge4j","ge2b","fakes");

                onelepFO_2j_0b_fakes        = new categoryHistogram("onelepFO","2j","0b","fakes");
                onelepFO_2j_1b_fakes        = new categoryHistogram("onelepFO","2j","1b","fakes");
                onelepFO_2j_ge2b_fakes      = new categoryHistogram("onelepFO","2j","ge2b","fakes");
                onelepFO_3j_0b_fakes        = new categoryHistogram("onelepFO","3j","0b","fakes");
                onelepFO_3j_1b_fakes        = new categoryHistogram("onelepFO","3j","1b","fakes");
                onelepFO_3j_ge2b_fakes      = new categoryHistogram("onelepFO","3j","ge2b","fakes");
                onelepFO_ge4j_0b_fakes      = new categoryHistogram("onelepFO","ge4j","0b","fakes");
                onelepFO_ge4j_1b_fakes      = new categoryHistogram("onelepFO","ge4j","1b","fakes");
                onelepFO_ge4j_ge2b_fakes    = new categoryHistogram("onelepFO","ge4j","ge2b","fakes");

                dilepFO_2j_0b_fakes         = new categoryHistogram("dilepFO","2j","0b","fakes");
                dilepFO_2j_1b_fakes         = new categoryHistogram("dilepFO","2j","1b","fakes");
                dilepFO_2j_ge2b_fakes       = new categoryHistogram("dilepFO","2j","ge2b","fakes");
                dilepFO_3j_0b_fakes         = new categoryHistogram("dilepFO","3j","0b","fakes");
                dilepFO_3j_1b_fakes         = new categoryHistogram("dilepFO","3j","1b","fakes");
                dilepFO_3j_ge2b_fakes       = new categoryHistogram("dilepFO","3j","ge2b","fakes");
                dilepFO_ge4j_0b_fakes       = new categoryHistogram("dilepFO","ge4j","0b","fakes");
                dilepFO_ge4j_1b_fakes       = new categoryHistogram("dilepFO","ge4j","1b","fakes");
                dilepFO_ge4j_ge2b_fakes     = new categoryHistogram("dilepFO","ge4j","ge2b","fakes");



                trilep_2j_0b_flips      = new categoryHistogram("trilep","2j","0b","flips");
                trilep_2j_1b_flips      = new categoryHistogram("trilep","2j","1b","flips");
                trilep_2j_ge2b_flips    = new categoryHistogram("trilep","2j","ge2b","flips");
                trilep_3j_0b_flips      = new categoryHistogram("trilep","3j","0b","flips");
                trilep_3j_1b_flips      = new categoryHistogram("trilep","3j","1b","flips");
                trilep_3j_ge2b_flips    = new categoryHistogram("trilep","3j","ge2b","flips");
                trilep_ge4j_0b_flips    = new categoryHistogram("trilep","ge4j","0b","flips");
                trilep_ge4j_1b_flips    = new categoryHistogram("trilep","ge4j","1b","flips");
                trilep_ge4j_ge2b_flips  = new categoryHistogram("trilep","ge4j","ge2b","flips");

                SS_SF_dilep_2j_0b_flips     = new categoryHistogram("SS_SF_dilep","2j","0b","flips");
                SS_SF_dilep_2j_1b_flips     = new categoryHistogram("SS_SF_dilep","2j","1b","flips");
                SS_SF_dilep_2j_ge2b_flips   = new categoryHistogram("SS_SF_dilep","2j","ge2b","flips");
                SS_SF_dilep_3j_0b_flips     = new categoryHistogram("SS_SF_dilep","3j","0b","flips");
                SS_SF_dilep_3j_1b_flips     = new categoryHistogram("SS_SF_dilep","3j","1b","flips");
                SS_SF_dilep_3j_ge2b_flips   = new categoryHistogram("SS_SF_dilep","3j","ge2b","flips");
                SS_SF_dilep_ge4j_0b_flips   = new categoryHistogram("SS_SF_dilep","ge4j","0b","flips");
                SS_SF_dilep_ge4j_1b_flips   = new categoryHistogram("SS_SF_dilep","ge4j","1b","flips");
                SS_SF_dilep_ge4j_ge2b_flips = new categoryHistogram("SS_SF_dilep","ge4j","ge2b","flips");

                SS_OF_dilep_2j_0b_flips     = new categoryHistogram("SS_OF_dilep","2j","0b","flips");
                SS_OF_dilep_2j_1b_flips     = new categoryHistogram("SS_OF_dilep","2j","1b","flips");
                SS_OF_dilep_2j_ge2b_flips   = new categoryHistogram("SS_OF_dilep","2j","ge2b","flips");
                SS_OF_dilep_3j_0b_flips     = new categoryHistogram("SS_OF_dilep","3j","0b","flips");
                SS_OF_dilep_3j_1b_flips     = new categoryHistogram("SS_OF_dilep","3j","1b","flips");
                SS_OF_dilep_3j_ge2b_flips   = new categoryHistogram("SS_OF_dilep","3j","ge2b","flips");
                SS_OF_dilep_ge4j_0b_flips   = new categoryHistogram("SS_OF_dilep","ge4j","0b","flips");
                SS_OF_dilep_ge4j_1b_flips   = new categoryHistogram("SS_OF_dilep","ge4j","1b","flips");
                SS_OF_dilep_ge4j_ge2b_flips = new categoryHistogram("SS_OF_dilep","ge4j","ge2b","flips");

                OS_SF_dilep_2j_0b_flips     = new categoryHistogram("OS_SF_dilep","2j","0b","flips");
                OS_SF_dilep_2j_1b_flips     = new categoryHistogram("OS_SF_dilep","2j","1b","flips");
                OS_SF_dilep_2j_ge2b_flips   = new categoryHistogram("OS_SF_dilep","2j","ge2b","flips");
                OS_SF_dilep_3j_0b_flips     = new categoryHistogram("OS_SF_dilep","3j","0b","flips");
                OS_SF_dilep_3j_1b_flips     = new categoryHistogram("OS_SF_dilep","3j","1b","flips");
                OS_SF_dilep_3j_ge2b_flips   = new categoryHistogram("OS_SF_dilep","3j","ge2b","flips");
                OS_SF_dilep_ge4j_0b_flips   = new categoryHistogram("OS_SF_dilep","ge4j","0b","flips");
                OS_SF_dilep_ge4j_1b_flips   = new categoryHistogram("OS_SF_dilep","ge4j","1b","flips");
                OS_SF_dilep_ge4j_ge2b_flips = new categoryHistogram("OS_SF_dilep","ge4j","ge2b","flips");

                OS_OF_dilep_2j_0b_flips     = new categoryHistogram("OS_OF_dilep","2j","0b","flips");
                OS_OF_dilep_2j_1b_flips     = new categoryHistogram("OS_OF_dilep","2j","1b","flips");
                OS_OF_dilep_2j_ge2b_flips   = new categoryHistogram("OS_OF_dilep","2j","ge2b","flips");
                OS_OF_dilep_3j_0b_flips     = new categoryHistogram("OS_OF_dilep","3j","0b","flips");
                OS_OF_dilep_3j_1b_flips     = new categoryHistogram("OS_OF_dilep","3j","1b","flips");
                OS_OF_dilep_3j_ge2b_flips   = new categoryHistogram("OS_OF_dilep","3j","ge2b","flips");
                OS_OF_dilep_ge4j_0b_flips   = new categoryHistogram("OS_OF_dilep","ge4j","0b","flips");
                OS_OF_dilep_ge4j_1b_flips   = new categoryHistogram("OS_OF_dilep","ge4j","1b","flips");
                OS_OF_dilep_ge4j_ge2b_flips = new categoryHistogram("OS_OF_dilep","ge4j","ge2b","flips");

                onelepFO_2j_0b_flips        = new categoryHistogram("onelepFO","2j","0b","flips");
                onelepFO_2j_1b_flips        = new categoryHistogram("onelepFO","2j","1b","flips");
                onelepFO_2j_ge2b_flips      = new categoryHistogram("onelepFO","2j","ge2b","flips");
                onelepFO_3j_0b_flips        = new categoryHistogram("onelepFO","3j","0b","flips");
                onelepFO_3j_1b_flips        = new categoryHistogram("onelepFO","3j","1b","flips");
                onelepFO_3j_ge2b_flips      = new categoryHistogram("onelepFO","3j","ge2b","flips");
                onelepFO_ge4j_0b_flips      = new categoryHistogram("onelepFO","ge4j","0b","flips");
                onelepFO_ge4j_1b_flips      = new categoryHistogram("onelepFO","ge4j","1b","flips");
                onelepFO_ge4j_ge2b_flips    = new categoryHistogram("onelepFO","ge4j","ge2b","flips");

                dilepFO_2j_0b_flips         = new categoryHistogram("dilepFO","2j","0b","flips");
                dilepFO_2j_1b_flips         = new categoryHistogram("dilepFO","2j","1b","flips");
                dilepFO_2j_ge2b_flips       = new categoryHistogram("dilepFO","2j","ge2b","flips");
                dilepFO_3j_0b_flips         = new categoryHistogram("dilepFO","3j","0b","flips");
                dilepFO_3j_1b_flips         = new categoryHistogram("dilepFO","3j","1b","flips");
                dilepFO_3j_ge2b_flips       = new categoryHistogram("dilepFO","3j","ge2b","flips");
                dilepFO_ge4j_0b_flips       = new categoryHistogram("dilepFO","ge4j","0b","flips");
                dilepFO_ge4j_1b_flips       = new categoryHistogram("dilepFO","ge4j","1b","flips");
                dilepFO_ge4j_ge2b_flips     = new categoryHistogram("dilepFO","ge4j","ge2b","flips");



                trilep_2j_0b_other      = new categoryHistogram("trilep","2j","0b","other");
                trilep_2j_1b_other      = new categoryHistogram("trilep","2j","1b","other");
                trilep_2j_ge2b_other    = new categoryHistogram("trilep","2j","ge2b","other");
                trilep_3j_0b_other      = new categoryHistogram("trilep","3j","0b","other");
                trilep_3j_1b_other      = new categoryHistogram("trilep","3j","1b","other");
                trilep_3j_ge2b_other    = new categoryHistogram("trilep","3j","ge2b","other");
                trilep_ge4j_0b_other    = new categoryHistogram("trilep","ge4j","0b","other");
                trilep_ge4j_1b_other    = new categoryHistogram("trilep","ge4j","1b","other");
                trilep_ge4j_ge2b_other  = new categoryHistogram("trilep","ge4j","ge2b","other");

                SS_SF_dilep_2j_0b_other     = new categoryHistogram("SS_SF_dilep","2j","0b","other");
                SS_SF_dilep_2j_1b_other     = new categoryHistogram("SS_SF_dilep","2j","1b","other");
                SS_SF_dilep_2j_ge2b_other   = new categoryHistogram("SS_SF_dilep","2j","ge2b","other");
                SS_SF_dilep_3j_0b_other     = new categoryHistogram("SS_SF_dilep","3j","0b","other");
                SS_SF_dilep_3j_1b_other     = new categoryHistogram("SS_SF_dilep","3j","1b","other");
                SS_SF_dilep_3j_ge2b_other   = new categoryHistogram("SS_SF_dilep","3j","ge2b","other");
                SS_SF_dilep_ge4j_0b_other   = new categoryHistogram("SS_SF_dilep","ge4j","0b","other");
                SS_SF_dilep_ge4j_1b_other   = new categoryHistogram("SS_SF_dilep","ge4j","1b","other");
                SS_SF_dilep_ge4j_ge2b_other = new categoryHistogram("SS_SF_dilep","ge4j","ge2b","other");

                SS_OF_dilep_2j_0b_other     = new categoryHistogram("SS_OF_dilep","2j","0b","other");
                SS_OF_dilep_2j_1b_other     = new categoryHistogram("SS_OF_dilep","2j","1b","other");
                SS_OF_dilep_2j_ge2b_other   = new categoryHistogram("SS_OF_dilep","2j","ge2b","other");
                SS_OF_dilep_3j_0b_other     = new categoryHistogram("SS_OF_dilep","3j","0b","other");
                SS_OF_dilep_3j_1b_other     = new categoryHistogram("SS_OF_dilep","3j","1b","other");
                SS_OF_dilep_3j_ge2b_other   = new categoryHistogram("SS_OF_dilep","3j","ge2b","other");
                SS_OF_dilep_ge4j_0b_other   = new categoryHistogram("SS_OF_dilep","ge4j","0b","other");
                SS_OF_dilep_ge4j_1b_other   = new categoryHistogram("SS_OF_dilep","ge4j","1b","other");
                SS_OF_dilep_ge4j_ge2b_other = new categoryHistogram("SS_OF_dilep","ge4j","ge2b","other");

                OS_SF_dilep_2j_0b_other     = new categoryHistogram("OS_SF_dilep","2j","0b","other");
                OS_SF_dilep_2j_1b_other     = new categoryHistogram("OS_SF_dilep","2j","1b","other");
                OS_SF_dilep_2j_ge2b_other   = new categoryHistogram("OS_SF_dilep","2j","ge2b","other");
                OS_SF_dilep_3j_0b_other     = new categoryHistogram("OS_SF_dilep","3j","0b","other");
                OS_SF_dilep_3j_1b_other     = new categoryHistogram("OS_SF_dilep","3j","1b","other");
                OS_SF_dilep_3j_ge2b_other   = new categoryHistogram("OS_SF_dilep","3j","ge2b","other");
                OS_SF_dilep_ge4j_0b_other   = new categoryHistogram("OS_SF_dilep","ge4j","0b","other");
                OS_SF_dilep_ge4j_1b_other   = new categoryHistogram("OS_SF_dilep","ge4j","1b","other");
                OS_SF_dilep_ge4j_ge2b_other = new categoryHistogram("OS_SF_dilep","ge4j","ge2b","other");

                OS_OF_dilep_2j_0b_other     = new categoryHistogram("OS_OF_dilep","2j","0b","other");
                OS_OF_dilep_2j_1b_other     = new categoryHistogram("OS_OF_dilep","2j","1b","other");
                OS_OF_dilep_2j_ge2b_other   = new categoryHistogram("OS_OF_dilep","2j","ge2b","other");
                OS_OF_dilep_3j_0b_other     = new categoryHistogram("OS_OF_dilep","3j","0b","other");
                OS_OF_dilep_3j_1b_other     = new categoryHistogram("OS_OF_dilep","3j","1b","other");
                OS_OF_dilep_3j_ge2b_other   = new categoryHistogram("OS_OF_dilep","3j","ge2b","other");
                OS_OF_dilep_ge4j_0b_other   = new categoryHistogram("OS_OF_dilep","ge4j","0b","other");
                OS_OF_dilep_ge4j_1b_other   = new categoryHistogram("OS_OF_dilep","ge4j","1b","other");
                OS_OF_dilep_ge4j_ge2b_other = new categoryHistogram("OS_OF_dilep","ge4j","ge2b","other");

                onelepFO_2j_0b_other        = new categoryHistogram("onelepFO","2j","0b","other");
                onelepFO_2j_1b_other        = new categoryHistogram("onelepFO","2j","1b","other");
                onelepFO_2j_ge2b_other      = new categoryHistogram("onelepFO","2j","ge2b","other");
                onelepFO_3j_0b_other        = new categoryHistogram("onelepFO","3j","0b","other");
                onelepFO_3j_1b_other        = new categoryHistogram("onelepFO","3j","1b","other");
                onelepFO_3j_ge2b_other      = new categoryHistogram("onelepFO","3j","ge2b","other");
                onelepFO_ge4j_0b_other      = new categoryHistogram("onelepFO","ge4j","0b","other");
                onelepFO_ge4j_1b_other      = new categoryHistogram("onelepFO","ge4j","1b","other");
                onelepFO_ge4j_ge2b_other    = new categoryHistogram("onelepFO","ge4j","ge2b","other");

                dilepFO_2j_0b_other         = new categoryHistogram("dilepFO","2j","0b","other");
                dilepFO_2j_1b_other         = new categoryHistogram("dilepFO","2j","1b","other");
                dilepFO_2j_ge2b_other       = new categoryHistogram("dilepFO","2j","ge2b","other");
                dilepFO_3j_0b_other         = new categoryHistogram("dilepFO","3j","0b","other");
                dilepFO_3j_1b_other         = new categoryHistogram("dilepFO","3j","1b","other");
                dilepFO_3j_ge2b_other       = new categoryHistogram("dilepFO","3j","ge2b","other");
                dilepFO_ge4j_0b_other       = new categoryHistogram("dilepFO","ge4j","0b","other");
                dilepFO_ge4j_1b_other       = new categoryHistogram("dilepFO","ge4j","1b","other");
                dilepFO_ge4j_ge2b_other     = new categoryHistogram("dilepFO","ge4j","ge2b","other");



                //***********************************************************
                //***********************************************************
                //***********************************************************
                //FAKE CR
                //***********************************************************
                //***********************************************************
                //***********************************************************
                trilep_2j_0b_fakeCR_fakes      = new categoryHistogram("trilep_fakeCR","2j","0b","fakes");
                trilep_2j_1b_fakeCR_fakes      = new categoryHistogram("trilep_fakeCR","2j","1b","fakes");
                trilep_2j_ge2b_fakeCR_fakes    = new categoryHistogram("trilep_fakeCR","2j","ge2b","fakes");
                trilep_3j_0b_fakeCR_fakes      = new categoryHistogram("trilep_fakeCR","3j","0b","fakes");
                trilep_3j_1b_fakeCR_fakes      = new categoryHistogram("trilep_fakeCR","3j","1b","fakes");
                trilep_3j_ge2b_fakeCR_fakes    = new categoryHistogram("trilep_fakeCR","3j","ge2b","fakes");
                trilep_ge4j_0b_fakeCR_fakes    = new categoryHistogram("trilep_fakeCR","ge4j","0b","fakes");
                trilep_ge4j_1b_fakeCR_fakes    = new categoryHistogram("trilep_fakeCR","ge4j","1b","fakes");
                trilep_ge4j_ge2b_fakeCR_fakes  = new categoryHistogram("trilep_fakeCR","ge4j","ge2b","fakes");

                SS_SF_dilep_2j_0b_fakeCR_fakes     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","0b","fakes");
                SS_SF_dilep_2j_1b_fakeCR_fakes     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","1b","fakes");
                SS_SF_dilep_2j_ge2b_fakeCR_fakes   = new categoryHistogram("SS_SF_dilep_fakeCR","2j","ge2b","fakes");
                SS_SF_dilep_3j_0b_fakeCR_fakes     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","0b","fakes");
                SS_SF_dilep_3j_1b_fakeCR_fakes     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","1b","fakes");
                SS_SF_dilep_3j_ge2b_fakeCR_fakes   = new categoryHistogram("SS_SF_dilep_fakeCR","3j","ge2b","fakes");
                SS_SF_dilep_ge4j_0b_fakeCR_fakes   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","0b","fakes");
                SS_SF_dilep_ge4j_1b_fakeCR_fakes   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","1b","fakes");
                SS_SF_dilep_ge4j_ge2b_fakeCR_fakes = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","ge2b","fakes");

                SS_OF_dilep_2j_0b_fakeCR_fakes     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","0b","fakes");
                SS_OF_dilep_2j_1b_fakeCR_fakes     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","1b","fakes");
                SS_OF_dilep_2j_ge2b_fakeCR_fakes   = new categoryHistogram("SS_OF_dilep_fakeCR","2j","ge2b","fakes");
                SS_OF_dilep_3j_0b_fakeCR_fakes     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","0b","fakes");
                SS_OF_dilep_3j_1b_fakeCR_fakes     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","1b","fakes");
                SS_OF_dilep_3j_ge2b_fakeCR_fakes   = new categoryHistogram("SS_OF_dilep_fakeCR","3j","ge2b","fakes");
                SS_OF_dilep_ge4j_0b_fakeCR_fakes   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","0b","fakes");
                SS_OF_dilep_ge4j_1b_fakeCR_fakes   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","1b","fakes");
                SS_OF_dilep_ge4j_ge2b_fakeCR_fakes = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","ge2b","fakes");

                OS_SF_dilep_2j_0b_fakeCR_fakes     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","0b","fakes");
                OS_SF_dilep_2j_1b_fakeCR_fakes     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","1b","fakes");
                OS_SF_dilep_2j_ge2b_fakeCR_fakes   = new categoryHistogram("OS_SF_dilep_fakeCR","2j","ge2b","fakes");
                OS_SF_dilep_3j_0b_fakeCR_fakes     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","0b","fakes");
                OS_SF_dilep_3j_1b_fakeCR_fakes     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","1b","fakes");
                OS_SF_dilep_3j_ge2b_fakeCR_fakes   = new categoryHistogram("OS_SF_dilep_fakeCR","3j","ge2b","fakes");
                OS_SF_dilep_ge4j_0b_fakeCR_fakes   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","0b","fakes");
                OS_SF_dilep_ge4j_1b_fakeCR_fakes   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","1b","fakes");
                OS_SF_dilep_ge4j_ge2b_fakeCR_fakes = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","ge2b","fakes");

                OS_OF_dilep_2j_0b_fakeCR_fakes     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","0b","fakes");
                OS_OF_dilep_2j_1b_fakeCR_fakes     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","1b","fakes");
                OS_OF_dilep_2j_ge2b_fakeCR_fakes   = new categoryHistogram("OS_OF_dilep_fakeCR","2j","ge2b","fakes");
                OS_OF_dilep_3j_0b_fakeCR_fakes     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","0b","fakes");
                OS_OF_dilep_3j_1b_fakeCR_fakes     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","1b","fakes");
                OS_OF_dilep_3j_ge2b_fakeCR_fakes   = new categoryHistogram("OS_OF_dilep_fakeCR","3j","ge2b","fakes");
                OS_OF_dilep_ge4j_0b_fakeCR_fakes   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","0b","fakes");
                OS_OF_dilep_ge4j_1b_fakeCR_fakes   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","1b","fakes");
                OS_OF_dilep_ge4j_ge2b_fakeCR_fakes = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","ge2b","fakes");

                onelepFO_2j_0b_fakeCR_fakes        = new categoryHistogram("onelepFO_fakeCR","2j","0b","fakes");
                onelepFO_2j_1b_fakeCR_fakes        = new categoryHistogram("onelepFO_fakeCR","2j","1b","fakes");
                onelepFO_2j_ge2b_fakeCR_fakes      = new categoryHistogram("onelepFO_fakeCR","2j","ge2b","fakes");
                onelepFO_3j_0b_fakeCR_fakes        = new categoryHistogram("onelepFO_fakeCR","3j","0b","fakes");
                onelepFO_3j_1b_fakeCR_fakes        = new categoryHistogram("onelepFO_fakeCR","3j","1b","fakes");
                onelepFO_3j_ge2b_fakeCR_fakes      = new categoryHistogram("onelepFO_fakeCR","3j","ge2b","fakes");
                onelepFO_ge4j_0b_fakeCR_fakes      = new categoryHistogram("onelepFO_fakeCR","ge4j","0b","fakes");
                onelepFO_ge4j_1b_fakeCR_fakes      = new categoryHistogram("onelepFO_fakeCR","ge4j","1b","fakes");
                onelepFO_ge4j_ge2b_fakeCR_fakes    = new categoryHistogram("onelepFO_fakeCR","ge4j","ge2b","fakes");

                dilepFO_2j_0b_fakeCR_fakes         = new categoryHistogram("dilepFO_fakeCR","2j","0b","fakes");
                dilepFO_2j_1b_fakeCR_fakes         = new categoryHistogram("dilepFO_fakeCR","2j","1b","fakes");
                dilepFO_2j_ge2b_fakeCR_fakes       = new categoryHistogram("dilepFO_fakeCR","2j","ge2b","fakes");
                dilepFO_3j_0b_fakeCR_fakes         = new categoryHistogram("dilepFO_fakeCR","3j","0b","fakes");
                dilepFO_3j_1b_fakeCR_fakes         = new categoryHistogram("dilepFO_fakeCR","3j","1b","fakes");
                dilepFO_3j_ge2b_fakeCR_fakes       = new categoryHistogram("dilepFO_fakeCR","3j","ge2b","fakes");
                dilepFO_ge4j_0b_fakeCR_fakes       = new categoryHistogram("dilepFO_fakeCR","ge4j","0b","fakes");
                dilepFO_ge4j_1b_fakeCR_fakes       = new categoryHistogram("dilepFO_fakeCR","ge4j","1b","fakes");
                dilepFO_ge4j_ge2b_fakeCR_fakes     = new categoryHistogram("dilepFO_fakeCR","ge4j","ge2b","fakes");



                trilep_2j_0b_fakeCR_flips      = new categoryHistogram("trilep_fakeCR","2j","0b","flips");
                trilep_2j_1b_fakeCR_flips      = new categoryHistogram("trilep_fakeCR","2j","1b","flips");
                trilep_2j_ge2b_fakeCR_flips    = new categoryHistogram("trilep_fakeCR","2j","ge2b","flips");
                trilep_3j_0b_fakeCR_flips      = new categoryHistogram("trilep_fakeCR","3j","0b","flips");
                trilep_3j_1b_fakeCR_flips      = new categoryHistogram("trilep_fakeCR","3j","1b","flips");
                trilep_3j_ge2b_fakeCR_flips    = new categoryHistogram("trilep_fakeCR","3j","ge2b","flips");
                trilep_ge4j_0b_fakeCR_flips    = new categoryHistogram("trilep_fakeCR","ge4j","0b","flips");
                trilep_ge4j_1b_fakeCR_flips    = new categoryHistogram("trilep_fakeCR","ge4j","1b","flips");
                trilep_ge4j_ge2b_fakeCR_flips  = new categoryHistogram("trilep_fakeCR","ge4j","ge2b","flips");

                SS_SF_dilep_2j_0b_fakeCR_flips     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","0b","flips");
                SS_SF_dilep_2j_1b_fakeCR_flips     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","1b","flips");
                SS_SF_dilep_2j_ge2b_fakeCR_flips   = new categoryHistogram("SS_SF_dilep_fakeCR","2j","ge2b","flips");
                SS_SF_dilep_3j_0b_fakeCR_flips     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","0b","flips");
                SS_SF_dilep_3j_1b_fakeCR_flips     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","1b","flips");
                SS_SF_dilep_3j_ge2b_fakeCR_flips   = new categoryHistogram("SS_SF_dilep_fakeCR","3j","ge2b","flips");
                SS_SF_dilep_ge4j_0b_fakeCR_flips   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","0b","flips");
                SS_SF_dilep_ge4j_1b_fakeCR_flips   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","1b","flips");
                SS_SF_dilep_ge4j_ge2b_fakeCR_flips = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","ge2b","flips");

                SS_OF_dilep_2j_0b_fakeCR_flips     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","0b","flips");
                SS_OF_dilep_2j_1b_fakeCR_flips     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","1b","flips");
                SS_OF_dilep_2j_ge2b_fakeCR_flips   = new categoryHistogram("SS_OF_dilep_fakeCR","2j","ge2b","flips");
                SS_OF_dilep_3j_0b_fakeCR_flips     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","0b","flips");
                SS_OF_dilep_3j_1b_fakeCR_flips     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","1b","flips");
                SS_OF_dilep_3j_ge2b_fakeCR_flips   = new categoryHistogram("SS_OF_dilep_fakeCR","3j","ge2b","flips");
                SS_OF_dilep_ge4j_0b_fakeCR_flips   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","0b","flips");
                SS_OF_dilep_ge4j_1b_fakeCR_flips   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","1b","flips");
                SS_OF_dilep_ge4j_ge2b_fakeCR_flips = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","ge2b","flips");

                OS_SF_dilep_2j_0b_fakeCR_flips     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","0b","flips");
                OS_SF_dilep_2j_1b_fakeCR_flips     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","1b","flips");
                OS_SF_dilep_2j_ge2b_fakeCR_flips   = new categoryHistogram("OS_SF_dilep_fakeCR","2j","ge2b","flips");
                OS_SF_dilep_3j_0b_fakeCR_flips     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","0b","flips");
                OS_SF_dilep_3j_1b_fakeCR_flips     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","1b","flips");
                OS_SF_dilep_3j_ge2b_fakeCR_flips   = new categoryHistogram("OS_SF_dilep_fakeCR","3j","ge2b","flips");
                OS_SF_dilep_ge4j_0b_fakeCR_flips   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","0b","flips");
                OS_SF_dilep_ge4j_1b_fakeCR_flips   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","1b","flips");
                OS_SF_dilep_ge4j_ge2b_fakeCR_flips = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","ge2b","flips");

                OS_OF_dilep_2j_0b_fakeCR_flips     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","0b","flips");
                OS_OF_dilep_2j_1b_fakeCR_flips     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","1b","flips");
                OS_OF_dilep_2j_ge2b_fakeCR_flips   = new categoryHistogram("OS_OF_dilep_fakeCR","2j","ge2b","flips");
                OS_OF_dilep_3j_0b_fakeCR_flips     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","0b","flips");
                OS_OF_dilep_3j_1b_fakeCR_flips     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","1b","flips");
                OS_OF_dilep_3j_ge2b_fakeCR_flips   = new categoryHistogram("OS_OF_dilep_fakeCR","3j","ge2b","flips");
                OS_OF_dilep_ge4j_0b_fakeCR_flips   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","0b","flips");
                OS_OF_dilep_ge4j_1b_fakeCR_flips   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","1b","flips");
                OS_OF_dilep_ge4j_ge2b_fakeCR_flips = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","ge2b","flips");

                onelepFO_2j_0b_fakeCR_flips        = new categoryHistogram("onelepFO_fakeCR","2j","0b","flips");
                onelepFO_2j_1b_fakeCR_flips        = new categoryHistogram("onelepFO_fakeCR","2j","1b","flips");
                onelepFO_2j_ge2b_fakeCR_flips      = new categoryHistogram("onelepFO_fakeCR","2j","ge2b","flips");
                onelepFO_3j_0b_fakeCR_flips        = new categoryHistogram("onelepFO_fakeCR","3j","0b","flips");
                onelepFO_3j_1b_fakeCR_flips        = new categoryHistogram("onelepFO_fakeCR","3j","1b","flips");
                onelepFO_3j_ge2b_fakeCR_flips      = new categoryHistogram("onelepFO_fakeCR","3j","ge2b","flips");
                onelepFO_ge4j_0b_fakeCR_flips      = new categoryHistogram("onelepFO_fakeCR","ge4j","0b","flips");
                onelepFO_ge4j_1b_fakeCR_flips      = new categoryHistogram("onelepFO_fakeCR","ge4j","1b","flips");
                onelepFO_ge4j_ge2b_fakeCR_flips    = new categoryHistogram("onelepFO_fakeCR","ge4j","ge2b","flips");

                dilepFO_2j_0b_fakeCR_flips         = new categoryHistogram("dilepFO_fakeCR","2j","0b","flips");
                dilepFO_2j_1b_fakeCR_flips         = new categoryHistogram("dilepFO_fakeCR","2j","1b","flips");
                dilepFO_2j_ge2b_fakeCR_flips       = new categoryHistogram("dilepFO_fakeCR","2j","ge2b","flips");
                dilepFO_3j_0b_fakeCR_flips         = new categoryHistogram("dilepFO_fakeCR","3j","0b","flips");
                dilepFO_3j_1b_fakeCR_flips         = new categoryHistogram("dilepFO_fakeCR","3j","1b","flips");
                dilepFO_3j_ge2b_fakeCR_flips       = new categoryHistogram("dilepFO_fakeCR","3j","ge2b","flips");
                dilepFO_ge4j_0b_fakeCR_flips       = new categoryHistogram("dilepFO_fakeCR","ge4j","0b","flips");
                dilepFO_ge4j_1b_fakeCR_flips       = new categoryHistogram("dilepFO_fakeCR","ge4j","1b","flips");
                dilepFO_ge4j_ge2b_fakeCR_flips     = new categoryHistogram("dilepFO_fakeCR","ge4j","ge2b","flips");



                trilep_2j_0b_fakeCR_other      = new categoryHistogram("trilep_fakeCR","2j","0b","other");
                trilep_2j_1b_fakeCR_other      = new categoryHistogram("trilep_fakeCR","2j","1b","other");
                trilep_2j_ge2b_fakeCR_other    = new categoryHistogram("trilep_fakeCR","2j","ge2b","other");
                trilep_3j_0b_fakeCR_other      = new categoryHistogram("trilep_fakeCR","3j","0b","other");
                trilep_3j_1b_fakeCR_other      = new categoryHistogram("trilep_fakeCR","3j","1b","other");
                trilep_3j_ge2b_fakeCR_other    = new categoryHistogram("trilep_fakeCR","3j","ge2b","other");
                trilep_ge4j_0b_fakeCR_other    = new categoryHistogram("trilep_fakeCR","ge4j","0b","other");
                trilep_ge4j_1b_fakeCR_other    = new categoryHistogram("trilep_fakeCR","ge4j","1b","other");
                trilep_ge4j_ge2b_fakeCR_other  = new categoryHistogram("trilep_fakeCR","ge4j","ge2b","other");

                SS_SF_dilep_2j_0b_fakeCR_other     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","0b","other");
                SS_SF_dilep_2j_1b_fakeCR_other     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","1b","other");
                SS_SF_dilep_2j_ge2b_fakeCR_other   = new categoryHistogram("SS_SF_dilep_fakeCR","2j","ge2b","other");
                SS_SF_dilep_3j_0b_fakeCR_other     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","0b","other");
                SS_SF_dilep_3j_1b_fakeCR_other     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","1b","other");
                SS_SF_dilep_3j_ge2b_fakeCR_other   = new categoryHistogram("SS_SF_dilep_fakeCR","3j","ge2b","other");
                SS_SF_dilep_ge4j_0b_fakeCR_other   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","0b","other");
                SS_SF_dilep_ge4j_1b_fakeCR_other   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","1b","other");
                SS_SF_dilep_ge4j_ge2b_fakeCR_other = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","ge2b","other");

                SS_OF_dilep_2j_0b_fakeCR_other     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","0b","other");
                SS_OF_dilep_2j_1b_fakeCR_other     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","1b","other");
                SS_OF_dilep_2j_ge2b_fakeCR_other   = new categoryHistogram("SS_OF_dilep_fakeCR","2j","ge2b","other");
                SS_OF_dilep_3j_0b_fakeCR_other     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","0b","other");
                SS_OF_dilep_3j_1b_fakeCR_other     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","1b","other");
                SS_OF_dilep_3j_ge2b_fakeCR_other   = new categoryHistogram("SS_OF_dilep_fakeCR","3j","ge2b","other");
                SS_OF_dilep_ge4j_0b_fakeCR_other   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","0b","other");
                SS_OF_dilep_ge4j_1b_fakeCR_other   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","1b","other");
                SS_OF_dilep_ge4j_ge2b_fakeCR_other = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","ge2b","other");

                OS_SF_dilep_2j_0b_fakeCR_other     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","0b","other");
                OS_SF_dilep_2j_1b_fakeCR_other     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","1b","other");
                OS_SF_dilep_2j_ge2b_fakeCR_other   = new categoryHistogram("OS_SF_dilep_fakeCR","2j","ge2b","other");
                OS_SF_dilep_3j_0b_fakeCR_other     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","0b","other");
                OS_SF_dilep_3j_1b_fakeCR_other     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","1b","other");
                OS_SF_dilep_3j_ge2b_fakeCR_other   = new categoryHistogram("OS_SF_dilep_fakeCR","3j","ge2b","other");
                OS_SF_dilep_ge4j_0b_fakeCR_other   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","0b","other");
                OS_SF_dilep_ge4j_1b_fakeCR_other   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","1b","other");
                OS_SF_dilep_ge4j_ge2b_fakeCR_other = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","ge2b","other");

                OS_OF_dilep_2j_0b_fakeCR_other     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","0b","other");
                OS_OF_dilep_2j_1b_fakeCR_other     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","1b","other");
                OS_OF_dilep_2j_ge2b_fakeCR_other   = new categoryHistogram("OS_OF_dilep_fakeCR","2j","ge2b","other");
                OS_OF_dilep_3j_0b_fakeCR_other     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","0b","other");
                OS_OF_dilep_3j_1b_fakeCR_other     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","1b","other");
                OS_OF_dilep_3j_ge2b_fakeCR_other   = new categoryHistogram("OS_OF_dilep_fakeCR","3j","ge2b","other");
                OS_OF_dilep_ge4j_0b_fakeCR_other   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","0b","other");
                OS_OF_dilep_ge4j_1b_fakeCR_other   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","1b","other");
                OS_OF_dilep_ge4j_ge2b_fakeCR_other = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","ge2b","other");

                onelepFO_2j_0b_fakeCR_other        = new categoryHistogram("onelepFO_fakeCR","2j","0b","other");
                onelepFO_2j_1b_fakeCR_other        = new categoryHistogram("onelepFO_fakeCR","2j","1b","other");
                onelepFO_2j_ge2b_fakeCR_other      = new categoryHistogram("onelepFO_fakeCR","2j","ge2b","other");
                onelepFO_3j_0b_fakeCR_other        = new categoryHistogram("onelepFO_fakeCR","3j","0b","other");
                onelepFO_3j_1b_fakeCR_other        = new categoryHistogram("onelepFO_fakeCR","3j","1b","other");
                onelepFO_3j_ge2b_fakeCR_other      = new categoryHistogram("onelepFO_fakeCR","3j","ge2b","other");
                onelepFO_ge4j_0b_fakeCR_other      = new categoryHistogram("onelepFO_fakeCR","ge4j","0b","other");
                onelepFO_ge4j_1b_fakeCR_other      = new categoryHistogram("onelepFO_fakeCR","ge4j","1b","other");
                onelepFO_ge4j_ge2b_fakeCR_other    = new categoryHistogram("onelepFO_fakeCR","ge4j","ge2b","other");

                dilepFO_2j_0b_fakeCR_other         = new categoryHistogram("dilepFO_fakeCR","2j","0b","other");
                dilepFO_2j_1b_fakeCR_other         = new categoryHistogram("dilepFO_fakeCR","2j","1b","other");
                dilepFO_2j_ge2b_fakeCR_other       = new categoryHistogram("dilepFO_fakeCR","2j","ge2b","other");
                dilepFO_3j_0b_fakeCR_other         = new categoryHistogram("dilepFO_fakeCR","3j","0b","other");
                dilepFO_3j_1b_fakeCR_other         = new categoryHistogram("dilepFO_fakeCR","3j","1b","other");
                dilepFO_3j_ge2b_fakeCR_other       = new categoryHistogram("dilepFO_fakeCR","3j","ge2b","other");
                dilepFO_ge4j_0b_fakeCR_other       = new categoryHistogram("dilepFO_fakeCR","ge4j","0b","other");
                dilepFO_ge4j_1b_fakeCR_other       = new categoryHistogram("dilepFO_fakeCR","ge4j","1b","other");
                dilepFO_ge4j_ge2b_fakeCR_other     = new categoryHistogram("dilepFO_fakeCR","ge4j","ge2b","other");



                //***********************************************************
                //***********************************************************
                //***********************************************************
                //FLIP CR
                //***********************************************************
                //***********************************************************
                //***********************************************************
                trilep_2j_0b_flipCR_fakes      = new categoryHistogram("trilep_flipCR","2j","0b","fakes");
                trilep_2j_1b_flipCR_fakes      = new categoryHistogram("trilep_flipCR","2j","1b","fakes");
                trilep_2j_ge2b_flipCR_fakes    = new categoryHistogram("trilep_flipCR","2j","ge2b","fakes");
                trilep_3j_0b_flipCR_fakes      = new categoryHistogram("trilep_flipCR","3j","0b","fakes");
                trilep_3j_1b_flipCR_fakes      = new categoryHistogram("trilep_flipCR","3j","1b","fakes");
                trilep_3j_ge2b_flipCR_fakes    = new categoryHistogram("trilep_flipCR","3j","ge2b","fakes");
                trilep_ge4j_0b_flipCR_fakes    = new categoryHistogram("trilep_flipCR","ge4j","0b","fakes");
                trilep_ge4j_1b_flipCR_fakes    = new categoryHistogram("trilep_flipCR","ge4j","1b","fakes");
                trilep_ge4j_ge2b_flipCR_fakes  = new categoryHistogram("trilep_flipCR","ge4j","ge2b","fakes");

                SS_SF_dilep_2j_0b_flipCR_fakes     = new categoryHistogram("SS_SF_dilep_flipCR","2j","0b","fakes");
                SS_SF_dilep_2j_1b_flipCR_fakes     = new categoryHistogram("SS_SF_dilep_flipCR","2j","1b","fakes");
                SS_SF_dilep_2j_ge2b_flipCR_fakes   = new categoryHistogram("SS_SF_dilep_flipCR","2j","ge2b","fakes");
                SS_SF_dilep_3j_0b_flipCR_fakes     = new categoryHistogram("SS_SF_dilep_flipCR","3j","0b","fakes");
                SS_SF_dilep_3j_1b_flipCR_fakes     = new categoryHistogram("SS_SF_dilep_flipCR","3j","1b","fakes");
                SS_SF_dilep_3j_ge2b_flipCR_fakes   = new categoryHistogram("SS_SF_dilep_flipCR","3j","ge2b","fakes");
                SS_SF_dilep_ge4j_0b_flipCR_fakes   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","0b","fakes");
                SS_SF_dilep_ge4j_1b_flipCR_fakes   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","1b","fakes");
                SS_SF_dilep_ge4j_ge2b_flipCR_fakes = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","ge2b","fakes");

                SS_OF_dilep_2j_0b_flipCR_fakes     = new categoryHistogram("SS_OF_dilep_flipCR","2j","0b","fakes");
                SS_OF_dilep_2j_1b_flipCR_fakes     = new categoryHistogram("SS_OF_dilep_flipCR","2j","1b","fakes");
                SS_OF_dilep_2j_ge2b_flipCR_fakes   = new categoryHistogram("SS_OF_dilep_flipCR","2j","ge2b","fakes");
                SS_OF_dilep_3j_0b_flipCR_fakes     = new categoryHistogram("SS_OF_dilep_flipCR","3j","0b","fakes");
                SS_OF_dilep_3j_1b_flipCR_fakes     = new categoryHistogram("SS_OF_dilep_flipCR","3j","1b","fakes");
                SS_OF_dilep_3j_ge2b_flipCR_fakes   = new categoryHistogram("SS_OF_dilep_flipCR","3j","ge2b","fakes");
                SS_OF_dilep_ge4j_0b_flipCR_fakes   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","0b","fakes");
                SS_OF_dilep_ge4j_1b_flipCR_fakes   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","1b","fakes");
                SS_OF_dilep_ge4j_ge2b_flipCR_fakes = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","ge2b","fakes");

                OS_SF_dilep_2j_0b_flipCR_fakes     = new categoryHistogram("OS_SF_dilep_flipCR","2j","0b","fakes");
                OS_SF_dilep_2j_1b_flipCR_fakes     = new categoryHistogram("OS_SF_dilep_flipCR","2j","1b","fakes");
                OS_SF_dilep_2j_ge2b_flipCR_fakes   = new categoryHistogram("OS_SF_dilep_flipCR","2j","ge2b","fakes");
                OS_SF_dilep_3j_0b_flipCR_fakes     = new categoryHistogram("OS_SF_dilep_flipCR","3j","0b","fakes");
                OS_SF_dilep_3j_1b_flipCR_fakes     = new categoryHistogram("OS_SF_dilep_flipCR","3j","1b","fakes");
                OS_SF_dilep_3j_ge2b_flipCR_fakes   = new categoryHistogram("OS_SF_dilep_flipCR","3j","ge2b","fakes");
                OS_SF_dilep_ge4j_0b_flipCR_fakes   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","0b","fakes");
                OS_SF_dilep_ge4j_1b_flipCR_fakes   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","1b","fakes");
                OS_SF_dilep_ge4j_ge2b_flipCR_fakes = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","ge2b","fakes");

                OS_OF_dilep_2j_0b_flipCR_fakes     = new categoryHistogram("OS_OF_dilep_flipCR","2j","0b","fakes");
                OS_OF_dilep_2j_1b_flipCR_fakes     = new categoryHistogram("OS_OF_dilep_flipCR","2j","1b","fakes");
                OS_OF_dilep_2j_ge2b_flipCR_fakes   = new categoryHistogram("OS_OF_dilep_flipCR","2j","ge2b","fakes");
                OS_OF_dilep_3j_0b_flipCR_fakes     = new categoryHistogram("OS_OF_dilep_flipCR","3j","0b","fakes");
                OS_OF_dilep_3j_1b_flipCR_fakes     = new categoryHistogram("OS_OF_dilep_flipCR","3j","1b","fakes");
                OS_OF_dilep_3j_ge2b_flipCR_fakes   = new categoryHistogram("OS_OF_dilep_flipCR","3j","ge2b","fakes");
                OS_OF_dilep_ge4j_0b_flipCR_fakes   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","0b","fakes");
                OS_OF_dilep_ge4j_1b_flipCR_fakes   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","1b","fakes");
                OS_OF_dilep_ge4j_ge2b_flipCR_fakes = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","ge2b","fakes");

                onelepFO_2j_0b_flipCR_fakes        = new categoryHistogram("onelepFO_flipCR","2j","0b","fakes");
                onelepFO_2j_1b_flipCR_fakes        = new categoryHistogram("onelepFO_flipCR","2j","1b","fakes");
                onelepFO_2j_ge2b_flipCR_fakes      = new categoryHistogram("onelepFO_flipCR","2j","ge2b","fakes");
                onelepFO_3j_0b_flipCR_fakes        = new categoryHistogram("onelepFO_flipCR","3j","0b","fakes");
                onelepFO_3j_1b_flipCR_fakes        = new categoryHistogram("onelepFO_flipCR","3j","1b","fakes");
                onelepFO_3j_ge2b_flipCR_fakes      = new categoryHistogram("onelepFO_flipCR","3j","ge2b","fakes");
                onelepFO_ge4j_0b_flipCR_fakes      = new categoryHistogram("onelepFO_flipCR","ge4j","0b","fakes");
                onelepFO_ge4j_1b_flipCR_fakes      = new categoryHistogram("onelepFO_flipCR","ge4j","1b","fakes");
                onelepFO_ge4j_ge2b_flipCR_fakes    = new categoryHistogram("onelepFO_flipCR","ge4j","ge2b","fakes");

                dilepFO_2j_0b_flipCR_fakes         = new categoryHistogram("dilepFO_flipCR","2j","0b","fakes");
                dilepFO_2j_1b_flipCR_fakes         = new categoryHistogram("dilepFO_flipCR","2j","1b","fakes");
                dilepFO_2j_ge2b_flipCR_fakes       = new categoryHistogram("dilepFO_flipCR","2j","ge2b","fakes");
                dilepFO_3j_0b_flipCR_fakes         = new categoryHistogram("dilepFO_flipCR","3j","0b","fakes");
                dilepFO_3j_1b_flipCR_fakes         = new categoryHistogram("dilepFO_flipCR","3j","1b","fakes");
                dilepFO_3j_ge2b_flipCR_fakes       = new categoryHistogram("dilepFO_flipCR","3j","ge2b","fakes");
                dilepFO_ge4j_0b_flipCR_fakes       = new categoryHistogram("dilepFO_flipCR","ge4j","0b","fakes");
                dilepFO_ge4j_1b_flipCR_fakes       = new categoryHistogram("dilepFO_flipCR","ge4j","1b","fakes");
                dilepFO_ge4j_ge2b_flipCR_fakes     = new categoryHistogram("dilepFO_flipCR","ge4j","ge2b","fakes");



                trilep_2j_0b_flipCR_flips      = new categoryHistogram("trilep_flipCR","2j","0b","flips");
                trilep_2j_1b_flipCR_flips      = new categoryHistogram("trilep_flipCR","2j","1b","flips");
                trilep_2j_ge2b_flipCR_flips    = new categoryHistogram("trilep_flipCR","2j","ge2b","flips");
                trilep_3j_0b_flipCR_flips      = new categoryHistogram("trilep_flipCR","3j","0b","flips");
                trilep_3j_1b_flipCR_flips      = new categoryHistogram("trilep_flipCR","3j","1b","flips");
                trilep_3j_ge2b_flipCR_flips    = new categoryHistogram("trilep_flipCR","3j","ge2b","flips");
                trilep_ge4j_0b_flipCR_flips    = new categoryHistogram("trilep_flipCR","ge4j","0b","flips");
                trilep_ge4j_1b_flipCR_flips    = new categoryHistogram("trilep_flipCR","ge4j","1b","flips");
                trilep_ge4j_ge2b_flipCR_flips  = new categoryHistogram("trilep_flipCR","ge4j","ge2b","flips");

                SS_SF_dilep_2j_0b_flipCR_flips     = new categoryHistogram("SS_SF_dilep_flipCR","2j","0b","flips");
                SS_SF_dilep_2j_1b_flipCR_flips     = new categoryHistogram("SS_SF_dilep_flipCR","2j","1b","flips");
                SS_SF_dilep_2j_ge2b_flipCR_flips   = new categoryHistogram("SS_SF_dilep_flipCR","2j","ge2b","flips");
                SS_SF_dilep_3j_0b_flipCR_flips     = new categoryHistogram("SS_SF_dilep_flipCR","3j","0b","flips");
                SS_SF_dilep_3j_1b_flipCR_flips     = new categoryHistogram("SS_SF_dilep_flipCR","3j","1b","flips");
                SS_SF_dilep_3j_ge2b_flipCR_flips   = new categoryHistogram("SS_SF_dilep_flipCR","3j","ge2b","flips");
                SS_SF_dilep_ge4j_0b_flipCR_flips   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","0b","flips");
                SS_SF_dilep_ge4j_1b_flipCR_flips   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","1b","flips");
                SS_SF_dilep_ge4j_ge2b_flipCR_flips = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","ge2b","flips");

                SS_OF_dilep_2j_0b_flipCR_flips     = new categoryHistogram("SS_OF_dilep_flipCR","2j","0b","flips");
                SS_OF_dilep_2j_1b_flipCR_flips     = new categoryHistogram("SS_OF_dilep_flipCR","2j","1b","flips");
                SS_OF_dilep_2j_ge2b_flipCR_flips   = new categoryHistogram("SS_OF_dilep_flipCR","2j","ge2b","flips");
                SS_OF_dilep_3j_0b_flipCR_flips     = new categoryHistogram("SS_OF_dilep_flipCR","3j","0b","flips");
                SS_OF_dilep_3j_1b_flipCR_flips     = new categoryHistogram("SS_OF_dilep_flipCR","3j","1b","flips");
                SS_OF_dilep_3j_ge2b_flipCR_flips   = new categoryHistogram("SS_OF_dilep_flipCR","3j","ge2b","flips");
                SS_OF_dilep_ge4j_0b_flipCR_flips   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","0b","flips");
                SS_OF_dilep_ge4j_1b_flipCR_flips   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","1b","flips");
                SS_OF_dilep_ge4j_ge2b_flipCR_flips = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","ge2b","flips");

                OS_SF_dilep_2j_0b_flipCR_flips     = new categoryHistogram("OS_SF_dilep_flipCR","2j","0b","flips");
                OS_SF_dilep_2j_1b_flipCR_flips     = new categoryHistogram("OS_SF_dilep_flipCR","2j","1b","flips");
                OS_SF_dilep_2j_ge2b_flipCR_flips   = new categoryHistogram("OS_SF_dilep_flipCR","2j","ge2b","flips");
                OS_SF_dilep_3j_0b_flipCR_flips     = new categoryHistogram("OS_SF_dilep_flipCR","3j","0b","flips");
                OS_SF_dilep_3j_1b_flipCR_flips     = new categoryHistogram("OS_SF_dilep_flipCR","3j","1b","flips");
                OS_SF_dilep_3j_ge2b_flipCR_flips   = new categoryHistogram("OS_SF_dilep_flipCR","3j","ge2b","flips");
                OS_SF_dilep_ge4j_0b_flipCR_flips   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","0b","flips");
                OS_SF_dilep_ge4j_1b_flipCR_flips   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","1b","flips");
                OS_SF_dilep_ge4j_ge2b_flipCR_flips = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","ge2b","flips");

                OS_OF_dilep_2j_0b_flipCR_flips     = new categoryHistogram("OS_OF_dilep_flipCR","2j","0b","flips");
                OS_OF_dilep_2j_1b_flipCR_flips     = new categoryHistogram("OS_OF_dilep_flipCR","2j","1b","flips");
                OS_OF_dilep_2j_ge2b_flipCR_flips   = new categoryHistogram("OS_OF_dilep_flipCR","2j","ge2b","flips");
                OS_OF_dilep_3j_0b_flipCR_flips     = new categoryHistogram("OS_OF_dilep_flipCR","3j","0b","flips");
                OS_OF_dilep_3j_1b_flipCR_flips     = new categoryHistogram("OS_OF_dilep_flipCR","3j","1b","flips");
                OS_OF_dilep_3j_ge2b_flipCR_flips   = new categoryHistogram("OS_OF_dilep_flipCR","3j","ge2b","flips");
                OS_OF_dilep_ge4j_0b_flipCR_flips   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","0b","flips");
                OS_OF_dilep_ge4j_1b_flipCR_flips   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","1b","flips");
                OS_OF_dilep_ge4j_ge2b_flipCR_flips = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","ge2b","flips");

                onelepFO_2j_0b_flipCR_flips        = new categoryHistogram("onelepFO_flipCR","2j","0b","flips");
                onelepFO_2j_1b_flipCR_flips        = new categoryHistogram("onelepFO_flipCR","2j","1b","flips");
                onelepFO_2j_ge2b_flipCR_flips      = new categoryHistogram("onelepFO_flipCR","2j","ge2b","flips");
                onelepFO_3j_0b_flipCR_flips        = new categoryHistogram("onelepFO_flipCR","3j","0b","flips");
                onelepFO_3j_1b_flipCR_flips        = new categoryHistogram("onelepFO_flipCR","3j","1b","flips");
                onelepFO_3j_ge2b_flipCR_flips      = new categoryHistogram("onelepFO_flipCR","3j","ge2b","flips");
                onelepFO_ge4j_0b_flipCR_flips      = new categoryHistogram("onelepFO_flipCR","ge4j","0b","flips");
                onelepFO_ge4j_1b_flipCR_flips      = new categoryHistogram("onelepFO_flipCR","ge4j","1b","flips");
                onelepFO_ge4j_ge2b_flipCR_flips    = new categoryHistogram("onelepFO_flipCR","ge4j","ge2b","flips");

                dilepFO_2j_0b_flipCR_flips         = new categoryHistogram("dilepFO_flipCR","2j","0b","flips");
                dilepFO_2j_1b_flipCR_flips         = new categoryHistogram("dilepFO_flipCR","2j","1b","flips");
                dilepFO_2j_ge2b_flipCR_flips       = new categoryHistogram("dilepFO_flipCR","2j","ge2b","flips");
                dilepFO_3j_0b_flipCR_flips         = new categoryHistogram("dilepFO_flipCR","3j","0b","flips");
                dilepFO_3j_1b_flipCR_flips         = new categoryHistogram("dilepFO_flipCR","3j","1b","flips");
                dilepFO_3j_ge2b_flipCR_flips       = new categoryHistogram("dilepFO_flipCR","3j","ge2b","flips");
                dilepFO_ge4j_0b_flipCR_flips       = new categoryHistogram("dilepFO_flipCR","ge4j","0b","flips");
                dilepFO_ge4j_1b_flipCR_flips       = new categoryHistogram("dilepFO_flipCR","ge4j","1b","flips");
                dilepFO_ge4j_ge2b_flipCR_flips     = new categoryHistogram("dilepFO_flipCR","ge4j","ge2b","flips");



                trilep_2j_0b_flipCR_other      = new categoryHistogram("trilep_flipCR","2j","0b","other");
                trilep_2j_1b_flipCR_other      = new categoryHistogram("trilep_flipCR","2j","1b","other");
                trilep_2j_ge2b_flipCR_other    = new categoryHistogram("trilep_flipCR","2j","ge2b","other");
                trilep_3j_0b_flipCR_other      = new categoryHistogram("trilep_flipCR","3j","0b","other");
                trilep_3j_1b_flipCR_other      = new categoryHistogram("trilep_flipCR","3j","1b","other");
                trilep_3j_ge2b_flipCR_other    = new categoryHistogram("trilep_flipCR","3j","ge2b","other");
                trilep_ge4j_0b_flipCR_other    = new categoryHistogram("trilep_flipCR","ge4j","0b","other");
                trilep_ge4j_1b_flipCR_other    = new categoryHistogram("trilep_flipCR","ge4j","1b","other");
                trilep_ge4j_ge2b_flipCR_other  = new categoryHistogram("trilep_flipCR","ge4j","ge2b","other");

                SS_SF_dilep_2j_0b_flipCR_other     = new categoryHistogram("SS_SF_dilep_flipCR","2j","0b","other");
                SS_SF_dilep_2j_1b_flipCR_other     = new categoryHistogram("SS_SF_dilep_flipCR","2j","1b","other");
                SS_SF_dilep_2j_ge2b_flipCR_other   = new categoryHistogram("SS_SF_dilep_flipCR","2j","ge2b","other");
                SS_SF_dilep_3j_0b_flipCR_other     = new categoryHistogram("SS_SF_dilep_flipCR","3j","0b","other");
                SS_SF_dilep_3j_1b_flipCR_other     = new categoryHistogram("SS_SF_dilep_flipCR","3j","1b","other");
                SS_SF_dilep_3j_ge2b_flipCR_other   = new categoryHistogram("SS_SF_dilep_flipCR","3j","ge2b","other");
                SS_SF_dilep_ge4j_0b_flipCR_other   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","0b","other");
                SS_SF_dilep_ge4j_1b_flipCR_other   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","1b","other");
                SS_SF_dilep_ge4j_ge2b_flipCR_other = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","ge2b","other");

                SS_OF_dilep_2j_0b_flipCR_other     = new categoryHistogram("SS_OF_dilep_flipCR","2j","0b","other");
                SS_OF_dilep_2j_1b_flipCR_other     = new categoryHistogram("SS_OF_dilep_flipCR","2j","1b","other");
                SS_OF_dilep_2j_ge2b_flipCR_other   = new categoryHistogram("SS_OF_dilep_flipCR","2j","ge2b","other");
                SS_OF_dilep_3j_0b_flipCR_other     = new categoryHistogram("SS_OF_dilep_flipCR","3j","0b","other");
                SS_OF_dilep_3j_1b_flipCR_other     = new categoryHistogram("SS_OF_dilep_flipCR","3j","1b","other");
                SS_OF_dilep_3j_ge2b_flipCR_other   = new categoryHistogram("SS_OF_dilep_flipCR","3j","ge2b","other");
                SS_OF_dilep_ge4j_0b_flipCR_other   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","0b","other");
                SS_OF_dilep_ge4j_1b_flipCR_other   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","1b","other");
                SS_OF_dilep_ge4j_ge2b_flipCR_other = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","ge2b","other");

                OS_SF_dilep_2j_0b_flipCR_other     = new categoryHistogram("OS_SF_dilep_flipCR","2j","0b","other");
                OS_SF_dilep_2j_1b_flipCR_other     = new categoryHistogram("OS_SF_dilep_flipCR","2j","1b","other");
                OS_SF_dilep_2j_ge2b_flipCR_other   = new categoryHistogram("OS_SF_dilep_flipCR","2j","ge2b","other");
                OS_SF_dilep_3j_0b_flipCR_other     = new categoryHistogram("OS_SF_dilep_flipCR","3j","0b","other");
                OS_SF_dilep_3j_1b_flipCR_other     = new categoryHistogram("OS_SF_dilep_flipCR","3j","1b","other");
                OS_SF_dilep_3j_ge2b_flipCR_other   = new categoryHistogram("OS_SF_dilep_flipCR","3j","ge2b","other");
                OS_SF_dilep_ge4j_0b_flipCR_other   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","0b","other");
                OS_SF_dilep_ge4j_1b_flipCR_other   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","1b","other");
                OS_SF_dilep_ge4j_ge2b_flipCR_other = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","ge2b","other");

                OS_OF_dilep_2j_0b_flipCR_other     = new categoryHistogram("OS_OF_dilep_flipCR","2j","0b","other");
                OS_OF_dilep_2j_1b_flipCR_other     = new categoryHistogram("OS_OF_dilep_flipCR","2j","1b","other");
                OS_OF_dilep_2j_ge2b_flipCR_other   = new categoryHistogram("OS_OF_dilep_flipCR","2j","ge2b","other");
                OS_OF_dilep_3j_0b_flipCR_other     = new categoryHistogram("OS_OF_dilep_flipCR","3j","0b","other");
                OS_OF_dilep_3j_1b_flipCR_other     = new categoryHistogram("OS_OF_dilep_flipCR","3j","1b","other");
                OS_OF_dilep_3j_ge2b_flipCR_other   = new categoryHistogram("OS_OF_dilep_flipCR","3j","ge2b","other");
                OS_OF_dilep_ge4j_0b_flipCR_other   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","0b","other");
                OS_OF_dilep_ge4j_1b_flipCR_other   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","1b","other");
                OS_OF_dilep_ge4j_ge2b_flipCR_other = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","ge2b","other");

                onelepFO_2j_0b_flipCR_other        = new categoryHistogram("onelepFO_flipCR","2j","0b","other");
                onelepFO_2j_1b_flipCR_other        = new categoryHistogram("onelepFO_flipCR","2j","1b","other");
                onelepFO_2j_ge2b_flipCR_other      = new categoryHistogram("onelepFO_flipCR","2j","ge2b","other");
                onelepFO_3j_0b_flipCR_other        = new categoryHistogram("onelepFO_flipCR","3j","0b","other");
                onelepFO_3j_1b_flipCR_other        = new categoryHistogram("onelepFO_flipCR","3j","1b","other");
                onelepFO_3j_ge2b_flipCR_other      = new categoryHistogram("onelepFO_flipCR","3j","ge2b","other");
                onelepFO_ge4j_0b_flipCR_other      = new categoryHistogram("onelepFO_flipCR","ge4j","0b","other");
                onelepFO_ge4j_1b_flipCR_other      = new categoryHistogram("onelepFO_flipCR","ge4j","1b","other");
                onelepFO_ge4j_ge2b_flipCR_other    = new categoryHistogram("onelepFO_flipCR","ge4j","ge2b","other");

                dilepFO_2j_0b_flipCR_other         = new categoryHistogram("dilepFO_flipCR","2j","0b","other");
                dilepFO_2j_1b_flipCR_other         = new categoryHistogram("dilepFO_flipCR","2j","1b","other");
                dilepFO_2j_ge2b_flipCR_other       = new categoryHistogram("dilepFO_flipCR","2j","ge2b","other");
                dilepFO_3j_0b_flipCR_other         = new categoryHistogram("dilepFO_flipCR","3j","0b","other");
                dilepFO_3j_1b_flipCR_other         = new categoryHistogram("dilepFO_flipCR","3j","1b","other");
                dilepFO_3j_ge2b_flipCR_other       = new categoryHistogram("dilepFO_flipCR","3j","ge2b","other");
                dilepFO_ge4j_0b_flipCR_other       = new categoryHistogram("dilepFO_flipCR","ge4j","0b","other");
                dilepFO_ge4j_1b_flipCR_other       = new categoryHistogram("dilepFO_flipCR","ge4j","1b","other");
                dilepFO_ge4j_ge2b_flipCR_other     = new categoryHistogram("dilepFO_flipCR","ge4j","ge2b","other");

            }else{
                //***********************************************************
                //***********************************************************
                //***********************************************************
                //SR
                //***********************************************************
                //***********************************************************
                //***********************************************************
                trilep_2j_0b      = new categoryHistogram("trilep","2j","0b",category);
                trilep_2j_1b      = new categoryHistogram("trilep","2j","1b",category);
                trilep_2j_ge2b    = new categoryHistogram("trilep","2j","ge2b",category);
                trilep_3j_0b      = new categoryHistogram("trilep","3j","0b",category);
                trilep_3j_1b      = new categoryHistogram("trilep","3j","1b",category);
                trilep_3j_ge2b    = new categoryHistogram("trilep","3j","ge2b",category);
                trilep_ge4j_0b    = new categoryHistogram("trilep","ge4j","0b",category);
                trilep_ge4j_1b    = new categoryHistogram("trilep","ge4j","1b",category);
                trilep_ge4j_ge2b  = new categoryHistogram("trilep","ge4j","ge2b",category);

                SS_SF_dilep_2j_0b     = new categoryHistogram("SS_SF_dilep","2j","0b",category);
                SS_SF_dilep_2j_1b     = new categoryHistogram("SS_SF_dilep","2j","1b",category);
                SS_SF_dilep_2j_ge2b   = new categoryHistogram("SS_SF_dilep","2j","ge2b",category);
                SS_SF_dilep_3j_0b     = new categoryHistogram("SS_SF_dilep","3j","0b",category);
                SS_SF_dilep_3j_1b     = new categoryHistogram("SS_SF_dilep","3j","1b",category);
                SS_SF_dilep_3j_ge2b   = new categoryHistogram("SS_SF_dilep","3j","ge2b",category);
                SS_SF_dilep_ge4j_0b   = new categoryHistogram("SS_SF_dilep","ge4j","0b",category);
                SS_SF_dilep_ge4j_1b   = new categoryHistogram("SS_SF_dilep","ge4j","1b",category);
                SS_SF_dilep_ge4j_ge2b = new categoryHistogram("SS_SF_dilep","ge4j","ge2b",category);

                SS_OF_dilep_2j_0b     = new categoryHistogram("SS_OF_dilep","2j","0b",category);
                SS_OF_dilep_2j_1b     = new categoryHistogram("SS_OF_dilep","2j","1b",category);
                SS_OF_dilep_2j_ge2b   = new categoryHistogram("SS_OF_dilep","2j","ge2b",category);
                SS_OF_dilep_3j_0b     = new categoryHistogram("SS_OF_dilep","3j","0b",category);
                SS_OF_dilep_3j_1b     = new categoryHistogram("SS_OF_dilep","3j","1b",category);
                SS_OF_dilep_3j_ge2b   = new categoryHistogram("SS_OF_dilep","3j","ge2b",category);
                SS_OF_dilep_ge4j_0b   = new categoryHistogram("SS_OF_dilep","ge4j","0b",category);
                SS_OF_dilep_ge4j_1b   = new categoryHistogram("SS_OF_dilep","ge4j","1b",category);
                SS_OF_dilep_ge4j_ge2b = new categoryHistogram("SS_OF_dilep","ge4j","ge2b",category);

                OS_SF_dilep_2j_0b     = new categoryHistogram("OS_SF_dilep","2j","0b",category);
                OS_SF_dilep_2j_1b     = new categoryHistogram("OS_SF_dilep","2j","1b",category);
                OS_SF_dilep_2j_ge2b   = new categoryHistogram("OS_SF_dilep","2j","ge2b",category);
                OS_SF_dilep_3j_0b     = new categoryHistogram("OS_SF_dilep","3j","0b",category);
                OS_SF_dilep_3j_1b     = new categoryHistogram("OS_SF_dilep","3j","1b",category);
                OS_SF_dilep_3j_ge2b   = new categoryHistogram("OS_SF_dilep","3j","ge2b",category);
                OS_SF_dilep_ge4j_0b   = new categoryHistogram("OS_SF_dilep","ge4j","0b",category);
                OS_SF_dilep_ge4j_1b   = new categoryHistogram("OS_SF_dilep","ge4j","1b",category);
                OS_SF_dilep_ge4j_ge2b = new categoryHistogram("OS_SF_dilep","ge4j","ge2b",category);

                OS_OF_dilep_2j_0b     = new categoryHistogram("OS_OF_dilep","2j","0b",category);
                OS_OF_dilep_2j_1b     = new categoryHistogram("OS_OF_dilep","2j","1b",category);
                OS_OF_dilep_2j_ge2b   = new categoryHistogram("OS_OF_dilep","2j","ge2b",category);
                OS_OF_dilep_3j_0b     = new categoryHistogram("OS_OF_dilep","3j","0b",category);
                OS_OF_dilep_3j_1b     = new categoryHistogram("OS_OF_dilep","3j","1b",category);
                OS_OF_dilep_3j_ge2b   = new categoryHistogram("OS_OF_dilep","3j","ge2b",category);
                OS_OF_dilep_ge4j_0b   = new categoryHistogram("OS_OF_dilep","ge4j","0b",category);
                OS_OF_dilep_ge4j_1b   = new categoryHistogram("OS_OF_dilep","ge4j","1b",category);
                OS_OF_dilep_ge4j_ge2b = new categoryHistogram("OS_OF_dilep","ge4j","ge2b",category);

                onelepFO_2j_0b        = new categoryHistogram("onelepFO","2j","0b",category);
                onelepFO_2j_1b        = new categoryHistogram("onelepFO","2j","1b",category);
                onelepFO_2j_ge2b      = new categoryHistogram("onelepFO","2j","ge2b",category);
                onelepFO_3j_0b        = new categoryHistogram("onelepFO","3j","0b",category);
                onelepFO_3j_1b        = new categoryHistogram("onelepFO","3j","1b",category);
                onelepFO_3j_ge2b      = new categoryHistogram("onelepFO","3j","ge2b",category);
                onelepFO_ge4j_0b      = new categoryHistogram("onelepFO","ge4j","0b",category);
                onelepFO_ge4j_1b      = new categoryHistogram("onelepFO","ge4j","1b",category);
                onelepFO_ge4j_ge2b    = new categoryHistogram("onelepFO","ge4j","ge2b",category);

                dilepFO_2j_0b         = new categoryHistogram("dilepFO","2j","0b",category);
                dilepFO_2j_1b         = new categoryHistogram("dilepFO","2j","1b",category);
                dilepFO_2j_ge2b       = new categoryHistogram("dilepFO","2j","ge2b",category);
                dilepFO_3j_0b         = new categoryHistogram("dilepFO","3j","0b",category);
                dilepFO_3j_1b         = new categoryHistogram("dilepFO","3j","1b",category);
                dilepFO_3j_ge2b       = new categoryHistogram("dilepFO","3j","ge2b",category);
                dilepFO_ge4j_0b       = new categoryHistogram("dilepFO","ge4j","0b",category);
                dilepFO_ge4j_1b       = new categoryHistogram("dilepFO","ge4j","1b",category);
                dilepFO_ge4j_ge2b     = new categoryHistogram("dilepFO","ge4j","ge2b",category);




                //***********************************************************
                //***********************************************************
                //***********************************************************
                //FAKE CR
                //***********************************************************
                //***********************************************************
                //***********************************************************
                trilep_2j_0b_fakeCR      = new categoryHistogram("trilep_fakeCR","2j","0b",category);
                trilep_2j_1b_fakeCR      = new categoryHistogram("trilep_fakeCR","2j","1b",category);
                trilep_2j_ge2b_fakeCR    = new categoryHistogram("trilep_fakeCR","2j","ge2b",category);
                trilep_3j_0b_fakeCR      = new categoryHistogram("trilep_fakeCR","3j","0b",category);
                trilep_3j_1b_fakeCR      = new categoryHistogram("trilep_fakeCR","3j","1b",category);
                trilep_3j_ge2b_fakeCR    = new categoryHistogram("trilep_fakeCR","3j","ge2b",category);
                trilep_ge4j_0b_fakeCR    = new categoryHistogram("trilep_fakeCR","ge4j","0b",category);
                trilep_ge4j_1b_fakeCR    = new categoryHistogram("trilep_fakeCR","ge4j","1b",category);
                trilep_ge4j_ge2b_fakeCR  = new categoryHistogram("trilep_fakeCR","ge4j","ge2b",category);

                SS_SF_dilep_2j_0b_fakeCR     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","0b",category);
                SS_SF_dilep_2j_1b_fakeCR     = new categoryHistogram("SS_SF_dilep_fakeCR","2j","1b",category);
                SS_SF_dilep_2j_ge2b_fakeCR   = new categoryHistogram("SS_SF_dilep_fakeCR","2j","ge2b",category);
                SS_SF_dilep_3j_0b_fakeCR     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","0b",category);
                SS_SF_dilep_3j_1b_fakeCR     = new categoryHistogram("SS_SF_dilep_fakeCR","3j","1b",category);
                SS_SF_dilep_3j_ge2b_fakeCR   = new categoryHistogram("SS_SF_dilep_fakeCR","3j","ge2b",category);
                SS_SF_dilep_ge4j_0b_fakeCR   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","0b",category);
                SS_SF_dilep_ge4j_1b_fakeCR   = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","1b",category);
                SS_SF_dilep_ge4j_ge2b_fakeCR = new categoryHistogram("SS_SF_dilep_fakeCR","ge4j","ge2b",category);

                SS_OF_dilep_2j_0b_fakeCR     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","0b",category);
                SS_OF_dilep_2j_1b_fakeCR     = new categoryHistogram("SS_OF_dilep_fakeCR","2j","1b",category);
                SS_OF_dilep_2j_ge2b_fakeCR   = new categoryHistogram("SS_OF_dilep_fakeCR","2j","ge2b",category);
                SS_OF_dilep_3j_0b_fakeCR     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","0b",category);
                SS_OF_dilep_3j_1b_fakeCR     = new categoryHistogram("SS_OF_dilep_fakeCR","3j","1b",category);
                SS_OF_dilep_3j_ge2b_fakeCR   = new categoryHistogram("SS_OF_dilep_fakeCR","3j","ge2b",category);
                SS_OF_dilep_ge4j_0b_fakeCR   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","0b",category);
                SS_OF_dilep_ge4j_1b_fakeCR   = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","1b",category);
                SS_OF_dilep_ge4j_ge2b_fakeCR = new categoryHistogram("SS_OF_dilep_fakeCR","ge4j","ge2b",category);

                OS_SF_dilep_2j_0b_fakeCR     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","0b",category);
                OS_SF_dilep_2j_1b_fakeCR     = new categoryHistogram("OS_SF_dilep_fakeCR","2j","1b",category);
                OS_SF_dilep_2j_ge2b_fakeCR   = new categoryHistogram("OS_SF_dilep_fakeCR","2j","ge2b",category);
                OS_SF_dilep_3j_0b_fakeCR     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","0b",category);
                OS_SF_dilep_3j_1b_fakeCR     = new categoryHistogram("OS_SF_dilep_fakeCR","3j","1b",category);
                OS_SF_dilep_3j_ge2b_fakeCR   = new categoryHistogram("OS_SF_dilep_fakeCR","3j","ge2b",category);
                OS_SF_dilep_ge4j_0b_fakeCR   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","0b",category);
                OS_SF_dilep_ge4j_1b_fakeCR   = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","1b",category);
                OS_SF_dilep_ge4j_ge2b_fakeCR = new categoryHistogram("OS_SF_dilep_fakeCR","ge4j","ge2b",category);

                OS_OF_dilep_2j_0b_fakeCR     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","0b",category);
                OS_OF_dilep_2j_1b_fakeCR     = new categoryHistogram("OS_OF_dilep_fakeCR","2j","1b",category);
                OS_OF_dilep_2j_ge2b_fakeCR   = new categoryHistogram("OS_OF_dilep_fakeCR","2j","ge2b",category);
                OS_OF_dilep_3j_0b_fakeCR     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","0b",category);
                OS_OF_dilep_3j_1b_fakeCR     = new categoryHistogram("OS_OF_dilep_fakeCR","3j","1b",category);
                OS_OF_dilep_3j_ge2b_fakeCR   = new categoryHistogram("OS_OF_dilep_fakeCR","3j","ge2b",category);
                OS_OF_dilep_ge4j_0b_fakeCR   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","0b",category);
                OS_OF_dilep_ge4j_1b_fakeCR   = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","1b",category);
                OS_OF_dilep_ge4j_ge2b_fakeCR = new categoryHistogram("OS_OF_dilep_fakeCR","ge4j","ge2b",category);

                onelepFO_2j_0b_fakeCR        = new categoryHistogram("onelepFO_fakeCR","2j","0b",category);
                onelepFO_2j_1b_fakeCR        = new categoryHistogram("onelepFO_fakeCR","2j","1b",category);
                onelepFO_2j_ge2b_fakeCR      = new categoryHistogram("onelepFO_fakeCR","2j","ge2b",category);
                onelepFO_3j_0b_fakeCR        = new categoryHistogram("onelepFO_fakeCR","3j","0b",category);
                onelepFO_3j_1b_fakeCR        = new categoryHistogram("onelepFO_fakeCR","3j","1b",category);
                onelepFO_3j_ge2b_fakeCR      = new categoryHistogram("onelepFO_fakeCR","3j","ge2b",category);
                onelepFO_ge4j_0b_fakeCR      = new categoryHistogram("onelepFO_fakeCR","ge4j","0b",category);
                onelepFO_ge4j_1b_fakeCR      = new categoryHistogram("onelepFO_fakeCR","ge4j","1b",category);
                onelepFO_ge4j_ge2b_fakeCR    = new categoryHistogram("onelepFO_fakeCR","ge4j","ge2b",category);

                dilepFO_2j_0b_fakeCR         = new categoryHistogram("dilepFO_fakeCR","2j","0b",category);
                dilepFO_2j_1b_fakeCR         = new categoryHistogram("dilepFO_fakeCR","2j","1b",category);
                dilepFO_2j_ge2b_fakeCR       = new categoryHistogram("dilepFO_fakeCR","2j","ge2b",category);
                dilepFO_3j_0b_fakeCR         = new categoryHistogram("dilepFO_fakeCR","3j","0b",category);
                dilepFO_3j_1b_fakeCR         = new categoryHistogram("dilepFO_fakeCR","3j","1b",category);
                dilepFO_3j_ge2b_fakeCR       = new categoryHistogram("dilepFO_fakeCR","3j","ge2b",category);
                dilepFO_ge4j_0b_fakeCR       = new categoryHistogram("dilepFO_fakeCR","ge4j","0b",category);
                dilepFO_ge4j_1b_fakeCR       = new categoryHistogram("dilepFO_fakeCR","ge4j","1b",category);
                dilepFO_ge4j_ge2b_fakeCR     = new categoryHistogram("dilepFO_fakeCR","ge4j","ge2b",category);




                //***********************************************************
                //***********************************************************
                //***********************************************************
                //FLIP CR
                //***********************************************************
                //***********************************************************
                //***********************************************************
                trilep_2j_0b_flipCR      = new categoryHistogram("trilep_flipCR","2j","0b",category);
                trilep_2j_1b_flipCR      = new categoryHistogram("trilep_flipCR","2j","1b",category);
                trilep_2j_ge2b_flipCR    = new categoryHistogram("trilep_flipCR","2j","ge2b",category);
                trilep_3j_0b_flipCR      = new categoryHistogram("trilep_flipCR","3j","0b",category);
                trilep_3j_1b_flipCR      = new categoryHistogram("trilep_flipCR","3j","1b",category);
                trilep_3j_ge2b_flipCR    = new categoryHistogram("trilep_flipCR","3j","ge2b",category);
                trilep_ge4j_0b_flipCR    = new categoryHistogram("trilep_flipCR","ge4j","0b",category);
                trilep_ge4j_1b_flipCR    = new categoryHistogram("trilep_flipCR","ge4j","1b",category);
                trilep_ge4j_ge2b_flipCR  = new categoryHistogram("trilep_flipCR","ge4j","ge2b",category);

                SS_SF_dilep_2j_0b_flipCR     = new categoryHistogram("SS_SF_dilep_flipCR","2j","0b",category);
                SS_SF_dilep_2j_1b_flipCR     = new categoryHistogram("SS_SF_dilep_flipCR","2j","1b",category);
                SS_SF_dilep_2j_ge2b_flipCR   = new categoryHistogram("SS_SF_dilep_flipCR","2j","ge2b",category);
                SS_SF_dilep_3j_0b_flipCR     = new categoryHistogram("SS_SF_dilep_flipCR","3j","0b",category);
                SS_SF_dilep_3j_1b_flipCR     = new categoryHistogram("SS_SF_dilep_flipCR","3j","1b",category);
                SS_SF_dilep_3j_ge2b_flipCR   = new categoryHistogram("SS_SF_dilep_flipCR","3j","ge2b",category);
                SS_SF_dilep_ge4j_0b_flipCR   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","0b",category);
                SS_SF_dilep_ge4j_1b_flipCR   = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","1b",category);
                SS_SF_dilep_ge4j_ge2b_flipCR = new categoryHistogram("SS_SF_dilep_flipCR","ge4j","ge2b",category);

                SS_OF_dilep_2j_0b_flipCR     = new categoryHistogram("SS_OF_dilep_flipCR","2j","0b",category);
                SS_OF_dilep_2j_1b_flipCR     = new categoryHistogram("SS_OF_dilep_flipCR","2j","1b",category);
                SS_OF_dilep_2j_ge2b_flipCR   = new categoryHistogram("SS_OF_dilep_flipCR","2j","ge2b",category);
                SS_OF_dilep_3j_0b_flipCR     = new categoryHistogram("SS_OF_dilep_flipCR","3j","0b",category);
                SS_OF_dilep_3j_1b_flipCR     = new categoryHistogram("SS_OF_dilep_flipCR","3j","1b",category);
                SS_OF_dilep_3j_ge2b_flipCR   = new categoryHistogram("SS_OF_dilep_flipCR","3j","ge2b",category);
                SS_OF_dilep_ge4j_0b_flipCR   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","0b",category);
                SS_OF_dilep_ge4j_1b_flipCR   = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","1b",category);
                SS_OF_dilep_ge4j_ge2b_flipCR = new categoryHistogram("SS_OF_dilep_flipCR","ge4j","ge2b",category);

                OS_SF_dilep_2j_0b_flipCR     = new categoryHistogram("OS_SF_dilep_flipCR","2j","0b",category);
                OS_SF_dilep_2j_1b_flipCR     = new categoryHistogram("OS_SF_dilep_flipCR","2j","1b",category);
                OS_SF_dilep_2j_ge2b_flipCR   = new categoryHistogram("OS_SF_dilep_flipCR","2j","ge2b",category);
                OS_SF_dilep_3j_0b_flipCR     = new categoryHistogram("OS_SF_dilep_flipCR","3j","0b",category);
                OS_SF_dilep_3j_1b_flipCR     = new categoryHistogram("OS_SF_dilep_flipCR","3j","1b",category);
                OS_SF_dilep_3j_ge2b_flipCR   = new categoryHistogram("OS_SF_dilep_flipCR","3j","ge2b",category);
                OS_SF_dilep_ge4j_0b_flipCR   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","0b",category);
                OS_SF_dilep_ge4j_1b_flipCR   = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","1b",category);
                OS_SF_dilep_ge4j_ge2b_flipCR = new categoryHistogram("OS_SF_dilep_flipCR","ge4j","ge2b",category);

                OS_OF_dilep_2j_0b_flipCR     = new categoryHistogram("OS_OF_dilep_flipCR","2j","0b",category);
                OS_OF_dilep_2j_1b_flipCR     = new categoryHistogram("OS_OF_dilep_flipCR","2j","1b",category);
                OS_OF_dilep_2j_ge2b_flipCR   = new categoryHistogram("OS_OF_dilep_flipCR","2j","ge2b",category);
                OS_OF_dilep_3j_0b_flipCR     = new categoryHistogram("OS_OF_dilep_flipCR","3j","0b",category);
                OS_OF_dilep_3j_1b_flipCR     = new categoryHistogram("OS_OF_dilep_flipCR","3j","1b",category);
                OS_OF_dilep_3j_ge2b_flipCR   = new categoryHistogram("OS_OF_dilep_flipCR","3j","ge2b",category);
                OS_OF_dilep_ge4j_0b_flipCR   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","0b",category);
                OS_OF_dilep_ge4j_1b_flipCR   = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","1b",category);
                OS_OF_dilep_ge4j_ge2b_flipCR = new categoryHistogram("OS_OF_dilep_flipCR","ge4j","ge2b",category);

                onelepFO_2j_0b_flipCR        = new categoryHistogram("onelepFO_flipCR","2j","0b",category);
                onelepFO_2j_1b_flipCR        = new categoryHistogram("onelepFO_flipCR","2j","1b",category);
                onelepFO_2j_ge2b_flipCR      = new categoryHistogram("onelepFO_flipCR","2j","ge2b",category);
                onelepFO_3j_0b_flipCR        = new categoryHistogram("onelepFO_flipCR","3j","0b",category);
                onelepFO_3j_1b_flipCR        = new categoryHistogram("onelepFO_flipCR","3j","1b",category);
                onelepFO_3j_ge2b_flipCR      = new categoryHistogram("onelepFO_flipCR","3j","ge2b",category);
                onelepFO_ge4j_0b_flipCR      = new categoryHistogram("onelepFO_flipCR","ge4j","0b",category);
                onelepFO_ge4j_1b_flipCR      = new categoryHistogram("onelepFO_flipCR","ge4j","1b",category);
                onelepFO_ge4j_ge2b_flipCR    = new categoryHistogram("onelepFO_flipCR","ge4j","ge2b",category);

                dilepFO_2j_0b_flipCR         = new categoryHistogram("dilepFO_flipCR","2j","0b",category);
                dilepFO_2j_1b_flipCR         = new categoryHistogram("dilepFO_flipCR","2j","1b",category);
                dilepFO_2j_ge2b_flipCR       = new categoryHistogram("dilepFO_flipCR","2j","ge2b",category);
                dilepFO_3j_0b_flipCR         = new categoryHistogram("dilepFO_flipCR","3j","0b",category);
                dilepFO_3j_1b_flipCR         = new categoryHistogram("dilepFO_flipCR","3j","1b",category);
                dilepFO_3j_ge2b_flipCR       = new categoryHistogram("dilepFO_flipCR","3j","ge2b",category);
                dilepFO_ge4j_0b_flipCR       = new categoryHistogram("dilepFO_flipCR","ge4j","0b",category);
                dilepFO_ge4j_1b_flipCR       = new categoryHistogram("dilepFO_flipCR","ge4j","1b",category);
                dilepFO_ge4j_ge2b_flipCR     = new categoryHistogram("dilepFO_flipCR","ge4j","ge2b",category);

            }
        }

        //methods to fill and save histograms
        void fill(vector<float> variablesForFilling, float weight, int nJets, int nBjets, int nGoodLep, int nFakeableLep, int nLooseNotTight, int nTightNotLoose, vector<int> muCharge_tight, vector<int> elCharge_tight, bool isFake, bool isFlip, bool isSMSS, bool isSignal){
            if(nLooseNotTight>0){
                if(isFake == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_fakeCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else if(isFlip == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_fakeCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else if(isSMSS == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_fakeCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else{
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_fakeCR->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }
            }else if (nTightNotLoose>0){
                if(isFake == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_flipCR_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else if(isFlip == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_flipCR_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else if(isSMSS == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_flipCR_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else{
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_flipCR->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }
            }else{
                if(isFake == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_fakes->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else if(isFlip == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_flips->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else if(isSMSS == 1){
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b_other->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }else{
                    if (nJets==2){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_2j_0b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_0b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_0b->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_2j_1b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_1b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_1b->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_2j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_2j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_2j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==2
                    if (nJets==3){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_3j_0b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_0b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_0b->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_3j_1b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_1b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_1b->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_3j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_3j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_3j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njet==3
                    if (nJets>=4){
                        if (nBjets==0){
                            if (nGoodLep>=3){
                                trilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_0b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_0b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_0b->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets==1){
                            if (nGoodLep>=3){
                                trilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_1b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_1b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_1b->fillHistogram(variablesForFilling, weight);
                            }
                        }else if (nBjets>=2){
                            if (nGoodLep>=3){
                                trilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nGoodLep == 2){
                                if (muCharge_tight.size() == 2){
                                    if (muCharge_tight[0]*muCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{ 
                                        OS_SF_dilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (elCharge_tight.size() == 2) {
                                    if (elCharge_tight[0]*elCharge_tight[1]>0){
                                        SS_SF_dilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_SF_dilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }else if (muCharge_tight.size() == 1) {
                                    if (muCharge_tight[0]*elCharge_tight[0]>0){
                                        SS_OF_dilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }else{
                                        OS_OF_dilep_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                                    }
                                }
                            }
                            if (nGoodLep==1 && nFakeableLep==1){
                                onelepFO_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                            if (nFakeableLep==2){
                                dilepFO_ge4j_ge2b->fillHistogram(variablesForFilling, weight);
                            }
                        }
                    }//njets>=4
                }
            }//sr or cr loop
        }//function close

        void write(string sampleName, TFile* &outfile){
            std::cout << "Writing " << sampleName << " to " << outfile->GetPath() << "/" << outfile->GetName() << std::endl;
            if (sampleName == "background"){
                trilep_2j_0b_fakes->writeHistogram(outfile);
                trilep_2j_1b_fakes->writeHistogram(outfile);
                trilep_2j_ge2b_fakes->writeHistogram(outfile);
                trilep_3j_0b_fakes->writeHistogram(outfile);
                trilep_3j_1b_fakes->writeHistogram(outfile);
                trilep_3j_ge2b_fakes->writeHistogram(outfile);
                trilep_ge4j_0b_fakes->writeHistogram(outfile);
                trilep_ge4j_1b_fakes->writeHistogram(outfile);
                trilep_ge4j_ge2b_fakes->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_fakes->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_fakes->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_fakes->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_fakes->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_fakes->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_fakes->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_fakes->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_fakes->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_fakes->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_fakes->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_fakes->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_fakes->writeHistogram(outfile);

                onelepFO_2j_0b_fakes->writeHistogram(outfile);
                onelepFO_2j_1b_fakes->writeHistogram(outfile);
                onelepFO_2j_ge2b_fakes->writeHistogram(outfile);
                onelepFO_3j_0b_fakes->writeHistogram(outfile);
                onelepFO_3j_1b_fakes->writeHistogram(outfile);
                onelepFO_3j_ge2b_fakes->writeHistogram(outfile);
                onelepFO_ge4j_0b_fakes->writeHistogram(outfile);
                onelepFO_ge4j_1b_fakes->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_fakes->writeHistogram(outfile);

                dilepFO_2j_0b_fakes->writeHistogram(outfile);
                dilepFO_2j_1b_fakes->writeHistogram(outfile);
                dilepFO_2j_ge2b_fakes->writeHistogram(outfile);
                dilepFO_3j_0b_fakes->writeHistogram(outfile);
                dilepFO_3j_1b_fakes->writeHistogram(outfile);
                dilepFO_3j_ge2b_fakes->writeHistogram(outfile);
                dilepFO_ge4j_0b_fakes->writeHistogram(outfile);
                dilepFO_ge4j_1b_fakes->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_fakes->writeHistogram(outfile);



                trilep_2j_0b_flips->writeHistogram(outfile);
                trilep_2j_1b_flips->writeHistogram(outfile);
                trilep_2j_ge2b_flips->writeHistogram(outfile);
                trilep_3j_0b_flips->writeHistogram(outfile);
                trilep_3j_1b_flips->writeHistogram(outfile);
                trilep_3j_ge2b_flips->writeHistogram(outfile);
                trilep_ge4j_0b_flips->writeHistogram(outfile);
                trilep_ge4j_1b_flips->writeHistogram(outfile);
                trilep_ge4j_ge2b_flips->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_flips->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_flips->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_flips->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_flips->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_flips->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_flips->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_flips->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_flips->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_flips->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_flips->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_flips->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_flips->writeHistogram(outfile);

                onelepFO_2j_0b_flips->writeHistogram(outfile);
                onelepFO_2j_1b_flips->writeHistogram(outfile);
                onelepFO_2j_ge2b_flips->writeHistogram(outfile);
                onelepFO_3j_0b_flips->writeHistogram(outfile);
                onelepFO_3j_1b_flips->writeHistogram(outfile);
                onelepFO_3j_ge2b_flips->writeHistogram(outfile);
                onelepFO_ge4j_0b_flips->writeHistogram(outfile);
                onelepFO_ge4j_1b_flips->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_flips->writeHistogram(outfile);

                dilepFO_2j_0b_flips->writeHistogram(outfile);
                dilepFO_2j_1b_flips->writeHistogram(outfile);
                dilepFO_2j_ge2b_flips->writeHistogram(outfile);
                dilepFO_3j_0b_flips->writeHistogram(outfile);
                dilepFO_3j_1b_flips->writeHistogram(outfile);
                dilepFO_3j_ge2b_flips->writeHistogram(outfile);
                dilepFO_ge4j_0b_flips->writeHistogram(outfile);
                dilepFO_ge4j_1b_flips->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_flips->writeHistogram(outfile);



                trilep_2j_0b_other->writeHistogram(outfile);
                trilep_2j_1b_other->writeHistogram(outfile);
                trilep_2j_ge2b_other->writeHistogram(outfile);
                trilep_3j_0b_other->writeHistogram(outfile);
                trilep_3j_1b_other->writeHistogram(outfile);
                trilep_3j_ge2b_other->writeHistogram(outfile);
                trilep_ge4j_0b_other->writeHistogram(outfile);
                trilep_ge4j_1b_other->writeHistogram(outfile);
                trilep_ge4j_ge2b_other->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_other->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_other->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_other->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_other->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_other->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_other->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_other->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_other->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_other->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_other->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_other->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_other->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_other->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_other->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_other->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_other->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_other->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_other->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_other->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_other->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_other->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_other->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_other->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_other->writeHistogram(outfile);

                onelepFO_2j_0b_other->writeHistogram(outfile);
                onelepFO_2j_1b_other->writeHistogram(outfile);
                onelepFO_2j_ge2b_other->writeHistogram(outfile);
                onelepFO_3j_0b_other->writeHistogram(outfile);
                onelepFO_3j_1b_other->writeHistogram(outfile);
                onelepFO_3j_ge2b_other->writeHistogram(outfile);
                onelepFO_ge4j_0b_other->writeHistogram(outfile);
                onelepFO_ge4j_1b_other->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_other->writeHistogram(outfile);

                dilepFO_2j_0b_other->writeHistogram(outfile);
                dilepFO_2j_1b_other->writeHistogram(outfile);
                dilepFO_2j_ge2b_other->writeHistogram(outfile);
                dilepFO_3j_0b_other->writeHistogram(outfile);
                dilepFO_3j_1b_other->writeHistogram(outfile);
                dilepFO_3j_ge2b_other->writeHistogram(outfile);
                dilepFO_ge4j_0b_other->writeHistogram(outfile);
                dilepFO_ge4j_1b_other->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_other->writeHistogram(outfile);





                trilep_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                trilep_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                trilep_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                trilep_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                trilep_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                trilep_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                trilep_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                trilep_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                trilep_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);

                onelepFO_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);

                dilepFO_2j_0b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_2j_1b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_2j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_3j_0b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_3j_1b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_3j_ge2b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_ge4j_0b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_ge4j_1b_fakeCR_fakes->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_fakeCR_fakes->writeHistogram(outfile);



                trilep_2j_0b_fakeCR_flips->writeHistogram(outfile);
                trilep_2j_1b_fakeCR_flips->writeHistogram(outfile);
                trilep_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                trilep_3j_0b_fakeCR_flips->writeHistogram(outfile);
                trilep_3j_1b_fakeCR_flips->writeHistogram(outfile);
                trilep_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                trilep_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                trilep_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                trilep_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);

                onelepFO_2j_0b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_2j_1b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_3j_0b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_3j_1b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);

                dilepFO_2j_0b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_2j_1b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_2j_ge2b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_3j_0b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_3j_1b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_3j_ge2b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_ge4j_0b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_ge4j_1b_fakeCR_flips->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_fakeCR_flips->writeHistogram(outfile);



                trilep_2j_0b_fakeCR_other->writeHistogram(outfile);
                trilep_2j_1b_fakeCR_other->writeHistogram(outfile);
                trilep_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                trilep_3j_0b_fakeCR_other->writeHistogram(outfile);
                trilep_3j_1b_fakeCR_other->writeHistogram(outfile);
                trilep_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                trilep_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                trilep_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                trilep_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);

                onelepFO_2j_0b_fakeCR_other->writeHistogram(outfile);
                onelepFO_2j_1b_fakeCR_other->writeHistogram(outfile);
                onelepFO_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                onelepFO_3j_0b_fakeCR_other->writeHistogram(outfile);
                onelepFO_3j_1b_fakeCR_other->writeHistogram(outfile);
                onelepFO_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                onelepFO_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                onelepFO_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);

                dilepFO_2j_0b_fakeCR_other->writeHistogram(outfile);
                dilepFO_2j_1b_fakeCR_other->writeHistogram(outfile);
                dilepFO_2j_ge2b_fakeCR_other->writeHistogram(outfile);
                dilepFO_3j_0b_fakeCR_other->writeHistogram(outfile);
                dilepFO_3j_1b_fakeCR_other->writeHistogram(outfile);
                dilepFO_3j_ge2b_fakeCR_other->writeHistogram(outfile);
                dilepFO_ge4j_0b_fakeCR_other->writeHistogram(outfile);
                dilepFO_ge4j_1b_fakeCR_other->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_fakeCR_other->writeHistogram(outfile);





                trilep_2j_0b_flipCR_fakes->writeHistogram(outfile);
                trilep_2j_1b_flipCR_fakes->writeHistogram(outfile);
                trilep_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                trilep_3j_0b_flipCR_fakes->writeHistogram(outfile);
                trilep_3j_1b_flipCR_fakes->writeHistogram(outfile);
                trilep_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                trilep_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                trilep_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                trilep_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);

                onelepFO_2j_0b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_2j_1b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_3j_0b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_3j_1b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);

                dilepFO_2j_0b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_2j_1b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_2j_ge2b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_3j_0b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_3j_1b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_3j_ge2b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_ge4j_0b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_ge4j_1b_flipCR_fakes->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_flipCR_fakes->writeHistogram(outfile);



                trilep_2j_0b_flipCR_flips->writeHistogram(outfile);
                trilep_2j_1b_flipCR_flips->writeHistogram(outfile);
                trilep_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                trilep_3j_0b_flipCR_flips->writeHistogram(outfile);
                trilep_3j_1b_flipCR_flips->writeHistogram(outfile);
                trilep_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                trilep_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                trilep_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                trilep_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);

                onelepFO_2j_0b_flipCR_flips->writeHistogram(outfile);
                onelepFO_2j_1b_flipCR_flips->writeHistogram(outfile);
                onelepFO_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                onelepFO_3j_0b_flipCR_flips->writeHistogram(outfile);
                onelepFO_3j_1b_flipCR_flips->writeHistogram(outfile);
                onelepFO_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                onelepFO_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                onelepFO_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);

                dilepFO_2j_0b_flipCR_flips->writeHistogram(outfile);
                dilepFO_2j_1b_flipCR_flips->writeHistogram(outfile);
                dilepFO_2j_ge2b_flipCR_flips->writeHistogram(outfile);
                dilepFO_3j_0b_flipCR_flips->writeHistogram(outfile);
                dilepFO_3j_1b_flipCR_flips->writeHistogram(outfile);
                dilepFO_3j_ge2b_flipCR_flips->writeHistogram(outfile);
                dilepFO_ge4j_0b_flipCR_flips->writeHistogram(outfile);
                dilepFO_ge4j_1b_flipCR_flips->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_flipCR_flips->writeHistogram(outfile);



                trilep_2j_0b_flipCR_other->writeHistogram(outfile);
                trilep_2j_1b_flipCR_other->writeHistogram(outfile);
                trilep_2j_ge2b_flipCR_other->writeHistogram(outfile);
                trilep_3j_0b_flipCR_other->writeHistogram(outfile);
                trilep_3j_1b_flipCR_other->writeHistogram(outfile);
                trilep_3j_ge2b_flipCR_other->writeHistogram(outfile);
                trilep_ge4j_0b_flipCR_other->writeHistogram(outfile);
                trilep_ge4j_1b_flipCR_other->writeHistogram(outfile);
                trilep_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_flipCR_other->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_flipCR_other->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_flipCR_other->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_flipCR_other->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

                onelepFO_2j_0b_flipCR_other->writeHistogram(outfile);
                onelepFO_2j_1b_flipCR_other->writeHistogram(outfile);
                onelepFO_2j_ge2b_flipCR_other->writeHistogram(outfile);
                onelepFO_3j_0b_flipCR_other->writeHistogram(outfile);
                onelepFO_3j_1b_flipCR_other->writeHistogram(outfile);
                onelepFO_3j_ge2b_flipCR_other->writeHistogram(outfile);
                onelepFO_ge4j_0b_flipCR_other->writeHistogram(outfile);
                onelepFO_ge4j_1b_flipCR_other->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

                dilepFO_2j_0b_flipCR_other->writeHistogram(outfile);
                dilepFO_2j_1b_flipCR_other->writeHistogram(outfile);
                dilepFO_2j_ge2b_flipCR_other->writeHistogram(outfile);
                dilepFO_3j_0b_flipCR_other->writeHistogram(outfile);
                dilepFO_3j_1b_flipCR_other->writeHistogram(outfile);
                dilepFO_3j_ge2b_flipCR_other->writeHistogram(outfile);
                dilepFO_ge4j_0b_flipCR_other->writeHistogram(outfile);
                dilepFO_ge4j_1b_flipCR_other->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_flipCR_other->writeHistogram(outfile);

            }else{

                trilep_2j_0b->writeHistogram(outfile);
                trilep_2j_1b->writeHistogram(outfile);
                trilep_2j_ge2b->writeHistogram(outfile);
                trilep_3j_0b->writeHistogram(outfile);
                trilep_3j_1b->writeHistogram(outfile);
                trilep_3j_ge2b->writeHistogram(outfile);
                trilep_ge4j_0b->writeHistogram(outfile);
                trilep_ge4j_1b->writeHistogram(outfile);
                trilep_ge4j_ge2b->writeHistogram(outfile);

                SS_SF_dilep_2j_0b->writeHistogram(outfile);
                SS_SF_dilep_2j_1b->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b->writeHistogram(outfile);
                SS_SF_dilep_3j_0b->writeHistogram(outfile);
                SS_SF_dilep_3j_1b->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b->writeHistogram(outfile);

                SS_OF_dilep_2j_0b->writeHistogram(outfile);
                SS_OF_dilep_2j_1b->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b->writeHistogram(outfile);
                SS_OF_dilep_3j_0b->writeHistogram(outfile);
                SS_OF_dilep_3j_1b->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b->writeHistogram(outfile);

                OS_SF_dilep_2j_0b->writeHistogram(outfile);
                OS_SF_dilep_2j_1b->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b->writeHistogram(outfile);
                OS_SF_dilep_3j_0b->writeHistogram(outfile);
                OS_SF_dilep_3j_1b->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b->writeHistogram(outfile);

                OS_OF_dilep_2j_0b->writeHistogram(outfile);
                OS_OF_dilep_2j_1b->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b->writeHistogram(outfile);
                OS_OF_dilep_3j_0b->writeHistogram(outfile);
                OS_OF_dilep_3j_1b->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b->writeHistogram(outfile);

                onelepFO_2j_0b->writeHistogram(outfile);
                onelepFO_2j_1b->writeHistogram(outfile);
                onelepFO_2j_ge2b->writeHistogram(outfile);
                onelepFO_3j_0b->writeHistogram(outfile);
                onelepFO_3j_1b->writeHistogram(outfile);
                onelepFO_3j_ge2b->writeHistogram(outfile);
                onelepFO_ge4j_0b->writeHistogram(outfile);
                onelepFO_ge4j_1b->writeHistogram(outfile);
                onelepFO_ge4j_ge2b->writeHistogram(outfile);

                dilepFO_2j_0b->writeHistogram(outfile);
                dilepFO_2j_1b->writeHistogram(outfile);
                dilepFO_2j_ge2b->writeHistogram(outfile);
                dilepFO_3j_0b->writeHistogram(outfile);
                dilepFO_3j_1b->writeHistogram(outfile);
                dilepFO_3j_ge2b->writeHistogram(outfile);
                dilepFO_ge4j_0b->writeHistogram(outfile);
                dilepFO_ge4j_1b->writeHistogram(outfile);
                dilepFO_ge4j_ge2b->writeHistogram(outfile);






                trilep_2j_0b_fakeCR->writeHistogram(outfile);
                trilep_2j_1b_fakeCR->writeHistogram(outfile);
                trilep_2j_ge2b_fakeCR->writeHistogram(outfile);
                trilep_3j_0b_fakeCR->writeHistogram(outfile);
                trilep_3j_1b_fakeCR->writeHistogram(outfile);
                trilep_3j_ge2b_fakeCR->writeHistogram(outfile);
                trilep_ge4j_0b_fakeCR->writeHistogram(outfile);
                trilep_ge4j_1b_fakeCR->writeHistogram(outfile);
                trilep_ge4j_ge2b_fakeCR->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_fakeCR->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_fakeCR->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_fakeCR->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_fakeCR->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_fakeCR->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_fakeCR->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_fakeCR->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_fakeCR->writeHistogram(outfile);

                onelepFO_2j_0b_fakeCR->writeHistogram(outfile);
                onelepFO_2j_1b_fakeCR->writeHistogram(outfile);
                onelepFO_2j_ge2b_fakeCR->writeHistogram(outfile);
                onelepFO_3j_0b_fakeCR->writeHistogram(outfile);
                onelepFO_3j_1b_fakeCR->writeHistogram(outfile);
                onelepFO_3j_ge2b_fakeCR->writeHistogram(outfile);
                onelepFO_ge4j_0b_fakeCR->writeHistogram(outfile);
                onelepFO_ge4j_1b_fakeCR->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_fakeCR->writeHistogram(outfile);

                dilepFO_2j_0b_fakeCR->writeHistogram(outfile);
                dilepFO_2j_1b_fakeCR->writeHistogram(outfile);
                dilepFO_2j_ge2b_fakeCR->writeHistogram(outfile);
                dilepFO_3j_0b_fakeCR->writeHistogram(outfile);
                dilepFO_3j_1b_fakeCR->writeHistogram(outfile);
                dilepFO_3j_ge2b_fakeCR->writeHistogram(outfile);
                dilepFO_ge4j_0b_fakeCR->writeHistogram(outfile);
                dilepFO_ge4j_1b_fakeCR->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_fakeCR->writeHistogram(outfile);






                trilep_2j_0b_flipCR->writeHistogram(outfile);
                trilep_2j_1b_flipCR->writeHistogram(outfile);
                trilep_2j_ge2b_flipCR->writeHistogram(outfile);
                trilep_3j_0b_flipCR->writeHistogram(outfile);
                trilep_3j_1b_flipCR->writeHistogram(outfile);
                trilep_3j_ge2b_flipCR->writeHistogram(outfile);
                trilep_ge4j_0b_flipCR->writeHistogram(outfile);
                trilep_ge4j_1b_flipCR->writeHistogram(outfile);
                trilep_ge4j_ge2b_flipCR->writeHistogram(outfile);

                SS_SF_dilep_2j_0b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_2j_1b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_2j_ge2b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_3j_0b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_3j_1b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_3j_ge2b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_ge4j_0b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_ge4j_1b_flipCR->writeHistogram(outfile);
                SS_SF_dilep_ge4j_ge2b_flipCR->writeHistogram(outfile);

                SS_OF_dilep_2j_0b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_2j_1b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_2j_ge2b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_3j_0b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_3j_1b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_3j_ge2b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_ge4j_0b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_ge4j_1b_flipCR->writeHistogram(outfile);
                SS_OF_dilep_ge4j_ge2b_flipCR->writeHistogram(outfile);

                OS_SF_dilep_2j_0b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_2j_1b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_2j_ge2b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_3j_0b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_3j_1b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_3j_ge2b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_ge4j_0b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_ge4j_1b_flipCR->writeHistogram(outfile);
                OS_SF_dilep_ge4j_ge2b_flipCR->writeHistogram(outfile);

                OS_OF_dilep_2j_0b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_2j_1b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_2j_ge2b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_3j_0b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_3j_1b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_3j_ge2b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_ge4j_0b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_ge4j_1b_flipCR->writeHistogram(outfile);
                OS_OF_dilep_ge4j_ge2b_flipCR->writeHistogram(outfile);

                onelepFO_2j_0b_flipCR->writeHistogram(outfile);
                onelepFO_2j_1b_flipCR->writeHistogram(outfile);
                onelepFO_2j_ge2b_flipCR->writeHistogram(outfile);
                onelepFO_3j_0b_flipCR->writeHistogram(outfile);
                onelepFO_3j_1b_flipCR->writeHistogram(outfile);
                onelepFO_3j_ge2b_flipCR->writeHistogram(outfile);
                onelepFO_ge4j_0b_flipCR->writeHistogram(outfile);
                onelepFO_ge4j_1b_flipCR->writeHistogram(outfile);
                onelepFO_ge4j_ge2b_flipCR->writeHistogram(outfile);

                dilepFO_2j_0b_flipCR->writeHistogram(outfile);
                dilepFO_2j_1b_flipCR->writeHistogram(outfile);
                dilepFO_2j_ge2b_flipCR->writeHistogram(outfile);
                dilepFO_3j_0b_flipCR->writeHistogram(outfile);
                dilepFO_3j_1b_flipCR->writeHistogram(outfile);
                dilepFO_3j_ge2b_flipCR->writeHistogram(outfile);
                dilepFO_ge4j_0b_flipCR->writeHistogram(outfile);
                dilepFO_ge4j_1b_flipCR->writeHistogram(outfile);
                dilepFO_ge4j_ge2b_flipCR->writeHistogram(outfile);
            }

        }



};
