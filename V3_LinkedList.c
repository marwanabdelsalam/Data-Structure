#include <stdio.h>
#include <stdlib.h>
/*

Author : MarwanAbdelsalam

V1:Simple code of linked list
V2: Add_Node_Last functions added
V3: PrintList and Delete_Node_First functions added
*/

/*a struct hold a data of the node and a pointer to a node which points to the next node */
typedef struct node
{
    int data;
    struct node* next;
}node;

/*first make a global pointer to a node named head which points to the first node but initially points to zero*/
node *head=NULL;

/*This function takes the value if the data in the node and return nothing
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


}
/*this function deletes the first node in the list  */
void Delete_Node_First(void)
{
	if (head==NULL)
	{
		printf("The list is already empty\n");
	}
	else
	{
		/*deleting the main head and makes the head equals the next of the first node which points to the second node */
		head=head->next;	
	}
	
}
int main()

{
		/*creating the first node*/
	/*reserve a block in memory with size of node and save the pointer to this block in the head*/
	head= (node*)malloc(sizeof(node));
	/*put the data in the first node*/
	head->data=1;
	/*make the first node points to null indicating that it's the last node*/
	head->next=NULL;
	/*creating the second node*/
	/*reserve a block in the memory with size of node and save the pointer to this block in a temp*/
	node *temp=(node*)malloc(sizeof(node));
	/*make the first node points to this new node(temp) instead of null*/
	head->next=temp;
	/*put the data in the second node*/
	head->next->data=2;
	/*make the second node points to null indicating that it's the last node*/
	head->next->next=NULL;
	/*creating the third node*/
	temp=(node*)malloc(sizeof(node));
	head->next->next=temp;
	head->next->next->data=3;
	head->next->next->next=NULL;
	
	Add_Node_Last(6);
	Add_Node_Last(7);
	Add_Node_Last(8);
	Add_Node_Last(9);
	/*simple print*/
	//printf("%d %d %d\n",head->data,head->next->data,head->next->next->data);
	
	PrintList();	
	
	Delete_Node_First();
	Delete_Node_First();
	Delete_Node_First();
	Delete_Node_First();
	Add_Node_Last(5);

	PrintList();	

}
