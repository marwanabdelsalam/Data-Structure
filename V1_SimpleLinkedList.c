#include <stdio.h>
#include <stdlib.h>
/*

Author : MarwanAbdelsalam

V1:Simple code of linked list
*/

/*a struct hold a data of the node and a pointer to a node which points to the next node */
typedef struct node
{
    int data;
    struct node* next;
}node;


int main()

{
	/*first make a pointer to a node named head which points to the first node but initially points to zero*/
	node *head=NULL;
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
	
	/*simple print*/
	printf("%d %d %d\n",head->data,head->next->data,head->next->next->data);
	
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
