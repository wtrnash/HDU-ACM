/*******************************************************************************
Problem Description
Your task is to calculate the sum of some integers.
Input:
Input contains multiple test cases, and one case one line. 
Each case starts with an integer N, and then N integers follow in the same line.
Output:
For each test case you should output the sum of N integers in one line, 
and with one line of output for each line in input. <br>
Sample Input:
4 1 2 3 4
5 1 2 3 4 5
Sample Output:
10
15
********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	int num;
	while(cin >> n)					//读取n，每组读取n个数。直到文件结束符。 
	{
		sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
	return 0;
}
 
