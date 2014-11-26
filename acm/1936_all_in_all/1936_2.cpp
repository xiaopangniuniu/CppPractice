#include<iostream>
using namespace std;
int Solve(char*s,char*t);
int main()
{
    char str1[100000],str2[100000];
    while(cin>>str1>>str2)
    {
        if(Solve(str1,str2))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}
int Solve(char*s,char*t)
{
    int pa,pb;
    pa=pb=0;
    while(s[pa]&&t[pb])
    {
       if(s[pa]==t[pb])
       {
            pa++;
        pb++;
       }
    else pb++;
    }
    if(!s[pa]) return 1;
    else return 0;
}
