//g++ -m32 -g -O3 -o palindrome main.cpp palindrome.cpp palindrome.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "palindrome.h"

//using namespace std;

//Test cases:
const int TC_NUM = 10;
char TC_Data[TC_NUM][100000] = {//N: [1..100,000]
        //1. example from the problem description
        "dooernedeevrvn",
        //2.
        "cc",
        //3. extreme_odd_elements
        "abbac",
        //4. extreme_single_character
        "a",
        //5. extreme_two_characters
        "ab",
        //6. extreme_len3
        "aka",
        //7. extreme_all_chars
        "abcdefghijklmnopqrstuvwxyz",
        //8. extreme_z_chars
        "z",
        //9. medium
        "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
        //10. big1: words with length 60000, multiple runs
        "xabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
};

char TC_Desc[TC_NUM][100] =
{
    "example from the desc",
    "normal case\t",
    "extreme_odd_elements",
    "extre_single_character",
    "extre_two_characters",
    "extreme_len3\t",
    "extreme_all_chars",
    "extreme_z_chars\t",
    "medium\t\t",
    "big1\t\t"
};

void test (char *S, double &dur1, int &res1, double &dur2, int &res2, double &dur3, int &res3);

int main()
{
    double dur1[TC_NUM], dur2[TC_NUM], dur3[TC_NUM];
    int res1[TC_NUM], res2[TC_NUM], res3[TC_NUM];
    for (int i = 0; i < TC_NUM; ++i)
    {
        test(TC_Data[i], dur1[i], res1[i], dur2[i], res2[i], dur3[i], res3[i]);
    }

    printf("Test name\t\t S1: Running time\tResult\t S2: Running time\tResult\t S3: Running time\tResult\n");
    for (int i = 0; i < TC_NUM; ++i)
    {
        printf("%s\t     %.2f\t\t%d\t     %.2f\t\t%d\t     %.2f\t\t%d\n", TC_Desc[i], dur1[i], res1[i], dur2[i], res2[i], dur3[i], res3[i]);
    }

    return 0;
}

void test (char *S, double &dur1, int &res1, double &dur2, int &res2, double &dur3, int &res3)
{
    long loop_num = 10000000L;//0000000
    long i;
    clock_t start, finish;

    i = loop_num;
    start = clock();
    while (i--)
        res1 = isAnagramOfPalindrome_solution1(S);
    finish = clock();
    dur1 = (double)(finish - start) /CLOCKS_PER_SEC;

    i = loop_num;
    start = clock();
    while (i--)
        res2 = isAnagramOfPalindrome_solution2(S);
    finish = clock();
    dur2 = (double)(finish - start) /CLOCKS_PER_SEC;

    i = loop_num;
    start = clock();
    while (i--)
        res3 = isAnagramOfPalindrome_solution3(S);
    finish = clock();
    dur3 = (double)(finish - start) /CLOCKS_PER_SEC;

    return;
    }
