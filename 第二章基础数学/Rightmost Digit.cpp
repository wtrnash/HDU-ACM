/************************************************************************************************
Problem Description
Given a positive integer N, you should output the most right digit of N^N.
Input
The input contains several test cases. 
The first line of the input is a single integer T which is the number of test cases.
 T test cases follow.<br>Each test case contains a single positive integer N(1<=N<=1,000,000,000).
Output
For each test case, you should output the rightmost digit of N^N.
Sample Input
2
3
4
Sample Output
7
6
***************************************************************************************************/ 
//因为求N^N时如果N过大会超过int 乃至 long long 的范围，所以不能暴力做 
//主要利用快速幂算法来简化指数，当指数为奇数时，将指数减1，结果乘上底数；
//指数为偶数时，底数乘以自身，底数除以2， 达到大大简化计算的目的
//因为是求最右边一位，所以在计算中需要不断将结果对10取余 
#include <iostream>
using namespace std;

//快速幂
int myPow(int base, int index)
{
	int result = 1;
	base %= 10;
	while(index > 0)
	{
		if(index % 2)	//指数为奇数 
		{
			result *= base % 10;
			result %= 10;
		}
		index /= 2;
		base *= base % 10;
		base %= 10;
	}
	return result;
}
 
int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cout << myPow(n, n) << endl;
	}
	
	return 0;
}
