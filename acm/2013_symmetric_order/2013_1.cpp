//: 1935_Symmetric Order.cpp
// http://acm.tju.edu.cn/acm/showp1935.html
#include <iostream>
using namespace std;

int main()
{
    int n,count(0);
    char name[20][30] = {0};
    while(cin >> n && n != 0)
    {
        int i;
        for(i = 0; i < n; i++)
            scanf("%s",name[i]);
        count++;
        cout << "SET " << count << endl;
        for(i = 0; i < n; i += 2)
            cout << name[i] << endl;
        if(n%2 == 0)
        {
            for(i = n-1; i >= 1; i -= 2)
                cout << name[i] << endl;
        }
        else
        {
            for(i = n-2; i >= 1; i -= 2)
                cout << name[i] << endl;
        }
    }

    return 0;
}
