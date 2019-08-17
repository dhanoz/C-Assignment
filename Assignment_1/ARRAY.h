typedef struct 
{
  int* base;
  int dim;
} ARRAY;

int create(ARRAY* aptr ,int size);
int store(ARRAY* aptr,int val ,int pos);
int readr(ARRAY* aptr,int pos);
