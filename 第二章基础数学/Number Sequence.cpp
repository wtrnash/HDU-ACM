/********************************************************************************************************
Problem Description
A number sequence is defined as follows:f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
Given A, B, and n, you are to calculate the value of f(n).
Input:
The input consists of multiple test cases.
Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000).
Three zeros signal the end of input and this test case is not to be processed.
Output:
For each test case, print the value of f(n) on a single line.<br>
Sample Input:
1 1 3
1 2 10
0 0 0
Sample Output:
2
5
************************************************************************************************************/
//一道很容易想到用递归的题目，但一旦n非常大，则会超出题目要求的限制时间，所以需要对题目进行理解。
//我们可以看到f(n)最后都要mod 7，也就是f(n)只有7个值，而f(n)是由f(n-1)和f(n-2)决定的，所以一共7*7=49组合，最多经过49次计算，
//一定能找到f(i)和f(i-1) 与 f(j) 和 f(j-1)相等，也就是找到了循环节，这样n再大就可以通过之前找到的循环节直接处理了

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, n;
	int begin, end;
	bool flag;    //标志记录是否找到循环节 
	vector<int> f;	//向量来记录f的值 

	cin >> a >> b >> n;
	while (a != 0 || b != 0 || n != 0)		//三者都为0则跳出循环 
	{
		flag = false;
		f.push_back(1);			//将f[0],f[1],f[2]初始化好 
		f.push_back(1);
		f.push_back(1);

		for (int i = 3;i <= n; i++)
		{
			f.push_back((a * f[i - 1] + b * f[i - 2]) % 7);
			for (int j = 2; j < i; j++)
			{
				if (f[j] == f[i] && f[j - 1] == f[i - 1])		//寻找循环节 
				{
					flag = true;
					begin = j - 1;    //第一个循环节的开始位置 
					end = i - 2;	  //第一个循环节的结束位置
					break;
				}
			}
			if (flag)
				break;
		}

		if (flag)
		{
			if ((n - end) % (end - begin + 1))
				cout << f[begin - 1 + (n - end) % (end - begin + 1)] << endl;		//根据循环节的位置确定n的值 
			else
				cout << f[begin - 1 + (end - begin + 1)] << endl;		//当除尽时，应该加上循环节的长度而不是0，因为第一个循环节前的内容不一定循环
		}
		else
			cout << f[n] << endl;

		f.clear();					//处理完后要清空vector 
		cin >> a >> b >> n;
	}
	return 0;
}
