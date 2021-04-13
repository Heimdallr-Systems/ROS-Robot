//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "isequal.h"

// Function Definitions
//
// Arguments    : const double varargin_1[3]
//                const double varargin_2[3]
// Return Type  : bool
//
namespace Codegen {
namespace coder {
bool isequal(const double varargin_1[3], const double varargin_2[3])
{
  int k;
  bool b_p;
  bool exitg1;
  bool p;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (varargin_1[k] != varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return b_p || p;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for isequal.cpp
//
// [EOF]
//
