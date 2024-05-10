#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>


void add(int n, float *x, float *y)
{
    for (int i = 0; i < n; i++)
        y[i] = x[i] + y[i];
}

extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

/* The benchmarking program */
int main(int argc, char** argv) 
{
    std::cout << std::fixed << std::setprecision(5); // Set precision to 5

#define MAX_PROBLEM_SIZE 1 << 29  //  256M
    std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};

    std::vector<uint64_t> A(MAX_PROBLEM_SIZE);


    int64_t t;
    int n_problems = problem_sizes.size();

    /* For each test size */
    for (int64_t n : problem_sizes) 
    {
        printf("Working on problem size N=%lld \n", n);

        // start timer
        auto start_timer = std::chrono::steady_clock::now();

        add(n, &x[0], &y[0]);

        // end timer
        auto end_timer = std::chrono::steady_clock::now();

        // calculate elapsed time
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_timer - start_timer).count();

        printf("Elapsed time = %lld ms\n", elapsed_time);
    } // end loop over problem sizes

    return 0;
}


