#include "stringMatching.h"

char *kmp(const char* pText, const char* pPattern)
{
	if (!*pPattern) // 空串
		return (char *)pText;
	
	int tLen = strlen(pText);
	int pLen = strlen(pPattern);
	int next[pLen] = {0};
	getNext(pPattern, next);

	int i(0), j(0);
	while(i < tLen && j < pLen
	      && (tLen-i) > (pLen-j))
	{
		if (pText[i] != pPattern[j])
		{
			j = next[j];
			if (-1 != j) // 非第1个不匹配字符
				continue;
		}
		++i; ++j;
	}
	if (pLen == j)
		return (char*)(pText+i-pLen);
	else
		return NULL;
}

void getNext (const char *pPattern, int *pNext)
{
    int pLen = strlen(pPattern);
	pNext[0] = -1;
    int k(-1), j(0);
    while(j < pLen-1)
    {
        if(pPattern[k] == pPattern[j] || -1 == k)
            pNext[++j] = ++k;
        else
            k = pNext[k]; //k = pNext[pNext[j]] = pNext[k];
    }
}
