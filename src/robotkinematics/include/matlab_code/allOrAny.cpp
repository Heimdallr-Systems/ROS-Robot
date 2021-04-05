//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: allOrAny.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "allOrAny.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const unsigned char x[4]
// Return Type  : bool
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      bool vectorAll(const unsigned char x[4])
      {
        int k;
        bool exitg1;
        bool y;
        y = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if ((static_cast<int>(x[k])) == 0) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return y;
      }
    }
  }
}

//
// File trailer for allOrAny.cpp
//
// [EOF]
//
