//: 1224_HTML.cpp
//http://acm.tju.edu.cn/acm/showp1224.html
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char word[1000][85];//????????????80?????

int main()
{
    int top(0),p(0);
    int i;
    while(scanf("%s",word[top]) != EOF)//??????????????ctrl-z,??¦Ê???????????EOF
        top++;
    int len = strlen(word[0]);
    if(strcmp(word[0],"<br>") == 0)
        cout << endl;
    else if(strcmp(word[0],"<hr>") == 0)
    {
        for(i = 0; i < 80; i++)//??§Ó?????80?????
            cout << "-";
        cout << endl;
    }
    else
    {
        cout << word[0];
        p = len;
    }

    for(i = 1; i < top; i++)
    {
        len = strlen(word[i]);
        if(strcmp(word[i],"<br>") == 0)
        {
            cout << endl;
            p = 0;
        }
        else if(strcmp(word[i],"<hr>") == 0)
        {
            if(p != 0)
                cout << endl;
            int j;
            for(j = 0; j < 80; j++)
                cout << "-";
            cout << endl;
            p = 0;
        }
        else
        {
            if(len+p+1 > 80)
            {
                cout << endl << word[i];
                p = len;
            }
            else
            {
                if(p == 0)//?????????????<br>??<hr>,?????¦Ì???§á??
                {
                    p = len;
                    cout << word[i];
                }
                else//p != 0
                {
                    p += len+1;//"+1"?????????????????????~
                    cout << " " << word[i];
                }
            }
            if(p >= 80)
                p = 0;
        }
    }
    cout << endl;

    return 0;
}
