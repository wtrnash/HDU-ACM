/******************************************************************************
Problem Description
Your task is to calculate the sum of some integers.
Input:
Input contains an integer N in the first line, and then N lines follow. 
Each line starts with a integer M, and then M integers follow in the same line.
Output:
For each group of input integers you should output their sum in one line, 
and you must note that there is a blank line between outputs.
Sample Input:
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3
Sample Output:
10

15

6
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int m;
	int sum, num;
	cin >> n;
	//因为输出的行之间有空行，要保证最后一个输出之后没有空行，则可以对第一组用例单独输出，之后每组用例先输出一个空行后再输出sum 
	if(n > 0)
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

	for(int i = 1; i < n; i++)
	{
		cin >> m;
		sum = 0;
		for(int j = 0; j < m; j++)
		{
			cin >> num;
			sum += num;
		}
		cout << endl;
		cout << sum << endl;
	}
	
	return 0;
}
