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
  _iq(_Q) ka;
  _iq(_Q) max;
  _iq(_Q) min;
} __STRUCT(ElsPiInitParam);


void __FUNC(els_pi_init)(
  __STRUCT(ElsPi) * const self,
  const __STRUCT(ElsPiInitParam) * const param
);

void __FUNC(els_pi_update)(__STRUCT(ElsPi) * const self);
void __FUNC(els_pi_track)(__STRUCT(ElsPi) * const self);

#endif  // _DECLARE_CODE


#ifdef _DEFINE_CODE


void __FUNC(els_pi_init)(__STRUCT(ElsPi) * const self, const __STRUCT(ElsPiInitParam) * const param) {
	/** check */
  ELS_ASSERT(param->kp >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ki >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ka >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ka <= _IQ(_Q, 1.F));
  ELS_ASSERT(param->max > param->min);

	/** public */
	// input
	// output

	/** private */
	// parameter
  self->_kp = param->kp;
  self->_ki = param->ki;
  self->_ka = param->ka;
  self->_max = param->max;
  self->_min = param->min;
	// variable
  self->_yi = _IQ(_Q, 0.F);

	/** other */
}


void __FUNC(els_pi_update)(__STRUCT(ElsPi) * const self) {
	// integrate
	self->_yi += _IQmpy(_Q, self->_ki, self->ref - self->fdb);
	// feedback calculate
	self->out = _IQmpy(
    _Q,
		_IQmpy(_Q, self->_ka, self->ref) - self->fdb,
		self->_kp
	) + self->_yi;
	// saturation
  LIMIT_RANGE(self->out, self->_max, self->_min);
}


/**set ref, fdb, and out before call this function
 */
void __FUNC(els_pi_track)(__STRUCT(ElsPi) * const self) {
	// saturation
  LIMIT_RANGE(self->out, self->_max, self->_min);
  // calculate yi
  if (self->_ki != _IQ(_Q, 0.F)) {
    const _iq(_Q) yp = _IQmpy(
      _Q,
      _IQmpy(_Q, self->_ka, self->ref) - self->fdb,
      self->_kp
    );
    self->_yi = self->out - yp;
  } else {
    self->_yi = _IQ(_Q, 0.F);
  }
}


#endif  // _DEFINE_CODE


//=======================================back_calc pi======================================//


#ifdef _DECLARE_CODE


typedef struct __STRUCT(_ElsPiBackCalc) {
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
} __STRUCT(ElsPiBackCalc);

//---------------------------------------------------------------------------------------------------//

typedef struct {
  _iq(_Q) kp;
  _iq(_Q) ki;
  _iq(_Q) kc;
  _iq(_Q) ka;
  _iq(_Q) max;
  _iq(_Q) min;
} __STRUCT(ElsPiBackCalcInitParam);


void __FUNC(els_pi_back_calc_init)(
  __STRUCT(ElsPiBackCalc) * const self,
  const __STRUCT(ElsPiBackCalcInitParam) * const param
);

void __FUNC(els_pi_back_calc_update)(__STRUCT(ElsPiBackCalc) * const self);
void __FUNC(els_pi_back_calc_track)(__STRUCT(ElsPiBackCalc) * const self);


#endif  // _DECLARE_CODE


#ifdef _DEFINE_CODE


void __FUNC(els_pi_back_calc_init)(__STRUCT(ElsPiBackCalc) * const self, const __STRUCT(ElsPiBackCalcInitParam) * const param) {
	/** check */
  ELS_ASSERT(param->kp >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ki >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->kc >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ka >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ka <= _IQ(_Q, 1.F));
  ELS_ASSERT(param->max > param->min);

	/** public */
	// input
	// output

	/** private */
	// parameter
  self->_kp = param->kp;
  self->_ki = param->ki;
  self->_kc = param->kc;
  self->_ka = param->ka;
  self->_max = param->max;
  self->_min = param->min;
	// variable
  self->_yi = _IQ(_Q, 0.F);

	/** other */
}


void __FUNC(els_pi_back_calc_update)(__STRUCT(ElsPiBackCalc) * const self) {
	// feedback calculate
	const _iq(_Q) out_pre = _IQmpy(
    _Q,
		_IQmpy(_Q, self->_ka, self->ref) - self->fdb,
		self->_kp
	) + self->_yi;
	// saturation
  self->out = out_pre;
  LIMIT_RANGE(self->out, self->_max, self->_min);
	// integrate
	self->_yi += _IQmpy(_Q, self->_ki, self->ref - self->fdb)
				        + _IQmpy(_Q, self->_kc, self->out - out_pre);
}


/**set ref, fdb, and out before call this function
 */
