#include<stdio.h>

int size, s[100];

int top1 = -1, top2, size;

void S1Push(int value)
{
	if(top2 == top1+1)
		printf("Overflow\n");
	else
	{
		top1++;
		s[top1] = value;
	}
} 

void S2Push(int value)
{
	if(top2==top1+1)
		printf("Overflow\n");
	else
	{
		top2--;
		s[top2] = value;
	}
}

void S1Pop()
{
	if(top1 == -1)
		printf("Underflow\n");
	else
	{
		top1--;
	}
}

void S2Pop()
{
	if(top2 == size)
		printf("Underflow\n");
	else
		top2++;
}

void s1Display()
{
	int i;
	if(top1 == -1)
		printf("Stack Empty\n");
	else
	{
		printf("Top -->\t");
		for(i = top1; i >= 0; i--)
			printf("%d\t", s[i]);
	}
}

void s2Display()
{
	int i;
	if(top2 == size)
		printf("Stack Empty\n");
	else
	{
		for(i = top2; i < size; i++)
			printf("%d\t", s[i]);
	}
}


void main()
{
	int choice, value;
	printf("Enter the size of the array :");
	scanf(" %d",&size);
	top2 = size;

	while(1)
	{
		printf("\n_____MENU_____\n1.Push to stack 1\n2.Push to stack 2\n3.Pop from stack 1\n4.Pop from stack 2\n5.Display Stack 1\n6.Display stack 2\n7.Exit\nEnter your choice:" );
		scanf(" %d", &choice);

		switch(choice)
		{
			case 1: printf("Enter the element to be pushed:");
					scanf(" %d",&value);
					S1Push(value);
					break;

			case 2: printf("Enter the value to be pushed:");
					scanf(" %d",&value);
					S2Push(value);
					break;

			case 3: S1Pop();
					break;

			case 4: S2Pop();
					break;

			case 5: printf("Present status of Stack 1 is:\n" );
					s1Display();
					break;

			case 6: printf("Present status of Stack 2 is:\n");
					s2Display();
					break;

			case 7: goto end;

			default: printf("Invalid choice!!!\n");
		}
	}
	end: ;
}
