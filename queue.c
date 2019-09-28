#include<stdio.h>
int q[100],size,front=-1,rear=-1;

void enque(int value)
{
	if(rear==size-1)
	{
		printf("Queue Overflow\n");
	}
	else if(front==-1)
	{
		front=rear=0;
		q[rear]=value;
	}
	else
	{
		rear++;
		q[rear]=value;
	}
}

void deque()
{
	if(front==-1)
		printf("Queue Underflow\n");
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
		front++;
}

void display()
{
	int i;
	if(front==-1)
		printf("Queue Empty\n");
	else
	{
		printf("FRONT -->\t");
		for(i=front;i<=rear;i++)
			printf("%d\t",q[i]);
		printf("<--REAR\n");
	}
}
int  menu()
{
	int choice;
	printf("\n____MENU_____\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	printf("Enter your choice:");
	scanf(" %d",&choice);
	return choice;
}

void main()
{
	int choice,value;
	printf("Enter the size of the stack:");
	scanf("%d",&size);
	while(1)
	{
		choice=menu();
		if(choice==4)
			break;
		switch(choice)
		{
			case 1: printf("Enter the element to be inserted:");
					scanf("%d",&value);
					enque(value);
					break;
			case 2: deque();
					break;
			case 3: printf("Current status of the Queue is :\n");
					display();
					break;
			default: printf("Invalid choice!!!\n");
		}
	}
}