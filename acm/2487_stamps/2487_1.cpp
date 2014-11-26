//: 1701_Stamps.cpp
//http://acm.tju.edu.cn/acm/showp1701.html
#include <iostream>
using namespace std;

int stamps[10001];

int main()
{
    int n,sNum,fNum;
    cin >> n;
    int i;
    for(i = 0; i < n; i++)
    {
        cin >> sNum >> fNum;
        int j;
        for(j = 0; j < fNum; j++)
            cin >> stamps[j];
        int fd = fNum,count(0);
        while(sNum > 0 && fd != 0)
        {
            int max = 0,maxPos;
            for(j = 0; j < fd; j++)
            {
                if(max < stamps[j])
                {
                    max = stamps[j];
                    maxPos = j;
                }
            }
            fd--;
            stamps[maxPos] = stamps[fd];//??????¦Ë??????????
            sNum -= max;
            count++;

        }

        cout << "Scenario #" << i+1 << ":" << endl;
        if(sNum > 0)
            cout << "impossible" << endl;
        else
            cout << count << endl;
        cout << endl;
    }

    return 0;
}
