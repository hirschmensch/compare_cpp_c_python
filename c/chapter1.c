#include <stdio.h>
#include <stdbool.h>

int multiply1(int, int);
bool odd(int);
int half(int);

int main(void)
{
	int val1 = 3;
	int val2 = 4;

	printf("%d * %d = %d",val1,val2,multiply1(val1,val2));

	return 0;
}

int multiply1(int n, int a)
{
	if(n == 1) return a;
	int result = multiply1(half(n), a + a);
	if(odd(n)) result = result + a;
	return result;
}

bool odd(int n)
{
	return n & 0x1;
}

int half(int n)
{
	return n >> 1;
}