#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <name> <marks1> <marks2> ...\n", argv[0]);
        return 1;
    }

    char *name = argv[1];
    int total = 0;
    int subjects = argc - 2;
    int i;

    printf("\n--- Student Details ---\n");
    printf("Name     : %s\n", name);
    printf("Subjects : %d\n", subjects);

    for (i = 2; i < argc; i++)
    {
        int mark = atoi(argv[i]);
        printf("Subject %d : %d\n", i - 1, mark);
        total += mark;
    }

    printf("Total    : %d\n", total);
    printf("Average  : %.2f\n", (float)total / subjects);

    return 0;
}
