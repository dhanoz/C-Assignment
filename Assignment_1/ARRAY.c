#include"ARRAY.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int create(ARRAY* aptr ,int size)
{
int* temp;
aptr->dim=size;
temp=(int*)malloc(sizeof(int) * size);
aptr->base =temp;
if(temp != NULL)
    {
        printf("Array Created");
    }
    else
    {
        return errno=EINVAL;
    }
}

int store(ARRAY* aptr,int val,int pos)
 {
   int*a=aptr->base;
   if(pos > aptr->dim)
   {
       printf("Out of Bounds");
       return errno=EINVAL;
   }
   *(a+pos)=val;
   if((a+pos)==NULL)
   {
       return errno=EINVAL;
   }
   else
   {
       return 1;
   }

}
int readr(ARRAY* aptr,int pos)
    {
        return *(aptr->base+pos);  
    }