//==============================================================
// Copyright © 2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
// ============================================================


#include <iostream>
#include<chrono>
#include<tbb/blocked_range.h>
#include<tbb/parallel_for.h>
using namespace tbb;

const long int n = 90;
long long int fib[n];

//-----------------fibonacci parallelism-----------//
 class fibonacci
 {

    public:
        void operator()(const blocked_range<long long int> r)const
        {
            for (int i = r.begin(); i != r.end(); ++i)
            {
                fib[i] = fib[i - 1] + fib[i - 2];
                std::cout << fib[i] << "\n";
            }
        }
 };

/*void fibonacci()
{
    fib[0] = 0;
    fib[1] = 1;

    tbb::parallel_for(tbb::blocked_range<size_t>(2,n), [&](tbb::blocked_range<size_t> r)
    { 
            for (size_t i = r.begin(); i <= r.end(); i++)
            {
                fib[i] = fib[i - 1] + fib[i - 2];
                std::cout << fib[i] << "\n";
            }
    });
    
 }*/


int main()
{
    fib[0] = 0;
    fib[1] = 1;
    auto start = std::chrono::system_clock::now();
    parallel_for(blocked_range<long long int>(2,n),fibonacci());
    //fibonacci();
    auto end = std::chrono::system_clock::now();

    std::cout << "\nTime taken for " <<n<<" numbers :"<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms";

    return 0;
}