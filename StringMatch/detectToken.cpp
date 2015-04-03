#include "detectToken.h"
#include "stringMatching.h"

extern unsigned short responseCode_;
extern unsigned char reasonHeaderQ850Present_;

const int TokenLenConst = 5;

void strstrMode(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
	    return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;
    char *pQ850 = "Q.850";
    char *pCause = "cause";

    char *p = (char *)pBlob;
    bool q850FindFlag = false;
    while(!reasonHeaderQ850Present_ && *p)
    {
        char *pToken;
        if(!q850FindFlag && !(pToken = strstr(p, pQ850)))
	          return;

        q850FindFlag = true;
	    if(q850FindFlag && !(pToken = strstr(pToken+TokenLenConst, pCause)))
	        return;

	    pToken += TokenLenConst;
	    while(*pToken && ('=' == *pToken || ' ' == *pToken))
	       ++pToken;

	    if(*pToken && (*pToken < '0' || *pToken > '9'))
	    {
	        p = pToken;
	        q850FindFlag = false;
	        continue;
	    }

	    while(*pToken && *pToken >= '0' && *pToken <= '9')
	    {
	        reasonHeaderQ850Present_ = 1;
	        responseCode_ = responseCode_ * 10 + (*pToken++ - '0');
	    }
	}

    return;
}

//C - version 8 - implement brute force manually
 void eBruteForce(unsigned char * pBlob, int var_len)
 {
     if(NULL == pBlob)
         return;

     const int LEN_Q850 = 5;
     const int LEN_CAUSE = 5;
     const char TOKEN_Q850[LEN_Q850+1] = "Q.850";
     const char TOKEN_CAUSE[LEN_CAUSE+1] = "cause";

     unsigned char *p = pBlob;
     unsigned char *pEnd = pBlob+var_len;
     reasonHeaderQ850Present_ = 0;
     responseCode_ = 0;
     int i = 0;

     while (p<pEnd)
         {
         while(p<pEnd && *p++!=TOKEN_Q850[0])
             ;
         for (i=1; i<LEN_Q850;)
             if (*p++==TOKEN_Q850[i])
                 ++i;
             else
                 break;
         if (i==LEN_Q850)
             {
             //++p;
             while(p<pEnd && *p++!=TOKEN_CAUSE[0])
                 ; //++p;
             for (i=1; i<LEN_CAUSE;)
                 if (*p++==TOKEN_CAUSE[i])
                     ++i;
                 else
                     break;
             if (i==LEN_CAUSE)
                 {
                 while (p<pEnd && (*p==' ' || *p== '\t' || *p=='='))
                     ++p;
                 unsigned char * pValue = p;
                 while (p<pEnd && *p >='0' && *p <= '9')
                     responseCode_ = (responseCode_ * 10) + (*p++ -'0');
                 if (p != pValue)
                     {
                     reasonHeaderQ850Present_ = 1;
                     return;
                     }
                 }
             }
         }
     //return;
 }

