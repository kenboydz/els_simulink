/* queue and stack, not thread safe
*/
#ifndef __ELS_UTILITY_H_
#define __ELS_UTILITY_H_


#include <stdint.h>
#include <stdbool.h>

#include "els.h"


typedef struct _ElsSpanCheck {
	/** public */
	// input
  bool is_true_raw;
	// output
  bool is_true;

	/** private */
	// parameter
  uint16_t _Cnt_Max;
	// variable
  uint16_t _cnt;
} ElsSpanCheck;

//---------------------------------------------------------------------------------------------------//

typedef struct {
  const uint16_t Cnt_Max;
} ElsSpanCheckInitParam;

void els_span_check_init(ElsSpanCheck * const self,
						             const ElsSpanCheckInitParam * const param);
void els_span_check_update(ElsSpanCheck * const self);
void els_span_check_reset(ElsSpanCheck * const self);


#endif  // __ELS_UTILITY_H_


