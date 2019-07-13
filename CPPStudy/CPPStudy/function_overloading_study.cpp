#include"main.h"

void print(int x)
{
	std::cout << "int : " << x << std::endl;
}

void print(char x)
{
	std::cout << "char : " << x << std::endl;
}

void print(double x)
{
	std::cout << "double : " << x << std::endl;
}

void test_function_overloading(void)
{
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

}