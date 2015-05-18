#include <iostream>
using namespace std;

int reverse(int x) 
{
    long res(0);
    while (x)
    {
        res = res*10 + x%10;
        x /= 10;
    }
    if (res > 0x7fffffff || res < -(0x7fffffff))
        res = 0;
    
    cout << res << endl;
    return res;
}

int main(void)
{
    int n, m;
    while(cin >> n)
    {
    m = reverse(n);
    }
    
    return 0;
}
