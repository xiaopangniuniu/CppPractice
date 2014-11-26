/*
 * Web Site: http://poj.org/problem?id=1218
 *           http://acm.tju.edu.cn/acm/showp2076.html
 * Date: 1/14/2014
 * Command: g++ -m32 -g -o 1218 1218.cpp
 * Note: Square number
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i;
    for (i = 0; i < N; ++i)
    {
        int n; // cells & rounds number
        cin >> n;
        // escaped number
        cout << (int)sqrt((double)n) << endl;
    }
    return 0;
}
