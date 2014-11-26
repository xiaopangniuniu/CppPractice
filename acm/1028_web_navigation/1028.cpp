/*
 * Web Site: http://poj.org/problem?id=1010
 *           http://acm.tju.edu.cn/acm/showp1196.html
 * Date: 1/14/2014
 * Command: g++ -m32 -g -o 1028 1028.cpp
 * Note: switch-case cannot be applied by string
 *       vector: pop_back() vs back()
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> forward;
    vector<string> backward;
    string command, url("http://www.acm.org/");
    while(cin >> command && command != "QUIT")
    {
        if ("VISIT" == command)
        {
            backward.push_back(url);
            forward.clear();
            cin >> url;
            cout << url << endl;
        }
        else if ("BACK" == command)
        {
            if (backward.size() == 0)
                cout << "Ignored" << endl;
            else
            {
                forward.push_back(url);
                url = backward.back();
                cout << url << endl;
                backward.pop_back();
            }
        }
        else if ("FORWARD" == command)
        {
            if (forward.size() == 0)
                cout << "Ignored" << endl;
            else
            {
                backward.push_back(url);
                url = forward.back();
                cout << url << endl;
                forward.pop_back();
            }
        }
    }
    return 0;
}
