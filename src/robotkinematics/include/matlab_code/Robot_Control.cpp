//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Robot_Control.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "Robot_Control.h"
#include "Body_Pose_Controller.h"
#include "CPos_wrt_I.h"
#include "Leg_Controller.h"
#include "Leg_Controller_B.h"
#include "abs.h"
#include "all.h"
#include "centroid_codeGen.h"
#include "eye.h"
#include "find_pgon_goal.h"
#include "ifWhileCond.h"
#include "inpolygon.h"
#include "isequal.h"
#include "manipulability.h"
#include "norm.h"
#include "rotx.h"
#include "roty.h"
#include "rotz.h"
#include "rt_nonfinite.h"
#include "sign.h"
#include "sort.h"
#include "step_planner_intelligent.h"
#include <cmath>
#include <cstring>

// Variable Definitions
namespace Codegen
{
  static bool waypoint_toggle;
  static bool turn_toggle;
  static unsigned char step_state;
  static bool turn_state;
  static unsigned char reached_centroid;
  static unsigned char reached_rest_centroid;
  static unsigned char step_needed;
  static bool calc_manip;
  static unsigned char legs_valid[4];
  static unsigned char floor_toggle[4];
  static bool floor_toggle_not_empty;
  static unsigned char legs_stepped;
  static bool leg_reset_needed;
  static unsigned char leg_index;
  static double startPoint[3];
  static double endPoint[3];
  static bool endPoint_not_empty;
  static double manip_vec[4];
  static double startPhi;
  static double endPhi;
  static bool endPhi_not_empty;
  static unsigned char is_turning;
  static double phi_d_temp;
  static double r_II_B_d_temp[3];
  static double T_I_B_d_temp[9];
  static double r_II_c_FR_0[3];
  static double r_II_c_FL_0[3];
  static double r_II_c_BR_0[3];
  static double r_II_c_BL_0[3];
  static double Theta1_d_midpt;
  static double Theta2_d_midpt;
  static double Theta3_d_midpt;
  static double Theta1_d_reset;
  static double Theta2_d_reset;
  static double Theta3_d_reset;
  static double r_II_c_current[3];
  static double r_II_c_dstep[3];
  static double Theta1_d[4];
  static double Theta2_d[4];
  static double Theta3_d[4];
}

// Function Declarations
namespace Codegen
{
  static double rt_roundd_snf(double u);
}

// Function Definitions
//
// Arguments    : double u
// Return Type  : double
//
namespace Codegen
{
  static double rt_roundd_snf(double u)
  {
    double y;
    if (std::abs(u) < 4.503599627370496E+15) {
      if (u >= 0.5) {
        y = std::floor(u + 0.5);
      } else if (u > -0.5) {
        y = u * 0.0;
      } else {
        y = std::ceil(u - 0.5);
      }
    } else {
      y = u;
    }

    return y;
  }

