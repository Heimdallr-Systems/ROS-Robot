//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 14-Apr-2021 15:32:06
//

#ifndef XSWAP_H
#define XSWAP_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void b_xswap(double x[9], int ix0, int iy0);

void c_xswap(double x[324], int ix0, int iy0);

void d_xswap(double x[36], int ix0, int iy0);

void xswap(double x[9], int ix0, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xswap.h
//
// [EOF]
//
