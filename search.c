#include <stdio.h>
int lsearch(int ar[],int n,int item)
{
	int i,present=0;
	for(i=0;i<n;i++)
		if(ar[i]==item)
		{	
			present=1;
			printf("%d\t",i);
		}
	printf("\n");
	if(!present)
		printf("Element is not  present!!\n");

}
int bsearch(int ar[],int n,int item,int searchFirst)
{
	int top=0,bottom=n-1,middle,pos=-1;
	while(top<=bottom)
	{
		middle=(top+bottom)/2;
		if(ar[middle]==item)
		{
			pos=middle;
			if(searchFirst)
				bottom=middle-1;
			else
				top=middle+1;
		}
		else if(item<ar[middle])
			bottom=middle-1;
		else 
			top=middle+1;

	}
	return pos;
}
int bsearchrec(int ar[],int top,int bottom,int item,int searchFirst)
{
	int pos=-1,lindex,middle=(top+bottom)/2;
	if(top<=bottom)
	{

		if(item==ar[middle])
		{
			pos=middle;
			if(searchFirst)
			{
				lindex=bsearchrec(ar,0,middle-1,item,1);
			}
			else
				lindex=bsearchrec(ar,middle+1,bottom,item,0);
			if(lindex!=-1)
				pos=lindex;
		}
		else if(item<ar[middle])
			pos=bsearchrec(ar,top,middle-1,item,searchFirst);
		else
			pos=bsearchrec(ar,middle+1,bottom,item,searchFirst);
		
	}
	return pos;
}
void main()
{
	int ch,ar[1000],i,n,item,l,r,pos;
	char c;
	while(1)
	{
		printf("_______MENU________\n1.Linear search\n2.Binary search using iteration\n3.Binary search using recursion\n4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1||ch==2||ch==3)
		{
			printf("Enter the number of elements in the array:");
			scanf("%d",&n);
			printf("Enter the elements of the array:");
			for(i=0;i<n;i++)
				scanf("%d",&ar[i]);
			printf("Enter the item to be searched:");
			scanf("%d",&item);			
		}
		switch(ch)
		{
			case 1:
					printf("%d is present at:\n",item);
					lsearch(ar,n,item);
					break;
			case 2:l=bsearch(ar,n,item,1);
					r=bsearch(ar,n,item,0);
					
					if(l==-1)
						printf("Element not present\n");
					else
					{
						printf("%d is present at:\n",item);
						for(i=l;i<=r;i++)
							printf("%d\t",i);
						printf("\n");
					}
					break;
			case 3:l=bsearchrec(ar,0,n-1,item,1);
					r=bsearchrec(ar,0,n-1,item,0);
					if(l==-1)
						printf("Element not present\n");
					else
					{
						printf("%d is present at:\n",item);
						for(i=l;i<=r;i++)
							printf("%d\t",i);
						printf("\n");
					}
					break;
			case 4:goto label;
			default:printf("INVALID ENTRY!!!\n");
		}



	}
	label:;
}