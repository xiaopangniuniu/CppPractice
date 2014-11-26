/*
 * Web Site: http://poj.org/problem?id=1001
 * Date: 11/4/2013
 * Command: g++ -m32 -g -O3 -o 1001 1001_1.cpp
                    i   0   1   2   3   4   5   6   7
                        1   8   6   7   1   0   4   1
                    j                   0   1   2   3
                                    4   3   2   1
carry:              0   0   0   0   0   0   0   0       j
                        1   8   6   7   1   0   4   1   3
carry:          0   1   1   1   0   0   0   0
                    2   6   2   4   2   0   8   2       2
carry:      0   2   1   2   0   0   1   0
                3   4   8   1   3   0   2   3           1
carry:  0   3   2   2   0   0   1   0
            4   2   4   8   4   0   6   4               0
carry:  0   1   1   2   1   1   1   0   1   0   0
        0   8   10  16  27  17  15  16  8   11  6   1
            8   0   6   7   7   5   6   8   1   6   1
i+j+1       1   2   3   4   5   6   7   8   9   10  11
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DIGIT=200;
const int MAX_LEN=10;

void large_int_multiply (const char* multiplicand, const char* multiplier, char* result)
{
    int len_multiplicand = strlen(multiplicand);
    int len_multiplier = strlen(multiplier);
    int len_total = len_multiplicand + len_multiplier;

/*    int *mid_res;
    mid_res = (int*)malloc(len_total*sizeof(int));*/
    int mid_res[MAX_DIGIT];
    memset(mid_res, 0, sizeof(mid_res));

    int i, j;
    for (i = 0; i < len_multiplicand; ++i)
        for (j = 0; j < len_multiplier; ++j)
            mid_res[i+j+1] += (multiplicand[i]-'0') * (multiplier[j]-'0');
    // add the carry
    for (i = len_total-1; i > 0; --i)
    {
        if (mid_res[i] >= 10)
        {
            mid_res[i-1] += mid_res[i]/10;
            mid_res[i] %= 10;
        }
    }
    i = 0;
    // remove the front zeros
    while (0 == mid_res[i])
        ++i;
    if (i >= len_total)
    {
        result[0] = '0';
        result[1] = '\0';
    }
    else
    {
        for (j = 0; i < len_total; ++j, ++i)
            result[j] = mid_res[i] + '0';
        result[j] = '\0';
    }

    return;
}

int main()
{
    char R[MAX_LEN];
    char handledR[MAX_DIGIT];
    int n;

    while (cin >> R >> n)
    // while(scanf("%s%d",R,&n)!=EOF)
    {
        if (0 == n)
        {
            cout << "1" << endl;
            continue;
        }

        // find the point place
        char* pPos = strchr(R, '.');
        int len_R = strlen(R);
        strcpy(handledR, "1");

        // R without point, such as 80
        if (NULL == pPos)
        {
            while (n--)
                large_int_multiply(R, handledR, handledR);
            cout << handledR << endl;
            continue;
        }
        else
        {
            int decimal_num = (len_R-1 - (pPos-R)) * n;
            // remove the point
            // the range of i should be 0-len_R rather than (len_R-1)
            // because '\0' should be included also!!
            int i;
            for (i = 0; i < len_R; ++i)
            {
                if(i >= pPos-R)
                {
                    R[i] = R[i+1];
                }
            }
            strcpy(handledR, "1");
            while (n--)
                large_int_multiply(R, handledR, handledR);
            if (strcmp(handledR, "0") == 0)
            {
                cout << handledR << endl;
                continue;
            }
            // remove the end zeros from the back
            // calculate the new decimal numbers
            int t = decimal_num-strlen(handledR);
            if (t > 0)
            {
                for (i = strlen(handledR) - 1; '0' == handledR[i]; --i)
                {
                    handledR[i] = '\0';
                }
                cout << ".";
                for (i = 0; i < t;++i)
                {
                    cout << "0";
                }
                cout << handledR << endl;
            }
            else
            {
                // add the point
                for (i = 0; i < -t; ++i)
                {
                    cout << handledR[i];
                }
                int j;
                for (j = strlen(handledR) - 1; '0' == handledR[j] && j >= i; --j)
                {
                    handledR[j] = '\0';
                }
                if (j < i)
                    cout << endl;
                else
                    cout << "." << handledR+i << endl;
            }
        }
    }

    return 0;
}
