/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Robot_Control_api.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 17-Mar-2021 14:19:13
 */

/* Include Files */
#include "_coder_Robot_Control_api.h"
#include "_coder_Robot_Control_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "Robot_Control",                     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Euler_d,
  const char_T *identifier))[3];
static const mxArray *c_emlrt_marshallOut(const real_T u[3]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static const mxArray *d_emlrt_marshallOut(const uint8_T u[4]);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gamma_m,
  const char_T *identifier))[36];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *r_II_B_d,
  const char_T *identifier))[3];
static const mxArray *emlrt_marshallOut(const real_T u[4]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[36];
static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *init_toggle, const char_T *identifier);
static boolean_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[36];
static boolean_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Euler_d
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Euler_d,
  const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(Euler_d), &thisId);
  emlrtDestroyArray(&Euler_d);
  return y;
}
/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
  static const mxArray *c_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 3 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], (int32_T)mxDOUBLE_CLASS, (int32_T)
    mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const uint8_T u[4]
 * Return Type  : const mxArray *
 */
  static const mxArray *d_emlrt_marshallOut(const uint8_T u[4])
{
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 1, 4 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], (int32_T)mxUINT8_CLASS, (int32_T)mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  emlrtSetDimensions((mxArray *)m, iv1, 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *gamma_m
 *                const char_T *identifier
 * Return Type  : real_T (*)[36]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gamma_m,
  const char_T *identifier))[36]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[36];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(gamma_m), &thisId);
  emlrtDestroyArray(&gamma_m);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *r_II_B_d
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *r_II_B_d,
  const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(r_II_B_d), &thisId);
  emlrtDestroyArray(&r_II_B_d);
  return y;
}

/*
 * Arguments    : const real_T u[4]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[4])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 4 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], (int32_T)mxDOUBLE_CLASS, (int32_T)
    mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[36]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[36]
{
  real_T (*y)[36];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *init_toggle
 *                const char_T *identifier
 * Return Type  : boolean_T
 */
  static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *init_toggle, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(init_toggle), &thisId);
  emlrtDestroyArray(&init_toggle);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : boolean_T
 */
static boolean_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[1] = { 3 };

  real_T (*ret)[3];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2] = { 1, 3 };

  real_T (*ret)[3];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[36]
 */
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[36]
{
  static const int32_T dims[1] = { 36 };

  real_T (*ret)[36];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[36])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T
 */
  static boolean_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[7]
 * Return Type  : void
 */
void Robot_Control_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[7])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T (*gamma_m)[36];
  real_T (*Theta1_d_out)[4];
  real_T (*Theta2_d_out)[4];
  real_T (*Theta3_d_out)[4];
  real_T (*Euler_d)[3];
  real_T (*r_II_B_d)[3];
  real_T (*r_II_B_d_temp_out)[3];
  real_T phi_d_temp_out;
  uint8_T (*floor_toggle_out)[4];
  uint8_T (*legs_valid_out)[4];
  boolean_T init_toggle;
  st.tls = emlrtRootTLSGlobal;
  Theta1_d_out = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));
  Theta2_d_out = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));
  Theta3_d_out = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));
  r_II_B_d_temp_out = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  floor_toggle_out = (uint8_T (*)[4])mxMalloc(sizeof(uint8_T [4]));
  legs_valid_out = (uint8_T (*)[4])mxMalloc(sizeof(uint8_T [4]));

  /* Marshall function inputs */
  r_II_B_d = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "r_II_B_d");
  Euler_d = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Euler_d");
  gamma_m = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "gamma_m");
  init_toggle = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "init_toggle");

  /* Invoke the target function */
  Robot_Control(*r_II_B_d, *Euler_d, *gamma_m, init_toggle, *Theta1_d_out,
                *Theta2_d_out, *Theta3_d_out, &phi_d_temp_out,
                *r_II_B_d_temp_out, *floor_toggle_out, *legs_valid_out);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*Theta1_d_out);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*Theta2_d_out);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*Theta3_d_out);
  }

  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(phi_d_temp_out);
  }

  if (nlhs > 4) {
    plhs[4] = c_emlrt_marshallOut(*r_II_B_d_temp_out);
  }

  if (nlhs > 5) {
    plhs[5] = d_emlrt_marshallOut(*floor_toggle_out);
  }

  if (nlhs > 6) {
    plhs[6] = d_emlrt_marshallOut(*legs_valid_out);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Robot_Control_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  Robot_Control_xil_terminate();
  Robot_Control_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Robot_Control_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Robot_Control_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_Robot_Control_api.c
 *
 * [EOF]
 */
