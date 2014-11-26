//: 1551_Digital Roots.cpp
// http://acm.tju.edu.cn/acm/showp1551.html
#include <iostream>
#include <cstring>
#include <cmath>//log(),pow()
using namespace std;

char n[10000] = {0};

int main()
{
    while(cin >> n && strcmp(n,"0") != 0)
    {
        int len = strlen(n);
        int i,m(0);
        for(i = 0; i < len; i++)
            m = m + (int)n[i] - 48;
        while(m >= 10)
        {
            int bit = (int)(log(m)/log(10)) + 1;//?§Ø???????????¦Ë??
            int i,sum(0);
            for(i = bit-1; i >= 0; i--)
            {
                double x = pow(10.0,i);
                sum += (int)(m/x);
                m -= x*(int)(m/x);
            }
            m = sum;
        }
        cout << m << endl;

        memset(n,0,sizeof(n));
    }

    return 0;
}
