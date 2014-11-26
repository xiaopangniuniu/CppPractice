/*
 * Web Site: http://poj.org/problem?id=1004
 *           http://acm.tju.edu.cn/acm/showp1574.html
 * Date: 11/5/2013
 * Command: g++ -m32 -g -o 1004 1004.cpp
 * Description:
 */
#include <iostream>

using namespace std;

int main()
{
    double penny, sum(0);
    int i = 0;
    while (cin >> penny)
    {
        sum += penny;
        if (++i >= 12)
            break;
    }
    printf("$%.2f", sum/12.0);
    return 0;
}
