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
void insertfront()
{
	struct node *newnode2=0;
	newnode2 =(struct node*)malloc(sizeof(struct node));
	printf("\nenter newly created node data: ");
	scanf("%d",&newnode2->data);
	newnode2->link = head;
	head=newnode2;
	printf("\nAFTER INSERTING NODE AT FRONT: ");
	display();
}
void insertend()
{
	struct node *newnode2=0;
	newnode2=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newnode data: ");
	scanf("%d",&newnode2->data);
	temp=head;
	while(temp->link!=0)
	{
		temp=temp->link;
	}
	temp->link=newnode2;
	newnode2->link=NULL;
	printf("\nAFTER INSERTING NODE AT END: ");
	display();
}
void insertpos()
{
	struct node *enode=0;
	int i,pos;
	printf("\nenter position: ");
	scanf("%d",&pos);
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newly created node data: ");
	scanf("%d",&enode->data);
	enode->link=NULL;
	if(pos==1)
	{
		enode->link=head;
		head=enode;	
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}
		enode->link=temp->link;
		temp->link=enode;
	}
	printf("\nAFTER INSERTING THE NODE AT PARTICUAR POSITION: ");
	display();
}
int main()
{
	create();
	display();
	int choice,ch;
	printf("\n1. INSERTING NODE AT FRONT");
	printf("\n2. INSERTING NODE AT END");
	printf("\n3. INSERTING NODE AT PARTICULAR POSITION");
	{
	printf("\nenter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insertfront();
			break;
		case 2:
			insertend();
			break;
		case 3:
			insertpos();
			break;
		default:
			printf("\nINVALID OPTION");
	}
	printf("\nDO YOU WANT ANOTHER OPTION (YES:1||NO:0): ");
	scanf("%d",&ch);
}
	return 0;
}
