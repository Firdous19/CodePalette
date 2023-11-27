#include "stdio.h"
#define MAX 10

void selection_sort(int arr[])
{
    int min, temp;
    for (int i = 0; i < MAX; i++)
    {
        min = i;
        for (int j = i + 1; j < MAX; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void display(int *arr)
{
    for (int i = 0; i < MAX; i++)
        printf("%d ", *(arr + i));
}

int main()
{
    int arr[MAX];
    printf("Enter the array elements\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Selection Sort\n");
    display(arr);
    printf("\n");
    selection_sort(arr);
    printf("After Selection Sort\n");
    display(arr);
    printf("\nTime Complexity O(n^2)");
    return 0;
}