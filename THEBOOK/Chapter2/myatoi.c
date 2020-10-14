#include <stdio.h> 
#define MAX_LENGTH 10 

int stringToInt(char s[]){
	int n, i;

	n = 0;
	for( i = 0; s[i] >= '0' && s[i] <= '9'; ++i){
		n = 10 * n + (s[i] - '0');
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
	char line[MAX_LENGTH];
	while((len = mygetline(line, MAX_LENGTH)) > 0){
		printf("%d\n", stringToInt(line));
	}
	return 0;
}
