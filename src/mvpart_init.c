#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
  Check these declarations against the C/Fortran source code.
*/
  
  /* .C calls */
  extern void formatg(void *, void *, void *, void *);
extern void gdistance(void *, void *, void *, void *, void *, void *);
extern void pred_rpart(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void rpartexp2(void *, void *, void *, void *);
extern void s_to_rp(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void s_to_rp2(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void s_xpred(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void xdists(void *, void *, void *, void *, void *, void *);

/* .Call calls */
  extern SEXP init_rpcallback(SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CMethodDef CEntries[] = {
  {"formatg",    (DL_FUNC) &formatg,     4},
  {"gdistance",  (DL_FUNC) &gdistance,   6},
  {"pred_rpart", (DL_FUNC) &pred_rpart, 13},
  {"rpartexp2",  (DL_FUNC) &rpartexp2,   4},
  {"s_to_rp",    (DL_FUNC) &s_to_rp,    16},
  {"s_to_rp2",   (DL_FUNC) &s_to_rp2,   14},
  {"s_xpred",    (DL_FUNC) &s_xpred,    18},
  {"xdists",     (DL_FUNC) &xdists,      6},
  {NULL, NULL, 0}
};

static const R_CallMethodDef CallEntries[] = {
  {"init_rpcallback", (DL_FUNC) &init_rpcallback, 5},
  {NULL, NULL, 0}
};

void R_init_mvpart(DllInfo *dll)
{
  R_registerRoutines(dll, CEntries, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}