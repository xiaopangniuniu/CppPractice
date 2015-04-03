//g++ -m32 -g -O3 -o detectToken main.cpp detectToken.cpp detectToken.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "detectToken.h"
//#include "SipTokenMessage.h"

//Test cases:

//The main aim of puting pBlob here rather than main() is about the stack capability of main()
const int TC_LEN = 6;
unsigned char TC_Data[TC_LEN][100000] = {
        //1. Q.850 in header (large string)
        "Q.850 ;cause=16 ;\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\n",
        //2. Q.850 in tail (large string)
        "ReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nQ.850 ;cause=16",
        //3. Normal Case
        "   SIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\naaaaaaaaaaaaaaaaaaaaaaaaaaaaa Q.850 ;cause=16 ;text=\"Terminated\"\nQ.850 ;cause=18 SIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\naaaaaaaaaaaaaaaaaaaaaaaaaaaaa SIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\n",
        //4. Without Q.850
        "ReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\nReasonHeader: SIP ;cause=200\n",
        //5. Special case for strstrMode
        "QQ.Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;Q.85x ;cause=200\nQ.850 ;cause=17 ;",
        //6. Q.850 with error cause
        "   SIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cau\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cau\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cau\nSIP ;cause=200\n\nQ.850 ;cause=a SIP ;cause=200\n Q.850 ;cause=17 SIP ;cause=200\nSIP ;cau\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cau\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cau\nSIP ;cause=200\nSIP ;cause=200\nSIP ;cau\nSIP ;cause=200\nSIP SIP ;caudafsdafafdsadsaf832738922737*&%$&(^%^&*(*&^%$%^&*(*&^%^&*&^%$%^&*&^%$%^&*dafsdafafdsadsaf832738922737*&%$&(^%^&*(*&^%$%^&*(*&^%^&"
};

char TC_Desc[TC_LEN][100] =
{
    "Q.850 in header (large string)",
    "Q.850 in tail (large string)",
    "Normal Case",
    "Without Q850",
    "Special case for strstrMode",
    "Q.850 with error cause"
};

unsigned short responseCode_ = 0;
unsigned char reasonHeaderQ850Present_ = 0;

void test (unsigned char * pBlob, double &dur1, double &dur2, double &dur3);

int main()
    {

    double dur1[TC_LEN], dur2[TC_LEN], dur3[TC_LEN];
    int i;
    for (i = 0; i < TC_LEN; i++)
    {
        printf ("============= TC %d Desc: %s =============\n", i+1, TC_Desc[i]);
        test (TC_Data[i], dur1[i], dur2[i], dur3[i]);
    }

    printf("\nTest result \n");
    printf("TC \t StrstrMode\t\t enhance BFMode\t\t enhance SundayMode\n");
    printf("--------------------------------------------------------------------------\n");
    for (i = 0; i < TC_LEN; i++)
        {
        printf(" %d \t %.2f\t\t\t%.2f\t\t\t%.2f (%s)\n", i+1, dur1[i], dur2[i], dur3[i], TC_Desc[i]);
        }
    printf("--------------------------------------------------------------------------\n\n");

    return 0;
    }


void test (unsigned char * pBlob, double &dur1, double &dur2, double &dur3)
    {
    printf("Test Case\n-------------\n%s\n-------------\n\n", pBlob);
    int var_len = strlen((char*)pBlob);
    long loop_num = 10000000L;
    long i;
    clock_t start, finish;

    //Call strstrMethod()
    printf("==========================\nStart test StrstrMode()\n");
    i = loop_num;
    start = clock();
    while (i--)
        strstrMode(pBlob, var_len);
    finish = clock();
    dur1 = (double)(finish - start) /CLOCKS_PER_SEC;
    if(reasonHeaderQ850Present_)
        printf("StrstrMode() Response Code: %d \n", (int) responseCode_);
    else
        printf("StrstrMode() cannot find the RC.\n");
    printf("End test StrstrMode () spends %f seconds\n\n", dur1);


    //Call bruteForce()
    printf("==========================\nStart test bruteForce()\n");
    i = loop_num;
    start = clock();
    while (i--)
        eBruteForce(pBlob, var_len);
    finish = clock();
    dur2 = (double)(finish - start) /CLOCKS_PER_SEC;
    if(reasonHeaderQ850Present_)
        printf("bruteForce() Response Code: %d \n", (int) responseCode_);
    else
        printf("bruteForce() cannot find the RC.\n");
    printf("End test bruteForce() spends %f seconds\n\n", dur2);

    //Call sundayMode()
    printf("==========================\nStart test sundayMode()\n");
    i = loop_num;
    start = clock();
    while (i--)
        eSundayMode(pBlob, var_len);
    finish = clock();
    dur3 = (double)(finish - start) /CLOCKS_PER_SEC;
    if(reasonHeaderQ850Present_)
        printf("sundayMode() Response Code: %d \n", (int) responseCode_);
    else
        printf("sundayMode() cannot find the RC.\n");
    printf("End test sundayMode() spends %f seconds\n\n", dur3);

    return;
    }
