/*
 * silist.h - header file for list api for creating and managing single linked list of integers. 
 * author - Dhananjay ,dhp1942012@gmail.com
 * version - 1.0, September 24 , 2019
 */

# ifndef SI_LIST_H

# define SI_LIST_H

typedef struct slnode {
  int data;		// data element
  struct slnode* next;	// address of next node (if present)	
} SINODE;		// SINODE represents a node of [S]ingle linked list of [I]ntegers

SINODE* sin_create(int data);

void sin_add(SINODE** head, SINODE* new_node);

SINODE* sin_insert(SINODE** head, int data, int pos);

int sin_delete(SINODE** head, int pos);

int sin_length(SINODE* head);

int sin_print(SINODE* curr);

int sin_mid(SINODE* head);

void sin_display(SINODE* head);

# endif
