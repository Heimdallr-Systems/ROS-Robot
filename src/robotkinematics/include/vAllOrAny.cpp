//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: vAllOrAny.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "vAllOrAny.h"
#include "isfinite.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    namespace internal
    {
      static bool flatVectorAllOrAny(const double x[108]);
    }
  }
}

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
      static bool flatVectorAllOrAny(const double x[108])
      {
        bool p;
        p = true;
        for (int k = 0; k < 108; k++) {
          if (p) {
            if (!b_isfinite(x[k])) {
              p = false;
            }
          } else {
            p = false;
          }
        }

        return p;
      }

      //
      // Arguments    : const double x[108]
      // Return Type  : bool
      //
      bool vAllOrAny(const double x[108])
      {
        return flatVectorAllOrAny(x);
      }
    }
  }
}

//
// File trailer for vAllOrAny.cpp
//
// [EOF]
//
