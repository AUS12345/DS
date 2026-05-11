# include<stdio.h>
# define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue()
{
    int a;
    if(rear==MAX-1)
    {
        printf("\noverflow");
    }
    else
    {
        printf("\nenter element: ");
        scanf("%d",&a);
        if(front==-1&&rear==-1)
        {
            rear=front=0;
            queue[rear]=a;
        }
        else
        {
            rear++;
            queue[rear]=a;
        }
    }
}
    void dequeue()
    {
        if(front==-1)
        {
            printf("\nunderflow");
        }
        else
        {
        	if(front==rear)
        	{
        		printf("\nthe deleted element: %d",queue[front]);
        		front=rear=0;
			}
			else
			{
				printf("\nthe dequeued element: %d",queue[front]);
				front++;
			}
		}
    void peek()
    {
        if(front==-1)
        {
            printf("\nunderflow");
        }
        else
        {
            printf("\nthe front element id: %d",queue[front]);
        }
    }
    void display()
    {
        if(front==-1)
        {
            printf("\nunderflow");
        }
        else
        {
            for(int i=front;i<=rear;i++)
            {
                printf("\n%d",queue[i]);
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
                printf("\n INVALID OPTION");
            }
            printf("\nDO YOU WANT ANOTHER OPTION");
            scanf("%d",&ch);
        }
        return 0;
    }
