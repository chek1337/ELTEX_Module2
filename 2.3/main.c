#include <stdio.h>

double add(double x, double y)
{
    return x+y;
}

double min(double x, double y)
{
    return x-y;
}

double mult(double x, double y)
{
    return x*y;
}

double div(double x, double y)
{
    return x/y;
}


void StartCalculator()
{
    int statusExit = -1, option;
    double (*operations[4])(double, double) = {add, min, mult, div};
    double a, b;
    printf("Calculator-Program\n");
    while(statusExit != 1)
    {
        printf("Enter two real numbers:\n");
        scanf("%lf %lf", &a, &b);
        printf("1) Addition\n");
        printf("2) Minus\n");
        printf("3) Multiplication\n");
        printf("4) Division\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("a + b = %lf\n", operations[0](a, b));
            break;
            case 2:
                printf("a - b = %lf\n", operations[1](a, b));
            break;
            case 3:
                printf("a * b = %lf\n", operations[2](a, b));
            break;
            case 4:
                printf("a / b = %lf\n", operations[3](a, b));
            break;
            defualt:
                printf("Wrong menu section!\n");
        }
    }
}
int main()
{
    StartCalculator();
}