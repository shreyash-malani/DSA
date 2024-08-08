#include<stdio.h>
#include<stdlib.h>
typedef struct student 
{
    int rno;
    char nm[15];
    double mrk;
    int state;  
}STU;

typedef struct node 
{
    STU data;
    struct node *next;
}NODE;

typedef struct studentlist
{
    NODE *st;
    int cnt;
}SLIST;

void init(SLIST *t)
{
    t->st=NULL;
    t->cnt=0;
}

NODE *search(SLIST *t,int no)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        if((a->data).rno==no)
            break;
        a=a->next;
    }
    return a;
}
void add(SLIST *t)
{
    NODE *a;
    int no;
    printf("\nRoll No:");
    scanf("%d",&no);
    a=search(t,no);
    if(a!=NULL)
    {
        printf("\n Record Exist");
        return;
    }
    a=(NODE *)malloc(sizeof(NODE));
    a->next=t->st;
    t->st=a;
    t->cnt++;
    a->data.rno=no;
    printf("\nName:");
    scanf("%s",a->data.nm);
    do
    {
        printf("\nMarks:");
        scanf("%lf",&a->data.mrk);
    }
    while(a->data.mrk<0.0 || a->data.mrk>10.0);
    a->data.state=1;
}
void mod(SLIST *t)
{
    NODE *a;
    int no;
    printf("\n Enter no:");
    scanf("%d",&no);
    a=search(t,no);
    if(a==NULL || a->data.state==0)
    {
        printf("\n Record Not Exist:");
        return;
    }
    a->data.rno=no;
    printf("\nName:");
    scanf("%s",a->data.nm);
    do
    {
        printf("\nMarks:");
        scanf("%lf",&a->data.mrk);
    }
    while(a->data.mrk<0.0 || a->data.mrk>10.0);
    a->data.state=1;
}
void del(SLIST *t)
{
    NODE *a;
    int no;
    printf("\n Enter no:");
    scanf("%d",&no);
    a=search(t,no);
    if(a==NULL || a->data.state==0)
    {
        printf("\n Record Not Exist");
        return;
    }
    a->data.state=0;
}
void display(SLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
        return;
    while (a != NULL)
    {
        if (a->data.state == 1)  // Only display active records
        {
            printf("%d %-15s %.2lf %d\n", a->data.rno, a->data.nm, a->data.mrk, a->data.state);  // Added newline for readability
        }
        a = a->next;
    }
}
int main()
{
    SLIST a;
    init(&a);
    add(&a);
    add(&a);
    add(&a);
    display(&a);
    mod(&a);
    display(&a);
    del(&a);
    display(&a);
}