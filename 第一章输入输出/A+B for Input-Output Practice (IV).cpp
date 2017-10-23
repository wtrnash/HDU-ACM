/*******************************************************************************************
Problem Description
Your task is to Calculate the sum of some integers.
Input:
Input contains multiple test cases. Each test case contains a integer N, 
and then N integers follow in the same line.
 A test case starting with 0 terminates the input and this test case is not to be processed.
Output:
For each group of input integers you should output their sum in one line, 
and with one line of output for each line in input.
Sample Input:
4 1 2 3 4
5 1 2 3 4 5
0 
Sample Output:
10
15
**********************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum;
	int num;
	cin >> n;
	while(n != 0)                      //读n,如果n不为0，则用num读取数据，并记录到和sum中，输出sum，再读取n，直到n为0则结束读取。 
	{
		sum = 0;
		for(int i = 0;i < n;i++)
		{
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
		cin >> n;
	}
	return 0;
}

