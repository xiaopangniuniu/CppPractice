//: 1633_Zipper.cpp
//http://acm.tju.edu.cn/acm/showp1633.html
#include <iostream>
#include <cstring>
using namespace std;

char str1[205],str2[205],str[410];
int dp[205][205] = {0};

int main()
{
    int n;
    cin >> n;
    int k;
    for(k = 0; k < n; k++)
    {
        memset(dp,0,sizeof(dp));//??????????!!!!
        cin >> str1 >> str2 >> str;
        int len1 = strlen(str1);
        int i;
        for(i = 1; i <= len1; i++)
        {
            if(str1[i-1] == str[i-1])
                dp[0][i] = 1;
        }
        int len2 = strlen(str2);
        for(i = 1; i <= len2; i++)
        {
            if(str2[i-1] == str[i-1])
                dp[i][0] = 1;
        }

        for(i = 1; i <= len2; i++)
        {
            int j;
            for(j = 1; j <= len1; j++)
            {
                if((str1[j-1] == str[i+j-1] && dp[i][j-1]) || (str2[i-1] == str[i+j-1] && dp[i-1][j]))
                    dp[i][j] = 1;
            }
        }
        cout << "Data set " << k+1 << ": ";
        if(dp[len2][len1])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
