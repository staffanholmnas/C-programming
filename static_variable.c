
#include<stdio.h>
int fun()
{
  static int count = 0; // static variable can be used to count how many times a function is called.
  count++;
  return count;
}
  
int main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}
