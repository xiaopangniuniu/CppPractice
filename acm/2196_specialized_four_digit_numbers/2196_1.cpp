//: 1637_Specialized Four-Digit Numbers.cpp
// http://acm.tju.edu.cn/acm/showp1637.html
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i;
    int n1,n2,n3,n4;
    int dec,duo,hex;
    for(i = 2992; i < 9999; i++)
    {
        n1 = (int)(i/1000);
        n2 = (int)((i - n1*1000)/100);
        n3 = (int)((i - n1*1000 - n2*100)/10);
        n4 = i - n1*1000 - n2*100 - n3*10;
        dec = n1+n2+n3+n4;

        n4 = i%12;
        n3 = ((int)(i/12))%12;
        n2 = ((int)(((int)(i/12)) / 12))%12;
        n1 = (((int)(( (int)(i/12) ) / 12)) / 12)%12;
        duo = n1+n2+n3+n4;

        n4 = i%16;
        n3 = ((int)(i/16))%16;
        n2 = ((int)(((int)(i/16)) / 16))%16;
        n1 = (((int)(( (int)(i/16) ) / 16)) / 16)%16;
        hex = n1+n2+n3+n4;

        if(dec == duo && duo == hex)
            cout << i << endl;
    }

    return 0;
}
