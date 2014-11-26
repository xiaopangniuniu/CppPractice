//: 1171_Goldbach's Conjecture.cpp
// http://acm.tju.edu.cn/acm/showp1171.html
#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int n)//?§Ø?????????????
{
    //if(n == 2 || n == 3)
    //  return 1;//??????
    if(n%2 == 0)
        return 0;//???2???????????????
    int i;
    for(i = 3; i <= sqrt(n); i += 2)//??n????3??????n?????????
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    while(n != 0)
    {
        if(n < 6 || n > 1000000)
            return 1;
        if(n%2 != 0)
            return 1;
        int i;
        bool flag = false;
        for(i = 3; i <= n/2; i++)
        {
            if(isPrime(i) && isPrime(n-i))
            {
                cout << n << " = " << i << " + " << (n-i) << endl;
                flag = true;
                break;
            }
        }
        if(flag == false)
            cout << "Goldbach's conjecture is wrong." << endl;
        cin >> n;
    }

    return 0;
}
