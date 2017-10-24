/**************************************************************************************
Problem Description
���еĶ������£����еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�
Input
���������ж��飬ÿ��ռһ�У�����������n��n<10000����m(m<1000)��ɣ�n��m�ĺ�����ǰ������
Output
����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС����
Sample Input
81 4
2 2
Sample Output
94.73
3.41
****************************************************************************************/
//ÿ�������ѭ��m�β��϶��Լ���������ӾͿ����ˡ� 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	double sum, term;
	while(cin >> n >> m)
	{
		sum = 0;
		term = n;
		for(int i = 0;i < m; i++)
		{
			sum += term;
			term = 	sqrt(term);
		}	
		cout << fixed << setprecision(2) << sum << endl;
	}	
	return 0;	
} 
