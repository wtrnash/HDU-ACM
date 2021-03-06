/***********************************************************************************************
Problem Description
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。
请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
Input
输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。
Output
对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。
Sample Input
2
1 2
3 6
Sample Output
1
3
************************************************************************************************/
//简单的递推求解，到达第i(i >= 3)个蜂房的路线数等于第i-1个加第i-2个的路线数，然后打表来做即可。
//要注意要用long long来储存，用Int会溢出 
#include <iostream>
using namespace std;

int main()
{
	long long f[51];
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i < 51; i++)
		f[i] = f[i - 1] + f[i - 2];
		
	int n, a, b;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << f[b - a + 1] << endl;
	}
	
	return 0;	
} 



