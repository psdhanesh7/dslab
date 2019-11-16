#include<stdio.h>
#include<stdlib.h>

#define hashMax 5

typedef  struct node
{
	int data;
	struct node *next;
} node;

node *hashArray[hashMax];

int hashFunction(int n)
{
	return n % hashMax;
}

void chaining(int value, int hashCode)
{
	node *new;

	new = (node*) malloc(sizeof(node));

	new->data = value;
	new->next = hashArray[hashCode];
	hashArray[hashCode] = new;
}

void deleteFromChain(int n, int hashCode)
{
	node *ptr, *pre;
	ptr = pre = hashArray[hashCode];

	while(ptr->data != n && ptr->next != NULL)
	{
		pre = ptr;
		ptr = ptr->next;
	}

	if(ptr == hashArray[hashCode])
	{
		hashArray[hashCode] = ptr->next;
		free(ptr);
	}
	else if(ptr->data == n)
	{
		pre->next = ptr->next;
		free(ptr);
	}

}

void deletion(int n)
{
	int hashCode;

	hashCode = hashFunction(n);
	deleteFromChain(n, hashCode);
}

void displayLinkedList(node *header)
{
	node *ptr = header;

	if(header == NULL)
		return;
	else
	{
		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
}


void displayHashTable()
{
	for(int i = 0; i < hashMax; i++)
	{
		displayLinkedList(hashArray[i]);  //Display each chain
	}
}

void insertion(int n)
{
	int hashCode;

	hashCode = hashFunction(n);

	chaining(n, hashCode);

}

node* deleteHead(node *header)
{
	if(header == NULL)

		return header;

	else
	{
		node *ptr;

		ptr = header;
		header = header->next;
		free(ptr);

		return header;
	}
}

void clearChain(node *header)
{
	while(header != NULL)
	{
		header = deleteHead(header);
	}	
}

void clearHashTable()
{
	for(int i = 0; i < hashMax; i++)
	{
		clearChain(hashArray[i]);
	}
}

void main()
{
	int n, hashCode, a = 1, choice;

	for(int i = 0; i < hashMax; ++i)
	{
		hashArray[i] = NULL;
	}

	while(a)
	{
		printf("\n___MENU___\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1 : printf("Enter the number to be inserted : ");
					 scanf("%d", &n);

					 insertion(n);
					 break;

			case 2 : printf("Enter the number to be deleted : ");
			 		 scanf("%d", &n);

					 deletion(n);
					 break;

			case 3 : printf("Current status of HashTable is : \n");

					 displayHashTable();
					 break;

			case 4 : a = 0;
					 break;

			default : printf("Invalid Input!!");

		}
	}

	clearHashTable();

}
