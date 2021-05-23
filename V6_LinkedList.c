#include <stdio.h>
#include <stdlib.h>
/*
Author : Marwan Abdelsalam

V1:Simple code of linked list
V2: Add_Node_Last functions added
V3: PrintList and Delete_Node_First functions added
V4: Delete_Node_Last function added
V5: Delete_Node_Number function added
V6: Update_Node_Data and Is_Existed functions added

*/

/*a struct hold a data of the node and a pointer to a node which points to the next node */
typedef struct node
{
    int data;
    struct node* next;
}node;

/*first make a global pointer to a node named head which points to the first node but initially points to zero*/
node *head=NULL;

/*This function takes the value of the data to be stored in the first node and return nothing*/
void Add_Node_First(int value)
{
	node*temp=(node*) malloc(sizeof(node));
	temp->data=value;
	temp->next=head;
	head=temp;
}

/*This function takes the value of the data to be stored in the last node and return nothing
it checks first if the linked list is totally empty (head=null) so it deals with the head first
if the list already has at least one node it enters the else*/
void Add_Node_Last(int value)
{
	if (head==NULL) 	
	{
		head=(node*) malloc(sizeof(node));
		head->data=value;
		head->next=NULL;
	}
	else
	{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=value;
	temp->next=NULL;
	/*make a pointer to node named current and make it = head and it loops searching for 
	the last node till it reaches it and make this node points to the new node */
	node *current=head;
	while (current->next!=NULL)
		{
		current=current->next;
		}
	current->next=temp;
	}
}

/*this function check if the list is empty or not if not it prints the whole list*/
void PrintList(void)
{
	if (head==NULL)
	{
	printf("There's no elements in the list to print\n");
	}
	else
	{
		printf("Your list is :\n");
	/*printing with a while loop*/
	/*make a pointer to node named (current) which at first point to the first node*/
	node *current=head;
	/*this while constantly checks if the current pointer reachs to null which is the last node*/
	while(current!=NULL)
		{
		printf("%d\n",current->data);
		current=current->next;				/*increment of the current  pointer	*/
		}
	}

printf("\n"); 

}
/*this function deletes the first node in the list */
void Delete_Node_First(void)
{
	
	node  * temp  = head ; 
	
	if ( head ==NULL)
	{
		printf("The list is already empty\n");
	}
	else
	{
		/*deleting the main head and makes the head equals the next of the first node which points to the second node */
		head = head ->next;	
		free ( temp );
	}
	
}
/*this function deletes the last node in the list  */
void Delete_Node_Last(void)
{
	
	if (head==NULL)
	{
		printf("The list is already empty\n");
	}
	else
	{
	int count =0;
	int i;
	/*make a pointer to node named (current) which at first point to the first node*/
	node *current=head;
	/*this while constantly checks if the current pointer reachs to null which is the last node and count the elements*/
	while(current->next!=NULL)
		{
		current=current->next;				/*increment of the current pointer	*/
		count++;
		}
		/*now count has the number of elements in the list*/
	current=head;		/*resetting the current pointer and make it points to the first node again*/
	/*this for loop make the current pointer points to the before last node to make it points to null to make it the last node*/
	for (i=0;i<count-1;i++)
		current=current->next;
	/*put the before last node points to null*/
	current->next=NULL;
	}
}

void Delete_Node_Number(int index)
{
	/*make a pointer to node named (current) which at first point to the first node*/
	node *current=head;
	int i;
	/*this loop makes the current points to the node just before the node wanted to be deleted*/
	for (i=0;i<index-1;i++)
		current=current->next;
	/*let the current pointer -which points to the node just before the node to be deleted - 
	   points to the node after the node to be deleted*/
	current->next=current->next->next;
}
void Update_Node_Data(int index,int value)
{
	/*make a pointer to node named (current) which at first point to the first node*/
	node *current=head; 
	int i;
	/*this loop makes the current points to the node just before the node wanted to be deleted*/
	for (i=0;i<index;i++)
		current=current->next;
	/*let the current pointer -which points to the node just before the node to be deleted - 
	   points to the node after the node to be deleted*/
	current->data=value;
}
int Is_Existed(int value)
{
		/*make a pointer to node named (current) which at first point to the first node*/
	node *current=head;
	/*this while constantly checks if the current pointer reachs to null which is the last node*/
	while(current->next!=NULL)
		{
			current=current->next;
			if (current->data==value)		/*if it founds the value return 1 and get out of the function*/
				return 1;
		}
	return 0;

}
int main()

{
Add_Node_Last(1);
Add_Node_Last(2);
Add_Node_Last(3);
Add_Node_Last(4);
Add_Node_Last(5);
Add_Node_Last(6);
Add_Node_Last(7);
Add_Node_Last(8);
PrintList();
Delete_Node_First();
Delete_Node_First();
Delete_Node_First();
PrintList();
Delete_Node_Last();
PrintList();
Delete_Node_Number(2);
PrintList();
Update_Node_Data(3,20);
PrintList();
printf("if existed state %d",Is_Existed(20));
}
