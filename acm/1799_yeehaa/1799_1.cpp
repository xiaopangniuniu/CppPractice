//: 1715_Yeehaa.cpp
// http://acm.tju.edu.cn/acm/showp1715.html
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265358

int main()
{
    int num;
    cin >> num;
    double R,r;
    int n;//§³???????
    int i;
    for(i = 0; i < num; i++)
    {
        cin >> R >> n;
        if(R < 1 || R > 100 || n < 2 || n > 100)
            return 1;

        double tmp;
        tmp = sin((2*PI)/(2*n));
        r = R*tmp / (1+tmp);
        cout << "Scenario #" << i+1 << ":" << endl;
        printf("%.3lf", r);
        cout << endl << endl;
    }

    return 0;
}
