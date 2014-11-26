/*
 * Web Site: http://poj.org/problem?id=1009
 * Date: 11/13/2013
 * Command: g++ -m32 -g -o 1009 1009.cpp
 * Key Info: Input images have at most 1,000 of these pairs.
 *           Vector, qsort, sort
 * Ref: http://www.myexception.cn/program/677797.html
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> // for sort()

using namespace std;

class Node
{
public:
    int pixel_value; // pixel value (0-255)
    int run_len; // run length (1-10^9)

    bool operator< (const Node& rhs) const { return run_len < rhs.run_len; }
};

// global various
vector<Node> iPairList;
int iWidth;
int iTotal(0);

int get_value(int pos)
{
    int i, n;
    for (i = 0, n = 0; n <= pos; ++i) // && i < iPairList.size()
    {
        n += iPairList[i].run_len;
    }
    return iPairList[i-1].pixel_value;
}

int cal_encode_res(int pos, int row, int col)
{
    int mid_value = get_value(pos);
    // cout << "mid_value: " << mid_value << endl;
    int i, j, res(0);
    for (i = row-1; i <= row+1; ++i)
    {
        for (j = col-1; j <= col+1; ++j)
        {
            int tmpPos = i*iWidth + j;
            // tmpPos should not equal to pos, 'cause it's the mid_value
            if (i < 0 || j < 0 || j >= iWidth || tmpPos == pos || tmpPos >= iTotal)
                continue;
            int round_value = get_value(tmpPos);
            // cout << "round_value: " << round_value << endl;
            if (abs(mid_value-round_value) > res)
                res = abs(mid_value-round_value);
        }
    }
    return res;
}

int main()
{
    while(cin >> iWidth && iWidth) // 0 != iWidth
    {
        Node pair;
        // if (0 == pair.pixel_value && 0 == pair.run_len) break;
        while(cin >> pair.pixel_value >> pair.run_len && (pair.pixel_value || pair.run_len))
        {
            iTotal += pair.run_len;
            iPairList.push_back(pair);
        }
        cout << iWidth << endl;

        // start to calculate
        vector<Node> resPairList;
        int midPos(0), iList;
        // Note: iList should "<=" iPairList.size()
        for (iList = 0; iList <= iPairList.size(); ++iList)
        {
            // cout << "midPos: " << midPos << endl;
            // get the row and column of the each changed point
            int row = midPos/iWidth;
            int col = midPos%iWidth;

            // handle a special case, the last point of some row is changed
            if (col == iWidth-1)
            {
                if ((row+2)*iWidth < iTotal)
                {
                    pair.pixel_value = cal_encode_res(midPos+iWidth+1, row+2, 0);
                    pair.run_len = midPos+iWidth+1;
                    resPairList.push_back(pair);
                }
            }

            // handle the normal case
            int i, j;
            for (i = row-1; i <= row+1; ++i)
            {
                for (j = col-1; j <= col+1; ++j)
                {
                    // roundPos includes midPos itself
                    int roundPos = i*iWidth + j;
                    // cout << "roundPos: " << roundPos << endl;
                    if (i < 0 || j < 0 || j >= iWidth || roundPos >= iTotal)
                        continue;
                    pair.pixel_value = cal_encode_res(roundPos, i, j);
                    pair.run_len = roundPos;
                    resPairList.push_back(pair);
                }
            }
            midPos += iPairList[iList].run_len;
        }
        // start to short
        // qsort(&resPairList[0], resPairList.size(), sizeof(Node), cmp);
        sort(resPairList.begin(), resPairList.end());
        // output the encoded piture
        int i, iCur(0);
        for (i = 0; i < resPairList.size(); ++i)
        {
            if (resPairList[iCur].pixel_value == resPairList[i].pixel_value)
                continue;
            cout << resPairList[iCur].pixel_value << " " << resPairList[i].run_len-resPairList[iCur].run_len << endl;
            iCur = i;
        }
        cout << resPairList[iCur].pixel_value << " " << iTotal-resPairList[iCur].run_len << endl;
        cout << "0 0" << endl;

        // prepare for the next data
        iPairList.clear();
        resPairList.clear();
        iTotal = 0;
    }
    cout << "0" << endl;
    return 0;
}
