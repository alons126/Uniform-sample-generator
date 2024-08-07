#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"

#include <fstream>
#include <iostream>

using namespace std;

TString addParticle(int part_idx, int pid, TVector3 momentum, double mass, TVector3 vtx) {
    // LUND info for each particle in the event
    TString formatstring =
            "%i \t %.3f \t %i \t %i \t %i \t %i \t %.5f \t %.5f \t %.5f \t %.5f \t %.5f \t %.5f \t %.5f \t %.5f \n";
    double energy = sqrt(momentum.Mag2() + mass * mass);
    TString outstring = Form(formatstring, part_idx, 0.0, 1, pid, 0, 0, momentum.Px(), momentum.Py(), momentum.Pz(),
                             energy, mass, vtx.X(), vtx.Y(), vtx.Z());

    return outstring;
}
