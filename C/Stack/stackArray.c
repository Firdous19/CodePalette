#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = data;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isFull()
{
    if(top == MAX -1)
    return 1;
    else 
    return 0;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top];
}

int isEmpty()
{
    if(top == -1)
    return 1;
    else 
    return 0;
}

void print()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Elements of stack are:\n");
        for (int i = top; i >=0; i--)
        {
            printf("%d\t", stack[top]);
            top--;
        }
    }
}

int main()
{
    int choice, data;

    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Print the top element\n");
        printf("4.Print all the elements of the stack\n");
        printf("5.Quit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to be pushed: \n");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Deleted element is %d\n", data);
                break;
            case 3:
                printf("The top most element of the stack is %d \n", peek());
                break;
            case 4: 
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice\n");
        }

        fflush(stdin);
        printf("\n\nPress any key to Continue...\n");
        getc(stdin);
    }
    return 0;
}