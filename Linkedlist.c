#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("Memory not allocated\n");
		return NULL;
	}
	
	return temp;
}

NODE insert_beg(int item,NODE first)
{
	NODE new;
	new=getnode();
	new->value=item;
	new->next=NULL;
	if(first==NULL)
	{
		return new;
	}
	else
	{
		new->next=first;
		first=new;
		return first;
	}
}

NODE insert_end(int item,NODE first)
{
	NODE new,last;
    new=getnode();
	new->value=item;
	new->next=NULL;
	if (first==NULL)
	{
		return new;
	}
	if(first->next==NULL)	
	{
		first->next=new;
		return first;
	}
	last=first;
	while(last->next!=NULL)
		last=last->next;
	last->next=new;
	return first;
}

NODE insert_pos(NODE first,int item,int pos)
{
	int count=1;
	int val=item;
	NODE new,curr,prev;
	new=getnode();
	new->value=item;
	new->next=NULL;
	
	if(first==NULL && pos==1)
	return new;
	prev=NULL;
	curr=first;
	while(count!=pos && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
		count++;
	}
	
	if(count==pos)
	{
		prev->next=new;
		new->next=curr;
		return first;
	}
	
	if(curr==NULL)
	{
		printf("position not fount\n");
		return first;
	}
	
	if(first!=NULL && pos==1)
	first=insert_beg(val,first);
	return first;
}

void display(NODE first)
{
	NODE temp;
	temp=first;
	while(temp!=NULL)
	{
		printf("value stored in node=%d\n",temp->value);
		temp=temp->next;
	}
}

void main()
{
	NODE first=NULL;
	int choice,pos,item;
	while(1)
	{
		printf("\n1.INSERT AT THE BEGINNING  2.INSERT AT THE END  3.INSERT AT A GIVEN POSITION  4.DISPLAY\n");
		printf("\n ENTER YOUR CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter the value to be inserted at the begining\n");
			       scanf("%d",&item);
			       first=insert_beg(item,first);
			       break;
			    
			case 2:printf("\nEnter the value to be inserted at the end\n");
			       scanf("%d",&item);
			       first=insert_end(item,first);
                   break;
                   
            case 3:printf("\nEnter the value to be inserted\n");
			       scanf("%d",&item);
			       printf("\nEnter the position at which item should be inserted \n");
			       scanf("%d",&pos);
			       first=insert_pos(first,item,pos);
			       break;
			        
			case 4:display(first);
			       break;
			         
		    default:exit(0);
			        
		}
		
	}
}