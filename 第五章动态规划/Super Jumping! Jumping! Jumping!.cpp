/**************************************************************************************************************************************
Nowadays, a kind of chess game called “Super Jumping! Jumping! Jumping!” is very popular in HDU.
Maybe you are a good boy, and know little about this game, so I introduce it to you now.
The game can be played by two or more than two players.
It consists of a chessboard（棋盘）and some chessmen（棋子）, and all chessmen are marked by a positive integer or “start” or “end”. 
The player starts from start-point and must jumps into end-point finally. 
In the course of jumping, the player will visit the chessmen in the path,
 but everyone must jumps from one chessman to another absolutely bigger 
 (you can assume start-point is a minimum and end-point is a maximum.). 
 And all players cannot go backwards. 
 One jumping can go from a chessman to next, also can go across many chessmen, 
 and even you can straightly get to end-point from start-point. Of course you get zero point in this situation. 
 A player is a winner if and only if he can get a bigger score according to his jumping solution. 
 Note that your score comes from the sum of value on the chessmen in you jumping path.
Your task is to output the maximum value according to the given chessmen list.
Input
Input contains multiple test cases. 
Each test case is described in a line as follow:
N value_1 value_2 …value_N It is guarantied that N is not more than 1000 and all value_i are in the range of 32-int.
A test case starting with 0 terminates the input and this test case is not to be processed.
Output
For each case, print the maximum according to rules, and one line one case.
Sample Input
3 1 3 2
4 1 2 3 4
4 3 3 2 1
0
Sample Output
4
10
3
*****************************************************************************************************************************************/
//求递增子序列的最大和。动态规划做。求出之前每个点包含当前点的递增子序列和，然后从所有点中找出最大的和。 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int answer;
	int n;
	int num[1001];
	int sum[1001];
	cin >> n;
	while(n != 0)
	{
		fill(sum, sum + 1001, 0); 
		num[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> num[i];
		}
		
		for(int i = 1; i <= n; i++)
		{
			answer = INT_MIN;
			
			for(int j = 0; j < i; j++)
			{
				if(num[j] < num[i])
				{
					answer = max(answer, sum[j]);
				}
			}
			
			sum[i] = answer + num[i];
		}
		
		
		answer = INT_MIN;
		for(int i = 0; i <= n; i++)
		{
			if(sum[i] > answer)
				answer = sum[i];
		}
		
		cout << answer << endl;
		
		cin >> n;
	}
	return 0;	
} 
