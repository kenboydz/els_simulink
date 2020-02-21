#ifndef __ELS_SVM_H__
#define __ELS_SVM_H__

#include <stdint.h>

#include "els.h"
#include "els_math.h"
#include "els_transform.h"


typedef enum {
	ElsSvmMode_PureSvm,
	ElsSvmMode_MinThd,
	ElsSvmMode_MinLoss
} ElsSvmMode;


typedef struct _ElsSvm {
	/** public */
	// input
	_iq(Q20) vd;  // [-2000, 2000]
	_iq(Q20) vq;  // [-2000, 2000]
	_iq(Q20) vdc;  // [0, 2000]
	_iq(Q30) sin;  // [-1, 1]
	_iq(Q30) cos;  // [-1, 1]
	// output
	_iq(Q30) ta;  // [-1, 1]
	_iq(Q30) tb;  // [-1, 1]
	_iq(Q30) tc;  // [-1, 1]

	/** private */
	// parameter
	ElsSvmMode _svm_mode;
	bool _enable_over_modulation;
	// variable
} ElsSvm;

//---------------------------------------------------------------------------------------------------//

typedef struct {
	ElsSvmMode svm_mode;
	bool enable_over_modulation;
} ElsSvmInitParam;

void els_svm_init(ElsSvm * const self, const ElsSvmInitParam * const param);
void els_svm_update(ElsSvm * const self);


static inline void
els_svm_set_mode(ElsSvm * const self, const ElsSvmMode svm_mode) {
	self->_svm_mode = svm_mode;
}


static inline void
els_svm_enable_over_modulation(ElsSvm * const self, bool enable) {
	self->_enable_over_modulation = enable;
}


#endif  // __ELS_SVM_H__
