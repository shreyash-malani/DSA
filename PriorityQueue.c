#include<stdio.h>
#include<stdlib.h>
# define N 5 
typedef struct priorityqueue
{
    int arr[N];
    int fr,rr;
}PQ;

void init(PQ *t)
{
    t->rr=-1;
    t->fr=0;
}

void insert(PQ *t,int d)
{
    int i;
    if(t->rr==N-1)
    {
        printf("---------------OverFlow-----------");
        return;
    }
    i=t->rr;
    while(i>=0 && t->arr[i]>d)
    {
        t->arr[i+1]=t->arr[i];
        i--;
    }
    t->arr[i+1]=d;
    t->rr++;
}
void remque(PQ *t)
{
    int i;
    if(t->rr < t->fr)
    {
        printf("-----------UnderFlow----------");
        return;
    }
    i=0;
    while(i<t->rr)
    {
        t->arr[i]=t->arr[i+1];
        i++;
    }
    t->rr--;
}
void display(PQ *t)
{
    int i;
    if(t->rr < t->fr)
    {
        printf("--------------------Empty Queue----------------");
    }
    i=0;
    while(i<=t->rr)
    {
        printf("%4d",t->arr[i]);
        i++;
    }
}

int main()
{
    int opt,d;
    PQ p;
    init(&p);
    while(1)
    {
        printf("\nPriority Queue \nMenu \n1.Insert \n2.Remove \n3.Display \n4.Exit \noption: ");
        scanf("%d",&opt);
        if(opt>3)
            break;
        switch(opt)
        {
            case 3:
                display(&p);break;
            case 2:
                remque(&p);break;
            case 1:
                printf("\nData\n");
                scanf("%d",&d);
                insert(&p,d);
                break;
        }    
    }
}