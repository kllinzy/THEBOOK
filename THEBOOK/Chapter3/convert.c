#include <stdio.h>

void replace(char c) {
switch(c){
    case '\t':
      putchar('\\');
      putchar('t');
      break;
    case '\n':
      putchar('\\');
      putchar('n');
      break;
    case ' ':
      putchar('\\');
      putchar('s');
      break;
    default:
      putchar(c);
    }

}

int main(){
  _Bool lastIsSpace = 0;
  char c;
  while((c = getchar()) != EOF){
    replace(c);
  }
  return 0;
}