  //
  // Controls Robot's walking algorithm
  //    input: r_II_B_d, Euler_d, gamma_m
  //    output: Theta_d (1-3), phi_d_temp & r_II_b_d_temp (orientation for plotting),
  //    floor_toggle & legs_valid (for computing forces)
  //    NOTE: For the real system, phi_d_temp & r_II_b_d_temp,
  //    floor_toggle & legs_valid can be thrown
  //    away. For kinematic system, floor_toggle is not needed. For dynamic
  //    system phi_d_temp % r_II_B_d_temp is not needed
  //    r_II_B_d = [x_d;y_d;z_d];
  //    Euler_d = [phi,theta,psi];
  //    gamma_m = [Euler,r_II_B,Theta1,Theta2,Theta3];
  //    Euler = [phi,theta,psi];
  //    r_II_B = [x,y,z];
  //    Theta1 = [Theta1FR,FL,BR,BL];
  //    Theta2 = [Theta2FR,FL,BR,BL];
  //    Theta3 = [Theta3FR,FL,BR,BL];
  // Arguments    : const double r_II_B_d[3]
  //                const double Euler_d[3]
  //                const double gamma_m[36]
  //                bool init_toggle
  //                double Theta1_d_out[4]
  //                double Theta2_d_out[4]
  //                double Theta3_d_out[4]
  //                double *phi_d_temp_out
  //                double r_II_B_d_temp_out[3]
  //                unsigned char floor_toggle_out[4]
  //                unsigned char legs_valid_out[4]
  // Return Type  : void
  //
  void Robot_Control(const double r_II_B_d[3], const double Euler_d[3], const
                     double gamma_m[36], bool init_toggle, double Theta1_d_out[4],
                     double Theta2_d_out[4], double Theta3_d_out[4], double
                     *phi_d_temp_out, double r_II_B_d_temp_out[3], unsigned char
                     floor_toggle_out[4], unsigned char legs_valid_out[4])
  {
    double state[36];
    double r_II_c[12];
    double T_I_B[9];
    double T_I_B_d_tmp[9];
    double b_T_I_B_d_tmp[9];
    double b_dv[9];
    double b_dv1[9];
    double b_dv2[9];
    double b_dv3[9];
    double Theta1[4];
    double Theta2[4];
    double Theta3[4];
    double b_r_II_c_FL[4];
    double b_r_II_c_FR[4];
    double c_r_II_c_FL[4];
    double c_r_II_c_FR[4];
    double unusedU0[4];
    double b_Theta1[3];
    double b_r_II_B[3];
    double b_r_II_B_d[3];
    double c_r_II_B[3];
    double d_r_II_B[3];
    double e_r_II_B[3];
    double f_r_II_B[3];
    double g_r_II_B[3];
    double h_r_II_B[3];
    double i_r_II_B[3];
    double j_r_II_B[3];
    double r_BB_c_reset_BL[3];
    double r_BB_c_reset_BR[3];
    double r_BB_c_reset_FL[3];
    double r_BB_c_reset_FR[3];
    double r_II_B[3];
    double r_II_c_BL[3];
    double r_II_c_BR[3];
    double r_II_c_FL[3];
    double r_II_c_FR[3];
    double b_x;
    double b_y;
    double c_x;
    double c_y;
    double d11;
    double d_x;
    double d_y;
    double e_x;
    double e_y;
    double f_x;
    double f_y;
    double g_x;
    double g_y;
    double h_x;
    double h_y;
    double i_x;
    double i_y;
    double muBL;
    double muBR;
    double muFL;
    double muFR;
    double step_error;
    double x;
    double y;
    int iidx[4];
    unsigned char uv[4];
    bool bv[3];

    //  Variable Init
    //  leg step distance
    //  constants for mid-step resting position
    //  FR
    //  FL
    //  BR
    //  BL
    //  initialize max bound for moving without steps
    //  persistent vars
    //  intialize toggle for determining direction of travel
    //  init toggle for determining direction of turning
    //  intialize toggle for determining which phase of step leg is in
    //  init toggle for determining which phase of turn robot is in
    //  initialize toggle for determining which state the body is in
    //  initialize toggle for determining which state the body is in when returning to a four-leg-defined polygon centroid 
    //  initialize variable for determining which leg needs to be stepped next
    //  initialize toggle for determining if manipulability needs to be recalculated 
    if (!floor_toggle_not_empty) {
      floor_toggle[0] = legs_valid[0];
      floor_toggle[1] = legs_valid[1];
      floor_toggle[2] = legs_valid[2];
      floor_toggle[3] = legs_valid[3];
      floor_toggle_not_empty = true;
    }

    //  Here begins the questionable initialization stuff. SHould be removed if possible 
    //  leg_index=0 will fallthrough and cause function to not do anything
    step_error = 0.0;

    //  TODO: Figure out how to remove these without breaking body pose controller 
    //  Removing some vars causes errors in body pose controller
    //  Removing some vars causes a singular matrix
    //  Removing some vars casues legs to move too far forward
    if (init_toggle) {
      waypoint_toggle = false;

      //  intialize toggle for determining direction of travel
      turn_toggle = false;

      //  init toggle for determining direction of turning
      step_state = 0U;

      //  intialize toggle for determining which phase of step leg is in
      turn_state = false;

      //  init toggle for determining which phase of turn robot is in
      reached_centroid = 0U;

      //  initialize toggle for determining which state the body is in
      reached_rest_centroid = 1U;

      //  initialize toggle for determining which state the body is in when returning to a four-leg-defined polygon centroid 
      step_needed = 1U;

      //  initialize variable for determining which leg needs to be stepped next 
      calc_manip = true;

      //  initialize toggle for determining if manipulability needs to be recalculated 
      legs_valid[0] = 1U;
      floor_toggle[0] = 1U;
      legs_valid[1] = 1U;
      floor_toggle[1] = 1U;
      legs_valid[2] = 1U;
      floor_toggle[2] = 1U;
      legs_valid[3] = 1U;
      floor_toggle[3] = 1U;
      legs_stepped = 0U;
      leg_reset_needed = false;
      coder::eye(T_I_B_d_temp);
      phi_d_temp = 0.0;
      is_turning = 0U;
    }

    //  Initialize state be the correct size
    std::memset(&state[0], 0, 36U * (sizeof(double)));

    //  current
    r_II_B[0] = gamma_m[3];
    r_II_B[1] = gamma_m[4];
    r_II_B[2] = gamma_m[5];
    Theta1[0] = gamma_m[6];
    Theta1[1] = gamma_m[7];
    Theta1[2] = gamma_m[8];
    Theta1[3] = gamma_m[9];
    Theta2[0] = gamma_m[10];
    Theta2[1] = gamma_m[11];
    Theta2[2] = gamma_m[12];
    Theta2[3] = gamma_m[13];
    Theta3[0] = gamma_m[14];
    Theta3[1] = gamma_m[15];
    Theta3[2] = gamma_m[16];
    Theta3[3] = gamma_m[17];
    rotz(gamma_m[0], b_dv);
    roty(gamma_m[1], b_dv1);
    rotx(gamma_m[2], b_dv2);
    for (int i = 0; i < 3; i++) {
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      double d5;
      d = b_dv[i];
      d1 = b_dv[i + 3];
      d2 = b_dv[i + 6];
      for (int i1 = 0; i1 < 3; i1++) {
        b_dv3[i + (3 * i1)] = ((d * b_dv1[3 * i1]) + (d1 * b_dv1[(3 * i1) + 1]))
          + (d2 * b_dv1[(3 * i1) + 2]);
      }

      d3 = b_dv3[i];
      d4 = b_dv3[i + 3];
      d5 = b_dv3[i + 6];
      for (int i2 = 0; i2 < 3; i2++) {
        T_I_B[i + (3 * i2)] = ((d3 * b_dv2[3 * i2]) + (d4 * b_dv2[(3 * i2) + 1]))
          + (d5 * b_dv2[(3 * i2) + 2]);
      }
    }

    std::memcpy(&state[0], &gamma_m[0], 18U * (sizeof(double)));

    //  Constants for "resetting" legs
    //  FR
    r_BB_c_reset_FR[0] = 0.25;
    r_BB_c_reset_FR[1] = -0.25;
    r_BB_c_reset_FR[2] = -gamma_m[5];

    //  FL
    r_BB_c_reset_FL[0] = 0.25;
    r_BB_c_reset_FL[1] = 0.25;
    r_BB_c_reset_FL[2] = -gamma_m[5];

    //  BR
    r_BB_c_reset_BR[0] = -0.25;
    r_BB_c_reset_BR[1] = -0.25;
    r_BB_c_reset_BR[2] = -gamma_m[5];

    //  BL
    r_BB_c_reset_BL[0] = -0.25;
    r_BB_c_reset_BL[1] = 0.25;
    r_BB_c_reset_BL[2] = -gamma_m[5];

    //  desired
    roty(Euler_d[1], T_I_B_d_tmp);
    rotx(Euler_d[2], b_T_I_B_d_tmp);
    CPos_wrt_I(Theta1, Theta2, Theta3, T_I_B, r_II_B, r_II_c_FR, r_II_c_FL,
               r_II_c_BR, r_II_c_BL);
    r_II_c[0] = r_II_c_FR[0];
    r_II_c[3] = r_II_c_FL[0];
    r_II_c[6] = r_II_c_BR[0];
    r_II_c[9] = r_II_c_BL[0];
    r_II_c[1] = r_II_c_FR[1];
    r_II_c[4] = r_II_c_FL[1];
    r_II_c[7] = r_II_c_BR[1];
    r_II_c[10] = r_II_c_BL[1];
    r_II_c[2] = r_II_c_FR[2];
    r_II_c[5] = r_II_c_FL[2];
    r_II_c[8] = r_II_c_BR[2];
    r_II_c[11] = r_II_c_BL[2];

    //  Check if step is needed
    //  manipulability calculations
    //  find the least manipulable leg, start stepping that leg. then
    //  step the next least manipulable leg until the last leg is stepped
    // TODO: COnvert to seperate function
    //  TODO: Why not just run this every time?
    if (((static_cast<int>(step_state)) == 0) && ((static_cast<int>
          (reached_rest_centroid)) == 1)) {
      if (calc_manip) {
        manipulability(state, &muFR, &muFL, &muBR, &muBL);
        unusedU0[0] = muFR;
        unusedU0[1] = muFL;
        unusedU0[2] = muBR;
        unusedU0[3] = muBL;
        coder::internal::sort(unusedU0, iidx);
        manip_vec[0] = static_cast<double>(iidx[0]);
        manip_vec[1] = static_cast<double>(iidx[1]);
        manip_vec[2] = static_cast<double>(iidx[2]);
        manip_vec[3] = static_cast<double>(iidx[3]);
        calc_manip = false;
      }

      switch (step_needed) {
       case 1:
        {
          double d6;
          unsigned char u;
          d6 = rt_roundd_snf(manip_vec[0]);
          if (d6 < 256.0) {
            if (d6 >= 0.0) {
              u = static_cast<unsigned char>(d6);
            } else {
              u = 0U;
            }
          } else if (d6 >= 256.0) {
            u = MAX_uint8_T;
          } else {
            u = 0U;
          }

          leg_index = u;
          step_needed = 2U;
        }
        break;

       case 2:
        {
          double d7;
          unsigned char u1;
          d7 = rt_roundd_snf(manip_vec[1]);
          if (d7 < 256.0) {
            if (d7 >= 0.0) {
              u1 = static_cast<unsigned char>(d7);
            } else {
              u1 = 0U;
            }
          } else if (d7 >= 256.0) {
            u1 = MAX_uint8_T;
          } else {
            u1 = 0U;
          }

          leg_index = u1;
          step_needed = 3U;
        }
        break;

       case 3:
        {
          double d8;
          unsigned char u2;
          d8 = rt_roundd_snf(manip_vec[2]);
          if (d8 < 256.0) {
            if (d8 >= 0.0) {
              u2 = static_cast<unsigned char>(d8);
            } else {
              u2 = 0U;
            }
          } else if (d8 >= 256.0) {
            u2 = MAX_uint8_T;
          } else {
            u2 = 0U;
          }

          leg_index = u2;
          step_needed = 4U;
        }
        break;

       case 4:
        {
          double d9;
          unsigned char u3;
          d9 = rt_roundd_snf(manip_vec[3]);
          if (d9 < 256.0) {
            if (d9 >= 0.0) {
              u3 = static_cast<unsigned char>(d9);
            } else {
              u3 = 0U;
            }
          } else if (d9 >= 256.0) {
            u3 = MAX_uint8_T;
          } else {
            u3 = 0U;
          }

          leg_index = u3;
          step_needed = 1U;
          calc_manip = true;
        }
        break;

       default:
        // no actions
        break;
      }
    }

    //  waypoint section
    if ((!waypoint_toggle) || (!endPoint_not_empty)) {
      startPoint[0] = gamma_m[3];
      endPoint[0] = r_II_B_d[0];
      startPoint[1] = gamma_m[4];
      endPoint[1] = r_II_B_d[1];
      startPoint[2] = gamma_m[5];
      endPoint[2] = r_II_B_d[2];
      endPoint_not_empty = true;
      waypoint_toggle = true;
    } else {
      waypoint_toggle = coder::isequal(endPoint, r_II_B_d);
    }

    if ((!turn_toggle) || (!endPhi_not_empty)) {
      startPhi = gamma_m[0];
      endPhi = Euler_d[0];
      endPhi_not_empty = true;
      turn_toggle = true;
    } else {
      turn_toggle = !(endPhi != Euler_d[0]);
    }

    //  Turn Needed Algorithm
    if (coder::b_abs(endPhi - startPhi) > 0.31415926535897931) {
      double d10;
      d10 = coder::b_abs(Euler_d[0] - gamma_m[0]);
      if (d10 < 0.31415926535897931) {
        if ((!turn_state) && (!leg_reset_needed)) {
          is_turning = 1U;
          phi_d_temp = Euler_d[0];
          turn_state = true;
        } else {
          if (turn_state && (d10 < 0.05)) {
            turn_state = false;
            startPhi = gamma_m[0];
            leg_reset_needed = true;

            //  reset legs
            is_turning = 2U;
          }
        }
      } else {
        //  TODO: Replace turn dir calc with if statement to reduce number of
        //  variables that are of type double
        if ((!turn_state) && (!leg_reset_needed)) {
          is_turning = 1U;
          d11 = Euler_d[0] - gamma_m[0];
          coder::b_sign(&d11);
          phi_d_temp = gamma_m[0] + ((d11 * 3.1415926535897931) / 10.0);
          rotz(phi_d_temp, b_dv);
          for (int i3 = 0; i3 < 3; i3++) {
            double d12;
            double d13;
            double d14;
            double d15;
            double d16;
            double d17;
            d12 = b_dv[i3];
            d13 = b_dv[i3 + 3];
            d14 = b_dv[i3 + 6];
            for (int i4 = 0; i4 < 3; i4++) {
              b_dv1[i3 + (3 * i4)] = ((d12 * T_I_B_d_tmp[3 * i4]) + (d13 *
                T_I_B_d_tmp[(3 * i4) + 1])) + (d14 * T_I_B_d_tmp[(3 * i4) + 2]);
            }

            d15 = b_dv1[i3];
            d16 = b_dv1[i3 + 3];
            d17 = b_dv1[i3 + 6];
            for (int i5 = 0; i5 < 3; i5++) {
              T_I_B_d_temp[i3 + (3 * i5)] = ((d15 * b_T_I_B_d_tmp[3 * i5]) +
                (d16 * b_T_I_B_d_tmp[(3 * i5) + 1])) + (d17 * b_T_I_B_d_tmp[(3 *
                i5) + 2]);
            }
          }

          turn_state = true;
        } else {
          if (turn_state) {
            is_turning = 1U;
            if (coder::b_abs(phi_d_temp - gamma_m[0]) < 0.05) {
              turn_state = false;
              startPhi = gamma_m[0];
              leg_reset_needed = true;

              //  reset legs
            }
          }
        }
      }

      //     %% Turn Stepping Section
      if (leg_reset_needed) {
        //  step to reset legs
        switch (leg_index) {
         case 1:
          {
            legs_valid[0] = 0U;
            if ((static_cast<int>(reached_centroid)) == 0) {
              c_r_II_B[0] = r_II_B[0];
              c_r_II_B[1] = r_II_B[1];
              c_r_II_B[2] = r_II_B[2];
              find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL,
                             c_r_II_B, leg_index, &x, &y);
              r_II_B_d_temp[0] = x;
              r_II_B_d_temp[1] = y;
              r_II_B_d_temp[2] = r_II_B_d[2];
            }

            switch (step_state) {
             case 0:
              //  hasn't started stepping yet
              Theta1_d_midpt = 0.78539816339744828;
              Theta2_d_midpt = -0.78539816339744828;
              Theta3_d_midpt = 2.3561944901923448;
              step_state = 1U;
              r_II_c_FR_0[0] = r_II_c_FR[0];
              r_II_c_FR_0[1] = r_II_c_FR[1];
              r_II_c_FR_0[2] = r_II_c_FR[2];
              break;

             case 1:
              //  moving towards midpoint
              b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
              b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
              b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
              b_Theta1[0] -= Theta1_d_midpt;
              b_Theta1[1] -= Theta2_d_midpt;
              b_Theta1[2] -= Theta3_d_midpt;
              step_error = coder::b_norm(b_Theta1);
              if (step_error < 0.2) {
                //  reached midpoint
                step_state = 3U;
                Leg_Controller_B(r_BB_c_reset_FR, static_cast<unsigned char>(1U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
              }
              break;

             case 3:
              {
                //  stepping towards goal now
                Leg_Controller_B(r_BB_c_reset_FR, static_cast<unsigned char>(1U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
                if (r_II_c_FR[2] <= 0.0) {
                  int i7;
                  step_state = 0U;
                  legs_valid[0] = 1U;
                  leg_index = 0U;
                  floor_toggle[0] = 1U;
                  reached_centroid = 0U;
                  reached_rest_centroid = 0U;
                  i7 = static_cast<int>(static_cast<unsigned int>((static_cast<
                    unsigned int>(legs_stepped)) + 1U));
                  if (((static_cast<unsigned int>(legs_stepped)) + 1U) > 255U) {
                    i7 = 255;
                  }

                  legs_stepped = static_cast<unsigned char>(i7);
                }
              }
              break;

             default:
              // no actions
              break;
            }
          }
          break;

         case 2:
          {
            legs_valid[1] = 0U;
            if ((static_cast<int>(reached_centroid)) == 0) {
              d_r_II_B[0] = r_II_B[0];
              d_r_II_B[1] = r_II_B[1];
              d_r_II_B[2] = r_II_B[2];
              find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL,
                             d_r_II_B, leg_index, &b_x, &b_y);
              r_II_B_d_temp[0] = b_x;
              r_II_B_d_temp[1] = b_y;
              r_II_B_d_temp[2] = r_II_B_d[2];
            }

            switch (step_state) {
             case 0:
              //  hasn't started stepping yet
              Theta1_d_midpt = -0.78539816339744828;
              Theta2_d_midpt = 0.78539816339744828;
              Theta3_d_midpt = -2.3561944901923448;
              step_state = 1U;
              r_II_c_FL_0[0] = r_II_c_FL[0];
              r_II_c_FL_0[1] = r_II_c_FL[1];
              r_II_c_FL_0[2] = r_II_c_FL[2];
              break;

             case 1:
              //  moving towards midpoint
              b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
              b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
              b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
              b_Theta1[0] -= Theta1_d_midpt;
              b_Theta1[1] -= Theta2_d_midpt;
              b_Theta1[2] -= Theta3_d_midpt;
              step_error = coder::b_norm(b_Theta1);
              if (step_error < 0.2) {
                //  reached midpoint
                step_state = 3U;
                Leg_Controller_B(r_BB_c_reset_FL, static_cast<unsigned char>(2U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
              }
              break;

             case 3:
              {
                //  stepping towards goal now
                Leg_Controller_B(r_BB_c_reset_FL, static_cast<unsigned char>(2U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
                if (r_II_c_FL[2] <= 0.0) {
                  int i8;
                  step_state = 0U;
                  legs_valid[1] = 1U;
                  leg_index = 0U;
                  floor_toggle[1] = 1U;
                  reached_centroid = 0U;
                  reached_rest_centroid = 0U;

                  // if error reached
                  i8 = static_cast<int>(static_cast<unsigned int>((static_cast<
                    unsigned int>(legs_stepped)) + 1U));
                  if (((static_cast<unsigned int>(legs_stepped)) + 1U) > 255U) {
                    i8 = 255;
                  }

                  legs_stepped = static_cast<unsigned char>(i8);
                }
              }
              break;

             default:
              // no actions
              break;
            }
          }
          break;

         case 3:
          {
            legs_valid[2] = 0U;
            if ((static_cast<int>(reached_centroid)) == 0) {
              e_r_II_B[0] = r_II_B[0];
              e_r_II_B[1] = r_II_B[1];
              e_r_II_B[2] = r_II_B[2];
              find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL,
                             e_r_II_B, leg_index, &c_x, &c_y);
              r_II_B_d_temp[0] = c_x;
              r_II_B_d_temp[1] = c_y;
              r_II_B_d_temp[2] = r_II_B_d[2];
            }

            switch (step_state) {
             case 0:
              //  hasn't started stepping yet
              Theta1_d_midpt = -0.78539816339744828;
              Theta2_d_midpt = -0.78539816339744828;
              Theta3_d_midpt = 2.3561944901923448;
              step_state = 1U;
              r_II_c_BR_0[0] = r_II_c_BR[0];
              r_II_c_BR_0[1] = r_II_c_BR[1];
              r_II_c_BR_0[2] = r_II_c_BR[2];
              break;

             case 1:
              //  moving towards midpoint
              b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
              b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
              b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
              b_Theta1[0] -= Theta1_d_midpt;
              b_Theta1[1] -= Theta2_d_midpt;
              b_Theta1[2] -= Theta3_d_midpt;
              step_error = coder::b_norm(b_Theta1);
              if (step_error < 0.2) {
                //  reached midpoint
                step_state = 3U;
                Leg_Controller_B(r_BB_c_reset_BR, static_cast<unsigned char>(3U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
              }
              break;

             case 3:
              {
                //  stepping towards goal now
                Leg_Controller_B(r_BB_c_reset_BR, static_cast<unsigned char>(3U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
                if (r_II_c_BR[2] <= 0.0) {
                  int i9;
                  legs_valid[2] = 1U;
                  step_state = 0U;
                  leg_index = 0U;
                  floor_toggle[2] = 1U;
                  reached_centroid = 0U;
                  reached_rest_centroid = 0U;

                  // if error reached
                  i9 = static_cast<int>(static_cast<unsigned int>((static_cast<
                    unsigned int>(legs_stepped)) + 1U));
                  if (((static_cast<unsigned int>(legs_stepped)) + 1U) > 255U) {
                    i9 = 255;
                  }

                  legs_stepped = static_cast<unsigned char>(i9);
                }
              }
              break;

             default:
              // no actions
              break;
            }
          }
          break;

         case 4:
          {
            legs_valid[3] = 0U;
            if ((static_cast<int>(reached_centroid)) == 0) {
              f_r_II_B[0] = r_II_B[0];
              f_r_II_B[1] = r_II_B[1];
              f_r_II_B[2] = r_II_B[2];
              find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL,
                             f_r_II_B, leg_index, &d_x, &d_y);
              r_II_B_d_temp[0] = d_x;
              r_II_B_d_temp[1] = d_y;
              r_II_B_d_temp[2] = r_II_B_d[2];
            }

            switch (step_state) {
             case 0:
              //  hasn't started stepping yet
              Theta1_d_midpt = 0.78539816339744828;
              Theta2_d_midpt = 0.78539816339744828;
              Theta3_d_midpt = -2.3561944901923448;
              step_state = 1U;
              r_II_c_BL_0[0] = r_II_c_BL[0];
              r_II_c_BL_0[1] = r_II_c_BL[1];
              r_II_c_BL_0[2] = r_II_c_BL[2];
              break;

             case 1:
              //  moving towards midpoint
              b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
              b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
              b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
              b_Theta1[0] -= Theta1_d_midpt;
              b_Theta1[1] -= Theta2_d_midpt;
              b_Theta1[2] -= Theta3_d_midpt;
              step_error = coder::b_norm(b_Theta1);
              if (step_error < 0.2) {
                //  reached midpoint
                step_state = 3U;
                Leg_Controller_B(r_BB_c_reset_BL, static_cast<unsigned char>(4U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
              }
              break;

             case 3:
              {
                //  stepping towards goal now
                Leg_Controller_B(r_BB_c_reset_BL, static_cast<unsigned char>(4U),
                                 &Theta1_d_reset, &Theta2_d_reset,
                                 &Theta3_d_reset);
                if (r_II_c_BL[2] <= 0.0) {
                  int i10;
                  step_state = 0U;
                  legs_valid[3] = 1U;
                  leg_index = 0U;
                  floor_toggle[3] = 1U;
                  reached_centroid = 0U;
                  reached_rest_centroid = 0U;

                  // if error reached
                  i10 = static_cast<int>(static_cast<unsigned int>((static_cast<
                    unsigned int>(legs_stepped)) + 1U));
                  if (((static_cast<unsigned int>(legs_stepped)) + 1U) > 255U) {
                    i10 = 255;
                  }

                  legs_stepped = static_cast<unsigned char>(i10);
                }
              }
              break;

             default:
              // no actions
              break;
            }
          }
          break;

         default:
          // no actions
          break;
        }

        if ((static_cast<int>(legs_stepped)) == 4) {
          legs_stepped = 0U;
          leg_reset_needed = false;
          if ((static_cast<int>(is_turning)) == 2) {
            is_turning = 0U;
          }
        }
      }

      //     %% walking forward section
    } else {
      bool guard1 = false;
      b_r_II_B_d[0] = r_II_B_d[0] - gamma_m[3];
      b_r_II_B_d[1] = r_II_B_d[1] - gamma_m[4];
      b_r_II_B_d[2] = r_II_B_d[2] - gamma_m[5];
      guard1 = false;
      if (coder::b_norm(b_r_II_B_d) >= 0.1) {
        guard1 = true;
      } else if ((static_cast<int>(step_state)) != 0) {
        guard1 = true;
      } else {
        b_r_II_c_FL[0] = r_II_c_FL[0];
        b_r_II_c_FL[1] = r_II_c_FR[0];
        b_r_II_c_FL[2] = r_II_c_BR[0];
        b_r_II_c_FL[3] = r_II_c_BL[0];
        c_r_II_c_FL[0] = r_II_c_FL[1];
        c_r_II_c_FL[1] = r_II_c_FR[1];
        c_r_II_c_FL[2] = r_II_c_BR[1];
        c_r_II_c_FL[3] = r_II_c_BL[1];
        if (!coder::inpolygon(gamma_m[3], gamma_m[4], b_r_II_c_FL, c_r_II_c_FL))
        {
          guard1 = true;
        } else {
          //  move with normal body pose controller
          rotz(Euler_d[0], b_dv);
          for (int b_i = 0; b_i < 3; b_i++) {
            double d18;
            double d19;
            double d20;
            double d21;
            double d22;
            double d23;
            r_II_B_d_temp[b_i] = r_II_B_d[b_i];
            d18 = b_dv[b_i];
            d19 = b_dv[b_i + 3];
            d20 = b_dv[b_i + 6];
            for (int i6 = 0; i6 < 3; i6++) {
              b_dv1[b_i + (3 * i6)] = ((d18 * T_I_B_d_tmp[3 * i6]) + (d19 *
                T_I_B_d_tmp[(3 * i6) + 1])) + (d20 * T_I_B_d_tmp[(3 * i6) + 2]);
            }

            d21 = b_dv1[b_i];
            d22 = b_dv1[b_i + 3];
            d23 = b_dv1[b_i + 6];
            for (int i11 = 0; i11 < 3; i11++) {
              b_dv[b_i + (3 * i11)] = ((d21 * b_T_I_B_d_tmp[3 * i11]) + (d22 *
                b_T_I_B_d_tmp[(3 * i11) + 1])) + (d23 * b_T_I_B_d_tmp[(3 * i11)
                + 2]);
            }
          }

          Body_Pose_Controller(r_II_c, b_dv, r_II_B_d_temp, r_II_B, floor_toggle,
                               Theta1_d, Theta2_d, Theta3_d);
        }
      }

      if (guard1) {
        //  determine direction of travel
        //  the direction of travel is computed at the very beginning or when
        //  the desired body position changes
        if (!waypoint_toggle) {
          startPoint[0] = gamma_m[3];
          endPoint[0] = r_II_B_d[0];
          startPoint[1] = gamma_m[4];
          endPoint[1] = r_II_B_d[1];
          startPoint[2] = gamma_m[5];
          endPoint[2] = r_II_B_d[2];
          waypoint_toggle = true;
        } else {
          bv[0] = (endPoint[0] != r_II_B_d[0]);
          bv[1] = (endPoint[1] != r_II_B_d[1]);
          bv[2] = (endPoint[2] != r_II_B_d[2]);
          waypoint_toggle = !coder::internal::ifWhileCond(bv);
        }

        //         %% leg stepping algorithm
        //  FR leg needs to step
        switch (leg_index) {
         case 1:
          legs_valid[0] = 0U;
          if ((static_cast<int>(reached_centroid)) == 0) {
            g_r_II_B[0] = r_II_B[0];
            g_r_II_B[1] = r_II_B[1];
            g_r_II_B[2] = r_II_B[2];
            find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL, g_r_II_B,
                           leg_index, &f_x, &f_y);
            r_II_B_d_temp[0] = f_x;
            r_II_B_d_temp[1] = f_y;
            r_II_B_d_temp[2] = r_II_B_d[2];
          }

          switch (step_state) {
           case 0:
            //  hasn't started stepping yet
            Theta1_d_midpt = 0.78539816339744828;
            Theta2_d_midpt = -0.78539816339744828;
            Theta3_d_midpt = 2.3561944901923448;
            step_state = 1U;
            r_II_c_FR_0[0] = r_II_c_FR[0];
            r_II_c_FR_0[1] = r_II_c_FR[1];
            r_II_c_FR_0[2] = r_II_c_FR[2];
            break;

           case 1:
            //  moving towards midpoint
            b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
            b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
            b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
            b_Theta1[0] -= Theta1_d_midpt;
            b_Theta1[1] -= Theta2_d_midpt;
            b_Theta1[2] -= Theta3_d_midpt;
            step_error = coder::b_norm(b_Theta1);
            if (step_error < 0.2) {
              //  reached midpoint
              step_state = 2U;
              step_planner_intelligent(startPoint, endPoint, r_II_c_FR_0, 0.12,
                r_II_c_dstep);
              r_II_c_current[0] = r_II_c_FR_0[0];
              r_II_c_current[1] = r_II_c_FR_0[1];
              r_II_c_current[2] = r_II_c_FR_0[2];
            }
            break;

           case 2:
            //  stepping towards goal now
            //                  step_error = norm(r_II_c_FR - r_II_c_dstep);
            if (r_II_c_FR[2] <= 0.0) {
              step_state = 0U;
              legs_valid[0] = 1U;
              leg_index = 0U;
              floor_toggle[0] = 1U;
              reached_centroid = 0U;
              reached_rest_centroid = 0U;
            }
            break;

           default:
            // no actions
            break;
          }
          break;

         case 2:
          legs_valid[1] = 0U;
          if ((static_cast<int>(reached_centroid)) == 0) {
            h_r_II_B[0] = r_II_B[0];
            h_r_II_B[1] = r_II_B[1];
            h_r_II_B[2] = r_II_B[2];
            find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL, h_r_II_B,
                           leg_index, &g_x, &g_y);
            r_II_B_d_temp[0] = g_x;
            r_II_B_d_temp[1] = g_y;
            r_II_B_d_temp[2] = r_II_B_d[2];
          }

          switch (step_state) {
           case 0:
            //  hasn't started stepping yet
            Theta1_d_midpt = -0.78539816339744828;
            Theta2_d_midpt = 0.78539816339744828;
            Theta3_d_midpt = -2.3561944901923448;
            step_state = 1U;
            r_II_c_FL_0[0] = r_II_c_FL[0];
            r_II_c_FL_0[1] = r_II_c_FL[1];
            r_II_c_FL_0[2] = r_II_c_FL[2];
            break;

           case 1:
            //  moving towards midpoint
            b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
            b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
            b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
            b_Theta1[0] -= Theta1_d_midpt;
            b_Theta1[1] -= Theta2_d_midpt;
            b_Theta1[2] -= Theta3_d_midpt;
            step_error = coder::b_norm(b_Theta1);
            if (step_error < 0.2) {
              //  reached midpoint
              step_state = 2U;
              step_planner_intelligent(startPoint, endPoint, r_II_c_FL_0, 0.12,
                r_II_c_dstep);
              r_II_c_current[0] = r_II_c_FL_0[0];
              r_II_c_current[1] = r_II_c_FL_0[1];
              r_II_c_current[2] = r_II_c_FL_0[2];
            }
            break;

           case 2:
            //  stepping towards goal now
            if (r_II_c_FL[2] <= 0.0) {
              step_state = 0U;
              legs_valid[1] = 1U;
              leg_index = 0U;
              floor_toggle[1] = 1U;
              reached_centroid = 0U;
              reached_rest_centroid = 0U;
            }
            break;

           default:
            // no actions
            break;
          }
          break;

         case 3:
          legs_valid[2] = 0U;
          if ((static_cast<int>(reached_centroid)) == 0) {
            i_r_II_B[0] = r_II_B[0];
            i_r_II_B[1] = r_II_B[1];
            i_r_II_B[2] = r_II_B[2];
            find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL, i_r_II_B,
                           leg_index, &h_x, &h_y);
            r_II_B_d_temp[0] = h_x;
            r_II_B_d_temp[1] = h_y;
            r_II_B_d_temp[2] = r_II_B_d[2];
          }

          switch (step_state) {
           case 0:
            //  hasn't started stepping yet
            Theta1_d_midpt = -0.78539816339744828;
            Theta2_d_midpt = -0.78539816339744828;
            Theta3_d_midpt = 2.3561944901923448;
            step_state = 1U;
            r_II_c_BR_0[0] = r_II_c_BR[0];
            r_II_c_BR_0[1] = r_II_c_BR[1];
            r_II_c_BR_0[2] = r_II_c_BR[2];
            break;

           case 1:
            //  moving towards midpoint
            b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
            b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
            b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
            b_Theta1[0] -= Theta1_d_midpt;
            b_Theta1[1] -= Theta2_d_midpt;
            b_Theta1[2] -= Theta3_d_midpt;
            step_error = coder::b_norm(b_Theta1);
            if (step_error < 0.2) {
              //  reached midpoint
              step_state = 2U;
              step_planner_intelligent(startPoint, endPoint, r_II_c_BR_0, 0.12,
                r_II_c_dstep);
              r_II_c_current[0] = r_II_c_BR_0[0];
              r_II_c_current[1] = r_II_c_BR_0[1];
              r_II_c_current[2] = r_II_c_BR_0[2];
            }
            break;

           case 2:
            //  stepping towards goal now
            if (r_II_c_BR[2] <= 0.0) {
              legs_valid[2] = 1U;
              step_state = 0U;
              leg_index = 0U;
              floor_toggle[2] = 1U;
              reached_centroid = 0U;
              reached_rest_centroid = 0U;
            }
            break;

           default:
            // no actions
            break;
          }
          break;

         case 4:
          legs_valid[3] = 0U;
          if ((static_cast<int>(reached_centroid)) == 0) {
            j_r_II_B[0] = r_II_B[0];
            j_r_II_B[1] = r_II_B[1];
            j_r_II_B[2] = r_II_B[2];
            find_pgon_goal(r_II_c_FR, r_II_c_FL, r_II_c_BR, r_II_c_BL, j_r_II_B,
                           leg_index, &i_x, &i_y);
            r_II_B_d_temp[0] = i_x;
            r_II_B_d_temp[1] = i_y;
            r_II_B_d_temp[2] = r_II_B_d[2];
          }

          switch (step_state) {
           case 0:
            //  hasn't started stepping yet
            Theta1_d_midpt = 0.78539816339744828;
            Theta2_d_midpt = 0.78539816339744828;
            Theta3_d_midpt = -2.3561944901923448;
            step_state = 1U;
            r_II_c_BL_0[0] = r_II_c_BL[0];
            r_II_c_BL_0[1] = r_II_c_BL[1];
            r_II_c_BL_0[2] = r_II_c_BL[2];
            break;

           case 1:
            //  moving towards midpoint
            b_Theta1[0] = Theta1[(static_cast<int>(leg_index)) - 1];
            b_Theta1[1] = Theta2[(static_cast<int>(leg_index)) - 1];
            b_Theta1[2] = Theta3[(static_cast<int>(leg_index)) - 1];
            b_Theta1[0] -= Theta1_d_midpt;
            b_Theta1[1] -= Theta2_d_midpt;
            b_Theta1[2] -= Theta3_d_midpt;
            step_error = coder::b_norm(b_Theta1);
            if (step_error < 0.2) {
              //  reached midpoint
              step_state = 2U;
              step_planner_intelligent(startPoint, endPoint, r_II_c_BL_0, 0.12,
                r_II_c_dstep);
              r_II_c_current[0] = r_II_c_BL_0[0];
              r_II_c_current[1] = r_II_c_BL_0[1];
              r_II_c_current[2] = r_II_c_BL_0[2];
            }
            break;

           case 2:
            //  stepping towards goal now
            if (r_II_c_BL[2] <= 0.0) {
              step_state = 0U;
              legs_valid[3] = 1U;
              leg_index = 0U;
              floor_toggle[3] = 1U;
              reached_centroid = 0U;
              reached_rest_centroid = 0U;
            }
            break;

           default:
            // no actions
            break;
          }
          break;

         default:
          // no actions
          break;
        }
      }
    }

    //  centroid moving/balance section, and commanding step (assigning thetad's) 
    switch (reached_rest_centroid) {
     case 0:
      //  needs to move back to resting 4-legged position to find new leg to move 
      b_r_II_c_FR[0] = r_II_c_FR[0];
      b_r_II_c_FR[1] = r_II_c_FL[0];
      b_r_II_c_FR[2] = r_II_c_BL[0];
      b_r_II_c_FR[3] = r_II_c_BR[0];
      c_r_II_c_FR[0] = r_II_c_FR[1];
      c_r_II_c_FR[1] = r_II_c_FL[1];
      c_r_II_c_FR[2] = r_II_c_BL[1];
      c_r_II_c_FR[3] = r_II_c_BR[1];
      centroid_codeGen(b_r_II_c_FR, c_r_II_c_FR, &e_x, &e_y);
      r_II_B_d_temp[0] = e_x;
      r_II_B_d_temp[1] = e_y;
      r_II_B_d_temp[2] = r_II_B_d[2];
      uv[0] = 1U;
      uv[1] = 1U;
      uv[2] = 1U;
      uv[3] = 1U;
      Body_Pose_Controller(r_II_c, T_I_B_d_temp, r_II_B_d_temp, r_II_B, uv,
                           Theta1_d, Theta2_d, Theta3_d);
      reached_rest_centroid = 2U;
      break;

     case 2:
      //  moving towards resting, or inbetween-step body pose
      b_r_II_B[0] = gamma_m[3] - r_II_B_d_temp[0];
      b_r_II_B[1] = gamma_m[4] - r_II_B_d_temp[1];
      b_r_II_B[2] = gamma_m[5] - r_II_B_d_temp[2];
      Body_Pose_Controller(r_II_c, T_I_B_d_temp, r_II_B_d_temp, r_II_B,
                           floor_toggle, Theta1_d, Theta2_d, Theta3_d);
      if (coder::b_norm(b_r_II_B) < 0.01) {
        reached_rest_centroid = 1U;
      }
      break;

     case 1:
      waypoint_toggle = false;

      //  rockback before step
      if (!coder::all(legs_valid)) {
        switch (reached_centroid) {
         case 0:
          //  hasn't started moving towards centroid yet
          Body_Pose_Controller(r_II_c, T_I_B_d_temp, r_II_B_d_temp, r_II_B,
                               floor_toggle, Theta1_d, Theta2_d, Theta3_d);
          reached_centroid = 2U;
          break;

         case 2:
          //  moving towards centroid
          r_II_B[0] = gamma_m[3] - r_II_B_d_temp[0];
          r_II_B[1] = gamma_m[4] - r_II_B_d_temp[1];
          r_II_B[2] = gamma_m[5] - r_II_B_d_temp[2];
          if (coder::b_norm(r_II_B) < 0.01) {
            reached_centroid = 1U;
          }
          break;

         case 1:
          //  step
          //  step leg
          Body_Pose_Controller(r_II_c, T_I_B_d_temp, r_II_B_d_temp, r_II_B,
                               floor_toggle, Theta1_d, Theta2_d, Theta3_d);
          if (((static_cast<int>(step_state)) == 1) && ((static_cast<int>
                (reached_centroid)) == 1)) {
            Theta1_d[(static_cast<int>(leg_index)) - 1] = Theta1_d_midpt;
            Theta2_d[(static_cast<int>(leg_index)) - 1] = Theta2_d_midpt;
            Theta3_d[(static_cast<int>(leg_index)) - 1] = Theta3_d_midpt;
          } else {
            switch (step_state) {
             case 2:
              Leg_Controller(r_II_c_dstep, r_II_c_current, T_I_B, r_II_B,
                             leg_index, &Theta1_d[(static_cast<int>(leg_index))
                             - 1], &Theta2_d[(static_cast<int>(leg_index)) - 1],
                             &Theta3_d[(static_cast<int>(leg_index)) - 1]);
              break;

             case 3:
              Theta1_d[(static_cast<int>(leg_index)) - 1] = Theta1_d_reset;
              Theta2_d[(static_cast<int>(leg_index)) - 1] = Theta2_d_reset;
              Theta3_d[(static_cast<int>(leg_index)) - 1] = Theta3_d_reset;
              break;

             default:
              // no actions
              break;
            }
          }

          if (step_error <= 0.03) {
            reached_centroid = 0U;
            reached_rest_centroid = 0U;
          }
          break;

         default:
          // no actions
          break;
        }
      } else {
        r_II_B_d_temp[0] = gamma_m[3];
        r_II_B_d_temp[1] = gamma_m[4];
        r_II_B_d_temp[2] = r_II_B_d[2];
        Body_Pose_Controller(r_II_c, T_I_B_d_temp, r_II_B_d_temp, r_II_B,
                             floor_toggle, Theta1_d, Theta2_d, Theta3_d);
      }
      break;

     default:
      // no actions
      break;
    }

    floor_toggle_out[0] = floor_toggle[0];
    legs_valid_out[0] = legs_valid[0];
    floor_toggle_out[1] = floor_toggle[1];
    legs_valid_out[1] = legs_valid[1];
    floor_toggle_out[2] = floor_toggle[2];
    legs_valid_out[2] = legs_valid[2];
    floor_toggle_out[3] = floor_toggle[3];
    legs_valid_out[3] = legs_valid[3];

    // Theta_d = [Theta1_d,Theta2_d,Theta3_d]; % output
    //  Euler_d = [phi_d_temp;theta_d;psi_d];
    *phi_d_temp_out = phi_d_temp;
    r_II_B_d_temp_out[0] = r_II_B_d_temp[0];
    r_II_B_d_temp_out[1] = r_II_B_d_temp[1];
    r_II_B_d_temp_out[2] = r_II_B_d_temp[2];
    Theta1_d_out[0] = Theta1_d[0];
    Theta2_d_out[0] = Theta2_d[0];
    Theta3_d_out[0] = Theta3_d[0];
    Theta1_d_out[1] = Theta1_d[1];
    Theta2_d_out[1] = Theta2_d[1];
    Theta3_d_out[1] = Theta3_d[1];
    Theta1_d_out[2] = Theta1_d[2];
    Theta2_d_out[2] = Theta2_d[2];
    Theta3_d_out[2] = Theta3_d[2];
    Theta1_d_out[3] = Theta1_d[3];
    Theta2_d_out[3] = Theta2_d[3];
    Theta3_d_out[3] = Theta3_d[3];
  }

  //
  // Controls Robot's walking algorithm
  //    input: r_II_B_d, Euler_d, gamma_m
  //    output: Theta_d (1-3), phi_d_temp & r_II_b_d_temp (orientation for plotting),
  //    floor_toggle & legs_valid (for computing forces)
  //    NOTE: For the real system, phi_d_temp & r_II_b_d_temp,
  //    floor_toggle & legs_valid can be thrown
  //    away. For kinematic system, floor_toggle is not needed. For dynamic
  //    system phi_d_temp % r_II_B_d_temp is not needed
  //    r_II_B_d = [x_d;y_d;z_d];
  //    Euler_d = [phi,theta,psi];
  //    gamma_m = [Euler,r_II_B,Theta1,Theta2,Theta3];
  //    Euler = [phi,theta,psi];
  //    r_II_B = [x,y,z];
  //    Theta1 = [Theta1FR,FL,BR,BL];
  //    Theta2 = [Theta2FR,FL,BR,BL];
  //    Theta3 = [Theta3FR,FL,BR,BL];
  // Arguments    : void
  // Return Type  : void
  //
  void Robot_Control_init()
  {
    waypoint_toggle = false;
    turn_toggle = false;
    step_state = 0U;
    turn_state = false;
    reached_centroid = 0U;
    reached_rest_centroid = 1U;
    step_needed = 1U;
    calc_manip = true;
    legs_valid[0] = 1U;
    legs_valid[1] = 1U;
    legs_valid[2] = 1U;
    legs_valid[3] = 1U;
    legs_stepped = 0U;
    leg_reset_needed = false;
    coder::eye(T_I_B_d_temp);
    phi_d_temp = 0.0;
    is_turning = 0U;
    leg_index = 0U;
    Theta1_d_midpt = 0.0;
    Theta2_d_midpt = 0.0;
    Theta3_d_midpt = 0.0;
    Theta1_d_reset = 0.0;
    Theta2_d_reset = 0.0;
    Theta3_d_reset = 0.0;
    r_II_c_BL_0[0] = 0.0;
    r_II_c_BR_0[0] = 0.0;
    r_II_c_FL_0[0] = 0.0;
    r_II_c_FR_0[0] = 0.0;
    r_II_B_d_temp[0] = 0.0;
    r_II_c_dstep[0] = 0.0;
    r_II_c_current[0] = 0.0;
    r_II_c_BL_0[1] = 0.0;
    r_II_c_BR_0[1] = 0.0;
    r_II_c_FL_0[1] = 0.0;
    r_II_c_FR_0[1] = 0.0;
    r_II_B_d_temp[1] = 0.0;
    r_II_c_dstep[1] = 0.0;
    r_II_c_current[1] = 0.0;
    r_II_c_BL_0[2] = 0.0;
    r_II_c_BR_0[2] = 0.0;
    r_II_c_FL_0[2] = 0.0;
    r_II_c_FR_0[2] = 0.0;
    r_II_B_d_temp[2] = 0.0;
    r_II_c_dstep[2] = 0.0;
    r_II_c_current[2] = 0.0;
    Theta1_d[0] = 0.0;
    Theta2_d[0] = 0.0;
    Theta3_d[0] = 0.0;
    manip_vec[0] = 0.0;
    Theta1_d[1] = 0.0;
    Theta2_d[1] = 0.0;
    Theta3_d[1] = 0.0;
    manip_vec[1] = 0.0;
    Theta1_d[2] = 0.0;
    Theta2_d[2] = 0.0;
    Theta3_d[2] = 0.0;
    manip_vec[2] = 0.0;
    Theta1_d[3] = 0.0;
    Theta2_d[3] = 0.0;
    Theta3_d[3] = 0.0;
    manip_vec[3] = 0.0;
  }

  //
  // Arguments    : void
  // Return Type  : void
  //
  void endPhi_not_empty_init()
  {
    endPhi_not_empty = false;
  }

  //
  // Arguments    : void
  // Return Type  : void
  //
  void endPoint_not_empty_init()
  {
    endPoint_not_empty = false;
  }

  //
  // Arguments    : void
  // Return Type  : void
  //
  void floor_toggle_not_empty_init()
  {
    floor_toggle_not_empty = false;
  }
}

//
// File trailer for Robot_Control.cpp
//
// [EOF]
//
