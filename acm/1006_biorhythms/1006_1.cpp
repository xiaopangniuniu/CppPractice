/*
 * Web Site: http://poj.org/problem?id=1006
 * Date: 11/8/2013
 * Command: g++ -m32 -g -o 1006 1006_1.cpp
 * Ref: http://www.cnblogs.com/walker01/archive/2010/01/23/1654880.html
 * Solution: 28*33%23 = 4, 23%4 = 3, 4-3 = 1 => (28*33*(23+1)/4)%23 = 1
 *           23*33%28 = 3, 28%3 = 1, 3-1 = 2 => (23*33*(28*2+1)/3)%28 = 1
 *           23*28%33 = 17, 33%17 = 16, 17-16 = 1 => (23*28*(33*1+1)/17)%33 = 1
 */
#include <iostream>

using namespace std;

int main()
{
/*    // another solution to get the number
    for(i=1;i<=23;i++)
        if((33*28*i)%23==1)
            break;*/
    const int a = 28*33*(23+1)/4;
    const int b = 23*33*(28*2+1)/3;
    const int c = 23*28*(33*1+1)/17;
    const int lcm = 23*28*33; // lowest common multiple of the three numbers (L.C.M)
    int physical, emotional, intellectual, days;
    int i = 0;
    while (cin >> physical >> emotional >> intellectual >> days)
    {
        if (-1 == physical && -1 == emotional && -1 == intellectual && -1 == days)
            break;
        // plus lcm once to avoid day becomes to negative
        int day = (physical*a + emotional*b + intellectual*c - days + lcm)%lcm;
        if (0 == day)
            day = lcm;
        cout << "Case " << ++i << ": the next triple peak occurs in " << day << " days." << endl;
    }
    return 0;
}
