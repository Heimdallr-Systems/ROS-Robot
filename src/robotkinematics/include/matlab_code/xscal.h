//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xscal.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//
#ifndef XSCAL_H
#define XSCAL_H

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
        void b_xscal(int n, double a, double x[18], int ix0);
        void b_xscal(double a, double x[324], int ix0);
        void xscal(int n, double a, double x[108], int ix0);
        void xscal(double a, double x[36], int ix0);
      }
    }
  }
}

#endif

//
// File trailer for xscal.h
//
// [EOF]
//
