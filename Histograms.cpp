//
// Created by alons on 08/08/2024.
//

#include "Histograms.h"

void InitHistograms(const double &Ebeam) {
    /* ep events */
    hTheta_e_ep = new TH1D("Theta_e_ep", "#theta_{e} in e-p;#theta_{e} [#circ]", 200, 0, 50);
    TH1_hist_list_ep.push_back(hTheta_e_ep);

    hPhi_e_ep = new TH1D("Phi_e_ep", "#phi_{e} in e-p;#phi_{e} [#circ]", 200, -180, 180);
    TH1_hist_list_ep.push_back(hPhi_e_ep);

    hP_e_ep = new TH1D("P_e_ep", "P_{e} in e-p;P_{e} [GeV]", 200, 0, Ebeam * 1.1);
    TH1_hist_list_ep.push_back(hP_e_ep);

    hTheta_e_VS_Phi_e_ep = new TH2D("Theta_e_VS_Phi_e_ep", "#theta_{e} vs. #phi_{e} in e-p;#phi_{e} [#circ];#theta_{e} [#circ]", 200, -180, 180, 200, 0, 50);
    TH2_hist_list_ep.push_back(hTheta_e_VS_Phi_e_ep);

    hTheta_e_VS_P_e_ep = new TH2D("Theta_e_VS_P_e_ep", "#theta_{e} vs. P_{e} in e-p;P_{e} [GeV];#theta_{e} [#circ]", 200, 0, Ebeam * 1.1, 200, 0, 50);
    TH2_hist_list_ep.push_back(hTheta_e_VS_P_e_ep);

    hPhi_e_VS_P_e_ep = new TH2D("Phi_e_VS_P_e_ep", "#phi_{e} vs. P_{e} in e-p;P_{e} [GeV];#phi_{e} [#circ]", 200, 0, Ebeam * 1.1, 200, -180, 180);
    TH2_hist_list_ep.push_back(hPhi_e_VS_P_e_ep);

    hTheta_p_ep = new TH1D("Theta_p_ep", "#theta_{p} in e-p;#theta_{p} [#circ]", 200, 0, 50);
    TH1_hist_list_ep.push_back(hTheta_p_ep);

    hPhi_p_ep = new TH1D("Phi_p_ep", "#phi_{p} in e-p;#phi_{p} [#circ]", 200, -180, 180);
    TH1_hist_list_ep.push_back(hPhi_p_ep);

    hP_p_ep = new TH1D("P_p_ep", "P_{p} in e-p;P_{p} [GeV]", 200, 0, Ebeam * 1.1);
    TH1_hist_list_ep.push_back(hP_p_ep);

    hTheta_p_VS_Phi_p_ep = new TH2D("Theta_p_VS_Phi_p_ep", "#theta_{p} vs. #phi_{p} in e-p;#phi_{p} [#circ];#theta_{p} [#circ]", 200, -180, 180, 200, 0, 50);
    TH2_hist_list_ep.push_back(hTheta_p_VS_Phi_p_ep);

    hTheta_p_VS_P_p_ep = new TH2D("Theta_p_VS_P_p_ep", "#theta_{p} vs. P_{p} in e-p;P_{p} [GeV];#theta_{p} [#circ]", 200, 0, Ebeam * 1.1, 200, 0, 50);
    TH2_hist_list_ep.push_back(hTheta_p_VS_P_p_ep);

    hPhi_p_VS_P_p_ep = new TH2D("Phi_p_VS_P_p_ep", "#phi_{p} vs. P_{p} in e-p;P_{p} [GeV];#phi_{p} [#circ]", 200, 0, Ebeam * 1.1, 200, -180, 180);
    TH2_hist_list_ep.push_back(hPhi_p_VS_P_p_ep);

    /* en events */
    hTheta_e_en = new TH1D("Theta_e_en", "#theta_{e} in e-n;#theta_{e} [#circ]", 200, 0, 50);
    TH1_hist_list_en.push_back(hTheta_e_en);

    hPhi_e_en = new TH1D("Phi_e_en", "#phi_{e} in e-n;#phi_{e} [#circ]", 200, -180, 180);
    TH1_hist_list_en.push_back(hPhi_e_en);

    hP_e_en = new TH1D("P_e_en", "P_{e} in e-n;P_{e} [GeV]", 200, 0, Ebeam * 1.1);
    TH1_hist_list_en.push_back(hP_e_en);

    hTheta_e_VS_Phi_e_en = new TH2D("Theta_e_VS_Phi_e_en", "#theta_{e} vs. #phi_{e} in e-n;#phi_{e} [#circ];#theta_{e} [#circ]", 200, -180, 180, 200, 0, 50);
    TH2_hist_list_en.push_back(hTheta_e_VS_Phi_e_en);

    hTheta_e_VS_P_e_en = new TH2D("Theta_e_VS_P_e_en", "#theta_{e} vs. P_{e} in e-n;P_{e} [GeV];#theta_{e} [#circ]", 200, 0, Ebeam * 1.1, 200, 0, 50);
    TH2_hist_list_en.push_back(hTheta_e_VS_P_e_en);

    hPhi_e_VS_P_e_en = new TH2D("Phi_e_VS_P_e_en", "#phi_{e} vs. P_{e} in e-n;P_{e} [GeV];#phi_{e} [#circ]", 200, 0, Ebeam * 1.1, 200, -180, 180);
    TH2_hist_list_en.push_back(hPhi_e_VS_P_e_en);

    hTheta_n_en = new TH1D("Theta_n_en", "#theta_{n} in e-n;#theta_{n} [#circ]", 200, 0, 50);
    TH1_hist_list_en.push_back(hTheta_n_en);

    hPhi_n_en = new TH1D("Phi_n_en", "#phi_{n} in e-n;#phi_{n} [#circ]", 200, -180, 180);
    TH1_hist_list_en.push_back(hPhi_n_en);

    hP_n_en = new TH1D("P_n_en", "P_{n} in e-n;P_{n} [GeV]", 200, 0, Ebeam * 1.1);
    TH1_hist_list_en.push_back(hP_n_en);

    hTheta_n_VS_Phi_n_en = new TH2D("Theta_n_VS_Phi_n_en", "#theta_{n} vs. #phi_{n} in e-n;#phi_{n} [#circ];#theta_{n} [#circ]", 200, -180, 180, 200, 0, 50);
    TH2_hist_list_en.push_back(hTheta_n_VS_Phi_n_en);

    hTheta_n_VS_P_n_en = new TH2D("Theta_n_VS_P_n_en", "#theta_{n} vs. P_{n} in e-n;P_{n} [GeV];#theta_{n} [#circ]", 200, 0, Ebeam * 1.1, 200, 0, 50);
    TH2_hist_list_en.push_back(hTheta_n_VS_P_n_en);

    hPhi_n_VS_P_n_en = new TH2D("Phi_n_VS_P_n_en", "#phi_{n} vs. P_{n} in e-n;P_{n} [GeV];#phi_{n} [#circ]", 200, 0, Ebeam * 1.1, 200, -180, 180);
    TH2_hist_list_en.push_back(hPhi_n_VS_P_n_en);
}