#include "TList.h"
#include "TObjString.h"

#include "Generate_uniform_event.C"
#include "DisplyText.C"
#include "Histograms.cpp"
#include "ConfigBeamE.cpp"

/* root CodeRun.cpp -q -b */

void Uniform_sample_generator(
    double Ebeam = 5.98636, bool EnforceMomCon = false,
    TString OutPutFolder = "/lustre19/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/598636MeV/",
    // TString OutPutFolder = "./OutPut/",
    TString OutputFileNamePrefix = "Uniform_sample",
    int nFiles = 10, int nEvents = 10000,
    double theta_e_min = 5., double theta_e_max = 40.,
    double theta_p_min = 5., double theta_p_max = 45.,
    double theta_n_min = 5., double theta_n_max = 35.) {
    // -------------------------------------------------------------------------------------------------
    cout << "\n";

    OutputFileNamePrefix = ConfigBeamE(Ebeam, OutputFileNamePrefix);

    if (EnforceMomCon) {
        OutputFileNamePrefix = OutputFileNamePrefix + "_wMomCon";
    } else {
        OutputFileNamePrefix = OutputFileNamePrefix + "_woMomCon";
    }

    bool GenerateLundFiles = true;
    bool EnforceMomentumConservation = EnforceMomCon;
    int DisplaySpace = 74;

    cout << "\n\n===========================================================================\n";
    cout << setw(50) << "Uniform sample generator\n";
    cout << "===========================================================================\n\n";

    DisplyText("OutputFileNamePrefix", DisplaySpace, OutputFileNamePrefix);
    DisplyText("nFiles", DisplaySpace, nFiles);
    DisplyText("nEvents", DisplaySpace, nEvents);
    DisplyText("Beam energy [GeV]", DisplaySpace, Ebeam);

    DisplyText("GenerateLundFiles", DisplaySpace, GenerateLundFiles);
    DisplyText("Enforce momentum conservation", DisplaySpace, EnforceMomentumConservation);

    cout << "\n";

    TRandom3 ran(0);
    const int nParticles = 2;
    double mass_e = 0.511e-3;
    double mass_p = 0.938272;
    double mass_n = 0.93957;
    DisplyText("nParticles", DisplaySpace, nParticles);
    DisplyText("mass_e [GeV]", DisplaySpace, mass_e);
    DisplyText("mass_p [GeV]", DisplaySpace, mass_p);
    DisplyText("mass_n [GeV]", DisplaySpace, mass_n);

    cout << "\n";

    string OutPutFolder0(OutPutFolder.Data());
    DisplyText("OutPutFolder", DisplaySpace, OutPutFolder);

    TString lundPath = OutPutFolder + "lundfiles", mchipoPath = OutPutFolder + "mchipo";
    TString reconhipoPath = OutPutFolder + "reconhipo", rootfilesPath = OutPutFolder + "rootfiles";
    string lundPath0(lundPath.Data()), mchipoPath0(mchipoPath.Data());
    string reconhipoPath0(reconhipoPath.Data()), rootfilesPath0(rootfilesPath.Data());
    DisplyText("lundPath", DisplaySpace, lundPath);
    DisplyText("mchipoPath", DisplaySpace, mchipoPath);
    DisplyText("reconhipoPath", DisplaySpace, reconhipoPath);
    DisplyText("rootfilesPath", DisplaySpace, rootfilesPath);

    TString MonitoringPlotsPath = OutPutFolder + "MonitoringPlotsPath/";
    string MonitoringPlotsPath0(MonitoringPlotsPath.Data());
    DisplyText("MonitoringPlotsPath", DisplaySpace, MonitoringPlotsPath);

    TList *plots = new TList();
    string OutputFileNamePrefix0(OutputFileNamePrefix.Data());
    string listName = OutPutFolder0 + OutputFileNamePrefix0 + "_plots.root";
    const char *TListName = listName.c_str();
    DisplyText("Plot list path", DisplaySpace, listName);

    cout << "\n";

    //Not useful usually
    double targP = 0.; // polarization
    double beamP = 0.; // polarization
    int interactN = 1;
    int beamType = 11;
    DisplyText("targP", DisplaySpace, targP);
    DisplyText("beamP", DisplaySpace, beamP);
    DisplyText("interactN", DisplaySpace, interactN);
    DisplyText("beamType", DisplaySpace, beamType);

    double beamE_in_lundfiles = -99; // GeV
    DisplyText("beamE_in_lundfiles", DisplaySpace, beamE_in_lundfiles);

    double weight = 1;
    DisplyText("weight", DisplaySpace, weight);

    cout << "\nCreating plot directories...\n";

    system(("rm -r " + OutPutFolder0).c_str()); // Delete old lundPath
    system(("mkdir -p " + OutPutFolder0).c_str()); // Make new lundPath

    system(("mkdir -p " + lundPath0).c_str()); // Make new lundPath
    system(("mkdir -p " + mchipoPath0).c_str()); // Make new lundPath
    system(("mkdir -p " + reconhipoPath0).c_str()); // Make new lundPath
    system(("mkdir -p " + rootfilesPath0).c_str()); // Make new lundPath

    system(("mkdir -p " + MonitoringPlotsPath0).c_str()); // Make new monitoring plots folder

    if (GenerateLundFiles) {
        InitHistograms(Ebeam);

        // if (nFiles > nEvents / 10000) { nFiles = nEvents / 10000; }

        cout << "\nGenerating lund files...\n\n";

        for (int iFiles = 1; iFiles < nFiles + 1; iFiles++) {
            TString OutFileName = Form("%s/%s_%d.txt", lundPath.Data(), OutputFileNamePrefix.Data(), iFiles);
            // TString OutFileName = Form("%s/%s_%d.dat", lundPath.Data(), OutputFileNamePrefix.Data(), iFiles);
            cout << "OutFileName: " << std::setw(49) << OutFileName << "\n";

            ofstream OutFile;
            OutFile.open(OutFileName);
            if (!OutFile.is_open()) { cout << "Output file cannot be created" << endl; }

            TString formatstring, outstring;

            Generate_uniform_event(EnforceMomentumConservation, TH1_hist_list_ep, TH2_hist_list_ep, OutFile, formatstring, outstring, ran, 2212, nEvents, nParticles,
                                   targP, beamP, interactN, beamType = 11, beamE_in_lundfiles, Ebeam, weight, mass_e, mass_p, theta_e_min, theta_e_max, theta_p_min,
                                   theta_p_max);
            Generate_uniform_event(EnforceMomentumConservation, TH1_hist_list_en, TH2_hist_list_en, OutFile, formatstring, outstring, ran, 2112, nEvents, nParticles,
                                   targP, beamP, interactN, beamType = 11, beamE_in_lundfiles, Ebeam, weight, mass_e, mass_n, theta_e_min, theta_e_max, theta_n_min,
                                   theta_n_max);

            OutFile.close();
        }

        cout << "\nPlotting and saving monitoring plots\n\n";

        TCanvas *c1 = new TCanvas("canvas", "canvas", 1000, 750); // normal res
        c1->SetGrid(), c1->SetBottomMargin(0.14), c1->SetLeftMargin(0.16), c1->SetRightMargin(0.12), c1->cd();

        int num = 0;

        for (int i = 0; i < TH1_hist_list_ep.size(); i++) {
            TH1_hist_list_ep[i]->Sumw2();
            TH1_hist_list_ep[i]->GetXaxis()->CenterTitle();
            TH1_hist_list_ep[i]->GetXaxis()->SetTitleSize(0.06);
            TH1_hist_list_ep[i]->GetXaxis()->SetLabelSize(0.0425);
            TH1_hist_list_ep[i]->GetYaxis()->SetTitle("Number of events");
            TH1_hist_list_ep[i]->GetYaxis()->CenterTitle();
            TH1_hist_list_ep[i]->GetYaxis()->SetTitleSize(0.06);
            TH1_hist_list_ep[i]->GetYaxis()->SetLabelSize(0.0425);
            plots->Add(TH1_hist_list_ep[i]);

            TH1_hist_list_ep[i]->Draw();
            string SavePath = MonitoringPlotsPath0 + to_string(num + 1) + "_" + TH1_hist_list_ep[i]->GetName() + ".png";
            c1->SaveAs(SavePath.c_str());
            ++num;
        }

        for (int i = 0; i < TH2_hist_list_ep.size(); i++) {
            TH2_hist_list_ep[i]->GetXaxis()->CenterTitle();
            TH2_hist_list_ep[i]->GetXaxis()->SetTitleSize(0.06);
            TH2_hist_list_ep[i]->GetXaxis()->SetLabelSize(0.0425);
            TH2_hist_list_ep[i]->GetYaxis()->CenterTitle();
            TH2_hist_list_ep[i]->GetYaxis()->SetTitleSize(0.06);
            TH2_hist_list_ep[i]->GetYaxis()->SetLabelSize(0.0425);
            plots->Add(TH2_hist_list_ep[i]);

            TH2_hist_list_ep[i]->Draw("colz");
            string SavePath = MonitoringPlotsPath0 + to_string(num + 1) + "_" + TH2_hist_list_ep[i]->GetName() + ".png";
            c1->SaveAs(SavePath.c_str());
            ++num;
        }

        for (int i = 0; i < TH1_hist_list_en.size(); i++) {
            TH1_hist_list_en[i]->Sumw2();
            TH1_hist_list_en[i]->GetXaxis()->CenterTitle();
            TH1_hist_list_en[i]->GetXaxis()->SetTitleSize(0.06);
            TH1_hist_list_en[i]->GetXaxis()->SetLabelSize(0.0425);
            TH1_hist_list_en[i]->GetYaxis()->SetTitle("Number of events");
            TH1_hist_list_en[i]->GetYaxis()->CenterTitle();
            TH1_hist_list_en[i]->GetYaxis()->SetTitleSize(0.06);
            TH1_hist_list_en[i]->GetYaxis()->SetLabelSize(0.0425);
            plots->Add(TH1_hist_list_en[i]);

            TH1_hist_list_en[i]->Draw();
            string SavePath = MonitoringPlotsPath0 + to_string(num + 1) + "_" + TH1_hist_list_en[i]->GetName() + ".png";
            c1->SaveAs(SavePath.c_str());
            ++num;
        }

        for (int i = 0; i < TH2_hist_list_en.size(); i++) {
            TH2_hist_list_en[i]->GetXaxis()->CenterTitle();
            TH2_hist_list_en[i]->GetXaxis()->SetTitleSize(0.06);
            TH2_hist_list_en[i]->GetXaxis()->SetLabelSize(0.0425);
            TH2_hist_list_en[i]->GetYaxis()->CenterTitle();
            TH2_hist_list_en[i]->GetYaxis()->SetTitleSize(0.06);
            TH2_hist_list_en[i]->GetYaxis()->SetLabelSize(0.0425);
            plots->Add(TH2_hist_list_en[i]);

            TH2_hist_list_en[i]->Draw("colz");
            string SavePath = MonitoringPlotsPath0 + to_string(num + 1) + "_" + TH2_hist_list_en[i]->GetName() + ".png";
            c1->SaveAs(SavePath.c_str());
            ++num;
        }

        TFile *plots_fout = new TFile(TListName, "recreate");
        plots_fout->cd();
        plots->Write();
        plots_fout->Write();
        plots_fout->Close();
    } else {
        cout << "\nLund files generation disabled.\n";
    }
}
