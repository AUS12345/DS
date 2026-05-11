# include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=0, *temp=0, *tail=0;
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
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
            tail->next=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
}
void display()
{
    temp=head;
    do
    {
        printf("  %d",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
void insert_front()
{
	struct node *enode=0;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter newely created node data: ");
    scanf("%d",&enode->data);
    enode->next=0;
    enode->next=head;
    head=enode;
    tail->next=head;
    display();
    printf("\n %d",tail->next->data);
}
void insert_end()
{
	struct node *enode=NULL;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter newely created node data: ");
    scanf("%d",&enode->data);
    enode->next=NULL;
    if(head==NULL){
        head=tail=enode;
        tail->next=head;
    }
    else{
        tail->next=enode;
        tail=enode;
        tail->next=head;
    }
    display();
    printf("\n%d",tail->next->data);
}
void insert_pos()
{
	int i,pos;
	printf("\nenter position: ");
	scanf("%d",&pos);
	struct node *enode=0;
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newely created data: ");
	scanf("%d",&enode->data);
	enode->next=0;
	if(head==0)
	{
		head=tail=enode;
		tail->next=head;
	}
	else if(pos==1)
	{
		enode->next=head;
		head=enode;
		tail->next=head;
	}
	else
	{
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	enode->next=temp->next;
	temp->next=enode;
	}
	display();
	printf("\n%d",tail->next->data);
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
