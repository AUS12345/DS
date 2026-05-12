#include<stdio.h>

void mergesort(int a[], int start, int end);
void merge(int a[], int start, int mid, int end);

int main()
{
    int n,i;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    mergesort(a,0,n-1);

    printf("Elements after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

void mergesort(int a[], int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;

        mergesort(a,start,mid);
        mergesort(a,mid+1,end);

        merge(a,start,mid,end);
    }
}

void merge(int a[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    int b[end-start+1];

    while(i <= mid && j <= end)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    while(i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while(j <= end)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for(i=start;i<=end;i++)
    {
        a[i] = b[i];
    }
}
