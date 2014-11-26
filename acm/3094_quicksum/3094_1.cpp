//: 2520_Quicksum.cpp
// http://acm.tju.edu.cn/acm/showp2520.html
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char pack[256] = {0};
    while(cin.getline(pack,256) && strcmp(pack,"#") != 0)
    {
        int len = strlen(pack);
        int i;
        int num,sum(0);
        for(i = 0; i < len; i++)
        {
            if(pack[i] == ' ')
                num = 0;
            else
                num = (int)pack[i] - 64;
            sum += num*(i+1);
//          cout << num << " " << sum << endl;
        }
        cout << sum << endl;
    }

    return 0;
}
