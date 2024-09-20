//in these approach we are entering one by one element in prevous we we were entering simultaneouslt 
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x[5],i,j,val;
    for(int i=0;i<5;i++)
    {
        printf("\nEnter No:");
        scanf("%d",&x[i]);      
        val=x[i];
        j=i-1;
        while(j>=0 && x[j]>val)
        {
            x[j+1]=x[j];
            j=j-1;
        }
        x[j+1]=val;
    }
    printf("\nAfter Sorting:");
    for(i=0;i<5;i++)
    {
        printf("%4d ",x[i]);
    }
    return;
}
