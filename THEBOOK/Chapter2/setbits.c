#include <stdio.h>

unsigned getbits(unsigned x, int p, int n){

  return (x >> (p+1-n) & ~(~0 << n));
}
void printbinary(unsigned x)
{
  int i;
  char binary[sizeof(unsigned)*8];

  binary[sizeof(unsigned)*8] = '\0';
  i = 0;
  
  while(i <sizeof(unsigned)*8)
    {
      
      if(x % 2)
        {
          binary[sizeof(unsigned)*8 - (i+1)] = '1';
        }
      else
        {
          binary[sizeof(unsigned)*8 - (i+1)] = '0';
        }
      x = x >> 1;
      ++i;
    }
  printf("%s\n", binary);
}
void printbinaryint(int x)
{
  int i;
  char binary[sizeof(int)*8];

  binary[sizeof(int)*8] = '\0';
  i = 0;
  
  while(i <sizeof(int)*8)
    {
      
      if(x % 2)
        {
          binary[sizeof(int)*8 - (i+1)] = '1';
        }
      else
        {
          binary[sizeof(int)*8 - (i+1)] = '0';
        }
      x = x >> 1;
      ++i;
    }
  printf("%s\n", binary);
}
unsigned setbits(unsigned x, unsigned y, int p, int n){

  y = (y & ~(~0<<n)) << (p-n+1);
  x = x & ~(~(~0 << n) << p-n) ;
  
  return x | y;
}

unsigned invert(unsigned x, int p, int n){

  return x ^ (~(~0 << n) << p -n + 1);

}
int rightrot(int x, int n){
  return (x >> n) | (~(~0 << n) << sizeof(int)*8 - n & (((x & ~(~0 << n)) << sizeof(int)*8 -n) | ~(~(~0 << n) << sizeof(int)*8 - n)));
}
int main() {

  int x = 0x00;
  int y = 0xFF;
  int p = 10;
  int n = 7;
  unsigned res = setbits(x,y,p,n);

  printf("%d\n", x);
  printf("%d\n", y);
  printbinary(res);
  printf("%d\n", res);
  printbinaryint(x);  
  printf("----------------------------------------\n");
  int result = rightrot(x,n);
  printbinaryint(result);
  printf("%d\n", result);
  return 0;

}
