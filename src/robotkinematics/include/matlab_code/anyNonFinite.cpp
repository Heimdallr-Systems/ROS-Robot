//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: anyNonFinite.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"

// Function Definitions
//
// Arguments    : const double x[108]
// Return Type  : bool
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      bool anyNonFinite(const double x[108])
      {
        return !vAllOrAny(x);
      }
    }
  }
}

//
// File trailer for anyNonFinite.cpp
//
// [EOF]
//
