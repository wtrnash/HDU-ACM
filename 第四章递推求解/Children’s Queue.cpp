/*************************************************************************************************************************************
Problem Description
There are many students in PHT School. One day, the headmaster whose name is PigHeader wanted all students stand in a line.
 He prescribed that girl can not be in single. In other words, either no girl in the queue or more than one girl stands side by side. 
 The case n=4 (n is the number of children) is like FFFF, FFFM, MFFF, FFMM, MFFM, MMFF, MMMM
 Here F stands for a girl and M stands for a boy. 
 The total number of queue satisfied the headmaster’s needs is 7. 
 Can you make a program to find the total number of queue with n children?
Input
There are multiple cases in this problem and ended by the EOF. 
In each case, there is only one integer n means the number of children (1<=n<=1000)
Output
For each test case, there is only one integer means the number of queue satisfied the headmaster’s needs.
Sample Input
1
2
3
Sample Output
1
2
4
***************************************************************************************************************************************/
/*首先是递归求解， 
设：F(n)表示n个人的合法队列，则：
	按照最后一个人的性别分析，他要么是男，要么是女，所以可以分两大类讨论：
	1、如果n个人的合法队列的最后一个人是男，则对前面n-1个人的队列没有任何限制，他只要站在最后即可，所以，这种情况一共有F(n-1);
2、如果n个人的合法队列的最后一个人是女，则要求队列的第n-1个人务必也是女生，这就是说，限定了最后两个人必须都是女生，这又可以分两种情况：
2.1、如果队列的前n-2个人是合法的队列，则显然后面再加两个女生，也一定是合法的，这种情况有F(n-2);
2.2、但是，难点在于，即使前面n-2个人不是合法的队列，加上两个女生也有可能是合法的，当然，这种长度为n-2的不合法队列，不合法的地方必须是尾巴，就是说，这里说的长度是n-2的不合法串的形式必须是“F(n-4)+男+女”，这种情况一共有F(n-4).

处理完递归后，因为n最大值为1000，当n过于大时，会超出long long的范围，所以需要用大数来做 

*/
#include <iostream>
#include <string> 
using namespace std;

string add(string a, string b)	//用string实现大数相加 
{
	int i, j;
	if(a.length() < b.length())
	{
		string temp = a;
		a = b;
		b = temp;	
	}	
	
	for(i = a.length() - 1, j = b.length() - 1; j >= 0; i--, j--)	//低位开始相加 
	{
		a[i] = a[i] + (b[j] - '0');
	}
	
	for(i = a.length() - 1; i > 0; i--) //处理进位 
	{
		if(a[i] > '9')
		{
			a[i] -= 10;
			a[i - 1]++;	
		} 
	}
	
	if(a[0] > '9')
	{
		a[0] -= 10;
		a = "1" + a;
	}
	
	return a;
}

int main()
{
	string f[1001];
	f[0] = "1";
	f[1] = "1";
	f[2] = "2";
	f[3] = "4";
	for(int i = 4; i < 1001; i++)
		f[i] = add(add(f[i - 1], f[i - 2]), f[i - 4]);
		
	int n;
	while(cin >> n)
		cout << f[n] << endl;
 	
	
	return 0;	
} 
