#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full! Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;  // circular increment
    }

    queue[rear] = value;
    printf("%d enqueued\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty! Underflow\n");
        return;
    }

    printf("Dequeued element: %d\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;  // last element deleted
    }
    else
    {
        front = (front + 1) % MAX;  // circular increment
    }
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;  // circular increment
    }
    printf("\n");
}

int main()
{
    int choice, ch = 1;

    while (ch)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek();    break;
            case 4: display(); break;
            default: printf("Invalid option!\n");
        }

        printf("Do you want another option? (1/0): ");
        scanf("%d", &ch);
    }
    return 0;
}
