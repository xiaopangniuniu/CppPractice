//: 1805_Electrical Outlets.cpp
// http://acm.tju.edu.cn/acm/showp1805.html
#include <iostream>
using namespace std;

int main()
{
    int n,k,o;
    cin >> n;
    if(n < 1 || n > 20)
        return 1;
    int i;
    for(i = 0; i < n; i++)
    {
        cin >> k;
        if(k < 1 || k > 10)
            return 1;
        int j,outlets(0);
        for(j = 0; j < k; j++)
        {
            cin >> o;
            outlets += o;
        }
        outlets = outlets - (k -1);
        cout << outlets << endl;
    }

    return 0;
}
