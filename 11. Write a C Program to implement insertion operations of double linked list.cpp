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
void insert_front()
{
	struct node *enode=0;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data for newely created node: ");
    scanf("%d",&enode->data);
    enode->prev=NULL;
    enode->next=NULL;
    head->prev=enode;
    enode->next=head;
    head=enode;
    printf("\nAFTER INSERTING NODE AT FRONT: ");
    display();
}
void insert_end()
{
	struct node *enode=NULL;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data for newely created node: ");
    scanf("%d",&enode->data);
    enode->next=0;
    enode->prev=0;
    tail->next=enode;
    enode->prev=tail;
    tail=enode;
    printf("\nAFTER INSERTING NODE AT END POSITION: ");
    display();
}
void insert_pos()
{
	struct node *enode=NULL;
	int pos,i;
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newely creates node data: ");
	scanf("%d",&enode->data);
	enode->prev=0;enode->next=0;
	printf("\nenter position: ");
	scanf("%d",&pos);
	if(pos==1)
	{
		enode->next=head;
		head->prev=enode;
		head=enode;
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		enode->next=temp->next;
		enode->prev=temp;
		temp->next=enode;
		enode->next->prev=enode;
	}
	printf("\nAFTER INSERTING A NODE AT POSITION: ");
	display();
}
int main()
{
    create();
	printf("\nBEFORE OPERATING ANY OPERATION:");
	display();
    int choice,ch;
	printf("\n1. INSERTING NODE AT FRONT");
	printf("\n2. INSERTING NODE AT END");
	printf("\n3. INSERTING NODE AT PARTICULAR POSITION");
	while(ch)
	{
	printf("\nenter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insert_front();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			insert_pos();
			break;
		default:
			printf("\nINVALID OPTION");
	}
	printf("\nDO YOU WANT ANOTHER OPTION (YES:1||NO:0): ");
	scanf("%d",&ch);
}
    return 0;
}
