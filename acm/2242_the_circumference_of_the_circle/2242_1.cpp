//: 1131.cpp
//The Circumference of the Circle
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793
using namespace std;

int main()
{
    double x,y,x1,y1,x2,y2,x3,y3,x_m1,y_m1,x_m2,y_m2,k1,k2,dia,circum;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        x_m1 = (x1 + x2) / 2;
        y_m1 = (y1 + y2) / 2;
        x_m2 = (x2 + x3) / 2;
        y_m2 = (y2 + y3) / 2;
        if(y1 == y2)
        {
            x = x_m1;
            k2 = (x3 - x2) / (y2 - y3);
            y = (double)(k2*x + y_m2 - k2*x_m2);
        }
        else if(y2 == y3)
        {
            x = x_m2;
            k1 = (x2 - x1) / (y1 - y2);
            y = (double)(k1*x + y_m1 - k1*x_m1);
        }
        else
        {
            k1 = (x2 - x1) / (y1 - y2);
            k2 = (x3 - x2) / (y2 - y3);
            x = (double)((y_m2 - y_m1 - k2*x_m2 + k1*x_m1)/(k1 - k2));
            y = (double)(k1*x + y_m1 - k1*x_m1);
        }
        dia = (double)(2*sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y)));
        circum = PI*dia;
        cout << setprecision(2) << fixed << circum << endl;
    }
    return 0;
}
