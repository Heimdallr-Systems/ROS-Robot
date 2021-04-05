//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: combineVectorElements.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double x[5]
// Return Type  : double
//
namespace Codegen
{
  namespace coder
  {
    double b_combineVectorElements(const double x[5])
    {
      return (((x[0] + x[1]) + x[2]) + x[3]) + x[4];
    }

    //
    // Arguments    : const double x[6]
    // Return Type  : double
    //
    double combineVectorElements(const double x[6])
    {
      double y;
      y = x[0];
      for (int k = 0; k < 5; k++) {
        y *= x[k + 1];
      }

      return y;
    }
  }
}

//
// File trailer for combineVectorElements.cpp
//
// [EOF]
//
