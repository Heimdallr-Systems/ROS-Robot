//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: skew.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "skew.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double w[3]
//                double S[9]
// Return Type  : void
//
namespace Codegen
{
  void skew(const double w[3], double S[9])
  {
    S[0] = 0.0;
    S[3] = -w[2];
    S[6] = w[1];
    S[1] = w[2];
    S[4] = 0.0;
    S[7] = -w[0];
    S[2] = -w[1];
    S[5] = w[0];
    S[8] = 0.0;
  }
}

//
// File trailer for skew.cpp
//
// [EOF]
//
