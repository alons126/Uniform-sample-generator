//
// Created by alons on 08/08/2024.
//

#ifndef HISTOGRAMS_H
#define HISTOGRAMS_H

#include <vector>

#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TLatex.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TStyle.h>

/* 1e events */
vector<TH1 *> TH1_hist_list_1e;
vector<TH2 *> TH2_hist_list_1e;

TH1D *hTheta_e_1e, *hPhi_e_1e, *hP_e_1e;
TH2D *hTheta_e_VS_Phi_e_1e, *hTheta_e_VS_P_e_1e, *hPhi_e_VS_P_e_1e;

/* ep events */
vector<TH1 *> TH1_hist_list_ep;
vector<TH2 *> TH2_hist_list_ep;

TH1D *hTheta_e_ep, *hPhi_e_ep, *hP_e_ep;
TH2D *hTheta_e_VS_Phi_e_ep, *hTheta_e_VS_P_e_ep, *hPhi_e_VS_P_e_ep;

TH1D *hTheta_p_ep, *hPhi_p_ep, *hP_p_ep;
TH2D *hTheta_p_VS_Phi_p_ep, *hTheta_p_VS_P_p_ep, *hPhi_p_VS_P_p_ep;
TH2D *hP_e_VS_P_p_ep, *hP_e_VS_Theta_p_ep, *hP_e_VS_Phi_p_ep;
TH2D *hTheta_e_VS_P_p_ep, *hTheta_e_VS_Theta_p_ep, *hTheta_e_VS_Phi_p_ep;
TH2D *hPhi_e_VS_P_p_ep, *hPhi_e_VS_Theta_p_ep, *hPhi_e_VS_Phi_p_ep;

/* en events */
vector<TH1 *> TH1_hist_list_en;
vector<TH2 *> TH2_hist_list_en;

TH1D *hTheta_e_en, *hPhi_e_en, *hP_e_en;
TH2D *hTheta_e_VS_Phi_e_en, *hTheta_e_VS_P_e_en, *hPhi_e_VS_P_e_en;

TH1D *hTheta_n_en, *hPhi_n_en, *hP_n_en;
TH2D *hTheta_n_VS_Phi_n_en, *hTheta_n_VS_P_n_en, *hPhi_n_VS_P_n_en;
TH2D *hP_e_VS_P_n_en, *hP_e_VS_Theta_n_en, *hP_e_VS_Phi_n_en;
TH2D *hTheta_e_VS_P_n_en, *hTheta_e_VS_Theta_n_en, *hTheta_e_VS_Phi_n_en;
TH2D *hPhi_e_VS_P_n_en, *hPhi_e_VS_Theta_n_en, *hPhi_e_VS_Phi_n_en;

#endif // HISTOGRAMS_H