void eSundayMode(unsigned char *pBlob, int var_len)
{
    if(NULL == pBlob)
        return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    const int TOKEN_LEN = 5;
    char *pQ850Token = "Q.850";
    char *pCauseToken = "cause";
    const int ASCII_SIZE = 128;
    int q850_shift_table[ASCII_SIZE];
    int cause_shift_table[ASCII_SIZE];
    char *pToken;

    //construct moving distance table
    for(int i = 0; i < ASCII_SIZE; ++i)
        q850_shift_table[i] = TOKEN_LEN+1;
    for(pToken = pQ850Token; *pToken; ++pToken)
        q850_shift_table[*pToken] = TOKEN_LEN - (pToken - pQ850Token);
    for(int i = 0; i < ASCII_SIZE; ++i)
        cause_shift_table[i] = TOKEN_LEN+1;
    for(pToken = pCauseToken; *pToken; ++pToken)
        cause_shift_table[*pToken] = TOKEN_LEN - (pToken - pCauseToken);

    unsigned char *p, *pTokenStart = pBlob;
    unsigned char *pBlobEnd = pBlob+var_len;
    pToken = pQ850Token;
    bool q850FindFlag = false;
    while(pTokenStart < pBlobEnd)
    {
        //to find the first character
        --pTokenStart;
        do
            if(!*++pTokenStart)
                return;
        while(*pTokenStart != *pToken);

        for(p = pTokenStart; *pToken; )
            if(*++p != *++pToken)
                break;
        if(!*pToken)
        {
            if(!q850FindFlag)
            {
                //found the "Q.850"
                q850FindFlag = true;
                pToken = pCauseToken;
                continue;
            }
            else
            {
                //found the "cause" and then to get cause value
                while (*p && ((' '==*p) || ('='==*p) || ('\t'==*p)))//delimitate
                    ++p;
                unsigned char *pValue = p; //here is a good method
                while (*p && *p >='0' && *p <= '9')
                    responseCode_ = responseCode_ * 10 + (*p++ -'0');
                if(p != pValue)
                {
                    reasonHeaderQ850Present_ = 1;
                    return;
                }
                q850FindFlag = false;
                pToken = pQ850Token;
            }
        }//if(!*pToken)

        if(!q850FindFlag)
            pTokenStart += q850_shift_table[pTokenStart[TOKEN_LEN]];
        else
            pTokenStart += cause_shift_table[pTokenStart[TOKEN_LEN]];

    }
}

 //J - wordDelimiter version4
 void wordDelimiter(unsigned char * pBlob, int var_len)
 {
     if(NULL == pBlob)
         return;

     reasonHeaderQ850Present_ = 0;
     responseCode_ = 0;
     char *pQ850Token = "Q.850";
     char *pCauseToken = "cause";
     char *pToken = pQ850Token;

     char *pTokenEnd = (char*)pBlob;
     bool q850FindFlag = false;
     while (*pTokenEnd)
     {
         --pTokenEnd;
         do
             if(!*++pTokenEnd)
                 return;
         while(*pTokenEnd != *pToken);
         char *pTokenStart = pTokenEnd;
         //OPTIMIZE:   Use "&&" rather than "||".
         //OPTIMIZE:   Put the token with highest frequency in the first place to enhance the efficiency.
         //scan the text
         while((';'!=*pTokenEnd)
             && (' '!=*pTokenEnd)
             && (':'!=*pTokenEnd)
             && ('='!=*pTokenEnd)
             && ('\t'!=*pTokenEnd)
             && ('\n'!=*pTokenEnd))//delimitate
             ++pTokenEnd;

             if(pTokenEnd - pTokenStart != TokenLenConst)
             {
                 ++pTokenEnd;
                 continue;
             }

             char tmp_char = *pTokenEnd;
             *pTokenEnd = '\0';
             if(!strcmp(pTokenStart, pToken))//memcmp() is slower than strcmp()
             {
                 *pTokenEnd = tmp_char;
                 if(!q850FindFlag)
                 {
                     q850FindFlag = true;
                     pToken = pCauseToken;
                     continue;
                 }
                 else
                 {
                     //To get cause value
                     while (*pTokenEnd && ((' '==*pTokenEnd) || ('='==*pTokenEnd) || ('\t'==*pTokenEnd)))//delimitate
                         ++pTokenEnd;

                     if(*pTokenEnd && (*pTokenEnd < '0' || *pTokenEnd > '9'))
                     {
                         q850FindFlag = false;
                         pToken = pQ850Token;
                         continue;
                     }

                     while (*pTokenEnd && *pTokenEnd >='0' && *pTokenEnd <= '9')
                     {
                         reasonHeaderQ850Present_ = 1;
                         responseCode_ = responseCode_ * 10 + (*pTokenEnd++ -'0');
                     }

                     if(reasonHeaderQ850Present_)
                         return;
                 }
             }//if(!memcmp(pTokenStart, pToken, TokenLenConst))
             *pTokenEnd = tmp_char;
     }//while
     return;
 }


/******************************************Other version for test*********************************************/

/*void strstrMode_1(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
        return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;
    char *pReasonHeader;
    char q850_token[6] = "Q.850";
    char cause_token[6] = "cause";
    char *pCause;
    const char *pProtocol;
    const char *pfCause;
    unsigned char causeLenChar = 0;

    char tmpChar = pBlob[var_len];
    pBlob[var_len] = '\0';
    pReasonHeader = (char*)pBlob;

    pProtocol = strstr(pReasonHeader, q850_token);
    if(NULL == pProtocol)
        return;

    pCause = strstr(pProtocol, cause_token);
    if (NULL == pCause)
        return;

    reasonHeaderQ850Present_ = 1;
    pCause += TokenLenConst;
    for(int i = pCause - pReasonHeader; i < var_len; ++i)
    {
        while(*pCause < '0' || *pCause > '9')
            ++pCause;
        pfCause = pCause;
        while(*pfCause >= '0' && *pfCause <= '9')
        {
            causeLenChar++;
            ++pfCause;
        }
    }

    pBlob[var_len] = tmpChar;
    tmpChar = pCause[causeLenChar];
    pCause[causeLenChar] = '\0';

    responseCode_ = atoi(pCause);

    pCause[causeLenChar] = tmpChar;

    return;
}*/

