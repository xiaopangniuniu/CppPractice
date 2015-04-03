#include "stringMatching.h"

void preBmBc(const char* pPattern, int* bmBc)
{
	int pLen = strlen(pPattern);
	for (int i = 0; i < 128; ++i) // 假设字符串为ASCII可显示字符
		bmBc[i] = pLen;
	for (int i = 0; i < pLen; ++i) // 算出每个字符离pattern末尾的距离
		bmBc[pPattern[i]] = pLen-i;
}

void preBmGs(const char* pPattern, int* bmGs)
{
	int pLen = strlen(pPattern);
	// 计算距离
	int i = pLen - 1; 
	int sufLen = 1;
	for (; i >= 0; --i, ++sufLen)
	{
		// 利用BF算法找好后缀的重复串
		int j = pLen - 1;
		int k = j - sufLen;
		while (j > pLen - 1- sufLen)
		{
			if (pPattern[j] == pPattern[k])
				--j;
			--k;
		}
		// 找到了重复串
		if (pLen - 1- sufLen == j)
			bmGs[i] = k + sufLen;
		else // 没找到取上一次的重复串所在位置
			bmGs[i] = bmGs[i+1];
	}
}

char *bm(const char* pText, const char* pPattern)
{
	if (!*pPattern) // 空串
		return (char *)pText;
		
	int textLen = strlen(pText);
	int pattLen = strlen(pPattern);
	int bmBc[128] = {0};
	preBmBc(pPattern, bmBc);
	int bmGs[pattLen] = {0};
	preBmGs(pPattern, bmGs);
	
	int i = textLen, j = pattLen;
	while (i > 0 && j > 0)
	{
		if (pText[i] == pPattern[j])
		{
			--i;
			--j;
		}
		else
		{
			j = pattLen;
			// 两者中取大的那个
			i = bmBc[pText[i]] > (pattLen-1-i+bmGs[i]) ? bmBc[pText[i]] : (pattLen-1-i+bmGs[i]);
		}
	}
	// 匹配成功
	if (j < 0)
		return (char*)(pText+i);
	else
		return NULL;
}