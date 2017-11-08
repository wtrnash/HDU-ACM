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
//动态规划，在之前子串比好的基础上，如果当前两个字符a[i]和b[j]一样，则现在的公共长度就是之前两个子串的长度dp[i-1][j-1]加1，如果当前不一样，
//则长度为 dp[i][j-1]和dp[i-1][j]的最大值 
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
		
		for(int i = 0; i < b.size(); i++)			//初始化第一行，也就是把a中第一个字母和b的每个子序列比好 
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
		
		for(int i = 0; i < a.size(); i++)			//初始化第一列，也就是把b中第一个字母和a的每个子序列比好 
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
		
		//处理剩余的 
		for(int i = 1; i < a.size(); i++)
		{
			for(int j = 1; j < b.size(); j++)
			{
				if(a[i] == b[j])	//如果一样，则长度等于不包含当前i,j两个字母的 子序列的公共长度加上1 
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else  					//不一样的话，长度则等于 a前i-1个字母和 b 的j个字母的公共长度  与   a前i个字母和 b的j-1个字母的公共长度 的较大值 
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	
				}
			}
		}
		
		cout << dp[a.size() - 1][b.size() - 1] << endl; 
	}
	return 0;	
} 
