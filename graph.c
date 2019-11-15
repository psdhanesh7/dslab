#include<stdio.h>
#include<stdlib.h>

void print(int **edges, int n, int sv, int *visited)
{
	printf("%d\t", sv);
	
	*(visited + sv) = 1;

	for(int i = 0; i < n; ++i)
	{
		if(i == sv)
		{
			continue;
		}

		if(*(*(edges + sv) + i) == 1)
		{
			if(*(visited + i))
			{
				continue;
			}
			print(edges, n, i, visited);
		}
	}
}

void main()
{
	int n, e, **edges, f, s, *visited;

	printf("Enter the number of vertices :");
	scanf(" %d", &n);

	printf("Enter the number of edges : ");
	scanf("%d", &e);

	edges = (int **) malloc(n * sizeof(int*));

	for(int i = 0; i < n; ++i)
	{
		*(edges + i) = (int *) malloc(n * sizeof(int));
		for(int j = 0; j < n; ++j)
		{
			*(*(edges + i) + j) = 0;
		}
	}

	printf("Enter the edges : \n");

	for(int i = 0; i < e; ++i)
	{
		scanf("%d %d", &f, &s);

		*(*(edges+f)+s) = 1;
		*(*(edges+s)+f) = 1;
	}

	visited = (int *) malloc(n * sizeof(int));

	for(int i = 0; i < n; ++i)
	{
		*(visited + i) = 0;
	}

	printf("DFS Traversal is :\n");

	print(edges, n, 0, visited);

	for(int i = 0; i < n; i++)
	{
		free(*(edges + i));
	}

	free(edges);	 	 
}
