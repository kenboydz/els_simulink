#ifndef _Q
    #error _Q should be defined before using template
#endif  // _Q
#ifndef _POSTFIX
    #error _POSTFIX should be defined before using template
#endif  // _POSTFIX

#define __CCAT(x, y)        __CCAT2(x, y)
#define __CCAT2(x, y)       x##y
#define __FUNC(name)        __CCAT(name, _POSTFIX)
#define __STRUCT(name)      __CCAT(name, _POSTFIX)


#include "els.h"
#include "els_math.h"



//=======================================simple pi======================================//


#ifdef _DECLARE_CODE


typedef struct __STRUCT(_ElsPi) {
	/** public */
    // input
    _iq(_Q) ref;
    _iq(_Q) fdb;
    // output
    _iq(_Q) out;

	/** private */
	// parameter
    _iq(_Q) _kp;
    _iq(_Q) _ki;
    _iq(_Q) _kc;
    _iq(_Q) _ka;
    _iq(_Q) _max;
    _iq(_Q) _min;
	// variable
    _iq(_Q) _yi;
} __STRUCT(ElsPi);

//---------------------------------------------------------------------------------------------------//

typedef struct {
    _iq(_Q) kp;
    _iq(_Q) ki;
    _iq(_Q) kc;
    _iq(_Q) ka;
    _iq(_Q) max;
    _iq(_Q) min;
} __STRUCT(ElsPiInitParam);


void __FUNC(els_pi_init)(
    __STRUCT(ElsPi) * const self,
    const __STRUCT(ElsPiInitParam) * const param);

void __FUNC(els_pi_update)(__STRUCT(ElsPi) * const self);

static inline void
__FUNC(els_pi_reset)(__STRUCT(ElsPi) * const self, _iq(_Q) yi) {
    self->_yi = yi;
}

#endif  // _DECLARE_CODE


#ifdef _DEFINE_CODE


void __FUNC(els_pi_init)(__STRUCT(ElsPi) * const self, const __STRUCT(ElsPiInitParam) * const param) {
	/** check */
    ELS_ASSERT(param->kp >= _IQ(_Q, 0.F));
    ELS_ASSERT(param->ki >= _IQ(_Q, 0.F));
    ELS_ASSERT(param->kc >= _IQ(_Q, 0.F));
    ELS_ASSERT(param->ka >= _IQ(_Q, 0.F));
    ELS_ASSERT(param->ka <= _IQ(_Q, 1.F));
    ELS_ASSERT(param->max > param->min);

	/*----------------------------- 初始化 ------------------------------*/

	/** public */
	// input
	self->ref = _IQ(_Q, 0.F);
	self->fdb = _IQ(_Q, 0.F);
	/* output */
	self->out = _IQ(_Q, 0.F);

	/** private */
	// parameter
    self->_kp = param->kp;
    self->_ki = param->ki;
    self->_kc = param->kc;
    self->_ka = param->ka;
    self->_max = param->max;
    self->_min = param->min;
	// variable

	/** other */
}


void __FUNC(els_pi_update)(__STRUCT(ElsPi) * const self) {
	// feedback calculate
	_iq(_Q) out_pre = _IQmpy(
        _Q,
		_IQmpy(_Q, self->_ka, self->ref) - self->fdb,
		self->_kp
	) + self->_yi;
	// saturation
	if (out_pre > self->_max) {
		self->out = self->_max;
	} else if (out_pre < self->_min) {
		self->out = self->_min;
	} else {
		self->out = out_pre;
	}
	// integrate
	self->_yi += _IQmpy(_Q, self->_ki, self->ref - self->fdb)
				+ _IQmpy(_Q, self->_kc, self->out - out_pre);
}


#endif  // _DEFINE_CODE


#undef _DECLARE_CODE
#undef _DEFINE_CODE

#undef _Q
#undef _POSTFIX
#undef __CCAT
#undef __CCAT2
#undef __FUNC
#undef __STRUCT
