#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *link;

}*header;

void insertionAtHead(int value)
{
	struct node *new;

	new = (struct node*) malloc(sizeof(struct node));

	new->data = value;
	new->link = header;
	header = new;
}

void insertionAtTail(int value)
{
	struct node *new, *ptr;

	new = (struct node*) malloc(sizeof(struct node));

	if(header == NULL)
	{
		new->link = header;
		header = new;
	}	
	else
	{
		ptr = header;

		while(ptr->link != header)
		{
			ptr = ptr->link;
		}

		new->link = NULL;
		ptr->link = new;
	}
}

void insertionAtAPostion(int pos, int value)
{
		// if(header == NULL)
		// {
		// 	printf("List empty!!\n");
		// }
		// else
		// {
		// 	struct node *prev, *ptr, *new;
		// 	int i;

		// 	prev = ptr = header;

		// 	for(i = 1; i < pos && ptr->link != NULL; i++)
		// 	{
		// 		prev = ptr;
		// 		ptr = ptr->link;
		// 	}

		// 	if(i != n-1)
		// 		printf("Invalid position\n");
		// 	else
		// 	{
		// 		new = (struct node *) malloc(sizeof(struct node));

		// 		new->data = value;
		// 		prev->link = new;
		// 		new->link = ptr;
		// 	}

		}
}

void insertionBeforeAData(int data, int value)
{
	if(header == NULL)

		printf("List is empty!!Data not found\n");

	else
	{
		struct node *ptr = header, *pc = header, *new;

		while(ptr->data != data && ptr->link !=NULL)
		{
			pc = ptr;
			ptr = ptr->link;
		}
		if(ptr->data != data)
			printf("Data not found\n");
		else
		{
				new = (struct node*) malloc(sizeof(struct node));

				if(ptr == pc)
				{
					new->link = header;
					header = new;
				}
				else
				{
					new->link = pc->link;
					pc->link = new;
				}
		}
	}
}


void deletetionAtHead()
{
	if(header == NULL)

		printf("Underflow\n");

	else
	{
		struct node *ptr;

		ptr = header;
		header = header->link;
		free(ptr);
	}
}

void deletetionAtTail()
{
	if(header == NULL)
	{
		printf("Underflow\n");
	}	
	else
	{
		struct node *pc = header, *ptr = header;

		while(ptr->link != NULL)
		{
			pc = ptr;
			ptr = ptr->link;
		}

		if(pc == ptr)
		{
			header = NULL;
			free(pc);
		}
		else
		{
			pc->link = NULL;
			free(ptr);
		}
	}
}

void deletetionAtAPosition()
{


}

void deletetionBeforeAData(int data)
{
	if(header == NULL)
	{
		printf("Underflow\n");
	}
	else
	{
		struct node *ptr = header, *pv1 = header, *pv2 = header;

		while(ptr->data != data && ptr->link != NULL)
		{
			pv2 = pv1;
			pv1 = ptr;
			ptr = ptr->link;
		}

		if(ptr->data != data)
		{
			printf("Node not found!!\n");
		}
		else
		{
			if(ptr == header)
				printf("No node before the specified node\n");
			else if(pv1 == header)
			{
				header = ptr;
				free(ptr);
			}
			else
			{
				pv2->link = ptr;
				free(pv1);
			}
		}
	}
}

void display()
{
	struct node *ptr = header;

	if(header == NULL)

		printf("List is empty\n");

	else
	{
		printf("Head -->\t");

		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->link;
		}

		printf("<--Tail\n");

	}
}

void main()
{
	int choice, data, value, position;

	header = NULL;

	while(1)
	{
		printf("\n____MENU____\n1. Insertion at head\n2. Deletion at head\n3. Insertion at tail\n4. Deletion at tail\n5. Insertion at a position\n6. Deletion at a position\n7. Insertion before a data\n8. Deletion before a data\n9. Display\n10.Exit\n");
		printf("Enter your choice:\n");

		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("Enter the value to be inserted\n");
					scanf("%d", &value);

					insertionAtHead(value);

					break;

			case 2: deletetionAtHead();

					break;

			case 3: printf("Enter the value to be inserted\n");
					scanf("%d", &value);

					insertionAtTail(value);

					break;

			case 4: deletetionAtTail();

					break;

			case 5: printf("Enter the position of the new node:");
					scanf("%d", &position);

					printf("Enter the value to be inserted\n");
					scanf("%d", &value);

					insertionAtAPostion(position, value);

					break;

			case 6: deletetionAtAPosition();

					break;

			case 7: printf("Enter the data of the node before which the new node is to be inserted");
					scanf("%d", &data);

					printf("Enter the value to be inserted\n");
					scanf("%d", &value);

					insertionBeforeAData(data, value);

					break;

			case 8: printf("Enter the data of the node before which the new node is to be deleted");
					scanf("%d", &data);

					deletetionBeforeAData(data);
					break;

			case 9: printf("Current status of the list is :\n");

					display();

					break;

			case 10: goto end;

			default : printf("Invalid Entry!!!\n");

		}
	}

	end: 

	while(header != NULL)
	{
		deletetionAtHead();
	}

}