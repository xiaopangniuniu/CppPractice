bool solution(vector<int> &A)
{
    if (A.empty())
    {
        return true;
    }
    
    vector<int>::iterator lIt=A.begin(), rIt=A.end()-1;

    while (lIt < rIt)
    {
        if (*lIt > *(lIt+1))
        {
            break;
        }
        ++lIt;
    }
    cout << "l: " << lIt - A.begin() << endl;

    while (lIt < rIt)
    {
        if (*rIt < *(rIt-1))
        {
            break;
        }
        --rIt;
    }
    cout << "r: " << rIt - A.begin() << endl;

    if (lIt < rIt)
    {
        //swap 
        int tmp = *lIt;
        *lIt = *rIt;
        *rIt = tmp;
    }
    else
    {
        return true;
    }

    while (lIt < rIt)
    {
        if (*lIt > *(lIt+1))
        {
            break;
        }
        ++lIt;
    }

    cout << "l: " << lIt - A.begin() <<  " r: " << rIt - A.begin() << endl;

    return (lIt < rIt) ? false : true;
}