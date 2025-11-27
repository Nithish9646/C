#include<stdio.h>
int main()
{
	int i,l,j,s,num,x=2,m=2;
	printf("enter the num : ");
	scanf("%d",&num);
	for(i=-num;i<=num;i++)
	{
		if(i<0)
			l=-i;
		else
			l=i;
		for(s=0;s<l;s++)
			printf(" ");
		for(j=0;j<num-l+1;j++)
		{
			if(i<0)
			{
				printf("%d ",x);
				x=x*2;
			}
			else if(i==0)
				printf("* ");
			else
			{
				printf("%d ",m);
				m=m*2;
			}

		}
		printf("\n");
	}
	printf("\n");
}