void __FUNC(els_pi_back_calc_track)(__STRUCT(ElsPiBackCalc) * const self) {
	// saturation
  LIMIT_RANGE(self->out, self->_max, self->_min);
  // calculate yi
  if (self->_ki != _IQ(_Q, 0.F)) {
    const _iq(_Q) yp = _IQmpy(
      _Q,
      _IQmpy(_Q, self->_ka, self->ref) - self->fdb,
      self->_kp
    );
    self->_yi = self->out - yp;
  } else {
    self->_yi = _IQ(_Q, 0.F);
  }
}


#endif  // _DEFINE_CODE


//=======================================clamp pi======================================//


#ifdef _DECLARE_CODE


typedef struct __STRUCT(_ElsPiClamp) {
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
  _iq(_Q) _ka;
  _iq(_Q) _max;
  _iq(_Q) _min;
	// variable
  _iq(_Q) _yi;
} __STRUCT(ElsPiClamp);

//---------------------------------------------------------------------------------------------------//

typedef struct {
  _iq(_Q) kp;
  _iq(_Q) ki;
  _iq(_Q) ka;
  _iq(_Q) max;
  _iq(_Q) min;
} __STRUCT(ElsPiClampInitParam);


void __FUNC(els_pi_clamp_init)(
  __STRUCT(ElsPiClamp) * const self,
  const __STRUCT(ElsPiClampInitParam) * const param
);

void __FUNC(els_pi_clamp_update)(__STRUCT(ElsPiClamp) * const self);
void __FUNC(els_pi_clamp_track)(__STRUCT(ElsPiClamp) * const self);

static inline void
__FUNC(els_pi_clamp_set_maxmin)(__STRUCT(ElsPiClamp) * const self, _iq(_Q) max, _iq(_Q) min) {
  ELS_ASSERT(max > min);
  self->_max = max;
  self->_min = min;
}

static inline void
__FUNC(els_pi_clamp_set_kpi)(__STRUCT(ElsPiClamp) * const self, _iq(_Q) kp, _iq(_Q) ki) {
  ELS_ASSERT(kp >= _IQ(_Q, 0.F));
  ELS_ASSERT(ki >= _IQ(_Q, 0.F));
  self->_kp = kp;
  self->_ki = ki;
}

#endif  // _DECLARE_CODE


#ifdef _DEFINE_CODE


void __FUNC(els_pi_clamp_init)(__STRUCT(ElsPiClamp) * const self, const __STRUCT(ElsPiClampInitParam) * const param) {
	/** check */
  ELS_ASSERT(param->kp >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ki >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ka >= _IQ(_Q, 0.F));
  ELS_ASSERT(param->ka <= _IQ(_Q, 1.F));
  ELS_ASSERT(param->max > param->min);

	/** public */
	// input
	// output

	/** private */
	// parameter
  self->_kp = param->kp;
  self->_ki = param->ki;
  self->_ka = param->ka;
  self->_max = param->max;
  self->_min = param->min;
	// variable
  self->_yi = _IQ(_Q, 0.F);

	/** other */
}


void __FUNC(els_pi_clamp_update)(__STRUCT(ElsPiClamp) * const self) {
	// feedback calculate
  const _iq(_Q) yp = _IQmpy(
    _Q,
		_IQmpy(_Q, self->_ka, self->ref) - self->fdb,
		self->_kp
	);
	const _iq(_Q) out_pre = yp + self->_yi;
  const _iq(_Q) yi_delta = _IQmpy(_Q, self->ref - self->fdb, self->_ki);
	// saturation
  if (out_pre > self->_max && yi_delta > _IQ(_Q, 0.F)) {
    // 上溢出且同向
    self->out = self->_max;
  } else if (out_pre < self->_min && yi_delta < _IQ(_Q, 0.F)) {
    // 下溢出且同向
    self->out = self->_min;
  } else {
    // 其他
    self->_yi += yi_delta;
    self->out = yp + self->_yi;
    LIMIT_RANGE(self->out, self->_max, self->_min);
  }
}


/**set ref, fdb, and out before call this function
 */
void __FUNC(els_pi_clamp_track)(__STRUCT(ElsPiClamp) * const self) {
	// saturation
  LIMIT_RANGE(self->out, self->_max, self->_min);
  // calculate yi
  if (self->_ki != _IQ(_Q, 0.F)) {
    const _iq(_Q) yp = _IQmpy(
      _Q,
      _IQmpy(_Q, self->_ka, self->ref) - self->fdb,
      self->_kp
    );
    self->_yi = self->out - yp;
  } else {
    self->_yi = _IQ(_Q, 0.F);
  }
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
