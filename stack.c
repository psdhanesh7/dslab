#include<stdio.h>

int top=-1,size,s[100];

void push(int value)
{
	if(top>=size-1)
		printf("Stack Overflow\n");
	else
	{
		top++;
		s[top]=value;

	}
}

void pop()
{
	if(top==-1)
		printf("Stack Underflow\n");
	else
	{
		top--;
	}
}

void display()
{
	int i;
	if(top==-1)
		printf("Stack Empty\n");
	else
	{
		printf("TOP -->\t");
		for(i=top;i>=0;i--)
		{
			printf("%d\t",s[i] );
		}		
		printf("\n");
	}

}

int  menu()
{
	int choice;
	printf("\n____MENU_____\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
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
			case 1: printf("Enter the element to be pushed:");
					scanf("%d",&value);
					push(value);
					break;
			case 2: pop();
					break;
			case 3: printf("Current status of the stack is :\n");
					display();
					break;
			default: printf("Invalid choice!!!\n");
		}
	}
}