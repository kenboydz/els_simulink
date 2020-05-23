#ifndef __ELS_PID_H__
#define __ELS_PID_H__

#include "els.h"
#include "els_math.h"


#define _DECLARE_CODE
#define _Q          Q24
#define _POSTFIX    _Q24
#include "_els_pid_template.h"


// for idq control
#define _DECLARE_CODE
#define _Q          Q18
#define _POSTFIX    _Q18
#include "_els_pid_template.h"


// for ppll
#define _DECLARE_CODE
#define _Q          Q16
#define _POSTFIX    _Q16
#include "_els_pid_template.h"


#endif  // __ELS_PID_H__
