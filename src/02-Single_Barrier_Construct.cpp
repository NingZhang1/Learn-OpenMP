#include "Useful_Macro.h"
#include "IncludeFile.h"

void foo1()
{
#pragma omp parallel
    {
#pragma omp single nowait
        {
            printf("Thread %d\n", OMP_THREAD_LABEL);
#pragma omp task
            printf("Hello world!\n");
        }
    }
}

void foo2()
{
#pragma omp parallel
    {
#pragma omp task
        printf("Hello.\n");

#pragma omp barrier

#pragma omp task
        printf("Goodbye.\n");
    }
}

int main()
{
    foo1();
    foo2();
    return 0;
}