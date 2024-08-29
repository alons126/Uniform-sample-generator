#include <cmath>

#include "addParticle.C"
#include "Histograms.h"

/* Uniform electron events */
void Generate_uniform_event(TVector3 vtx, vector<TH1*> TH1_hist_list, vector<TH2*> TH2_hist_list, ofstream& OutFile, TString formatstring, TString outstring, TRandom3& ran,
                            int nEvents = 10000, double targP = 0., double beamP = 0., int interactN = 1, int beamType = 11, double beamE_in_lundfiles = -99,
                            double Ebeam = -99, double weight = 1, double mass_e = 0.511e-3, double theta_e_min = 5., double theta_e_max = 40.)
{
    double pi = 3.14159265359;
    int i = 0;

    while (i < nEvents)
    {
        /* Create nEvents uniform (e,e'p) events and nEvents uniform (e,e'n) events
           LUND header for the event: */
        formatstring = "%i \t %i \t %i \t %.3f \t %.3f \t %i \t %.1f \t %i \t %i \t %.3f \n";
        outstring = Form(formatstring, 1, 1 /* A */, 1 /* Z */, targP, beamP, beamType, beamE_in_lundfiles, interactN, i, weight);
        // OutFile << outstring;

        /* Electron */
        TVector3 P_e_3v;
        double Theta_e = ran.Uniform(theta_e_min, theta_e_max); // Uniform Theta_e from theta_e_min to theta_e_max
        double Phi_e = ran.Uniform(-180., 180.); // Uniform Phi_e from -180 to +180
        double P_e = ran.Uniform(0, Ebeam); // Uniform P_e from 0 to P_e = beamE
        P_e_3v.SetMagThetaPhi(P_e, Theta_e * TMath::DegToRad(), Phi_e * TMath::DegToRad());
        OutFile << outstring;
        OutFile << addParticle(1, 11, P_e_3v, mass_e, vtx);

        hTheta_e_1e->Fill(P_e_3v.Theta() * TMath::RadToDeg());
        hPhi_e_1e->Fill(P_e_3v.Phi() * TMath::RadToDeg());
        hP_e_1e->Fill(P_e_3v.Mag());

        hTheta_e_VS_Phi_e_1e->Fill(P_e_3v.Phi() * TMath::RadToDeg(), P_e_3v.Theta() * TMath::RadToDeg());
        hTheta_e_VS_P_e_1e->Fill(P_e_3v.Mag(), P_e_3v.Theta() * TMath::RadToDeg());
        hPhi_e_VS_P_e_1e->Fill(P_e_3v.Mag(), P_e_3v.Phi() * TMath::RadToDeg());

        ++i;
    }
}

