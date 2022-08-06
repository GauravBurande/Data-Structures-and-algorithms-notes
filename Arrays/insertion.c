#include<stdio.h>

void display(int arr[], int n);
int indInsertion(int arr[], int size, int element, int capacity, int index);

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;
    display(arr, 5);
    indInsertion(arr, size, element, 100, index);
    size++ ;
    display(arr, size);

    return 0;
}

void display(int arr[], int n)
{
    // code for traversal
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // code for insertion
    if(size>=capacity)
    {
        return -1;
    }
    for (int i = size-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}