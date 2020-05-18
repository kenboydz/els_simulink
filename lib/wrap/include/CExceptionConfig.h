#ifndef __CEXCEPTION_H__
#define __CEXCEPTION_H__

#include <stdint.h>
#include <stdbool.h>

#include "els_assert.h"


//This is the value to assign when there isn't an exception
// #define CEXCEPTION_NONE      (0x5A5A5A5A)

//This is number of exception stacks to keep track of (one per task)
// #define CEXCEPTION_NUM_ID    (1) //there is only the one stack by default

//This is the method of getting the current exception stack index (0 if only one stack)
// #define CEXCEPTION_GET_ID    (0) //use the first index always because there is only one anyway

//The type to use to store the exception values.
// #define CEXCEPTION_T         unsigned int

//This is an optional special handler for when there is no global Catch
#define CEXCEPTION_NO_CATCH_HANDLER(id) ELS_ERROR_ID(id)

//These hooks allow you to inject custom code into places, particularly useful for saving and restoring additional state
// #define CEXCEPTION_HOOK_START_TRY
// #define CEXCEPTION_HOOK_HAPPY_TRY
// #define CEXCEPTION_HOOK_AFTER_TRY
// #define CEXCEPTION_HOOK_START_CATCH


#endif  // __CEXCEPTION_H__
