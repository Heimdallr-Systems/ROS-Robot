//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "svd.h"
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
namespace Codegen {
namespace coder {
void svd(const double A[108], double U[36], double S[108], double V[324])
{
  double s[6];
  internal::b_svd(A, U, s, V);
  (void)std::memset(&S[0], 0, 108U * (sizeof(double)));
  for (int k = 0; k < 6; k++) {
    S[k + (6 * k)] = s[k];
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for svd.cpp
//
// [EOF]
//
