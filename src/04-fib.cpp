#include "Useful_Macro.h"
#include "IncludeFile.h"

int fib(int n)
{
#pragma omp critical
    {
        printf("Thread %d\n", OMP_THREAD_LABEL);
    }

    if (n < 2)
        return n;

    int i, j;

#pragma omp task default(none) shared(i) firstprivate(n)
    i = fib(n - 1);

#pragma omp task default(none) shared(j) firstprivate(n) /// may be executed by other threads!
    j = fib(n - 2);

#pragma omp taskwait

    return i + j;
}

int main()
{
#pragma omp parallel
#pragma omp single
    printf("fib(10) = %d\n", fib(10));

    return 0;
}