#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head=NULL,*tail=NULL,*ptr,*prev;
void insertFront();
void insertEnd();
void deleteFront();
void deleteEnd();
void display();
int main()
{
int choice;
while(1)
{
printf("\n\n Operations on Linked List \n");
printf("------------------------------\n");
printf("1.Insertion from Front \n");
printf("2.Insertion at the End \n");
printf("3.Deletion from Front \n");
printf("4.Deletion at the End \n");
printf("5.Display \n");
printf("6.Exit \n");
printf("\n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : insertFront();
 break;
case 2 : insertEnd();
 break;
case 3 : deleteFront();
 break;
case 4 : deleteEnd();
 break;
case 5 : display();
 break;
case 6: exit(0);
 break;
default: printf("Wrong Choice \n");
 }
 }
return 0;
}
/* To insert a node at front of the list */
void insertFront()
{
 int data;
 printf("Enter the data to be inserted into the list\n");
 scanf("%d", &data);

 struct node *newnode;
 newnode = (struct node *) malloc(sizeof(struct node));

 newnode->data = data;
 newnode->next = NULL;

 if (head == NULL)
 {
 head = tail = newnode;
 }
 else
 {
 newnode->next = head;
 head = newnode;
 }
}

/* To insert a node at the end of the list */
void insertEnd()
{
 int data;
 printf("Enter the data to be inserted into the list\n");
 scanf("%d", &data);

 struct node *newnode;
 newnode = (struct node *) malloc(sizeof(struct node));

 newnode->data = data;
 newnode->next = NULL;


if (head == NULL)
 {
 head = tail = newnode;
 }
 else
 {
 ptr = head;
 while (ptr->next!= NULL)
 ptr=ptr->next;
 ptr->next = newnode;
 tail = newnode;
 }
}


 /* To delete a node from front of the list */
void deleteFront()
{
 if (head == NULL)
 {
 printf("\n List is Empty.....\n");
 return;
 }
 else
 {
 ptr = head;
 printf("\n Deleted Element is : %d", ptr->data);
 head = ptr->next;
 free(ptr);
 }
}

/* To delete a node from the end of the list */
void deleteEnd()
{
 if (head == NULL)
 {
 printf("\n List is Empty....\n");
 return;
 }
 else
 {
 ptr = head;

 while(ptr != NULL)
 {
 prev = ptr;
 ptr = ptr->next;
 }

 prev->next = NULL;
 printf("\n Deleted Element is : %d", ptr->data);
 free(ptr);

 }

}


/* To display the contents of the list */
void display()
{
int length = 0;
if (head == NULL)
 {
 printf("List is empty...Nothing to print");
 }
 else
 {
 printf("\n Contents in the Linked List: ");
 printf("\n-------------------------------\n");
 ptr = head;
 while (ptr!=NULL)
 {
 length++;
 printf("%d\t",ptr->data);
 ptr = ptr -> next;
 }
 }
 printf("\nLength of the Linked List is : %d", length);
}