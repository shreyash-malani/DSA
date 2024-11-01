#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    struct node *left;
    char ch;
    struct node *right;
}NODE;

NODE *rt=NULL; //root Node 
NODE *ptr[50];  //array of pointers to nodes
char data[50];
void init()
{
    int i=0;
    while(i<50)
    {
        ptr[i]=NULL;
        i++;
    }
    rt=NULL;
}

NODE *createNode(char ch)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->ch=ch;
    a->left=a->right=NULL;
    return a;
}

void createTree()
{
    int i=1,cnt=1,lvl,dep;
    NODE *a;
    printf("Enter Height of Binary Tree");
    scanf("%d",&dep);
    while(i<=dep)
    {
        cnt*=2;
        i++;
    }
    i=1;
    while(i<cnt)
    {
        printf("\n Character for %d NODE",i);
        scanf(" %c",&data[i]);
        if(data[i]=='#')
            ptr[i]=NULL;
        else
        {
            a=createNode(data[i]);
            if(i==1)
                rt=a;
            ptr[i]=a;
        }
        i++;
    }
    lvl=(cnt/2)-1;
    i=1;
    while(i<=lvl)
    {
        if(ptr[i]!=NULL)
        {
            ptr[i]->left=ptr[2*i];
            ptr[i]->right=ptr[(2*i)+1];

        }
        i++;
    }
}

//preorder(rt-lft-right)
void preorder(NODE *a)
{
    if(a!=NULL)
    {
        printf(" %c",a->ch);
        preorder(a->left);
        preorder(a->right);
    }
    else
    {
        return;
    }
}

//inorder(lft-rt-right)
void inorder(NODE *a)
{
    if(a!=NULL)
    {
        inorder(a->left);
        printf(" %c",a->ch);
        inorder(a->right);
    }
    else
    {
        return;
    }
}

//postorder(lft-right-root)
void  postorder(NODE *a)
{
    if(a!=NULL)
    {  
        postorder(a->left);
        postorder(a->right);
        printf(" %c",a->ch);
    }
    else
    {
        return;
    }
}

int main()
{
    createTree();
    printf("\nPreorder");
    preorder(rt);
    printf("\nInorder\n");
    inorder(rt);
    printf("\nPostorder");
    postorder(rt);
    return 0;
}
