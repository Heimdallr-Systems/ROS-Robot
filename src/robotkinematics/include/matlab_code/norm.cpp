//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: norm.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "norm.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    static double genpnorm(const double x[3]);
  }
}

// Function Definitions
//
// Arguments    : const double x[3]
// Return Type  : double
//
namespace Codegen
{
  namespace coder
  {
    static double genpnorm(const double x[3])
    {
      return internal::blas::xnrm2(x);
    }

    //
    // Arguments    : const double x[3]
    // Return Type  : double
    //
    double b_norm(const double x[3])
    {
      return genpnorm(x);
    }
  }
}

//
// File trailer for norm.cpp
//
// [EOF]
//
