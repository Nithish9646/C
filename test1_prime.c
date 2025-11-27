#include<stdio.h>
int main()
{
	int i,l,k,num,count=0,even=0,odd=0,a;
	printf("enter the num :");
	scanf("%d",&num);
	for(i=2;i<=num;i++)
	{
		if(num%i==0)
			break;
	}
	if(i==num)
		printf("its prime \n");
	else
		printf("not a prime\n");
	for(l=num;l!=0;l/=10)
	{
		count++;
	}
	for(k=num;k!=0;k/=10)
	{
		a=k%10;
		if(count--%2!=0)
			odd=odd+a;
		else
			even=even+a;
	}
	printf("odd--->%d\n",odd);
	printf("even-->%d\n",even);
}
