//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"
#include "xdot.h"

// Function Definitions
//
// Arguments    : int n
//                const double x[36]
//                int ix0
//                const double y[36]
//                int iy0
// Return Type  : double
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        double b_xdotc(int n, const double x[36], int ix0, const double y[36],
                       int iy0)
        {
          return b_xdot(n, x, ix0, y, iy0);
        }

        //
        // Arguments    : int n
        //                const double x[324]
        //                int ix0
        //                const double y[324]
        //                int iy0
        // Return Type  : double
        //
        double c_xdotc(int n, const double x[324], int ix0, const double y[324],
                       int iy0)
        {
          return c_xdot(n, x, ix0, y, iy0);
        }

        //
        // Arguments    : int n
        //                const double x[108]
        //                int ix0
        //                const double y[108]
        //                int iy0
        // Return Type  : double
        //
        double xdotc(int n, const double x[108], int ix0, const double y[108],
                     int iy0)
        {
          return xdot(n, x, ix0, y, iy0);
        }
      }
    }
  }
}

//
// File trailer for xdotc.cpp
//
// [EOF]
//
