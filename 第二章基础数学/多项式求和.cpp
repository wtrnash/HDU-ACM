/**********************************************************************************************
Problem Description
多项式的描述如下：1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...现在请你求出该多项式的前n项的和。
Input
输入数据由2行组成，首先是一个正整数m（m<100），表示测试实例的个数，第二行包含m个正整数，
对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。
Output
对于每个测试实例n，要求输出多项式前n项的和。每个测试实例的输出占一行，结果保留2位小数。
Sample Input
2
1 2
Sample Output
1.00
0.50
************************************************************************************************/
//简单题，对奇数项偶数项分别处理即可 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int m, n;
	double sum;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> n;
		sum = 0;
		for(int i = 1;i <= n; i++)
		{
			if(i % 2)
			{
				sum += (double) 1 / i; 
			}
			else
				sum -= (double) 1 / i;
		}
		cout << fixed << setprecision(2) << sum << endl;
	}
	
	return 0;
}
