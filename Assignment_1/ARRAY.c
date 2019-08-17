#include"ARRAY.h"
#include<stdio.h>
#include<stdlib.h>
int create(ARRAY* aptr ,int size){
int* temp;
aptr->dim=size;
temp=(int*)malloc(sizeof(int) * size);
aptr->base =temp;
if(temp != NULL){
return 1;
}
else{
return 0;
}
}

int store(ARRAY* aptr,int val,int pos)
 {
   int*a=aptr->base;
   if(*(a+pos)>aptr->dim)
   {
       printf("Out of Bounds");
       return 0;
   }
   *(a+pos)=val;
   if((a+pos)==NULL)
   {
       return 0;
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