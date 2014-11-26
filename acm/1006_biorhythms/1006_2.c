/*
 * Web Site: http://poj.org/problem?id=1006
 * Date: 11/8/2013
 * Command: gcc -m32 -g -o 1006 1006_2.c
 * Ref: poj book section 8.2
 */
#include <stdio.h>

void main()
{
    int p,e,i,d,j,no=1;
    scanf("%d%d%d%d", &p, &e, &i, &d);
    while(p!=-1 && e!=-1 && i!=-1 && d!=-1)
    {
        for(j=d+1; j<21252; j++)
            if ((j-p)%23 == 0)
                break;
        for( ; j<21252; j=j+23)
            if ((j-e)%28 == 0)
                break;
        for( ; j<21252; j=j+23*28)
            if ((j-i)%33 == 0)
                break;
        printf("Case %d", no);
        printf(": the next triple peak occurs in %d days.\n", j-d);
        scanf("%d%d%d%d", &p, &e, &i, &d);
        no++;
    }
}
