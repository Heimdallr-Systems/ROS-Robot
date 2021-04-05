//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: all.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "all.h"
#include "allOrAny.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const unsigned char x[4]
// Return Type  : bool
//
namespace Codegen
{
  namespace coder
  {
    bool all(const unsigned char x[4])
    {
      return internal::vectorAll(x);
    }
  }
}

//
// File trailer for all.cpp
//
// [EOF]
//
