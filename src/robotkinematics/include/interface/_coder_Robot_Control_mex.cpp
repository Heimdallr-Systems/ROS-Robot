//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_Robot_Control_mex.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "_coder_Robot_Control_mex.h"
#include "_coder_Robot_Control_api.h"

// Function Definitions
//
// Arguments    : int32_T nlhs
//                mxArray *plhs[7]
//                int32_T nrhs
//                const mxArray *prhs[5]
// Return Type  : void
//
void Robot_Control_mexFunction(int32_T nlhs, mxArray *plhs[7], int32_T nrhs,
                               const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, // site
      NULL, // tls
      NULL  // prev
  };
  const mxArray *outputs[7];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        13, "Robot_Control");
  }
  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "Robot_Control");
  }
  // Call the function.
  Robot_Control_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[2]
//                int32_T nrhs
//                const mxArray *prhs[2]
// Return Type  : void
//
void getUp_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                       const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, // site
      NULL, // tls
      NULL  // prev
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        5, "getUp");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "getUp");
  }
  // Call the function.
  getUp_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[]
//                int32_T nrhs
//                const mxArray *prhs[]
// Return Type  : void
//
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[2] = {"getUp", "Robot_Control"};
  emlrtStack st = {
      NULL, // site
      NULL, // tls
      NULL  // prev
  };
  mexAtExit(&Robot_Control_atexit);
  // Module initialization.
  Robot_Control_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    switch (emlrtGetEntryPointIndexR2016a(
        &st, nrhs, &prhs[0], (const char_T **)(&emlrtEntryPoints[0]), 2)) {
    case 0:
      getUp_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    case 1:
      Robot_Control_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    default:
      /* no actions */
      break;
    }
    // Module termination.
    Robot_Control_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

//
// File trailer for _coder_Robot_Control_mex.cpp
//
// [EOF]
//
