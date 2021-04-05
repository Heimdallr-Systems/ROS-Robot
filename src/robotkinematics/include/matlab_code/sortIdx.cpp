//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "sortIdx.h"
#include "isnan.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace Codegen
{
  static int asr_s32(int u, unsigned int n);
  namespace coder
  {
    namespace internal
    {
      static void merge(int idx[4], double x[4], int offset, int np, int nq, int
                        iwork[4], double xwork[4]);
      static void merge_block(int idx[4], double x[4], int offset, int n, int
        preSortLevel, int iwork[4], double xwork[4]);
    }
  }
}

// Function Definitions
//
// Arguments    : int u
//                unsigned int n
// Return Type  : int
//
namespace Codegen
{
  static int asr_s32(int u, unsigned int n)
  {
    int y;
    if (u >= 0) {
      y = static_cast<int>(static_cast<unsigned int>((static_cast<unsigned int>
        (u)) >> (static_cast<unsigned long>(n))));
    } else {
      y = (-(static_cast<int>(static_cast<unsigned int>((static_cast<unsigned
               int>(static_cast<int>(-1 - u))) >> (static_cast<unsigned long>(n))))))
        - 1;
    }

    return y;
  }

  //
  // Arguments    : int idx[4]
  //                double x[4]
  //                int offset
  //                int np
  //                int nq
  //                int iwork[4]
  //                double xwork[4]
  // Return Type  : void
  //
  namespace coder
  {
    namespace internal
    {
      static void merge(int idx[4], double x[4], int offset, int np, int nq, int
                        iwork[4], double xwork[4])
      {
        if ((np != 0) && (nq != 0)) {
          int iout;
          int n_tmp;
          int p;
          int q;
          n_tmp = np + nq;
          for (int j = 0; j < n_tmp; j++) {
            int i;
            i = offset + j;
            iwork[j] = idx[i];
            xwork[j] = x[i];
          }

          p = 0;
          q = np;
          iout = offset - 1;
          int exitg1;
          do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
              idx[iout] = iwork[p];
              x[iout] = xwork[p];
              if ((p + 1) < np) {
                p++;
              } else {
                exitg1 = 1;
              }
            } else {
              idx[iout] = iwork[q];
              x[iout] = xwork[q];
              if ((q + 1) < n_tmp) {
                q++;
              } else {
                int offset1;
                offset1 = iout - p;
                for (int b_j = p + 1; b_j <= np; b_j++) {
                  int i1;
                  i1 = offset1 + b_j;
                  idx[i1] = iwork[b_j - 1];
                  x[i1] = xwork[b_j - 1];
                }

                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
      }

      //
      // Arguments    : int idx[4]
      //                double x[4]
      //                int offset
      //                int n
      //                int preSortLevel
      //                int iwork[4]
      //                double xwork[4]
      // Return Type  : void
      //
      static void merge_block(int idx[4], double x[4], int offset, int n, int
        preSortLevel, int iwork[4], double xwork[4])
      {
        int bLen;
        int nBlocks;
        nBlocks = asr_s32(n, static_cast<unsigned int>(preSortLevel));
        bLen = (1 << (static_cast<unsigned long>(preSortLevel)));
        while (nBlocks > 1) {
          int bLen2;
          int nPairs;
          if ((nBlocks & 1) != 0) {
            int nTail;
            int tailOffset;
            nBlocks--;
            tailOffset = bLen * nBlocks;
            nTail = n - tailOffset;
            if (nTail > bLen) {
              merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                    xwork);
            }
          }

          bLen2 = bLen * 2;
          nPairs = asr_s32(nBlocks, 1U);
          for (int k = 0; k < nPairs; k++) {
            merge(idx, x, offset + (k * bLen2), bLen, bLen, iwork, xwork);
          }

          bLen = bLen2;
          nBlocks = nPairs;
        }

        if (n > bLen) {
          merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
        }
      }

      //
      // Arguments    : double x[4]
      //                int idx[4]
      // Return Type  : void
      //
      void sortIdx(double x[4], int idx[4])
      {
        double x4[4];
        double xwork[4];
        int iwork[4];
        int ib;
        int m;
        int nNaNs;
        signed char idx4[4];
        signed char perm[4];
        idx[0] = 0;
        x4[0] = 0.0;
        idx4[0] = 0;
        xwork[0] = 0.0;
        idx[1] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        xwork[1] = 0.0;
        idx[2] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        xwork[2] = 0.0;
        idx[3] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        xwork[3] = 0.0;
        nNaNs = -3;
        ib = -1;
        if (b_isnan(x[0])) {
          idx[3] = 1;
          xwork[3] = x[0];
          nNaNs = -2;
        } else {
          ib = 0;
          idx4[0] = 1;
          x4[0] = x[0];
        }

        if (b_isnan(x[1])) {
          idx[-nNaNs] = 2;
          xwork[-nNaNs] = x[1];
          nNaNs++;
        } else {
          ib++;
          idx4[ib] = 2;
          x4[ib] = x[1];
        }

        if (b_isnan(x[2])) {
          idx[-nNaNs] = 3;
          xwork[-nNaNs] = x[2];
          nNaNs++;
        } else {
          ib++;
          idx4[ib] = 3;
          x4[ib] = x[2];
        }

        if (b_isnan(x[3])) {
          idx[-nNaNs] = 4;
          xwork[-nNaNs] = x[3];
          nNaNs++;
        } else {
          ib++;
          idx4[ib] = 4;
          x4[ib] = x[3];
          if ((ib + 1) == 4) {
            double d;
            double d1;
            int i1;
            int i2;
            int i3;
            int i4;
            if (x4[0] <= x4[1]) {
              i1 = 1;
              i2 = 2;
            } else {
              i1 = 2;
              i2 = 1;
            }

            if (x4[2] <= x4[3]) {
              i3 = 3;
              i4 = 4;
            } else {
              i3 = 4;
              i4 = 3;
            }

            d = x4[i1 - 1];
            d1 = x4[i3 - 1];
            if (d <= d1) {
              double d3;
              d3 = x4[i2 - 1];
              if (d3 <= d1) {
                perm[0] = static_cast<signed char>(i1);
                perm[1] = static_cast<signed char>(i2);
                perm[2] = static_cast<signed char>(i3);
                perm[3] = static_cast<signed char>(i4);
              } else if (d3 <= x4[i4 - 1]) {
                perm[0] = static_cast<signed char>(i1);
                perm[1] = static_cast<signed char>(i3);
                perm[2] = static_cast<signed char>(i2);
                perm[3] = static_cast<signed char>(i4);
              } else {
                perm[0] = static_cast<signed char>(i1);
                perm[1] = static_cast<signed char>(i3);
                perm[2] = static_cast<signed char>(i4);
                perm[3] = static_cast<signed char>(i2);
              }
            } else {
              double d2;
              d2 = x4[i4 - 1];
              if (d <= d2) {
                if (x4[i2 - 1] <= d2) {
                  perm[0] = static_cast<signed char>(i3);
                  perm[1] = static_cast<signed char>(i1);
                  perm[2] = static_cast<signed char>(i2);
                  perm[3] = static_cast<signed char>(i4);
                } else {
                  perm[0] = static_cast<signed char>(i3);
                  perm[1] = static_cast<signed char>(i1);
                  perm[2] = static_cast<signed char>(i4);
                  perm[3] = static_cast<signed char>(i2);
                }
              } else {
                perm[0] = static_cast<signed char>(i3);
                perm[1] = static_cast<signed char>(i4);
                perm[2] = static_cast<signed char>(i1);
                perm[3] = static_cast<signed char>(i2);
              }
            }

            idx[-(nNaNs + 3)] = static_cast<int>(idx4[perm[0] - 1]);
            idx[-(nNaNs + 2)] = static_cast<int>(idx4[perm[1] - 1]);
            idx[-(nNaNs + 1)] = static_cast<int>(idx4[perm[2] - 1]);
            idx[-nNaNs] = static_cast<int>(idx4[perm[3] - 1]);
            x[-(nNaNs + 3)] = x4[perm[0] - 1];
            x[-(nNaNs + 2)] = x4[perm[1] - 1];
            x[-(nNaNs + 1)] = x4[perm[2] - 1];
            x[-nNaNs] = x4[perm[3] - 1];
            ib = -1;
          }
        }

        if ((ib + 1) > 0) {
          perm[1] = 0;
          perm[2] = 0;
          perm[3] = 0;
          switch (ib + 1) {
           case 1:
            perm[0] = 1;
            break;

           case 2:
            if (x4[0] <= x4[1]) {
              perm[0] = 1;
              perm[1] = 2;
            } else {
              perm[0] = 2;
              perm[1] = 1;
            }
            break;

           default:
            if (x4[0] <= x4[1]) {
              if (x4[1] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 2;
                perm[2] = 3;
              } else if (x4[0] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 3;
                perm[2] = 2;
              } else {
                perm[0] = 3;
                perm[1] = 1;
                perm[2] = 2;
              }
            } else if (x4[0] <= x4[2]) {
              perm[0] = 2;
              perm[1] = 1;
              perm[2] = 3;
            } else if (x4[1] <= x4[2]) {
              perm[0] = 2;
              perm[1] = 3;
              perm[2] = 1;
            } else {
              perm[0] = 3;
              perm[1] = 2;
              perm[2] = 1;
            }
            break;
          }

          for (int b_k = 0; b_k <= ib; b_k++) {
            int b_idx_tmp;
            int idx_tmp;
            idx_tmp = (static_cast<int>(perm[b_k])) - 1;
            b_idx_tmp = (b_k - nNaNs) - ib;
            idx[b_idx_tmp] = static_cast<int>(idx4[idx_tmp]);
            x[b_idx_tmp] = x4[idx_tmp];
          }
        }

        m = asr_s32(nNaNs + 3, 1U) + 1;
        for (int k = 0; k <= (m - 2); k++) {
          int itmp;
          int itmp_tmp;
          itmp_tmp = (k - nNaNs) + 1;
          itmp = idx[itmp_tmp];
          idx[itmp_tmp] = idx[3 - k];
          idx[3 - k] = itmp;
          x[itmp_tmp] = xwork[3 - k];
          x[3 - k] = xwork[itmp_tmp];
        }

        if (((nNaNs + 3) & 1) != 0) {
          int i;
          i = m - nNaNs;
          x[i] = xwork[i];
        }

        if ((1 - nNaNs) > 1) {
          iwork[0] = 0;
          iwork[1] = 0;
          iwork[2] = 0;
          iwork[3] = 0;
          merge_block(idx, x, 0, 1 - nNaNs, 2, iwork, xwork);
        }
      }
    }
  }
}

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
