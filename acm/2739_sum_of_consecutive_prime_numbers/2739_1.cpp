//: 2010_Sum of Consecutive Prime Numbers.cpp
// http://acm.tju.edu.cn/acm/showp2010.html
#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10000;
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
    int k(0);
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
    int n;
    while(cin >> n && n != 0)
    {
        int count(0),i,j;
        for (i = 0; prime[i] <= n; i++)
        {
            int sum = 0;
            for (j = i; sum < n; j++)
            {
                sum += prime[j];
                if (sum == n)
                {
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
