//: 1233_Number Steps.cpp
// http://acm.tju.edu.cn/acm/showp1233.html
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x,y;//coordinates
    int i;
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;
        if(x < 0 || x > 5000 || y < 0 || y > 5000)
            return 1;
        if(x == y || x == (y+2))
        {
            if(x%2 == 0)
                cout << x+y << endl;
            else
                cout << x+y-1 << endl;
        }
        else
            cout << "No Number" << endl;
    }

    return 0;
}
