#include "Useful_Macro.h"
#include "IncludeFile.h"

void task_within_forloop(int n)
{
#pragma omp parallel
#pragma omp single /// a single thread to generate tasks
    {
        for (int i = 0; i < n; i++)
        {

#pragma omp task

            printf("Thread %d print %d\n", OMP_THREAD_LABEL, i);
        }
    }
}

void taskloop_within_forloop(int n, int grain_size)
{
    printf("Do %d worth with grain size %d\n", n, grain_size);

#pragma omp parallel
#pragma omp single /// a single thread to generate tasks
    {
#pragma omp taskloop grainsize(grain_size)
        for (int i = 0; i < n; i++)
        {
            printf("Thread %d print %d\n", OMP_THREAD_LABEL, i);
        }
    }
}

int main()
{
    task_within_forloop(10);

    taskloop_within_forloop(16, 3);

    return 0;
}