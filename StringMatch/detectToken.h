#ifndef __DETECTTOKEN_H__
#define __DETECTTOKEN_H__

#include <string.h>
#include <stdlib.h>

void strstrMode(unsigned char * pBlob, int var_len);
void eBruteForce(unsigned char * pBlob, int var_len);
void eSundayMode(unsigned char *pBlob, int var_len);
void wordDelimiter(unsigned char * pBlob, int var_len);
//void memCmpMode(unsigned char * pBlob, int var_len);

#endif




