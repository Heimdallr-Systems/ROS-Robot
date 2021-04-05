//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "mldivide.h"
#include "lusolve.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    static void mldiv(const double A[9], const double B[3], double Y[3]);
  }
}

// Function Definitions
//
// Arguments    : const double A[9]
//                const double B[3]
//                double Y[3]
// Return Type  : void
//
namespace Codegen
{
  namespace coder
  {
    static void mldiv(const double A[9], const double B[3], double Y[3])
    {
      internal::lusolve(A, B, Y);
    }

    //
    // Arguments    : const double A[9]
    //                const double B[3]
    //                double Y[3]
    // Return Type  : void
    //
    void mldivide(const double A[9], const double B[3], double Y[3])
    {
      mldiv(A, B, Y);
    }
  }
}

//
// File trailer for mldivide.cpp
//
// [EOF]
//
