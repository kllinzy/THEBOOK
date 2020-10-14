#include <stdio.h>


int main(){

	int c;
	printf("end of file is represented as %d \n", EOF);
	while ((c = getchar()) != EOF) {
		printf("%d", c != EOF);
		putchar(c);
	}
}	
