#include "Generate_uniform_event.C"

void Uniform_sample_generator(TString outputFile = "test.lund", int nEvents = 10000, double BeamE = -99,
                              double theta_min = 35, double theta_max = 135) {
    TRandom3 ran(0);
    const int nParticles = 2;
    double mass_e = 0.511e-3;
    double mass_p = 0.938272;
    double mass_n = 0.93957;

    system("mkdir -p lundfiles");

    //Not useful usually
    double targP = 0.; // polarization
    double beamP = 0.; // polarization
    int interactN = 1;
    int beamType = 11;

    double beamE = -99; // GeV

    double weight = 1;

    ofstream outfile;
    TString outputFolder = "./lundfiles/";
    outputFile = outputFolder + outputFile;

    cout << "outputFile = " << outputFile << "\n";

    outfile.open(outputFile);
    if (!outfile.is_open()) { cout << "Output file cannot be created" << endl; }

    TString formatstring, outstring;

    Generate_uniform_event(outfile, formatstring, outstring, ran, 2212, nEvents, nParticles, targP, beamP, interactN,
                           beamType = 11, beamE, BeamE, weight, mass_e, mass_p, 5., 40., 5., 45.);
    Generate_uniform_event(outfile, formatstring, outstring, ran, 2112, nEvents, nParticles, targP, beamP, interactN,
                           beamType = 11, beamE, BeamE, weight, mass_e, mass_n, 5., 40., 5., 35.);

    outfile.close();
}
