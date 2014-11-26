//: 1380_A multiplication game.cpp
// http://acm.tju.edu.cn/acm/showp1380.html
#include <iostream>
using namespace std;

int main()
{
    long long n;
    while(cin >> n)
    {
        int p(1);
        while(1)
        {
            p *= 9;
            if(p >= n)
            {
                cout << "Stan wins." << endl;
                break;
            }
            p *= 2;
            if(p >= n)
            {
                cout << "Ollie wins." << endl;
                break;
            }
        }
    }

    return 0;
}
