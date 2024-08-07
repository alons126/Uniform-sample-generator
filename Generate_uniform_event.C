#include "addParticle.C"

void Generate_uniform_event(ofstream &outfile, TString formatstring, TString outstring, TRandom3 &ran, int N_pid,
                             int nEvents = 10000, const int nParticles = 2, double targP = 0., double beamP = 0.,
                             int interactN = 1, int beamType = 11, double beamE = -99, double BeamE = -99,
                             double weight = 1, double mass_e = 0.511e-3, double mass_N = 0.938272,
                             double theta_e_min = 5., double theta_e_max = 40.,
                             double theta_N_min = 5., double theta_N_max = 45.) {
    for (int i = 0; i < nEvents / 2; i++) {
        // Half of events are uniform (e,e'p) and the other are uniform (e,e'n)
        // LUND header for the event:
        formatstring = "%i \t %i \t %i \t %.3f \t %.3f \t %i \t %.1f \t %i \t %i \t %.3f \n";
        outstring = Form(formatstring, nParticles, 1 /* A */, 1 /* Z */,
                         targP, beamP, beamType, beamE, interactN, i, weight);
        outfile << outstring;

        //Add particles in event below
        TVector3 vtx(0, 0, -3);

        //Electron
        double P_e = ran.Uniform(0, BeamE); // Uniiform P_e from 0 to P_e = beamE
        double Phi_e = ran.Uniform(-180., 180.) * TMath::RadToDeg(); // Uniiform Phi_e from -180 to +180
        double Theta_e = ran.Uniform(theta_e_min, theta_e_max) * TMath::RadToDeg();
        // Uniiform Theta_e from theta_e_min to theta_e_max
        TVector3 P_e_3v(P_e * sin(Theta_e) * cos(Phi_e), P_e * sin(Theta_e) * sin(Phi_e), P_e * cos(Theta_e));
        outfile << addParticle(1, 11, P_e_3v, mass_e, vtx);

        //Nucleon
        TVector3 P_N_3v(-P_e_3v.Px(), -P_e_3v.Py(), BeamE - P_e_3v.Pz());
        outfile << addParticle(2, N_pid, P_N_3v, mass_N, vtx);

        /*mom = ran.Uniform(.2, 1);
        phi = ran.Uniform(-TMath::Pi(), TMath::Pi());
        theta = acos(2 * ran.Uniform() - 1); //isotropic

        while (!(theta * TMath::RadToDeg() > theta_N_min && theta * TMath::RadToDeg() < theta_N_max)) {
            theta = acos(2 * ran.Uniform() - 1);
        }

        px = mom * sin(theta) * cos(phi);
        py = mom * sin(theta) * sin(phi);
        pz = mom * cos(theta);
        outfile << addParticle(2, 2212, TVector3(px, py, pz), mass_N, vtx);*/
    }
}