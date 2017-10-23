/****************************************************
Problem Description
给你n个整数，求他们中所有奇数的乘积。
Input:
输入数据包含多个测试实例，每个测试实例占一行，
每行的第一个数为n，表示本组数据一共有n个，
接着是n个整数，你可以假设每组数据必定至少存在一个奇数。
Output:
输出每组数中的所有奇数的乘积，对于测试实例，输出一行。
Sample Input:
3 1 2 3
4 2 3 4 5
Sample Output:
3
15
******************************************************/ 

#include <iostream>
using namespace std;

int main()
{
	int num;
	int sum;
	int n;
	while(cin >> n)
	{
		sum = 1;
		for(int i = 0; i < n; i++)			//每组用例n个数，判断是否是奇数，是奇数则和sum相乘。 
		{
			cin >> num;
			if(num % 2)
				sum *= num;
		}
		cout << sum << endl;
	}
	return 0;
}
