#include <iostream>
#include <cmath>
#include <chrono>

// function to add the elements of two arrays
void add(int n, float *x, float *y)
{
    for (int i = 0; i < n; i++)
        y[i] = x[i] + y[i];
}

int main(void)
{
    int N = 1<<29;

    float *x = new float[N];
    float *y = new float[N];

    // initialize x and y arrays on the host
    for (int i = 0; i < N; i++) {
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    auto start_timer = std::chrono::steady_clock::now();

    add(N, x, y);

    auto end_timer = std::chrono::steady_clock::now();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_timer - start_timer).count();

    // Check for errors (all values should be 3.0f)
    float maxError = 0.0f;
    for (int i = 0; i < N; i++)
        maxError = std::fmax(maxError, std::fabs(y[i]-3.0f));
    std::cout << "Max error: " << maxError << std::endl;
    
    std::cout << "Elapsed time: " << elapsed_time << " milliseconds" << std::endl;

    // Free memory
    delete [] x;
    delete [] y;

    return 0;
}




