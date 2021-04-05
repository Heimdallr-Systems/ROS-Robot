//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Body_Pose_Controller.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "Body_Pose_Controller.h"
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
// This function is used to solve for IK solutions of the robot's legs when
//  measurements in terms of the inertial frame are known. Use this function
//  when solving for tilt under the flat plane assumption.
//  r_II_c = [r_II_c_FR,r_II_c_FL, r_II_c_BR, r_II_c_BL];
//  r_II_c_?? = [x_II_c; y_II_c; z_II_c]
//  BodyRot = zyx rotation of body
//  r_II_B_d = vector from inertial to body
//  Returns: Theta1 of each leg, both solutions for theta2 of each leg, both
//  solutions for theta3 of each leg
// Arguments    : const double r_II_c[12]
//                const double T_I_B[9]
//                double r_II_B_d[3]
//                const double r_II_B_0[3]
//                const unsigned char legs_on_gnd[4]
//                double Theta1[4]
//                double Theta2[4]
//                double Theta3[4]
// Return Type  : void
//
namespace Codegen
{
  void Body_Pose_Controller(const double r_II_c[12], const double T_I_B[9],
    double r_II_B_d[3], const double r_II_B_0[3], const unsigned char
    legs_on_gnd[4], double Theta1[4], double Theta2[4], double Theta3[4])
  {
    creal_T dc;
    double b_dv1[9];
    double b_dv3[9];
    double b_dv5[9];
    double b_dv6[9];
    double b_dv7[9];
    double b_dv9[9];
    double dv11[9];
    double dv12[9];
    double b_dv[3];
    double b_dv10[3];
    double b_dv2[3];
    double b_dv4[3];
    double b_dv8[3];
    double b_r_II_c[3];
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
    double Theta1_2_idx_0;
    double Theta1_2_idx_1;
    double Theta1_2_idx_2;
    double Theta1_2_idx_3;
    double Theta2_2_idx_0;
    double Theta2_2_idx_1;
    double Theta2_2_idx_2;
    double Theta2_2_idx_3;
    double Theta2_4_idx_0;
    double Theta2_4_idx_1;
    double Theta2_4_idx_2;
    double Theta2_4_idx_3;
    double Theta3_2_idx_0;
    double Theta3_2_idx_1;
    double Theta3_2_idx_2;
    double Theta3_2_idx_3;
    double Theta3_4_idx_0;
    double Theta3_4_idx_1;
    double Theta3_4_idx_2;
    double Theta3_4_idx_3;
    double d;
    double d10;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d20;
    double d21;
    double d22;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d32;
    double d33;
    double d35;
    double d36;
    double d37;
    double d38;
    double d39;
    double d4;
    double d40;
    double d41;
    double d42;
    double d43;
    double d44;
    double d45;
    double d46;
    double d47;
    double d48;
    double d49;
    double d5;
    double d6;
    double d7;
    double d9;
    double travel_dir_idx_0;
    double travel_dir_idx_1;
    double travel_dir_idx_2;
    bool T1_cond_idx_0;
    bool T1_cond_idx_1;
    bool T1_cond_idx_2;
    bool T1_cond_idx_3;
    bool loop_toggle;

    //  Constants, known offsets
    //  known lengths of last two links
    loop_toggle = false;

    // initialize
    Theta1[0] = 0.0;
    Theta1_2_idx_0 = 0.0;
    Theta2_2_idx_0 = 0.0;
    Theta2_4_idx_0 = 0.0;
    Theta3_2_idx_0 = 0.0;
    Theta3_4_idx_0 = 0.0;
    Theta1[1] = 0.0;
    Theta1_2_idx_1 = 0.0;
    Theta2_2_idx_1 = 0.0;
    Theta2_4_idx_1 = 0.0;
    Theta3_2_idx_1 = 0.0;
    Theta3_4_idx_1 = 0.0;
    Theta1[2] = 0.0;
    Theta1_2_idx_2 = 0.0;
    Theta2_2_idx_2 = 0.0;
    Theta2_4_idx_2 = 0.0;
    Theta3_2_idx_2 = 0.0;
    Theta3_4_idx_2 = 0.0;
    Theta1[3] = 0.0;
    Theta1_2_idx_3 = 0.0;
    Theta2_2_idx_3 = 0.0;
    Theta2_4_idx_3 = 0.0;
    Theta3_2_idx_3 = 0.0;
    Theta3_4_idx_3 = 0.0;

    //  Reference for what the elements are for each variable
    //  Theta1(:,1) = [Theta1_FR, Theta1_FL, Theta1_BR, Theta1_BL]
    //  Theta1_2(:,1) = [Theta1_FR_2, Theta1_FL_2, Theta1_BR_2, Theta1_BL_2]
    //  Theta2(:,1) = [Theta2_FR, Theta2_FL, Theta2_BR, Theta2_BL]
    //  Theta2_2(:,1) =  [Theta2_FR_2, Theta2_FL_2, Theta2_BR_2, Theta2_BL_2]
    //  Theta2_3(:,1) = [Theta2_FR_3, Theta2_FL_3, Theta2_BR_3, Theta2_BL_3]
    //  Theta2_4(:,1) = [Theta2_FR_4, Theta2_FL_4, Theta2_BR_4, Theta2_BL_4]
    //  Theta3(:,1) = [Theta3_FR, Theta3_FL, Theta3_BR, Theta3_BL]
    //  Theta3_2(:,1) =  [Theta3_FR_2, Theta3_FL_2, Theta3_BR_2, Theta3_BL_2]
    //  Theta3_3(:,1) = [Theta3_FR_3, Theta3_FL_3, Theta3_BR_3, Theta3_BL_3]
    //  Theta3_4(:,1) = [Theta3_FR_4, Theta3_FL_4, Theta3_BR_4, Theta3_BL_4]
    travel_dir_tmp[0] = r_II_B_d[0] - r_II_B_0[0];
    travel_dir_tmp[1] = r_II_B_d[1] - r_II_B_0[1];
    travel_dir_tmp[2] = r_II_B_d[2] - r_II_B_0[2];
    d = coder::b_norm(travel_dir_tmp);
    travel_dir_idx_0 = travel_dir_tmp[0] / d;
    travel_dir_idx_1 = travel_dir_tmp[1] / d;
    travel_dir_idx_2 = travel_dir_tmp[2] / d;
    while (!loop_toggle) {
      //     %% FR LEG
      loop_toggle = true;
      if ((static_cast<int>(legs_on_gnd[0])) == 1) {
        double D_FR;
        double D_FR_2;
        double d1;
        double r_FR;
        double r_FR_2;
        double s_FR;
        double s_FR_2;
        b_r_II_c[0] = r_II_c[0] - r_II_B_d[0];
        b_r_II_c[1] = r_II_c[1] - r_II_B_d[1];
        b_r_II_c[2] = r_II_c[2] - r_II_B_d[2];
        coder::mldivide(T_I_B, b_r_II_c, b_dv);
        r_B1_c_FR[0] = b_dv[0] - 0.12578;
        r_B1_c_FR[1] = b_dv[1] - -0.12578;
        r_B1_c_FR[2] = b_dv[2] - 0.0254;
        d1 = coder::b_atan2(b_dv[1] - -0.12578, b_dv[0] - 0.12578) +
          1.5707963267948966;
        dc.re = d1 * 0.0;
        dc.im = d1;
        coder::b_exp(&dc);
        Theta1[0] = coder::angle(dc);
        Theta1_2_idx_0 = Theta1[0] + 3.1415926535897931;
        rotz(Theta1[0], b_dv1);
        coder::mldivide(b_dv1, r_B1_c_FR, b_dv2);
        coder::mldivide(dv10, b_dv2, r_1prime1_c_FR);
        rotz(Theta1[0] + 3.1415926535897931, b_dv3);
        coder::mldivide(b_dv3, r_B1_c_FR, b_dv4);
        coder::mldivide(dv10, b_dv4, r_1prime1_c_FR_2);
        coder::mldivide(dv10, dv1, r_1prime1_2_FR);
        r_FR = r_1prime1_c_FR[1] - r_1prime1_2_FR[1];
        r_FR_2 = r_1prime1_c_FR_2[1] - r_1prime1_2_FR[1];
        s_FR = r_1prime1_c_FR[2] - r_1prime1_2_FR[2];
        s_FR_2 = r_1prime1_c_FR_2[2] - r_1prime1_2_FR[2];
        D_FR = ((((r_FR * r_FR) + (s_FR * s_FR)) - 0.0225) -
                0.041615999999999993) / 0.061199999999999991;
        D_FR_2 = ((((r_FR_2 * r_FR_2) + (s_FR_2 * s_FR_2)) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
        if (D_FR > 0.999) {
          loop_toggle = false;
          r_II_B_d[0] -= travel_dir_idx_0 * 0.001;
          r_II_B_d[1] -= travel_dir_idx_1 * 0.001;
          r_II_B_d[2] -= travel_dir_idx_2 * 0.001;

          //              r_II_B_d(3) = r_II_B_0(3);
        } else {
          double Theta3_FR_2_Temp;
          double Theta3_FR_Temp;
          double d2;
          d2 = 1.0 - (D_FR * D_FR);
          d3 = d2;
          coder::b_sqrt(&d3);
          Theta3_FR_Temp = coder::b_atan2(d3, D_FR);
          d5 = d2;
          coder::b_sqrt(&d5);
          Theta3_FR_2_Temp = coder::b_atan2(-d5, D_FR);
          d9 = d2;
          coder::b_sqrt(&d9);
          d12 = d2;
          coder::b_sqrt(&d12);
          Theta3_2_idx_0 = -coder::b_atan2(-d12, D_FR);
          d15 = Theta3_FR_Temp;
          coder::b_sin(&d15);
          d18 = Theta3_FR_Temp;
          coder::b_cos(&d18);
          d21 = Theta3_FR_2_Temp;
          coder::b_sin(&d21);
          d25 = Theta3_FR_2_Temp;
          coder::b_cos(&d25);
          Theta2_2_idx_0 = -(coder::b_atan2(s_FR, r_FR) - coder::b_atan2(0.204 *
            d21, (0.204 * d25) + 0.15));
        }

        //  see if second solution possible
        if (D_FR_2 > 0.999) {
          Theta1_2_idx_0 = 0.0;
          Theta3_4_idx_0 = 0.0;
          Theta2_4_idx_0 = 0.0;
        } else {
          double Theta3_FR_2_Temp_2;
          double d11;
          d11 = 1.0 - (D_FR_2 * D_FR_2);
          d13 = d11;
          coder::b_sqrt(&d13);
          Theta3_FR_2_Temp_2 = coder::b_atan2(-d13, D_FR_2);
          d16 = d11;
          coder::b_sqrt(&d16);
          Theta3_4_idx_0 = -coder::b_atan2(-d16, D_FR_2);
          d19 = Theta3_FR_2_Temp_2;
          coder::b_sin(&d19);
          d22 = Theta3_FR_2_Temp_2;
          coder::b_cos(&d22);
          Theta2_4_idx_0 = -(coder::b_atan2(s_FR_2, r_FR_2) - coder::b_atan2
                             (0.204 * d19, (0.204 * d22) + 0.15));
        }
      } else {
        Theta1[0] = 0.0;
        Theta1_2_idx_0 = 0.0;
        Theta2_2_idx_0 = 0.0;
        Theta2_4_idx_0 = 0.0;
        Theta3_2_idx_0 = 0.0;
        Theta3_4_idx_0 = 0.0;
      }

      //     %% FL LEG
      if ((static_cast<int>(legs_on_gnd[1])) == 1) {
        double D_FL;
        double D_FL_2;
        b_r_II_c[0] = r_II_c[3] - r_II_B_d[0];
        b_r_II_c[1] = r_II_c[4] - r_II_B_d[1];
        b_r_II_c[2] = r_II_c[5] - r_II_B_d[2];
        coder::mldivide(T_I_B, b_r_II_c, b_dv);
        r_B1_c_FL[0] = b_dv[0] - 0.12578;
        r_B1_c_FL[1] = b_dv[1] - 0.12578;
        r_B1_c_FL[2] = b_dv[2] - 0.0254;
        Theta1[1] = coder::b_atan2(b_dv[1] - 0.12578, b_dv[0] - 0.12578) -
          1.5707963267948966;
        dc.re = Theta1[1] * 0.0;
        dc.im = Theta1[1];
        coder::b_exp(&dc);
        Theta1[1] = coder::angle(dc);
        Theta1_2_idx_1 = Theta1[1] + 3.1415926535897931;
        rotz(Theta1[1], b_dv5);
        coder::mldivide(b_dv5, r_B1_c_FL, r_11_c_FL);
        rotz(Theta1[1] + 3.1415926535897931, b_dv6);
        coder::mldivide(b_dv6, r_B1_c_FL, r_11_c_FL_2);
        D_FL = (((((r_11_c_FL[1] - 0.039) * (r_11_c_FL[1] - 0.039)) +
                  (r_11_c_FL[2] * r_11_c_FL[2])) - 0.0225) -
                0.041615999999999993) / 0.061199999999999991;
        D_FL_2 = (((((r_11_c_FL_2[1] - 0.039) * (r_11_c_FL_2[1] - 0.039)) +
                    (r_11_c_FL_2[2] * r_11_c_FL_2[2])) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
        if (D_FL_2 > 0.999) {
          Theta1_2_idx_1 = 0.0;
          Theta3_4_idx_1 = 0.0;
          Theta2_4_idx_1 = 0.0;
        } else {
          d4 = 1.0 - (D_FL_2 * D_FL_2);
          coder::b_sqrt(&d4);
          Theta3_4_idx_1 = coder::b_atan2(-d4, D_FL_2);
          d6 = Theta3_4_idx_1;
          coder::b_sin(&d6);
          d7 = Theta3_4_idx_1;
          coder::b_cos(&d7);
          Theta2_4_idx_1 = coder::b_atan2(r_11_c_FL_2[2], r_11_c_FL_2[1] - 0.039)
            - coder::b_atan2(0.204 * d6, (0.204 * d7) + 0.15);
        }

        if (D_FL > 0.999) {
          loop_toggle = false;
          r_II_B_d[0] -= travel_dir_idx_0 * 0.001;
          r_II_B_d[1] -= travel_dir_idx_1 * 0.001;
          r_II_B_d[2] -= travel_dir_idx_2 * 0.001;

          //              r_II_B_d(3) = r_II_B_0(3);
        } else {
          double d8;
          d8 = 1.0 - (D_FL * D_FL);
          d10 = d8;
          coder::b_sqrt(&d10);
          Theta3[1] = coder::b_atan2(d10, D_FL);
          d14 = d8;
          coder::b_sqrt(&d14);
          Theta3_2_idx_1 = coder::b_atan2(-d14, D_FL);
          d17 = Theta3[1];
          coder::b_sin(&d17);
          d20 = Theta3[1];
          coder::b_cos(&d20);
          d24 = Theta3_2_idx_1;
          coder::b_sin(&d24);
          d28 = Theta3_2_idx_1;
          coder::b_cos(&d28);
          Theta2_2_idx_1 = coder::b_atan2(r_11_c_FL[2], r_11_c_FL[1] - 0.039) -
            coder::b_atan2(0.204 * d24, (0.204 * d28) + 0.15);
        }
      } else {
        Theta1[1] = 0.0;
        Theta1_2_idx_1 = 0.0;
        Theta2_2_idx_1 = 0.0;
        Theta2_4_idx_1 = 0.0;
        Theta3_2_idx_1 = 0.0;
        Theta3_4_idx_1 = 0.0;
      }

      //     %% BR LEG
      if ((static_cast<int>(legs_on_gnd[2])) == 1) {
        double D_BR;
        double D_BR_2;
        double r_BR;
        double r_BR_2;
        double s_BR;
        double s_BR_2;
        b_r_II_c[0] = r_II_c[6] - r_II_B_d[0];
        b_r_II_c[1] = r_II_c[7] - r_II_B_d[1];
        b_r_II_c[2] = r_II_c[8] - r_II_B_d[2];
        coder::mldivide(T_I_B, b_r_II_c, b_dv);
        r_B1_c_BR[0] = b_dv[0] - -0.12578;
        r_B1_c_BR[1] = b_dv[1] - -0.12578;
        r_B1_c_BR[2] = b_dv[2] - 0.0254;
        Theta1[2] = coder::b_atan2(b_dv[1] - -0.12578, b_dv[0] - -0.12578) +
          1.5707963267948966;
        dc.re = Theta1[2] * 0.0;
        dc.im = Theta1[2];
        coder::b_exp(&dc);
        Theta1[2] = coder::angle(dc);
        Theta1_2_idx_2 = Theta1[2] + 3.1415926535897931;
        rotz(Theta1[2], b_dv7);
        coder::mldivide(b_dv7, r_B1_c_BR, b_dv8);
        coder::mldivide(dv10, b_dv8, r_1prime1_c_BR);
        rotz(Theta1[2] + 3.1415926535897931, b_dv9);
        coder::mldivide(b_dv9, r_B1_c_BR, b_dv10);
        coder::mldivide(dv10, b_dv10, r_1prime1_c_BR_2);
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
          Theta1_2_idx_2 = 0.0;
          Theta3_4_idx_2 = 0.0;
          Theta2_4_idx_2 = 0.0;
        } else {
          double Theta3_BR_2_Temp_2;
          double d23;
          d23 = 1.0 - (D_BR_2 * D_BR_2);
          d26 = d23;
          coder::b_sqrt(&d26);
          Theta3_BR_2_Temp_2 = coder::b_atan2(-d26, D_BR_2);
          d29 = d23;
          coder::b_sqrt(&d29);
          Theta3_4_idx_2 = -coder::b_atan2(-d29, D_BR_2);
          d35 = Theta3_BR_2_Temp_2;
          coder::b_sin(&d35);
          d37 = Theta3_BR_2_Temp_2;
          coder::b_cos(&d37);
          Theta2_4_idx_2 = -(coder::b_atan2(s_BR_2, r_BR_2) - coder::b_atan2
                             (0.204 * d35, (0.204 * d37) + 0.15));
        }

        if (D_BR > 0.999) {
          loop_toggle = false;
          r_II_B_d[0] -= travel_dir_idx_0 * 0.001;
          r_II_B_d[1] -= travel_dir_idx_1 * 0.001;
          r_II_B_d[2] -= travel_dir_idx_2 * 0.001;

          //              r_II_B_d(3) = r_II_B_0(3);
        } else {
          double Theta3_BR_2_Temp;
          double Theta3_BR_Temp;
          double d31;
          d31 = 1.0 - (D_BR * D_BR);
          d32 = d31;
          coder::b_sqrt(&d32);
          Theta3_BR_Temp = coder::b_atan2(d32, D_BR);
          d38 = d31;
          coder::b_sqrt(&d38);
          Theta3_BR_2_Temp = coder::b_atan2(-d38, D_BR);
          d40 = d31;
          coder::b_sqrt(&d40);
          d42 = d31;
          coder::b_sqrt(&d42);
          Theta3_2_idx_2 = -coder::b_atan2(-d42, D_BR);
          d44 = Theta3_BR_Temp;
          coder::b_sin(&d44);
          d46 = Theta3_BR_Temp;
          coder::b_cos(&d46);
          d48 = Theta3_BR_2_Temp;
          coder::b_sin(&d48);
          d49 = Theta3_BR_2_Temp;
          coder::b_cos(&d49);
          Theta2_2_idx_2 = -(coder::b_atan2(s_BR, r_BR) - coder::b_atan2(0.204 *
            d48, (0.204 * d49) + 0.15));
        }
      } else {
        Theta1[2] = 0.0;
        Theta1_2_idx_2 = 0.0;
        Theta2_2_idx_2 = 0.0;
        Theta2_4_idx_2 = 0.0;
        Theta3_2_idx_2 = 0.0;
        Theta3_4_idx_2 = 0.0;
      }

      //     %% BL LEG
      if ((static_cast<int>(legs_on_gnd[3])) == 1) {
        double D_BL;
        double D_BL_2;
        b_r_II_c[0] = r_II_c[9] - r_II_B_d[0];
        b_r_II_c[1] = r_II_c[10] - r_II_B_d[1];
        b_r_II_c[2] = r_II_c[11] - r_II_B_d[2];
        coder::mldivide(T_I_B, b_r_II_c, b_dv);
        r_B1_c_BL[0] = b_dv[0] - -0.12578;
        r_B1_c_BL[1] = b_dv[1] - 0.12578;
        r_B1_c_BL[2] = b_dv[2] - 0.0254;
        Theta1[3] = coder::b_atan2(b_dv[1] - 0.12578, b_dv[0] - -0.12578) -
          1.5707963267948966;
        dc.re = Theta1[3] * 0.0;
        dc.im = Theta1[3];
        coder::b_exp(&dc);
        Theta1[3] = coder::angle(dc);
        Theta1_2_idx_3 = Theta1[3] + 3.1415926535897931;
        rotz(Theta1[3], dv11);
        coder::mldivide(dv11, r_B1_c_BL, r_11_c_BL);
        rotz(Theta1[3] + 3.1415926535897931, dv12);
        coder::mldivide(dv12, r_B1_c_BL, r_11_c_BL_2);
        D_BL = (((((r_11_c_BL[1] - 0.039) * (r_11_c_BL[1] - 0.039)) +
                  (r_11_c_BL[2] * r_11_c_BL[2])) - 0.0225) -
                0.041615999999999993) / 0.061199999999999991;
        D_BL_2 = (((((r_11_c_BL_2[1] - 0.039) * (r_11_c_BL_2[1] - 0.039)) +
                    (r_11_c_BL_2[2] * r_11_c_BL_2[2])) - 0.0225) -
                  0.041615999999999993) / 0.061199999999999991;
        if (D_BL_2 > 0.999) {
          Theta1_2_idx_3 = 0.0;
          Theta3_4_idx_3 = 0.0;
          Theta2_4_idx_3 = 0.0;
        } else {
          d27 = 1.0 - (D_BL_2 * D_BL_2);
          coder::b_sqrt(&d27);
          Theta3_4_idx_3 = coder::b_atan2(-d27, D_BL_2);
          d30 = Theta3_4_idx_3;
          coder::b_sin(&d30);
          d33 = Theta3_4_idx_3;
          coder::b_cos(&d33);
          Theta2_4_idx_3 = coder::b_atan2(r_11_c_BL_2[2], r_11_c_BL_2[1] - 0.039)
            - coder::b_atan2(0.204 * d30, (0.204 * d33) + 0.15);
        }

        if (D_BL > 0.999) {
          loop_toggle = false;
          r_II_B_d[0] -= travel_dir_idx_0 * 0.001;
          r_II_B_d[1] -= travel_dir_idx_1 * 0.001;
          r_II_B_d[2] -= travel_dir_idx_2 * 0.001;

          //              r_II_B_d(3) = r_II_B_0(3);
        } else {
          double d34;
          d34 = 1.0 - (D_BL * D_BL);
          d36 = d34;
          coder::b_sqrt(&d36);
          Theta3[3] = coder::b_atan2(d36, D_BL);
          d39 = d34;
          coder::b_sqrt(&d39);
          Theta3_2_idx_3 = coder::b_atan2(-d39, D_BL);
          d41 = Theta3[3];
          coder::b_sin(&d41);
          d43 = Theta3[3];
          coder::b_cos(&d43);
          d45 = Theta3_2_idx_3;
          coder::b_sin(&d45);
          d47 = Theta3_2_idx_3;
          coder::b_cos(&d47);
          Theta2_2_idx_3 = coder::b_atan2(r_11_c_BL[2], r_11_c_BL[1] - 0.039) -
            coder::b_atan2(0.204 * d45, (0.204 * d47) + 0.15);
        }
      } else {
        Theta1[3] = 0.0;
        Theta1_2_idx_3 = 0.0;
        Theta2_2_idx_3 = 0.0;
        Theta2_4_idx_3 = 0.0;
        Theta3_2_idx_3 = 0.0;
        Theta3_4_idx_3 = 0.0;
      }
    }

    //  if theta1 wraps around into robot
    if ((Theta1[0] <= -1.5707963267948966) || (Theta1[0] >= 3.1415926535897931))
    {
      T1_cond_idx_0 = true;
    } else {
      T1_cond_idx_0 = false;
    }

    //  FR
    if ((Theta1[1] <= -3.1415926535897931) || (Theta1[1] >= 1.5707963267948966))
    {
      T1_cond_idx_1 = true;
    } else {
      T1_cond_idx_1 = false;
    }

    // FL
    if ((Theta1[2] <= -3.1415926535897931) || (Theta1[2] >= 1.5707963267948966))
    {
      T1_cond_idx_2 = true;
    } else {
      T1_cond_idx_2 = false;
    }

    //  BR
    if ((Theta1[3] <= -1.5707963267948966) || (Theta1[3] >= 3.1415926535897931))
    {
      T1_cond_idx_3 = true;
    } else {
      T1_cond_idx_3 = false;
    }

    //  BL
    if (T1_cond_idx_0) {
      Theta1[0] = Theta1_2_idx_0;
      Theta2[0] = Theta2_4_idx_0;
      Theta3[0] = Theta3_4_idx_0;
    } else {
      Theta2[0] = Theta2_2_idx_0;
      Theta3[0] = Theta3_2_idx_0;
    }

    if (T1_cond_idx_1) {
      Theta1[1] = Theta1_2_idx_1;
      Theta2[1] = Theta2_4_idx_1;
      Theta3[1] = Theta3_4_idx_1;
    } else {
      Theta2[1] = Theta2_2_idx_1;
      Theta3[1] = Theta3_2_idx_1;
    }

    if (T1_cond_idx_2) {
      Theta1[2] = Theta1_2_idx_2;
      Theta2[2] = Theta2_4_idx_2;
      Theta3[2] = Theta3_4_idx_2;
    } else {
      Theta2[2] = Theta2_2_idx_2;
      Theta3[2] = Theta3_2_idx_2;
    }

    if (T1_cond_idx_3) {
      Theta1[3] = Theta1_2_idx_3;
      Theta2[3] = Theta2_4_idx_3;
      Theta3[3] = Theta3_4_idx_3;
    } else {
      Theta2[3] = Theta2_2_idx_3;
      Theta3[3] = Theta3_2_idx_3;
    }
  }
}

//
// File trailer for Body_Pose_Controller.cpp
//
// [EOF]
//
