#include<stdio.h>
#include<stdlib.h>
#include"si_list.h"
#include<errno.h>
struct slnode* head=NULL;
void main()
{
    int choice,data,pos,mid;
    struct slnode* temp_address;
    while (1)
    {
        printf("\n 1.Create \n 2.Add node \n 3.Mid point of List \n 4.display \n 5.Exit\n");
        printf("Enter option :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("\n Enter the data want to add into link list :");
                scanf("%d",&data);
                head=sin_create(data);
                if (head!=0)
                {
                    printf("\n Node is allocated");
                }
                break;
        case 2: printf("\n Enter the data you want to add :");
                scanf("%d",&data);
                sin_add(&head,sin_create(data));
                printf("Node Added\n");
                break;
        case 3: mid=sin_mid(head);
                printf("The mid point of list is %d \n ",mid);
        case 4: sin_display(head);
                break;
        case 5 : exit(0);
        
        default:printf("Please choose the correct choice :");    
                break;
        }
    }
    
}