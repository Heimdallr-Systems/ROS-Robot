//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isnan.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "isnan.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double x
// Return Type  : bool
//
namespace Codegen
{
  namespace coder
  {
    bool b_isnan(double x)
    {
      return rtIsNaN(x);
    }
  }
}

//
// File trailer for isnan.cpp
//
// [EOF]
//
