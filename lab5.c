#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE struct node
 
struct node
{
	char name[20];
	int number;
	NODE *next;
};
NODE *head=NULL;
NODE *tail=NULL;

void add(); 
void delete();
void display();

int main()
{	

	int choice=0;
	
	while(1)
	{
		printf("Please choose an option\n (1) to Add\n (2) to Remove\n (3) to Display\n (4) to Quit\n");
		scanf("%d", &choice);
		
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			return 0;
		}
	}
return 0;
}

void add()
{
	NODE *temp; //the new part of the list
	char nombres[20];
	temp = (NODE *)malloc(sizeof(NODE)); //creating the new part

	printf("Please enter a name for the reservation. \n");
	scanf("%s", nombres);
	strcpy(temp->name, nombres);
	
	printf("Please enter the party size.\n");
        scanf("%d", &temp->number);
			
	if (head==NULL) //checks if the list is empty
	{
		temp->next=head;
		head=temp;
		tail=temp;
		tail->next=NULL;
		NODE *ptr=head;
       		while(ptr!=NULL)
        	{
                	int q=strcmp(nombres, ptr->name); //checks if there is a duplicate name
                	ptr=ptr->next;
                	if (q==0)
                	{
                       		 printf("There is a duplicate name!\n");
                        	return;
                 	}
        	}
	}
	
	else //list is not empty
	{
		tail->next=temp;
		tail=temp;
		tail->next=NULL;
	}
	 
       /*NODE *ptr=head;
       while(ptr!=NULL)
        {
                int q=strcmp(nombres, ptr->name); //checks if there is a duplicate name
                ptr=ptr->next;
                if (q==0)
                {
                        printf("There is a duplicate name!\n");
                        return;
                 }
        }*/
	
return;
}

void  delete()
{
	int table_open=0; //what the open table size is
	printf("what is the size of the table that is open?\n");
	scanf("%d", &table_open);
	
	NODE *previous=head;
	NODE *current=previous->next;
	
	if (head->number<=table_open)
		head=head->next;
	
	else
	{
		while(current!=NULL && current->number<=table_open)
		{
			previous=previous->next;
			current=current->next;
		}
	
		if (previous==NULL && head->number<=table_open)
		{
			current=head;
			head=current->next;
			free(current);
		}
	
		else if (previous->next != NULL && previous->next->number<=table_open)
		{
			current=previous->next;
			previous->next = previous->next->next;
			free(current);
		}
	}
return;
}

void display()
{
	NODE *current;
	current = head;
	while (current != NULL) //while loop with temporary pointer to traverse and print array
	{
		printf("Names: %s Party: %d\n", current->name, current->number);
		current=current->next;
	}
return;
}

