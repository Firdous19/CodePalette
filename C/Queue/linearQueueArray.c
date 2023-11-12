// Linear Queue implementation in C

#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

// Function to perform enqueue operation
void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

// Function to perform dequeue operation
void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

int items[SIZE], front = -1, rear = -1;

int main() {

    int ch,x;

    while(1)
    {
        system("cls");
        printf("\n ======== Menu =========\n");
        printf("\n Press 1 for INSERT(Enqueue) \n");
        printf("\n Press 2 for DELETE(Dequeue) \n");
        printf("\n Press 3 for DISPLAY \n");
        printf("\n Press 4 for EXIT \n");

        printf("\n\nEnter your choice ::  ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the value to be inserted  : ");
                scanf("%d",&x);
                enQueue(x);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("\n Wrong Choice !!! Give option from the menu");
        }
        fflush(stdin);
        printf("\n\n PRESS any key to Continue.......");
        getc(stdin);
    }
    return 0;
}








