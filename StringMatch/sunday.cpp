#include "stringMatching.h"

char *sunday (const char *pText, const char *pPattern)
{
    int pattern_len = strlen(pPattern);
    int text_len = strlen(pText);

    const int ASCII_SIZE = 128;
    int shift_table[ASCII_SIZE];

    //construct delta shift table
    //moving distance
    for(int i = 0; i < ASCII_SIZE; ++i)
        shift_table[i] = pattern_len+1;
    const char *p;
    for(p = pPattern; *p; ++p)
        shift_table[*p] = pattern_len - (p - pPattern);

    const char *pTextEnd = pText + text_len;
    const char *t, *text = pText;

    //start searching
    while(text<pTextEnd)
    {
        p = pPattern;
        --text;
        //to find the first character
        while(text<pTextEnd && *++text!=*p)
            ;
        for(t = text; *++p; )
            if(*p != *++t)
                break;

        if(!*p)
            return (char*)text;

        text += shift_table[text[pattern_len]];
    }
	
    return NULL;
}
