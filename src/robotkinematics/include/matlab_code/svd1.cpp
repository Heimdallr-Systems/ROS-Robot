//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "svd1.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const double A[108]
//                double U[36]
//                double s[6]
//                double V[324]
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      void b_svd(const double A[108], double U[36], double s[6], double V[324])
      {
        double b_A[108];
        std::memcpy(&b_A[0], &A[0], 108U * (sizeof(double)));
        reflapack::xzsvdc(b_A, U, s, V);
      }
    }
  }
}

//
// File trailer for svd1.cpp
//
// [EOF]
//
