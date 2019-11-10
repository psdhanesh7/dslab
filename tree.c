#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *leftChild, *rightChild;
};

struct node* insert(struct node *root, int data)
{

	if(root == NULL)
	{

		struct node *new = (struct node *) malloc(sizeof(struct node *));
		
		new->data = data;
		new->leftChild = NULL;
		new->rightChild = NULL;

		root = new;
	}
	else if(data <= root->data)
	{
		root->leftChild = insert(root->leftChild, data);
	}
	else if(data > root->data)
	{
		root->rightChild = insert(root->rightChild, data);	
	}
	
	return root;

}

void traverse(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	traverse(root->leftChild);

	printf("%d\t", root->data);

	traverse(root->rightChild);
}

struct node* search(struct node *root, int value)
{

	struct node *searchedElement;

	if(root == NULL)
		return root;

	if(root->data == value)
	{
		return root;
	}
	else if(value < root->data)
	{
		searchedElement = search(root->leftChild, value);
	}
	else
	{
		searchedElement = search(root->rightChild, value);
	}

	return searchedElement;
}

struct node* findMin(struct node *root)
{
	struct node *minimum;

	if(root == NULL)
	{
		minimum = NULL;
	}
	else if(root->leftChild == NULL)
	{
		minimum = root;
	}
	else
	{
		minimum = findMin(root->leftChild);
	}

	return minimum;
}
struct node* delete(struct node *root, int data)
{
	if(root == NULL)
		return root;

	if(data < root->data)
	{
		root->leftChild = delete(root->leftChild, data);
	}
	else if(data > root->data)
	{
		root->rightChild = delete(root->rightChild, data);
	}
	else
	{
		struct node *temp;

		if(root->leftChild == NULL && root->rightChild == NULL)
		{
			free(root);
			root = NULL;
		}
		else if(root->leftChild == NULL)
		{
			temp = root;
			root = root->rightChild;

			free(temp);
		}
		else if(root->rightChild == NULL)
		{
			temp = root;
			root = root->leftChild;

			free(temp);
		}
		else
		{
			temp = findMin(root->rightChild);

			root->data = temp->data;
			root->rightChild = delete(root->rightChild, temp->data);
		}

		return root;
	}
}

void deleteTree(struct node *root)
{
	if(root == NULL)
	{
		return ;
	}

	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	free(root);
}

void main()
{
	int data, choice, a = 1;
	struct node *root = NULL, *searchedElement;

	while(a)
	{

		printf("\n___MENU___\n1.Insertion\n2.Deletion\n3.Search\n4.Traversal\n5.Exit\n");
		printf("Enter your choice:");
		scanf(" %d", &choice);

		switch(choice)
		{
			case 1 : printf("Enter the element to be inserted : ");
					 scanf(" %d", &data);

					 root = insert(root, data);

					 break;

			case 2 : printf("Enter the value to be deleted : ");
					 scanf("%d", &data);

					 root = delete(root, data);

					 break;

			case 3 : printf("Enter the element to be searched : ");
					 scanf(" %d", &data);

					 searchedElement = search(root, data);

					 if(searchedElement == NULL)
					 {
					 	printf("Searched element not found!!\n");
					 }
					 else
					 {
					 	printf("Value found\n");
					 }

					 break;

			case 4 : if(root == NULL)
					 {
					 	printf("Tree is empty\n");
					 }
					 else
					 {
					 	printf("Current status of the tree is :\n");
					 	traverse(root);
					 }
					 printf("\n");

					 break;

			case 5 : a = 0;

					 break;

			default : printf("Invalid Choice!!\n");

		}

	}

	deleteTree(root);

}


