#include<stdio.h>

int size, s[100];

int top1 = 0, top2 = size;

void S1Push(int value)
{
	if(top2 == top1+1)
		printf("Overflow\n");
	else
	{
		top1++;
		s[top] = value;
	}
} 

void S2Push(int value)
{
	if(top2==top1+1)
		printf("Overflow\n");
	else
	{
		top2--;
		s[top] = value;
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

void main()
{
	int choice, value;
	while(1)
	{
		printf("%s\n", );
	}
}
