# include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=0,*temp=0;
void create()
{
    struct node *newnode=0;
    int i,n;
    printf("\nenter n size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter node %d data: ",i+1);
    scanf("%d",&newnode->data);
    newnode->link=0;
    if(head==0)
    {
        temp=head=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=newnode;
    }
    }
}
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("  %d",temp->data);
        temp=temp->link;
    }
}
void deletefront()
{
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		temp=head;
		head=temp->link;
		free(temp);
	}
	printf("\nAFTER DELETING THE FIRST NODE: ");
	display();
}
void deleteend()
{
	struct node *prevnode=0;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else if(head->link==0)
	{
		free(head);
		head=0;
	}
	else
	{
		temp=head;
		while(temp->link!=0)
		{
			prevnode=temp;
			temp=temp->link;
		}
		free(temp);
		prevnode->link=NULL;
	}
	printf("\nAFTER DELETING THE LAST NODE: ");
	display();
}
void deletepos()
{
	struct node *prevnode=0;
	int pos,i;
	printf("\nenter position: ");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else if(pos==1)
	{
		temp=head;
		head=temp->link;
		free(temp);
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}
		prevnode=temp->link;
		temp->link=prevnode->link;
		free(prevnode);
	}
	printf("\nAFTER DELETING THE NODE AT PARTICULAR POSITION");
	display();
}
int main()
{
	create();
	display();
	int choice,ch;
	printf("\n1. DELETING NODE AT FRONT");
	printf("\n2. DELETING NODE AT END");
	printf("\n3. DELETING NODE AT PARTICULAR POSITION");
	{
	printf("\nenter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			deletefront();
			break;
		case 2:
			deleteend();
			break;
		case 3:
			deletepos();
			break;
		default:
			printf("\nINVALID OPTION");
	}
	printf("\nDO YOU WANT ANOTHER OPTION (YES:1||NO:0): ");
	scanf("%d",&ch);
}
	return 0;
}
