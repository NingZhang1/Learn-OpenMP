#include "Useful_Macro.h"
#include "IncludeFile.h"

int main()
{

#pragma omp parallel

    {

#pragma omp task /// every thread will execute the followng code once!
        {
            printf("Thread %d\n", OMP_THREAD_LABEL);
            printf("Hello world!\n");
        }
    }
    return 0;
}