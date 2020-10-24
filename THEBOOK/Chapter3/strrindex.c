#include <stdio.h>

#define MAX_LENGTH 300

int strrindex(char s1[], char s2[], int lim){
  int i = 0;
  int index = -1;
  while(s1[i] != '\0'){
    int temp = 0;
    for(int j = 0; j < lim && s2[j] != '\0'; ++j){
      if(s1[i+j] != s2[j]){
	temp = 1;
	break;
      }
    }
    if(temp == 0){
      index = i;
    }
    ++i;
  }
  return index; 
}

int mygetline (char s[], int lim){
  int c, i;
  for (i=0;  i < lim-1 && (c=getchar())!=EOF &&  c!='\n'; ++i){
    s[i] = c;
  }
  s[i] = '\0';

  return i;
}

int main(){
  char s1[MAX_LENGTH];
  char s2[MAX_LENGTH];
  int len;
  int index;
  while(((len = mygetline(s1, MAX_LENGTH))) > 0 && (mygetline(s2,MAX_LENGTH) > 0)){
    
    index = strrindex(s1,s2, MAX_LENGTH);
    printf("%d\n", index);
  }
  return 0;
}
