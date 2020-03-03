#ifndef __ELS_PLL_H__
#define __ELS_PLL_H__

#include "els.h"
#include "els_math.h"
#include "els_math_tool.h"


//====================================single pll===============================//


typedef struct _ElsSinglePll {
	/** public */
    // input
    _iq(Q16) vac;  // bipolar voltage signal, unit V
    // output
    _iq(Q16) omega;
    _iq(Q16) theta;  // angle of _x1

	/** private */
	// parameter
    _iq(Q16) _k1;
    _iq(Q16) _gamma;
    _iq(Q16) _omega_max;
    _iq(Q16) _omega_min;
	// variable
    _iq(Q16) _x1;  // same phase of vac, unit V
    _iq(Q16) _x2;  // 90° phase lagged of vac, unit V
} ElsSinglePll;


typedef struct {
    _iq(Q16) k1;
    _iq(Q16) gamma;
    _iq(Q16) omega_max;
    _iq(Q16) omega_min;
} ElsSinglePllInitParam;

void els_single_pll_init(ElsSinglePll * const self,
                         const ElsSinglePllInitParam * const param);
void els_single_pll_update(ElsSinglePll * const self);
void els_single_pll_reset(ElsSinglePll * const self);


//====================================unipolar pll===============================//
/**only used for single pfc, in which vac is sampled after rectifier, therefore,
 * the voltage is unipolar.
 * all simple and fast calculation is used to shorten the overshoot.
 */

#define ELS_UNIPOLAR_BUF_SIZE               6  // do not change this, unless you know what you are doing.
#define ELS_UNIPOLAR_ARCH_GAP               5  // do not change this, unless you know what you are doing.
#define ELS_UNIPOLAR_LOCK_DELAY             3
#define ELS_UNIPOLAR_UPDATE_INTERVAL(N)     _IQ(N, 0.001F)


typedef struct _ElsUnipolarPll {
	/** public */
    // input
    _iq(Q17) vac;  // bipolar voltage signal, unit V
    // output
    bool is_locked;
    _iq(Q17) amplitude;  // max voltage, unit v
    _iq(Q17) freq;
    _iq(Q17) omega;
    _iq(Q17) theta;  // angle of _x1

	/** private */
	// parameter
    _iq(Q17) _freq_max;
    _iq(Q17) _freq_min;
	// variable
    int_least8_t _lock_cnt;
    _iq(Q17) _amplitude;
    bool _is_last_time_an_arc;
    _iq(Q17) _update_tick;  // time span between zero-cross and current update function.
                            // increase 1.F every time update function called,
                            // reset to real time after zero-cross detected.
    int_least8_t _curr_index;
    _iq(Q17) _time_buf[ELS_UNIPOLAR_BUF_SIZE];
    _iq(Q17) _vac_buf[ELS_UNIPOLAR_BUF_SIZE];
} ElsUnipolarPll;


typedef struct {
    _iq(Q17) freq_max;
    _iq(Q17) freq_min;
} ElsUnipolarPllInitParam;

void els_unipolar_pll_init(ElsUnipolarPll * const self,
                           const ElsUnipolarPllInitParam * const param);
void els_unipolar_pll_update_1ms(ElsUnipolarPll * const self);  // called every 1ms
void els_unipolar_pll_reset(ElsUnipolarPll * const self);


#endif  // __ELS_PLL_H__
