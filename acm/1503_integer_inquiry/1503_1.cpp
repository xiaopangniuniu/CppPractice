//:1112_Integer Inquiry.cpp
//http://acm.tju.edu.cn/acm/showp1112.html
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int size = 10000;

char bigInt1[size],bigInt2[size],bigInt3[size];

string reverse(char *str)//????????
{
    vector<char> temp;
    int i;
    for(i = 0; i < strlen(str); i++)
        temp.push_back(str[i]);
    for(i = 0; i < strlen(str); i++)
    {
        str[i] = temp.back();
        temp.pop_back();
    }
    temp.clear();
    return str;
}

int main()
{
    cin >> bigInt1;
    if(strcmp(bigInt1,"0") == 0)
        return 0;
    cin >> bigInt2;
    reverse(bigInt1);
    int add;//??¦Ë
    while(strcmp(bigInt2,"0"))
    {
        reverse(bigInt2);
        int len1 = strlen(bigInt1);
        int len2 = strlen(bigInt2);
        int len,flag(0);
        if(len1 > len2)
        {
            len = len2;
            flag = 1;
        }
        else
            len = len1;
        add = 0;
        int i;
        for(i = 0; i < len; i++)
        {
            bigInt3[i] = bigInt1[i] + bigInt2[i] + add - 48;
            if(bigInt3[i] > '9')
            {
                bigInt3[i] -= 10;
                add = 1;
            }
            else
                add = 0;
        }
        if(flag == 1)//???len1??len2??
        {
            for(i = len; i < len1; i++)
            {
                bigInt3[i] = bigInt1[i] + add;
                if(bigInt3[i] > '9')
                {
                    bigInt3[i] -= 10;
                    add = 1;
                }
                else
                add = 0;
            }
        }
        else
        {
            for(i = len; i< len2; i++)
            {
                bigInt3[i] = bigInt2[i] + add;
                if(bigInt3[i] > '9')
                {
                    bigInt3[i] -= 10;
                    add = 1;
                }
                else
                    add = 0;
            }
        }

        if(add)
            bigInt3[i] = '1';
        len = strlen(bigInt3);
        for(i = 0; i < len; i++)
            bigInt1[i] = bigInt3[i];
        cin >> bigInt2;
    }
    reverse(bigInt1);
    cout << bigInt1 << endl;

    return 0;
}
