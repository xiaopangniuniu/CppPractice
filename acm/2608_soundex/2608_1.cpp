//: 1326_Soundex.cpp
// http://acm.tju.edu.cn/acm/showp1326.html
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    char str[20] = {0};
    vector<int> soundex;

    while(cin >> str)
    {
        int len = strlen(str);
        if(str[0]=='B' || str[0]=='F' || str[0]=='P' || str[0]=='V')
            soundex.push_back(1);
        else if(str[0]=='C' || str[0]=='G' || str[0]=='J' || str[0]=='K' || str[0]=='Q' || str[0]=='S' || str[0]=='X' || str[0]=='Z')
            soundex.push_back(2);
        else if(str[0]=='D' || str[0]=='T')
            soundex.push_back(3);
        else if(str[0]=='L')
            soundex.push_back(4);
        else if(str[0]=='M' || str[0]=='N')
            soundex.push_back(5);
        else if(str[0]=='R')
            soundex.push_back(6);
        else
            soundex.push_back(0);
        int i;
        for(i = 1; i < len; i++)
        {
            if(str[i]=='B' || str[i]=='F' || str[i]=='P' || str[i]=='V')
            {
                if(soundex.back() == 0)
                {
                    soundex.pop_back();
                    soundex.push_back(1);
                }
                else if(soundex.back() != 1 && soundex.back() != 0)
                    soundex.push_back(1);
            }
            else if(str[i]=='C' || str[i]=='G' || str[i]=='J' || str[i]=='K' || str[i]=='Q' || str[i]=='S' || str[i]=='X' || str[i]=='Z')
            {
                if(soundex.back() == 0)
                {
                    soundex.pop_back();
                    soundex.push_back(2);
                }
                if(soundex.back() != 2 && soundex.back() != 0)
                    soundex.push_back(2);
            }
            else if(str[i]=='D' || str[i]=='T')
            {
                if(soundex.back() == 0)
                {
                    soundex.pop_back();
                    soundex.push_back(3);
                }
                if(soundex.back() != 3 && soundex.back() != 0)
                    soundex.push_back(3);
            }
            else if(str[i]=='L')
            {
                if(soundex.back() == 0)
                {
                    soundex.pop_back();
                    soundex.push_back(4);
                }
                if(soundex.back() != 4 && soundex.back() != 0)
                    soundex.push_back(4);
            }
            else if(str[i]=='M' || str[i]=='N')
            {
                if(soundex.back() == 0)
                {
                    soundex.pop_back();
                    soundex.push_back(5);
                }
                if(soundex.back() != 5 && soundex.back() != 0)
                    soundex.push_back(5);
            }
            else if(str[i]=='R')
            {
                if(soundex.back() == 0)
                {
                    soundex.pop_back();
                    soundex.push_back(6);
                }
                if(soundex.back() != 6 && soundex.back() != 0)
                    soundex.push_back(6);
            }
            else
            {
                if(soundex.back() == 0)
                    soundex.pop_back();
                soundex.push_back(0);
            }
        }
        if(soundex.back() == 0)
            soundex.pop_back();
        for(i = 0; i < soundex.size(); i++)
            cout << soundex[i];
        cout << endl;
        soundex.clear();
    }

    return 0;
}
