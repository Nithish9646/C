#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st 
{
	int roll;
	char name[20];
	float mark;
	struct st *next;
};
void add_begin(struct st **);
void print(struct st*);
void save(struct st*);
void add_end(struct st  **);
void add_middle(struct st **);
void reverse(struct st *);
void rev_data(struct st *);
void rev_link(struct st **);
int count(struct st *);
void delete(struct st *);
void delete_node(struct st **,int);

int main()
{
	struct st *hptr=0;
	char op;
	do 
	{
		add_begin(&hptr);
		add_end(&hptr);
		add_middle(&hptr);
		printf("DO YOU NEED ANOTHER STD DETAIL(Y/N)\n");
		scanf(" %c",&op);
	}while(op=='Y');
	print(hptr);
	save(hptr);
	printf("REVERSE\n");
	reverse(hptr);
	printf("REVERSE DATA\n");
	rev_data(hptr);
	printf("REVERSE LINK\n");
	rev_link(&hptr);
	printf("DELETE\n");
	delete(hptr);
	int n;
	printf("enter the roll->num\n");
	scanf("%d",&n);
	printf("DELETE NODE\n");
	delete_node(&hptr,n);
}

void add_begin(struct st **ptr)
{
	struct st * temp;
	temp=(struct st *)malloc(sizeof(struct st));
	printf("ENTER THE STD DETAIL\n");
	temp->next=*ptr;
	*ptr=temp;
}
void add_end(struct st ** ptr)
{	
	struct st * temp;
	temp=(struct st *)malloc(sizeof(struct st));
	printf("ENTER THE STD DETAIL\n");
	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st * last=*ptr;
		while(last->next!=0)
			last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
void add_middle(struct st **ptr)
{

	struct st * temp;
	temp=(struct st *)malloc(sizeof(struct st));
	printf("ENTER THE STD DETAIL\n");
	if((*ptr==0)||(temp->roll < (*ptr)->roll))
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st * last=*ptr;
		while((last->next!=0)&&(temp->roll > last->next->roll))
			last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
void print(struct st * ptr)
{
	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
}

void save(struct st * ptr)
{
      FILE *fp=fopen("data","w");
	while(ptr!=0)
	{
		fprintf(fp,"%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
}
void reverse(struct st *ptr)
{
	if(ptr!=0)
	{
		reverse(ptr->next);
	}
}
void rev_data(struct st *ptr)
{
	int c,i,j,size=sizeof(struct st)-8;
	c=count(ptr);
	struct st **p;
	p=(struct st **)malloc(c*sizeof(struct st *));
	for(i=0;i<c;i++)
	{
		p[i]=ptr;
		ptr=ptr->next;
	}
	struct st temp;
	for(i=0,j=c-1;i<j;i++,j--)
	{
		memcpy(&temp,p[i],size);
		memcpy(p[i],p[j],size);
		memcpy(p[j],&temp,size);
	}
}
int count(struct st *ptr)
{
	int count=0;
	while(ptr!=0)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}

void rev_link(struct st **ptr)
{
	int c,i;
	c=count(*ptr);
	struct st *temp=*ptr;
	struct st **p;
	p=(struct st **)malloc(c*sizeof(struct st *));
	for(i=0;i<c;i++)
	{
		p[i]=temp;
		temp=temp->next;
	}
	p[0]->next=0;
	for(i=1;i<c;i++)
	{
		p[i]->next=p[i-1];
	}
	*ptr=p[c-1];
}

void delete(struct st *ptr)
{
	struct st *temp;
	while(ptr!=0)
	{
		temp=ptr;
		ptr=ptr->next;
		free(temp);
	}
}

void delete_node(struct st ** ptr,int n)
{
	struct st *temp,*prev;
	temp=*ptr;
	while(temp!=0)
	{
		if(temp->roll==n)
		{
			if(temp==*ptr)
				temp=(*ptr)->next;
			else
				prev->next=temp->next;
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	printf("INVALID ROLL\n");
}

