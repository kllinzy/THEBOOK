#include <stdio.h>
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
//this is genius
int bitcount(int x){
  int count = 0;
  while(x != 0){
    x &= (x-1);
    ++count;
  }
  return count;
}
int main(){

  int x = -728913;
  printbinaryint(x);
  printf("%d\n", bitcount(x));
  return 0;
}
