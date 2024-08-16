#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct stack
{
    char top;
    char arr[N];
}STK;

void init(STK *t)
{
    t->top=-1;
}

int isEmpty(STK *t)
{
    return (t->top==-1);
}

int isFull(STK *t)
{
    return (t->top==N-1);
}

void push(STK *t,char d)
{
    if(isFull(t))
        printf("\nOverFlow....");
    else
    {
        t->top++;
        t->arr[t->top]=d;
    }
}
char pop(STK *t)
{
    return t->arr[t->top--];
}
int main()
{
    int i=0;
    char s[50],d[50];
    STK p;
    init(&p);
    printf("\nString:");
    gets(s);
    while(s[i]!='\0')
    {
        push(&p,s[i]);
        i++;
    }
    i=0;
    while(!isEmpty(&p))
    {
        d[i]=pop(&p);
        i++;
    }
    d[i]='\0';
    puts(d);
    return 0;
    
}