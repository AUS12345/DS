# include<stdio.h>
# include<stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *front=0, *rear=0, *temp=0;
void enqueue()
{
    struct queue *newnode=0;
    newnode=(struct queue *)malloc(sizeof(struct queue));
    printf("\nenter element: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    if(front==0)
    {
        printf("underflow");
    }
    else
    {
        temp=front;
        printf("\nthe dequeued element is: %d",front->data);
        front=front->next;
        free(temp);
        if(front==0)
        {
            rear=0;
        }
    }
}
void peek()
{
    if(front==0)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("\nthe front element: %d",front->data);
    }
}
void display()
{
    if(front==0)
    {
        printf("\nunderflow");
    }
    else
    {
        temp=front;
        while(temp!=0)
        {
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int choice, ch=1;
    while(ch)
    {
        printf("\n1.enqueue()\n2.dequeue()\n3.peek()\n4.display()");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("\nINVALID OPTION");
        }
        printf("\n DO YOU WANT ANOTHER OPTION");
        scanf("%d",&ch);
    }
    return 0;
}
