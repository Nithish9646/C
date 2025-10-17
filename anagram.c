#include<stdio.h>
#include<string.h>
void remove_special(char *);
int sn_st(char*,char*);
int over(char *);
void my_sort(char *);
//void my_cmp(char *,char*);
int main()
{
	char a[100],b[100];
	printf("enter the string 1 : ");
	scanf("%[^\n]",a);
	printf("enter the string 2 : ");
	scanf(" %[^\n]",b);
	remove_special(a);
	remove_special(b);
	int p=sn_st(a,b);
	if(p==0)
	{
		a[100]=over(a);
		b[100]=over(b);
		my_sort(a);
		my_sort(b);
		if((strcmp(a,b))==0)
			printf("ITS AN ANAGRAM\n");
		else
			printf("NOT AN ANAGRAM\n");
	}
	else
		printf("NOT AN ANAGRAM\n");

}
void remove_special(char *p)
{
	int i,j;
	char c[10],d[10];
	for(i=0;p[i];i++)
	{
		if(!(((p[i]>='A')&&(p[i]<='Z'))||((p[i]>='a')&&(p[i]<='z'))))
		{
			for(j=i;p[j];j++)
			{
				p[j]=p[j+1];
			}
			i--;
	        }
	}
}
int sn_st(char *p,char*q)
{
	int k,m;
	k=strlen(p);
	m=strlen(q);
	if(k==m)
		return 0;
	else
		return -1;
}
void  my_sort(char *p)
{
	int i,j,n,temp;
	n=strlen(p);

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i]>p[j])
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
int over(char *p)
{
	int i;
	for(i=0;p[i];i++)
	{
		if((p[i]>='A')&&(p[i]<='Z'))
			p[i]=p[i]+32;
	}
}
