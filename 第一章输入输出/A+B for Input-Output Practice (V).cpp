/************************************************************************
Problem Description
Your task is to calculate the sum of some integers.
Input:
Input contains an integer N in the first line, 
and then N lines follow. Each line starts with a integer M, 
and then M integers follow in the same line. 
Output:
For each group of input integers you should output their sum in one line, 
and with one line of output for each line in input.
Sample Input:
2
4 1 2 3 4
5 1 2 3 4 5
Sample Output:
10
15
**************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	int num, sum;
	cin >> n;
	for(int i = 0; i < n; i++)					//n个用例，每个用例读m个数进行相加，所以用两个嵌套的for循环即可 
	{
		cin >> m;
		sum = 0;
		for(int j = 0; j < m; j++)
		{
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
	return 0;	
} 
