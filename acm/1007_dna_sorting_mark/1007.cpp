/*
 * Web Site: http://poj.org/problem?id=1007
 * Date: 11/11/2013
 * Command: g++ -m32 -g -o 1007 1007.cpp
 * Ref:
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; // 0 < n <= 50, 0 < m <= 100
    char dna_string[100][51];
    int measure[100];
    cin >> n >> m;
    int i;
    for (i = 0; i < m; ++i)
    {
        cin >> dna_string[i];
        int flag = 0;
        int cnt[3] = {0};
        int j;
        for (j = n-1; j >= 0; --j)
        {
            switch (dna_string[i][j])
            {
                case 'A':
                    // use for loop if there are more letters
                    ++cnt[0];
                    ++cnt[1];
                    ++cnt[2];
                    break;
                case 'C':
                    ++cnt[1];
                    ++cnt[2];
                    flag += cnt[0];
                    break;
                case 'G':
                    ++cnt[2];
                    flag += cnt[1];
                    break;
                case 'T':
                    flag += cnt[2];
                    break;
                default:
                    break;
            }
        }
        // bound i with measure to store in measure[]
        measure[i] = flag*1000 + i;
    }
    sort(measure, measure+m);
    for(i = 0; i < m; ++i)
    {
        cout << dna_string[measure[i]%1000] << endl;
    }
    return 0;
}
