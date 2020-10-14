#include <stdio.h> 

#define NUM_SPACES 4
int main(){

	int n, c;

	n = NUM_SPACES;
	while((c = getchar()) != EOF){
		
		if(c == '\t'){
			for(int i = 0; i< n; ++i){
				putchar(' ');
			}
		}
		else{
			putchar(c);
		}
	}
	return 0;
}
