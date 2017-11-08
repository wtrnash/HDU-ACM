/*******************************************************************************************************************************************************
Problem Description
A subsequence of a given sequence is the given sequence with some elements (possible none) left out. 
Given a sequence X = <x1, x2, ..., xm> another sequence Z = <z1, z2, ..., zk> is a subsequence of X if there exists a strictly increasing sequence
 <i1, i2, ..., ik> of indices of X such that for all j = 1,2,...,k, xij = zj. 
 For example, Z = <a, b, f, c> is a subsequence of X = <a, b, c, f, b, c> with index sequence <1, 2, 4, 6>.
  Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
The program input is from a text file. Each data set in the file contains two strings representing the given sequences. 
The sequences are separated by any number of white spaces. The input data are correct. 
For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
Sample Input
abcfbc abfcab
programming contest 
abcd mnp
Sample Output
4
2
0
********************************************************************************************************************************************************/
//��̬�滮����֮ǰ�Ӵ��ȺõĻ����ϣ������ǰ�����ַ�a[i]��b[j]һ���������ڵĹ������Ⱦ���֮ǰ�����Ӵ��ĳ���dp[i-1][j-1]��1�������ǰ��һ����
//�򳤶�Ϊ dp[i][j-1]��dp[i-1][j]�����ֵ 
#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int main()
{
	string a, b;
	while(cin >> a >> b)
	{
		int **dp = new int*[a.size()];
		for(int i = 0; i < a.size(); i++)
		{
			dp[i] = new int[b.size()];
		}
		
		for(int i = 0; i < b.size(); i++)			//��ʼ����һ�У�Ҳ���ǰ�a�е�һ����ĸ��b��ÿ�������бȺ� 
		{
			if(a[0] == b[i])
			{
				for(int j = i; j < b.size(); j++)
					dp[0][j] = 1;
				
				break;
			}
			else
				dp[0][i] = 0;
		}
		
		for(int i = 0; i < a.size(); i++)			//��ʼ����һ�У�Ҳ���ǰ�b�е�һ����ĸ��a��ÿ�������бȺ� 
		{
			if(b[0] == a[i])
			{
				for(int j = i; j < a.size(); j++)
					dp[j][0] = 1;
				
				break;
			}
			else
				dp[i][0] = 0;
		}
		
		//����ʣ��� 
		for(int i = 1; i < a.size(); i++)
		{
			for(int j = 1; j < b.size(); j++)
			{
				if(a[i] == b[j])	//���һ�����򳤶ȵ��ڲ�������ǰi,j������ĸ�� �����еĹ������ȼ���1 
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else  					//��һ���Ļ������������ aǰi-1����ĸ�� b ��j����ĸ�Ĺ�������  ��   aǰi����ĸ�� b��j-1����ĸ�Ĺ������� �Ľϴ�ֵ 
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	
				}
			}
		}
		
		cout << dp[a.size() - 1][b.size() - 1] << endl; 
	}
	return 0;	
} 
