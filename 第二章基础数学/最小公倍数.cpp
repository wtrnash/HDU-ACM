/***************************************************************
Problem Description
给定两个正整数，计算这两个数的最小公倍数。
Input
输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.
Output
对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。
Sample Input
10 14
Sample Output
70
****************************************************************/
//利用辗转相除法算出最大公约数后，最小公倍数通过两个数的乘积除以最大公约数算出 
#include <iostream>
using namespace std;

int gcd(int big, int small)		//辗转相除法的递归形式求最大公约数 
{
	if(small == 0)
		return big;
	else
		return gcd(small, big % small);
}

int main()
{
	int number1, number2;
	int divisor;
	while(cin >> number1 >> number2)
	{
		if(number1 > number2)
			divisor = gcd(number1, number2);
		else
			divisor = gcd(number2, number1);
			
		cout << number1 / divisor * number2 << endl;
	}
	
	return 0;	
}
