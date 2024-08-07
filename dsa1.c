#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}NODE;

NODE *st=NULL;  //Head pointer 

NODE * createNode(int d) //created a node
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

NODE * getlastNode() //Function to get last node 
{
    NODE * a=st;
    while(a->next!=NULL)
        a=a->next; //Traverse the list upto last node is found
    return a;
}

void addEnd(int d)
{
    NODE *a,*b;
    a=createNode(d);
    if(st==NULL)  //his means st itself is a pointer, and initially, it points to NULL.
        st=a;
    else
    {
        b=getlastNode();
        b->next=a;
        a->next=NULL; //
    }
    return;
}

void addBeg(int d)
{
    NODE *a;
    a=createNode(d);
    a->next=st;
    st=a;
}

void display()
{
    NODE *a=st;
    if(st==NULL)
        printf("\nEmpty List");
    else
    {
        printf("\nData");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
            
    }
}

int count()
{
    int cnt=0;
    NODE *a =st;
    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;
}
int main()
{
    int opt,d;
    while(1)
    {
        printf("\n Menu \n1.Add at End \n2.Add at Begin \n3.Display \n4.Count \n5.Exit \nOption: ");
        scanf("%d",&opt);
        if(opt>=5)
            break;
        switch(opt)
        {
            case 1:
                printf("\nData: ");
                scanf("%d",&d);
                addEnd(d);
                break;
            case 2:
                printf("\nData: ");
                scanf("%d",&d);
                addBeg(d);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Node Count: ");
                printf("%d",count());
        }
    }
    return 0;
}

