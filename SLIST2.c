#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void main()
{
    int opt,rev,sv,rep,pos,d,*q,i,n;
    SLIST p;
    init(&p);
    while(1)
    {
        printf("\nSingle Linked List");
        printf("\n Menu: \n1.Add at End \n2.Add at Begin \n3.Display \n4.Sum of Node \n5.Min Value \n6.Max Value \n7.Odd Count \n8.Even Count \n9.Odd display \n10.Even display \n11.Search the value \n12.Find the value and Replace \n13.Delete First Node \n14.Delete Last Node \n15.Delete ith Node \n16.Delete All Node \n17.Reverse the Node \n18.Display the reversed String \n19.Convert List to Array \n20.Convert Array to list \n21.Sort the List \n22.Check List in Ascending Order \n23.List data to File \n24.Built List to File \nOption: ");
        scanf("%d",&opt);
        if(opt>24)
            break;
        switch(opt)
        {
            case 1:
                printf("Data at End:");
                scanf("%d",&d);
                addEnd(&p,d);
                break;
            
            case 2:
                printf("Data at Begin:");
                scanf("%d",&d);
                addBeg(&p,d);break;

            case 3:
                display(&p);break;
            
            case 4:
                printf("\nSum :%d",sum(&p));break;
            
            case 5:
                printf("Min Value:%d",minValue(&p));break;
            
            case 6: 
                printf("Max Value:%d",maxValue(&p));break;

            case 7:
                printf("Odd Data Nodes:%d",oddCount(&p));break;

            case 8:
                printf("Even Data Nodes:%d",evenCount(&p));break;

            case 9:
                odisplay(&p);break;
            
            case 10:
                edisplay(&p);break;

            case 11:
                printf("Enter the Search Value:");
                scanf("%d",&sv);
                if(search(&p,sv)==0)
                    printf("\n Not Found");
                else    
                    printf("\n Found");break;  

            case 12:
                printf("Enter the Search Value:");
                scanf("%d",&sv);
                printf("\n Replace the Value:");
                scanf("%d",&rep);
                findRep(&p,sv,rep);break;          

            case 13:
                delFirst(&p);break;
            
            case 14:
                delLast(&p);break;
            
            case 15:
                printf("Enter the Position :");
                scanf("%d",&pos);
                deliNode(&p,pos);break;
            
            case 16:
                delAll(&p);break;
            
            case 17:
                reverse(&p);break;

            case 18:
                printf("\nData");
                rdisplay(p.st); //100
                break;
            
            case 19:
                q=toArray(&p);
                n=p.cnt;
                for(i=0;i<n;i++)
                    printf("%4d",q[i]);
                free(q);
                break;
            
            case 20:
                printf("Enter the data count");
                scanf("%d",&n);
                q=(int *)malloc(n*sizeof(int));
                printf("\n Data:");
                for(i=0;i<n;i++)
                    scanf("%d",q+i);
                toList(&p,q,n);
                break;
            
            case 21:
                sort(&p);
                break;
            
            case 22:
                if(isOrdered(&p)==0)
                    printf("Not Ordered");
                else
                    printf("Ordered List");
                break;
            
            case 23:
                toFile(&p);
                break;

            case 24:
                fromFile(&p);
                break;
        }
    }
}