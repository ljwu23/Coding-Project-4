#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

void add(int n, float *x, float *y);

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(5);

#define MAX_PROBLEM_SIZE 1 << 29  //  256M
   std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};
   
   std::vector<float> x(MAX_PROBLEM_SIZE, 1.0f);
   std::vector<float> y(MAX_PROBLEM_SIZE, 2.0f);

   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      printf("Working on problem size N=%lld \n", n);

      // Insert your timer code here
      auto START_TIMER = std::chrono::steady_clock::now();

      // Invoke the add function to perform the addition
      add(n, x.data(), y.data());

      // Insert your end timer code here, and print out elapsed time for this problem size
      auto END_TIMER = std::chrono::steady_clock::now();
      
      auto ELAPSED_TIME = std::chrono::duration_cast<std::chrono::duration<double>>(END_TIMER - START_TIMER).count();

      printf(" Elapsed time = %.5f seconds \n", ELAPSED_TIME);
   } // end loop over problem sizes
}