/* Uniform (e,e'p) and (e,e'n) events */
void Generate_uniform_event(TVector3 vtx, const bool& EnforceMomentumConservation, vector<TH1*> TH1_hist_list, vector<TH2*> TH2_hist_list, ofstream& OutFile,
                            TString formatstring, TString outstring, TRandom3& ran, int N_pid, int nEvents = 10000, const int nParticles = 2, double targP = 0.,
                            double beamP = 0., int interactN = 1, int beamType = 11, double beamE_in_lundfiles = -99, double Ebeam = -99, double weight = 1,
                            double mass_e = 0.511e-3, double mass_N = 0.938272, double theta_e_min = 5., double theta_e_max = 40., double theta_N_min = 5.,
                            double theta_N_max = 45.)
{
    double pi = 3.14159265359;
    int i = 0;

    while (i < nEvents)
    {
        /* Create nEvents uniform (e,e'p) events and nEvents uniform (e,e'n) events
           LUND header for the event: */
        formatstring = "%i \t %i \t %i \t %.3f \t %.3f \t %i \t %.1f \t %i \t %i \t %.3f \n";
        outstring = Form(formatstring, nParticles, 1 /* A */, 1 /* Z */, targP, beamP, beamType, beamE_in_lundfiles, interactN, i, weight);
        // OutFile << outstring;

        /* Nucleon - uniform Theta_N, Phi_N, and P_N */
        TVector3 P_N_3v;
        double Theta_N = ran.Uniform(theta_N_min, theta_N_max); // Uniform Theta_N from theta_N_min to theta_N_max
        double Phi_N = ran.Uniform(-180., 180.); // Uniform Phi_N from -180 to +180
        double P_N = ran.Uniform(0, Ebeam); // Uniform P_N from 0 to P_N = beamE
        P_N_3v.SetMagThetaPhi(P_N, Theta_N * TMath::DegToRad(), Phi_N * TMath::DegToRad());

        /* Electron */
        //TODO: ask Adi if we can use these constant Theta_e and Phi_e for the electron
        //TODO: ask Adi if we can use these constant P_e as well
        TVector3 P_e_3v;
        double Theta_e = 25.; // Uniform Theta_e from theta_e_min to theta_e_max
        // double Theta_e = ran.Uniform(theta_e_min, theta_e_max); // Uniform Theta_e from theta_e_min to theta_e_max
        double Phi_e = 0.; // Uniform Phi_e from -180 to +180
        // double Phi_e = ran.Uniform(-180., 180.); // Uniform Phi_e from -180 to +180
        double P_e = ran.Uniform(P_N_3v.Mag(), Ebeam); // Uniform P_e from P_N to P_e = beamE
        P_e_3v.SetMagThetaPhi(P_e, Theta_e * TMath::DegToRad(), Phi_e * TMath::DegToRad());

        OutFile << outstring;
        OutFile << addParticle(1, 11, P_e_3v, mass_e, vtx);
        OutFile << addParticle(2, N_pid, P_N_3v, mass_N, vtx);
        // OutFile << "\n";

        if (N_pid == 2212)
        {
            hTheta_e_ep->Fill(P_e_3v.Theta() * TMath::RadToDeg());
            hPhi_e_ep->Fill(P_e_3v.Phi() * TMath::RadToDeg());
            hP_e_ep->Fill(P_e_3v.Mag());

            hTheta_e_VS_Phi_e_ep->Fill(P_e_3v.Phi() * TMath::RadToDeg(), P_e_3v.Theta() * TMath::RadToDeg());
            hTheta_e_VS_P_e_ep->Fill(P_e_3v.Mag(), P_e_3v.Theta() * TMath::RadToDeg());
            hPhi_e_VS_P_e_ep->Fill(P_e_3v.Mag(), P_e_3v.Phi() * TMath::RadToDeg());

            hTheta_p_ep->Fill(P_N_3v.Theta() * TMath::RadToDeg());
            hPhi_p_ep->Fill(P_N_3v.Phi() * TMath::RadToDeg());
            hP_p_ep->Fill(P_N_3v.Mag());

            hTheta_p_VS_Phi_p_ep->Fill(P_N_3v.Phi() * TMath::RadToDeg(), P_N_3v.Theta() * TMath::RadToDeg());
            hTheta_p_VS_P_p_ep->Fill(P_N_3v.Mag(), P_N_3v.Theta() * TMath::RadToDeg());
            hPhi_p_VS_P_p_ep->Fill(P_N_3v.Mag(), P_N_3v.Phi() * TMath::RadToDeg());

            hP_e_VS_P_p_ep->Fill(P_N_3v.Mag(), P_e_3v.Mag());
        }
        else if (N_pid == 2112)
        {
            hTheta_e_en->Fill(P_e_3v.Theta() * TMath::RadToDeg());
            hPhi_e_en->Fill(P_e_3v.Phi() * TMath::RadToDeg());
            hP_e_en->Fill(P_e_3v.Mag());

            hTheta_e_VS_Phi_e_en->Fill(P_e_3v.Phi() * TMath::RadToDeg(), P_e_3v.Theta() * TMath::RadToDeg());
            hTheta_e_VS_P_e_en->Fill(P_e_3v.Mag(), P_e_3v.Theta() * TMath::RadToDeg());
            hPhi_e_VS_P_e_en->Fill(P_e_3v.Mag(), P_e_3v.Phi() * TMath::RadToDeg());

            hTheta_n_en->Fill(P_N_3v.Theta() * TMath::RadToDeg());
            hPhi_n_en->Fill(P_N_3v.Phi() * TMath::RadToDeg());
            hP_n_en->Fill(P_N_3v.Mag());

            hTheta_n_VS_Phi_n_en->Fill(P_N_3v.Phi() * TMath::RadToDeg(), P_N_3v.Theta() * TMath::RadToDeg());
            hTheta_n_VS_P_n_en->Fill(P_N_3v.Mag(), P_N_3v.Theta() * TMath::RadToDeg());
            hPhi_n_VS_P_n_en->Fill(P_N_3v.Mag(), P_N_3v.Phi() * TMath::RadToDeg());

            hP_e_VS_P_n_en->Fill(P_N_3v.Mag(), P_e_3v.Mag());
        }

        ++i;
    }
}
