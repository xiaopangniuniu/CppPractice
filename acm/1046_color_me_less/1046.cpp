/*
 * Web Site: http://poj.org/problem?id=1046
 *           http://acm.tju.edu.cn/acm/showp1557.html
 * Date: 1/14/2014
 * Command: g++ -m32 -g -o 1046 1046.cpp
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int targetRgb[16][3] = {0};
    int i;
    for (i = 0; i < 16; ++i)
        cin >> targetRgb[i][0] >> targetRgb[i][1] >> targetRgb[i][2];
    int arbitraryRgb[3] = {0};
    while (cin >> arbitraryRgb[0] >> arbitraryRgb[1] >> arbitraryRgb[2])
    {
        if (-1 == arbitraryRgb[0] &&
            -1 == arbitraryRgb[1] &&
            -1 == arbitraryRgb[2])
            break;
        int distance(-1), pos(0);
        for (i = 0; i < 16; ++i)
        {
            if (targetRgb[i][0] == arbitraryRgb[0] &&
                targetRgb[i][1] == arbitraryRgb[1] &&
                targetRgb[i][2] == arbitraryRgb[2])
            {
                pos = i;
                break;
            }
            int tmp_dis(0), j;
            for (j = 0; j < 3; ++j)
            {
                tmp_dis += (targetRgb[i][j]-arbitraryRgb[j])*(targetRgb[i][j]-arbitraryRgb[j]);
                // cout << "tmp_dis " << tmp_dis << endl;
            }
            tmp_dis = (int)sqrt(float(tmp_dis));
            if (-1 == distance || tmp_dis < distance)
            {
                distance = tmp_dis;
                pos = i;
            }
        }
        cout << "(" << arbitraryRgb[0] << "," << arbitraryRgb[1] << "," << arbitraryRgb[2]
             << ") maps to ("
             << targetRgb[pos][0] << "," << targetRgb[pos][1] << "," << targetRgb[pos][2] << ")" << endl;
    }
    return 0;
}
