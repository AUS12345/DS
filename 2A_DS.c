#include <stdio.h>

struct student
{
    int rno;
    char name[20];
    int marks;
};

int main()
{
    struct student s1, s2;

    printf("Enter roll number: ");
    scanf("%d", &s1.rno);

    getchar();  // consume leftover newline

    printf("Enter name: ");
    fgets(s1.name, sizeof(s1.name), stdin);

    printf("Enter marks: ");
    scanf("%d", &s1.marks);

    s2 = s1;  // copy structure

    printf("\n--- Copied Student Details ---\n");
    printf("Roll Number : %d\n", s2.rno);
    printf("Name        : %s", s2.name);
    printf("Marks       : %d\n", s2.marks);

    return 0;
}
