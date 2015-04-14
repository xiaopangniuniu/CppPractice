#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    
    long res(0), n(x);
    while (n)
    {
        res = res*10 + n%10;
        n /= 10;
    }
    cout << res << endl;
    return !(x^res);
}

int main(void)
{
    int n;
    while (cin >> n)
    {
        bool res = isPalindrome(n);
        cout << res << endl;
    }
    return 0;
}
