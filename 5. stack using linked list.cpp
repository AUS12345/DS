# include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=0, *temp=0;
void push()
{
    struct node *newnode=0;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter node data: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop()
{
    if(top==0)
    {
        printf("\nstack is empty");
    }
    else
    {
        temp=top;
        printf("\npoped element: %d",temp->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    if(top==0)
    {
        printf("\nstack is underflow");
}
else
{
    temp=top;
    while(temp!=0)
    {
    printf("\n%d",temp->data);
    temp=temp->next;
    }
}
}
void peek()
{
    if(top==0)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("%d",top->data);
    }
}
int main()
{
    int choice, ch=1;
    while(ch)
    {
        printf("\n1.push()\n2.pop()\n3.peek()\n4.display()");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("\nINVALID OPTION: ");
        }
        printf("\nDO YOU WANT TO ENTER ANOTHER OPTION: ");
        scanf("%d",&ch);
    }
    return 0;
}
