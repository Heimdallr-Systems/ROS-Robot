//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: atan21.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "atan21.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
namespace Codegen
{
  static double rt_atan2d_snf(double u0, double u1);
}

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
namespace Codegen
{
  static double rt_atan2d_snf(double u0, double u1)
  {
    double y;
    if ((rtIsNaN(u0)) || (rtIsNaN(u1))) {
      y = rtNaN;
    } else if ((rtIsInf(u0)) && (rtIsInf(u1))) {
      int b_u0;
      int b_u1;
      if (u0 > 0.0) {
        b_u0 = 1;
      } else {
        b_u0 = -1;
      }

      if (u1 > 0.0) {
        b_u1 = 1;
      } else {
        b_u1 = -1;
      }

      y = std::atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
    } else if (u1 == 0.0) {
      if (u0 > 0.0) {
        y = RT_PI / 2.0;
      } else if (u0 < 0.0) {
        y = -(RT_PI / 2.0);
      } else {
        y = 0.0;
      }
    } else {
      y = std::atan2(u0, u1);
    }

    return y;
  }

  //
  // Arguments    : double y
  //                double x
  // Return Type  : double
  //
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        double c_atan2(double y, double x)
        {
          return rt_atan2d_snf(y, x);
        }
      }
    }
  }
}

//
// File trailer for atan21.cpp
//
// [EOF]
//
