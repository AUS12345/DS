#include <stdio.h>

int main()
{
    int n, i;
    int a[100];
    int tot = 0;
    float avg;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &a[i]);
        tot += a[i];
    }

    avg = (float)tot / n;

    printf("\n--- Result ---\n");
    printf("Total Marks  : %d\n", tot);
    printf("Average Marks: %.2f\n", avg);

    return 0;
}
