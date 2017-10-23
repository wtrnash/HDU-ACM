/***********************************************************************
Problem Description
Hey, welcome to HDOJ(Hangzhou Dianzi University Online Judge).
In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
Input:
The input will consist of a series of integers n, one integer per line.
Output:
For each case, output SUM(n) in one line, followed by a blank line. 
You may assume the result will be in the range of 32-bit signed integer.
Sample Input:
1
100
Sample Output:
1

5050

*************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum;
	while(cin >> n)
	{
		if(n % 2 == 0)						//用等差数列求和公式来求和时要注意，虽然sum是在int范围内，但可能 (1+n) * n超过int的范围，所以判断奇偶性后先除以2再做乘法可避免溢出。 
		{
			sum = (1 + n) * (n / 2);	
		} 
		else
		{
			sum = (1 + n) / 2 * n;
		}
		cout << sum << endl;
		cout << endl;
	}
	return 0;
}

