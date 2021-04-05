//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "svd.h"
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const double A[108]
//                double U[36]
//                double S[108]
//                double V[324]
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    void svd(const double A[108], double U[36], double S[108], double V[324])
    {
      double s[6];
      if (!internal::anyNonFinite(A)) {
        internal::b_svd(A, U, s, V);
      } else {
        for (int i = 0; i < 36; i++) {
          U[i] = rtNaN;
        }

        for (int b_i = 0; b_i < 6; b_i++) {
          s[b_i] = rtNaN;
        }

        for (int i1 = 0; i1 < 324; i1++) {
          V[i1] = rtNaN;
        }
      }

      std::memset(&S[0], 0, 108U * (sizeof(double)));
      for (int k = 0; k < 6; k++) {
        S[k + (6 * k)] = s[k];
      }
    }
  }
}

//
// File trailer for svd.cpp
//
// [EOF]
//
