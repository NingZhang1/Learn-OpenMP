#include "Useful_Macro.h"
#include "IncludeFile.h"

void foo1()
{
#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp task
            {
#pragma omp task
                {
                    printf("Hello.\n"); /// It is possible that a child task gets executed after the generating task has finished.
                }
                printf("Hi.\n");
            }

            printf("Hej.\n");
        } /// there will be a barrier here

        printf("Goodbye.\n");
    }
}

void foo2()
{
#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp task
            {
#pragma omp task
                printf("Hello.\n");

#pragma omp taskwait /// wait for all child tasks to finish

                printf("Hi.\n");
            }

            printf("Hej.\n");
        }

        printf("Goodbye.\n");
    }
}

int main()
{
    foo1();
    foo2();
    return 0;
}