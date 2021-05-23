/*

Author : MarwanAbdelsalam

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

//same function from V7_LinkedList
void PrintList(node **head)
{
	
	if ((*head)==NULL)
	{
	printf("There's no elements in the list to print\n");
	}
	else
	{
	printf("Your list is :\n");
	//printing with a while loop
	//make a pointer to node named (current) which at first point to the first node
	node *current=(*head);
	//this while constantly checks if the current pointer reachs to null which is the last node
	while(current!=NULL)
		{
		printf("%d\n",current->data);
		current=current->next;				//increment of the current  pointer	
		}
	}

printf("\n");

}

// this function takes the pointer to the sp and the value which we want to put in the new created node which will be last node
// and the first node to access (pop)
// draw to understand (check notes)
void push( node **sp,int value)
{
	//it's not necessary to put this condition as it's done already in else
	/*if (sp==NULL)
	{
		sp=(node *)malloc(sizeof(node));
		sp->data=value;
		sp->next=NULL;
	}
	else 
	{*/
		node *temp=(node *)malloc(sizeof(node));
		temp->data=value;
		temp->next=(*sp);
		(*sp)=temp;
	//}
}
//this function takes the pointer to the sp and returns the value in the last node (the node at which the sp points ) 
// and it then free this node by making temp points to it then free temp
//draw to understand (check notes) 
int pop(node **sp)
{
	if ((*sp)==NULL)
	{
		printf("There's no elemnts in the stack to be popped\n");
	}
	else 
	{
	int value=(*sp)->data;
	node *temp=(*sp);
	(*sp)=(*sp)->next;
	free(temp);
	return value;
	}
}

int main ()
{
	node *sp1=NULL;
	node *sp2=NULL;
	push(&sp1,1);
	push(&sp1,2);
	push(&sp1,3);
	push(&sp2,0);
	push(&sp2,-1);
	push(&sp2,-2);
	//push(3);
	//printf("%d %d %d",sp->data,sp->next->data,sp->next->next->data);
	PrintList(&sp1);
	 printf("%d\n",pop( &sp1));
	 printf("%d\n",pop( &sp1));
	 printf("%d\n",pop( &sp1));
 pop( &sp1);
	PrintList(&sp1);
	//PrintList(&sp2);


}