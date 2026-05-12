#include<stdio.h>
int i;
void radixsort(int a[],int n);
int max(int a[],int n)
{
	int maxi=a[0];
	for(int i=0;i<n;i++)
	{
		if (maxi<a[i])
		{
			maxi=a[i];
		}
	}
	return maxi;
}
int main()
{
	printf("enter the size of the array");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("enter the array");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	printf("the sorted array is ");
	for(int i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	return 0;
}
void countSort(int a[], int n, int exp)
{
    int output[n];      
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }


    for(int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixsort(int a[], int n)
{
    int m_no = max(a, n);

    for(int exp = 1; m_no / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
