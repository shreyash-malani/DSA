#include<stdio.h>
#include<stdlib.h>
# define N 10
void input(int *a)
{
    int i=0;
    printf("\n Array Data:");
    while(i<N)
    {
        scanf("%d",(a+i));
        i++;
    }
}
void display(int *a,int flg)
{
    int i=0;
    if(flg==0)
    {
        printf("\n Before Sorting");
    }
    else
    {
        printf("\n After Sorting");
    }
    while(i<N)
    {
        printf("%4d",a[i]);
        i++;
    }
}
void swap(int *p,int *q)
{
    int r=*p;
    *p=*q;
    *q=r;
}
void pivot(int *a,int l,int r)
{
    if(a[l]>a[r])
        swap(a+l,a+r);
}
int partition(int *a,int l,int r)
{
    int i=l;int j=r,val;
    pivot(a,l,r);
    val=a[l]; //pivot value
    do
    {
        do ++i;while(a[i]<val);
        do --j;while(a[j]>val);
        if(i<j)
            swap(a+i,a+j);
    }while(i<j);
    swap(a+l,a+j);
    return j;
}
void quick(int *a,int l,int r)
{
    int k;
    if(l<r)
    {
        k=partition(a,l,r);
        quick(a,l,k-1);
        quick(a,k+1,r);
    }
}
int main()
{
    int x[N];
    input(x);
    display(x,0);
    quick(x,0,N-1);
    display(x,1);
}