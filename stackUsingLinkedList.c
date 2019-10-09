#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
	
}*top, *ptr;

void push(int value)
{
	struct node *new;

	new = (struct node*)malloc(sizeof(struct node));

	new->data = value;
	new->link = top;
	top = new;
}

void pop()
{
	if(top == NULL)
		printf("Underflow\n");
	else

	{
		ptr = top;
		top = top->link;
		free(ptr);
	}
}

void display()
{
	ptr = top;
	if(top == NULL)
		printf("Stack Empty\n");
	else
	{
		printf("Top -->\t");
		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->link;
		}
	}
	
}

void main()
{
	int value, choice;
	top = NULL;
	while(1)
	{
		printf("\n_____MENU_____\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("Enter the element to be inserted:");
					scanf("%d", &value);
					push(value);
					break;
			case 2: pop();
					break;
			case 3: printf("Current status of stack is :\n");
					display();
					break;
			case 4: goto end;

			default: printf("Invalid Entry!!!\n");
		}
	}
	
	end:
		while(top != NULL)
		{
			pop();
		}
}