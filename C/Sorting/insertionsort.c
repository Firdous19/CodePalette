#include<stdio.h>
#include<math.h>
#define MAX 10

int arr[MAX];

// Insertion Sort algorithm
void insertion_sort(int arr[])
{
    int i, j , key;
    for(j = 1; j < MAX; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

// Function to display the array elements after sorting
void display()
{
    printf("After sorting\n");
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int i;
    printf("Enter 10 numbers that you want to sort: ");
    for(i = 1;i <= MAX; i++)
        scanf("%d",&arr[i]);
    insertion_sort(arr);
    display();
    return 0;
}