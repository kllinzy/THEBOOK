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
int main(){

	int len;
	char line[MAX_LENGTH];

	while((len = mygetline(line, MAX_LENGTH)) > 0){
		if(len > MIN){
			printf("%s", line);
		}
	}
	return 0;

}
