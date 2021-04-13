//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Robot_Control_types.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

#ifndef ROBOT_CONTROL_TYPES_H
#define ROBOT_CONTROL_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
namespace Codegen {
struct rtRunTimeErrorInfo {
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
};

struct rtBoundsCheckInfo {
  int iFirst;
  int iLast;
  int lineNo;
  int colNo;
  const char *aName;
  const char *fName;
  const char *pName;
  int checkKind;
};

} // namespace Codegen

#endif
//
// File trailer for Robot_Control_types.h
//
// [EOF]
//
