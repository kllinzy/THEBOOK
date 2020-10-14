#include <stdio.h> 

long power(long a, long b){
	long p; 

	for(p = 1; b > 0; --b){
		p *=a;
	}
	return p;
}

int main(){ 
	char k; 
	k = 0;
	int numBits = 8 * sizeof(k);

	
	printf("char range = %ld\n", power(2,numBits));
	

	int l; 
	l = 0;
	long longNumBits = 8* sizeof(l);
	printf("int range = %ld\n", power(2,longNumBits));
	return 0;
}
