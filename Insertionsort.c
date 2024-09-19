#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x[5],i,j,val;
    printf("\nArray Data:");
    for(i=0;i<5;i++)
        scanf("%d",&x[i]);
    printf("\nBefore Sorting:");
    for(i=0;i<5;i++)
        printf("%4d",x[i]);
    for(i=1;i<5;i++)
    {
        val=x[i];
        j=i-1;
        while(j>=0 && x[j]>val)
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=val;
    }
    printf("\nAfter Sorting:");
    for(i=0;i<5;i++)
        printf("%4d",x[i]);
}