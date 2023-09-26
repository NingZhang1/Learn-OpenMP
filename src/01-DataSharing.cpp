
#include "Useful_Macro.h"
#include "IncludeFile.h"

void foo1()
{
    printf("Variables declared outside the parallel construct are shared by default.\n");

    int number = 1;

#pragma omp parallel
    {

#pragma omp task
        {
            printf("I think the number is %d.\n", number);
            number++;
        }
    }
}

void foo2()
{
    printf("If we move the variable number inside the parallel construct, then the variable becomes firstprivate by default.\n");

#pragma omp parallel
    {
        int number = 1;

#pragma omp task
        {
            printf("I think the number is %d.\n", number);
            number++;
        }
    }
}

void foo3()
{
    printf("We can also use the explicit dara sharing rules.\n");

    int number = 1;
#pragma omp parallel firstprivate(number)
    {

#pragma omp task
        {
            printf("I think the number is %d.\n", number);
#pragma omp critical
            {
                number++;
            }
        }
    }
}

#include <stdio.h>

int main()
{
    foo1();
    foo2();
    foo3();

    return 0;
}