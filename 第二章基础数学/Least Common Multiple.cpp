/*****************************************************************************************************
Problem Description
The least common multiple (LCM) of a set of positive integers is the smallest positive integer
which is divisible by all the numbers in the set. 
For example, the LCM of 5, 7 and 15 is 105.
Input:
Input will consist of multiple problem instances. 
The first line of the input will contain a single integer indicating the number of problem instances. 
Each instance will consist of a single line of the form m n1 n2 n3 ... nm 
where m is the number of integers in the set and n1 ... nm are the integers.
 All integers will be positive and lie within the range of a 32-bit integer.
Output:
For each problem instance, output a single line containing the corresponding LCM. 
All results will lie in the range of a 32-bit integer.
Sample Input:
2
3 5 7 15
6 4 10296 936 1287 792 1
Sample Output:
105
10296
*********************************************************************************************************/

#include <iostream>
using namespace std;

//辗转相除法也就是欧几里得法求最大公约数，使用递归形式 
int gcd(int big, int small)         
{
	if(small == 0)
		return big;
		
	return gcd(small, big % small);	
} 

int main()
{
	int number1, number2, divisor;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		number1 = 1;
		for(int j = 0;j < m; j++)						//每次读入一个数后，和之前算出的所有数的最小公倍数一起求出最大公约数，再求出此两个数的最小公倍数 
		{                                                 //第一次读时，就是求1 和 该数的最小公倍数。  
			cin >> number2;                               //最小公倍数通过求出最大公约数，然后两个数相乘除以最大公倍数就是最小公约数         
			if(number2 > number1)
				divisor = gcd(number2, number1);
			else
				divisor = gcd(number1, number2);
			
			number1 = number1 / divisor * number2;	
		}	
		cout << number1 << endl; 
	}	
	return 0;
} 
