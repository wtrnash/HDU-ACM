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
		if(n % 2 == 0)						//�õȲ�������͹�ʽ�����ʱҪע�⣬��Ȼsum����int��Χ�ڣ������� (1+n) * n����int�ķ�Χ�������ж���ż�Ժ��ȳ���2�����˷��ɱ�������� 
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

