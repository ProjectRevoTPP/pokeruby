#include <stdarg.h>
#include <stdio.h>
#include "gba/gba.h"
#include "config.h"

#define AGB_PRINT_FLUSH_ADDR 0x9FE209D
#define AGB_PRINT_STRUCT_ADDR 0x9FE20F8
#define AGB_PRINT_PROTECT_ADDR 0x9FE2FFE
#define WSCNT_DATA (WAITCNT_PHI_OUT_16MHZ | WAITCNT_WS0_S_2 | WAITCNT_WS0_N_4)

// for auto no$gba support, the string "no$gba" should be at this address.
// except it's not, blame Martin, hence I'm letting the user deal with this nonsense.
#define NOGBAIDADDR 0x4FFFA00
#define NOGBAPRINTADDR 0x4FFFA14

struct AGBPrintStruct
{
    u16 m_nRequest;
    u16 m_nBank;
    u16 m_nGet;
    u16 m_nPut;
};

typedef void (*LPFN_PRINT_FLUSH)(void);

#ifndef NDEBUG

void AGBPrintFlush1Block(void);

void AGBPrintInit(void)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    u16 *pWSCNT = (u16 *)REG_ADDR_WAITCNT;
    u16 *pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    u16 nOldWSCNT = *pWSCNT;
    *pWSCNT = WSCNT_DATA;
    *pProtect = 0x20;
    pPrint->m_nRequest = pPrint->m_nGet = pPrint->m_nPut = 0;
    pPrint->m_nBank = 0xFD;
    *pProtect = 0;
    *pWSCNT = nOldWSCNT;
}

static void AGBPutcInternal(const char cChr)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    u16 *pPrintBuf = (u16 *)(0x8000000 + (pPrint->m_nBank << 16));
    u16 *pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    u16 nData = pPrintBuf[pPrint->m_nPut / 2];
    *pProtect = 0x20;
    nData = (pPrint->m_nPut & 1) ? (nData & 0xFF) | (cChr << 8) : (nData & 0xFF00) | cChr;
    pPrintBuf[pPrint->m_nPut / 2] = nData;
    pPrint->m_nPut++;
    *pProtect = 0;
}

void AGBPutc(const char cChr)
{
    u16 *pWSCNT = (u16 *)REG_ADDR_WAITCNT;
    u16 nOldWSCNT = *pWSCNT;
    volatile struct AGBPrintStruct *pPrint;
    *pWSCNT = WSCNT_DATA;
    AGBPutcInternal(cChr);
    *pWSCNT = nOldWSCNT;
    pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    if (pPrint->m_nPut == ((pPrint->m_nGet - 1) & 0xFFFF))
        AGBPrintFlush1Block();
}

void AGBPrint(const char *pBuf)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    u16 *pWSCNT = (u16 *)REG_ADDR_WAITCNT;
    u16 nOldWSCNT = *pWSCNT;
    *pWSCNT = WSCNT_DATA;
    while (*pBuf)
    {
        AGBPutc(*pBuf);
        pBuf++;
    }
    *pWSCNT = nOldWSCNT;
}

void AGBPrintf(const char *pBuf, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, pBuf);
    vsprintf(bufPrint, pBuf, vArgv);
    va_end(vArgv);
    AGBPrint(bufPrint);
}

static void AGBPrintTransferDataInternal(u32 bAllData)
{
    LPFN_PRINT_FLUSH lpfnFuncFlush;
    u16 *pIME;
    u16 nIME;
    u16 *pWSCNT;
    u16 nOldWSCNT;
    u16 *pProtect;
    volatile struct AGBPrintStruct *pPrint;

    pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    lpfnFuncFlush = (LPFN_PRINT_FLUSH)AGB_PRINT_FLUSH_ADDR;
    pIME = (u16 *)REG_ADDR_IME;
    nIME = *pIME;
    pWSCNT = (u16 *)REG_ADDR_WAITCNT;
    nOldWSCNT = *pWSCNT;
    *pIME = nIME & ~1;
    *pWSCNT = WSCNT_DATA;

    if (bAllData)
    {
        while (pPrint->m_nPut != pPrint->m_nGet)
        {
            *pProtect = 0x20;
            lpfnFuncFlush();
            *pProtect = 0;
        }
    }
    else if (pPrint->m_nPut != pPrint->m_nGet)
    {
        *pProtect = 0x20;
        lpfnFuncFlush();
        *pProtect = 0;
    }

    *pWSCNT = nOldWSCNT;
    *pIME = nIME;
}

void AGBPrintFlush1Block(void)
{
    AGBPrintTransferDataInternal(FALSE);
}

void AGBPrintFlush(void)
{
    AGBPrintTransferDataInternal(TRUE);
}

void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram)
{
    if (nStopProgram)
    {
        AGBPrintf("ASSERTION FAILED  FILE=[%s] LINE=[%d]  EXP=[%s] \n", pFile, nLine, pExpression);
        AGBPrintFlush();
        asm(".hword 0xEFFF");
    }
    else
    {
        AGBPrintf("WARING FILE=[%s] LINE=[%d]  EXP=[%s] \n", pFile, nLine, pExpression);
    }
}

// nogba print function, uncomment to use
/*
void NOGBAPrint(const char *pBuf)
{
    *(volatile u32*)NOGBAPRINTADDR = (u32)pBuf;
}
*/

#endif