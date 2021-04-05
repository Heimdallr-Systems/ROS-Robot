//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: exp1.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "exp1.h"
#include "isinf.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : creal_T *x
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
        void c_exp(creal_T *x)
        {
          if (x->im == 0.0) {
            x->re = std::exp(x->re);
            x->im = 0.0;
          } else {
            bool guard1 = false;
            guard1 = false;
            if (b_isinf(x->im)) {
              if (b_isinf(x->re)) {
                if (x->re < 0.0) {
                  x->re = 0.0;
                  x->im = 0.0;
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              double d;
              double r;
              r = std::exp(x->re / 2.0);
              d = x->im;
              x->re = r * (r * std::cos(x->im));
              x->im = r * (r * std::sin(d));
            }
          }
        }
      }
    }
  }
}

//
// File trailer for exp1.cpp
//
// [EOF]
//
