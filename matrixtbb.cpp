//==============================================================
// Copyright © 2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================
//#include <CL/sycl.hpp>
#include <iostream>
#include<chrono>
#include<tbb/parallel_for.h>
#include <tbb/blocked_range.h>

using namespace std;
using namespace tbb;

const int n = 2000;

double a[n][n];
double b[n][n];
double c[n][n];
//double sum;
int i, j, k;

class Multiply
{
public:
    void operator()(blocked_range<int> r) const {
        for (i = r.begin(); i != r.end(); ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < n; ++k) {
                    c[i][j]+= a[i][k] * b[k][j];
                     //sum = 0.0;
                }
            }
        }
    }
};


int main()
{
    // Initialize buffers.
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            c[i][j] = 0.0;
        }
    }
    // Compute matrix multiplication.
        // C <- C + A x B
    auto start = chrono::high_resolution_clock::now();
    parallel_for(blocked_range<int>(0, n), Multiply()); 
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double>elapsed = end - start;

    cout << "Parallel Elapsed time for "<< n <<" is :"<< elapsed.count() << " s\n";

    return 0;
}
