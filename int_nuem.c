#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	
	int num,c=0,rev=0,k,d,f,e;
	char a[20][20]={"I","II","III","IV","V","VI","VII","VIII","IX","X","XL","L","XC","C","CD","D","CM","M"};
	printf("enter the num : ");
	scanf("%d",&num);
	while(num!=0)
	{
		k=num%10;
		c++;
		rev=(rev*10)+k;
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
			printf("%s",a[e-1]);
			else if(e==2)
				printf("%s",a[e-1]);
			else if(e==3)
				printf("%s",a[e-1]);
			else if(e==4)
				printf("%s",a[e-1]);
			else if(e==5)
				printf("%s",a[e-1]);
			else if(e==6)
				printf("%s",a[e-1]);
			else if(e==7)
				printf("%s",a[e-1]);
			else if(e==8)
				printf("%s",a[e-1]);
			else if(e==9)
				printf("%s",a[e-1]);
			else if(e==10)
				printf("%s",a[e-1]);
			else if((e>10)&&(e<501))
			{
				if((e>10)&&(e<=50))
				{

					int l,i;
					while(e!=0)
					{
						l=e%10;
						e=e/10;
						for(i=0;i<e;i++)
						{
							if(e<=3)
							{
							printf("%s",a[9]);
							}
							else if(e==4)
							{
								printf("%s",a[10]);
								break;
							}
							else if(e==5)
							{
								printf("%s",a[11]);
								break;
							}
						}
						if(l>0)
						printf("%s",a[l-1]);
						e=e/10;
					}
				}
				else if((e>59)&&(e<100))
				{
					int l,i,p=1;
					while(e!=0)
					{
						l=e%10;
						e=e/10;
						for(i=0;i<e-5;i++)
						{
							if((e>5)&&(e<9))
							{
								if(p==1)
									printf("%s",a[11]);
							printf("%s",a[9]);
							}
							else if(e==9)
							{
								printf("%s",a[12]);
								break;
							}
							p++;
						}
						printf("%s",a[l-1]);
						e=e/10;
					}

			     }
				else if((e>=100)&&(e<500))
				{
					int l,i,p,q;
					while(e!=0)
					{
						l=e%100;
						e=e/100;
						for(i=0;i<e;i++)
						{
							if(e<4)
							{
								printf("%s",a[13]);
							}
							else if(e==4)
							{
								printf("%s",a[14]);
								break;
							}
						}
						p=l/10;
						for(i=0;i<p;i++)
						{
							if(p<4)
								printf("%s",a[9]);
							else if(p==4)
								printf("%s",a[10]);
						}
						q=l%10;
						if(q>0)
						printf("%s",a[k-1]);
						e=e/100;
					}

			     
				}
				else if((e>=500)&&(e<1000))
				{
					int l,i,p,r;
					while(e!=0)
					{
						l=e%100;
						e=e/100;
						for(i=0;i<e;i++)
						{
							if(e==5)
							{
								printf("%s",a[15]);
								break;
						}
							else if((e>5)&&(e<9))
							{
								printf("%s",a[15]);
							}
							else if(e==9)
							{
								printf("%s",a[16]);
								break;
							}
						}
						p=l/10;
						for(i=0;i<p;i++)
						{
							if(p<4)
								printf("%s",a[9]);
							else if(p==4)
								printf("%s",a[10]);
						}
						r=l%10;
						if(r>0)
						printf("%s",a[k-1]);
						e=e/100;
					}
				}

		    }
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
