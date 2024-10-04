#include<stdio.h>
#include<stdlib.h>
#define N 10
void input(int *a)
{
    int i=0;
    while(i<N)
    {
        printf("\nData:");
        scanf("%d",(a+i));
        i++;
    }
}
void display(int *a,int flg)
{
    int i=0;
    if(flg==0)
    {
        printf("\nBefore Sorting: ");
    }   
    else
    {
        printf("\nAfter Sorting: ");
    }
    while(i<N)
    {
        printf("%4d",*(a+i));
        i++;
    }
}
void merge(int *a)
{
    int size=1,i,j,k;
    int l1,u1,l2,u2,tmp[N];
    while(size<N)
    {
        l1=0;k=0;
        while(l1+size<N)
        {
            l2=l1+size;
            u1=l2-1;
            if(l2+size<N)
                u2=l2+size-1;
            else
                u2=N-1;
            for(i=l1,j=l2;i<=u1 && j<=u2;k++)
            {
                if(a[i]<a[j])
                    tmp[k]=a[i++];
                else
                    tmp[k]=a[j++];
            }
            for(;i<=u1;i++)
                tmp[k++]=a[i];
            for(;j<=u2;j++)
                tmp[k++]=a[j];
            l1=u2+1;
        }
        for(i=l1;i<N;i++)
            tmp[k++]=a[i];
        for(i=0;i<N;i++)
            a[i]=tmp[i];
        size=size*2;
    }
}
int main()
{
    int x[N];
    input(x);
    display(x,0);
    merge(x);
    display(x,1);
}