/*void memCmpMode(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
	    return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    char *pQ850 = "Q.850";
    char *pCause = "cause";

    //int q850StrLen = strlen(pQ850);
	//int causeStrLen = strlen(pCause);

    int q850StrLen = TokenLenConst;
    int causeStrLen = TokenLenConst;

    bool q850FindFlag = false;
    int i;
    for(i = 0; i < var_len - q850StrLen; ++i)
	{
	    if(0 == memcmp(pBlob+i, pQ850, q850StrLen))
	    {
	        q850FindFlag = true;
	        break;
	    }
	}

    if(!q850FindFlag)
	    return;

    for(i += q850StrLen; i < var_len - causeStrLen; ++i)
	{
	if(0 == memcmp(pBlob+i, pCause, causeStrLen))
	    {
	    reasonHeaderQ850Present_ = 1;
	    break;
	    }
	}

    if(1 != reasonHeaderQ850Present_)
	    return;


    bool responseCodeStartFlag = false;
    for(i += causeStrLen; i < var_len; ++i)
	{
        if(!responseCodeStartFlag)
        {
            if(pBlob[i] < '0' || pBlob[i] > '9')
        	    continue;
            else
        	{
        	    responseCodeStartFlag = true;
        	    responseCode_ = pBlob[i] - '0';
        	}
        }
        else
        {
            if(pBlob[i] < '0' || pBlob[i] > '9')
        	    break;
            else
        	    responseCode_ = responseCode_ * 10 + (pBlob[i] -'0');
        }
	}

    return;
}*/

/*//J - wordDelimiter version1
void wordDelimiter_1(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
	    return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    char *pQ850 = "Q.850";
    char *pCause = "cause";

    int wordStartList[1000] = {0};
    bool wordStartFlag = false;
    int i, j;
    for(i = 0, j = 0; i < var_len; ++i)
	{
	    if(':' == pBlob[i] || ';' == pBlob[i] || ' ' == pBlob[i] ||
           '=' == pBlob[i] || '(' == pBlob[i] || ')' == pBlob[i] ||
	       '"' == pBlob[i] || '\t' == pBlob[i] || '\n' == pBlob[i])
	    {
	        pBlob[i] = '\0';
	        wordStartFlag = false;
	        continue;
	    }
	    else if (!wordStartFlag)
	    {
            wordStartFlag = true;
	        wordStartList[j++] = i;
	    }
	}

    int wordCount = j;
    bool tokenFindFlag = false;
    for(i = 0; i < wordCount; ++i)
	{
	    if(0 != strcmp((char*)(pBlob+wordStartList[i]), pQ850))
	        continue;
	    else
	    {
	        tokenFindFlag = true;
	        break;
	    }
	}
    if(!tokenFindFlag)
	    return;

    tokenFindFlag = false;
    for(; i < wordCount; ++i)
	{
	    if(0 != strcmp((char*)(pBlob+wordStartList[i]), pCause))
	        continue;
	    else
	    {
	        tokenFindFlag = true;
	        break;
	    }
	}
    if(!tokenFindFlag)
	    return;

    for(; i < wordCount; ++i)
	{
	    if(pBlob[wordStartList[i]] < '0' || pBlob[wordStartList[i]] > '9')
	        continue;
	    else
	    {
	        tokenFindFlag = true;
		    for(j = wordStartList[i]; j < wordStartList[i+1]; ++j)
			{
	            if(pBlob[j] < '0' || pBlob[j] > '9')
	        	    break;
	            else
	       	        responseCode_ = responseCode_ * 10 + (pBlob[j] -'0');
			} 
		    break;
	    }
	}
    if(!tokenFindFlag)
	    return;

    return;
}*/

