#include <stdio.h>

void toRoman(int num)
{
	static char *roman[][10]={"","I","II","III","IV","V","VI","VII","VIII","IX",
			      "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
			      "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
			      "","M","MM","MMM"};
	int i, j, n;
	printf("%d = ", num);
	for(j = 0, i = 10000; j < 4; ++j, i/=10)
	{
		n = (num%i) / (i/10);
		printf("%s",roman[3-j][n]);
	}
	printf("\n");
}

int main()
{
	int n;
	char* roman;
	printf("Please enter a decimal number (1-3999):");
	scanf("%d", &n);
	if(n < 1 || n > 3999)
	{
		printf("Illegal Parameter!\n");
		return 1;
	}
	toRoman(n);
	
	return 0;
}
