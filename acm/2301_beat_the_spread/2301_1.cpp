//: 1457_Beat the Spread!.cpp
// http://acm.tju.edu.cn/acm/showp1457.html
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,s,d,a,b;
    cin >> n;
    while(n--)
    {
        cin >> s >> d;
        if(s < d)
            cout << "impossible" << endl;
        else
        {
            if((s+d)%2 == 0)
            {
                a = (s+d)/2;
                b = (s-d)/2;
                cout << a << " " << b << endl;
            }
            else
                cout << "impossible" << endl;
        }
    }

    return 0;
}
