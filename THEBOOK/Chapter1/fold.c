#include <stdio.h> 
#define MAX_LENGTH 1000
#define CORRECT_LENGTH 14 



int main(){

	char line[MAX_LENGTH];
	int c, n, counter, index;


	n = CORRECT_LENGTH;
	counter = 0;
	index = 0;
	while((c = getchar()) != EOF){ 
			
		//print when we see new line and reset
		if(c == '\n'){
			line[counter] = '\0'; 
			printf("%s\n", line);
			index = 0; 
			counter = 0; 
		}
		//print when we hit limit and reset
		else if(counter == n){
			line[index+1] = '\0';
			printf("%s\n", line);
			index = 0; 
			counter =0; 
		}
		if(c != ' ' && c != '\t'){
			index = counter; // set the index to chop at
		}
		line[counter] = c;
		++counter;	
	}
	
	return 0;

}
