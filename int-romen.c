#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	
	int num,c=0,rev=0,a,d,f,e;
	printf("enter the num : ");
	scanf("%d",&num);
	while(num!=0)
	{
		a=num%10;
		c++;
		rev=(rev*10)+a;
		num=num/10;
	}
	while(rev!=0)
	{
		d=rev%10;
		while(d!=0)
		{
			c--;
			f=pow(10,c);
			e=f*d;
			if(e==1)
			printf("I");
			else if(e==2)
				printf("II");
			else if(e==3)
				printf("III");
			else if(e==4)
				printf("IV");
			else if(e==5)
				printf("V");
			else if(e==6)
				printf("VI");
			else if(e==7)
				printf("VII");
			else if(e==8)
				printf("VIII");
			else if(e==9)
				printf("IX");
			else if(e==10)
				printf("X");
			else if((e>10)&&(e<=50))
			{
				if(e==50)
				printf("L");
				else if(e==40)
					printf("XL");
				else
				{
					while(e!=0)


				}
			}
			else if(e==100)
				printf("C");
			else if(e==500)
				printf("D");
			else if(e==1000)
				printf("M");
			d=d/10;
		}
		rev=rev/10;
	}

/*	
 	printf("num--->%d\n",num);
	printf("count--->%d\n",c);
	printf("reverse--->%d\n",rev);
	*/



	
}
