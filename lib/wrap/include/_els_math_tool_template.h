#ifndef _Q
    #error _Q should be defined before using template
#endif  // _Q
#ifndef _POSTFIX
    #error _POSTFIX should be defined before template
#endif  // _POSTFIX

#define __CCAT(x, y)        __CCAT2(x, y)
#define __CCAT2(x, y)       x##y
#define __FUNC(name)        __CCAT(name, _POSTFIX)
#define __STRUCT(name)      __CCAT(name, _POSTFIX)


#include "els.h"
#include "els_math.h"


#ifdef _DECLARE_CODE


/**interpolate
 */
static inline _iq(_Q)
__FUNC(els_interpolate_2d)(const _iq(_Q) x1, const _iq(_Q) y1,
                           const _iq(_Q) x2, const _iq(_Q) y2,
                           const _iq(_Q) x)
{
    const _iq(_Q) num = _IQmpy(_Q, x1, y2) \
                        - _IQmpy(_Q, x2, y1) \
                        + _IQmpy(_Q, x, (y1 - y2));
    _iq(_Q) den = x1 - x2;
    if (den == _IQ(_Q, 0.F)) {
        den = MIN_IQ_POS;
    }
    return _IQdiv(_Q, num, den);
}


/**power invarient clarke transform and inverse
 */
static inline void
__FUNC(els_clarke)(const _iq(_Q) u, const _iq(_Q) v, const _iq(_Q) w,
		    	   _iq(_Q) *alpha, _iq(_Q) *beta)
{
	*alpha = _IQmpy(_Q, CONST_1_SQRT6(_Q), (_IQmpy2(u) - v - w));
	*beta = _IQmpy(_Q, CONST_1_SQRT2(_Q), (v - w));
}

static inline void
__FUNC(els_iclarke)(const _iq(_Q) alpha, const _iq(_Q) beta,
				   _iq(_Q) *u, _iq(_Q) *v, _iq(_Q) *w)
{
	*u = _IQmpy(_Q, CONST_SQRT2_SQRT3(_Q), alpha);
	*v = _IQmpy(_Q, -CONST_1_SQRT6(_Q), alpha) + _IQmpy(_Q, CONST_1_SQRT2(_Q), beta);
	*w = _IQmpy(_Q, -CONST_1_SQRT6(_Q), alpha) - _IQmpy(_Q, CONST_1_SQRT2(_Q), beta);
}

static inline void
__FUNC(els_park)(const _iq(_Q) alpha, const _iq(_Q) beta,
				 const _iq(30) sin, const _iq(30) cos,
				 _iq(_Q) *d, _iq(_Q) *q)
{
	*d = _IQmpyIQX(_Q, alpha, _Q, cos, Q30) + _IQmpyIQX(_Q, beta, _Q, sin, Q30);
	*q = _IQmpyIQX(_Q, beta, _Q, cos, Q30) - _IQmpyIQX(_Q, alpha, _Q, sin, Q30);
}

static inline void
__FUNC(els_ipark)(const _iq(_Q) d, const _iq(_Q) q,
				  const _iq(30) sin, const _iq(30) cos,
				  _iq(_Q) *alpha, _iq(_Q) *beta)
{
	*alpha = _IQmpyIQX(_Q, d, _Q, cos, Q30) - _IQmpyIQX(_Q, q, _Q, sin, Q30);
	*beta  = _IQmpyIQX(_Q, q, _Q, cos, Q30) + _IQmpyIQX(_Q, d, _Q, sin, Q30);
}


#endif  // _DECLARE_CODE


#ifdef _DEFINE_CODE


#endif  // _DEFINE_CODE


#undef _DECLARE_CODE
#undef _DEFINE_CODE

#undef _Q
#undef _POSTFIX
#undef __CCAT
#undef __CCAT2
#undef __FUNC
#undef __STRUCT
