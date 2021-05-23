
#include <stdio.h>
#include <stdlib.h>

/*a struct hold a data of the node and a pointer to a node which points to the next node */
typedef struct node
{
    int data;
    struct node* next;
}node;

//This function takes the address of the head of the list required to print as a pointer to pointer to node
//it check if the list is empty or not if not it prints the whole list
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

void InQueue(node **head,int value)
{
	node*temp=(node*) malloc(sizeof(node));
	temp->data=value;
	temp->next=(*head);
	(*head)=temp;
}


int DeQueue(node **head)
{
	int value;
	if ((*head)==NULL)
	{
		printf("The list is already empty\n");
	}
	else if ((*head)->next==NULL)
	{
		node *temp;
		value = (*head)->data;
		temp=(*head);
		(*head)=NULL;
		free (temp);
		return value;
	}
	else
	{
		node  *temp; 
		int count =1;
		int i;
		//make a pointer to node named (current) which at first point to the first node
		node *current=(*head);
		//this while constantly checks if the current pointer reachs to null which is the last node and count the elements
		while(current->next!=NULL)
		{
		current=current->next;				//increment of the current pointer	
		count++;
		}
		//now count has the number of elements in the list
		current=(*head);		//resetting the current pointer and make it points to the first node again
		//this for loop make the current pointer points to the before last node to make it points to null to make it the last node
		// (the current itself is now the next pointer of the third last node)
		for (i=0;i<count-2;i++)
		current=current->next;
		value=current->next->data;
		/*make the temp is the next of the last node to free it(to free the pointer(the address) to the last node)*/
		temp=current->next;
		//put the before last node points to null
		current->next=NULL;
	
		free(temp);
		return value;
	}

}

int main()
{
	node * head1=NULL;
	node * head2=NULL;
	InQueue(&head1,1);
	InQueue(&head1,2);
	InQueue(&head1,3);
	InQueue(&head1,3);
	printf("%d\n",DeQueue(&head1));
	printf("%d\n",DeQueue(&head1));
	printf("%d\n",DeQueue(&head1));
	 PrintList(&head1);

}
