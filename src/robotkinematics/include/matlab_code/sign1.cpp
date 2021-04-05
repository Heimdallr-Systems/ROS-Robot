//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sign1.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "sign1.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        static void realScalarSign(double *x);
      }
    }
  }
}

// Function Definitions
//
// Arguments    : double *x
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        static void realScalarSign(double *x)
        {
          double u;
          double y;
          u = *x;
          if (u < 0.0) {
            y = -1.0;
          } else if (u > 0.0) {
            y = 1.0;
          } else if (u == 0.0) {
            y = 0.0;
          } else {
            y = rtNaN;
          }

          *x = y;
        }

        //
        // Arguments    : double *x
        // Return Type  : void
        //
        void c_sign(double *x)
        {
          realScalarSign(x);
        }
      }
    }
  }
}

//
// File trailer for sign1.cpp
//
// [EOF]
//
