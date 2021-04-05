//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inpolygon.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//
#ifndef INPOLYGON_H
#define INPOLYGON_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen
{
  namespace coder
  {
    bool b_inpolygon(double x, double y, const double xv[3], const double yv[3]);
    bool inpolygon(double x, double y, const double xv[4], const double yv[4]);
  }
}

#endif

//
// File trailer for inpolygon.h
//
// [EOF]
//
