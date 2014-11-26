//1818_A Simple Question of Chemistry.cpp
// http://acm.tju.edu.cn/acm/showp1818.html
#include <iostream>
using namespace std;
const int size = 1000;

int main()
{
    double temperature[size] = {0};
    int i;
    for(i = 0; temperature[i-1] != 999; i++)
        cin >> temperature[i];
    if(i < 3)
        return 1;
    int count = i-1;
    for(i = 1; i < count && temperature[i] != 999; i++)
    {
        printf("%.2lf",(temperature[i] - temperature[i-1]));
        cout << endl;
    }
    cout << "End of Output" << endl;

    return 0;
}
