#include <stdio.h>

int binsearch(int x, int v[], int n){

  int low, high, mid;

  low = 0;
  high = n - 1;

  while(low <= high){

    mid = (low + high) / 2;
    if( x < v[mid]){
      high = mid - 1;
    }
    else if (x > v[mid]){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}
//this isn't worth it because we are upper bounded by nlogn still, but we are now lower bounded by nlogn, we don't get to stop when we find the result. 
int slowbinsearch(int x, int v[], int n){

  int low, high, mid;
  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while(low < high){
    printf("%d\t%d\t%d\n", low, mid, high);
    if( x <= v[mid]){
      high = mid;
    }
    else{
      low = mid + 1;
    }
    mid = (low + high) / 2;
    
  }
  if(v[mid] == x)
    return mid;
  return -1;
}
int main(){
  
  int testing[] = {12, 15, 35, 55 , 107, 144, 145, 146, 189, 203, 400, 561};
  printf("%d\n", slowbinsearch( 107, testing, 12));
  return 0;
}
