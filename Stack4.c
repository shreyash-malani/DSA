//LinkedList implementation on stack 

#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node * next;
}NODE;

typedef struct stack
{
    NODE * top;
}STK;

void init(STK *t)
{
    t->top = NULL;
}

NODE * createNode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

void push(STK *t,int d)
{
    NODE *a=createNode(d);
    a->next=t->top;
    t->top=a;
}

void pop(STK *t)
{
    NODE *a=t->top;
    if(t->top==NULL)
        printf("\nUnderFlow");
    else
    {
        t->top=a->next;
        free(a);
    }
}

void display(STK *t)
{
    NODE *a=t->top;
    if(t->top==NULL)
        printf("\nStack Empty");
    else
    {
        printf("\nStack Data:");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}

int main()
{
    STK p;
    init(&p);
    push(&p,10);
    push(&p,20);
    push(&p,30);
    push(&p,40);
    display(&p);
    pop(&p);
    display(&p);
    return 0;
}