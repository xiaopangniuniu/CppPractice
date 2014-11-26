/*
 * Web Site: http://poj.org/problem?id=1316
 *           http://acm.tju.edu.cn/acm/showp1730.html
 * Date: 1/14/2014
 * Command: g++ -m32 -g -o 1316 1316.cpp
 */
#include <iostream>
using namespace std;

int main()
{
    int self_number[10050] = {0};
    int i;
    for (i = 1; i < 10000; ++i)
    {
        int g = i + i/1000 + (i/100)%10 + (i/10)%10 + i%10;
        self_number[g] = 1;
    }
    for (i = 1; i < 10000; ++i)
    {
        if (0 == self_number[i])
            cout << i << endl;
    }
    return 0;
}
