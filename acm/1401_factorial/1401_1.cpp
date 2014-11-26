//: 1065_Factorial.cpp
// http://acm.tju.edu.cn/acm/showp1065.html
#include <iostream>
using namespace std;

int main()
{
    int n,N;
    cin >> n;
    while(n--)
    {
        cin >> N;
        if(N < 1 || N > 1000000000)
            return 1;
        int count(0);
        if(N < 5)
            count = 0;
        else
        {
            while(N != 0)
            {
                count += N/5;
                N /= 5;
            }
        }
        cout << count << endl;
    }

    return 0;
}
