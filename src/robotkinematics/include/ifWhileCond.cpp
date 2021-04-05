//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ifWhileCond.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "ifWhileCond.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      static bool checkNoNaNs(const bool x[3]);
    }
  }
}

// Function Definitions
//
// Arguments    : const bool x[3]
// Return Type  : bool
//
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      static bool checkNoNaNs(const bool x[3])
      {
        int k;
        bool exitg1;
        bool y;
        y = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 3)) {
          if (!x[k]) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return y;
      }

      //
      // Arguments    : const bool x[3]
      // Return Type  : bool
      //
      bool ifWhileCond(const bool x[3])
      {
        return checkNoNaNs(x);
      }
    }
  }
}

//
// File trailer for ifWhileCond.cpp
//
// [EOF]
//
