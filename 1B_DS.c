#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)   // returns pivot index
{
    int pivot = a[low];
    int start = low + 1;
    int end = high;

    while (start <= end)
    {
        while (start <= high && a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
            swap(&a[start], &a[end]);
    }
    swap(&a[low], &a[end]);
    return end;   // return instead of global
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(a, low, high);  
        quicksort(a, low, loc - 1);
        quicksort(a, loc + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
