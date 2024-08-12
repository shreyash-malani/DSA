#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}NODE;

typedef struct mlist
{
    NODE *st;
}MLIST;

void init(MLIST *t)
{
    t->st=NULL;
}

NODE *createNode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

void delAll(MLIST *t)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        t->st=a->next;
        free(a);
        a=a->next;
    }
}

void display(MLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
        printf("\nEmpty List");
    else
    {
        printf("\nData: ");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}

void createList(MLIST *t)
{
    NODE *a=t->st,*b;
    int d;
    delAll(t);
    while(1)
    {
        printf("\nData: ");
        scanf("%d",&d);
        if(d==0)
            break;
        a=createNode(d);
        if(t->st==NULL)
            t->st=a;
        else
            b->next=a;
        b=a;
    }
}

void sort(MLIST *t)
{
    NODE *a=t->st,*b,*c;
    int tmp;
    if(t->st==NULL)
        return;
    while(a!=NULL)
    {
        b=a;
        c=b->next;
        while(c!=NULL)
        {
            if(c->data < b->data)
                b=c;
            c=c->next;
        }
        if(b!=a)
        {
            tmp=b->data;
            b->data=a->data;
            a->data=tmp;
        }
        a=a->next;
    }
}

//These main is for above functions 

// int main()
// {
//     MLIST p;
//     init (&p);
//     createList(&p);
//     display(&p);
//     sort(&p);
//     display(&p);
//     return 0;
// }

void copyList(MLIST *d,MLIST *s) //Copy Source lsit to destination part 
{
    NODE *a=s->st,*b,*c; //Source 
    if(s->st==NULL) //Source is absent 
        return;
    delAll(d); //delete all nodes from destination list 
    while(a!=NULL)
    {
        b=createNode(a->data);
        if(d->st==NULL)
            d->st=b;
        else
            c->next=b;
        c=b;
        a=a->next;

    }
}
//These main is for copy the list from source to destination

// int main()
// {
//     MLIST p,q;
//     init(&p);
//     init(&q);
//     createList(&p);
//     display(&p);
//     copyList(&q,&p);
//     display(&q);
//     delAll(&p);
//     delAll(&q);
// }



// void appendList(MLIST *d,MLIST *s)
// {
//     NODE *a=s->st,*b,*c;
//     if(s->st==NULL || d->st==NULL)
//         return;
//     c=d->st;
//     while(c->next!=NULL)
//          c=c->next;
//     while(a!=NULL)
//     {
//         b=createNode(a->data);
//         c->next=b;
//         c=b;
//         a=a->next;
//     }
// }

// // These main is for appendlist
// int main() {
//     MLIST p, q,r;
//     init(&p);
//     init(&q);
//     init(&r);
//     createList(&p);
//     display(&p);
//     createList(&q);
//     display(&q);
//     copyList(&r,&p);
//     appendList(&r,&q);
//     display(&r);
//     delAll(&p);
//     delAll(&q);
//     delAll(&r);
//     return 0;
// }

//Function to Append the List
void appendList(MLIST *d,MLIST *s)
{
    NODE *a=s->st,*b=d->st,*c;
    if(b!=NULL)
    {
        while(b->next!=NULL)
            b=b->next;
    }
    while(a!=NULL)
    {
        c=createNode(a->data);
        if(d->st==NULL) //destination is empty 
            d->st=c;
        else
            b->next=c;
        b=c;
        a=a->next;
    }   
}
// int main()
// {
//     MLIST p,q,r;
//     init(&p);
//     init(&q);
//     init(&r);
//     createList(&p);
//     createList(&q);
//     appendList(&r,&p);
//     appendList(&r,&q);
//     display(&p);
//     display(&q);
//     display(&r);
// }
//Function to merge the list 
MLIST merge(MLIST *p,MLIST*q)
{
    MLIST r;
    NODE *a=p->st,*b=q->st,*c,*d;
    int data;
    init(&r);
    sort(p);
    sort(q);
    while(a && b)   // a and b not equal to null
    {
        if (a->data < b->data)
        {
            data=a->data;
            a=a->next;

        }
        else
        {
            data=b->data;
            b=b->next;        
        }
        c=createNode(data);
        if(r.st==NULL) 
            r.st=c;
        else 
            d->next=c;
        d=c;           
    }
    while(a!=NULL)
    {
        c=createNode(a->data);
        d->next=c;
        d=c;
        a=a->next;
    }
    while(b!=NULL)
    {
        c=createNode(b->data);
        d->next=c;
        d=c;
        b=b->next;
    }
    return r;
}

//these main is for merge sort 
int main()
{
    MLIST p,q,r;
    init(&p);
    init(&q);
    init(&r);
    printf("\n Create List p:\n");
    createList(&p);
    printf("\n Create List q:\n");
    createList(&q);
    r=merge(&p,&q);
    display(&p);
    display(&q);
    display(&r);

}

//Function to perform Intersection list 
MLIST intersection(MLIST *p,MLIST *q)
{
    NODE *a=p->st,*b=q->st,*c,*d;
    int data;
    MLIST r;
    sort(p);
    sort(q);
    init(&r);
    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
            a=a->next;
        else
        {
            if(b->data < a->data)
                b=b->next;
            else
            {
                data=a->data;
                if(r.st==NULL)
                    r.st=c=d=createNode(data);
                else
                {
                    if(d->data!=data)
                    {
                        c=createNode(data);
                        d->next=c;
                        d=c;
                    }     
                }
                a=a->next;
                b=b->next;
            }
        }
    }
    return r;
}
//THESE MAIN IS FOR iNTERSECTION FUNCTION 
// int main()
// {
//     MLIST p,q,r;
//     init(&p);
//     init(&q);
//     init(&r);
//     createList(&p);
//     createList(&q);
//     display(&p);
//     display(&q);
//     r=intersection(&p,&q);
//     display(&r);
// }

//FUNCTION TO UNION THE LIST
MLIST unionList(MLIST *p,MLIST *q)
{
    int val;
    NODE *a=p->st,*b=q->st,*c,*d;
    MLIST r;
    init(&r);
    sort(p);
    sort(q);
    while(a && b)
    {
        if(a->data < b->data)
        {
            val=a->data;
            a=a->next;
        }
        else
        {
            if(b->data < a->data)
            {
                val=b->data;
                b=b->next;
            }   
            else
            {
                val=a->data;
                a=a->next;
                b=b->next;
            }
        }
        // printf("\n%d",val);
        if(r.st==NULL)
            r.st=c=d=createNode(val);
        else
        {
            if(d->data==val)
                continue;
            c=createNode(val);
            d->next=c;
            d=c;
        }
    }
    // display(&r);
    while(b!=NULL)
    {
        val=b->data;
        if(d->data!=val)
        {
            c=createNode(val);
            d->next=c;
            d=c;
        }
        b=b->next;
    }
    while(a!=NULL)
    {
        val=a->data;
        if(d->data!=val)
        {
            c=createNode(val);
            d->next=c;
            d=c;
        }
        a=a->next;
    }
    return r;
}
//These main is for union function 
// int main()
// {
//     MLIST p,q,r;
//     init(&p);
//     init(&q);
//     init(&r);
//     createList(&p);
//     createList(&q);
//     display(&p);
//     display(&q);
//     r=unionList(&p,&q);
//     display(&r);
// }
