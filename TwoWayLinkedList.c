#include <stdio.h>
#include <stdlib.h>
/*
Author : Marwan Abdelsalam

//draw to undestand 
// check notes p57

*/

/*
a struct hold a data of the node and a pointer to a node which points to the next node
and a pointer to a node which points to the previos node */
typedef struct TwoWayNode
{
    int data;
    struct TwoWayNode* next;
    struct TwoWayNode* previous;
}TwoWayNode;

//this function checks if the link is empty or not by checking if the head points to null or not
//returns 0 or 1
char IsEmpty(TwoWayNode **head)
{
	return (*head)==NULL;
}

//this function just return an address of a new node to be saved in a pointer to node variable when called
TwoWayNode* CreateNode(void)
{
	return (TwoWayNode*)malloc(sizeof(TwoWayNode));
}

//This function takes the address of the head of the list required to print as a pointer to pointer to node
//it check if the list is empty or not if not it prints the whole list
void PrintList(TwoWayNode **head)
{
	
	if (IsEmpty(head))
	{
	printf("There's no elements in the list to print\n");
	}
	else
	{
	printf("Your list is :\n");
	//printing with a while loop
	//make a pointer to node named (current) which at first point to the first node
	TwoWayNode *current=(*head);
	//this while constantly checks if the current pointer reachs to null which is the last node
	while(current!=NULL)
		{
		printf("%d\n",current->data);
		current=current->next;				//increment of the current  pointer	
		}
	}

printf("\n");

}

// This function takes the address of the head and the value of the node needed to be added first
//draw to undestand 
// check notes p57
void Add_Node_First(TwoWayNode **head,int value)
{
	TwoWayNode * temp=CreateNode();
	if (IsEmpty(head))
	{
		temp->data=value;
		temp->previous=NULL;
		temp->next=NULL;
		(*head)=temp;
	}
	else 
	{
		temp->data=value;
		temp->next=(*head);
		temp->previous=NULL;
		(*head)->previous=temp;
		(*head)=temp;
	}	
}

// This function takes the address of the head and the value of the node needed to be added last
//draw to undestand 
// check notes p57
void Add_Node_Last(TwoWayNode **head,int value )
{
	TwoWayNode*temp= CreateNode();
	temp->data=value;
	temp->next=NULL;
	if (IsEmpty(head))
	{
		temp->previous=NULL;
		(*head)=temp;
	}
	else 
	{
		TwoWayNode* current=(*head);
		while(current->next!=NULL)
			current=current->next;
		temp->previous=current;
		current->next=temp;
	}
}
// This function takes the address of the head and the index of the node needed to be added and the value saved in it
// the indeces of the elements start from 1 not 0 ,, that's why we made i<index-2 in the for loop instead of i<index-1
//draw to undestand 
//check page 59
void Add_Node_Number(TwoWayNode **head,int index,int value)
{
	if (IsEmpty(head))
	{
		printf("The list is empty, your value has been put in the list now\n");
		Add_Node_First(head,value);
	}
	else if (index<1)						// negative or zero index
		printf("Wrong index\n");
	else if (index==1)						//add in the first node
		Add_Node_First(head,value);
	else									//	for indeces larger than 1
	{
		TwoWayNode * temp=CreateNode();
		TwoWayNode * current=(*head);
		int i;
		//save the data 3ady 3ady aho
		temp->data=value;
		//this for loop make the current points to the node before the node to be added
		// the current becomes equal the next of the node before before the node to be added
		for(i=0;i<index-2;i++)
			current=current->next;
		// make the new node points to the previous and next node
		temp->previous=current;
		temp->next=current->next;
		//the linking
		current->next=temp;
		current->next->previous=temp;
	}
}

