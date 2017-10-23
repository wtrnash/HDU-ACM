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
//һ���������뵽�õݹ����Ŀ����һ��n�ǳ�����ᳬ����ĿҪ�������ʱ�䣬������Ҫ����Ŀ������⡣
//���ǿ��Կ���f(n)���Ҫmod 7��Ҳ����f(n)ֻ��7��ֵ����f(n)����f(n-1)��f(n-2)�����ģ�����һ��7*7=49��ϣ���ྭ��49�μ��㣬
//һ�����ҵ�f(i)��f(i-1) �� f(j) �� f(j-1)��ȣ�Ҳ�����ҵ���ѭ���ڣ�����n�ٴ�Ϳ���ͨ��֮ǰ�ҵ���ѭ����ֱ�Ӵ�����

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, n;
	int begin, end;
	bool flag;    //��־��¼�Ƿ��ҵ�ѭ���� 
	vector<int> f;	//��������¼f��ֵ 

	cin >> a >> b >> n;
	while (a != 0 || b != 0 || n != 0)		//���߶�Ϊ0������ѭ�� 
	{
		flag = false;
		f.push_back(1);			//��f[0],f[1],f[2]��ʼ���� 
		f.push_back(1);
		f.push_back(1);

		for (int i = 3;i <= n; i++)
		{
			f.push_back((a * f[i - 1] + b * f[i - 2]) % 7);
			for (int j = 2; j < i; j++)
			{
				if (f[j] == f[i] && f[j - 1] == f[i - 1])		//Ѱ��ѭ���� 
				{
					flag = true;
					begin = j - 1;    //��һ��ѭ���ڵĿ�ʼλ�� 
					end = i - 2;	  //��һ��ѭ���ڵĽ���λ��
					break;
				}
			}
			if (flag)
				break;
		}

		if (flag)
		{
			if ((n - end) % (end - begin + 1))
				cout << f[begin - 1 + (n - end) % (end - begin + 1)] << endl;		//����ѭ���ڵ�λ��ȷ��n��ֵ 
			else
				cout << f[begin - 1 + (end - begin + 1)] << endl;		//������ʱ��Ӧ�ü���ѭ���ڵĳ��ȶ�����0����Ϊ��һ��ѭ����ǰ�����ݲ�һ��ѭ��
		}
		else
			cout << f[n] << endl;

		f.clear();					//�������Ҫ���vector 
		cin >> a >> b >> n;
	}
	return 0;
}
