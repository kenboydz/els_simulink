#ifndef __ELS_MATH_PORT_H__
#define __ELS_MATH_PORT_H__

#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


#define MAX(a, b)		            ( (a) > (b) ? (a) : (b) )
#define MIN(a, b)		            ( (a) < (b) ? (a) : (b) )

#define MAX_IN_3(a, b, c)		    ( MAX( MAX( (a), (b) ), (c) ) )
#define MIN_IN_3(a, b, c)		    ( MIN( MIN( (a), (b) ), (c) ) )


#define   FLOAT_MATH    0
#define   IQ_MATH       1

#ifndef   MATH_TYPE
#define   MATH_TYPE     IQ_MATH
#endif

//---------------------------------------------------------------------------
// Various Usefull Constant Definitions:
//
#define   Q30           30
#define   Q29           29
#define   Q28           28
#define   Q27           27
#define   Q26           26
#define   Q25           25
#define   Q24           24
#define   Q23           23
#define   Q22           22
#define   Q21           21
#define   Q20           20
#define   Q19           19
#define   Q18           18
#define   Q17           17
#define   Q16           16
#define   Q15           15
#define   Q14           14
#define   Q13           13
#define   Q12           12
#define   Q11           11
#define   Q10           10
#define   Q9            9
#define   Q8            8
#define   Q7            7
#define   Q6            6
#define   Q5            5
#define   Q4            4
#define   Q3            3
#define   Q2            2
#define   Q1            1

#define   MAX_IQ_POS    LONG_MAX
#define   MAX_IQ_NEG    LONG_MIN
#define   MIN_IQ_POS    1
#define   MIN_IQ_NEG    -1


//###########################################################################
#if MATH_TYPE == IQ_MATH
//###########################################################################
// If IQ_MATH is used, the following IQmath library function definitions
// are used:
//===========================================================================
#define   _iq(N)        __iq(N)
#define   __iq(N)       __iq_##N

typedef   int32_t       __iq_30;
typedef   int32_t       __iq_29;
typedef   int32_t       __iq_28;
typedef   int32_t       __iq_27;
typedef   int32_t       __iq_26;
typedef   int32_t       __iq_25;
typedef   int32_t       __iq_24;
typedef   int32_t       __iq_23;
typedef   int32_t       __iq_22;
typedef   int32_t       __iq_21;
typedef   int32_t       __iq_20;
typedef   int32_t       __iq_19;
typedef   int32_t       __iq_18;
typedef   int32_t       __iq_17;
typedef   int32_t       __iq_16;
typedef   int32_t       __iq_15;
typedef   int32_t       __iq_14;
typedef   int32_t       __iq_13;
typedef   int32_t       __iq_12;
typedef   int32_t       __iq_11;
typedef   int32_t       __iq_10;
typedef   int32_t       __iq_9;
typedef   int32_t       __iq_8;
typedef   int32_t       __iq_7;
typedef   int32_t       __iq_6;
typedef   int32_t       __iq_5;
typedef   int32_t       __iq_4;
typedef   int32_t       __iq_3;
typedef   int32_t       __iq_2;
typedef   int32_t       __iq_1;
//---------------------------------------------------------------------------
#define   _IQ(N, A)     __IQ(N, A)
#define   __IQ(N, A)    __IQ_##N(A)

#define   __IQ_30(A)    (__iq_30) ((A) * 1073741824.0L)
#define   __IQ_29(A)    (__iq_29) ((A) * 536870912.0L)
#define   __IQ_28(A)    (__iq_28) ((A) * 268435456.0L)
#define   __IQ_27(A)    (__iq_27) ((A) * 134217728.0L)
#define   __IQ_26(A)    (__iq_26) ((A) * 67108864.0L)
#define   __IQ_25(A)    (__iq_25) ((A) * 33554432.0L)
#define   __IQ_24(A)    (__iq_24) ((A) * 16777216.0L)
#define   __IQ_23(A)    (__iq_23) ((A) * 8388608.0L)
#define   __IQ_22(A)    (__iq_22) ((A) * 4194304.0L)
#define   __IQ_21(A)    (__iq_21) ((A) * 2097152.0L)
#define   __IQ_20(A)    (__iq_20) ((A) * 1048576.0L)
#define   __IQ_19(A)    (__iq_19) ((A) * 524288.0L)
#define   __IQ_18(A)    (__iq_18) ((A) * 262144.0L)
#define   __IQ_17(A)    (__iq_17) ((A) * 131072.0L)
#define   __IQ_16(A)    (__iq_16) ((A) * 65536.0L)
#define   __IQ_15(A)    (__iq_15) ((A) * 32768.0L)
#define   __IQ_14(A)    (__iq_14) ((A) * 16384.0L)
#define   __IQ_13(A)    (__iq_13) ((A) * 8192.0L)
#define   __IQ_12(A)    (__iq_12) ((A) * 4096.0L)
#define   __IQ_11(A)    (__iq_11) ((A) * 2048.0L)
#define   __IQ_10(A)    (__iq_10) ((A) * 1024.0L)
#define   __IQ_9(A)     (__iq_9) ((A) * 512.0L)
#define   __IQ_8(A)     (__iq_8) ((A) * 256.0L)
#define   __IQ_7(A)     (__iq_7) ((A) * 128.0L)
#define   __IQ_6(A)     (__iq_6) ((A) * 64.0L)
#define   __IQ_5(A)     (__iq_5) ((A) * 32.0L)
#define   __IQ_4(A)     (__iq_4) ((A) * 16.0L)
#define   __IQ_3(A)     (__iq_3) ((A) * 8.0L)
#define   __IQ_2(A)     (__iq_2) ((A) * 4.0L)
#define   __IQ_1(A)     (__iq_1) ((A) * 2.0L)
//---------------------------------------------------------------------------
#define   _IQmod(N, A, B)   ((A) % (B))
//---------------------------------------------------------------------------
float __PC_IQtoF(const int32_t a, const int_fast8_t frac);

#define   _IQtoF(N, A)      __IQtoF(N, A)
#define   __IQtoF(N, A)     __IQtoF_##N(A)

#define   __IQtoF_30(A)	    __PC_IQtoF(A, 30)
#define   __IQtoF_29(A)	    __PC_IQtoF(A, 29)
#define   __IQtoF_28(A)	    __PC_IQtoF(A, 28)
#define   __IQtoF_27(A)	    __PC_IQtoF(A, 27)
#define   __IQtoF_26(A)	    __PC_IQtoF(A, 26)
#define   __IQtoF_25(A)	    __PC_IQtoF(A, 25)
#define   __IQtoF_24(A)	    __PC_IQtoF(A, 24)
#define   __IQtoF_23(A)	    __PC_IQtoF(A, 23)
#define   __IQtoF_22(A)	    __PC_IQtoF(A, 22)
#define   __IQtoF_21(A)	    __PC_IQtoF(A, 21)
#define   __IQtoF_20(A)	    __PC_IQtoF(A, 20)
#define   __IQtoF_19(A)	    __PC_IQtoF(A, 19)
#define   __IQtoF_18(A)	    __PC_IQtoF(A, 18)
#define   __IQtoF_17(A)	    __PC_IQtoF(A, 17)
#define   __IQtoF_16(A)	    __PC_IQtoF(A, 16)
#define   __IQtoF_15(A)	    __PC_IQtoF(A, 15)
#define   __IQtoF_14(A)	    __PC_IQtoF(A, 14)
#define   __IQtoF_13(A)	    __PC_IQtoF(A, 13)
#define   __IQtoF_12(A)	    __PC_IQtoF(A, 12)
#define   __IQtoF_11(A)	    __PC_IQtoF(A, 11)
#define   __IQtoF_10(A)	    __PC_IQtoF(A, 10)
#define   __IQtoF_9(A)	    __PC_IQtoF(A, 9)
#define   __IQtoF_8(A)	    __PC_IQtoF(A, 8)
#define   __IQtoF_7(A)	    __PC_IQtoF(A, 7)
#define   __IQtoF_6(A)	    __PC_IQtoF(A, 6)
#define   __IQtoF_5(A)	    __PC_IQtoF(A, 5)
#define   __IQtoF_4(A)	    __PC_IQtoF(A, 4)
#define   __IQtoF_3(A)	    __PC_IQtoF(A, 3)
#define   __IQtoF_2(A)	    __PC_IQtoF(A, 2)
#define   __IQtoF_1(A)	    __PC_IQtoF(A, 1)
//---------------------------------------------------------------------------
float __PC_FtoIQ(const float a, const int_fast8_t frac);

#define   _FtoIQ(N, A)      __FtoIQ(N, A)
#define   __FtoIQ(N, A)     __FtoIQ_##N(A)

#define   __FtoIQ_30(A)	    __PC_FtoIQ(A, 30)
#define   __FtoIQ_29(A)	    __PC_FtoIQ(A, 29)
#define   __FtoIQ_28(A)	    __PC_FtoIQ(A, 28)
#define   __FtoIQ_27(A)	    __PC_FtoIQ(A, 27)
#define   __FtoIQ_26(A)	    __PC_FtoIQ(A, 26)
#define   __FtoIQ_25(A)	    __PC_FtoIQ(A, 25)
#define   __FtoIQ_24(A)	    __PC_FtoIQ(A, 24)
#define   __FtoIQ_23(A)	    __PC_FtoIQ(A, 23)
#define   __FtoIQ_22(A)	    __PC_FtoIQ(A, 22)
#define   __FtoIQ_21(A)	    __PC_FtoIQ(A, 21)
#define   __FtoIQ_20(A)	    __PC_FtoIQ(A, 20)
#define   __FtoIQ_19(A)	    __PC_FtoIQ(A, 19)
#define   __FtoIQ_18(A)	    __PC_FtoIQ(A, 18)
#define   __FtoIQ_17(A)	    __PC_FtoIQ(A, 17)
#define   __FtoIQ_16(A)	    __PC_FtoIQ(A, 16)
#define   __FtoIQ_15(A)	    __PC_FtoIQ(A, 15)
#define   __FtoIQ_14(A)	    __PC_FtoIQ(A, 14)
#define   __FtoIQ_13(A)	    __PC_FtoIQ(A, 13)
#define   __FtoIQ_12(A)	    __PC_FtoIQ(A, 12)
#define   __FtoIQ_11(A)	    __PC_FtoIQ(A, 11)
#define   __FtoIQ_10(A)	    __PC_FtoIQ(A, 10)
#define   __FtoIQ_9(A)	    __PC_FtoIQ(A, 9)
#define   __FtoIQ_8(A)	    __PC_FtoIQ(A, 8)
#define   __FtoIQ_7(A)	    __PC_FtoIQ(A, 7)
#define   __FtoIQ_6(A)	    __PC_FtoIQ(A, 6)
#define   __FtoIQ_5(A)	    __PC_FtoIQ(A, 5)
#define   __FtoIQ_4(A)	    __PC_FtoIQ(A, 4)
#define   __FtoIQ_3(A)	    __PC_FtoIQ(A, 3)
#define   __FtoIQ_2(A)	    __PC_FtoIQ(A, 2)
#define   __FtoIQ_1(A)	    __PC_FtoIQ(A, 1)
//---------------------------------------------------------------------------
#define   _IQsat(A, Pos, Neg)   (MAX(((MIN((A),(Pos)))),(Neg)))
//---------------------------------------------------------------------------
#define   _IQNtoM(A, N, M)      M > N ? ((int32_t) (A) << ( (M) - (N) ) ) : ((int32_t) (A) >> ( (N) - (M) ) )
//---------------------------------------------------------------------------
#define   _IQmpy2(A)        ((A)<<1)
#define   _IQmpy4(A)        ((A)<<2)
#define   _IQmpy8(A)        ((A)<<3)
#define   _IQmpy16(A)       ((A)<<4)
#define   _IQmpy32(A)       ((A)<<5)
#define   _IQmpy64(A)       ((A)<<6)
            
