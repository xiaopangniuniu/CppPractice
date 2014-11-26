//: 1549_u Calculate e.cpp
// http://acm.tju.edu.cn/acm/showp1549.html
#include <iostream>
#include <cmath>
using namespace std;

int factorial(int a)
{
    int res;
    if(a == 0 || a == 1)
        res = 1;
    else
    {
        int i;
        res = 1;
        for(i = 1; i <= a; i++)
            res *= i;
    }
    return res;
}

int main()
{
    int n;
    double e;
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
    cout << "2 2.5" << endl;
    for(n = 3; n <= 9; n++)
    {
        cout << n << " ";
        int i;
        e = 0;
        for(i = 0; i <= n; i++)
            e += (double)(1.0/factorial(i));
        printf("%.9lf",e);
        cout << endl;
    }

    return 0;
}
