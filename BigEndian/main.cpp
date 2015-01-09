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
int main()
{
	if (isBigEndian())
		std::cout << "Is big-endian" << std::endl;
	else
		std::cout << "Is little-endian" << std::endl;
		
	return 0;
}
