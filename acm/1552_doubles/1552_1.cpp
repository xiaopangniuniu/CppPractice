//: 1930_Doubles.cpp
// http://acm.tju.edu.cn/acm/showp1930.html
#include <iostream>
using namespace std;

int main()
{
    int a[20] = {0};
    while(cin >> a[0] && a[0] != -1)
    {
        int i;
        int flag = 1;
/*      for(i = 1; i < 15; i++)
        {
            cin >> a[i];
            if(a[i] == 0)
                break;
        }
        int flag = i;*/
        while(cin >> a[flag] && a[flag] != 0)
            flag++;
        int j,count(0);
        for(i = 0; i < flag; i++)
        {
            for(j = i; j < flag; j++)
            {
                if(a[i] == a[j]*2 || a[j] == a[i]*2)
                    count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
