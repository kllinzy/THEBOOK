#include <stdio.h>

#define MAX_LENGTH 100

void strdel(char s[], char t[]){

  int i , j, k;
  i = j = k =  0;

  while(t[i] != '\0'){
    while(s[j] != '\0'){
      s[j] = s[j+k];
      if(s[j] == t[i]){
        ++k;
      }
      else{
        ++j;
      }
    }
    ++i;
    j = k = 0;
  }
}

void faststrdel(char s[], char t[]){

  char letters[256] = {0};
  int i = 0;
  int k = 0;

  while(t[i] != '\0'){
    letters[t[i]]++;
    ++i;
  }
  i = 0;
  while(s[i] != '\0'){
    s[i] = s[i+k];
    if(letters[s[i]] != 0 ){
      k++; 
    }
    else{
      ++i;
    }
  }
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

  int len;
  int len2;
  char line[MAX_LENGTH];
  char line2[MAX_LENGTH];

  while((len = mygetline(line, MAX_LENGTH)) > 0 && (len2 = mygetline(line2, MAX_LENGTH)) > 0) {

    faststrdel(line, line2);
    printf("%s\n", line);
    printf("-----------------------------\n");
  }

  return 0;
}
