/****************************************************************************************
Problem Description
Your task is to Calculate a + b.
Input:
Input contains an integer N in the first line, and then N lines follow.
Each line consists of a pair of integers a and b, separated by a space, 
one pair of integers per line. 
Output:
For each pair of input integers a and b you should output the sum of a and b in one line,
and with one line of output for each line in input. <br>
Sample Input:
2
1 5
10 20
Sample Output:
6
30
*******************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n;
	while(n > 0)			//根据读入的n进行n次a+b运算 
	{
		cin >> a >> b;
		cout << a + b << endl;
		n--;
	}
	return 0;	
} 
