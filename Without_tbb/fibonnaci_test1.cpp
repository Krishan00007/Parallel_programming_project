// fibonacci_test1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<chrono>
#include<iostream>

const int num = 90;
long long int fib[num];
//--------- simple fibonacci code----------//
void fibonacci_serial()
{
    fib[0] = 0;
    fib[1] = 1;
    //if (num == 0)
      //  std::cout<< f1;

    for (int i = 2; i <= num; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
       std::cout << fib[i]<<"\n";
    }
}

int main() 
{
    auto start = std::chrono::system_clock::now();
    fibonacci_serial();
    auto end = std::chrono::system_clock::now();
      std::cout<<"\nTime taken for "<<num<<"numbers :"<<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<" ms";

 
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
