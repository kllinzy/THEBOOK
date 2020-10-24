#include <stdio.h>

#define MAX_LENGTH 300

void expand(char s1[], char s2[]){
  int i,index;

  i = index = 0;

  while(s1[i] != '\0' && i < MAX_LENGTH && index < MAX_LENGTH){
    //if the next character is not a dash
    //or the dash is the last character
    //or the current character is greater than the end of the range
    //then plain copy char to new string
    if(s1[i+1] != '-' ||
       (s1[i+1] == '-' &&
	(s1[i+2] == '\0' || s1[i] > s1[i+2] ))){
      s2[index] = s1[i];
      ++i;
      ++index;
    }
    //otherwise, expand
    else{
      for(int j = s1[i]; j < s1[i+2]; ++j, ++index)
	s2[index] = j;
      //we don't write the last character, we let the next loop handle it (because it might need to expand again i.e. a-d-g)
      i = i+2;
    }
      }
  s2[index] = '\0';

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
  while((len = mygetline(s1, MAX_LENGTH)) > 0){
    expand(s1,s2);
    printf("%s\n", s2);
  }
  return 0;
}
