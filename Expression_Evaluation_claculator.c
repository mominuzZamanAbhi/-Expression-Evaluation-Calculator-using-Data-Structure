#define SIZE 50            /* Size of Stack */
#include <ctype.h>
#include<stdio.h>
#define MAX 25

int stack[MAX],TOS=-1;
int s[SIZE];
int top=-1;       /* Global declarations */

push(int elem)
{                       /* Function for PUSH operation */
 s[++top]=elem;
}

int pop()
{                      /* Function for POP operation */
 return(s[top--]);
}

int precedence(char symbol)
{
int result;
switch(symbol)
{
case '(':
         result=0;
         break;
case '+':
case '-':result=1;break;
case '*':
case '/':result=2;break;
case '^':result=3;break;
}
return(result);
}
int isoperand(char symbol)
{
return((symbol >= 'a' && symbol <= 'z') ||
(symbol >= 'A' && symbol <= 'Z') ||
(symbol >= '0' && symbol <='9'));
}
int isoperator(char symbol)
{
int result=0;
switch(symbol)
{
case '+':
case '-':
case '*':
case '/':
case '^':result=1;break;
}
return(result);
}

main()
{
char infix[MAX],postfix[MAX];
int inputpointer,outputpointer;
inputpointer = outputpointer = -1;
stack[++TOS]='(';
printf("\nEnter the infix expression : ");
scanf("%s",infix);
while(infix[++inputpointer]!='\0')
{
if(isoperand(infix[inputpointer]))
postfix[++outputpointer]=infix[inputpointer];
else if(isoperator(infix[inputpointer]))
{
while(precedence(infix[inputpointer])<=precedence(stack[TOS]))
postfix[++outputpointer]=stack[TOS--];
stack[++TOS]=infix[inputpointer];
}
else if(infix[inputpointer]=='(')
stack[++TOS]='(';
else if(infix[inputpointer]==')')
{
while(stack[TOS]!='(')
postfix[++outputpointer]=stack[TOS--];
TOS--;
}
else
{
printf("invalid symbol");
exit(1);
}
}
while(stack[TOS]!='(')
postfix[++outputpointer]=stack[TOS--];
postfix[++outputpointer]='\0';
printf("\nThe postfix expression is %s",postfix);


// char pofx[50],
 char ch;
 int i=0,op1,op2;
  while( (ch=postfix[i++]) != '\0')
 {
  if(isdigit(ch)) push(ch-'0'); /* Push the operand */
  else
  {        /* Operator,pop two  operands */
   op2=pop();
   op1=pop();
   switch(ch)
   {
   case '+':push(op1+op2);break;
   case '-':push(op1-op2);break;
   case '*':push(op1*op2);break;
   case '/':push(op1/op2);break;
   }
  }
 }
 printf("\n\n Result after Evaluation: %d\n",s[top]);
}
