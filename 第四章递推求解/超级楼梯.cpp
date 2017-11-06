/***********************************************************************************************************
Problem Description
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
Input
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
Output
对于每个测试实例，请输出不同走法的数量
Sample Input
2
2
3
Sample Output
1
2
***********************************************************************************************************/
//简单的递推问题，走到第M级的走法只和走到第M-1级和第M-2级的走法有关，因为走到第M-1级后走一步到M，而走到第M-2级后走两步到M，
//所以走到第M级的走法f(M) = f(M-1) + f(M-2)。然后f(1) = 1, f(2) = 1 就可以做了。但是直接用递归做会超时，
//题目只要求前40级，所以可以利用数组先全部求出来，等输入相应的M时直接用数组对应下标的值即可。 
#include <iostream>
using namespace std;


int main()
{
	int f[41];
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= 40; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		cout << f[m] << endl;	
	}	
	
	return 0;
} 