//this function deletes the first node in the list ,, 
//(in case of many linked lists it takes a pointer to head of the list required to delete first node) 
//it takes a pointer to head because it would modify the value of the head itself 
void Delete_Node_First(TwoWayNode ** head)
{
	if ( IsEmpty(head) )
	{
		printf("The list is already empty\n");
	}
	else if ((*head)->next==NULL)		// if there's just one element in the list
	{
		//deleting the main head and makes the head equals the next of the first node which points to the second node 
		TwoWayNode  * temp  = (*head) ; 
		(*head) = temp ->next;			// this make the head = NULL
		free ( temp );
	}	
	else					 			// more than one element
	{
		//deleting the main head and makes the head equals the next of the first node which points to the second node 
		TwoWayNode  * temp  = (*head) ; 
		(*head) = temp ->next;
		(*head)->previous=NULL;			// I didn't put this in the one element case because in the last line the head 
										//becomes already NULL so we can't say NULL->previous =NULL it makes run time error
		free ( temp );
	
	}
}

//this function deletes the last node in the list  
void Delete_Node_Last(TwoWayNode **head)
{
	if (IsEmpty(head))
	{
		printf("The list is already empty\n");
	}
	else if ((*head)->next==NULL)		// if there's just one element in the list
	{
		TwoWayNode * temp=(*head);
		(*head)=NULL;
		free(temp);

	}
	else
	{
		TwoWayNode * current=(*head);
		TwoWayNode * temp;
		while (current->next->next!=NULL)
			current=current->next;
		temp=current->next;
		current->next=NULL;
		free(temp);
	}
}

void Delete_Node_Number(TwoWayNode **head,int index)
{
	if (IsEmpty(head))
	{
		printf("The list is already empty\n");
	}
	else if (index<1)						// negative or zero index
		printf("Wrong index\n");
	else if (index==1)						//add in the first node
		Delete_Node_First(head);
	else
	{
		TwoWayNode * current=(*head);
		TwoWayNode * temp;
		int i;
		for (i=0;i<index-2;i++)
			current=current->next;
		temp=current->next;
		current->next->previous=current;
		current->next=current->next->next;
		free(temp);		
	}
}

//same as one way linked list 
void Update_Node_Data(TwoWayNode** head, int index,int value)
{
	if (IsEmpty(head))
	{
		printf("The list is already empty\n");
	}
	else if (index<1)						// negative or zero index
		printf("Wrong index\n");
	else
	{
	//make a pointer to node named (current) which at first point to the first node
	TwoWayNode *current=(*head); 
	int i;
	//this loop makes the current points to the node to be modified
	// the current itself becomes equal the next of the node before the node to be modified
	for (i=0;i<index-1;i++)
		current=current->next;
	//let the current pointer -which points to the node just before the node to be deleted - 
	   //points to the node after the node to be deleted
	current->data=value;
	}
}

//this function returns void and take the address of the hea dand the value wanted to search for 
// and an address of a variable (Existed) in main to indicate wether the element is existed or not 
// and an address of a variable (firstoccurance) in main to return the first occurance of this number in the list
void Search(TwoWayNode **head,int value,int *Existed ,int *firstoccurance )
{
	(*Existed)=0;
	(*firstoccurance)=0;
	if (IsEmpty(head))
	{
		printf("The list is empty\n");
	}
	else
	{
		//make a pointer to node named (current) which at first point to the first node
		TwoWayNode *current=(*head);
		//this while constantly checks if the current reachs to null which is the last node
		while(current!=NULL)
			{
				(*firstoccurance)++;
				if (current->data==value)		
				{
					*Existed=1;
					break;
				}
				current=current->next;
			}
	}
}

int main()
{
	TwoWayNode * head1=NULL;
	TwoWayNode * head2=NULL;
	Add_Node_First(&head1,1);
	Add_Node_First(&head1,3);
	Add_Node_First(&head1,2);
	Add_Node_First(&head1,1);
	
	//Add_Node_First(&head2,-4);
	//Add_Node_First(&head2,-3);
	//Add_Node_First(&head2,-2);
//	Add_Node_First(&head2,-1);
	int existed=0,firstoccurance=0;
	
PrintList(&head1);
Search(&head1,5,&existed,&firstoccurance);
//PrintList(&head2);
 //Add_Node_Number(&head1,1,22);
 //Add_Node_Number(&head1,2,55);
 //Add_Node_Number(&head1,3,77);
// Add_Node_Number(&head2,3,15);
printf("state :%d\nits order :%d\n",existed,firstoccurance);
//PrintList(&head1);
//PrintList(&head2);

}