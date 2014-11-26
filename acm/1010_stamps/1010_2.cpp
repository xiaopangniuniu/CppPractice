/*
 * Web Site: http://poj.org/problem?id=1010
 * Date: 1/24/2014
 * Command: g++ -m32 -g -o 1010 1010_2.cpp
 */
#include <iostream>
using namespace std;

int main()
{
    int stamp_denomination;
    while(cin >> stamp_denomination)
    {
        const int NUM_STAMP_TYPE = 128;
        int stamp_types[NUM_STAMP_TYPE] = {0};
        int iTotal(1);// Note: initial iTotal to 1 rather than 0
        while(0 != stamp_denomination)
        {
            // add an optimization here
            // if there're more than 4 stamps of which value is the same one,
            // then ignore them
            int i, j;
            for (i = 1, j = 0; i < iTotal; ++i)
            {
                if (stamp_types[i] == stamp_denomination)
                    ++j;
            }
            if (j < 5)
                stamp_types[iTotal++] = stamp_denomination;
            cin >> stamp_denomination;
        }
        int people_needs;
        while(cin >> people_needs && (0 != people_needs))
        {

        }
    return 0;
}
