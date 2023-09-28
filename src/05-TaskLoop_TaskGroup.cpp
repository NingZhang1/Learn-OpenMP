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

struct alloc_data
{
public:
    alloc_data()
    {
        thread_label = OMP_THREAD_LABEL;
    }

    int thread_label;
};

void taskloop_within_forloop_and_malloc(int n, int grain_size)
{
    printf("Do %d worth with grain size %d\n", n, grain_size);

#pragma omp parallel
#pragma omp single /// a single thread to generate tasks
    {
        // #pragma omp taskloop grainsize(grain_size)
        for (int i = 0; i < n * n * n; i++)
        {
#pragma omp task
            {
                alloc_data *data = new alloc_data();
#pragma omp critical
                {
                    printf("Thread %d print %d, data 2 is created by thread %d\n", OMP_THREAD_LABEL, i, data->thread_label);
                }
                delete data;
            }
        }

        for (int i = 0; i < n * n; i++)
        {
#pragma omp task
            {
                alloc_data *data = new alloc_data();
#pragma omp critical
                {
                    printf("Thread %d print %d, data 1 is created by thread %d\n", OMP_THREAD_LABEL, i, data->thread_label);
                }
                delete data;
            }
        }

        for (int i = 0; i < n * n * n; i++)
        {
#pragma omp task /// not the same task
            {
                alloc_data *data = new alloc_data();
#pragma omp critical
                {
                    printf("Thread %d print %d, data 3 is created by thread %d\n", OMP_THREAD_LABEL, i, data->thread_label);
                }
                delete data;
            }
        }
    }
}

void taskloop_within_forloop_and_malloc2(int n, int grain_size)
{
    printf("Do %d worth with grain size %d\n", n, grain_size);

#pragma omp parallel
#pragma omp single /// a single thread to generate tasks
    {
#pragma omp taskloop grainsize(grain_size) /// there exist a barrier!
        for (int i = 0; i < n * n * n; i++)
        {

            alloc_data *data = new alloc_data();
#pragma omp critical
            {
                printf("Thread %d print %d, data 2 is created by thread %d\n", OMP_THREAD_LABEL, i, data->thread_label);
            }
            delete data;
        }

#pragma omp taskloop grainsize(grain_size)
        for (int i = 0; i < n * n; i++)
        {

            alloc_data *data = new alloc_data();
#pragma omp critical
            {
                printf("Thread %d print %d, data 1 is created by thread %d\n", OMP_THREAD_LABEL, i, data->thread_label);
            }
            delete data;
        }

#pragma omp taskloop grainsize(grain_size)
        for (int i = 0; i < n * n * n; i++)
        {

            alloc_data *data = new alloc_data();
#pragma omp critical
            {
                printf("Thread %d print %d, data 3 is created by thread %d\n", OMP_THREAD_LABEL, i, data->thread_label);
            }
            delete data;
        }
    }
}

int main()
{
    task_within_forloop(10);

    taskloop_within_forloop(16, 3);

    taskloop_within_forloop_and_malloc(4, 3);

    taskloop_within_forloop_and_malloc2(4, 3);

    return 0;
}