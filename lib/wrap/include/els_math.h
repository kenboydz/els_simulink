#ifndef __ELS_MATH_H__
#define __ELS_MATH_H__

#include "els.h"
#include "els_math_port.h"


#define CONST_1_SQRT2(N)        _IQ(N, 0.7071067811865475F)  // 1/sqrt(2)
#define CONST_1_SQRT3(N)        _IQ(N, 0.5773502691896258F)  // 1/sqrt(3)
#define CONST_1_SQRT6(N)        _IQ(N, 0.4082482904638630F)  // 1/sqrt(6)
#define CONST_2_SQRT3(N)        _IQ(N, 1.1547005383792517F)  // 2/sqrt(3)
#define CONST_SQRT2_SQRT3(N)    _IQ(N, 0.8164965809277260F)  // sqrt(2)/sqrt(3)
#define CONST_SQRT3_2(N)        _IQ(N, 0.8660254037844386F)  // sqrt(3)/2
#define CONST_PI                _IQ(N, 3.1415926535897932F)  // Pi
#define CONST_2xPI              _IQ(N, 6.2831853071795865F)  // 2Pi
#define CONST_PI_2              _IQ(N, 1.5707963267948966F)  // Pi/2


#define MAX(a, b)		            ( (a) > (b) ? (a) : (b) )
#define MIN(a, b)		            ( (a) < (b) ? (a) : (b) )

#define MAX_IN_3(a, b, c)		    ( MAX( MAX( (a), (b) ), (c) ) )
#define MIN_IN_3(a, b, c)		    ( MIN( MIN( (a), (b) ), (c) ) )

#define LIMIT_RANGE(a, max, min)    ( MAX( MIN( (a), (max) ), (min) ) )


#endif  // __ELS_MATH_H__
