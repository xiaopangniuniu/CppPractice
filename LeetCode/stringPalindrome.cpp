#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    if (s.length() == 0 || s.length() == 1)
        return true;

    *s++-'a'
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
    string s;
    while (cin >> s)
    {
        bool res = isPalindrome(s);
        cout << res << endl;
    }
    return 0;
}

