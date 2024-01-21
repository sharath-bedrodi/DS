#include<stdio.h>
#include<stdlib.h>
struct stud
{
char name[20],USN[10],prog[20];
int sem;
long int phno;
struct stud *next;
};
struct stud *head=NULL,*tail=NULL,*ptr,*prev, *newnode;

struct Node
{
int data;
struct Node *next;
}*top = NULL;
void createnode();
void insertFront();
void insertEnd();
void insertPos();
void deleteFront();
void deleteEnd();
void display();
void push(int);
void pop();
void displaystack();
int main()
{
int choice,data;
while(1)

{
printf("\n\n DEMO: Operations on Singly Linked List \n");
printf("-----------------------------------------------\n");
printf("1.Create Node \n");
printf("2.Insertion from Front \n");
printf("3.Insertion at the End \n");
printf("4.Deletion from Front \n");
printf("5.Deletion at the End \n");
printf("6.Display \n");
printf("7.Push data into stack \n");
printf("8.Pop an element from stack \n");
printf("9.Display Stack Contents \n");
printf("10. Exit \n");
printf("\n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : createnode();
break;
case 2 : insertFront();
break;
case 3 : insertEnd();
break;
case 4 : deleteFront();
break;
case 5 : deleteEnd();
break;
case 6 : display();
break;
case 7:
printf("Enter the value to be insert: ");
scanf("%d",&data);
push(data);
break;
case 8: pop();
break;
case 9: displaystack();
break;
case 10: exit(0);
break;
default: printf("Wrong Choice \n");
}
}
return 0;
}

void createnode(int item)
{
newnode=(struct stud *)malloc(sizeof(struct stud));
printf("\nEnter the USN of the student:");
scanf("%s",newnode->USN);
printf("\nEnter the name of the student:");
scanf("%s",newnode->name);
printf("\nEnter the program of the student:");
scanf("%s",newnode->prog);
printf("\nEnter the Semester :");
scanf("%d",&newnode->sem);
printf("\nEnter the Phone Number:");
scanf("%ld",&newnode->phno);
newnode->next = NULL;
head = newnode;
printf("\nNode inserted\n");
}

/* To insert a node at front of the list */
void insertFront()
{
newnode=(struct stud *)malloc(sizeof(struct stud));
printf("\nEnter the USN of the student:");
scanf("%s",newnode->USN);
printf("\nEnter the name of the student:");
scanf("%s",newnode->name);
printf("\nEnter the program of the student:");
scanf("%s",newnode->prog);
printf("\nEnter the Semester :");
scanf("%d",&newnode->sem);
printf("\nEnter the Phone Number:");
scanf("%ld",&newnode->phno);
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
struct stud *newnode;
newnode=(struct stud *)malloc(sizeof(struct stud));
printf("\nEnter the USN of the student:");
scanf("%s",newnode->USN);
printf("\nEnter the name of the student:");
scanf("%s",newnode->name);
printf("\nEnter the program of the student:");
scanf("%s",newnode->prog);
printf("\nEnter the Semester :");
scanf("%d",&newnode->sem);
printf("\nEnter the Phone Number:");
scanf("%ld",&newnode->phno);
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

printf("\nDeleted Student Record: ");
printf("\n-----------------------------");
printf("\nUSN :");
printf("%s",ptr->USN);
printf("\n Name :");
printf("%s",ptr->name);
printf("\n Program :");
printf("%s",ptr->prog);
printf("\n Semester :");
printf("%d",ptr->sem);
printf("\n Phone Number:");
printf("%ld",ptr->phno);
head = ptr->next;
free(ptr);
}
}
/* To delete a node from the end of the list */
void deleteEnd()
{
if(head == NULL)
{
printf("\nlist is empty");
}
else if(head -> next == NULL)
{
head = NULL;
free(head);
printf("\nOnly node of the list deleted ...");
}
else
{
ptr = head;
while(ptr->next != NULL)
{
prev = ptr;
ptr = ptr ->next;
}
prev->next = NULL;
free(ptr);
printf("\n Deleted Node from the last ...");
}
}

/* To display the contents of the list */
void display()
{
int length = 0;
if (head == NULL)
{
printf("\nList is empty...Nothing to print");
}
else
{
printf("\n Contents in the Linked List: ");
printf("\n-------------------------------\n");
ptr = head;
printf("\n List of Student Records: ");
while (ptr!=NULL)
{
length++;
printf("\n-----------------------------");
printf("\nUSN :");
printf("%s",ptr->USN);
printf("\n Name :");
printf("%s",ptr->name);
printf("\n Program :");
printf("%s",ptr->prog);
printf("\n Semester :");
printf("%d",ptr->sem);
printf("\n Phone Number:");
printf("%ld",ptr->phno);
printf("\n-----------------------------");
ptr = ptr -> next;
}
}
printf("\nLength of the Linked List is : %d", length);
printf("\n------------------------------------------");
}

/* To push the elements on to the Stack */
void push(int data)
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
if(top == NULL)
newNode->next = NULL;
else
newNode->next = top;
top = newNode;
printf("\nInsertion is Success!!!\n");
}
/* To pop the elements from the Stack */

void pop()
{
if(top == NULL)
printf("\nStack is Empty!!!\n");
else
{
struct Node *temp = top;
printf("\nDeleted element: %d", temp->data);
top = top->next;
free(temp);
}
}

/* To display the contents of the Stack */

void displaystack()
{
if(top == NULL)
printf("\nStack is Empty!!!\n");
else
{
struct Node *temp;
for( temp = top; temp != NULL; temp = temp->next)
printf("%d-----> \t",temp->data);
}
}