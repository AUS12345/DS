# include<stdio.h>
# include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=0,*temp=0,*tail=0;
void create()
{
    struct node *newnode=0;
    int i,n;
    printf("\nenter n size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf("\nenter node %d data: ",i+1);
    	scanf("%d",&newnode->data);
    	newnode->prev=NULL;
    	newnode->next=NULL;
    	if(head==NULL)
    	{
    		head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
	}
}
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("  %d",temp->data);
        temp=temp->next;
    }
}
void delete_front()
{
	if(head==NULL)
	{
		printf("\nLIST IS empty");
	}
	else
	{
	head=head->next;
	free(head->prev);
	head->prev=NULL;
	}
	printf("\n AFTER DELETING, THE LIST IS: ");
	display();
}
void delete_end()
{
	if(head==NULL)
	{
		printf("\nLIST IS empty");
	}
	else if(head->next==NULL)
	{
		free(head);
		head=tail=NULL;
	}
	else
	{
		tail=tail->prev;
		free(tail->next);
		tail->next=0;
	}
	printf("\nAFTER DELETING");
	display();
}
void delete_pos()
{
	int i,pos;
	printf("\nenter position: ");
	scanf("%d",&pos);
	if(head==0)
	{
		printf("\nLIST ID EMPTY");
	}
	else if(pos==1)
	{
		head=head->next;
		free(head->prev);
		head->prev=NULL;
	}
	else
	{
		temp=head;
		for(i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
	printf("\nAFTER DELETING");
	display();
}
int main()
{
    create();
	printf("\nBEFORE OPERATING ANY OPERATION:");
	display();
    int choice,ch=1;
	printf("\n1. DELETING NODE AT FRONT");
	printf("\n2. DELETING NODE AT END");
	printf("\n3. DELETING NODE AT PARTICULAR POSITION");

	while(ch)
	{
	printf("\nenter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			delete_front();
			break;
		case 2:
			delete_end();
			break;
		case 3:
			delete_pos();
			break;
		default:
			printf("\nINVALID OPTION");
	}
	printf("\nDO YOU WANT ANOTHER OPTION (YES:1||NO:0): ");
	scanf("%d",&ch);
}
    return 0;
}
