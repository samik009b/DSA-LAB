#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

void queuePush()
{
    if (rear == SIZE - 1)
    {
        printf("\narray overflowwwwwwwwwwwwwwwwwwwwwwwwww\n");
    }
    else
    {
        int value;
        printf("enter the element : ");
        scanf("%d", &value);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void queuePop()
{
    if (front == -1 || front > rear)
    {
        printf("\nqueue underflowwwwwwwwwwwwwwwwwwwwwwwww\n");
    }
    else
    {
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n\n");
        return;
    }

    printf("\nyour queue :");
    for (int i = front; i <= rear; i++)
    {

        printf("%d ", queue[i]);
    }
    printf("\n\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("1 - insertion\n");
        printf("2 - deletion\n");
        printf("3 - exit\n");
        printf("your choice : ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            queuePush();
            displayQueue();
            break;

        case 2:
            queuePop();
            displayQueue();
            break;

        case 3:
            printf("termination successful");
            exit(0);

        default:
            printf("enter a valid choice");
            break;
        }
    }

    return 0;
}