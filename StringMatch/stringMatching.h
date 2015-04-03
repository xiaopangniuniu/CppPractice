#ifndef __STRINGMATCHING_H__
#define __STRINGMATCHING_H__

#include <string.h>
#include <stdlib.h>

typedef unsigned chartype;

char *bruteforce (const char *phaystack, const char *pneedle);
char *bruteforce_strstr_MS (const char *phaystack, const char *pneedle);
char *bruteforce_strstr_glibc (const char *phaystack, const char *pneedle);

char *kmp (const char *pText, const char *pPattern);
void getNext (const char *S, int *next);

char *sunday (const char *pText, const char *pPattern);

#endif
