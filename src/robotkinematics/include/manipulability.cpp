//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: manipulability.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Mar-2021 14:19:13
//

// Include Files
#include "manipulability.h"
#include "contactJacobians.h"
#include "prod.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <cstring>

// Function Definitions
//
// Arguments    : double state[36]
//                double *muFR
//                double *muFL
//                double *muBR
//                double *muBL
// Return Type  : void
//
namespace Codegen
{
  void manipulability(double state[36], double *muFR, double *muFL, double *muBR,
                      double *muBL)
  {
    double unusedU1[324];
    double unusedU3[324];
    double unusedU5[324];
    double unusedU7[324];
    double GeoJc_BL[108];
    double GeoJc_BR[108];
    double GeoJc_FL[108];
    double GeoJc_FR[108];
    double SIG_BL[108];
    double SIG_BR[108];
    double SIG_FL[108];
    double SIG_FR[108];
    double unusedU0[36];
    double unusedU2[36];
    double unusedU4[36];
    double unusedU6[36];
    double sigBL[6];
    double sigBR[6];
    double sigFL[6];
    double sigFR[6];
    std::memset(&state[18], 0, 18U * (sizeof(double)));
    contactJacobians(state, GeoJc_FR, GeoJc_FL, GeoJc_BR, GeoJc_BL);

    //  Find SVD
    coder::svd(GeoJc_FR, unusedU0, SIG_FR, unusedU1);
    coder::svd(GeoJc_FL, unusedU2, SIG_FL, unusedU3);
    coder::svd(GeoJc_BR, unusedU4, SIG_BR, unusedU5);
    coder::svd(GeoJc_BL, unusedU6, SIG_BL, unusedU7);
    for (int ii = 0; ii < 6; ii++) {
      int sigFR_tmp;
      sigFR_tmp = ii + (6 * ii);
      sigFR[ii] = SIG_FR[sigFR_tmp];
      sigFL[ii] = SIG_FL[sigFR_tmp];
      sigBR[ii] = SIG_BR[sigFR_tmp];
      sigBL[ii] = SIG_BL[sigFR_tmp];
    }

    *muFR = coder::prod(sigFR);
    *muFL = coder::prod(sigFL);
    *muBR = coder::prod(sigBR);
    *muBL = coder::prod(sigBL);
  }
}

//
// File trailer for manipulability.cpp
//
// [EOF]
//
