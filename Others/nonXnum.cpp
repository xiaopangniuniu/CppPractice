int solution(vector<int> &A)
{
    vector<int>::const_iterator lIt=A.begin(), rIt=A.end()-1;
    
    bool lFlag = true;
    while (lIt <= rIt)
    {
        cout << "l: " << lIt - A.begin() << " r: " << rIt-A.begin() << " f: " << lFlag << endl;
        if (lFlag)
        {
            if (*lIt == X)
            {
                lFlag = false;
            }
            ++lIt;
        }
        else
        {
            if (*rIt != X)
            {
                lFlag = true;
            }
            --rIt;
        }
    }

    if (lIt == A.begin() || rIt == A.end()-1 )
    {
        return -1;
    }
    else
    {
        return rIt - A.begin();
    }
}