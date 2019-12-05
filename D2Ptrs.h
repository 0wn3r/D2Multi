#pragma once
#ifndef __D2PTRS_H__
#define __D2PTRS_H__

//#include "D2Structs.h"

#pragma warning ( push )
#pragma warning ( disable: 4245 )

#pragma optimize ( "", off )

#ifdef _DEFINE_VARS

#define D2OFFSET(o1)        o1
#define D2FUNC(v1,t1,t2,o1) typedef t1 D2##_##v1##_t t2; D2##_##v1##_t *    D2##_##v1 = (D2##_##v1##_t *)D2OFFSET(o1);
#define D2VAR(v1,t1,o1)     typedef t1 D2##_##v1##_t;    D2##_##v1##_t *p_##D2##_##v1 = (D2##_##v1##_t *)D2OFFSET(o1);
#define D2ASM(v1,o1)        DWORD D2##_##v1 = D2OFFSET(o1);

#else

#define D2FUNC(v1,t1,t2,o1) typedef t1 D2##_##v1##_t t2; extern D2##_##v1##_t *D2##_##v1;
#define D2VAR(v1,t1,o1)     typedef t1 D2##_##v1##_t;    extern D2##_##v1##_t *p_##D2##_##v1;
#define D2ASM(v1,o1)        extern DWORD D2##_##v1;

#endif
#define _D2PTRS_START D2_InitMPQ

D2FUNC(InitMPQ, DWORD __fastcall, (char *mpqfile, char *dll, int v3, int timeout), 0x117332) // 1.14d

#define _D2PTRS_END   D2_InitMPQ

#undef FUNCPTR
#undef VARPTR
#undef ASMPTR

#pragma warning ( pop )

#pragma optimize ( "", on )

#endif
