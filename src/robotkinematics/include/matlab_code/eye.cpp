//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eye.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "eye.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
//
// Arguments    : double b_I[9]
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    void eye(double b_I[9])
    {
      std::memset(&b_I[0], 0, 9U * (sizeof(double)));
      b_I[0] = 1.0;
      b_I[4] = 1.0;
      b_I[8] = 1.0;
    }
  }
}

//
// File trailer for eye.cpp
//
// [EOF]
//
