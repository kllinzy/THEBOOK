#include <stdio.h>
#define MAX_LENGTH 100 
int main(){

	int c, count;
	int result[MAX_LENGTH] = {0};	
	count = 0;
	
	while((c = getchar()) != EOF){
	
		if(c == ' ' || c == '\n' || c == '\t')
		{
			++result[count];	
			count = 0;
		}	
		++count;
	}
	for(int i = 0; i < MAX_LENGTH; ++i){
		if(result[i] != 0){
			printf("%d: ", i);
			for(int j = 1; j <= result[i]; ++j){
				printf("-");
			}
			printf("\n");
		}
	}
	return 0;
}
