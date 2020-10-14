#include <stdio.h>


int main(){

	_Bool lastIsSpace = 0;
	char c;

	while((c = getchar()) != EOF){

		if(c == '\t'){
			putchar('\\');
			putchar('t');
			continue;
		}		  
		if(c == '\b'){
			putchar('\\');
			putchar('b');
			continue;
		}
		if(c == '\\'){
			putchar('\\');
			putchar('\\');
			continue;
		}
		if(c == ' ' && !lastIsSpace){
			putchar(c);
			lastIsSpace = 1;
		}
		else if(c != ' '){
			putchar(c);
			lastIsSpace = 0;
		}


		
	}

	return 0;
}
