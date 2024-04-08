#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdlib.h>
void HandleCheck(void *handle)
{
    if(!handle)
    {
        perror("handle");
        exit(EXIT_FAILURE);
    }
}

void StartCalculator()
{
    void *handle;
    int statusExit = -1, option;
    double (*operation)(double, double);
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
                handle = dlopen("libadd.so", RTLD_LAZY);
                if(!handle)
                {
                    perror("handle");
                    exit(EXIT_FAILURE);
                }

                operation = dlsym(handle, "add");

                printf("a + b = %lf\n", operation(a, b));
                
                break;

            case 2:
                handle = dlopen("libmin.so", RTLD_LAZY);
                if(!handle)
                {
                    perror("handle");
                    exit(EXIT_FAILURE);
                }

                operation = dlsym(handle, "min");

                printf("a - b = %lf\n", operation(a, b));
                
                break;
            
            case 3:
                handle = dlopen("libmult.so", RTLD_LAZY);
                if(!handle)
                {
                    perror("handle");
                    exit(EXIT_FAILURE);
                }

                operation = dlsym(handle, "mult");

                printf("a * b = %lf\n", operation(a, b));   
                
                break;

            case 4:
                handle = dlopen("libdiv.so", RTLD_LAZY);
                if(!handle)
                {
                    perror("handle");
                    exit(EXIT_FAILURE);
                }
                
                operation = dlsym(handle, "div");
                
                printf("a / b = %lf\n", operation(a, b));
            
                break;
                
            defualt:
                printf("Wrong menu section!\n");
        }
    }

    dlclose(handle);
}
int main()
{
    StartCalculator();
}