//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Leg_Controller.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "Leg_Controller.h"
#include "Robot_Control_data.h"
#include "angle.h"
#include "atan2.h"
#include "cos.h"
#include "exp.h"
#include "mldivide.h"
#include "norm.h"
#include "rotz.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sqrt.h"

// Function Definitions
//
// This function operates similar to IK_Solver_Legs_Inertial, but instead is
//  intended to use the current T_I_B and r_II_B with a desired r_BB_c_d.
//  This should allow the leg desired to be moved act independent to the
//  position/tilt controller.
//  Works for one leg only!!!
// Arguments    : double r_II_c_d[3]
//                const double r_II_c_0[3]
//                const double T_I_B[9]
//                const double r_II_B[3]
//                unsigned char b_leg_index
//                double *Theta1
//                double *Theta2
//                double *Theta3
// Return Type  : void
//
namespace Codegen
{
  void Leg_Controller(double r_II_c_d[3], const double r_II_c_0[3], const double
                      T_I_B[9], const double r_II_B[3], unsigned char
                      b_leg_index, double *Theta1, double *Theta2, double
                      *Theta3)
  {
    creal_T dc;
    double b_dv1[9];
    double b_dv10[9];
    double b_dv2[9];
    double b_dv3[9];
    double b_dv4[9];
    double b_dv7[9];
    double b_dv8[9];
    double b_dv9[9];
    double b_dv[3];
    double b_dv5[3];
    double b_dv6[3];
    double b_r_II_c_d[3];
    double dv11[3];
    double dv12[3];
    double r_11_c_BL[3];
    double r_11_c_BL_2[3];
    double r_11_c_FL[3];
    double r_11_c_FL_2[3];
    double r_1prime1_2_BR[3];
    double r_1prime1_2_FR[3];
    double r_1prime1_c_BR[3];
    double r_1prime1_c_BR_2[3];
    double r_1prime1_c_FR[3];
    double r_1prime1_c_FR_2[3];
    double r_B1_c_BL[3];
    double r_B1_c_BR[3];
    double r_B1_c_FL[3];
    double r_B1_c_FR[3];
    double travel_dir_tmp[3];
    double Theta1_2;
    double Theta2_2;
    double Theta2_4;
    double Theta3_2;
    double Theta3_4;
    double d;
    double d10;
    double d11;
    double d12;
    double d14;
    double d15;
    double d16;
    double d18;
    double d19;
    double d20;
    double d21;
    double d23;
    double d24;
    double d26;
    double d27;
    double d28;
    double d29;
    double d30;
    double d31;
    double d32;
    double d33;
    double d34;
    double d35;
    double d36;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    double travel_dir_idx_0;
    double travel_dir_idx_1;
    double travel_dir_idx_2;
    int loop_toggle;
    bool T1_cond;

    //  Constants, known offsets
    //  known lengths of last two links
    //  Init these so that coder does not throw a hissy fit
    //  FIXME: This could actually cause problems. Check with Nick
    *Theta1 = 0.0;
    Theta1_2 = 0.0;
    Theta2_2 = 0.0;
    Theta3_2 = 0.0;
    Theta2_4 = 0.0;
    Theta3_4 = 0.0;

    //
    travel_dir_tmp[0] = r_II_c_d[0] - r_II_c_0[0];
    travel_dir_tmp[1] = r_II_c_d[1] - r_II_c_0[1];
    travel_dir_tmp[2] = r_II_c_d[2] - r_II_c_0[2];
    d = coder::b_norm(travel_dir_tmp);
    travel_dir_idx_0 = travel_dir_tmp[0] / d;
    travel_dir_idx_1 = travel_dir_tmp[1] / d;
    travel_dir_idx_2 = travel_dir_tmp[2] / d;
    loop_toggle = 0;
    while (loop_toggle == 0) {
      loop_toggle = 1;

      // initialize
      switch (b_leg_index) {
       case 1:
        {
          double D_FR;
          double D_FR_2;
          double d4;
          double r_FR;
          double r_FR_2;
          double s_FR;
          double s_FR_2;

          //     %% FR LEG
          b_r_II_c_d[0] = r_II_c_d[0] - r_II_B[0];
          b_r_II_c_d[1] = r_II_c_d[1] - r_II_B[1];
          b_r_II_c_d[2] = r_II_c_d[2] - r_II_B[2];
          coder::mldivide(T_I_B, b_r_II_c_d, b_dv);
          r_B1_c_FR[0] = b_dv[0] - 0.12578;
          r_B1_c_FR[1] = b_dv[1] - -0.12578;
          r_B1_c_FR[2] = b_dv[2] - 0.0254;
          d4 = coder::b_atan2(b_dv[1] - -0.12578, b_dv[0] - 0.12578) +
            1.5707963267948966;
          dc.re = d4 * 0.0;
          dc.im = d4;
          coder::b_exp(&dc);
          *Theta1 = coder::angle(dc);
          Theta1_2 = (*Theta1) + 3.1415926535897931;
          rotz(*Theta1, b_dv4);
          coder::mldivide(b_dv4, r_B1_c_FR, b_dv6);
          coder::mldivide(dv10, b_dv6, r_1prime1_c_FR);
          rotz((*Theta1) + 3.1415926535897931, b_dv10);
          coder::mldivide(b_dv10, r_B1_c_FR, dv12);
          coder::mldivide(dv10, dv12, r_1prime1_c_FR_2);
          coder::mldivide(dv10, dv1, r_1prime1_2_FR);
          r_FR = r_1prime1_c_FR[1] - r_1prime1_2_FR[1];
          r_FR_2 = r_1prime1_c_FR_2[1] - r_1prime1_2_FR[1];
          s_FR = r_1prime1_c_FR[2] - r_1prime1_2_FR[2];
          s_FR_2 = r_1prime1_c_FR_2[2] - r_1prime1_2_FR[2];
          D_FR = ((((r_FR * r_FR) + (s_FR * s_FR)) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
          D_FR_2 = ((((r_FR_2 * r_FR_2) + (s_FR_2 * s_FR_2)) - 0.0225) -
                    0.041615999999999993) / 0.061199999999999991;

          //  see if second solution possible
          if (D_FR_2 > 0.999) {
            Theta1_2 = 0.0;
            Theta3_4 = 0.0;
            Theta2_4 = 0.0;
          } else {
            double Theta3_FR_2_Temp_2;
            double d17;
            d17 = 1.0 - (D_FR_2 * D_FR_2);
            d18 = d17;
            coder::b_sqrt(&d18);
            Theta3_FR_2_Temp_2 = coder::b_atan2(-d18, D_FR_2);
            d23 = d17;
            coder::b_sqrt(&d23);
            Theta3_4 = -coder::b_atan2(-d23, D_FR_2);
            d28 = Theta3_FR_2_Temp_2;
            coder::b_sin(&d28);
            d31 = Theta3_FR_2_Temp_2;
            coder::b_cos(&d31);
            Theta2_4 = -(coder::b_atan2(s_FR_2, r_FR_2) - coder::b_atan2(0.204 *
              d28, (0.204 * d31) + 0.15));
          }

          if (D_FR > 0.999) {
            loop_toggle = 0;
            r_II_c_d[0] -= travel_dir_idx_0 * 0.01;
            r_II_c_d[1] -= travel_dir_idx_1 * 0.01;
            r_II_c_d[2] -= travel_dir_idx_2 * 0.01;
            r_II_c_d[2] = r_II_c_0[2];
          } else {
            double Theta3_FR_2_Temp;
            double d25;
            d25 = 1.0 - (D_FR * D_FR);
            d27 = d25;
            coder::b_sqrt(&d27);
            Theta3_FR_2_Temp = coder::b_atan2(-d27, D_FR);
            d32 = d25;
            coder::b_sqrt(&d32);
            Theta3_2 = -coder::b_atan2(-d32, D_FR);
            d34 = Theta3_FR_2_Temp;
            coder::b_sin(&d34);
            d36 = Theta3_FR_2_Temp;
            coder::b_cos(&d36);
            Theta2_2 = -(coder::b_atan2(s_FR, r_FR) - coder::b_atan2(0.204 * d34,
              (0.204 * d36) + 0.15));
          }

          //     %% FL LEG
        }
        break;

       case 2:
        {
          double D_FL;
          double D_FL_2;
          double d1;
          b_r_II_c_d[0] = r_II_c_d[0] - r_II_B[0];
          b_r_II_c_d[1] = r_II_c_d[1] - r_II_B[1];
          b_r_II_c_d[2] = r_II_c_d[2] - r_II_B[2];
          coder::mldivide(T_I_B, b_r_II_c_d, b_dv);
          r_B1_c_FL[0] = b_dv[0] - 0.12578;
          r_B1_c_FL[1] = b_dv[1] - 0.12578;
          r_B1_c_FL[2] = b_dv[2] - 0.0254;
          d1 = coder::b_atan2(b_dv[1] - 0.12578, b_dv[0] - 0.12578) -
            1.5707963267948966;
          dc.re = d1 * 0.0;
          dc.im = d1;
          coder::b_exp(&dc);
          *Theta1 = coder::angle(dc);
          Theta1_2 = (*Theta1) + 3.1415926535897931;
          rotz(*Theta1, b_dv1);
          coder::mldivide(b_dv1, r_B1_c_FL, r_11_c_FL);
          rotz((*Theta1) + 3.1415926535897931, b_dv7);
          coder::mldivide(b_dv7, r_B1_c_FL, r_11_c_FL_2);
          D_FL = (((((r_11_c_FL[1] - 0.039) * (r_11_c_FL[1] - 0.039)) +
                    (r_11_c_FL[2] * r_11_c_FL[2])) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
          D_FL_2 = (((((r_11_c_FL_2[1] - 0.039) * (r_11_c_FL_2[1] - 0.039)) +
                      (r_11_c_FL_2[2] * r_11_c_FL_2[2])) - 0.0225) -
                    0.041615999999999993) / 0.061199999999999991;
          if (D_FL_2 > 0.999) {
            Theta1_2 = 0.0;
            Theta3_4 = 0.0;
            Theta2_4 = 0.0;
          } else {
            d5 = 1.0 - (D_FL_2 * D_FL_2);
            coder::b_sqrt(&d5);
            Theta3_4 = coder::b_atan2(-d5, D_FL_2);
            d7 = Theta3_4;
            coder::b_sin(&d7);
            d9 = Theta3_4;
            coder::b_cos(&d9);
            Theta2_4 = coder::b_atan2(r_11_c_FL_2[2], r_11_c_FL_2[1] - 0.039) -
              coder::b_atan2(0.204 * d7, (0.204 * d9) + 0.15);
          }

          if (D_FL > 0.999) {
            loop_toggle = 0;
            r_II_c_d[0] -= travel_dir_idx_0 * 0.01;
            r_II_c_d[1] -= travel_dir_idx_1 * 0.01;
            r_II_c_d[2] -= travel_dir_idx_2 * 0.01;
            r_II_c_d[2] = r_II_c_0[2];
          } else {
            d10 = 1.0 - (D_FL * D_FL);
            coder::b_sqrt(&d10);
            Theta3_2 = coder::b_atan2(-d10, D_FL);
            d14 = Theta3_2;
            coder::b_sin(&d14);
            d19 = Theta3_2;
            coder::b_cos(&d19);
            Theta2_2 = coder::b_atan2(r_11_c_FL[2], r_11_c_FL[1] - 0.039) -
              coder::b_atan2(0.204 * d14, (0.204 * d19) + 0.15);
          }

          //     %% BR LEG
        }
        break;

       case 3:
        {
          double D_BR;
          double D_BR_2;
          double d2;
          double r_BR;
          double r_BR_2;
          double s_BR;
          double s_BR_2;
          b_r_II_c_d[0] = r_II_c_d[0] - r_II_B[0];
          b_r_II_c_d[1] = r_II_c_d[1] - r_II_B[1];
          b_r_II_c_d[2] = r_II_c_d[2] - r_II_B[2];
          coder::mldivide(T_I_B, b_r_II_c_d, b_dv);
          r_B1_c_BR[0] = b_dv[0] - -0.12578;
          r_B1_c_BR[1] = b_dv[1] - -0.12578;
          r_B1_c_BR[2] = b_dv[2] - 0.0254;
          d2 = coder::b_atan2(b_dv[1] - -0.12578, b_dv[0] - -0.12578) +
            1.5707963267948966;
          dc.re = d2 * 0.0;
          dc.im = d2;
          coder::b_exp(&dc);
          *Theta1 = coder::angle(dc);
          Theta1_2 = (*Theta1) + 3.1415926535897931;
          rotz(*Theta1, b_dv2);
          coder::mldivide(b_dv2, r_B1_c_BR, b_dv5);
          coder::mldivide(dv10, b_dv5, r_1prime1_c_BR);
          rotz((*Theta1) + 3.1415926535897931, b_dv9);
          coder::mldivide(b_dv9, r_B1_c_BR, dv11);
          coder::mldivide(dv10, dv11, r_1prime1_c_BR_2);
          coder::mldivide(dv10, dv1, r_1prime1_2_BR);
          r_BR = r_1prime1_c_BR[1] - r_1prime1_2_BR[1];
          r_BR_2 = r_1prime1_c_BR_2[1] - r_1prime1_2_BR[1];
          s_BR = r_1prime1_c_BR[2] - r_1prime1_2_BR[2];
          s_BR_2 = r_1prime1_c_BR_2[2] - r_1prime1_2_BR[2];
          D_BR = ((((r_BR * r_BR) + (s_BR * s_BR)) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
          D_BR_2 = ((((r_BR_2 * r_BR_2) + (s_BR_2 * s_BR_2)) - 0.0225) -
                    0.041615999999999993) / 0.061199999999999991;
          if (D_BR_2 > 0.999) {
            Theta1_2 = 0.0;
            Theta3_4 = 0.0;
            Theta2_4 = 0.0;
          } else {
            double Theta3_BR_2_Temp_2;
            double d13;
            d13 = 1.0 - (D_BR_2 * D_BR_2);
            d15 = d13;
            coder::b_sqrt(&d15);
            Theta3_BR_2_Temp_2 = coder::b_atan2(-d15, D_BR_2);
            d21 = d13;
            coder::b_sqrt(&d21);
            Theta3_4 = -coder::b_atan2(-d21, D_BR_2);
            d26 = Theta3_BR_2_Temp_2;
            coder::b_sin(&d26);
            d29 = Theta3_BR_2_Temp_2;
            coder::b_cos(&d29);
            Theta2_4 = -(coder::b_atan2(s_BR_2, r_BR_2) - coder::b_atan2(0.204 *
              d26, (0.204 * d29) + 0.15));
          }

          if (D_BR > 0.999) {
            loop_toggle = 0;
            r_II_c_d[0] -= travel_dir_idx_0 * 0.01;
            r_II_c_d[1] -= travel_dir_idx_1 * 0.01;
            r_II_c_d[2] -= travel_dir_idx_2 * 0.01;
            r_II_c_d[2] = r_II_c_0[2];
          } else {
            double Theta3_BR_2_Temp;
            double d22;
            d22 = 1.0 - (D_BR * D_BR);
            d24 = d22;
            coder::b_sqrt(&d24);
            Theta3_BR_2_Temp = coder::b_atan2(-d24, D_BR);
            d30 = d22;
            coder::b_sqrt(&d30);
            Theta3_2 = -coder::b_atan2(-d30, D_BR);
            d33 = Theta3_BR_2_Temp;
            coder::b_sin(&d33);
            d35 = Theta3_BR_2_Temp;
            coder::b_cos(&d35);
            Theta2_2 = -(coder::b_atan2(s_BR, r_BR) - coder::b_atan2(0.204 * d33,
              (0.204 * d35) + 0.15));
          }

          //     %% BL LEG
        }
        break;

       case 4:
        {
          double D_BL;
          double D_BL_2;
          double d3;
          b_r_II_c_d[0] = r_II_c_d[0] - r_II_B[0];
          b_r_II_c_d[1] = r_II_c_d[1] - r_II_B[1];
          b_r_II_c_d[2] = r_II_c_d[2] - r_II_B[2];
          coder::mldivide(T_I_B, b_r_II_c_d, b_dv);
          r_B1_c_BL[0] = b_dv[0] - -0.12578;
          r_B1_c_BL[1] = b_dv[1] - 0.12578;
          r_B1_c_BL[2] = b_dv[2] - 0.0254;
          d3 = coder::b_atan2(b_dv[1] - 0.12578, b_dv[0] - -0.12578) -
            1.5707963267948966;
          dc.re = d3 * 0.0;
          dc.im = d3;
          coder::b_exp(&dc);
          *Theta1 = coder::angle(dc);
          Theta1_2 = (*Theta1) + 3.1415926535897931;
          rotz(*Theta1, b_dv3);
          coder::mldivide(b_dv3, r_B1_c_BL, r_11_c_BL);
          rotz((*Theta1) + 3.1415926535897931, b_dv8);
          coder::mldivide(b_dv8, r_B1_c_BL, r_11_c_BL_2);
          D_BL = (((((r_11_c_BL[1] - 0.039) * (r_11_c_BL[1] - 0.039)) +
                    (r_11_c_BL[2] * r_11_c_BL[2])) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
          D_BL_2 = (((((r_11_c_BL_2[1] - 0.039) * (r_11_c_BL_2[1] - 0.039)) +
                      (r_11_c_BL_2[2] * r_11_c_BL_2[2])) - 0.0225) -
                    0.041615999999999993) / 0.061199999999999991;
          if (D_BL_2 > 0.999) {
            Theta1_2 = 0.0;
            Theta3_4 = 0.0;
            Theta2_4 = 0.0;
          } else {
            d6 = 1.0 - (D_BL_2 * D_BL_2);
            coder::b_sqrt(&d6);
            Theta3_4 = coder::b_atan2(-d6, D_BL_2);
            d8 = Theta3_4;
            coder::b_sin(&d8);
            d11 = Theta3_4;
            coder::b_cos(&d11);
            Theta2_4 = coder::b_atan2(r_11_c_BL_2[2], r_11_c_BL_2[1] - 0.039) -
              coder::b_atan2(0.204 * d8, (0.204 * d11) + 0.15);
          }

          if (D_BL > 0.999) {
            loop_toggle = 0;
            r_II_c_d[0] -= travel_dir_idx_0 * 0.01;
            r_II_c_d[1] -= travel_dir_idx_1 * 0.01;
            r_II_c_d[2] -= travel_dir_idx_2 * 0.01;
            r_II_c_d[2] = r_II_c_0[2];
          } else {
            d12 = 1.0 - (D_BL * D_BL);
            coder::b_sqrt(&d12);
            Theta3_2 = coder::b_atan2(-d12, D_BL);
            d16 = Theta3_2;
            coder::b_sin(&d16);
            d20 = Theta3_2;
            coder::b_cos(&d20);
            Theta2_2 = coder::b_atan2(r_11_c_BL[2], r_11_c_BL[1] - 0.039) -
              coder::b_atan2(0.204 * d16, (0.204 * d20) + 0.15);
          }
        }
        break;

       default:
        // no actions
        break;
      }
    }

    //  if theta1 wraps around into robot
    switch (b_leg_index) {
     case 1:
      if (((*Theta1) <= -1.5707963267948966) || ((*Theta1) >= 3.1415926535897931))
      {
        T1_cond = true;
      } else {
        T1_cond = false;
      }

      //  FR
      break;

     case 2:
      if (((*Theta1) <= -3.1415926535897931) || ((*Theta1) >= 1.5707963267948966))
      {
        T1_cond = true;
      } else {
        T1_cond = false;
      }

      // FL
      break;

     case 3:
      if (((*Theta1) <= -3.1415926535897931) || ((*Theta1) >= 1.5707963267948966))
      {
        T1_cond = true;
      } else {
        T1_cond = false;
      }

      //  BR
      break;

     case 4:
      if (((*Theta1) <= -1.5707963267948966) || ((*Theta1) >= 3.1415926535897931))
      {
        T1_cond = true;
      } else {
        T1_cond = false;
      }

      //  BL
      break;

     default:
      // no actions
      break;
    }

    if (T1_cond) {
      *Theta1 = Theta1_2;
      *Theta2 = Theta2_4;
      *Theta3 = Theta3_4;
    } else {
      *Theta2 = Theta2_2;
      *Theta3 = Theta3_2;
    }
  }
}

//
// File trailer for Leg_Controller.cpp
//
// [EOF]
//
