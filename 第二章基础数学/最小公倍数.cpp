/***************************************************************
Problem Description
��������������������������������С��������
Input
�����������������ݣ�ÿ��ֻ��һ�У���������������1000��������.
Output
����ÿ����������������������������С��������ÿ��ʵ�����һ�С�
Sample Input
10 14
Sample Output
70
****************************************************************/
//����շת�����������Լ������С������ͨ���������ĳ˻��������Լ����� 
#include <iostream>
using namespace std;

int gcd(int big, int small)		//շת������ĵݹ���ʽ�����Լ�� 
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
