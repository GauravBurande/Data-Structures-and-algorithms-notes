#include<stdio.h>

int linearSearch(int arr[], int size, int element);
int binarySearch(int arr[], int size, int element);

int main()
{
    // unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);
    // int element;
    // printf("Enter the element: ");
    // scanf("%i", &element);
    // int searchIndex = linearSearch(arr, size, element);
    // printf("The element %i was found at index %i \n", element, searchIndex);

    // sorted array for binary search
    int arr[] = {1, 3, 5, 56, 64, 73, 74, 80, 83, 86, 91, 99, 101, 200, 323, 444};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the element: ");
    scanf("%i", &element);
    int searchIndex = binarySearch(arr, size, element);
    if(searchIndex>=0)
    {
        printf("The element %i was found at index %i \n", element, searchIndex);
    }
    else
    {
        printf("not found!");
    }
    return 0;
}

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
        return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    // start searching
    if (arr[low]==element)
    {
        return low;
    }
    if (arr[high]==element)
    {
        return high;
    }
    else
    {
        //  keep searching until low<=high converges
        while(low<=high)
        {
            mid = (low + high)/2;
            if(arr[mid]==element)
            {
                return mid;
            }
            if(arr[mid]<element)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        // searching ends
        return -1;
    }

}