/*//J - wordDelimiter version2
void wordDelimiter_2(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
		return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

	char *pQ850Token = "Q.850";
	char *pCauseToken = "cause";
    //int q850StrLen = 5;
    //int causeStrLen = 5;
	char *pToken = NULL;

	bool q850FindFlag = false;
	char *p = (char*)pBlob;
	while(!reasonHeaderQ850Present_ && (p - (char*)pBlob) < var_len)
	    //	while(*p)
		{
		pToken = p;
		//OPTIMIZE:   Use "&&" rather than "||".
		//OPTIMIZE:   Put the token with highest frequency in the first place to enhance the efficiency.
		//scan the text
		while(*p && (';'!=*p) && (' '!=*p) && (':'!=*p) && ('='!=*p) && ('\t'!=*p) && ('\n'!=*p))//delimitate
			++p;
        if(p - pToken != TokenLenConst)
            {
            ++p;
            continue;
            }

		//char tmp_char = *p;
		//*p = '\0';

		//found the "Q.850", then to find "cause"
		if(q850FindFlag && !memcmp(pToken, pCauseToken, TokenLenConst))
			{
			//*p = tmp_char;
			//To get cause value
			while (*p && ((' '==*p) || ('='==*p) || ('\t'==*p)))//delimitate
				++p;
			pToken = p;
			while (*p >='0' && *p <= '9')
				++p;
			char tmp_char= *p;
			*p = '\0';
			if (*pToken)
				{
				responseCode_ = atoi(pToken);
				*p = tmp_char;
				return;
				}
			*p = tmp_char;
			if(*p && (*p < '0' || *p > '9'))
			    {
			    q850FindFlag = false;
			    continue;
			    }

			while (*p && *p >='0' && *p <= '9')
			    {
			    reasonHeaderQ850Present_ = 1;
			    responseCode_ = responseCode_ * 10 + (*p -'0');
			    ++p;
			    }
			}
		if(!q850FindFlag && !memcmp(pToken, pQ850Token, TokenLenConst))// why reorder
			{
			q850FindFlag = true;
			//*p = tmp_char;
			continue;
			}

		else
			{
			*p = tmp_char;
			}
		
		}
	return;
}*/

/*//J - wordDelimiter version3
void wordDelimiter_3(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
	    return;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    char *pQ850 = "Q.850";
    char *pCause = "cause";

    bool Q850Flag = false;
    char *p = (char*)pBlob;
    while (*p)
	{
	char *pToken = p;
	while ((':'!= *p) && (';'!=*p) && (' '!=*p) && ('='!= *p) && ('\t'!=*p) && ('\n'!=*p)) // delimitate
	    ++p;
	char c = *p;
	*p = '\0';
	while (*pToken==' '||*pToken=='\t') ++pToken;

	if(Q850Flag && *pToken && !strcmp(pToken, pCause))
	    {
	    *p = c;
            // get cause "cause = 0-9"
            while (*p==' ' || *p== '\t' || *p=='=') ++p; // delimitate
            pToken = p;
            while (*p>='0' && *p<='9') ++p;
            c = *p;
            *p = 0;
            if (*pToken)
                {
        	reasonHeaderQ850Present_ = 1;
                responseCode_ = atoi(pToken);
                *p = c;
                break;
                }
            }
        if(!Q850Flag && *pToken && !strcmp(pToken, pQ850)) // why reorder
            {
            Q850Flag = true;
            }
        if (!c)
            break;
        *p++ = c;
    }
}*/

/*//C - version 2 strcmp
void wordDelimiter_22(unsigned char * pBlob, int var_len)
{
    char pQ850[6] = "Q.850";
    char pCause[6] = "cause";

    bool Q850Flag = false;
    char *p = (char *) pBlob;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    // set end of string to '\0'
    char tmpChar = pBlob[var_len];
    pBlob[var_len] = '\0';
    char *pToken, c;

    while (*p)
    {
        while(*p && !((*p>'a' && *p<='z') || (*p>='A' && *p <='Z'))) ++p;
        //while (';'==*p) || (' '==*p) || (':'==*p) || ('='==*p) || ('\t'==*p) || ('\n'==*p) || ('"'==*p)) ++p;
        pToken = p;
        while(*p && (';'!=*p) && (' '!=*p) && (':'!=*p) && ('='!=*p) && ('\t'!=*p) && ('\n'!=*p) && ('"'!=*p)) ++p;
        c = *p;
        *p = 0;

        if (Q850Flag && *pToken && (p-pToken == 5) && !strcmp(pToken, pCause))
        {
            // get cause "cause = 0-9"
            *p = c;
            while (*p==' ' || *p== '\t' || *p=='=') ++p; // delimitate

            pToken = p;
            while (*p>='0' && *p<='9') ++p;
            c = *p;
            *p = 0;
            if (*pToken)
                {
                reasonHeaderQ850Present_ = 1;
                responseCode_ = atoi(pToken);
                *p = c;
                break;
                }
            Q850Flag = false;
            *p = c;
        }
        if(!Q850Flag && *pToken && (p-pToken == 5) && !strcmp(pToken, pQ850)) // why reorder
            Q850Flag = true;
        if (c)
            *p++ = c;
    }

    // set back end of string.
    pBlob[var_len] = tmpChar;
    return;
 }
*/

