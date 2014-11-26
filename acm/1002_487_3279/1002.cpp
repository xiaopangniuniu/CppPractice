/*
 * Web Site: http://poj.org/problem?id=1002
 * Date: 11/4/2013
 * Command: g++ -m32 -g -O3 -o 1002 1002.cpp
 * Description:
 */
#include <iostream>
#include <algorithm> // sort()

using namespace std;

int main()
{
    // WA: MAX_TELE_NUM_LEN=16 is too small!
    const int MAX_TELE_NUM_LEN = 55;

    int n;
    char telephone_num[MAX_TELE_NUM_LEN];
    cin >> n;
    int *int_tele_num = (int*)malloc((n+1)*sizeof(int));
    int i;
    for (i = 0; i < n; ++i)
    {
        cin >> telephone_num;
        int j, k;
        int_tele_num[i] = 0;
        for (j = 0, k = 0; k < 7; ++j) // telephone_num[j] != '\0'
        {
            if (telephone_num[j] >= 'A' && telephone_num[j] <= 'Z')
            {
                int_tele_num[i] *= 10;
                // the keypad of a phone supplies the mapping of letters to numbers
                int_tele_num[i] += (telephone_num[j]-'A'-(telephone_num[j]>'Q'))/3 + 2;
                ++k;
            }
            else if (telephone_num[j] >= '0' && telephone_num[j] <= '9')
            {
                int_tele_num[i] *= 10;
                int_tele_num[i] += telephone_num[j] - '0';
                ++k;
            }
        }
        // cout << int_tele_num[i] << endl;
    }
    sort(int_tele_num, int_tele_num+n);
    char dup_flag = 0;
    for (i = 0; i < n; ++i)
    {
        int times(1);
        // note that int_tele_num is an ordered array
        while (int_tele_num[i] == int_tele_num[i+1])
        {
            ++i;
            ++times;
        }
        if (times > 1)
        {
            dup_flag = 1;
            // here is the WA:
            // cout << int_tele_num[i]/10000 << "-" << int_tele_num[i]%10000 << " " << times << endl;
            // for 000-0000 case
            printf("%03d-%04d %d\n", int_tele_num[i]/10000, int_tele_num[i]%10000, times);
        }
    }
    if (0 == dup_flag)
        cout << "No duplicates."  << endl;

    free(int_tele_num);

    return 0;
}
