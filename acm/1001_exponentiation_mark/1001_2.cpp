/*
 * Web Site: http://poj.org/problem?id=1001
 * Date: 11/4/2013
 * Command: g++ -m32 -g -O3 -o 1001 1001_2.cpp
 * Ref: http://blog.sina.com.cn/s/blog_93ced90c01016lb9.html
 */
#include <iostream>
using namespace std;
#define MAX 200

char str[MAX+1];
int num[MAX+1];
int num0[MAX+1];
int result[MAX+1];
int fraction_len;

void multify();
int length(int*);
bool find_radix();
int main()
{
    int n,i,j,len;
    while(cin>>str>>n)
    {
        fraction_len = 0;
        memset(num,0,sizeof(num));
        memset(num0,0,sizeof(num0));
        int temp_len = strlen(str);
        len = strlen(str);
        for(i = temp_len-1 ; i >= 0; i--)
            if(str[i] != '0' && find_radix())
            {
                len = i + 1;
                break;
            }
        for(i = len - 1,j = 0;i >= 0; i--)
        {
            if(str[i] != '.')
            {
                num[j] = str[i] - '0';
                num0[j] = str[i] - '0';
                j++;
            }
            else
                fraction_len = len-1 - i;
        }
        for(i = 1;i <= n-1; i++)
            multify();
        if(n * fraction_len >= length(num0))
        {
            cout<<".";
            for(i = n*fraction_len - length(num0); i >= 1; i--)
                cout<<"0";
        }
        for(i = length(num0)-1; i >= 0; i--)
        {
            cout<<num0[i];
            if(i == n*fraction_len && i != 0)
                cout<<".";
        }
        cout<<endl;
        memset(str,'0',sizeof(str));
        memset(num,0,sizeof(num));
        memset(num0,0,sizeof(num0));
    }
}
int length(int* temp)
{
    int i;
    for(i = MAX; i >= 0; i--)
    {
        if(temp[i] != 0)
        {
            return i+1;
        }
    }
    return 0;
}
void multify()
{
    int i;
    int len1 = length(num0);
    int len2 = length(num);
    for(i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            result[i+j] += num0[i]* num[j];
        }
    }
    for(i = 0; i < length(result);  i++)
    {
        if(result[i] >= 10)
        {
            result[i+1] += result[i]/10;
            result[i] %= 10;
        }
    }
    for(i = length(result)-1; i >= 0; i--)
        num0[i] = result[i];
    memset(result,0,sizeof(result));
}
bool find_radix()
{
    int i ;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == '.')
            return true;
    }
    return false;
}
