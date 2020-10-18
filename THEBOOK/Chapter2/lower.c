#include <stdio.h>

#define MAX_LENGTH 100
void lower(char s[], int lim){
  int i = 0;
	while(s[i] != '\0' && i < lim){
		s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] - 'A' + 'a' : s[i];
    ++i;
	}
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
  int len2;
  char line[MAX_LENGTH];
  char c;

  while((len = mygetline(line, MAX_LENGTH)) > 0 ) {

    lower(line, MAX_LENGTH);

    printf("lower: %s\n", line);
    printf("-----------------------------\n");
  }

  return 0;
}
