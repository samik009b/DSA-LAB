#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push operation
void push(int value)
{
    if (top == SIZE - 1)
        printf("Stack Overflow! Cannot push %d\n", value);
    else
        stack[++top] = value;
}

// Pop operation
void pop()
{
    if (top == -1)
        printf("Stack Underflow! Cannot pop.\n");
    else
        top--;
}

// Display operation
void display()
{
    if (top == -1)
        printf("Stack is empty.\n");
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice! Please enter 1-3.\n");
        }
    }

    return 0;
}
