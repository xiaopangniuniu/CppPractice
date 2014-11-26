//: 1939_Speed Limit.cpp
// http://acm.tju.edu.cn/acm/showp1939.html
#include <iostream>
using namespace std;
const int num = 10;
const int size = 1000;

typedef struct{
    int n[num];
    int s[num];
    int t[num];
}speed;

int main()
{
    speed a[size] = {0};
    int i(0),j(0),count(0);
    cin >> a[i].n[0];

    for(i = 0; a[i].n[i] != -1; i++)
    {
        for(j = 0; j < a[i].n[i]; j++)
            cin >> a[i].s[j] >> a[i].t[j];
        cin >> a[i+1].n[i+1];
        count ++;
    }

    for(i = 0; i < count; i++)
    {
        int miles = a[i].s[0]*a[i].t[0];
        for(j = 1; j < a[i].n[i]; j++)
            miles += a[i].s[j]*(a[i].t[j]-a[i].t[j-1]);
        cout << miles << " miles" << endl;
    }

    return 0;
}///:~
