//: 2051_Keep on Truckin'.cpp
// http://acm.tju.edu.cn/acm/showp2051.html
#include <iostream>
using namespace std;
const int wheeler = 168;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a <= 168)
        cout << "CRASH " << a << endl;
    else if(b <= 168)
        cout << "CRASH " << b << endl;
    else if(c <= 168)
        cout << "CRASH " << c << endl;
    else
        cout << "NO CRASH" << endl;

    return 0;
}
