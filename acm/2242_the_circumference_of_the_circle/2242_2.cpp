#define Pi 3.141592653589793
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    double ix1,ix2,ix3,iy1,iy2,iy3,
        x1,x2,y1,y2,x,y,r,ans,k1,k2;
    while(cin>>ix1>>iy1>>ix2>>iy2>>ix3>>iy3){

        x1 = (ix1+ix2)/2;
        y1 = (iy1+iy2)/2;

        x2 = (ix2+ix3)/2;
        y2 = (iy2+iy3)/2;


        k1 = (ix1-ix2)/(iy2-iy1);

        k2 = (ix2-ix3)/(iy3-iy2);

        if(iy1 == iy2){
            x = x1;
            y =(double)( k2*x - k2*x2 + y2);

        }

        else if(iy3 == iy2 ){
            x = x2;
            y =(double)( k1*x - k1*x1 + y1);

        }

        else{
            if( k1 - k2 != 0 )
                x =(double)( (k1*x1 - k2*x2 - y1 + y2)/(k1 - k2) );
            else
                x = x1;
            y =(double)( k1*x - k1*x1 + y1);
        }


        r = (double) sqrt( (x - ix1)*(x - ix1) + (y - iy1)*(y- iy1) );

        ans = 2 * Pi * r;

        cout<<setiosflags(ios::fixed);
        cout<<setprecision(2)<<setiosflags(ios::showpoint)<<ans<<endl;
    }

    return 0;

}
