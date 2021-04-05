//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: angle1.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "angle1.h"
#include "atan21.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const creal_T x
// Return Type  : double
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        double b_angle(const creal_T x)
        {
          return c_atan2(x.im, x.re);
        }
      }
    }
  }
}

//
// File trailer for angle1.cpp
//
// [EOF]
//
