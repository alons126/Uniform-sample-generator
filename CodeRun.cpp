#include "Uniform_sample_generator.C"
#include "Uniform_sample_generator_e_tester.C"

#define independent_tester false

void CodeRun()
{
    // Uniform_sample_generator_e_tester(true, false, false);
    // Uniform_sample_generator(true, false, false, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut/");
    // Uniform_sample_generator(false, true, false, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut/");

    // Uniform_sample_generator(true, false, false, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut/");
    // Uniform_sample_generator(false, true, false, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut/");
    
    Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-TorusSymmetric-test/OutPut/");
    Uniform_sample_generator(false, true, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-TorusSymmetric-test/OutPut/");
    Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-TorusSymmetric-test/OutPut/");
    // Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-torus_plus1-test/OutPut/");
    // Uniform_sample_generator(false, true, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-torus_plus1-test/OutPut/");
    // Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-torus_plus1-test/OutPut/");
    // Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-vtx-test-1/OutPut/");
    // Uniform_sample_generator(false, true, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-vtx-test-1/OutPut/");
    // Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV-vtx-test-1/OutPut/");
    // Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut/");
    // Uniform_sample_generator(false, true, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut/");
}
