//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "svd1.h"
#include "xzsvdc.h"
#include <algorithm>

// Function Definitions
//
// Arguments    : const double A[108]
//                double U[36]
//                double s[6]
//                double V[324]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
void b_svd(const double A[108], double U[36], double s[6], double V[324])
{
  double b_A[108];
  (void)std::copy(&A[0], &A[108], &b_A[0]);
  reflapack::xzsvdc(b_A, U, s, V);
}

} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for svd1.cpp
//
// [EOF]
//
