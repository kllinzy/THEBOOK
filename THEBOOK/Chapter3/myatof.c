#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 80

double atof(char s[]){
  double val, power, sci, scipower;
  int i, j, k, sign, scisign;

  for(i = 0; isspace(s[i]);++i)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-'){
    ++i;
  }
  for(val = 0.0; isdigit(s[i]); ++i){
    val = 10.0*val+(s[i] - '0');
  }
  if(s[i] == '.'){
    ++i;
  }
  for(power = 1.0; isdigit(s[i]);++i){
    val = 10.0*val+(s[i] - '0');
    power *= 10.0;
  } 
  if(s[i] == 'e' || s[i] == 'E'){
    ++i;
  }
  scisign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-'){
    ++i;
  }
  for(sci = 1.0, scipower = 1.0; isdigit(s[i]); ++i){
    int temp = s[i] - '0';
    //we can do something special in here
    if(sci> 1.0){
      for(k = 0; k < 10; ++k)
      sci*=scipower;
    }
    for(j = 0; j < temp; ++j)
      sci *= 10;
    scipower *=10;
  }

  return scisign < 0 ? (sign * val / power) / sci : (sign * val / power) * sci;
  
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
    printf("%f\n", atof(line));
  }
  return 0;
}
