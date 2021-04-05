//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
#include "main.h"
#include "Robot_Control.h"
#include "Robot_Control_initialize.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_36x1_real_T(double result[36]);
static void argInit_3x1_real_T(double result[3]);
static bool argInit_boolean_T();
static double argInit_real_T();
static void main_Robot_Control();

// Function Definitions
//
// Arguments    : double result[36]
// Return Type  : void
//
static void argInit_36x1_real_T(double result[36])
{
  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < 36; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_3x1_real_T(double result[3])
{
  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < 3; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : bool
//
static bool argInit_boolean_T()
{
  return false;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_Robot_Control()
{
  double dv2[36];
  double Theta1_d_out[4];
  double Theta2_d_out[4];
  double Theta3_d_out[4];
  double dv[3];
  double dv1[3];
  double r_II_B_d_temp_out[3];
  double phi_d_temp_out;
  unsigned char floor_toggle_out[4];
  unsigned char legs_valid_out[4];

  // Initialize function 'Robot_Control' input arguments.
  // Initialize function input argument 'r_II_B_d'.
  // Initialize function input argument 'Euler_d'.
  // Initialize function input argument 'gamma_m'.
  // Call the entry-point 'Robot_Control'.
  argInit_3x1_real_T(dv);
  argInit_3x1_real_T(dv1);
  argInit_36x1_real_T(dv2);
  Codegen::Robot_Control(dv, dv1, dv2, argInit_boolean_T(), Theta1_d_out,
    Theta2_d_out, Theta3_d_out, &phi_d_temp_out, r_II_B_d_temp_out,
    floor_toggle_out, legs_valid_out);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  Codegen::Robot_Control_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_Robot_Control();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
