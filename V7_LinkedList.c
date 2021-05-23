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
V7 : -making it more generic by passing for each function the address of the head to make us able to deal with more than just one list
	 -adding the free function in each delete node function
	 -fixing some logical errors
	 -function Add_Node_Number added
	 -functions IsEmpty and CreateNode added
*/

/*a struct hold a data of the node and a pointer to a node which points to the next node */
typedef struct node
{
    int data;
    struct node* next;
}node;

//this function checks if the link is empty or not by checking if the head points to null or not
//returns 0 or 1
char IsEmpty(node **head)
{
	return (*head)==NULL;
}

//this function just return an address of a new node to be saved in a pointer to node variable when called
node* CreateNode(void)
{
	return (node*)malloc(sizeof(node));
}

//This function takes the address of the head of the list required to print as a pointer to pointer to node
//it check if the list is empty or not if not it prints the whole list
void PrintList(node **head)
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

//This function takes the address of the head of the list required to modify in as a pointer to pointer to node 
//and value of the data to be stored in the first node and return nothing
// it's the same as the not generic one the only difference is that we deals with the address of the head instead of the head itself
// and instead of (head) in the old code we put (*head)

void Add_Node_First(node **head,int value)
{
	node*temp=CreateNode();
	temp->data=value;
	temp->next=(*head);
	(*head)=temp;
}

//This function takes the address of the head of the list required to modify in as a pointer to pointer to node 
//and value of the data to be stored in the last node and return nothing
//it checks first if the linked list is totally empty (head=null) so it deals with the head first
//if the list already has at least one node it enters the else
// it's the same as the not generic one the only difference is that we deals with the address of the head instead of the head itself
// and instead of (head) in the old code we put (*head)
	
void Add_Node_Last(node **head,int value )
{
	if (IsEmpty(head)) 	
	{
		(*head)=CreateNode();
		(*head)->data=value;
		(*head)->next=NULL;
	}
	else
	{
	node *temp=CreateNode();
	temp->data=value;
	temp->next=NULL;
	//make a pointer to node named current and make it = head and it loops searching for 
	//the last node till it reaches it and make this node points to the new node 
	node *current=(*head);
	while (current->next!=NULL)
		{
		current=current->next;
		}
	current->next=temp;
	}
}

// same as other functions 
// the indeces of the elements start from 1 not 0 ,, that's why we made i<index-2 in the for loop instead of i<index-1

void Add_Node_Number(node **head,int index,int value)
{
	if (IsEmpty(head))
	{
		printf("The list is empty, your value has been put in the list now\n");
		Add_Node_First(head,value);
		//(*head)=CreateNode();
		//(*head)->data=value;
		//(*head)->next=NULL;
	}
	else if (index<1)						// negative or zero index
		printf("Wrong index\n");
	else if (index==1)						//add in the first node
		Add_Node_First(head,value);
	else
	{
		int i;
		node *temp=CreateNode();
		node *current=(*head);
		temp->data=value;
		for (i=0;i<index-2;i++)
			current=current->next;
		//draw to understand what happened here
		temp->next=current->next;
		current->next=temp;
	}
}


//this function deletes the first node in the list ,, 
//(in case of many linked lists it takes a pointer to head of the list required to delete first node) 
//it takes a pointer to head because it would modify the value of the head itself 
void Delete_Node_First(node ** head)
{
	if ( IsEmpty(head))
	{
		printf("The list is already empty\n");
	}
	else
	{
		//deleting the main head and makes the head equals the next of the first node which points to the second node 
		node  * temp  = (*head) ; 
		(*head) = temp ->next;	
		free ( temp );
	}	
}

//this function deletes the last node in the list  
void Delete_Node_Last(node **head)
{
	
	if (IsEmpty(head))
	{
		printf("The list is already empty\n");
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
	/*make the temp is the next of the last node to free it(to free the pointer(the address) to the last node)*/
	temp=current->next;
	//put the before last node points to null
	current->next=NULL;
	
	free(temp);

	}
}

void Delete_Node_Number(node **head,int index)
{
	if (IsEmpty(head))
	{
		printf("The list is already empty\n");
	}
	else
	{
	node  *temp; 
	//make a pointer to node named (current) which at first point to the first node
	node *current=(*head);
	int i;
	//this loop makes the current points to the node just before the node wanted to be deleted
	//the current itself is the next of the node before the node to be deleted by 2 nodes
	for (i=0;i<index-2;i++)
		current=current->next;

	//make the temp is the next of node before the node to be deleted
	//make the temp points to the node to be deleted
	temp=current->next;
	//let the current pointer -which points to the node just before the node to be deleted - 
	 //points to the node after the node to be deleted
	current->next=current->next->next;
		free(temp);

	}
}

void Update_Node_Data(node** head, int index,int value)
{
	if (IsEmpty(head))
	{
		printf("The list is empty\n");
	}
	else
	{
	//make a pointer to node named (current) which at first point to the first node
	node *current=(*head); 
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

int Is_Existed(node **head,int value)
{
	if (IsEmpty(head))
	{
		printf("The list is empty\n");
	}
	else
	{
		//make a pointer to node named (current) which at first point to the first node
		node *current=(*head);
		//this while constantly checks if the current pointer reachs to null which is the last node
		while(current->next!=NULL)
			{
				current=current->next;
				if (current->data==value)		//if it founds the value return 1 and get out of the function
					return 1;
			}
	}
	return 0;
}

int main()

{
	node *head1=NULL;
	node *head2=NULL;
	Add_Node_Last(&head1,1);
	Add_Node_Last(&head1,2);
	Add_Node_Last(&head1,3);
	Add_Node_Last(&head1,4);
	Add_Node_Last(&head1,5);
PrintList(&head1);
Add_Node_Number(&head1,-2,22);
//	Add_Node_Last(&head2,2);
//	Add_Node_Last(&head2,4);
//	Add_Node_Last(&head2,6);
//	Add_Node_Last(&head2,8);
//	Add_Node_Last(&head2,10);
//PrintList(&head2);
 //Add_Node_Number(&head1,6,95);
// Add_Node_Number(&head2,4,0);
//PrintList(&head1);
//PrintList(&head2);
 //Add_Node_Number(&head1,3,55);
// Add_Node_Number(&head2,4,0);
PrintList(&head1);
//PrintList(&head2);


}
