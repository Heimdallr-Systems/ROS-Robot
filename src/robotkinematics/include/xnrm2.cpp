//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "xnrm2.h"
#include "abs.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int n
//                const double x[18]
//                int ix0
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
        double b_xnrm2(int n, const double x[18], int ix0)
        {
          double y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = b_abs(x[ix0 - 1]);
            } else {
              double scale;
              int kend;
              scale = 3.3121686421112381E-170;
              kend = (ix0 + n) - 1;
              for (int k = ix0; k <= kend; k++) {
                double absxk;
                absxk = b_abs(x[k - 1]);
                if (absxk > scale) {
                  double t;
                  t = scale / absxk;
                  y = ((y * t) * t) + 1.0;
                  scale = absxk;
                } else {
                  double t;
                  t = absxk / scale;
                  y += t * t;
                }
              }

              y = scale * std::sqrt(y);
            }
          }

          return y;
        }

        //
        // Arguments    : int n
        //                const double x[108]
        //                int ix0
        // Return Type  : double
        //
        double xnrm2(int n, const double x[108], int ix0)
        {
          double y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = b_abs(x[ix0 - 1]);
            } else {
              double scale;
              int kend;
              scale = 3.3121686421112381E-170;
              kend = (ix0 + n) - 1;
              for (int k = ix0; k <= kend; k++) {
                double absxk;
                absxk = b_abs(x[k - 1]);
                if (absxk > scale) {
                  double t;
                  t = scale / absxk;
                  y = ((y * t) * t) + 1.0;
                  scale = absxk;
                } else {
                  double t;
                  t = absxk / scale;
                  y += t * t;
                }
              }

              y = scale * std::sqrt(y);
            }
          }

          return y;
        }

        //
        // Arguments    : const double x[3]
        // Return Type  : double
        //
        double xnrm2(const double x[3])
        {
          double absxk;
          double scale;
          double t;
          double y;
          scale = 3.3121686421112381E-170;
          absxk = b_abs(x[0]);
          if (absxk > 3.3121686421112381E-170) {
            y = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            y = t * t;
          }

          absxk = b_abs(x[1]);
          if (absxk > scale) {
            t = scale / absxk;
            y = ((y * t) * t) + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }

          absxk = b_abs(x[2]);
          if (absxk > scale) {
            t = scale / absxk;
            y = ((y * t) * t) + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }

          return scale * std::sqrt(y);
        }
      }
    }
  }
}

//
// File trailer for xnrm2.cpp
//
// [EOF]
//
