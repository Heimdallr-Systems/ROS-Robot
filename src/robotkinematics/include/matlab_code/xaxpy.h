//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//
#ifndef XAXPY_H
#define XAXPY_H

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
        void b_xaxpy(int n, double a, const double x[6], int ix0, double y[108],
                     int iy0);
        void b_xaxpy(int n, double a, int ix0, double y[36], int iy0);
        void c_xaxpy(int n, double a, int ix0, double y[324], int iy0);
        void xaxpy(int n, double a, int ix0, double y[108], int iy0);
        void xaxpy(int n, double a, const double x[108], int ix0, double y[6],
                   int iy0);
      }
    }
  }
}

#endif

//
// File trailer for xaxpy.h
//
// [EOF]
//
