#include <stdio.h>

#define MAX_LENGTH 3000 




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

void copy(char to[], char from[]){
	
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0'){
		++i;
	}
}

int main(){

	int len;
	int max;
	char line[MAX_LENGTH];
	char longest[MAX_LENGTH];

	max = 0;
	while((len = mygetline(line, MAX_LENGTH)) > 0){
		if(len > max){
			max = len;
			copy(longest, line);
		}
		if(max > 0){
			printf("%s: %d \n", longest, max);
		}
	}
	return 0;

}
