#include<stdio.h>
#include<errno.h>
#include"ARRAY.h"
int main(){
    int ch,size,valid,val,pos,i;
    i=1;
    ch =0;
    ARRAY num;
    while(i)
    {
        printf("1.create Array \n2.Insert \n3.Read \n4.Exit  \n:-> ");
        scanf("%d",&ch);
        printf("%d",ch);
        switch (ch)
        {
            case 1: 
                printf("\nEnter the Dimension of array : ");
                scanf("%d",&size);
                valid=create(&num,size);
                if(valid==errno)
                {
                    printf("\nArray not created\n");
                }
                break;
            case 2: 
                printf("\nEnter the value and Postion in array\n ");
                scanf("%d %d",&val,&pos);
                valid=store(&num,val,pos);
                if(valid==errno)
                {
                    printf("\nFailed to Insert");
                }
                break;
            case 3:
                printf("\nEnter the posistion in array : \n");
                int val;
                scanf("%d",&val);
                printf("value is:-> %d",readr(&num,val));
                break;
            default:
                printf("Exit\n");
                i=0;
                break;
        }
        printf("\n");
    }
}