/***************************************************************************************
Problem Description
There are another kind of Fibonacci numbers: F(0) = 7, F(1) = 11, F(n) = F(n-1) + F(n-2).
Input:
Input consists of a sequence of lines, each containing an integer n. (n < 1,000,000).
Output:
Print the word "yes" if 3 divide evenly into F(n).Print the word "no" if not.
Sample Input:
0
1
2
3
4
5
Sample Output:
no
no
yes
no
no
no
********************************************************************************************/
//这题和之前的Number Sequence 思路完全一致，因为f(n)能不能被3整除还是由f(n-1) 和 f(n-2)决定的， 
//而且实质上是由f(n-1) % 3 以及 f(n-2) %3 的和决定的，所以实际上一共有3 * 3 = 9种组合，之后一定会
//出现循环，所以就和Number Sequence这道题一样处理，找循环节即可。  
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int  n;
	int begin, end;
	bool flag;    //标志记录是否找到循环节 
	vector<int> f;	//向量来记录f的值 

	while (cin >> n)		
	{
		flag = false;
		f.push_back(7);			//将f[0],f[1]初始化好 
		f.push_back(11);

		for (int i = 2;i <= n; i++)
		{
			f.push_back((f[i - 1] +  f[i - 2]) % 3);		//存储 对3 的余数即可，因为最后只要判断是否整除3，所以能整除3的部分都可以舍去 
			for (int j = 1; j < i; j++)
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
				if(f[begin - 1 + (n - end) % (end - begin + 1)])  	//根据循环节的位置确定n的值。 如果为真，则说明不为0，没有除尽3 
					cout << "no" << endl;
				else
					cout << "yes" << endl;
					
			else
				if(f[begin - 1 + (end - begin + 1)] )		//当循环节被除尽时，应该加上循环节的长度而不是0，因为第一个循环节前的内容不一定循环。 
					cout << "no" << endl;
				else
					cout << "yes" << endl; 
		}
		else
			if(f[n])
				cout << "no" << endl;
			else
				cout << "yes" << endl;

		f.clear();					//处理完后要清空vector 
	}
	return 0;	
} 
