#include<stdio.h>
int strlength(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
		;
	return i;
}
void strconcant(char s1[],char s2[])
{
	int i,j;
	for(i=0;s1[i]!='\0';i++)
		;
	for(j=0;s2[j]!='\0';j++)
	{
		s1[i]=s2[j];
		i++;
	}
	s1[i]='\0';
}
void stringcpy(char s1[],char s2[])
{
	int i=0;
	while(s1[i]=s2[i])
		i++;
}
int stringcompare(char s1[],char s2[])
{
	int i=0;
	while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0')
		i++;
	return s1[i]-s2[i];
}
int substringsearch(char s[],char subs[],int pos[])
{
	int i,j,pos_count=0;
	int sublength=strlength(subs);
	for(i=0;s[i]!='\0';i++)
	{
		for(j=0;j<sublength;j++)
			if(s[i+j]!=subs[j])
				break;
		if(j==sublength)
		{
			pos[pos_count]=i;
			pos_count++;
		}
	}
	return pos_count;
}
int substringreplacement(char s[],char sub[],char replacement[])
{
	int i=0,j,index[100],index_count,k;
	char newstring[100];
	index_count=substringsearch(s,sub,index);
	if(index_count==0)
	{
		printf("Substring not found in the string!!\n");
	
	}
	else 
	{
		k=0;
		for(int itr=0;itr<index_count;itr++)
		{
			while(i<index[itr])
		 		newstring[k++]=s[i++];
			j=0;
			while(replacement[j])
		 		newstring[k++]=replacement[j++];
		
			i=i+strlength(sub);			
		}
		while(s[i])
		{
			newstring[k++]=s[i++];
		}
		newstring[k]='\0';
		stringcpy(s,newstring);
	}
	return index_count;

}
int vowels(char s[])
{
	int count=0,i;
	for(i=0;s[i]!='\0';i++)
		if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U')
			count++;
	return count;
}
int consonants(char s[])
{
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
		if( ( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ) && s[i]!='a' && s[i]!='A' && s[i]!='e' && s[i]!='E' && s[i]!='i' && s[i]!='I' && s[i]!='o' && s[i]!='O' && s[i]!='u' && s[i]!='U')
			count++;
	return count;
}
int wordcount(char s[])
{
	int i,pc,count=0;
	pc=s[0];
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]==' ' || s[i]=='\t' || s[i]=='\n')&&pc!=' ' && pc!='\t' && pc!='\n')
			count++;
		pc=s[i];
	}
	if(pc!=' ' && pc!='\t' && pc!='\n')
		count++;
	return count;
}
int menu()
{
	int choice;
	printf("\n_____MENU_____\n1.String Length\n2.String concantenation \n3.String copy\n4.String Comparison\n");
	printf("5.Substring search\n6.Substring replacement\n7.Count the number of vowels,consonants and words\n8.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	return choice;
}
void main()
{
	char s1[100],s2[100],sub[100];
	int choice,strcmp,pos,length,index[100],index_count;
	while(1)
	{
		choice=menu();
		if(choice==1 || choice==5 || choice==7 || choice==6 || choice==3 )
		{
			printf("Enter your string:");
			scanf(" %[^\n]",s1);
		}
		else if(choice==2 || choice==4)
		{
			printf("Enter string 1:");
			scanf(" %[^\n]",s1);
			printf("Enter string 2:");
			scanf(" %[^\n]",s2);
		}
		switch(choice)
		{

			case 1:	length=strlength(s1);
					printf("\nLength of the string is %d\n",length);
					break;
			case 2: strconcant(s1,s2);
					printf("\nString 2 appended with string 1 is : \n%s\n",s1);
					break;
			case 3: stringcpy(s2,s1);
					printf("\nCopied string is : %s\n",s1);
					break;
			case 4: strcmp=stringcompare(s1,s2);
					if(strcmp>0)
						printf("\nString 1 is greater than string 2\n");
					else if (strcmp<0)
						printf("\nString 2 is greater than string 1\n");
					else 
						printf("\nStrings are same\n");
					break;
			case 5: printf("\nEnter substring:");
					scanf(" %[^\n]",sub);
					index_count=substringsearch(s1,sub,index);
					if(index_count==0)
						printf("\nSubstring not found!!\n");
					else
					{	printf("\nSubstring found at the index:\n");
						for(int i=0;i<index_count;i++)
							printf("%d\t",index[i]);
						printf("\n");
					}
					break;
			case 6:	printf("Enter substring:");
					scanf(" %[^\n]",s2);
					printf("Enter the substring to replace:");
					scanf(" %[^\n]",sub);
					index_count=substringreplacement(s1,s2,sub);
					if(index_count!=0)
						printf("\nNew string is :\n%s\n",s1);
					break;
			case 7: printf("\nNumber of vowels in the string is: %d\n",vowels(s1));
					printf("Number of consonants in the string is : %d\n",consonants(s1));
					printf("Number of words in the string is : %d \n",wordcount(s1));
					break;
			case 8:goto end;

			default: printf("\nInvalid Entry!!!\n");

		}
	}

	end: ;
}