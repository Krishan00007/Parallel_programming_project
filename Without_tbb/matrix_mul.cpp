// vs_test_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include<iostream>
#include<chrono>

using namespace std;
const int SIZE = 1000; // for size*size matrix
void MultiplyMatricesSequential(double a[][SIZE], double b[][SIZE], double ans[][SIZE]);
int i, j, k;
//double s;
double a[SIZE][SIZE], b[SIZE][SIZE], ans[SIZE][SIZE];
/*
 *
 */
int main() {
    // assign the numbers for matrix a and b
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            ans[i][j] = 0.0;
        }
    }
    auto start = chrono::high_resolution_clock::now();
    MultiplyMatricesSequential(a, b, ans);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Sequential Method time elapsed for SIZE " << SIZE << " : ";
    cout << elapsed.count() << "s\n";

    return 0;
}

void MultiplyMatricesSequential(double a[][SIZE], double b[][SIZE], double ans[][SIZE])
{
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            for (k = 0; k < SIZE; ++k)
                ans[i][j] += a[i][k] * b[k][j];
            //s = 0.0;
        }

    }
    // double duration = timer.stop();
    // timer.printTime(duration);

}
