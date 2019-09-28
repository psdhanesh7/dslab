#include<stdio.h>
int q[100],size,front=-1,rear=-1;

void enque(int value)
{
 	if(front==-1)
	{
		front=rear=0;
		q[rear]=value;
	}
	else if( (front==0 && rear==size-1) || (front!=0 && rear==front-1) )
	{
		printf("Queue Overflow\n");
	}
	else
	{
		rear=(rear+1)%size;
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
		front=(front+1)%size;
}

void display()
{
	int i;
	if(front==-1)
		printf("Queue Empty\n");
	else
	{
		printf("FRONT -->\t");
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
				printf("%d\t",q[i]);
		}
		else
		{
			for(i=front;i<size;i++)
				printf("%d\t",q[i]);
			for(i=0;i<=rear;i++)
				printf("%d\t", q[i]);
		}
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