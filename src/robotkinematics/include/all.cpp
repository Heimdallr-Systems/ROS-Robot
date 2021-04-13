//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: all.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "all.h"
#include "allOrAny.h"

// Function Definitions
//
// Arguments    : const unsigned char x[4]
// Return Type  : bool
//
namespace Codegen {
namespace coder {
bool all(const unsigned char x[4])
{
  return internal::vectorAll(x);
}

} // namespace coder
} // namespace Codegen

//
// File trailer for all.cpp
//
// [EOF]
//
