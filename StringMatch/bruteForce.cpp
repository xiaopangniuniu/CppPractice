#include "stringMatching.h"

char *bruteforce (const char *phaystack, const char *pneedle)
{
    int i(0), j(0);
    int haystack_len = strlen(phaystack);
    int needle_len = strlen(pneedle);

    while(i < haystack_len && j < needle_len)
    {
        if(phaystack[i++] != pneedle[j++])
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if(j == needle_len)
        return (char *)phaystack+i-needle_len;
    else
        return NULL;
}

//Microsoft strstr()
char *bruteforce_strstr_MS (const char *phaystack, const char *pneedle)
{
    char *haystack = (char *)phaystack;
    char *rhaystack, *rneedle;

    if(!*pneedle)
        return (char *)phaystack;

    while(*haystack)
    {
        rhaystack = haystack;
        rneedle = (char *)pneedle;
        while(*rhaystack && *rneedle && !(*rhaystack - *rneedle))
        {
            ++rhaystack;
            ++rneedle;
        }
        if(!*rneedle)
            return haystack;
        ++haystack;
    }
    return NULL;
}

//glibc strstr
/*
 * My personal strstr() implementation that beats most other algorithms.
 * Until someone tells me otherwise, I assume that this is the
 * fastest implementation of strstr() in C.
 * I deliberately chose not to comment it. You should have at least
 * as much fun trying to understand it, as I had to write it :-).
 *
 * Stephen R. van den Berg, berg@pool.informatik.rwth-aachen.de    */
char *bruteforce_strstr_glibc (const char *phaystack, const char *pneedle)
{
    const unsigned char *haystack, *needle;
    chartype b;
    const unsigned char *rneedle;

    haystack = (const unsigned char *) phaystack;

    if ((b = *(needle = (const unsigned char *) pneedle)))
    {
        chartype c;
        haystack--;       /* possible ANSI violation */
                          /* for unify processing afterward */

        {
            chartype a;
            do
                if (!(a = *++haystack))
                    goto ret0;         /* if haystack ends, return 0 */
            while (a != b);            /* find the first postion that equals */
        }

        /* first char equals, go on */
        if (!(c = *++needle))
            goto foundneedle;          /* only one char in needle, found it */
        ++needle;                      /* needle go to 3rd char */
        goto jin;

        for (;;)
        {
            {
                chartype a;
                if (0)
                    jin:{
                        if ((a = *++haystack) == c)   /* check if the second char in needle equals*/
                            goto crest;
                    }
                else
                    a = *++haystack;                  /* set a = next char to be compared */
                do
                {
                    for (; a != b; a = *++haystack)   /* search haystack to find a char equals the 1st char of needle */
                    {
                        if (!a)
                            goto ret0;
                        if ((a = *++haystack) == b)   /* one loop compare 2 chars */
                            break;
                        if (!a)
                            goto ret0;
                    }
                }
                while ((a = *++haystack) != c);      /* until second char equals */
            }
crest:/* 2 char equals, go on */
            {
                chartype a;
                {
                    const unsigned char *rhaystack;
                    /* rhaystack =next char, haystack-- set haystack point at the postion to be returned */
                    if (*(rhaystack = haystack-- + 1) == (a = *(rneedle = needle)))/* go on comparing from 3rd char of needle */
                        do
                        {
                            if (!a)
                                goto foundneedle;
                            if (*++rhaystack != (a = *++needle))
                                break;
                            if (!a)
                                goto foundneedle;
                        }
                        while (*++rhaystack == (a = *++needle));/* until reach a char not equal */
                    needle = rneedle; /* took the register-poor aproach, needle point to 3rd char */
                }
                if (!a)
                    break;
            }
        }
    }
foundneedle:
    return (char *) haystack;
ret0:
    return 0;
}
