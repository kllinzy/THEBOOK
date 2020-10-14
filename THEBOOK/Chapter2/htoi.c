#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 11
int hexStringToInt(char s[]){
  int n, i;

  n = 0;
  for(i = 0; isxdigit(s[i]) || (i == 1 && tolower(s[i]) == 'x'); ++i){
    if((i == 0 && s[i] == '0') || (i == 1 && tolower(s[i]) == 'x')){
      continue;
    }
    n = n * 16 + ((s[i] - '0') * (isdigit(s[i]) != 0)) +
      ((tolower(s[i]) - 'a' + 10) * !(isdigit(s[i]) != 0));
  }
  return n;

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

	char line[(2*sizeof(int) + 3)];
	while((len = mygetline(line, MAX_LENGTH)) > 0){
		printf("%d\n", hexStringToInt(line));
	}
	
  return 0;
}