/*//C - Version 3 memcmp
void wordDelimiter_23(unsigned char * pBlob, int var_len)
{
    char pQ850[6] = "Q.850";
    char pCause[6] = "cause";

    bool Q850Flag = false;
    char *p = (char *) pBlob;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    // set end of string to '\0'
    char tmpChar = pBlob[var_len];
    pBlob[var_len] = '\0';
    char *pToken, c;

    while (1)
    {
        while(*p && !((*p>'a' && *p<='z') || (*p>='A' && *p <='Z'))) ++p;
        pToken = p;
        while(*p && (';'!=*p) && (' '!=*p) && (':'!=*p) && ('='!=*p) && ('\t'!=*p) && ('\n'!=*p) && ('"'!=*p)) ++p;

        if(!Q850Flag && (p-pToken == 5) && *pToken==pQ850[0] && !memcmp(pToken, pQ850, 5))
            {
            Q850Flag = true;
            if (!*p) break;
            p++;
            continue;
            }
        if (Q850Flag && (p-pToken == 5) && *pToken==pCause[0] && !memcmp(pToken, pCause, 5))
            {
            // get cause "cause = 0-9"
            *p = c;
            while (*p==' ' || *p== '\t' || *p=='=') ++p; // delimitate
            pToken = p;
            while (*p>='0' && *p<='9') ++p;
            c = *p;
            *p = 0;
            if (*pToken)
                {
                reasonHeaderQ850Present_ = 1;
                responseCode_ = atoi(pToken);
                *p = c;
                break;
                }
            Q850Flag = false;
            *p = c;
            }
        if (!*p) break;
        p++;
    }

    // set back end of string.
    pBlob[var_len] = tmpChar;
    return;
 }
*/

/*//C - Version 4
void wordDelimiter_24(unsigned char * pBlob, int var_len)
{
    const char pQ850[6] = "Q.850";
    const char pCause[6] = "cause";

    unsigned char *p = pBlob;
    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;
    //bool Q850Flag = false;

    while (p-pBlob<var_len)
    {
    while (p-pBlob<var_len)
        {
        while(p-pBlob<var_len && *p!=pQ850[0])
            ++p;
        if (var_len-(p-pBlob)>TokenLenConst && !memcmp(p, pQ850, TokenLenConst))
            {
            //Q850Flag = true;
            p+=TokenLenConst;
            break;
            }
        else
            {
            p++;
            }
        }
    //if (!Q850Flag)
        //return;

    while (p-pBlob<var_len)
        {
        while(p-pBlob<var_len && *p!=pCause[0])
            ++p;
        if (var_len-(p-pBlob)>TokenLenConst && !memcmp(p, pCause, TokenLenConst))
            {
            p += TokenLenConst;

            while (p-pBlob<var_len && (*p==' ' || *p== '\t' || *p=='='))
                ++p;
            unsigned char * pValue = p;
            while (p-pBlob<var_len && *p >='0' && *p <= '9')
                {
                responseCode_ = (responseCode_ * 10) + (*p++ -'0');
                }
            if (p != pValue)
                {
                reasonHeaderQ850Present_ = 1;
                return;
                }
            break;
            }
        else
            {
            p++;
            }
        }
    }

    return;
 }
*/

