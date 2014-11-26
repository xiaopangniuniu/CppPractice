//: 1695_Count on Canton.cpp
//http://acm.tju.edu.cn/acm/showp1695.html
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n < 1 || n > 10000000)
            return 1;
        if(n == 1)
        {
            cout << "TERM 1 IS 1/1" << endl;
            break;
        }
        else
        {
            int i,m = n;
            for(i = 1; i < n; i++)
            {
                m -= i;
                if(m <= i+1)
                {
                    if((i+1)%2 != 0)
                        cout << "TERM " << n << " IS " << (i+1-m+1) << "/" << m << endl;
                    else
                        cout << "TERM " << n << " IS " << m << "/" << (i+1-m+1) << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
