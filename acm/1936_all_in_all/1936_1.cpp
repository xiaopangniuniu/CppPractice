// http://acm.tju.edu.cn/acm/showp1401.html
#include <iostream>
using namespace std;

int cmp(char* str1,char* str2);

int main()
{
    char t[100000],s[100000];
    while(cin >> s >> t)
    {
        if(cmp(s,t))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

int cmp(char* str1,char* str2)
{
    int i(0),j(0);
    while(str1[i]&&str2[j])
    {
        if(str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    if(!str1[i])
        return 1;
    else
        return 0;
}