/*//C - version 5
void wordDelimiter_25(unsigned char * pBlob, int var_len)
{
    const int LEN_Q850 = 5;
    const int LEN_CAUSE = 5;
    const char TOKEN_Q850[LEN_Q850+1] = "Q.850";
    const char TOKEN_CAUSE[LEN_CAUSE+1] = "cause";

    unsigned char *p = pBlob;
    unsigned char *pEnd = pBlob+var_len;
    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    while (pEnd-p>LEN_Q850+LEN_CAUSE+3)
    {
    while (pEnd-p>LEN_Q850+LEN_CAUSE+3)
        {
        while(p<pEnd && *p!=TOKEN_Q850[0])
            ++p;
        if (!memcmp(++p, TOKEN_Q850+1, LEN_Q850-1))
            {
            p+=LEN_Q850;
            break;
            }
        }

    while (pEnd-p>LEN_CAUSE+2)
        {
        while(p<pEnd && *p!=TOKEN_CAUSE[0])
            ++p;
        if (!memcmp(++p, TOKEN_CAUSE+1, LEN_CAUSE-1))
            {
            p+=LEN_CAUSE;
            while (p<pEnd && (*p==' ' || *p== '\t' || *p=='='))
                ++p;
            unsigned char * pValue = p;
            while (p<pEnd && *p >='0' && *p <= '9')
                responseCode_ = (responseCode_ * 10) + (*p++ -'0');
            if (p != pValue)
                {
                reasonHeaderQ850Present_ = 1;
                return;
                }
            }
        break;
        }
    }

    return;
 }*/

/*//C - version 6
 void wordDelimiter_26(unsigned char * pBlob, int var_len)
{
    const int LEN_Q850 = 5;
    const int LEN_CAUSE = 5;
    const char TOKEN_Q850[LEN_Q850+1] = "Q.850";
    const char TOKEN_CAUSE[LEN_CAUSE+1] = "cause";

    unsigned char *p = pBlob;
    unsigned char *pEnd = pBlob+var_len;
    int i = 0;

    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    //while (pEnd-p>LEN_Q850+LEN_CAUSE+3)
    while (p<pEnd)
    {
    //while (pEnd-p>LEN_Q850+LEN_CAUSE+3)
    while (p<pEnd)
        {
        i = 0;
        while (*p++ == TOKEN_Q850[i++] && i<LEN_Q850)
            {
            }
        if (i!=LEN_Q850)
            continue;
        break;
        }

    //while (pEnd-p>LEN_CAUSE+2)
    while (p<pEnd)
        {
        i=0;
        while (*p++ == TOKEN_CAUSE[i++] && i<LEN_CAUSE)
            {
            }
        if (i!=LEN_CAUSE)
            continue;
        // Found
        while (p<pEnd && (*p==' '||*p== '\t'||*p=='='))
            ++p;
        unsigned char * pValue = p;
        while (p<pEnd && *p>='0' && *p<='9')
            responseCode_ = (responseCode_*10) + (*p++ - '0');
        if (p != pValue)
            {
            reasonHeaderQ850Present_ = 1;
            return;
            }
        break;
        }
    }

    return;
 }
*/

/* //C - version 7
void wordDelimiter_27(unsigned char * pBlob, int var_len)
{
    if(NULL == pBlob)
        return;

    const char TOKEN_Q850[6] = "Q.850";
    const char TOKEN_CAUSE[6] = "cause";

    unsigned char *p = pBlob, *pTmp;
    unsigned char *pEnd = pBlob+var_len-3;
    unsigned char *pEnd_Cause = pEnd-TokenLenConst;
    int i = 0;
    reasonHeaderQ850Present_ = 0;
    responseCode_ = 0;

    for (;p<pEnd_Cause;)
    {
        if (i==TokenLenConst)
        {
            for (i=0; p<pEnd; )
            {
                if (i==TokenLenConst)
                {// Found
                    while ((*p==' '||*p=='='))
                        p++;
                    pTmp = p;
                    while (*p>='0' && *p<='9')
                    {
                        responseCode_ = 10*responseCode_+*p++ - '0';
                    }
                    if (p!=pTmp)
                    {
                        reasonHeaderQ850Present_ = 1;
                        return;
                    }
                    i = 0;
                    break;
                }
                else
                {
                    if (*p++!=*(TOKEN_CAUSE+i++))
                        i = 0;
                }
            }
        }
        if (*p++!=*(TOKEN_Q850+i++))
            i = 0;
    }
}*/

/******************************************Other version for test*********************************************/

