//: 1036_Rails.cpp
// http://acm.tju.edu.cn/acm/showp1036.html
#include <iostream>
using namespace std;

int outStation[1001] = {0};
int inStation[1001] = {0};

int main()
{
    int n,i,j,k;
    while(cin >> n && n != 0)
    {
        while(cin >> outStation[0] && outStation[0] != 0)
        {
            for(i = 1; i < n; i++)
                cin >> outStation[i];
            j = -1;
            k = 0;
            for(i = 0; i < n; i++)
            {
                inStation[++j] = i+1;
                while(j >= 0 && inStation[j] == outStation[k])
                {
                    j--;
                    k++;
                }
            }

            if(j == -1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }

    return 0;
}
