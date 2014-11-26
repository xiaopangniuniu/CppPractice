//: 1412_Above Average.cpp
// http://acm.tju.edu.cn/acm/showp1412.html
#include <iostream>
using namespace std;
const int c_size = 100;
const int n_size = 1000;

int main(){
    int c;
    int n[c_size] = {0};
    cin >> c;
    int grade[c_size][n_size] = {0};
    int i,j;
    for(i = 0; i < c; i++)
    {
        cin >> n[i];
        if(n[i] < 1 || n[i] > n_size)
            return 1;
        for(j = 0; j < n[i]; j++)
            cin >> grade[i][j];
    }

    int average[c_size] = {0};//????
    int count[c_size] = {0};
    for(i = 0; i < c; i++)
    {
        for(j = 0; j < n[i]; j++)
            average[i] += grade[i][j];
        average[i] /= n[i];
        for(j = 0; j < n[i]; j++)
        {
            if(grade[i][j] > average[i])
                count[i]++;
        }
        count[i] = count[i] * 100;
    }
    for(i = 0; i < c; i++)
    {
        printf("%.3lf",(double)count[i]/(double)n[i]);
        cout << "%" << endl;
    }

    return 0;
}
