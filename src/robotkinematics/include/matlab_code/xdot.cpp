//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdot.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "xdot.h"
#include "rt_nonfinite.h"

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
        double b_xdot(int n, const double x[36], int ix0, const double y[36],
                      int iy0)
        {
          double d;
          d = 0.0;
          if (n >= 1) {
            int ix;
            int iy;
            ix = ix0;
            iy = iy0;
            for (int k = 0; k < n; k++) {
              d += x[ix - 1] * y[iy - 1];
              ix++;
              iy++;
            }
          }

          return d;
        }

        //
        // Arguments    : int n
        //                const double x[324]
        //                int ix0
        //                const double y[324]
        //                int iy0
        // Return Type  : double
        //
        double c_xdot(int n, const double x[324], int ix0, const double y[324],
                      int iy0)
        {
          double d;
          d = 0.0;
          if (n >= 1) {
            int ix;
            int iy;
            ix = ix0;
            iy = iy0;
            for (int k = 0; k < n; k++) {
              d += x[ix - 1] * y[iy - 1];
              ix++;
              iy++;
            }
          }

          return d;
        }

        //
        // Arguments    : int n
        //                const double x[108]
        //                int ix0
        //                const double y[108]
        //                int iy0
        // Return Type  : double
        //
        double xdot(int n, const double x[108], int ix0, const double y[108],
                    int iy0)
        {
          double d;
          d = 0.0;
          if (n >= 1) {
            int ix;
            int iy;
            ix = ix0;
            iy = iy0;
            for (int k = 0; k < n; k++) {
              d += x[ix - 1] * y[iy - 1];
              ix++;
              iy++;
            }
          }

          return d;
        }
      }
    }
  }
}

//
// File trailer for xdot.cpp
//
// [EOF]
//
