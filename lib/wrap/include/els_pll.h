#ifndef __ELS_PLL_H__
#define __ELS_PLL_H__

#include "els.h"
#include "els_math.h"

typedef struct _ElsSinglePll {
	/** public */
    // input
    _iq(Q16) vac;  // 输入电压，单位 V
    // output
    _iq(Q16) x1;  // 与 vac 同相，单位 V
    _iq(Q16) x2;  // 滞后 vac 90°，单位 V
    _iq(Q16) x1_;  // 超前一个计算周期的 x1，单位 V
    _iq(Q16) x2_;  // 超前一个计算周期的 x2，单位 V
    _iq(Q16) cos;  // x1 同相单位化滤波值
    _iq(Q16) sin;  // x2 同相单位化滤波值
    _iq(Q16) theta;  // 角度值（cos为准），单位 rad

	/** private */
	// parameter
    _iq(Q16) _k1;
    _iq(Q16) _omega_max;
    _iq(Q16) _omega_min;
	// variable
    _iq(Q16) _omega;
    _iq(Q16) _fll_integer;
} ElsSinglePll;


typedef struct {
    _iq(Q16) _k1;
    _iq(Q16) _omega_max;
    _iq(Q16) _omega_min;
} ElsSinglePllInitParam;

void els_single_pll_init(ElsSinglePll * const self, const ElsSinglePllInitParam * const param);
void els_single_pll_update(ElsSinglePll * const self);
void els_single_pll_reset(ElsSinglePll * const self);


#endif  // __ELS_PLL_H__