#define   _IQdiv2(A)        ((A)>>1)
#define   _IQdiv4(A)        ((A)>>2)
#define   _IQdiv8(A)        ((A)>>3)
#define   _IQdiv16(A)       ((A)>>4)
#define   _IQdiv32(A)       ((A)>>5)
#define   _IQdiv64(A)       ((A)>>6)
//---------------------------------------------------------------------------
int32_t __PC_IQmpy(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQmpy(N, A, B)   __IQmpy(N, A, B)
#define   __IQmpy(N, A, B)  __IQmpy_##N(A, B)

#define   __IQmpy_30(A, B)  __PC_IQmpy(A, B, 30)
#define   __IQmpy_29(A, B)  __PC_IQmpy(A, B, 29)
#define   __IQmpy_28(A, B)  __PC_IQmpy(A, B, 28)
#define   __IQmpy_27(A, B)  __PC_IQmpy(A, B, 27)
#define   __IQmpy_26(A, B)  __PC_IQmpy(A, B, 26)
#define   __IQmpy_25(A, B)  __PC_IQmpy(A, B, 25)
#define   __IQmpy_24(A, B)  __PC_IQmpy(A, B, 24)
#define   __IQmpy_23(A, B)  __PC_IQmpy(A, B, 23)
#define   __IQmpy_22(A, B)  __PC_IQmpy(A, B, 22)
#define   __IQmpy_21(A, B)  __PC_IQmpy(A, B, 21)
#define   __IQmpy_20(A, B)  __PC_IQmpy(A, B, 20)
#define   __IQmpy_19(A, B)  __PC_IQmpy(A, B, 19)
#define   __IQmpy_18(A, B)  __PC_IQmpy(A, B, 18)
#define   __IQmpy_17(A, B)  __PC_IQmpy(A, B, 17)
#define   __IQmpy_16(A, B)  __PC_IQmpy(A, B, 16)
#define   __IQmpy_15(A, B)  __PC_IQmpy(A, B, 15)
#define   __IQmpy_14(A, B)  __PC_IQmpy(A, B, 14)
#define   __IQmpy_13(A, B)  __PC_IQmpy(A, B, 13)
#define   __IQmpy_12(A, B)  __PC_IQmpy(A, B, 12)
#define   __IQmpy_11(A, B)  __PC_IQmpy(A, B, 11)
#define   __IQmpy_10(A, B)  __PC_IQmpy(A, B, 10)
#define   __IQmpy_9(A, B)   __PC_IQmpy(A, B, 9)
#define   __IQmpy_8(A, B)   __PC_IQmpy(A, B, 8)
#define   __IQmpy_7(A, B)   __PC_IQmpy(A, B, 7)
#define   __IQmpy_6(A, B)   __PC_IQmpy(A, B, 6)
#define   __IQmpy_5(A, B)   __PC_IQmpy(A, B, 5)
#define   __IQmpy_4(A, B)   __PC_IQmpy(A, B, 4)
#define   __IQmpy_3(A, B)   __PC_IQmpy(A, B, 3)
#define   __IQmpy_2(A, B)   __PC_IQmpy(A, B, 2)
#define   __IQmpy_1(A, B)   __PC_IQmpy(A, B, 1)
//---------------------------------------------------------------------------
int32_t  __PC_IQrmpy(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQrmpy(N, A,B)   __IQrmpy(N, A, B)
#define   __IQrmpy(N, A,B)  __IQrmpy_##N(A, B)

#define   __IQrmpy_30(A,B)  __PC_IQrmpy(A, B, 30)
#define   __IQrmpy_29(A,B)  __PC_IQrmpy(A, B, 29)
#define   __IQrmpy_28(A,B)  __PC_IQrmpy(A, B, 28)
#define   __IQrmpy_27(A,B)  __PC_IQrmpy(A, B, 27)
#define   __IQrmpy_26(A,B)  __PC_IQrmpy(A, B, 26)
#define   __IQrmpy_25(A,B)  __PC_IQrmpy(A, B, 25)
#define   __IQrmpy_24(A,B)  __PC_IQrmpy(A, B, 24)
#define   __IQrmpy_23(A,B)  __PC_IQrmpy(A, B, 23)
#define   __IQrmpy_22(A,B)  __PC_IQrmpy(A, B, 22)
#define   __IQrmpy_21(A,B)  __PC_IQrmpy(A, B, 21)
#define   __IQrmpy_20(A,B)  __PC_IQrmpy(A, B, 20)
#define   __IQrmpy_19(A,B)  __PC_IQrmpy(A, B, 19)
#define   __IQrmpy_18(A,B)  __PC_IQrmpy(A, B, 18)
#define   __IQrmpy_17(A,B)  __PC_IQrmpy(A, B, 17)
#define   __IQrmpy_16(A,B)  __PC_IQrmpy(A, B, 16)
#define   __IQrmpy_15(A,B)  __PC_IQrmpy(A, B, 15)
#define   __IQrmpy_14(A,B)  __PC_IQrmpy(A, B, 14)
#define   __IQrmpy_13(A,B)  __PC_IQrmpy(A, B, 13)
#define   __IQrmpy_12(A,B)  __PC_IQrmpy(A, B, 12)
#define   __IQrmpy_11(A,B)  __PC_IQrmpy(A, B, 11)
#define   __IQrmpy_10(A,B)  __PC_IQrmpy(A, B, 10)
#define   __IQrmpy_9(A,B)   __PC_IQrmpy(A, B, 9)
#define   __IQrmpy_8(A,B)   __PC_IQrmpy(A, B, 8)
#define   __IQrmpy_7(A,B)   __PC_IQrmpy(A, B, 7)
#define   __IQrmpy_6(A,B)   __PC_IQrmpy(A, B, 6)
#define   __IQrmpy_5(A,B)   __PC_IQrmpy(A, B, 5)
#define   __IQrmpy_4(A,B)   __PC_IQrmpy(A, B, 4)
#define   __IQrmpy_3(A,B)   __PC_IQrmpy(A, B, 3)
#define   __IQrmpy_2(A,B)   __PC_IQrmpy(A, B, 2)
#define   __IQrmpy_1(A,B)   __PC_IQrmpy(A, B, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQrsmpy(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQrsmpy(N, A, B)     __IQrsmpy(N, A, B)
#define   __IQrsmpy(N, A, B)    __IQrsmpy_##N(A, B)

#define   __IQrsmpy_30(A, B)    __PC_IQrmpy(A, B, 30)
#define   __IQrsmpy_29(A, B)    __PC_IQrmpy(A, B, 29)
#define   __IQrsmpy_28(A, B)    __PC_IQrmpy(A, B, 28)
#define   __IQrsmpy_27(A, B)    __PC_IQrmpy(A, B, 27)
#define   __IQrsmpy_26(A, B)    __PC_IQrmpy(A, B, 26)
#define   __IQrsmpy_25(A, B)    __PC_IQrmpy(A, B, 25)
#define   __IQrsmpy_24(A, B)    __PC_IQrmpy(A, B, 24)
#define   __IQrsmpy_23(A, B)    __PC_IQrmpy(A, B, 23)
#define   __IQrsmpy_22(A, B)    __PC_IQrmpy(A, B, 22)
#define   __IQrsmpy_21(A, B)    __PC_IQrmpy(A, B, 21)
#define   __IQrsmpy_20(A, B)    __PC_IQrmpy(A, B, 20)
#define   __IQrsmpy_19(A, B)    __PC_IQrmpy(A, B, 19)
#define   __IQrsmpy_18(A, B)    __PC_IQrmpy(A, B, 18)
#define   __IQrsmpy_17(A, B)    __PC_IQrmpy(A, B, 17)
#define   __IQrsmpy_16(A, B)    __PC_IQrmpy(A, B, 16)
#define   __IQrsmpy_15(A, B)    __PC_IQrmpy(A, B, 15)
#define   __IQrsmpy_14(A, B)    __PC_IQrmpy(A, B, 14)
#define   __IQrsmpy_13(A, B)    __PC_IQrmpy(A, B, 13)
#define   __IQrsmpy_12(A, B)    __PC_IQrmpy(A, B, 12)
#define   __IQrsmpy_11(A, B)    __PC_IQrmpy(A, B, 11)
#define   __IQrsmpy_10(A, B)    __PC_IQrmpy(A, B, 10)
#define   __IQrsmpy_9(A, B)     __PC_IQrmpy(A, B, 9)
#define   __IQrsmpy_8(A, B)     __PC_IQrmpy(A, B, 8)
#define   __IQrsmpy_7(A, B)     __PC_IQrmpy(A, B, 7)
#define   __IQrsmpy_6(A, B)     __PC_IQrmpy(A, B, 6)
#define   __IQrsmpy_5(A, B)     __PC_IQrmpy(A, B, 5)
#define   __IQrsmpy_4(A, B)     __PC_IQrmpy(A, B, 4)
#define   __IQrsmpy_3(A, B)     __PC_IQrmpy(A, B, 3)
#define   __IQrsmpy_2(A, B)     __PC_IQrmpy(A, B, 2)
#define   __IQrsmpy_1(A, B)     __PC_IQrmpy(A, B, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQdiv(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQdiv(N, A, B)       __IQdiv(N, A, B)
#define   __IQdiv(N, A, B)      __IQdiv_##N(A, B)

#define   __IQdiv_30(A, B)      __PC_IQdiv(A, B, 30)
#define   __IQdiv_29(A, B)      __PC_IQdiv(A, B, 29)
#define   __IQdiv_28(A, B)      __PC_IQdiv(A, B, 28)
#define   __IQdiv_27(A, B)      __PC_IQdiv(A, B, 27)
#define   __IQdiv_26(A, B)      __PC_IQdiv(A, B, 26)
#define   __IQdiv_25(A, B)      __PC_IQdiv(A, B, 25)
#define   __IQdiv_24(A, B)      __PC_IQdiv(A, B, 24)
#define   __IQdiv_23(A, B)      __PC_IQdiv(A, B, 23)
#define   __IQdiv_22(A, B)      __PC_IQdiv(A, B, 22)
#define   __IQdiv_21(A, B)      __PC_IQdiv(A, B, 21)
#define   __IQdiv_20(A, B)      __PC_IQdiv(A, B, 20)
#define   __IQdiv_19(A, B)      __PC_IQdiv(A, B, 19)
#define   __IQdiv_18(A, B)      __PC_IQdiv(A, B, 18)
#define   __IQdiv_17(A, B)      __PC_IQdiv(A, B, 17)
#define   __IQdiv_16(A, B)      __PC_IQdiv(A, B, 16)
#define   __IQdiv_15(A, B)      __PC_IQdiv(A, B, 15)
#define   __IQdiv_14(A, B)      __PC_IQdiv(A, B, 14)
#define   __IQdiv_13(A, B)      __PC_IQdiv(A, B, 13)
#define   __IQdiv_12(A, B)      __PC_IQdiv(A, B, 12)
#define   __IQdiv_11(A, B)      __PC_IQdiv(A, B, 11)
#define   __IQdiv_10(A, B)      __PC_IQdiv(A, B, 10)
#define   __IQdiv_9(A, B)       __PC_IQdiv(A, B, 9)
#define   __IQdiv_8(A, B)       __PC_IQdiv(A, B, 8)
#define   __IQdiv_7(A, B)       __PC_IQdiv(A, B, 7)
#define   __IQdiv_6(A, B)       __PC_IQdiv(A, B, 6)
#define   __IQdiv_5(A, B)       __PC_IQdiv(A, B, 5)
#define   __IQdiv_4(A, B)       __PC_IQdiv(A, B, 4)
#define   __IQdiv_3(A, B)       __PC_IQdiv(A, B, 3)
#define   __IQdiv_2(A, B)       __PC_IQdiv(A, B, 2)
#define   __IQdiv_1(A, B)       __PC_IQdiv(A, B, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQsin(const int32_t a, const int_fast8_t frac);

#define   _IQsin(N, A)      __IQsin(N, A)
#define   __IQsin(N, A)     __IQsin_##N(A)

#define   __IQsin_30(A)     __PC_IQsin(A, 30)
#define   __IQsin_29(A)     __PC_IQsin(A, 29)
#define   __IQsin_28(A)     __PC_IQsin(A, 28)
#define   __IQsin_27(A)     __PC_IQsin(A, 27)
#define   __IQsin_26(A)     __PC_IQsin(A, 26)
#define   __IQsin_25(A)     __PC_IQsin(A, 25)
#define   __IQsin_24(A)     __PC_IQsin(A, 24)
#define   __IQsin_23(A)     __PC_IQsin(A, 23)
#define   __IQsin_22(A)     __PC_IQsin(A, 22)
#define   __IQsin_21(A)     __PC_IQsin(A, 21)
#define   __IQsin_20(A)     __PC_IQsin(A, 20)
#define   __IQsin_19(A)     __PC_IQsin(A, 19)
#define   __IQsin_18(A)     __PC_IQsin(A, 18)
#define   __IQsin_17(A)     __PC_IQsin(A, 17)
#define   __IQsin_16(A)     __PC_IQsin(A, 16)
#define   __IQsin_15(A)     __PC_IQsin(A, 15)
#define   __IQsin_14(A)     __PC_IQsin(A, 14)
#define   __IQsin_13(A)     __PC_IQsin(A, 13)
#define   __IQsin_12(A)     __PC_IQsin(A, 12)
#define   __IQsin_11(A)     __PC_IQsin(A, 11)
#define   __IQsin_10(A)     __PC_IQsin(A, 10)
#define   __IQsin_9(A)      __PC_IQsin(A, 9)
#define   __IQsin_8(A)      __PC_IQsin(A, 8)
#define   __IQsin_7(A)      __PC_IQsin(A, 7)
#define   __IQsin_6(A)      __PC_IQsin(A, 6)
#define   __IQsin_5(A)      __PC_IQsin(A, 5)
#define   __IQsin_4(A)      __PC_IQsin(A, 4)
#define   __IQsin_3(A)      __PC_IQsin(A, 3)
#define   __IQsin_2(A)      __PC_IQsin(A, 2)
#define   __IQsin_1(A)      __PC_IQsin(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQsinPU(const int32_t a, const int_fast8_t frac);

#define   _IQsinPU(N, A)    __IQsinPU(N, A)
#define   __IQsinPU(N, A)   __IQsinPU_##N(A)

#define   __IQsinPU_30(A)   __PC_IQsinPU(A, 30)
#define   __IQsinPU_29(A)   __PC_IQsinPU(A, 29)
#define   __IQsinPU_28(A)   __PC_IQsinPU(A, 28)
#define   __IQsinPU_27(A)   __PC_IQsinPU(A, 27)
#define   __IQsinPU_26(A)   __PC_IQsinPU(A, 26)
#define   __IQsinPU_25(A)   __PC_IQsinPU(A, 25)
#define   __IQsinPU_24(A)   __PC_IQsinPU(A, 24)
#define   __IQsinPU_23(A)   __PC_IQsinPU(A, 23)
#define   __IQsinPU_22(A)   __PC_IQsinPU(A, 22)
#define   __IQsinPU_21(A)   __PC_IQsinPU(A, 21)
#define   __IQsinPU_20(A)   __PC_IQsinPU(A, 20)
#define   __IQsinPU_19(A)   __PC_IQsinPU(A, 19)
#define   __IQsinPU_18(A)   __PC_IQsinPU(A, 18)
#define   __IQsinPU_17(A)   __PC_IQsinPU(A, 17)
#define   __IQsinPU_16(A)   __PC_IQsinPU(A, 16)
#define   __IQsinPU_15(A)   __PC_IQsinPU(A, 15)
#define   __IQsinPU_14(A)   __PC_IQsinPU(A, 14)
#define   __IQsinPU_13(A)   __PC_IQsinPU(A, 13)
#define   __IQsinPU_12(A)   __PC_IQsinPU(A, 12)
#define   __IQsinPU_11(A)   __PC_IQsinPU(A, 11)
#define   __IQsinPU_10(A)   __PC_IQsinPU(A, 10)
#define   __IQsinPU_9(A)    __PC_IQsinPU(A, 9)
#define   __IQsinPU_8(A)    __PC_IQsinPU(A, 8)
#define   __IQsinPU_7(A)    __PC_IQsinPU(A, 7)
#define   __IQsinPU_6(A)    __PC_IQsinPU(A, 6)
#define   __IQsinPU_5(A)    __PC_IQsinPU(A, 5)
#define   __IQsinPU_4(A)    __PC_IQsinPU(A, 4)
#define   __IQsinPU_3(A)    __PC_IQsinPU(A, 3)
#define   __IQsinPU_2(A)    __PC_IQsinPU(A, 2)
#define   __IQsinPU_1(A)    __PC_IQsinPU(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQasin(const int32_t a, const int_fast8_t frac);

#define   _IQasin(N, A)     __IQasin(N, A)
#define   __IQasin(N, A)    __IQasin_##N(A)

#define   __IQasin_30(A)    __PC_IQasin(A, 30)
#define   __IQasin_29(A)    __PC_IQasin(A, 29)
#define   __IQasin_28(A)    __PC_IQasin(A, 28)
#define   __IQasin_27(A)    __PC_IQasin(A, 27)
#define   __IQasin_26(A)    __PC_IQasin(A, 26)
#define   __IQasin_25(A)    __PC_IQasin(A, 25)
#define   __IQasin_24(A)    __PC_IQasin(A, 24)
#define   __IQasin_23(A)    __PC_IQasin(A, 23)
#define   __IQasin_22(A)    __PC_IQasin(A, 22)
#define   __IQasin_21(A)    __PC_IQasin(A, 21)
#define   __IQasin_20(A)    __PC_IQasin(A, 20)
#define   __IQasin_19(A)    __PC_IQasin(A, 19)
#define   __IQasin_18(A)    __PC_IQasin(A, 18)
#define   __IQasin_17(A)    __PC_IQasin(A, 17)
#define   __IQasin_16(A)    __PC_IQasin(A, 16)
#define   __IQasin_15(A)    __PC_IQasin(A, 15)
#define   __IQasin_14(A)    __PC_IQasin(A, 14)
#define   __IQasin_13(A)    __PC_IQasin(A, 13)
#define   __IQasin_12(A)    __PC_IQasin(A, 12)
#define   __IQasin_11(A)    __PC_IQasin(A, 11)
#define   __IQasin_10(A)    __PC_IQasin(A, 10)
#define   __IQasin_9(A)     __PC_IQasin(A, 9)
#define   __IQasin_8(A)     __PC_IQasin(A, 8)
#define   __IQasin_7(A)     __PC_IQasin(A, 7)
#define   __IQasin_6(A)     __PC_IQasin(A, 6)
#define   __IQasin_5(A)     __PC_IQasin(A, 5)
#define   __IQasin_4(A)     __PC_IQasin(A, 4)
#define   __IQasin_3(A)     __PC_IQasin(A, 3)
#define   __IQasin_2(A)     __PC_IQasin(A, 2)
#define   __IQasin_1(A)     __PC_IQasin(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQcos(const int32_t a, const int_fast8_t frac);

#define   _IQcos(N, A)      __IQcos(N, A)
#define   __IQcos(N, A)     __IQcos_##N(A)

#define   __IQcos_30(A)     __PC_IQcos(A, 30)
#define   __IQcos_29(A)     __PC_IQcos(A, 29)
#define   __IQcos_28(A)     __PC_IQcos(A, 28)
#define   __IQcos_27(A)     __PC_IQcos(A, 27)
#define   __IQcos_26(A)     __PC_IQcos(A, 26)
#define   __IQcos_25(A)     __PC_IQcos(A, 25)
#define   __IQcos_24(A)     __PC_IQcos(A, 24)
#define   __IQcos_23(A)     __PC_IQcos(A, 23)
#define   __IQcos_22(A)     __PC_IQcos(A, 22)
#define   __IQcos_21(A)     __PC_IQcos(A, 21)
#define   __IQcos_20(A)     __PC_IQcos(A, 20)
#define   __IQcos_19(A)     __PC_IQcos(A, 19)
#define   __IQcos_18(A)     __PC_IQcos(A, 18)
#define   __IQcos_17(A)     __PC_IQcos(A, 17)
#define   __IQcos_16(A)     __PC_IQcos(A, 16)
#define   __IQcos_15(A)     __PC_IQcos(A, 15)
#define   __IQcos_14(A)     __PC_IQcos(A, 14)
#define   __IQcos_13(A)     __PC_IQcos(A, 13)
#define   __IQcos_12(A)     __PC_IQcos(A, 12)
#define   __IQcos_11(A)     __PC_IQcos(A, 11)
#define   __IQcos_10(A)     __PC_IQcos(A, 10)
#define   __IQcos_9(A)      __PC_IQcos(A, 9)
#define   __IQcos_8(A)      __PC_IQcos(A, 8)
#define   __IQcos_7(A)      __PC_IQcos(A, 7)
#define   __IQcos_6(A)      __PC_IQcos(A, 6)
#define   __IQcos_5(A)      __PC_IQcos(A, 5)
#define   __IQcos_4(A)      __PC_IQcos(A, 4)
#define   __IQcos_3(A)      __PC_IQcos(A, 3)
#define   __IQcos_2(A)      __PC_IQcos(A, 2)
#define   __IQcos_1(A)      __PC_IQcos(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQcosPU(const int32_t a, const int_fast8_t frac);

#define   _IQcosPU(N, A)    __IQcosPU(N, A)
#define   __IQcosPU(N, A)   __IQcosPU_##N(A)

#define   __IQcosPU_30(A)   __PC_IQcosPU(A, 30)
#define   __IQcosPU_29(A)   __PC_IQcosPU(A, 29)
#define   __IQcosPU_28(A)   __PC_IQcosPU(A, 28)
#define   __IQcosPU_27(A)   __PC_IQcosPU(A, 27)
#define   __IQcosPU_26(A)   __PC_IQcosPU(A, 26)
#define   __IQcosPU_25(A)   __PC_IQcosPU(A, 25)
#define   __IQcosPU_24(A)   __PC_IQcosPU(A, 24)
#define   __IQcosPU_23(A)   __PC_IQcosPU(A, 23)
#define   __IQcosPU_22(A)   __PC_IQcosPU(A, 22)
#define   __IQcosPU_21(A)   __PC_IQcosPU(A, 21)
#define   __IQcosPU_20(A)   __PC_IQcosPU(A, 20)
#define   __IQcosPU_19(A)   __PC_IQcosPU(A, 19)
#define   __IQcosPU_18(A)   __PC_IQcosPU(A, 18)
#define   __IQcosPU_17(A)   __PC_IQcosPU(A, 17)
#define   __IQcosPU_16(A)   __PC_IQcosPU(A, 16)
#define   __IQcosPU_15(A)   __PC_IQcosPU(A, 15)
#define   __IQcosPU_14(A)   __PC_IQcosPU(A, 14)
#define   __IQcosPU_13(A)   __PC_IQcosPU(A, 13)
#define   __IQcosPU_12(A)   __PC_IQcosPU(A, 12)
#define   __IQcosPU_11(A)   __PC_IQcosPU(A, 11)
#define   __IQcosPU_10(A)   __PC_IQcosPU(A, 10)
#define   __IQcosPU_9(A)    __PC_IQcosPU(A, 9)
#define   __IQcosPU_8(A)    __PC_IQcosPU(A, 8)
#define   __IQcosPU_7(A)    __PC_IQcosPU(A, 7)
#define   __IQcosPU_6(A)    __PC_IQcosPU(A, 6)
#define   __IQcosPU_5(A)    __PC_IQcosPU(A, 5)
#define   __IQcosPU_4(A)    __PC_IQcosPU(A, 4)
#define   __IQcosPU_3(A)    __PC_IQcosPU(A, 3)
#define   __IQcosPU_2(A)    __PC_IQcosPU(A, 2)
#define   __IQcosPU_1(A)    __PC_IQcosPU(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQacos(const int32_t a, const int_fast8_t frac);

#define   _IQacos(N, A)     __IQacos(N, A)
#define   __IQacos(N, A)    __IQacos_##N(A)

#define   __IQacos_30(A)    __PC_IQacos(A, 30)
#define   __IQacos_29(A)    __PC_IQacos(A, 29)
#define   __IQacos_28(A)    __PC_IQacos(A, 28)
#define   __IQacos_27(A)    __PC_IQacos(A, 27)
#define   __IQacos_26(A)    __PC_IQacos(A, 26)
#define   __IQacos_25(A)    __PC_IQacos(A, 25)
#define   __IQacos_24(A)    __PC_IQacos(A, 24)
#define   __IQacos_23(A)    __PC_IQacos(A, 23)
#define   __IQacos_22(A)    __PC_IQacos(A, 22)
#define   __IQacos_21(A)    __PC_IQacos(A, 21)
#define   __IQacos_20(A)    __PC_IQacos(A, 20)
#define   __IQacos_19(A)    __PC_IQacos(A, 19)
#define   __IQacos_18(A)    __PC_IQacos(A, 18)
#define   __IQacos_17(A)    __PC_IQacos(A, 17)
#define   __IQacos_16(A)    __PC_IQacos(A, 16)
#define   __IQacos_15(A)    __PC_IQacos(A, 15)
#define   __IQacos_14(A)    __PC_IQacos(A, 14)
#define   __IQacos_13(A)    __PC_IQacos(A, 13)
#define   __IQacos_12(A)    __PC_IQacos(A, 12)
#define   __IQacos_11(A)    __PC_IQacos(A, 11)
#define   __IQacos_10(A)    __PC_IQacos(A, 10)
#define   __IQacos_9(A)     __PC_IQacos(A, 9)
#define   __IQacos_8(A)     __PC_IQacos(A, 8)
#define   __IQacos_7(A)     __PC_IQacos(A, 7)
#define   __IQacos_6(A)     __PC_IQacos(A, 6)
#define   __IQacos_5(A)     __PC_IQacos(A, 5)
#define   __IQacos_4(A)     __PC_IQacos(A, 4)
#define   __IQacos_3(A)     __PC_IQacos(A, 3)
#define   __IQacos_2(A)     __PC_IQacos(A, 2)
#define   __IQacos_1(A)     __PC_IQacos(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQatan2(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQtan(N, A)      __IQtan(N, A)
#define   __IQtan(N, A)     __IQtan_##N(A)

#define   __IQtan_30(A)     _IQdiv(30, _IQsin(30, A), _IQcos(30, A))
#define   __IQtan_29(A)     _IQdiv(29, _IQsin(29, A), _IQcos(29, A))
#define   __IQtan_28(A)     _IQdiv(28, _IQsin(28, A), _IQcos(28, A))
#define   __IQtan_27(A)     _IQdiv(27, _IQsin(27, A), _IQcos(27, A))
#define   __IQtan_26(A)     _IQdiv(26, _IQsin(26, A), _IQcos(26, A))
#define   __IQtan_25(A)     _IQdiv(25, _IQsin(25, A), _IQcos(25, A))
#define   __IQtan_24(A)     _IQdiv(24, _IQsin(24, A), _IQcos(24, A))
#define   __IQtan_23(A)     _IQdiv(23, _IQsin(23, A), _IQcos(23, A))
#define   __IQtan_22(A)     _IQdiv(22, _IQsin(22, A), _IQcos(22, A))
#define   __IQtan_21(A)     _IQdiv(21, _IQsin(21, A), _IQcos(21, A))
#define   __IQtan_20(A)     _IQdiv(20, _IQsin(20, A), _IQcos(20, A))
#define   __IQtan_19(A)     _IQdiv(19, _IQsin(19, A), _IQcos(19, A))
#define   __IQtan_18(A)     _IQdiv(18, _IQsin(18, A), _IQcos(18, A))
#define   __IQtan_17(A)     _IQdiv(17, _IQsin(17, A), _IQcos(17, A))
#define   __IQtan_16(A)     _IQdiv(16, _IQsin(16, A), _IQcos(16, A))
#define   __IQtan_15(A)     _IQdiv(15, _IQsin(15, A), _IQcos(15, A))
#define   __IQtan_14(A)     _IQdiv(14, _IQsin(14, A), _IQcos(14, A))
#define   __IQtan_13(A)     _IQdiv(13, _IQsin(13, A), _IQcos(13, A))
#define   __IQtan_12(A)     _IQdiv(12, _IQsin(12, A), _IQcos(12, A))
#define   __IQtan_11(A)     _IQdiv(11, _IQsin(11, A), _IQcos(11, A))
#define   __IQtan_10(A)     _IQdiv(10, _IQsin(10, A), _IQcos(10, A))
#define   __IQtan_9(A)      _IQdiv(9, _IQsin(9, A), _IQcos(9, A))
#define   __IQtan_8(A)      _IQdiv(8, _IQsin(8, A), _IQcos(8, A))
#define   __IQtan_7(A)      _IQdiv(7, _IQsin(7, A), _IQcos(7, A))
#define   __IQtan_6(A)      _IQdiv(6, _IQsin(6, A), _IQcos(6, A))
#define   __IQtan_5(A)      _IQdiv(5, _IQsin(5, A), _IQcos(5, A))
#define   __IQtan_4(A)      _IQdiv(4, _IQsin(4, A), _IQcos(4, A))
#define   __IQtan_3(A)      _IQdiv(3, _IQsin(3, A), _IQcos(3, A))
#define   __IQtan_2(A)      _IQdiv(2, _IQsin(2, A), _IQcos(2, A))
#define   __IQtan_1(A)      _IQdiv(1, _IQsin(1, A), _IQcos(1, A))
//---------------------------------------------------------------------------
int32_t __PC_IQatan2(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQatan2(N, A, B)    __IQatan2(N, A, B)
#define   __IQatan2(N, A, B)   __IQatan2_##N(A, B)
    
#define   __IQatan2_30(A,B)     __PC_IQatan2(A, B, 30)
#define   __IQatan2_29(A,B)     __PC_IQatan2(A, B, 29)
#define   __IQatan2_28(A,B)     __PC_IQatan2(A, B, 28)
#define   __IQatan2_27(A,B)     __PC_IQatan2(A, B, 27)
#define   __IQatan2_26(A,B)     __PC_IQatan2(A, B, 26)
#define   __IQatan2_25(A,B)     __PC_IQatan2(A, B, 25)
#define   __IQatan2_24(A,B)     __PC_IQatan2(A, B, 24)
#define   __IQatan2_23(A,B)     __PC_IQatan2(A, B, 23)
#define   __IQatan2_22(A,B)     __PC_IQatan2(A, B, 22)
#define   __IQatan2_21(A,B)     __PC_IQatan2(A, B, 21)
#define   __IQatan2_20(A,B)     __PC_IQatan2(A, B, 20)
#define   __IQatan2_19(A,B)     __PC_IQatan2(A, B, 19)
#define   __IQatan2_18(A,B)     __PC_IQatan2(A, B, 18)
#define   __IQatan2_17(A,B)     __PC_IQatan2(A, B, 17)
#define   __IQatan2_16(A,B)     __PC_IQatan2(A, B, 16)
#define   __IQatan2_15(A,B)     __PC_IQatan2(A, B, 15)
#define   __IQatan2_14(A,B)     __PC_IQatan2(A, B, 14)
#define   __IQatan2_13(A,B)     __PC_IQatan2(A, B, 13)
#define   __IQatan2_12(A,B)     __PC_IQatan2(A, B, 12)
#define   __IQatan2_11(A,B)     __PC_IQatan2(A, B, 11)
#define   __IQatan2_10(A,B)     __PC_IQatan2(A, B, 10)
#define   __IQatan2_9(A,B)      __PC_IQatan2(A, B, 9)
#define   __IQatan2_8(A,B)      __PC_IQatan2(A, B, 8)
#define   __IQatan2_7(A,B)      __PC_IQatan2(A, B, 7)
#define   __IQatan2_6(A,B)      __PC_IQatan2(A, B, 6)
#define   __IQatan2_5(A,B)      __PC_IQatan2(A, B, 5)
#define   __IQatan2_4(A,B)      __PC_IQatan2(A, B, 4)
#define   __IQatan2_3(A,B)      __PC_IQatan2(A, B, 3)
#define   __IQatan2_2(A,B)      __PC_IQatan2(A, B, 2)
#define   __IQatan2_1(A,B)      __PC_IQatan2(A, B, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQatan2PU(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQatan2PU(N, A, B)   __IQatan2PU(N, A, B)
#define   __IQatan2PU(N, A, B)  __IQatan2PU_##N(A, B)

#define   __IQatan2PU_30(A,B)   __PC_IQatan2PU(A, B, 30)
#define   __IQatan2PU_29(A,B)   __PC_IQatan2PU(A, B, 29)
#define   __IQatan2PU_28(A,B)   __PC_IQatan2PU(A, B, 28)
#define   __IQatan2PU_27(A,B)   __PC_IQatan2PU(A, B, 27)
#define   __IQatan2PU_26(A,B)   __PC_IQatan2PU(A, B, 26)
#define   __IQatan2PU_25(A,B)   __PC_IQatan2PU(A, B, 25)
#define   __IQatan2PU_24(A,B)   __PC_IQatan2PU(A, B, 24)
#define   __IQatan2PU_23(A,B)   __PC_IQatan2PU(A, B, 23)
#define   __IQatan2PU_22(A,B)   __PC_IQatan2PU(A, B, 22)
#define   __IQatan2PU_21(A,B)   __PC_IQatan2PU(A, B, 21)
#define   __IQatan2PU_20(A,B)   __PC_IQatan2PU(A, B, 20)
#define   __IQatan2PU_19(A,B)   __PC_IQatan2PU(A, B, 19)
#define   __IQatan2PU_18(A,B)   __PC_IQatan2PU(A, B, 18)
#define   __IQatan2PU_17(A,B)   __PC_IQatan2PU(A, B, 17)
#define   __IQatan2PU_16(A,B)   __PC_IQatan2PU(A, B, 16)
#define   __IQatan2PU_15(A,B)   __PC_IQatan2PU(A, B, 15)
#define   __IQatan2PU_14(A,B)   __PC_IQatan2PU(A, B, 14)
#define   __IQatan2PU_13(A,B)   __PC_IQatan2PU(A, B, 13)
#define   __IQatan2PU_12(A,B)   __PC_IQatan2PU(A, B, 12)
#define   __IQatan2PU_11(A,B)   __PC_IQatan2PU(A, B, 11)
#define   __IQatan2PU_10(A,B)   __PC_IQatan2PU(A, B, 10)
#define   __IQatan2PU_9(A,B)    __PC_IQatan2PU(A, B, 9)
#define   __IQatan2PU_8(A,B)    __PC_IQatan2PU(A, B, 8)
#define   __IQatan2PU_7(A,B)    __PC_IQatan2PU(A, B, 7)
#define   __IQatan2PU_6(A,B)    __PC_IQatan2PU(A, B, 6)
#define   __IQatan2PU_5(A,B)    __PC_IQatan2PU(A, B, 5)
#define   __IQatan2PU_4(A,B)    __PC_IQatan2PU(A, B, 4)
#define   __IQatan2PU_3(A,B)    __PC_IQatan2PU(A, B, 3)
#define   __IQatan2PU_2(A,B)    __PC_IQatan2PU(A, B, 2)
#define   __IQatan2PU_1(A,B)    __PC_IQatan2PU(A, B, 1)
//---------------------------------------------------------------------------
#define   _IQatan(N, A)     __IQatan(N, A)
#define   __IQatan(N, A)    __IQatan_##N(A)

#define   __IQatan_30(A)    _IQatan2(30, A,_IQ30(1.0))
#define   __IQatan_29(A)    _IQatan2(29, A,_IQ29(1.0))
#define   __IQatan_28(A)    _IQatan2(28, A,_IQ28(1.0))
#define   __IQatan_27(A)    _IQatan2(27, A,_IQ27(1.0))
#define   __IQatan_26(A)    _IQatan2(26, A,_IQ26(1.0))
#define   __IQatan_25(A)    _IQatan2(25, A,_IQ25(1.0))
#define   __IQatan_24(A)    _IQatan2(24, A,_IQ24(1.0))
#define   __IQatan_23(A)    _IQatan2(23, A,_IQ23(1.0))
#define   __IQatan_22(A)    _IQatan2(22, A,_IQ22(1.0))
#define   __IQatan_21(A)    _IQatan2(21, A,_IQ21(1.0))
#define   __IQatan_20(A)    _IQatan2(20, A,_IQ20(1.0))
#define   __IQatan_19(A)    _IQatan2(19, A,_IQ19(1.0))
#define   __IQatan_18(A)    _IQatan2(18, A,_IQ18(1.0))
#define   __IQatan_17(A)    _IQatan2(17, A,_IQ17(1.0))
#define   __IQatan_16(A)    _IQatan2(16, A,_IQ16(1.0))
#define   __IQatan_15(A)    _IQatan2(15, A,_IQ15(1.0))
#define   __IQatan_14(A)    _IQatan2(14, A,_IQ14(1.0))
#define   __IQatan_13(A)    _IQatan2(13, A,_IQ13(1.0))
#define   __IQatan_12(A)    _IQatan2(12, A,_IQ12(1.0))
#define   __IQatan_11(A)    _IQatan2(11, A,_IQ11(1.0))
#define   __IQatan_10(A)    _IQatan2(10, A,_IQ10(1.0))
#define   __IQatan_9(A)     _IQatan2(9, A,_IQ9(1.0))
#define   __IQatan_8(A)     _IQatan2(8, A,_IQ8(1.0))
#define   __IQatan_7(A)     _IQatan2(7, A,_IQ7(1.0))
#define   __IQatan_6(A)     _IQatan2(6, A,_IQ6(1.0))
#define   __IQatan_5(A)     _IQatan2(5, A,_IQ5(1.0))
#define   __IQatan_4(A)     _IQatan2(4, A,_IQ4(1.0))
#define   __IQatan_3(A)     _IQatan2(3, A,_IQ3(1.0))
#define   __IQatan_2(A)     _IQatan2(2, A,_IQ2(1.0))
#define   __IQatan_1(A)     _IQatan2(1, A,_IQ1(1.0))
//---------------------------------------------------------------------------
int32_t __PC_IQsqrt(const int32_t a, const int_fast8_t frac);

#define   _IQsqrt(N, A)     __IQsqrt(N, A)
#define   __IQsqrt(N, A)    __IQsqrt_##N(A)

#define   __IQsqrt_30(A)    __PC_IQsqrt(A, 30)
#define   __IQsqrt_29(A)    __PC_IQsqrt(A, 29)
#define   __IQsqrt_28(A)    __PC_IQsqrt(A, 28)
#define   __IQsqrt_27(A)    __PC_IQsqrt(A, 27)
#define   __IQsqrt_26(A)    __PC_IQsqrt(A, 26)
#define   __IQsqrt_25(A)    __PC_IQsqrt(A, 25)
#define   __IQsqrt_24(A)    __PC_IQsqrt(A, 24)
#define   __IQsqrt_23(A)    __PC_IQsqrt(A, 23)
#define   __IQsqrt_22(A)    __PC_IQsqrt(A, 22)
#define   __IQsqrt_21(A)    __PC_IQsqrt(A, 21)
#define   __IQsqrt_20(A)    __PC_IQsqrt(A, 20)
#define   __IQsqrt_19(A)    __PC_IQsqrt(A, 19)
#define   __IQsqrt_18(A)    __PC_IQsqrt(A, 18)
#define   __IQsqrt_17(A)    __PC_IQsqrt(A, 17)
#define   __IQsqrt_16(A)    __PC_IQsqrt(A, 16)
#define   __IQsqrt_15(A)    __PC_IQsqrt(A, 15)
#define   __IQsqrt_14(A)    __PC_IQsqrt(A, 14)
#define   __IQsqrt_13(A)    __PC_IQsqrt(A, 13)
#define   __IQsqrt_12(A)    __PC_IQsqrt(A, 12)
#define   __IQsqrt_11(A)    __PC_IQsqrt(A, 11)
#define   __IQsqrt_10(A)    __PC_IQsqrt(A, 10)
#define   __IQsqrt_9(A)     __PC_IQsqrt(A, 9)
#define   __IQsqrt_8(A)     __PC_IQsqrt(A, 8)
#define   __IQsqrt_7(A)     __PC_IQsqrt(A, 7)
#define   __IQsqrt_6(A)     __PC_IQsqrt(A, 6)
#define   __IQsqrt_5(A)     __PC_IQsqrt(A, 5)
#define   __IQsqrt_4(A)     __PC_IQsqrt(A, 4)
#define   __IQsqrt_3(A)     __PC_IQsqrt(A, 3)
#define   __IQsqrt_2(A)     __PC_IQsqrt(A, 2)
#define   __IQsqrt_1(A)     __PC_IQsqrt(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQisqrt(const int32_t a, const int_fast8_t frac);

#define   _IQisqrt(N, A)    __IQisqrt(N, A)
#define   __IQisqrt(N, A)   __IQisqrt_##N(A)

#define   __IQisqrt_30(A)   __PC_IQisqrt(A, 30)
#define   __IQisqrt_29(A)   __PC_IQisqrt(A, 29)
#define   __IQisqrt_28(A)   __PC_IQisqrt(A, 28)
#define   __IQisqrt_27(A)   __PC_IQisqrt(A, 27)
#define   __IQisqrt_26(A)   __PC_IQisqrt(A, 26)
#define   __IQisqrt_25(A)   __PC_IQisqrt(A, 25)
#define   __IQisqrt_24(A)   __PC_IQisqrt(A, 24)
#define   __IQisqrt_23(A)   __PC_IQisqrt(A, 23)
#define   __IQisqrt_22(A)   __PC_IQisqrt(A, 22)
#define   __IQisqrt_21(A)   __PC_IQisqrt(A, 21)
#define   __IQisqrt_20(A)   __PC_IQisqrt(A, 20)
#define   __IQisqrt_19(A)   __PC_IQisqrt(A, 19)
#define   __IQisqrt_18(A)   __PC_IQisqrt(A, 18)
#define   __IQisqrt_17(A)   __PC_IQisqrt(A, 17)
#define   __IQisqrt_16(A)   __PC_IQisqrt(A, 16)
#define   __IQisqrt_15(A)   __PC_IQisqrt(A, 15)
#define   __IQisqrt_14(A)   __PC_IQisqrt(A, 14)
#define   __IQisqrt_13(A)   __PC_IQisqrt(A, 13)
#define   __IQisqrt_12(A)   __PC_IQisqrt(A, 12)
#define   __IQisqrt_11(A)   __PC_IQisqrt(A, 11)
#define   __IQisqrt_10(A)   __PC_IQisqrt(A, 10)
#define   __IQisqrt_9(A)    __PC_IQisqrt(A, 9)
#define   __IQisqrt_8(A)    __PC_IQisqrt(A, 8)
#define   __IQisqrt_7(A)    __PC_IQisqrt(A, 7)
#define   __IQisqrt_6(A)    __PC_IQisqrt(A, 6)
#define   __IQisqrt_5(A)    __PC_IQisqrt(A, 5)
#define   __IQisqrt_4(A)    __PC_IQisqrt(A, 4)
#define   __IQisqrt_3(A)    __PC_IQisqrt(A, 3)
#define   __IQisqrt_2(A)    __PC_IQisqrt(A, 2)
#define   __IQisqrt_1(A)    __PC_IQisqrt(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQexp(const int32_t a, const int_fast8_t frac);

#define   _IQexp(N, A)      __IQexp(N, A)
#define   __IQexp(N, A)     __IQexp_##N(A)

#define   __IQexp_30(A)     __PC_IQexp(A, 30)
#define   __IQexp_29(A)     __PC_IQexp(A, 29)
#define   __IQexp_28(A)     __PC_IQexp(A, 28)
#define   __IQexp_27(A)     __PC_IQexp(A, 27)
#define   __IQexp_26(A)     __PC_IQexp(A, 26)
#define   __IQexp_25(A)     __PC_IQexp(A, 25)
#define   __IQexp_24(A)     __PC_IQexp(A, 24)
#define   __IQexp_23(A)     __PC_IQexp(A, 23)
#define   __IQexp_22(A)     __PC_IQexp(A, 22)
#define   __IQexp_21(A)     __PC_IQexp(A, 21)
#define   __IQexp_20(A)     __PC_IQexp(A, 20)
#define   __IQexp_19(A)     __PC_IQexp(A, 19)
#define   __IQexp_18(A)     __PC_IQexp(A, 18)
#define   __IQexp_17(A)     __PC_IQexp(A, 17)
#define   __IQexp_16(A)     __PC_IQexp(A, 16)
#define   __IQexp_15(A)     __PC_IQexp(A, 15)
#define   __IQexp_14(A)     __PC_IQexp(A, 14)
#define   __IQexp_13(A)     __PC_IQexp(A, 13)
#define   __IQexp_12(A)     __PC_IQexp(A, 12)
#define   __IQexp_11(A)     __PC_IQexp(A, 11)
#define   __IQexp_10(A)     __PC_IQexp(A, 10)
#define   __IQexp_9(A)      __PC_IQexp(A, 9)
#define   __IQexp_8(A)      __PC_IQexp(A, 8)
#define   __IQexp_7(A)      __PC_IQexp(A, 7)
#define   __IQexp_6(A)      __PC_IQexp(A, 6)
#define   __IQexp_5(A)      __PC_IQexp(A, 5)
#define   __IQexp_4(A)      __PC_IQexp(A, 4)
#define   __IQexp_3(A)      __PC_IQexp(A, 3)
#define   __IQexp_2(A)      __PC_IQexp(A, 2)
#define   __IQexp_1(A)      __PC_IQexp(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQint(const int32_t a, const int_fast8_t frac);

#define   _IQint(N, A)      __IQint(N, A)
#define   __IQint(N, A)     __IQint_##N(A)

#define   __IQint_30(A)     __PC_IQint(A, 30)
#define   __IQint_29(A)     __PC_IQint(A, 29)
#define   __IQint_28(A)     __PC_IQint(A, 28)
#define   __IQint_27(A)     __PC_IQint(A, 27)
#define   __IQint_26(A)     __PC_IQint(A, 26)
#define   __IQint_25(A)     __PC_IQint(A, 25)
#define   __IQint_24(A)     __PC_IQint(A, 24)
#define   __IQint_23(A)     __PC_IQint(A, 23)
#define   __IQint_22(A)     __PC_IQint(A, 22)
#define   __IQint_21(A)     __PC_IQint(A, 21)
#define   __IQint_20(A)     __PC_IQint(A, 20)
#define   __IQint_19(A)     __PC_IQint(A, 19)
#define   __IQint_18(A)     __PC_IQint(A, 18)
#define   __IQint_17(A)     __PC_IQint(A, 17)
#define   __IQint_16(A)     __PC_IQint(A, 16)
#define   __IQint_15(A)     __PC_IQint(A, 15)
#define   __IQint_14(A)     __PC_IQint(A, 14)
#define   __IQint_13(A)     __PC_IQint(A, 13)
#define   __IQint_12(A)     __PC_IQint(A, 12)
#define   __IQint_11(A)     __PC_IQint(A, 11)
#define   __IQint_10(A)     __PC_IQint(A, 10)
#define   __IQint_9(A)      __PC_IQint(A, 9)
#define   __IQint_8(A)      __PC_IQint(A, 8)
#define   __IQint_7(A)      __PC_IQint(A, 7)
#define   __IQint_6(A)      __PC_IQint(A, 6)
#define   __IQint_5(A)      __PC_IQint(A, 5)
#define   __IQint_4(A)      __PC_IQint(A, 4)
#define   __IQint_3(A)      __PC_IQint(A, 3)
#define   __IQint_2(A)      __PC_IQint(A, 2)
#define   __IQint_1(A)      __PC_IQint(A, 1)
//---------------------------------------------------------------------------
int32_t __PC_IQfrac(const int32_t a, const int_fast8_t frac);

#define   _IQfrac(N, A)     __IQfrac(N, A)
#define   __IQfrac(N, A)    __IQfrac_##N(A)

#define   __IQfrac_30(A)    __PC_IQfrac(A, 30)
#define   __IQfrac_29(A)    __PC_IQfrac(A, 29)
#define   __IQfrac_28(A)    __PC_IQfrac(A, 28)
#define   __IQfrac_27(A)    __PC_IQfrac(A, 27)
#define   __IQfrac_26(A)    __PC_IQfrac(A, 26)
#define   __IQfrac_25(A)    __PC_IQfrac(A, 25)
#define   __IQfrac_24(A)    __PC_IQfrac(A, 24)
#define   __IQfrac_23(A)    __PC_IQfrac(A, 23)
#define   __IQfrac_22(A)    __PC_IQfrac(A, 22)
#define   __IQfrac_21(A)    __PC_IQfrac(A, 21)
#define   __IQfrac_20(A)    __PC_IQfrac(A, 20)
#define   __IQfrac_19(A)    __PC_IQfrac(A, 19)
#define   __IQfrac_18(A)    __PC_IQfrac(A, 18)
#define   __IQfrac_17(A)    __PC_IQfrac(A, 17)
#define   __IQfrac_16(A)    __PC_IQfrac(A, 16)
#define   __IQfrac_15(A)    __PC_IQfrac(A, 15)
#define   __IQfrac_14(A)    __PC_IQfrac(A, 14)
#define   __IQfrac_13(A)    __PC_IQfrac(A, 13)
#define   __IQfrac_12(A)    __PC_IQfrac(A, 12)
#define   __IQfrac_11(A)    __PC_IQfrac(A, 11)
#define   __IQfrac_10(A)    __PC_IQfrac(A, 10)
#define   __IQfrac_9(A)     __PC_IQfrac(A, 9)
#define   __IQfrac_8(A)     __PC_IQfrac(A, 8)
#define   __IQfrac_7(A)     __PC_IQfrac(A, 7)
#define   __IQfrac_6(A)     __PC_IQfrac(A, 6)
#define   __IQfrac_5(A)     __PC_IQfrac(A, 5)
#define   __IQfrac_4(A)     __PC_IQfrac(A, 4)
#define   __IQfrac_3(A)     __PC_IQfrac(A, 3)
#define   __IQfrac_2(A)     __PC_IQfrac(A, 2)
#define   __IQfrac_1(A)     __PC_IQfrac(A, 1)
//---------------------------------------------------------------------------
// TODO check the realization of __IQxmpy in TI
int32_t __PC_IQmpyIQX(const int32_t a, const int32_t b, const int_least8_t frac);

#define   _IQmpyIQX(N, A, IQA, B, IQB)      __IQmpyIQX(N, A, IQA, B, IQB)
#define   __IQmpyIQX(N, A, IQA, B, IQB)     __IQmpyIQX_##N(A, IQA, B, IQB)
    
#define   __IQmpyIQX_30(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 30))
#define   __IQmpyIQX_29(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 29))
#define   __IQmpyIQX_28(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 28))
#define   __IQmpyIQX_27(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 27))
#define   __IQmpyIQX_26(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 26))
#define   __IQmpyIQX_25(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 25))
#define   __IQmpyIQX_24(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 24))
#define   __IQmpyIQX_23(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 23))
#define   __IQmpyIQX_22(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 22))
#define   __IQmpyIQX_21(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 21))
#define   __IQmpyIQX_20(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 20))
#define   __IQmpyIQX_19(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 19))
#define   __IQmpyIQX_18(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 18))
#define   __IQmpyIQX_17(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 17))
#define   __IQmpyIQX_16(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 16))
#define   __IQmpyIQX_15(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 15))
#define   __IQmpyIQX_14(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 14))
#define   __IQmpyIQX_13(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 13))
#define   __IQmpyIQX_12(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 12))
#define   __IQmpyIQX_11(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 11))
#define   __IQmpyIQX_10(A, IQA, B, IQB)     __PC_IQmpyIQX(A, B, (IQA + IQB - 10))
#define   __IQmpyIQX_9(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 9))
#define   __IQmpyIQX_8(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 8))
#define   __IQmpyIQX_7(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 7))
#define   __IQmpyIQX_6(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 6))
#define   __IQmpyIQX_5(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 5))
#define   __IQmpyIQX_4(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 4))
#define   __IQmpyIQX_3(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 3))
#define   __IQmpyIQX_2(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 2))
#define   __IQmpyIQX_1(A, IQA, B, IQB)      __PC_IQmpyIQX(A, B, (IQA + IQB - 1))
//---------------------------------------------------------------------------
/* below is not supported currently
#define   __IQmpyI32(A,B)    ((A)*(B))
#define   __IQ30mpyI32(A,B)  ((A)*(B))
#define   __IQ29mpyI32(A,B)  ((A)*(B))
#define   __IQ28mpyI32(A,B)  ((A)*(B))
#define   __IQ27mpyI32(A,B)  ((A)*(B))
#define   __IQ26mpyI32(A,B)  ((A)*(B))
#define   __IQ25mpyI32(A,B)  ((A)*(B))
#define   __IQ24mpyI32(A,B)  ((A)*(B))
#define   __IQ23mpyI32(A,B)  ((A)*(B))
#define   __IQ22mpyI32(A,B)  ((A)*(B))
#define   __IQ21mpyI32(A,B)  ((A)*(B))
#define   __IQ20mpyI32(A,B)  ((A)*(B))
#define   __IQ19mpyI32(A,B)  ((A)*(B))
#define   __IQ18mpyI32(A,B)  ((A)*(B))
#define   __IQ17mpyI32(A,B)  ((A)*(B))
#define   __IQ16mpyI32(A,B)  ((A)*(B))
#define   __IQ15mpyI32(A,B)  ((A)*(B))
#define   __IQ14mpyI32(A,B)  ((A)*(B))
#define   __IQ13mpyI32(A,B)  ((A)*(B))
#define   __IQ12mpyI32(A,B)  ((A)*(B))
#define   __IQ11mpyI32(A,B)  ((A)*(B))
#define   __IQ10mpyI32(A,B)  ((A)*(B))
#define   __IQ9mpyI32(A,B)   ((A)*(B))
#define   __IQ8mpyI32(A,B)   ((A)*(B))
#define   __IQ7mpyI32(A,B)   ((A)*(B))
#define   __IQ6mpyI32(A,B)   ((A)*(B))
#define   __IQ5mpyI32(A,B)   ((A)*(B))
#define   __IQ4mpyI32(A,B)   ((A)*(B))
#define   __IQ3mpyI32(A,B)   ((A)*(B))
#define   __IQ2mpyI32(A,B)   ((A)*(B))
#define   __IQ1mpyI32(A,B)   ((A)*(B))
*/
//---------------------------------------------------------------------------
/* below is not supported currently
extern    int32_t _IQ30mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ29mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ28mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ27mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ26mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ25mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ24mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ23mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ22mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ21mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ20mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ19mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ18mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ17mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ16mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ15mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ14mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ13mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ12mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ11mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ10mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ9mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ8mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ7mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ6mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ5mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ4mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ3mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ2mpyI32int(int32_t A, int32_t B);
extern    int32_t _IQ1mpyI32int(int32_t A, int32_t B);
*/
//---------------------------------------------------------------------------
/* below is not supported currently
extern    int32_t _IQ30mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ29mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ28mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ27mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ26mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ25mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ24mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ23mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ22mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ21mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ20mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ19mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ18mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ17mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ16mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ15mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ14mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ13mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ12mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ11mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ10mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ9mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ8mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ7mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ6mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ5mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ4mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ3mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ2mpyI32frac(int32_t A, int32_t B);
extern    int32_t _IQ1mpyI32frac(int32_t A, int32_t B);
*/
//---------------------------------------------------------------------------
int32_t __PC_IQmag(const int32_t a, const int32_t b, const int_fast8_t frac);

#define   _IQmag(N, A, B)   __IQmag(N, A, B)
#define   __IQmag(N, A, B)  __IQmag_##N(A, B)

#define   __IQmag_30(A,B)   __PC_IQmag(A, B, 30)
#define   __IQmag_29(A,B)   __PC_IQmag(A, B, 29)
#define   __IQmag_28(A,B)   __PC_IQmag(A, B, 28)
#define   __IQmag_27(A,B)   __PC_IQmag(A, B, 27)
#define   __IQmag_26(A,B)   __PC_IQmag(A, B, 26)
#define   __IQmag_25(A,B)   __PC_IQmag(A, B, 25)
#define   __IQmag_24(A,B)   __PC_IQmag(A, B, 24)
#define   __IQmag_23(A,B)   __PC_IQmag(A, B, 23)
#define   __IQmag_22(A,B)   __PC_IQmag(A, B, 22)
#define   __IQmag_21(A,B)   __PC_IQmag(A, B, 21)
#define   __IQmag_20(A,B)   __PC_IQmag(A, B, 20)
#define   __IQmag_19(A,B)   __PC_IQmag(A, B, 19)
#define   __IQmag_18(A,B)   __PC_IQmag(A, B, 18)
#define   __IQmag_17(A,B)   __PC_IQmag(A, B, 17)
#define   __IQmag_16(A,B)   __PC_IQmag(A, B, 16)
#define   __IQmag_15(A,B)   __PC_IQmag(A, B, 15)
#define   __IQmag_14(A,B)   __PC_IQmag(A, B, 14)
#define   __IQmag_13(A,B)   __PC_IQmag(A, B, 13)
#define   __IQmag_12(A,B)   __PC_IQmag(A, B, 12)
#define   __IQmag_11(A,B)   __PC_IQmag(A, B, 11)
#define   __IQmag_10(A,B)   __PC_IQmag(A, B, 10)
#define   __IQmag_9(A,B)    __PC_IQmag(A, B, 9)
#define   __IQmag_8(A,B)    __PC_IQmag(A, B, 8)
#define   __IQmag_7(A,B)    __PC_IQmag(A, B, 7)
#define   __IQmag_6(A,B)    __PC_IQmag(A, B, 6)
#define   __IQmag_5(A,B)    __PC_IQmag(A, B, 5)
#define   __IQmag_4(A,B)    __PC_IQmag(A, B, 4)
#define   __IQmag_3(A,B)    __PC_IQmag(A, B, 3)
#define   __IQmag_2(A,B)    __PC_IQmag(A, B, 2)
#define   __IQmag_1(A,B)    __PC_IQmag(A, B, 1)
//---------------------------------------------------------------------------
/* below is not supported currently
extern    int32_t _atoIQN(const char *A, int32_t q_value);
#define   _atoIQ(A)    _atoIQN(A, GLOBAL_Q)
#define   _atoIQ30(A)  _atoIQN(A, 30)
#define   _atoIQ29(A)  _atoIQN(A, 29)
#define   _atoIQ28(A)  _atoIQN(A, 28)
#define   _atoIQ27(A)  _atoIQN(A, 27)
#define   _atoIQ26(A)  _atoIQN(A, 26)
#define   _atoIQ25(A)  _atoIQN(A, 25)
#define   _atoIQ24(A)  _atoIQN(A, 24)
#define   _atoIQ23(A)  _atoIQN(A, 23)
#define   _atoIQ22(A)  _atoIQN(A, 22)
#define   _atoIQ21(A)  _atoIQN(A, 21)
#define   _atoIQ20(A)  _atoIQN(A, 20)
#define   _atoIQ19(A)  _atoIQN(A, 19)
#define   _atoIQ18(A)  _atoIQN(A, 18)
#define   _atoIQ17(A)  _atoIQN(A, 17)
#define   _atoIQ16(A)  _atoIQN(A, 16)
#define   _atoIQ15(A)  _atoIQN(A, 15)
#define   _atoIQ14(A)  _atoIQN(A, 14)
#define   _atoIQ13(A)  _atoIQN(A, 13)
#define   _atoIQ12(A)  _atoIQN(A, 12)
#define   _atoIQ11(A)  _atoIQN(A, 11)
#define   _atoIQ10(A)  _atoIQN(A, 10)
#define   _atoIQ9(A)   _atoIQN(A, 9)
#define   _atoIQ8(A)   _atoIQN(A, 8)
#define   _atoIQ7(A)   _atoIQN(A, 7)
#define   _atoIQ6(A)   _atoIQN(A, 6)
#define   _atoIQ5(A)   _atoIQN(A, 5)
#define   _atoIQ4(A)   _atoIQN(A, 4)
#define   _atoIQ3(A)   _atoIQN(A, 3)
#define   _atoIQ2(A)   _atoIQN(A, 2)
#define   _atoIQ1(A)   _atoIQN(A, 1)
*/
//---------------------------------------------------------------------------
/* below is not supported currently
extern    int __IQNtoa(char *A, const char *B, int32_t C, int D);
extern    int __IQtoa30(char *A, const char *B, int32_t C);
extern    int __IQtoa29(char *A, const char *B, int32_t C);
extern    int __IQtoa28(char *A, const char *B, int32_t C);
extern    int __IQtoa27(char *A, const char *B, int32_t C);
extern    int __IQtoa26(char *A, const char *B, int32_t C);
extern    int __IQtoa25(char *A, const char *B, int32_t C);
extern    int __IQtoa24(char *A, const char *B, int32_t C);
extern    int __IQtoa23(char *A, const char *B, int32_t C);
extern    int __IQtoa22(char *A, const char *B, int32_t C);
extern    int __IQtoa21(char *A, const char *B, int32_t C);
extern    int __IQtoa20(char *A, const char *B, int32_t C);
extern    int __IQtoa19(char *A, const char *B, int32_t C);
extern    int __IQtoa18(char *A, const char *B, int32_t C);
extern    int __IQtoa17(char *A, const char *B, int32_t C);
extern    int __IQtoa16(char *A, const char *B, int32_t C);
extern    int __IQtoa15(char *A, const char *B, int32_t C);
extern    int __IQtoa14(char *A, const char *B, int32_t C);
extern    int __IQtoa13(char *A, const char *B, int32_t C);
extern    int __IQtoa12(char *A, const char *B, int32_t C);
extern    int __IQtoa11(char *A, const char *B, int32_t C);
extern    int __IQtoa10(char *A, const char *B, int32_t C);
extern    int  __IQtoa9(char *A, const char *B, int32_t C);
extern    int  __IQtoa8(char *A, const char *B, int32_t C);
extern    int  __IQtoa7(char *A, const char *B, int32_t C);
extern    int  __IQtoa6(char *A, const char *B, int32_t C);
extern    int  __IQtoa5(char *A, const char *B, int32_t C);
extern    int  __IQtoa4(char *A, const char *B, int32_t C);
extern    int  __IQtoa3(char *A, const char *B, int32_t C);
extern    int  __IQtoa2(char *A, const char *B, int32_t C);
extern    int  __IQtoa1(char *A, const char *B, int32_t C);


#define   __IQtoa30(A, B, C)   __IQNtoa(A, B, C, 30);
#define   __IQtoa29(A, B, C)   __IQNtoa(A, B, C, 29);
#define   __IQtoa28(A, B, C)   __IQNtoa(A, B, C, 28);
#define   __IQtoa27(A, B, C)   __IQNtoa(A, B, C, 27);
#define   __IQtoa26(A, B, C)   __IQNtoa(A, B, C, 26);
#define   __IQtoa25(A, B, C)   __IQNtoa(A, B, C, 25);
#define   __IQtoa24(A, B, C)   __IQNtoa(A, B, C, 24);
#define   __IQtoa23(A, B, C)   __IQNtoa(A, B, C, 23);
#define   __IQtoa21(A, B, C)   __IQNtoa(A, B, C, 21);
#define   __IQtoa22(A, B, C)   __IQNtoa(A, B, C, 22);
#define   __IQtoa20(A, B, C)   __IQNtoa(A, B, C, 20);
#define   __IQtoa19(A, B, C)   __IQNtoa(A, B, C, 19);
#define   __IQtoa18(A, B, C)   __IQNtoa(A, B, C, 18);
#define   __IQtoa17(A, B, C)   __IQNtoa(A, B, C, 17);
#define   __IQtoa16(A, B, C)   __IQNtoa(A, B, C, 16);
#define   __IQtoa15(A, B, C)   __IQNtoa(A, B, C, 15);
#define   __IQtoa14(A, B, C)   __IQNtoa(A, B, C, 14);
#define   __IQtoa13(A, B, C)   __IQNtoa(A, B, C, 13);
#define   __IQtoa12(A, B, C)   __IQNtoa(A, B, C, 12);
#define   __IQtoa11(A, B, C)   __IQNtoa(A, B, C, 11);
#define   __IQtoa10(A, B, C)   __IQNtoa(A, B, C, 10);
#define   __IQtoa9(A, B, C)    __IQNtoa(A, B, C, 9);
#define   __IQtoa8(A, B, C)    __IQNtoa(A, B, C, 8);
#define   __IQtoa7(A, B, C)    __IQNtoa(A, B, C, 7);
#define   __IQtoa6(A, B, C)    __IQNtoa(A, B, C, 6);
#define   __IQtoa5(A, B, C)    __IQNtoa(A, B, C, 5);
#define   __IQtoa4(A, B, C)    __IQNtoa(A, B, C, 4);
#define   __IQtoa3(A, B, C)    __IQNtoa(A, B, C, 3);
#define   __IQtoa2(A, B, C)    __IQNtoa(A, B, C, 2);
#define   __IQtoa1(A, B, C)    __IQNtoa(A, B, C, 1);
*/
//---------------------------------------------------------------------------
#define   _IQabs(N, A)      __IQabs(N, A)
#define   __IQabs(N, A)     __IQabs_##N(A)

#define   __IQabs_30(A)     labs(A)
#define   __IQabs_29(A)     labs(A)
#define   __IQabs_28(A)     labs(A)
#define   __IQabs_27(A)     labs(A)
#define   __IQabs_26(A)     labs(A)
#define   __IQabs_25(A)     labs(A)
#define   __IQabs_24(A)     labs(A)
#define   __IQabs_23(A)     labs(A)
#define   __IQabs_22(A)     labs(A)
#define   __IQabs_21(A)     labs(A)
#define   __IQabs_20(A)     labs(A)
#define   __IQabs_19(A)     labs(A)
#define   __IQabs_18(A)     labs(A)
#define   __IQabs_17(A)     labs(A)
#define   __IQabs_16(A)     labs(A)
#define   __IQabs_15(A)     labs(A)
#define   __IQabs_14(A)     labs(A)
#define   __IQabs_13(A)     labs(A)
#define   __IQabs_12(A)     labs(A)
#define   __IQabs_11(A)     labs(A)
#define   __IQabs_10(A)     labs(A)
#define   __IQabs_9(A)      labs(A)
#define   __IQabs_8(A)      labs(A)
#define   __IQabs_7(A)      labs(A)
#define   __IQabs_6(A)      labs(A)
#define   __IQabs_5(A)      labs(A)
#define   __IQabs_4(A)      labs(A)
#define   __IQabs_3(A)      labs(A)
#define   __IQabs_2(A)      labs(A)
#define   __IQabs_1(A)      labs(A)
//---------------------------------------------------------------------------
int32_t __PC_IQlog(int32_t a, int_fast8_t frac);

#define   _IQlog(N, A)      __IQlog(N, A)
#define   __IQlog(N, A)     __IQlog_##N(A)

#define   __IQlog_30(A)     __PC_IQlog(A, 30)
#define   __IQlog_29(A)     __PC_IQlog(A, 29)
#define   __IQlog_28(A)     __PC_IQlog(A, 28)
#define   __IQlog_27(A)     __PC_IQlog(A, 27)
#define   __IQlog_26(A)     __PC_IQlog(A, 26)
#define   __IQlog_25(A)     __PC_IQlog(A, 25)
#define   __IQlog_24(A)     __PC_IQlog(A, 24)
#define   __IQlog_23(A)     __PC_IQlog(A, 23)
#define   __IQlog_22(A)     __PC_IQlog(A, 22)
#define   __IQlog_21(A)     __PC_IQlog(A, 21)
#define   __IQlog_20(A)     __PC_IQlog(A, 20)
#define   __IQlog_19(A)     __PC_IQlog(A, 19)
#define   __IQlog_18(A)     __PC_IQlog(A, 18)
#define   __IQlog_17(A)     __PC_IQlog(A, 17)
#define   __IQlog_16(A)     __PC_IQlog(A, 16)
#define   __IQlog_15(A)     __PC_IQlog(A, 15)
#define   __IQlog_14(A)     __PC_IQlog(A, 14)
#define   __IQlog_13(A)     __PC_IQlog(A, 13)
#define   __IQlog_12(A)     __PC_IQlog(A, 12)
#define   __IQlog_11(A)     __PC_IQlog(A, 11)
#define   __IQlog_10(A)     __PC_IQlog(A, 10)
#define   __IQlog_9(A)      __PC_IQlog(A, 9)
#define   __IQlog_8(A)      __PC_IQlog(A, 8)
#define   __IQlog_7(A)      __PC_IQlog(A, 7)
#define   __IQlog_6(A)      __PC_IQlog(A, 6)
#define   __IQlog_5(A)      __PC_IQlog(A, 5)
#define   __IQlog_4(A)      __PC_IQlog(A, 4)
#define   __IQlog_3(A)      __PC_IQlog(A, 3)
#define   __IQlog_2(A)      __PC_IQlog(A, 2)
#define   __IQlog_1(A)      __PC_IQlog(A, 1)

//###########################################################################
#else   // MATH_TYPE == FLOAT_MATH
//###########################################################################
// If FLOAT_MATH is used, the IQmath library function are replaced by
// equivalent floating point operations:
//===========================================================================
#define   _iq(N)            float
//---------------------------------------------------------------------------
#define   _IQ(N, A)         (A)
//---------------------------------------------------------------------------
#define   _IQmod(N, A, B)   (fmodf(A, B))
//---------------------------------------------------------------------------
#define   _IQtoF(N, A)      (A)
//---------------------------------------------------------------------------
#define   _FtoIQ(N, A)      (A)
//---------------------------------------------------------------------------
//extern  float _satf(float A, float Pos, float Neg);
//#define   _IQsat(A, Pos, Neg)    _satf(A, Pos, Neg)
//
// The following define requires codegen tools V5.2.2 or later
//
#define   _IQsat(A, Pos, Neg)   (fmaxf(((fminf((A),(Pos)))),(Neg)))
//---------------------------------------------------------------------------
#define   _IQNtoM(A, N, M)      (A)
//---------------------------------------------------------------------------
#define   _IQmpy2(A)            ((A)*2.0F)
#define   _IQmpy4(A)            ((A)*4.0F)
#define   _IQmpy8(A)            ((A)*8.0F)
#define   _IQmpy16(A)           ((A)*16.0F)
#define   _IQmpy32(A)           ((A)*32.0F)
#define   _IQmpy64(A)           ((A)*64.0F)
    
#define   _IQdiv2(A)            ((A)*0.5F)
#define   _IQdiv4(A)            ((A)*0.25F)
#define   _IQdiv8(A)            ((A)*0.125F)
#define   _IQdiv16(A)           ((A)*0.0625F)
#define   _IQdiv32(A)           ((A)*0.03125F)
#define   _IQdiv64(A)           ((A)*0.015625F)
//---------------------------------------------------------------------------
#define   _IQmpy(N, A, B)       ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQrmpy(N, A,B)       ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQrsmpy(N, A, B)     ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQdiv(N, A, B)       ((float)(A) / (float)(B))
//---------------------------------------------------------------------------
#define   _IQsin(N, A)          sin(A)
//---------------------------------------------------------------------------
#define   _IQsinPU(N, A)        sin((A)*6.283185307F)
//---------------------------------------------------------------------------
#define   _IQasin(N, A)         asin(A)
//---------------------------------------------------------------------------
#define   _IQcos(N, A)          cos(A)
//---------------------------------------------------------------------------
#define   _IQcosPU(N, A)        cos((A)*6.283185307F)
//---------------------------------------------------------------------------
#define   _IQacos(N, A)         acos(A)
//---------------------------------------------------------------------------
#define   _IQtan(N, A)          tan(A)
//---------------------------------------------------------------------------
#define   _IQatan2(N, A, B)     atan2(A,B)
//---------------------------------------------------------------------------
#define   _IQatan2PU(N, A, B)   ((atan2(A,B)*(1.0F/6.283185307F)) >= 0.0F ? (atan2(A,B)*(1.0F/6.283185307F)):1.0F + (atan2(A,B)*(1.0F/6.283185307F)))
//---------------------------------------------------------------------------
#define   _IQatan(N, A)         atan(A)
//---------------------------------------------------------------------------
#define   _IQsqrt(N, A)         sqrt(A)
//---------------------------------------------------------------------------
#define   _IQisqrt(N, A)        (1.0/sqrt(A))
//---------------------------------------------------------------------------
#define   _IQexp(N, A)          exp(A)
//---------------------------------------------------------------------------
#define   _IQint(N, A)          ((int32_t) (A))
//---------------------------------------------------------------------------
#define   _IQfrac(N, A)         ((A) - (float)((int32_t) (A)))
//---------------------------------------------------------------------------
#define   _IQmpyIQX(N, A, IQA, B, IQB)      ((A)*(B))
//---------------------------------------------------------------------------
/* below is not supported currently
#define   __IQmpyI32(A,B)      ((A) * (float) (B))
#define   __IQ30mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ29mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ28mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ27mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ26mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ25mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ24mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ23mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ22mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ21mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ20mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ19mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ18mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ17mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ16mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ15mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ14mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ13mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ12mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ11mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ10mpyI32(A,B)    ((A) * (float) (B))
#define   __IQ9mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ8mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ7mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ6mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ5mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ4mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ3mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ2mpyI32(A,B)     ((A) * (float) (B))
#define   __IQ1mpyI32(A,B)     ((A) * (float) (B))
*/
//---------------------------------------------------------------------------
/*
#define   _IQmpyI32int(A,B)   ((int32_t) ((A) * (float) (B)))
#define   _IQ30mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ29mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ28mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ27mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ26mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ25mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ24mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ23mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ22mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ21mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ20mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ19mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ18mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ17mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ16mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ15mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ14mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ13mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ12mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ11mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ10mpyI32int(A,B) ((int32_t) ((A) * (float) (B)))
#define   _IQ9mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ8mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ7mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ6mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ5mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ4mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ3mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ2mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
#define   _IQ1mpyI32int(A,B)  ((int32_t) ((A) * (float) (B)))
*/
//---------------------------------------------------------------------------
/*
#define   _IQmpyI32frac(A,B)    ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ30mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ29mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ28mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ27mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ26mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ25mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ24mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ23mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ22mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ21mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ20mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ19mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ18mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ17mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ16mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ15mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ14mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ13mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ12mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ11mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ10mpyI32frac(A,B)  ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ9mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ8mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ7mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ6mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ5mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ4mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ3mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ2mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
#define   _IQ1mpyI32frac(A,B)   ((A) - (float)((int32_t) ((A) * (float) (B))))
*/
//---------------------------------------------------------------------------
#define   _IQmag(N, A, B)       sqrt((A)*(A) + (B)*(B))
//---------------------------------------------------------------------------
/* below is not supported currently
#define   _atoIQ(A)           atof(A)
#define   _atoIQ30(A)         atof(A)
#define   _atoIQ29(A)         atof(A)
#define   _atoIQ28(A)         atof(A)
#define   _atoIQ27(A)         atof(A)
#define   _atoIQ26(A)         atof(A)
#define   _atoIQ25(A)         atof(A)
#define   _atoIQ24(A)         atof(A)
#define   _atoIQ23(A)         atof(A)
#define   _atoIQ22(A)         atof(A)
#define   _atoIQ21(A)         atof(A)
#define   _atoIQ20(A)         atof(A)
#define   _atoIQ19(A)         atof(A)
#define   _atoIQ18(A)         atof(A)
#define   _atoIQ17(A)         atof(A)
#define   _atoIQ16(A)         atof(A)
#define   _atoIQ15(A)         atof(A)
#define   _atoIQ14(A)         atof(A)
#define   _atoIQ13(A)         atof(A)
#define   _atoIQ12(A)         atof(A)
#define   _atoIQ11(A)         atof(A)
#define   _atoIQ10(A)         atof(A)
#define   _atoIQ9(A)          atof(A)
#define   _atoIQ8(A)          atof(A)
#define   _atoIQ7(A)          atof(A)
#define   _atoIQ6(A)          atof(A)
#define   _atoIQ5(A)          atof(A)
#define   _atoIQ4(A)          atof(A)
#define   _atoIQ3(A)          atof(A)
#define   _atoIQ2(A)          atof(A)
#define   _atoIQ1(A)          atof(A)
*/
//---------------------------------------------------------------------------
/* below is not supported currently
#define   _IQtoa(A, B, C)     sprintf(A, B, C)
#define   __IQtoa30(A, B, C)   sprintf(A, B, C)
#define   __IQtoa29(A, B, C)   sprintf(A, B, C)
#define   __IQtoa28(A, B, C)   sprintf(A, B, C)
#define   __IQtoa27(A, B, C)   sprintf(A, B, C)
#define   __IQtoa26(A, B, C)   sprintf(A, B, C)
#define   __IQtoa25(A, B, C)   sprintf(A, B, C)
#define   __IQtoa24(A, B, C)   sprintf(A, B, C)
#define   __IQtoa23(A, B, C)   sprintf(A, B, C)
#define   __IQtoa22(A, B, C)   sprintf(A, B, C)
#define   __IQtoa21(A, B, C)   sprintf(A, B, C)
#define   __IQtoa20(A, B, C)   sprintf(A, B, C)
#define   __IQtoa19(A, B, C)   sprintf(A, B, C)
#define   __IQtoa18(A, B, C)   sprintf(A, B, C)
#define   __IQtoa17(A, B, C)   sprintf(A, B, C)
#define   __IQtoa16(A, B, C)   sprintf(A, B, C)
#define   __IQtoa15(A, B, C)   sprintf(A, B, C)
#define   __IQtoa14(A, B, C)   sprintf(A, B, C)
#define   __IQtoa13(A, B, C)   sprintf(A, B, C)
#define   __IQtoa12(A, B, C)   sprintf(A, B, C)
#define   __IQtoa11(A, B, C)   sprintf(A, B, C)
#define   __IQtoa10(A, B, C)   sprintf(A, B, C)
#define   __IQtoa9(A, B, C)    sprintf(A, B, C)
#define   __IQtoa8(A, B, C)    sprintf(A, B, C)
#define   __IQtoa7(A, B, C)    sprintf(A, B, C)
#define   __IQtoa6(A, B, C)    sprintf(A, B, C)
#define   __IQtoa5(A, B, C)    sprintf(A, B, C)
#define   __IQtoa4(A, B, C)    sprintf(A, B, C)
#define   __IQtoa3(A, B, C)    sprintf(A, B, C)
#define   __IQtoa2(A, B, C)    sprintf(A, B, C)
#define   __IQtoa1(A, B, C)    sprintf(A, B, C)
*/
//---------------------------------------------------------------------------
#define   _IQabs(N, A)      fabs(A)
//---------------------------------------------------------------------------
#define   _IQlog(N, A)      log(A)
//###########################################################################
#endif  // No more.
//###########################################################################

#endif  // __ELS_MATH_PORT_H__
