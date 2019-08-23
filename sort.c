#include<stdio.h>
#define max 100
int partition(int ar[],int start,int end)
{
	int pivot=ar[end],pindex=start,i,temp;
	for (int i = start; i <=end-1; ++i)
	{
		if(ar[i]<=pivot)
		{
			temp=ar[i];
			ar[i]=ar[pindex];
			ar[pindex]=temp;
			pindex++;
		}
	}
	temp=ar[end];
	ar[end]=ar[pindex];
	ar[pindex]=temp;
	return pindex;
}
void quicksort(int ar[],int start,int end)
{
	if(start<end)
	{
		int pindex=partition(ar,start,end);
		quicksort(ar,start,pindex-1);
		quicksort(ar,pindex+1,end);
	}
}
void bubblesort(int ar[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(ar[j]>ar[j+1])
			{
				int temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
}
void merge(int a[],int b[],int c[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(a[i]<=b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else if(b[j]<a[i])
		{
			c[k]=b[j];
			k++;
			j++;
		}
		else
		{
			c[k]=c[k+1]=a[i];
			i++;
			j++;
			k+=2;
		}
	}
	while(i<n1)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		c[k]=b[j];
		j++;
		k++;
	}

}
void mergesort(int ar[],int n)
{
	int left[max],right[max],mid,i;
	if(n<2)
		return ;
	mid=n/2;
	for(i=0;i<mid;i++)
		left[i]=ar[i];
	for(i=mid;i<n;i++)
		right[i-mid]=ar[i];
	mergesort(left,mid);
	mergesort(right,n-mid);
	merge(left,right,ar,mid,n-mid);
	
}
void insertionsort(int ar[],int n)
{
	int i,hole,value;
	for(i=1;i<n;i++)
	{
		value=ar[i];
		hole=i;
		while(hole>0 && ar[hole-1]>value)
		{
			ar[hole]=ar[hole-1];
			hole--;
		}
		ar[hole]=value;
	}
}
void selectionsort(int ar[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(ar[j]<ar[min])
				min=j;
		if(min!=i)
		{
			int temp=ar[i];
			ar[i]=ar[min];
			ar[min]=temp;
		}
	}
}
int menu()
{
	int choice;
	printf("\n_____MENU_____\n1.Bubblesort\n2.Selection sort\n3.Quick sort\n4.Merge sort\n5.Insertion sort\n6.Exit");
	printf("\nEnter your choice:  ");
	scanf("%d",&choice);
	return choice;

}
void main()
{
	int ar[max],n,i,choice;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	printf("Entered array is :\n");
	for(i=0;i<n;i++)
		printf("%d\t",ar[i]);
	choice=menu();
	switch(choice)
	{
		case 1: bubblesort(ar,n);
				break;
		case 2: selectionsort(ar,n);
				break;
		case 3: quicksort(ar,0,n-1);
				break;
		case 4: mergesort(ar,n);
				break;
		case 5: insertionsort(ar,n);
				break;
		case 6: goto end;

		default:printf("Invalid Entry!!");

	}
	
	printf("\nSorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d\t",ar[i]);
	printf("\n");
	end:;

}