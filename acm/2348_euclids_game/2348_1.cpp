//: 1410_Euclid's Game.cpp
// http://acm.tju.edu.cn/acm/showp1410.html
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m,n;
    while(cin >> m >> n && m != 0 && n != 0)
    {
        if(m < n)
        {
            int tmp;
            tmp = m;
            m = n;
            n = tmp;
        }
        if(m == n || m > ((1+sqrt(5))/2) * n)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }

    return 0;
}
