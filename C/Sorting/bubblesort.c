#include<stdio.h>
#define MAX 10

int arr[MAX];

void bubble_sort()
{
    int temp;
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printarray(int arr[])
{
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    printf("Enter 10 array elements: ");
    for(int i = 0; i < MAX; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Before bubble sort\n");
    printarray(arr);
    printf("\n");
    bubble_sort();
    printf("After bubble sort\n");
    printarray(arr);

    return 0;
}