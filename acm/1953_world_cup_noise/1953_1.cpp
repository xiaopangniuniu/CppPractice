//: 1726_World Cup Noise.cpp
// http://acm.tju.edu.cn/acm/showp1726.html
#include <iostream>
using namespace std;

int main()
{
    int n,m,i;
    cin >> n;
    int res[45] = {2,3};
    for(i = 2; i < 45; i++)
        res[i] = res[i-1] + res[i-2];
    for(i = 0; i < n; i++)
    {
        cin >> m;
        int count = res[m-1];
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << count << endl << endl;
    }

    return 0;
}
