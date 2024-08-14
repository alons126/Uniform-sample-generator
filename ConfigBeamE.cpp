//
// Created by alons on 14/08/2024.
//

#include <iomanip>
#include <string>

#include "TString.h"

using namespace std;

string ConfigBeamE(const double &BeamE) {
    string be;

    if (BeamE == 5.98636) {
        be = "598636MeV";
    } else if (BeamE == 4.02962) {
        be = "402962MeV";
    } else if (BeamE == 2.07052) {
        be = "207052MeV";
    }

    return be;
}

TString ConfigBeamE(const double &BeamE, TString OutputFileNamePrefix) {
    TString opfnPrefix, be;

    if (BeamE == 5.98636) {
        be = "_598636MeV";
    } else if (BeamE == 4.02962) {
        be = "_402962MeV";
    } else if (BeamE == 2.07052) {
        be = "_207052MeV";
    }

    opfnPrefix = OutputFileNamePrefix + be;
    return opfnPrefix;
}
