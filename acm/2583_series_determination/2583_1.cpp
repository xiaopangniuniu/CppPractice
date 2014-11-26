//: 2056_Series Determination.cpp
// http://acm.tju.edu.cn/acm/show_code.php
#include <iostream>
using namespace std;

int main()
{
    int f[6] = {0};
    int a,b,c;
    while(cin >> f[0] >> f[1] >> f[2])
    {
        c = f[0];
        a = (f[2] - 2*f[1] + c)/2;
        b = f[1] - c - a;
        f[3] = 3*3*a + 3*b + c;
        f[4] = 4*4*a + 4*b + c;
        f[5] = 5*5*a + 5*b + c;
        cout << f[3] << " " << f[4] << " " << f[5] << endl;
    }

    return 0;
}
