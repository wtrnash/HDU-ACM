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
//�����֮ǰ��Number Sequence ˼·��ȫһ�£���Ϊf(n)�ܲ��ܱ�3����������f(n-1) �� f(n-2)�����ģ� 
//����ʵ��������f(n-1) % 3 �Լ� f(n-2) %3 �ĺ;����ģ�����ʵ����һ����3 * 3 = 9����ϣ�֮��һ����
//����ѭ�������Ծͺ�Number Sequence�����һ��������ѭ���ڼ��ɡ�  
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int  n;
	int begin, end;
	bool flag;    //��־��¼�Ƿ��ҵ�ѭ���� 
	vector<int> f;	//��������¼f��ֵ 

	while (cin >> n)		
	{
		flag = false;
		f.push_back(7);			//��f[0],f[1]��ʼ���� 
		f.push_back(11);

		for (int i = 2;i <= n; i++)
		{
			f.push_back((f[i - 1] +  f[i - 2]) % 3);		//�洢 ��3 ���������ɣ���Ϊ���ֻҪ�ж��Ƿ�����3������������3�Ĳ��ֶ�������ȥ 
			for (int j = 1; j < i; j++)
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
				if(f[begin - 1 + (n - end) % (end - begin + 1)])  	//����ѭ���ڵ�λ��ȷ��n��ֵ�� ���Ϊ�棬��˵����Ϊ0��û�г���3 
					cout << "no" << endl;
				else
					cout << "yes" << endl;
					
			else
				if(f[begin - 1 + (end - begin + 1)] )		//��ѭ���ڱ�����ʱ��Ӧ�ü���ѭ���ڵĳ��ȶ�����0����Ϊ��һ��ѭ����ǰ�����ݲ�һ��ѭ���� 
					cout << "no" << endl;
				else
					cout << "yes" << endl; 
		}
		else
			if(f[n])
				cout << "no" << endl;
			else
				cout << "yes" << endl;

		f.clear();					//�������Ҫ���vector 
	}
	return 0;	
} 
