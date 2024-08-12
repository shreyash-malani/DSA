#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    struct node *next;
    int data;
    struct node *prev;
}NODE;

typedef struct dlist
{
    NODE *st;
    NODE *ed;
}DLIST;

void init(DLIST *t)
{
    t->st=t->ed=NULL;
}

//function to create node 
NODE * createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->prev=NULL;
    a->next=NULL;
    a->data=d;
    return a;
}

//Add new node at end
void addEnd(DLIST *t,int d)
{
    NODE *a,*b;
    a=createNode(d);
    if(t->st==NULL)
        t->st=a;
    else
    {
        b=t->ed;
        b->next=a;
        a->prev=b;
    }
    t->ed=a;
}

//Add new node at Begin
void addBegin(DLIST *t,int d)
{
    NODE *a=createNode(d),*b;
    if(t->ed==NULL)
        t->ed=a;
    else
    {
        b=t->st;
        a->next=b;
        b->prev=a;
    }
    t->st=a;
}

//Display the data of list from start to end 
void displaySE(DLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
        printf("\nEmpty List");
    else
    {
        printf("\nData:");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
    return;
}

//Display the data from the list from end to start 
void displayES(DLIST *t)
{
    NODE *a=t->ed;
    if(t->ed==NULL)
        printf("\nEmpty List");
    else
    {
        printf("\nData:");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->prev;
        }
    }
    return;
}

// int main()
// {
//     DLIST p;
//     init(&p);
//     addEnd(&p,10);
//     addEnd(&p,20);
//     addEnd(&p,30);
//     addBegin(&p,40);
//     displaySE(&p);
//     displayES(&p);
//     return 0;

// }
//function to delete the first node 
void delFirst(DLIST *t)
{
    NODE *a=t->st,*b;
    if(t->st==NULL)
        return;
    if(t->st==t->ed)
        t->st=t->ed=NULL;
    else
    {
        b=a->next;
        t->st=b;
        b->prev=NULL;
    }
    free(a);
}

void delLast(DLIST *t)
{
    NODE *a=t->ed,*b;
    if(t->ed==NULL)
        return;
    if(t->st==t->ed)
        t->st=t->ed=NULL;
    else
    {
        b=a->prev;
        b->next=NULL;
        t->ed=b;
    }
    free(a);
}

// int main()
// {
//     DLIST p;
//     init(&p);
//     addEnd(&p,10);
//     addEnd(&p,20);
//     addEnd(&p,30);
//     addBegin(&p,40);
//     addBegin(&p,50);
//     displaySE(&p);
//     addEnd(&p,60);
//     displayES(&p);
//     delLast(&p);
//     displaySE(&p);
//     delFirst(&p);
//     delLast(&p);
//     displayES(&p);
// }

//function to delete the ith node
void deliNode(DLIST *t,int pos)
{
    NODE *a=t->st,*b,*c;
    int i=1,count=0;
    if(t->st==NULL)
        return;
    while (a!= NULL)
    {
        count++;
        a=a->next;
    }
    a=t->st;
    if(pos<1 || pos>count)
        printf("Invalid data");
    else
    {
        if(pos==1)
            delFirst(t);
        else
        {
            if(pos==count)
                delLast(t);
            else
            {
                while(i<pos)
                {
                    b=a;
                    a=a->next;
                    i++;
                }
                c=a->next;
                b->next=c;
                c->prev=b;
                free(a);
            }
        }
    }
} 

// int main()
// {
//     DLIST p;
//     init(&p);
//     addEnd(&p,10);
//     addEnd(&p,20);
//     addEnd(&p,30);
//     addBegin(&p,40);
//     addBegin(&p,50);
//     displaySE(&p);
//     deliNode(&p,3);
//     displaySE(&p);
//     // displaySE(&p);
//     // addEnd(&p,60);
//     // displayES(&p);
//     // delLast(&p);
//     // displaySE(&p);
//     // delFirst(&p);
//     // delLast(&p);
//     // displayES(&p);
// }

//function to delete alll node 
void delAll(DLIST *t)
{
    while (t->st!=NULL)
    {
        delFirst(t);
    }
}

// int main()
// {
//     DLIST p;
//     init(&p);
//     addEnd(&p,10);
//     addEnd(&p,20);
//     addEnd(&p,30);
//     addEnd(&p,40);
//     displaySE(&p);

//     delFirst(&p);
//     displaySE(&p);

//     addBegin(&p,100);
//     displaySE(&p);
//     delLast(&p);
//     displaySE(&p);

//     deliNode(&p,3);
//     displaySE(&p);
// }

//function to insert node before ith position 
void insertB (DLIST *t,int pos,int val)
{
    int i=1;
    NODE *a,*b,*c;
    if(t->st==NULL || pos<1)
        return;
    if(pos==1)
        addBegin(t,val);
    else
    {
        a=t->st;
        while(i<pos && a!=NULL)
        {
            b=a;
            a=a->next;
            i++;
        }
        if(a==NULL)
            printf("\nNo NODE");
        else
        {
            c=createNode(val);
            b->next=c;
            c->prev=b;
            c->next=a;
            a->prev=c;
        }
    }
}

//function to insert node after ith position
void insertA(DLIST *t,int pos,int val)
{
    int i=1;
    NODE *a=t->st,*b,*c;
    if(pos<1 || a==NULL)  //a means list is empty 
        return;
    while(i<=pos && a!=NULL)
    {
        b=a;
        a=a->next;
        i++;
    }
    if(a==NULL)
    {
        if(i>pos)
            addEnd(t,val);
        else
            printf("\nNO NODE");
    }
    else
    {
        c=createNode(val);
        b->next=c;
        c->prev=b;
        c->next=a;
        a->prev=c; 
    }
}
// int main()
// {
//     DLIST p;
//     init(&p);
//     addEnd(&p,10);
//     addEnd(&p,20);
//     addEnd(&p,30);
//     insertB(&p,2,40);
//     displaySE(&p);

//     insertA(&p,4,50);
//     displaySE(&p);
// }

int main()
{
    DLIST p;
    int opt ,d,pos;
    init(&p);
    while(1)
    {
        printf("\nMenu: \n1.Add at End \n2.Add at Begin \n3.DisplaySE \n4.DisplayES  \n5.Delete first Node: \n6.Delete Last Node\n7.Delete ith node \n8.Delete All Nodes \n9.Insert Before ith position \n10.Insert After ith position \n11.Exit \nOption: ");
        scanf("%d",&opt);
        if(opt>10)
            break;
        switch(opt)
        {
            case 1:
                printf("\n Data:");
                scanf("%d",&d);
                addEnd(&p,d);
                break;
            case 2:
                printf("\n Data:");
                scanf("%d",&d);
                addBegin(&p,d);
                break;
            case 3:
                displaySE(&p);break;
            case 4:
                displayES(&p);break;
            case 5:
                delFirst(&p);break;
            case 6:
                delLast(&p);break;
            case 7:
                printf("\nNode Position: ");
                scanf("%d",&pos);
                deliNode(&p,pos);break;
            case 8:
                delAll(&p);break;
            
            case 9:
                printf("\nNode Position:");
                scanf("%d",&pos);
                printf("\n Data:");
                scanf("%d",&d);
                insertB(&p,pos,d);
                break;
            case 10:
                printf("\nNode Position:");
                scanf("%d",&pos);
                printf("\n Data:");
                scanf("%d",&d);
                insertA(&p,pos,d);
                break;
        }
    }
    return 0;
}