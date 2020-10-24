#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 80

int atoi(char s[]){
  int i, n, sign;

  for(i = 0; isspace(s[i]);++i)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-'){
    ++i;
  }
  for(n = 0; isdigit(s[i]); ++i){
    n = 10*n+(s[i] - '0');
  }
  return sign * n;
  
}

int mygetline (char s[], int lim){
  int c, i;
  for (i=0;  i < lim-1 && (c=getchar())!=EOF &&  c!='\n'; ++i){
    s[i] = c;
  }
  s[i] = '\0';
  return i;
}

int main(){
  int len;
  char line[MAX_LENGTH];
  while((len = mygetline(line, MAX_LENGTH)) > 0){
    printf("%d\n", atoi(line));
  }
  return 0;
}
