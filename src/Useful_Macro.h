
#ifndef USEFUL_MACRO
#define USEFUL_MACRO

#define OMP_NUM_OF_THREADS std::atoi(getenv("OMP_NUM_THREADS"))
#define OMP_THREAD_LABEL omp_get_thread_num()

#endif