//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "xswap.h"

// Function Definitions
//
// Arguments    : double x[36]
//                int ix0
//                int iy0
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void b_xswap(double x[36], int ix0, int iy0)
{
  for (int k = 0; k < 6; k++) {
    double temp;
    int i;
    int temp_tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    i = (iy0 + k) - 1;
    x[temp_tmp] = x[i];
    x[i] = temp;
  }
}

//
// Arguments    : double x[324]
//                int ix0
//                int iy0
// Return Type  : void
//
void xswap(double x[324], int ix0, int iy0)
{
  for (int k = 0; k < 18; k++) {
    double temp;
    int i;
    int temp_tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    i = (iy0 + k) - 1;
    x[temp_tmp] = x[i];
    x[i] = temp;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xswap.cpp
//
// [EOF]
//
