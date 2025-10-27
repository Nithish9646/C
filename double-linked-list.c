#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
	int roll;
	char name[20];
	float mark;
	struct st * next;
	struct st * prev;
};
void add_begin(struct st **);
void add_end(struct st **);
void print(struct st *);
void save(struct st *);
void reverse(struct st *);
void rev_link(struct st **);
int count(struct st *);
void rev_data(struct st *);
void delete(struct st *);
void delete_node(struct st **,int);
void add_middle(struct st **);
int main()
{
	struct st *hptr=0;
	char op;
	do
	{
		//add_begin(&hptr);
		//add_end(&hptr);
		add_middle(&hptr);
		printf("DO YOU NEED STD DETAIL(Y/N)\n");
		scanf(" %c",&op);
	}while(op=='Y');
	printf("PRINT\n");
	print(hptr);
	printf("REVERSE\n");
	reverse(hptr);
	printf("REVERSE-LINK\n");
	rev_link(&hptr);
	print(hptr);
	printf("REV-DATA\n");
	rev_data(hptr);
	print(hptr);
	//printf("DELETE\n");
	//delete(hptr);
	//print(hptr);
	printf("DELETE-NODE\n");
	int n;
	printf("ENTER THE ROLL-NUM\n");
	scanf("%d",&n);
	delete_node(&hptr,n);
	print(hptr);

}
void add_begin(struct st **ptr)
{
	struct st * temp;
	temp=(struct st *)malloc(sizeof(struct st ));
	printf("ENTER THE DETAIL\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);
	temp->prev=*ptr;
	temp->next=0;
	if(*ptr!=0)
		(*ptr)->prev=temp;
	*ptr=temp;
}

void print(struct st * ptr)
{

	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
}
void add_end(struct st **ptr)
{

	struct st * temp;
	temp=(struct st *)malloc(sizeof(struct st ));
	printf("ENTER THE DETAIL\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);
	if(*ptr==0)
	{
		temp->prev=*ptr;
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st *last=*ptr;
		while(last->next!=0)
			last=last->next;
		temp->prev=last;
		temp->next=last->next;
		last->next=temp;
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
	while(ptr->next!=0)
		ptr=ptr->next;
	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->prev;
	}
}
void rev_link(struct st **ptr)
{
	struct st * temp;
	while(*ptr!=0)
	{
		temp=(*ptr)->prev;
	        (*ptr)->prev=(*ptr)->next;
		(*ptr)->next=temp;
		(*ptr)=(*ptr)->prev;
	}
	(*ptr)=temp->prev;
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
void rev_data(struct st *ptr)
{
	struct st *p1,*p2;
	p2=ptr;
	p1=ptr;
	while(p2->next!=0)
	{
		p2=p2->next;
	}
	int c,i,size=sizeof(struct st)-16;
	c=count(ptr);
	struct st temp;
	for(i=0;i<c/2;i++)
	{
		memcpy(&temp.roll,&p1->roll,size);
		memcpy(&p1->roll,&p2->roll,size);
		memcpy(&p2->roll,&temp.roll,size);
	}

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
void delete_node(struct st **ptr,int n)
{
	struct st *pre,*temp;
	temp=*ptr;
	while(temp!=0)
	{
		if(temp->roll==n)
		{
			if(temp==*ptr)
			{
				temp->next->prev=temp->prev;
				*ptr=temp->next;
			}
			else
			{
				pre->next=temp->next;
				temp->next->prev=temp->prev;
			}
			free(temp);
			temp=NULL;
			return;
		}
		else
		{
			pre=temp;
			temp=temp->next;
		}
	}
	printf("INVALID DATA\n");
}

void add_middle(struct st ** ptr)
{
	struct st *temp;
	temp=(struct st *)malloc(sizeof(struct st));
	printf("enter the detail\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);
	if((*ptr==0)||(temp->roll < (*ptr)->roll))
	{
		temp->prev=*ptr;
		if(temp->prev!=0)
		{
			temp->prev=(*ptr)->prev;
			(*ptr)->prev=temp;
		}
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st * last=*ptr;
		while((last->next!=0)&&(temp->roll > last->next->roll))
			last=last->next;
		temp->prev=last;
		temp->next=last->next;
		last->next=temp;
	}
}

