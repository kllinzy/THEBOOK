#include <stdio.h>


void shellsort(int v[], int n){
  int gap, i, j, temp;

  for(gap = n/2; gap > 0; gap /= 2)
    for(i = gap; i < n; i++)
      for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
	temp = v[j];
	v[j] = v[j+gap];
	v[j+gap] = temp;
    }
}

void printArr(int v[], int n){
  int i = 0;

  while(i < n - 1){
    printf("%d, ", v[i]);
    ++i;
  }
  printf("%d\n", v[i]);
}

int main(){
  int x[] =  {13,43,55,54,23,5,21,5,6,23,6,7,8,987,34,23,543,7,567,543,34,4,32,56,9,43,7,987,56,34};
  int n = 30;
  printArr(x,n);
  shellsort(x,n);
  printArr(x,n);
  return 0;
}
