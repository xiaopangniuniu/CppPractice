/*
 * Web Site: http://poj.org/problem?id=1003
 * Date: 11/5/2013
 * Command: g++ -m32 -g -o 1003 1003.cpp
 * Description:
 */
#include <iostream>

using namespace std;

int main()
{
    float card_len;
    while (cin >> card_len && 0.00 != card_len)
    {
/*        if (card_len <= 0.5)
            cout << "1 card(s)" << endl;*/
        int i;
        float sum(0);
        for (i = 2; sum <= card_len; ++i)
        {
            sum += (float)1/i;
            // cout << sum << endl;
        }
        cout << i-2 << " card(s)" << endl;
    }
    return 0;
}
