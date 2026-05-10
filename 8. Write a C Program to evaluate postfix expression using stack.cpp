#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

int main()
{
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0')
    {
        // Ignore spaces and newline
        if(exp[i] == ' ' || exp[i] == '\n')
        {
            i++;
            continue;
        }
        if(isdigit(exp[i]))
        {
            int num = 0;
            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            top = top + 1;
            stack[top] = num;

           continue;
        }
        else
        {
            int b, a;

            b = stack[top];
            top = top - 1;

            a = stack[top];
            top = top - 1;

            switch(exp[i])
            {
                case '+':
                    top = top + 1;
                    stack[top] = a + b;
                    break;

                case '-':
                    top = top + 1;
                    stack[top] = a - b;
                    break;

                case '*':
                    top = top + 1;
                    stack[top] = a * b;
                    break;

                case '/':
                    top = top + 1;
                    stack[top] = a / b;
                    break;
            }
        }
        i++;
    }

    printf("Result = %d", stack[top]);

    return 0;
}
