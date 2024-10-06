#include<stdlib.h>
#include<stdio.h>
int main()
{
    int x[5],i,j,flg,tmp;
    for(i=0;i<5;i++)
    {
        printf("\nData:");
        scanf("%d",&x[i]);

    }
    printf("Before Sorting:");
    for(i=0;i<5;i++)
        printf("%4d",x[i]);
    for(i=0;i<4;i++)
    {
        flg=0;
        for(j=0;j<4-i;j++)
        {
            if(x[j]>x[j+1])
            {
                flg=1;
                tmp=x[j];
                x[j]=x[j+1];
                x[j+1]=tmp;
            }
        }
        if(flg==0)
            break;
    }
    printf("\nAfter Sorting:");
    for(i=0;i<5;i++)
        printf("%4d",x[i]);
    return 02;

}