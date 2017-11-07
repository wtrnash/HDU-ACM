/*************************************************************************************************************************************
Problem Description
There are many students in PHT School. One day, the headmaster whose name is PigHeader wanted all students stand in a line.
 He prescribed that girl can not be in single. In other words, either no girl in the queue or more than one girl stands side by side. 
 The case n=4 (n is the number of children) is like FFFF, FFFM, MFFF, FFMM, MFFM, MMFF, MMMM
 Here F stands for a girl and M stands for a boy. 
 The total number of queue satisfied the headmaster��s needs is 7. 
 Can you make a program to find the total number of queue with n children?
Input
There are multiple cases in this problem and ended by the EOF. 
In each case, there is only one integer n means the number of children (1<=n<=1000)
Output
For each test case, there is only one integer means the number of queue satisfied the headmaster��s needs.
Sample Input
1
2
3
Sample Output
1
2
4
***************************************************************************************************************************************/
/*�����ǵݹ���⣬ 
�裺F(n)��ʾn���˵ĺϷ����У���
	�������һ���˵��Ա��������Ҫô���У�Ҫô��Ů�����Կ��Է����������ۣ�
	1�����n���˵ĺϷ����е����һ�������У����ǰ��n-1���˵Ķ���û���κ����ƣ���ֻҪվ����󼴿ɣ����ԣ��������һ����F(n-1);
2�����n���˵ĺϷ����е����һ������Ů����Ҫ����еĵ�n-1�������Ҳ��Ů���������˵���޶�����������˱��붼��Ů�������ֿ��Է����������
2.1��������е�ǰn-2�����ǺϷ��Ķ��У�����Ȼ�����ټ�����Ů����Ҳһ���ǺϷ��ģ����������F(n-2);
2.2�����ǣ��ѵ����ڣ���ʹǰ��n-2���˲��ǺϷ��Ķ��У���������Ů��Ҳ�п����ǺϷ��ģ���Ȼ�����ֳ���Ϊn-2�Ĳ��Ϸ����У����Ϸ��ĵط�������β�ͣ�����˵������˵�ĳ�����n-2�Ĳ��Ϸ�������ʽ�����ǡ�F(n-4)+��+Ů�����������һ����F(n-4).

������ݹ����Ϊn���ֵΪ1000����n���ڴ�ʱ���ᳬ��long long�ķ�Χ��������Ҫ�ô������� 

*/
#include <iostream>
#include <string> 
using namespace std;

string add(string a, string b)	//��stringʵ�ִ������ 
{
	int i, j;
	if(a.length() < b.length())
	{
		string temp = a;
		a = b;
		b = temp;	
	}	
	
	for(i = a.length() - 1, j = b.length() - 1; j >= 0; i--, j--)	//��λ��ʼ��� 
	{
		a[i] = a[i] + (b[j] - '0');
	}
	
	for(i = a.length() - 1; i > 0; i--) //�����λ 
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
