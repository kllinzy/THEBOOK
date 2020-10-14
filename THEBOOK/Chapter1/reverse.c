#include <stdio.h> 

#define MAX_LENGTH 1000 
#define MIN 80

int mygetline (char s[], int lim){
	int c, i;

	for (i=0; (c=getchar())!=EOF && c!='\n';++i){

		if(i<lim-1){

			s[i] = c;
			if (c == '\n'){
				s[i] = c;
				++i;
			}
		}
	}

	if(i > lim - 1){
		s[lim-1] = '\0';
	}	
	else{
		s[i] = '\0';
	}
	return i;


}
void reverse(char from[], char to[], int len){

	int i;
	i = 0;
	while(i < len){
		to[i] = from[len-(i+1)];
		++i;
	}	
	to[len] = '\0';

}

int main(){

	int len;
	char line[MAX_LENGTH];
	char reversed[MAX_LENGTH];

	while((len = mygetline(line, MAX_LENGTH)) > 0){
		reverse(line, reversed, len);
		printf("%s\n", reversed);
	}
	return 0;

}
