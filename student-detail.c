#include<stdio.h>
#include<string.h>
struct st
{
	int roll;
	char name[10];
	float mark;
};
void scan(struct st *);
void print(struct st *);
void sort(struct st * );
int main()
{
	struct st v[5];
	scan(v);
	print(v);
	sort(v);
}
void scan(struct st *p)
{
	int i;
	printf("enter the roll no , name , mark :\n ");
	for(i=0;i<3;i++)
	{
		scanf("%d %s %f",&p[i].roll,p[i].name,&p[i].mark);
	}
}
void print(struct st *s)
{
	int i;
	printf("printing the table \n");
	for(i=0;i<3;i++)
	{
		printf("%d %s %f\n",s[i].roll,s[i].name,s[i].mark);
	}
}
void sort(struct st *d )
{
	int op,i,j,temp;
	char h[10];
	printf("enter the num 1->roll 2->name 3->mark\n");
	scanf("%d",&op);
	for(i=0;i<3;i++)
		{
			for(j=i+1;j<3;j++)
			{
				if(op==1)
				{
					if(d[i].roll>d[j].roll)
					{
						temp=d[i].roll;
						d[i].roll=d[j].roll;
						d[j].roll=temp;
						strcpy(h,d[i].name);
						strcpy(d[i].name,d[j].name);
						strcpy(d[j].name,h);
						temp=d[i].mark;
						d[i].mark=d[j].mark;
						d[j].mark=temp;
					}
				}
				else if(op==2)
				{
					if(strcmp(d[i].name,d[j].name)>0)
					{
						temp=d[i].roll;
						d[i].roll=d[j].roll;
						d[j].roll=temp;
						strcpy(h,d[i].name);
						strcpy(d[i].name,d[j].name);
						strcpy(d[j].name,h);
						temp=d[i].mark;
						d[i].mark=d[j].mark;
						d[j].mark=temp;
					}
				}  
				else if(op==3)
				{
					if(d[i].mark>d[j].mark)
					{
						temp=d[i].roll;
						d[i].roll=d[j].roll;
						d[j].roll=temp;
						temp=d[i].mark;
						d[i].mark=d[j].mark;
						d[j].mark=temp;
						strcpy(h,d[i].name);
						strcpy(d[i].name,d[j].name);
						strcpy(d[j].name,h);
					}
				}
				else
				{
					printf("not in this\n");
					break;
				}
			}
		}
					for(i=0;i<3;i++)
						printf("%d %s %f\n",d[i].roll,d[i].name,d[i].mark);

}



