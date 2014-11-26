/*
 * Web Site: http://poj.org/problem?id=1010
 * Date: 1/21/2014
 * Command: g++ -m32 -g -o 1010 1010_1.cpp
 * Ref: http://blog.csdn.net/cugbliang/article/details/2742242
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
            // start to handle, use 4 loops
            int cur_stamp_num(10), cur_stamp_type(-1), cur_max_value(-1);
            int cur_count[4]={0};
            bool tie_flag(false);
            int i, j, k, l;
            for (i = 0; i < iTotal; ++i)
                for (j = i; j < iTotal; ++j)
                    for (k = j; k < iTotal; ++k)
                        for (l = k; l < iTotal; ++l)
                        {
                            if (stamp_types[i]+stamp_types[j]+stamp_types[k]+stamp_types[l] != people_needs)
                                continue;
                            // cout << stamp_types[i] << " " << stamp_types[j] << " " << stamp_types[k] << " " << stamp_types[l] << endl;
                            // == means it's a valid solution
                            // we assume that the stamp_types is sorted by number
                            int stamp_num(0), stamp_type(0), max_value(0);
                            if (0 != stamp_types[i])
                            {
                                // this stamp is valid
                                ++stamp_num;
                                // the number of stamp type should be increased
                                ++stamp_type;
                                if (stamp_types[i] > max_value)
                                    max_value = stamp_types[i];
                            }
                            if (0 != stamp_types[j])
                            {
                                // this stamp is valid
                                ++stamp_num;
                                // the number of stamp type should be increased
                                if (j > i) // Note here
                                    ++stamp_type;
                                if (stamp_types[j] > max_value)
                                    max_value = stamp_types[j];
                            }
                            if (0 != stamp_types[k])
                            {
                                // this stamp is valid
                                ++stamp_num;
                                // the number of stamp type should be increased
                                if (k > j)
                                    ++stamp_type;
                                if (stamp_types[k] > max_value)
                                    max_value = stamp_types[k];
                            }
                            if (0 != stamp_types[l])
                            {
                                // this stamp is valid
                                ++stamp_num;
                                // the number of stamp type should be increased
                                if (l > k)
                                    ++stamp_type;
                                if (stamp_types[l] > max_value)
                                    max_value = stamp_types[l];
                            }
                            // start to decide if this solution is optimality
                            // 1. the max (stamp types)
                            // cout << stamp_type << " " << cur_stamp_type << endl;
                            if (stamp_type < cur_stamp_type)
                                continue;
                            if (stamp_type > cur_stamp_type)
                            {
                                // cout << stamp_type << " " << cur_stamp_type << endl;
                                cur_stamp_num = stamp_num;
                                cur_stamp_type = stamp_type;
                                cur_max_value = max_value;
                                cur_count[0] = i;
                                cur_count[1] = j;
                                cur_count[2] = k;
                                cur_count[3] = l;
                                tie_flag = false;
                                continue;
                            }
                            // 2. the same stamp types and the min stamp numbers
                            if (stamp_num > cur_stamp_num)
                                continue;
                            if (stamp_num < cur_stamp_num)
                            {
                                // cout << stamp_num << " " << cur_stamp_num << endl;
                                cur_stamp_num = stamp_num;
                                cur_stamp_type = stamp_type;
                                cur_max_value = max_value;
                                cur_count[0] = i;
                                cur_count[1] = j;
                                cur_count[2] = k;
                                cur_count[3] = l;
                                tie_flag = false;
                                continue;
                            }
                            // 3. the same stamp types and numbers
                            // the max stamp value
                            if (max_value < cur_max_value)
                                continue;
                            if (max_value > cur_max_value)
                            {
                                // cout << max_value << " " << cur_max_value << endl;
                                cur_stamp_num = stamp_num;
                                cur_stamp_type = stamp_type;
                                cur_max_value = max_value;
                                cur_count[0] = i;
                                cur_count[1] = j;
                                cur_count[2] = k;
                                cur_count[3] = l;
                                tie_flag = false;
                                continue;
                            }
                            // otherwise, tie
                            tie_flag = true;
                        }
            if (-1 == cur_stamp_type)
            {
                cout << people_needs << " ---- none" << endl;
                continue;
            }
            cout << people_needs << " (" << cur_stamp_type << "):";
            if (tie_flag)
                cout << " tie" << endl;
            else
            {
                int i;
                for (i = 0; i < 4; ++i)
                    if (stamp_types[cur_count[i]] != 0) // the number may less than 4, so...
                        cout << " " << stamp_types[cur_count[i]];
                cout << endl;
            }
        }
        //reset stamp_types list
    }

    return 0;
}
