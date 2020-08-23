// gcc -lm option is important!
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int multiply0(int, int);
int multiply1(int, int);
bool odd(int);
int half(int);

int main(void)
{
  int val1 = 10;
  int val2 = 5;
  int intBits = 0;
  int c = 0;
  int onesCount = 0;
  float numberOfAdds = 0;

  printf("n = %d a = %d\n", val1, val2);
  printf("%d * %d = %d\n",val1,val2,multiply0(val1,val2));
  printf("Number of adds: %d -> O(n)\n", val1);
  printf("%d * %d = %d\n",val1,val2,multiply1(val1,val2));
  numberOfAdds = log2((double)val1);
  intBits = sizeof(int)*8;
  for(c = 0; c < intBits; c++)
  {
    if(val1 & 0x1U) onesCount++;
    val1 = val1 >> 1;
  }
  printf("Number of adds: %f --> O(log(n))\n", numberOfAdds + (float)(onesCount - 1));

  return 0;
}

int multiply0(int n, int a)
{
  if(n == 1) return a;
  return multiply0(n - 1, a) + a;
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