/*
 * si_list.c - Ane api to provide basic functions to create, read, write and process a list of integers.
 * 
 * author - Dhananjay Purohit, dhp1942012@gmail.com
 * version - 1.0, October 5, 2019 
 */

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "si_list.h"
/* sin_create(): Creates a new list node, if successuful returns the address of the new node. 
 * On error returns NULL and sets the errorno to ENOMEM.
 */
SINODE* sin_create(int data)
{
  struct slnode* temp;
  temp=(struct slnode*)malloc(sizeof(struct slnode*)); // Allocating memory 
  temp->data=data;// Storing the data
  temp->next=NULL;       
  if (temp==NULL) // Checking if the memory is allocated or not
  {
    errno=ENOMEM;
    printf("%d\n",errno);
    return 0; // Returns the error
  }
  else
  {
    return temp;  //returns address of the new node
  }
  
}

/* sin_add(): Adds a node at the end of existing list.
 */
void sin_add(SINODE** head, SINODE* new_node)
{                                 
  struct slnode* temp,*end_node;
  temp=*head;
  end_node=new_node;
  if (temp==NULL)
  {
    *head=new_node;        
  }
else
  {
    while (temp->next!=NULL)
    {
        temp=temp->next; // Linkng two nodes at the end
    }
    temp->next=new_node;//linked with previous node
    printf("Node is added at the end");
  }
  // Code to add a node at the end of exisiting list.
  // Note: The list may be empty initially
}

/* sin_insert(): Creates a node with specified data and inserts it in the list at specified position and
 * returns the address of inserted node. pos = 0 signifies the first node.
 * A 0 or negative value of pos will insert the node at first position.
 * A value of pos, greater than the length will insert the node at the end.
 * On error, returns NULL and the errorno is set to ENOMEM
 */  
   
SINODE* sin_insert(SINODE** head, int data, int pos)
{
  struct slnode* temp,*temp_node;
  int counter=1;
  temp=*head;// Assgining the start node address 
  if(pos==0||pos<0)// Check if given posistion is equal to zero or lesser than it 
  {
    temp_node=(struct slnode*)malloc(sizeof(struct slnode*));// Allocating memory
    temp_node->next=NULL;
    temp_node->data=data;// Storing data
    return temp_node; //returing the address of node
  }
  else 
  {
    while (temp!=NULL) // Traversing the node of finding out the length of list
    {
      temp=temp->next;
      counter++;
    }
    if(pos>counter)// Checking if given posistion is greater than total lenghth of list 
    {
      temp=*head; // Assigning the start
      while (temp->next==NULL)
      {
        temp=temp->next;
      }
      temp_node=(struct slnode*)malloc(sizeof(struct slnode*));
      temp_node->next=NULL;
      temp_node->data=data;    // Added node at the end
    }
    else
    {
      temp=*head;// Assigning the start
      for (int i=1; i <=pos-1; i++)
      {
        temp=temp->next;
      }
      temp_node=(struct slnode*)malloc(sizeof(struct slnode*));
      temp_node->next=NULL;
      temp_node->data=data;
      temp_node->next=temp->next; // Assigning address of the next node
      temp->next=temp_node; // Assigning the address of new node 
    }
  }

  // List is empty, new node is added as first node.
  // List is not empty, new node is inserted at first position.
  // New node is inserted beyond first node. 
}

/* sin_delete(): Deletes the node at specified position. Returns the data from the deleted node.
 */
int sin_delete(SINODE** head, int pos)
{
  struct slnode* temp;
  temp=*head;// Assigning the start
  for (int i=1; i <=pos-1; i++) // Traversing till given posistion node -1
    {
      temp=temp->next;
    }
    temp->next=temp->next->next; // Assgining the address of next node link to current node link
    int r_data= temp->data; // Storing the data 
    free(temp); // Releasing Memory
    return r_data;
}

/* sin_length(): Returns the number of nodes in the list.
 */
int sin_length(SINODE* head)
{
  int counter;
  while(head==NULL)
    {
       head=head->next;
       counter++;
    }
  return counter;
  // Code to count the number of nodes in the list.
}

/* sin_print(): Print the list from specified node, returns the number of nodes printed */ 
int sin_print(SINODE* curr)
{
 struct slnode* temp;
temp=curr; // Storing the address into temp pointer
int counter=0;
printf("data%d\n",temp->data);
while (temp->next!=NULL)
{
  temp=temp->next;
  printf("data :%d\n",temp->data);
  counter++;
 } 
return counter;
  // Code to print the value (data) of nodes in the list.
}
