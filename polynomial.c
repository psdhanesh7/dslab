#include<stdio.h>
#include<stdlib.h>

struct term{

	int exp, coeff;
	struct term *next;
};

struct term* insertTerm(struct term *head, int exp, int coeff)
{
	struct term *new, *ptr, *prev;

	if(head == NULL)
	{
		new = (struct term*) malloc(sizeof(struct term));

		new->coeff = coeff;
		new->exp = exp;
		new->next = NULL;

		head = new;
	}
	else
	{
		ptr = prev = head;

		while(ptr->exp > exp && ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
		}

		if(ptr->exp == exp)         //if a term with the given exponent already exists, then coefficients are simply added
		{
			ptr->coeff = ptr->coeff + coeff;
		}
		else
		{
			new = (struct term*) malloc(sizeof(struct term));  //oherwise a new term is created and added to its corresponding position

			new->coeff = coeff;
			new->exp = exp;

			if(ptr->next == NULL && exp < ptr->exp)
			{
				ptr->next = new;
				new->next = NULL;
			}
			else if(ptr == head)
			{
				new->next = head;
				head = new;
			}
			else
			{
				new->next = prev->next;
				prev->next = new;
			}
		}
	}

	return head;
}

struct term* createPolynomial(int n)
{
	int coeff, exp;
	struct term *head = NULL;

	for(int i = 1; i <= n; i++)
	{

		printf("\nEnter term %d:\n", i);

		printf("coefficient : ");
		scanf("%d", &coeff);

		printf("Exponent : ");
		scanf("%d", &exp);

		head = insertTerm(head, exp, coeff);

	}

	return head;
}

struct term* deletionAtHead(struct term *head)
{
	if(head != NULL)
	{
		struct term *ptr;

		ptr = head;
		head = head->next;
		free(ptr);
	}

	return head;
}

struct term* multiply(struct term* p1, struct term* p2)
{
	struct term *itr1, *itr2, *result = NULL;
	int exp, coeff;

	itr1 = p1;
	itr2 = p2;

	while(itr1 != NULL)
	{
		itr2 = p2;

		while(itr2 != NULL)
		{
			exp = itr1->exp + itr2->exp;
			coeff = itr1->coeff * itr2->coeff;

			result = insertTerm(result, exp, coeff);

			itr2 = itr2->next;
		}

		itr1 = itr1->next;
	}

	return result;
}

void display(struct term *head)
{
	struct term *ptr = head;

	if(head == NULL)

		printf("Polynomial is empty!!\n");

	else
	{
		while(ptr != NULL)
		{
			printf("%dx^%d", ptr->coeff, ptr->exp);

			if(ptr->next != NULL)
				printf(" + ");

			ptr = ptr->next;
		}

		printf("\n");
	}
}

struct term* add(struct term *p1, struct term *p2)
{
	struct term *ptr1, *ptr2, *result = NULL, *tail = NULL, *new;

	ptr1 = p1;
	ptr2 = p2;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		new = (struct term*) malloc(sizeof(struct term));

		new->next = NULL;

		if(ptr1->exp > ptr2->exp)
		{
			new->exp = ptr1->exp;
			new->coeff = ptr1->coeff;

			ptr1 = ptr1->next;
		}
		else if(ptr2->exp > ptr1->exp)
		{
			new->exp = ptr2->exp;
			new->coeff = ptr2->coeff;

			ptr2 = ptr2->next;
		}
		else
		{
			new->exp = ptr1->exp;
			new->coeff = ptr1->coeff + ptr2->coeff;

			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		if(result == NULL)
		{
			result = tail = new;
		}
		else
		{
			tail->next = new;
			tail = new;
		}


	}

	while(ptr1 != NULL)
	{
		new = (struct term*) malloc(sizeof(struct term));

		new->next = NULL;
		new->exp = ptr1->exp;
		new->coeff = ptr1->coeff;

		tail->next = new;
		tail = new;

		ptr1 = ptr1->next;
	}

	while(ptr2 != NULL)
	{
		new = (struct term*) malloc(sizeof(struct term));

		new->next = NULL;
		new->exp = ptr2->exp;
		new->coeff = ptr2->coeff;

		tail->next = new;
		tail = new;

		ptr2 = ptr2->next;
	}

	return result;
}

void main(int argc, char const *argv[])
{
	struct term *p1 = NULL, *p2 = NULL, *result = NULL;
	int n;

	printf("Enter the number of terms of polynomial 1:");
	scanf("%d", &n);

	p1 = createPolynomial(n);

	printf("\nEnter the number of terms of polynomial 2:");
	scanf("%d", &n);

	p2 = createPolynomial(n);

	result = add(p1, p2);

	printf("Polynomial 1:\n");
	display(p1);

	printf("Polynomial 2:\n");
	display(p2);

	printf("Result:\n");
	display(result);



	while(p1 != NULL)
	{
		p1 = deletionAtHead(p1);
	}

	while(p2 != NULL)
	{
		p2 = deletionAtHead(p1);
	}

	while(result != NULL)
	{
		result = deletionAtHead(result);
	}
}