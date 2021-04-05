/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Robot_Control_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 17-Mar-2021 14:19:13
 */

#ifndef _CODER_ROBOT_CONTROL_API_H
#define _CODER_ROBOT_CONTROL_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void Robot_Control(real_T r_II_B_d[3], real_T Euler_d[3], real_T gamma_m[36],
                     boolean_T init_toggle, real_T Theta1_d_out[4], real_T
                     Theta2_d_out[4], real_T Theta3_d_out[4], real_T
                     *phi_d_temp_out, real_T r_II_B_d_temp_out[3], uint8_T
                     floor_toggle_out[4], uint8_T legs_valid_out[4]);
  void Robot_Control_api(const mxArray * const prhs[4], int32_T nlhs, const
    mxArray *plhs[7]);
  void Robot_Control_atexit(void);
  void Robot_Control_initialize(void);
  void Robot_Control_terminate(void);
  void Robot_Control_xil_shutdown(void);
  void Robot_Control_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_Robot_Control_api.h
 *
 * [EOF]
 */
