//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cross.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "cross.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double a[3]
//                const double b[3]
//                double c[3]
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    void cross(const double a[3], const double b[3], double c[3])
    {
      c[0] = (a[1] * b[2]) - (a[2] * b[1]);
      c[1] = (a[2] * b[0]) - (a[0] * b[2]);
      c[2] = (a[0] * b[1]) - (a[1] * b[0]);
    }
  }
}

//
// File trailer for cross.cpp
//
// [EOF]
//
