/*
 * Web Site: http://poj.org/problem?id=1008
 * Date: 11/11/2013
 * Command: g++ -m32 -g -o 1008 1008.cpp
 * Description:
 * Haab: 19 months (has names), 20 days or 5 days
 * Tzolkin: 13 months, 20 days (has names)
 */
#include <iostream>

using namespace std;

int main()
{
    const int NAMELEN = 10;
    const char haab_month_name[19][NAMELEN] =
                                        {"pop", "no", "zip", "zotz", "tzec",
                                         "xul", "yoxkin", "mol", "chen", "yax",
                                         "zac", "ceh", "mac", "kankin", "muan",
                                         "pax", "koyab", "cumhu", "uayet"};
    const char tzolkin_day_name[20][NAMELEN] =
                                         {"imix", "ik", "akbal", "kan", "chicchan",
                                          "cimi", "manik", "lamat", "muluk", "ok",
                                          "chuen", "eb", "ben", "ix", "mem",
                                          "cib", "caban", "eznab", "canac", "ahau"};

    int nCase;
    cin >> nCase;
    cout << nCase << endl;
    for (int i = 0; i < nCase; ++i)
    {
        char haab_month[NAMELEN];
        int haab_day, haab_year;
/*      char haab_days[4];
        cin >> haab_days >> haab_month >> haab_year;
        // get day which denotes by integer
        int day_len = strlen(haab_days);
        int haab_day = 0;
        int j;
        for (j = 0; j < day_len; ++j)
        {
            if ('.' != haab_days[j])
            {
                haab_day *= 10;
                haab_day += haab_days[j]-'0';
            }
            else
                break;
        }*/
        // use scanf to get day
        scanf("%d. %s %d", &haab_day, haab_month, &haab_year);
        int j;
        // 19 is haab month number
        for (j = 0; j < 19; ++j)
            if(!strcmp(haab_month_name[j], haab_month)) // return 0 if equal
                break;
        // 20 is tzolkin day number
        int dates = haab_year*365 + j*20 + haab_day;
        //260 = 13*20, 13 is tzolkin month number, 20 is haab day number
        printf("%d %s %d\n", dates%260%13+1, tzolkin_day_name[dates%260%20], dates/260);
    }
    return 0;
}
