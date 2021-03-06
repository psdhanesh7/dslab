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

	new->data = value;

	if(header == NULL)
	{
		new->link = header;
		header = new;
	}	
	else
	{
		ptr = header;

		while(ptr->link != NULL)
		{
			ptr = ptr->link;
		}

		new->link = NULL;
		ptr->link = new;
	}
}

void insertionAtAPostion(int pos, int value)
{
		int currentPos = 1;
		struct node *new, *ptr = header;

		if(pos == 1)
		{
			new = (struct node *) malloc(sizeof(struct node*));

			new->data = value;	
			new->link = header;
			header = new;
		}
		else
		{
			while(currentPos < pos-1 && ptr != NULL)
			{
				ptr = ptr->link;
				currentPos++;
			}

			if(ptr == NULL)

				printf("Specified position not valid!!\n");

			else
			{
				new = (struct node*) malloc(sizeof(struct node));

				new->data = value;
				new->link = ptr->link;
				ptr->link = new;
			}
		}
}

void insertionBeforeAData(int data, int value)
{
	if(header == NULL)

		printf("List is empty!!\n");

	else
	{
		struct node *ptr = header, *pc = header, *new;

		while(ptr->data != data && ptr->link !=NULL)
		{
			pc = ptr;
			ptr = ptr->link;
		}
		if(ptr->data != data)
			printf("Data not found!!\n");
		else
		{
				new = (struct node*) malloc(sizeof(struct node));

				new->data = value;

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


void deletionAtHead()
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

void deletionAtTail()
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

void deletionAtAPosition(int pos)
{
	int currentPos = 1;
	struct node *temp, *ptr = header;

	if(pos == -1)
	{
		temp = header;
		header = header->link;

		free(temp);
	}
	else
	{
		while(currentPos < pos-1 && ptr != NULL)
		{
			ptr = ptr->link;
			currentPos++;
		}

		if(ptr == NULL)
			printf("Specified position not valid !!\n");
		else
		{
			temp = ptr->link;
			ptr->link = ptr->link->link;

			free(temp);
		}
	}

}

void deletionBeforeAData(int data)
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
				printf("No node before the specified node!!\n");
			else if(pv1 == header)
			{
				header = ptr;
				free(pv1);
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

		printf("List is empty!!\n");

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
		printf("\n____MENU____\n1. Insertion at head\n2. Deletion at head\n3. Insertion at tail\n4. Deletion at tail\n");
		printf("5. Insertion at a position\n6. Deletion at a position\n7. Insertion before a data\n");
		printf("8. Deletion before a data\n9. Display\n10.Exit\n");
		printf("Enter your choice:\n");

		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("Enter the value to be inserted : \n");
					scanf("%d", &value);

					insertionAtHead(value);

					break;

			case 2: deletionAtHead();

					break;

			case 3: printf("Enter the value to be inserted :\n");
					scanf("%d", &value);

					insertionAtTail(value);

					break;

			case 4: deletionAtTail();

					break;

			case 5: printf("Enter the position of the new node : ");
					scanf("%d", &position);

					printf("Enter the value to be inserted :\n");
					scanf("%d", &value);

					insertionAtAPostion(position, value);

					break;

			case 6: deletionAtAPosition(position);

					break;

			case 7: printf("Enter the data of the node before which the new node is to be inserted : ");
					scanf("%d", &data);

					printf("Enter the value to be inserted\n");
					scanf("%d", &value);

					insertionBeforeAData(data, value);

					break;

			case 8: printf("Enter the data of the node before which the new node is to be deleted : ");
					scanf("%d", &data);

					deletionBeforeAData(data);
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
		deletionAtHead();
	}

}