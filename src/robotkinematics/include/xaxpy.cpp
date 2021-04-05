//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "xaxpy.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int n
//                double a
//                const double x[6]
//                int ix0
//                double y[108]
//                int iy0
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        void b_xaxpy(int n, double a, const double x[6], int ix0, double y[108],
                     int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            int ix;
            int iy;
            ix = ix0 - 1;
            iy = iy0 - 1;
            i = n - 1;
            for (int k = 0; k <= i; k++) {
              y[iy] += a * x[ix];
              ix++;
              iy++;
            }
          }
        }

        //
        // Arguments    : int n
        //                double a
        //                int ix0
        //                double y[36]
        //                int iy0
        // Return Type  : void
        //
        void b_xaxpy(int n, double a, int ix0, double y[36], int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            int ix;
            int iy;
            ix = ix0 - 1;
            iy = iy0 - 1;
            i = n - 1;
            for (int k = 0; k <= i; k++) {
              y[iy] += a * y[ix];
              ix++;
              iy++;
            }
          }
        }

        //
        // Arguments    : int n
        //                double a
        //                int ix0
        //                double y[324]
        //                int iy0
        // Return Type  : void
        //
        void c_xaxpy(int n, double a, int ix0, double y[324], int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            int ix;
            int iy;
            ix = ix0 - 1;
            iy = iy0 - 1;
            i = n - 1;
            for (int k = 0; k <= i; k++) {
              y[iy] += a * y[ix];
              ix++;
              iy++;
            }
          }
        }

        //
        // Arguments    : int n
        //                double a
        //                int ix0
        //                double y[108]
        //                int iy0
        // Return Type  : void
        //
        void xaxpy(int n, double a, int ix0, double y[108], int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            int ix;
            int iy;
            ix = ix0 - 1;
            iy = iy0 - 1;
            i = n - 1;
            for (int k = 0; k <= i; k++) {
              y[iy] += a * y[ix];
              ix++;
              iy++;
            }
          }
        }

        //
        // Arguments    : int n
        //                double a
        //                const double x[108]
        //                int ix0
        //                double y[6]
        //                int iy0
        // Return Type  : void
        //
        void xaxpy(int n, double a, const double x[108], int ix0, double y[6],
                   int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            int ix;
            int iy;
            ix = ix0 - 1;
            iy = iy0 - 1;
            i = n - 1;
            for (int k = 0; k <= i; k++) {
              y[iy] += a * x[ix];
              ix++;
              iy++;
            }
          }
        }
      }
    }
  }
}

//
// File trailer for xaxpy.cpp
//
// [EOF]
//
