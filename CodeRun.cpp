#include "Uniform_sample_generator.C"
#include "Uniform_sample_generator_e_tester.C"

#define independent_tester false

void CodeRun() {
    // Uniform_sample_generator_e_tester(2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV/OutPut_Tester_e/");
    // Uniform_sample_generator_e_tester(4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV/OutPut_Tester_e/");
    // Uniform_sample_generator_e_tester(5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV/OutPut_Tester_e/");

    // Uniform_sample_generator(true, false, false, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV/OutPut/");
    // Uniform_sample_generator(true, false, false, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV_devGEMC_rgm_fall2021_C_S/OutPut/");
    Uniform_sample_generator(true, false, false, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV_devGEMC_rgm_fall2021_Ar/OutPut/");
    // Uniform_sample_generator(false, true, false, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV_ConstPn/OutPut/");
    // Uniform_sample_generator(false, false, true, 2.07052, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/2070MeV_target_zpos_test/OutPut/");

    // Uniform_sample_generator(true, false, false, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV/OutPut/");
    // Uniform_sample_generator(true, false, false, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV_devGEMC_rgm_fall2021_C_S/OutPut/");
    // Uniform_sample_generator(true, false, false, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV_devGEMC_rgm_fall2021_Ar/OutPut/");
    // Uniform_sample_generator(false, true, false, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV_ConstPn/OutPut/");
    // Uniform_sample_generator(false, false, true, 4.02962, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/4029MeV_target_zpos_test/OutPut/");

    // Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV/OutPut/");
    // Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV_devGEMC_rgm_fall2021_C_S/OutPut/");
    // Uniform_sample_generator(true, false, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV_devGEMC_rgm_fall2021_Ar/OutPut/");
    // Uniform_sample_generator(false, true, false, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV/OutPut/");
    // Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV_ConstPn/OutPut/");
    // Uniform_sample_generator(false, false, true, 5.98636, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/5986MeV_target_zpos_test/OutPut/");

    // Uniform_sample_generator(false, false, true, 10.6, "/lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco_Samples/Uniform_e-p-n_samples/10600MeV_test/OutPut/");
}
