//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzsvdc.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 12-Apr-2021 14:32:25
//

// Include Files
#include "xzsvdc.h"
#include "Robot_Control_types.h"
#include "abs.h"
#include "sqrt.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xscal.h"
#include "xswap.h"
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
namespace Codegen {
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

}

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
namespace Codegen {
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "SVD fails to converge";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : double A[108]
//                double U[36]
//                double S[6]
//                double V[324]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzsvdc(double A[108], double U[36], double S[6], double V[324])
{
  static rtRunTimeErrorInfo b_emlrtRTEI = {
      269,      // lineNo
      13,       // colNo
      "xzsvdc", // fName
      "D:\\Program "
      "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
      "reflapack\\xzsvdc.m" // pName
  };
  double e[18];
  double s[7];
  double work[6];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double cs;
  double d_cs;
  double d_sn;
  double f;
  double rt;
  double shift;
  double sn;
  double snorm;
  double t;
  int iter;
  int m;
  int qjj;
  int qp1;
  int qq;
  bool exitg1;
  for (int i = 0; i < 7; i++) {
    s[i] = 0.0;
  }
  (void)std::memset(&e[0], 0, 18U * (sizeof(double)));
  for (int b_i = 0; b_i < 6; b_i++) {
    work[b_i] = 0.0;
  }
  (void)std::memset(&U[0], 0, 36U * (sizeof(double)));
  (void)std::memset(&V[0], 0, 324U * (sizeof(double)));
  for (int q = 0; q < 6; q++) {
    double nrm;
    int qq_tmp;
    bool apply_transform;
    qp1 = q + 2;
    qq_tmp = q + (6 * q);
    qq = qq_tmp + 1;
    apply_transform = false;
    if ((q + 1) <= 5) {
      nrm = blas::xnrm2(6 - q, A, qq_tmp + 1);
      if (nrm > 0.0) {
        double d;
        apply_transform = true;
        if (A[qq_tmp] < 0.0) {
          d = -nrm;
          s[q] = -nrm;
        } else {
          d = nrm;
          s[q] = nrm;
        }
        if (b_abs(d) >= 1.0020841800044864E-292) {
          blas::xscal(6 - q, 1.0 / d, A, qq_tmp + 1);
        } else {
          int b;
          b = (qq_tmp - q) + 6;
          for (int k = qq; k <= b; k++) {
            A[k - 1] /= s[q];
          }
        }
        A[qq_tmp]++;
        s[q] = -s[q];
      } else {
        s[q] = 0.0;
      }
    }
    for (int jj = qp1; jj < 19; jj++) {
      qjj = q + (6 * (jj - 1));
      if (apply_transform) {
        t = blas::xdotc(6 - q, A, qq_tmp + 1, A, qjj + 1);
        t = -(t / A[qq_tmp]);
        blas::xaxpy(6 - q, t, qq_tmp + 1, A, qjj + 1);
      }
      e[jj - 1] = A[qjj];
    }
    if ((q + 1) <= 5) {
      for (int b_ii = q + 1; b_ii < 7; b_ii++) {
        int U_tmp;
        U_tmp = (b_ii + (6 * q)) - 1;
        U[U_tmp] = A[U_tmp];
      }
    }
    nrm = blas::b_xnrm2(17 - q, e, q + 2);
    if (nrm == 0.0) {
      e[q] = 0.0;
    } else {
      double a;
      if (e[q + 1] < 0.0) {
        e[q] = -nrm;
      } else {
        e[q] = nrm;
      }
      a = e[q];
      if (b_abs(e[q]) >= 1.0020841800044864E-292) {
        blas::b_xscal(17 - q, 1.0 / e[q], e, q + 2);
      } else {
        for (int b_k = qp1; b_k < 19; b_k++) {
          e[b_k - 1] /= a;
        }
      }
      e[q + 1]++;
      e[q] = -e[q];
      if ((q + 2) <= 6) {
        for (int i_ii = qp1; i_ii < 7; i_ii++) {
          work[i_ii - 1] = 0.0;
        }
        for (int d_jj = qp1; d_jj < 19; d_jj++) {
          blas::xaxpy(5 - q, e[d_jj - 1], A, (q + (6 * (d_jj - 1))) + 2, work,
                      q + 2);
        }
        for (int e_jj = qp1; e_jj < 19; e_jj++) {
          blas::b_xaxpy(5 - q, (-e[e_jj - 1]) / e[q + 1], work, q + 2, A,
                        (q + (6 * (e_jj - 1))) + 2);
        }
      }
    }
    for (int e_ii = qp1; e_ii < 19; e_ii++) {
      V[(e_ii + (18 * q)) - 1] = e[e_ii - 1];
    }
  }
  m = 5;
  s[5] = A[35];
  s[6] = 0.0;
  e[6] = 0.0;
  for (int ii = 0; ii < 6; ii++) {
    U[ii + 30] = 0.0;
  }
  U[35] = 1.0;
  for (int b_q = 4; b_q >= 0; b_q--) {
    qp1 = b_q + 2;
    qq = b_q + (6 * b_q);
    if (s[b_q] != 0.0) {
      for (int b_jj = qp1; b_jj < 7; b_jj++) {
        qjj = (b_q + (6 * (b_jj - 1))) + 1;
        t = blas::b_xdotc(6 - b_q, U, qq + 1, U, qjj);
        t = -(t / U[qq]);
        blas::b_xaxpy(6 - b_q, t, qq + 1, U, qjj);
      }
      for (int d_ii = b_q + 1; d_ii < 7; d_ii++) {
        int b_U_tmp;
        b_U_tmp = (d_ii + (6 * b_q)) - 1;
        U[b_U_tmp] = -U[b_U_tmp];
      }
      U[qq]++;
      for (int g_ii = 0; g_ii < b_q; g_ii++) {
        U[g_ii + (6 * b_q)] = 0.0;
      }
    } else {
      for (int c_ii = 0; c_ii < 6; c_ii++) {
        U[c_ii + (6 * b_q)] = 0.0;
      }
      U[qq] = 1.0;
    }
  }
  for (int c_q = 17; c_q >= 0; c_q--) {
    if (((c_q + 1) <= 6) && (e[c_q] != 0.0)) {
      int qp1q;
      qp1 = c_q + 2;
      qp1q = (c_q + (18 * c_q)) + 2;
      for (int c_jj = qp1; c_jj < 19; c_jj++) {
        int qp1jj;
        qp1jj = (c_q + (18 * (c_jj - 1))) + 2;
        t = blas::c_xdotc(17 - c_q, V, qp1q, V, qp1jj);
        t = -(t / V[qp1q - 1]);
        blas::c_xaxpy(17 - c_q, t, qp1q, V, qp1jj);
      }
    }
    (void)std::memset(&V[c_q * 18], 0, 18U * (sizeof(double)));
    V[c_q + (18 * c_q)] = 1.0;
  }
  for (int d_q = 0; d_q < 7; d_q++) {
    double d1;
    double r;
    d1 = s[d_q];
    if (d1 != 0.0) {
      rt = b_abs(d1);
      r = d1 / rt;
      s[d_q] = rt;
      if ((d_q + 1) < 7) {
        e[d_q] /= r;
      }
      if ((d_q + 1) <= 6) {
        blas::xscal(r, U, (6 * d_q) + 1);
      }
    }
    if (((d_q + 1) < 7) && (e[d_q] != 0.0)) {
      rt = b_abs(e[d_q]);
      r = rt / e[d_q];
      e[d_q] = rt;
      s[d_q + 1] *= r;
      blas::b_xscal(r, V, (18 * (d_q + 1)) + 1);
    }
  }
  iter = 0;
  snorm = 0.0;
  for (int f_ii = 0; f_ii < 7; f_ii++) {
    double u0;
    double u1;
    double y;
    u0 = b_abs(s[f_ii]);
    u1 = b_abs(e[f_ii]);
    if (u0 > u1) {
      y = u0;
    } else {
      y = u1;
    }
    if (snorm <= y) {
      snorm = y;
    }
  }
  exitg1 = false;
  while ((!exitg1) && ((m + 2) > 0)) {
    if (iter >= 75) {
      b_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
    } else {
      int e_q;
      int h_ii;
      int kase;
      h_ii = m;
      int exitg2;
      do {
        exitg2 = 0;
        e_q = h_ii + 1;
        if ((h_ii + 1) == 0) {
          exitg2 = 1;
        } else {
          double ztest0;
          ztest0 = b_abs(e[h_ii]);
          if (ztest0 <= (2.2204460492503131E-16 *
                         (b_abs(s[h_ii]) + b_abs(s[h_ii + 1])))) {
            e[h_ii] = 0.0;
            exitg2 = 1;
          } else if ((ztest0 <= 1.0020841800044864E-292) ||
                     ((iter > 20) &&
                      (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
            e[h_ii] = 0.0;
            exitg2 = 1;
          } else {
            h_ii--;
          }
        }
      } while (exitg2 == 0);
      if ((h_ii + 1) == (m + 1)) {
        kase = 4;
      } else {
        int j_ii;
        int qs;
        bool exitg3;
        qs = m + 2;
        j_ii = m + 2;
        exitg3 = false;
        while ((!exitg3) && (j_ii >= (h_ii + 1))) {
          qs = j_ii;
          if (j_ii == (h_ii + 1)) {
            exitg3 = true;
          } else {
            double test;
            double ztest;
            test = 0.0;
            if (j_ii < (m + 2)) {
              test = b_abs(e[j_ii - 1]);
            }
            if (j_ii > (h_ii + 2)) {
              test += b_abs(e[j_ii - 2]);
            }
            ztest = b_abs(s[j_ii - 1]);
            if ((ztest <= (2.2204460492503131E-16 * test)) ||
                (ztest <= 1.0020841800044864E-292)) {
              s[j_ii - 1] = 0.0;
              exitg3 = true;
            } else {
              j_ii--;
            }
          }
        }
        if (qs == (h_ii + 1)) {
          kase = 3;
        } else if (qs == (m + 2)) {
          kase = 1;
        } else {
          kase = 2;
          e_q = qs;
        }
      }
      switch (kase) {
      case 1: {
        int b_a;
        f = e[m];
        e[m] = 0.0;
        b_a = m + 1;
        for (int e_k = b_a; e_k >= (e_q + 1); e_k--) {
          blas::xrotg(&s[e_k - 1], &f, &cs, &sn);
          if (e_k > (e_q + 1)) {
            double b_f_tmp;
            b_f_tmp = e[e_k - 2];
            f = (-sn) * b_f_tmp;
            e[e_k - 2] = b_f_tmp * cs;
          }
          blas::xrot(V, (18 * (e_k - 1)) + 1, (18 * (m + 1)) + 1, cs, sn);
        }
      } break;
      case 2: {
        f = e[e_q - 1];
        e[e_q - 1] = 0.0;
        for (int d_k = e_q + 1; d_k <= (m + 2); d_k++) {
          double f_tmp;
          a__1 = f;
          blas::xrotg(&s[d_k - 1], &a__1, &b_cs, &b_sn);
          f_tmp = e[d_k - 1];
          f = (-b_sn) * f_tmp;
          e[d_k - 1] = f_tmp * b_cs;
          blas::b_xrot(U, (6 * (d_k - 1)) + 1, (6 * (e_q - 1)) + 1, b_cs, b_sn);
        }
      } break;
      case 3: {
        double b_b;
        double b_u0;
        double b_u1;
        double b_y;
        double c;
        double c_u1;
        double c_y;
        double d_u1;
        double d_y;
        double e_u1;
        double emm1;
        double g;
        double scale;
        double scale_tmp;
        double sm;
        double smm1;
        double sqds;
        int mm1;
        mm1 = m + 1;
        scale_tmp = s[m + 1];
        b_u0 = b_abs(scale_tmp);
        b_u1 = b_abs(s[m]);
        if (b_u0 > b_u1) {
          b_y = b_u0;
        } else {
          b_y = b_u1;
        }
        c_u1 = b_abs(e[m]);
        if (b_y > c_u1) {
          c_y = b_y;
        } else {
          c_y = c_u1;
        }
        d_u1 = b_abs(s[e_q]);
        if (c_y > d_u1) {
          d_y = c_y;
        } else {
          d_y = d_u1;
        }
        e_u1 = b_abs(e[e_q]);
        if (d_y > e_u1) {
          scale = d_y;
        } else {
          scale = e_u1;
        }
        sm = scale_tmp / scale;
        smm1 = s[m] / scale;
        emm1 = e[m] / scale;
        sqds = s[e_q] / scale;
        b_b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
        c = sm * emm1;
        c *= c;
        if ((b_b != 0.0) || (c != 0.0)) {
          shift = (b_b * b_b) + c;
          b_sqrt(&shift);
          if (b_b < 0.0) {
            shift = -shift;
          }
          shift = c / (b_b + shift);
        } else {
          shift = 0.0;
        }
        f = ((sqds + sm) * (sqds - sm)) + shift;
        g = sqds * (e[e_q] / scale);
        for (int f_k = e_q + 1; f_k <= mm1; f_k++) {
          double c_f_tmp;
          double f_tmp_tmp;
          b_f = f;
          a__2 = g;
          blas::xrotg(&b_f, &a__2, &c_cs, &c_sn);
          if (f_k > (e_q + 1)) {
            e[f_k - 2] = b_f;
          }
          f_tmp_tmp = e[f_k - 1];
          c_f_tmp = s[f_k - 1];
          e[f_k - 1] = (c_cs * f_tmp_tmp) - (c_sn * c_f_tmp);
          a__3 = c_sn * s[f_k];
          s[f_k] *= c_cs;
          blas::xrot(V, (18 * (f_k - 1)) + 1, (18 * f_k) + 1, c_cs, c_sn);
          s[f_k - 1] = (c_cs * c_f_tmp) + (c_sn * f_tmp_tmp);
          blas::xrotg(&s[f_k - 1], &a__3, &d_cs, &d_sn);
          f = (d_cs * e[f_k - 1]) + (d_sn * s[f_k]);
          s[f_k] = ((-d_sn) * e[f_k - 1]) + (d_cs * s[f_k]);
          g = d_sn * e[f_k];
          e[f_k] *= d_cs;
          if (f_k < 6) {
            blas::b_xrot(U, (6 * (f_k - 1)) + 1, (6 * f_k) + 1, d_cs, d_sn);
          }
        }
        e[m] = f;
        iter++;
      } break;
      default:
        if (s[e_q] < 0.0) {
          s[e_q] = -s[e_q];
          blas::b_xscal(-1.0, V, (18 * e_q) + 1);
        }
        qp1 = e_q + 1;
        while (((e_q + 1) < 7) && (s[e_q] < s[qp1])) {
          rt = s[e_q];
          s[e_q] = s[qp1];
          s[qp1] = rt;
          blas::xswap(V, (18 * e_q) + 1, (18 * (e_q + 1)) + 1);
          if ((e_q + 1) < 6) {
            blas::b_xswap(U, (6 * e_q) + 1, (6 * (e_q + 1)) + 1);
          }
          e_q = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  for (int c_k = 0; c_k < 6; c_k++) {
    S[c_k] = s[c_k];
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xzsvdc.cpp
//
// [EOF]
//
