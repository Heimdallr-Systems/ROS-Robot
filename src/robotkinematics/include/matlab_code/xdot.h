//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdot.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//
#ifndef XDOT_H
#define XDOT_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        double b_xdot(int n, const double x[36], int ix0, const double y[36],
                      int iy0);
        double c_xdot(int n, const double x[324], int ix0, const double y[324],
                      int iy0);
        double xdot(int n, const double x[108], int ix0, const double y[108],
                    int iy0);
      }
    }
  }
}

#endif

//
// File trailer for xdot.h
//
// [EOF]
//
