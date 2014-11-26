//Check whether a string is an anagram of a palindrome
// S="dooernedeevrvn" => "neveroddoreven"
#include "palindrome.h"

//Normal Solution
int isAnagramOfPalindrome_solution1(char *S)
{
    int counts[26];
    for (int i=0; i<26; ++i)
        counts[i] = 0;

    int N=0;
    while(*S)
    {
        ++counts[*S++-'a'];
    }

    int oddcount=0;
    for (int i=0; i<26; ++i)
        if (counts[i]%2)
            ++oddcount;

    return (oddcount <= 1);
}

int isAnagramOfPalindrome_solution2(char *S)
{
    int m = 0;
    while(*S)
        m ^= (1 << (*S++-'a'));
    return !(m&(m-1));
}

//A wrong solution
//a^b^...^z = 27, 27 ^ a = z, 27 ^ b = y...
int isAnagramOfPalindrome_solution3(char *S)
{
    int result1 = 0;
    int result2 = 0;
    while(*S)
    {
        result1 ^= *S;
        //result ^= 'x';
        result2 ^= ((*S) * (*S));
        S++;
    }

    return (result2 == result1 * result1);
}
