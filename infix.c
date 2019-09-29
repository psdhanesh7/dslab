#include<stdio.h>
#include<string.h>

int top=-1,size=100;
char s[100];

void push(char c)
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

char TOP()
{
	return s[top];
}

int isempty()
{
	if(top==-1)
		return 1;
	return 0;
}

int IsNumericDigit(char c)
{
	return c>='0' && c<='9' ? 1 : 0;
}

int isoperand(char c)
{
	return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ? 1 : 0 ;
}

int isoperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	return 0;
}

int IsLeftToRightAssociative(char c)
{
	return c=='+' || c=='-' || c=='*' || c=='/' ? 1 : 0; 
}

int weight(char c)
{
	switch(c)
	{
		case '/':
		case '*': return 4;

		case '+':
		case '-': return 3;

	}
}
int hashigherprecedence(char c1,char c2)
{
	int wt1,wt2;
	wt1=weight(c1);
	wt2=weight(c2);
	if(wt1==wt2)
	{
		if(IsLeftToRightAssociative(c1))
			return 1;
	}
	else if(wt1>wt2)
		return 1;
	else
		return 0;
}
void infixtopostfix(char exp[],char result[])
{
	int i,length=strlen(exp),index=0,operand;
	for(i=0;i<length;i++)
	{
		if(exp[i] == ' ' || exp[i] == ',')
			continue;
		if(exp[i]=='(')
			push(exp[i]);
		else if(exp[i]==')')
		{
			while(s[top]!='(' && !isempty())
			{
				result[index++]=TOP();
				pop();
			}
			pop();

		}
		else if(isoperand(exp[i]))
		{
			// if(IsNumericDigit(exp[i]))
			// {
			// 	operand = 0;
			// 	while(IsNumericDigit(exp[i]))
			// 	{
			// 		operand = operand * 10 + (exp[i] - '0');
			// 		i++;
			// 	}
			// 	i--;
			// 	result=operand;
			// }
			// else

			result[index++]=exp[i];
		}
		else if(isoperator(exp[i]))
		{
			while(!isempty() && hashigherprecedence(TOP(),exp[i]) && s[top]!='(')
			{
				result[index++]=TOP();
				pop();
			}
			push(exp[i]);
		}

	}
	while(!isempty())
	{
		result[index++]=TOP();
		pop();
	}
	result[index++]='\0';

}
void main()
{
	char exp[100],result[100];
	printf("Enter a valid infix expresssion:");
	scanf(" %[^\n]",exp);
	infixtopostfix(exp,result);
	printf("Postfix Expression is : \n %s \n",result);
}