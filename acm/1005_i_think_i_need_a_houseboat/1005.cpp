/*
 * Web Site: http://poj.org/problem?id=1005
 *           http://acm.tju.edu.cn/acm/showp1575.html
 * Date: 11/5/2013
 * Command: g++ -m32 -g -o 1005 1005.cpp
 * Description:
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // const double PI = acos(0)*2;
    const double Pi = 3.1415;
    int n;
    cin >> n;
    int i;
    for (i = 1; i <= n; ++i)
    {
        double x_coor, y_coor, area;
        cin >> x_coor >> y_coor;
        area = (x_coor*x_coor + y_coor*y_coor)*Pi/2.0;
        int years = area/50 + 1;
        printf("Property %d: This property will begin eroding in year %d.\n", i, years);
    }
    cout << "END OF OUTPUT." << endl;

    return 0;
}
