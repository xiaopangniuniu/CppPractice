//: 2025_Prime Cuts.cpp
// http://acm.tju.edu.cn/acm/showp2025.html
#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1010;
int isPrime[MAX],prime[MAX];

void getPrime()
{
    int i,j;
    for(i = 0; i < MAX; i++)
        isPrime[i] = 1;
    isPrime[1] = 0;
    for(i = 2; i < sqrt(MAX); i++)
        if(isPrime[i])
            for(j = i*2; j < MAX; j += i)
                isPrime[j] = 0;
    int k(1);
    for(i = 2; i < MAX; i++)
        if(isPrime[i])
        {
            prime[k] = i;
            k++;
        }
}

int main()
{
    getPrime();
    prime[0] = 1;
    int n,c;
    while(cin >> n >> c)
    {
        cout << n << " " << c << ":";
        int i(0),j;
        while(prime[i] <= n)
            i++;
        if(c*2 > i)
        {
            for(j = 0; j < i; j++)
                    cout << " " << prime[j];
        }
        else
        {
            for(j = i/2 - c + i%2; j <= i/2+c-1; j++)
                cout << " " << prime[j];
        }
        cout << endl << endl;
    }

    return 0;
}
