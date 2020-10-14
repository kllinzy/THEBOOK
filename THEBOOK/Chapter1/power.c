#include <stdio.h> 

int power(int a, int b){
	int p; 

	for(p = 1; b > 0; --b){
		p *=a;
	}
	return p;
}
int main(){

	int p, n;
	p = 3; 
	n = 6; 
	
	printf("%d\n", power(p, n));
	printf("%d\n", n);
	return 0;

}
