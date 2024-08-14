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
void pop(STK *t)
{
    if(isEmpty(t))
        printf("\n UnderFlow....");
    else
    {
        t->top--;
    }
}
void display(STK *t)
{
    int i=t->top;
    if(isEmpty(t))
        printf("\nEmpty Stack..");
    else
    {
        printf("\nStack Data:\n");
        while(i>=0)
        {
            printf(" %c",t->arr[i]);  //Here we reading the stack 
            i--;
        }
    }
}
int main()
{
    STK p;
    char d;int opt;
    init(&p);
    while(1)
    {
        printf("\n Stack Menu \n1.Push \n2.Pop \n3.Display \n4.Exit \nOption: ");
        scanf("%d",&opt);
        if(opt>3)
            break;
        switch(opt)
        {
            case 1:
                printf("\nData: ");
                scanf(" %c",&d);
                push(&p,d);break;
            case 2:
                pop(&p);break;
            case 3:
                display(&p);break;
        }
    }
}


