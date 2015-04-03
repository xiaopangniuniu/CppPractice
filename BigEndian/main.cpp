// g++ -g -O3 -o bigEndian main.cpp
#include <iostream>

bool isBigEndian()
{
	int a = 0x1234;
	// int -> char
	char b = *(char *)&a;
	if ( b == 0x12)
		return true;
	return false;
}

bool isBigEndian_union()
{
	union NUM
	{
		int a;
		char b;
	} num;
	num.a = 0x1234;
	if (num.b == 0x12)
		return true;
	return false;
}

int main()
{
	if (isBigEndian())
		std::cout << "Is big-endian" << std::endl;
	else
		std::cout << "Is little-endian" << std::endl;
		
	if (isBigEndian_union())
		std::cout << "UNION: Is big-endian" << std::endl;
	else
		std::cout << "UNION: Is little-endian" << std::endl;
		
	return 0;
}
