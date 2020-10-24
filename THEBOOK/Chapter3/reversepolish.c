#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 80
#define MAX_OP 100
#define NUMBER '0'
#define MAXVAL 100 //maximum stack size
#define BUFSIZE 100

//function definitions
char mygetc(void);
void myungetc(char);
int getch(void);
void ungetch(int);
void ungets(char[]);
double myatof(char[]);
int getop(char[]);
void push(double);
double pop(void);
double copytop(void);
void swaptoptwo(void);

//external variables
int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
char pushback = '\0';

int main(){
  int type;
  double op2;
  char s[MAX_OP];

  while((type = getop(s)) != EOF){
    switch(type){
    case NUMBER:
      push(myatof(s));
      break;    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if(op2 != 0.0){
	push(pop() / op2);
      }
      else{
	printf("error: zero division\n");
      }
      break;
    case '%':
      op2 = pop();
      if(op2 != 0.0){
	double division = pop()/op2;
	int casted = (int) division;
	push((division - casted)*op2);
      }
      else{
	printf("error: zero division (mod)\n");
      }
      break;
    case '^':
      op2 = pop();
      push(pow(pop(),op2));
      break;
    //cheating to use @ as pow
    case '@':
      push(sin(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case '\n':
      printf("\t%8g\n",pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
char mygetc(void){
  int result = pushback == '\0' ? getchar() : pushback;
  pushback = '\0';
  return result; 
}
void myungetc(char c){
  if(pushback == '\0')
    pushback = c;
  else
    printf("error: there is already a character pushed back\n");
}

int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
  if(bufp >= BUFSIZE){
    printf("ungetch: too many characters\n");
  }
  else{
    buf[bufp++] = c;
  }
}
int getop(char s[]){
  int c, i;

  while((s[0] = c = mygetc()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.'){
    return c;
  }
  i = 0;
  if(isdigit(c)){
    while(isdigit(s[++i] = c = mygetc()))
      ;
    if(c=='.'){
      while(isdigit(s[++i] = c = mygetc()))
	;
    }
    s[i] = '\0';
    if(c != EOF)
      myungetc(c);
    return NUMBER;
  }
}

double myatof(char s[]){
  double val, power, sci, scipower;
  int i, j, k, sign, scisign;

  for(i = 0; isspace(s[i]);++i)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-'){
    ++i;
  }
  for(val = 0.0; isdigit(s[i]); ++i){
    val = 10.0*val+(s[i] - '0');
  }
  if(s[i] == '.'){
    ++i;
  }
  for(power = 1.0; isdigit(s[i]);++i){
    val = 10.0*val+(s[i] - '0');
    power *= 10.0;
  } 
  if(s[i] == 'e' || s[i] == 'E'){
    ++i;
  }
  scisign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-'){
    ++i;
  }
  for(sci = 1.0, scipower = 1.0; isdigit(s[i]); ++i){
    int temp = s[i] - '0';
    //we can do something special in here
    if(sci> 1.0){
      for(k = 0; k < 10; ++k)
      sci*=scipower;
    }
    for(j = 0; j < temp; ++j)
      sci *= 10;
    scipower *=10;
  }

  return scisign < 0 ? (sign * val / power) / sci : (sign * val / power) * sci;
  
}

void push(double f){

  if(sp < MAXVAL){
    val[sp++] = f;
  }
  else{
    printf("error: stack is full\n");
  }
  
}

double pop(){
  if(sp > 0){
    return val[--sp];
  }
  else{
    printf("error: attempt to pop on empty stack\n");
    return 0.0;
  }
}

double copytop(){
  if(sp > 0){
    printf("top:\t%f\n",val[sp - 1]);
    return val[sp-1];
  } 
  else{
    printf("stack empty\n");
    return 0.0;
  }
}

void swaptoptwo(){
  if(sp > 1){
    double temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
  }
}

void ungets(char s[]){
  int i = 0;
  char c;
  while((c = s[i++]) != '\0'){
    ungetch(c);
  }
}
