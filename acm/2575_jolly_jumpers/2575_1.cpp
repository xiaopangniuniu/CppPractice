//: 1355_Jolly Jumpers.cpp
// http://acm.tju.edu.cn/acm/showp1355.html
#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
const int size = 3001;

int main()
{
    int n;
    bitset<size> seq;
    while(cin >> n)
    {
        if(n == 1)
        {
            int num;
            cin >> num;
            cout << "Jolly" << endl;
        }
        else
        {
            seq.reset();
            int pre,nxt;
            cin >> pre;
            int i;
            for(i = 0; i < n-1; i++)
            {
                cin >> nxt;
                if(abs(pre-nxt) > 0 && abs(pre-nxt) < n)
                    seq.set(abs(pre-nxt));
                pre = nxt;
            }
            if(seq.count() != (n-1))
                cout << "Not jolly" << endl;
            else
                cout << "Jolly" << endl;
        }
    }

    return 0;
}
