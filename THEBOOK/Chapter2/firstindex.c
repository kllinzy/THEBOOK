#include <stdio.h>

#define MAX_LENGTH 100

int firstindex(char s[], char t[]){

  int x = -1;
  int i, j;

  i = j = 0;

  while(t[i] != '\0'){
    while(s[j] != '\0'){
      if(s[j] == t[i]){
        if(x == -1 || x > j){
          x = j;
        }
      }
      ++j;
    }
    j = 0;
    ++i;
  }
  return x;
}

int fastfirstindex(char s[], char t[]){
  char letters[256] = {0};
  int i = 0;
  while(t[i] != '\0'){
    letters[t[i]]++;
    ++i;
  }
  i = 0;
  while(s[i] != '\0'){
    if(letters[s[i]] != 0){
      return i;
    }
    ++i;
  }
  return -1;
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
  int index , index2 = -1;
  char line[MAX_LENGTH];
  char line2[MAX_LENGTH];
  while((len = mygetline(line, MAX_LENGTH)) > 0 && (len2 = mygetline(line2, MAX_LENGTH)) > 0) {

    index = firstindex(line, line2);
    index2 = fastfirstindex(line, line2);
    printf("slow: %d\tfast: %d\n", index, index2);
    printf("-----------------------------\n");
  }

  return 0;
}
