#include<stdio.h>
#include<string.h>

int top,size=100;
int s[100];

void push(int c)
{
	if(top>=size-1)
		return;
	else
	{
		top++;
		s[top]=c;

	}
}

void pop()
{
	if(top==-1)
		return;
	else
	{
		top--;
	}
}

int IsEmpty()
{
	if(top==-1)
		return 1;
	return 0;
}

char Top()
{
	return s[top];
}

int IsOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	return 0;
}

int PerformOperation(int operand1, int operand2, char operator)
{
	switch(operator)
	{
		case '*': return operand1 * operand2;

		case '/': return operand1 / operand2;

		case '+': return operand1 + operand2;

		case '-': return operand1 - operand2;
	}
}

int IsNumericDigit(char c)
{
	return c>='0' && c<='9' ? 1 : 0;
}

int reverse(int n)
{
	int rev = 0, dig;
	while(n>0)
	{
		dig = n%10;
		rev = rev*10+dig;
		n/=10;
	}
	return rev;
}
int EvaluatePostfix(char exp[])
{
	int i,result,length=strlen(exp),operand1,operand2,operand;
	for(i=0;i<length;i++)
	{
		if(exp[i] == ' ' || exp[i] == ',')
			continue;
		else if(IsOperator(exp[i]))
		{
			operand2 = Top();
			pop();
			operand1 = Top();
			pop();
			result = PerformOperation(operand1,operand2,exp[i]);
			push(result);
		}
		else if(IsNumericDigit(exp[i]))
		{
			operand = 0;
			while(IsNumericDigit(exp[i]))
			{
				operand = operand * 10 + (exp[i] - '0');
				i++;
			}
			i--;
			push(operand);
		}
	}
	result=Top();
	pop();
		
	return result;
}


int EvaluatePrefix(char exp[] )
{
	int i,result,length=strlen(exp),operand1,operand2,operand;
	for(i=length-1;i>=0;i--)
	{
		if(exp[i] == ' ' || exp[i] == ',')
			continue;
		else if(IsOperator(exp[i]))
		{
			operand1 = Top();
			pop();
			operand2 = Top();
			pop();
			result = PerformOperation(operand1,operand2,exp[i]);
			push(result);
		}
		else if(IsNumericDigit(exp[i]))
		{
			operand = 0;
			while(IsNumericDigit(exp[i]))
			{
				operand = operand * 10 + (exp[i] - '0');
				i--;
			}
			i++;
			operand = reverse(operand);
			push(operand);
		}
	}
	result=Top();
	pop();
		
	return result;

}

void main()
{
	char exp[100];
	int result,choice;
	while(1)
	{
		printf("\n____MENU_____\n1.Postfix Expression Evaluation\n2.Prefix Expression Evaluation\n3.Exit\nEnter your choice:");
		scanf( " %d", &choice);
		top = -1;
		switch(choice)
		{
			case 1: printf("Enter a valid Postfix Expression:\n");
					scanf(" %[^\n]",exp);
						
					result = EvaluatePostfix(exp);

					printf("Result of the given expression is : %d\n", result);

					break;
			case 2: printf("Enter a valid Prefix Expression:\n");
					scanf(" %[^\n]",exp);

					result = EvaluatePrefix(exp);

					printf("Result of the given expression is : %d\n", result);

					break;
			case 3: goto end;

			default: printf("Invalid choice!!!\n");	

		}

	}
	end: ;
	


}