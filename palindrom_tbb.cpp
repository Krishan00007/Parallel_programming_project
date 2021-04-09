// palindrom_tbb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<chrono>
#include <iostream>
#include<string.h>
#include <tbb/parallel_for.h>
#include<tbb/blocked_range.h>

using namespace std;
using namespace tbb;

int len, i, x,flag = 1;
char str[50];

class palindrom
{

 public:
	 void operator()(blocked_range<int> r)const
	 {

		 for (i = r.begin(), x = len - 1; i <= r.end(); i++, x--)
		 {
			 if (str[i] != str[x])
			 {
				 flag = 2;
				 break;

			 }

			 if (flag == 1)
			 {
				 cout << "\nstring is palindrome";
				 break;
			 }
			 //if (flag == 2)
			// {
				// cout << "\nstring is not palindrome";
				 //break;
			 //}

		/* if (flag == 1)
		 {
			 cout <<" string is palindrome";
		 }
		 else
		 {
			 cout << "\nString is not a palindrome\n";
		 }*/

		 }
	 }

};
int main()
{
	cout << "Enter a string :";
	cin.getline(str, 50);
	len = strlen(str);


	auto start = chrono::steady_clock::now();
	parallel_for(blocked_range<int>(0,len/2), palindrom());
	auto end = chrono::steady_clock::now();


	cout << "\nTime Taken :"<< chrono::duration_cast<chrono::microseconds>(end - start).count() <<" microseconds\n";
	return 0;
}




