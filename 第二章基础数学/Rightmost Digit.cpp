/************************************************************************************************
Problem Description
Given a positive integer N, you should output the most right digit of N^N.
Input
The input contains several test cases. 
The first line of the input is a single integer T which is the number of test cases.
 T test cases follow.<br>Each test case contains a single positive integer N(1<=N<=1,000,000,000).
Output
For each test case, you should output the rightmost digit of N^N.
Sample Input
2
3
4
Sample Output
7
6
***************************************************************************************************/ 
//��Ϊ��N^Nʱ���N����ᳬ��int ���� long long �ķ�Χ�����Բ��ܱ����� 
//��Ҫ���ÿ������㷨����ָ������ָ��Ϊ����ʱ����ָ����1��������ϵ�����
//ָ��Ϊż��ʱ����������������������2�� �ﵽ���򻯼����Ŀ��
//��Ϊ�������ұ�һλ�������ڼ�������Ҫ���Ͻ������10ȡ�� 
#include <iostream>
using namespace std;

//������
int myPow(int base, int index)
{
	int result = 1;
	base %= 10;
	while(index > 0)
	{
		if(index % 2)	//ָ��Ϊ���� 
		{
			result *= base % 10;
			result %= 10;
		}
		index /= 2;
		base *= base % 10;
		base %= 10;
	}
	return result;
}
 
int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cout << myPow(n, n) << endl;
	}
	
	return 0;
}
