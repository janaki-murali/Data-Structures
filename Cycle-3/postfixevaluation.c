/*To evaluate a postfix expression using stack*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define size 2500
#define invalid -9999

int s[size],top=-1;

void push(int opd)
{
    if(top==size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        s[top]=opd;
    }
}
int pop()
{
    int opd;
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return invalid; 
    }
    else
    {
        opd=s[top];
        top--;
        return opd;
    }
}
int evalpostfix(char postfix[])
{
    int i=0;
    int a,b;
    while(postfix[i]!='\0')
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+': push(b+a);
                          break;
                case '-': push(b-a);
                          break;
                case '*': push(b*a);
                          break;
                case '/': push(b/a);
                          break;
                case '^': push(pow(b,a));
                          break;
            }
        }
        i++;
    }
    return pop();   
}
void main()
{
    char postfix[size]; 
    int r;
    printf("Enter the postfix epression : ");
    scanf("%[^\n]",postfix);
    r=evalpostfix(postfix);
    printf("Result : %d",r);
}
