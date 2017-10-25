/*********************************************************************************************************************
Problem Description
Ignatius has just come back school from the 30th ACM/ICPC.
Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework.
If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test.
And now we assume that doing everyone homework always takes one day. 
So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.
Input
The input contains several test cases. 
The first line of the input is a single integer T that is the number of test cases. 
T test cases follow. Each test case start with a positive integer N(1<=N<=1000) which indicate the number of homework.
Then 2 lines follow. The first line contains N integers that indicate the deadlines of the subjects, 
and the next line contains N integers that indicate the reduced scores.
Output
For each test case, you should output the smallest total reduced score, one line per test case.
Sample Input
3
3
3 3 3
10 5 1
3
1 3 1
6 2 3
7
1 4 6 4 2 4 3
3 2 1 7 6 5 4
Sample Output
0
3
5
***********************************************************************************************************************/
//因为最后要扣除的分数最少，所以先按分数高低排序，分数相同时按deadline早晚进行排序。
//排完后，从排序第一个作业开始处理，从他的deadline一直往前，看有没有空的天，有就放进去，处理下个作业。 
//当一个作业deadline前面的所有天都有安排作业时，该作业就没办法完成了，扣除的分数就加上该作业的分数。 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Homework
{
	int deadline;
	int score;	
};

bool compare(Homework h1, Homework h2)	//先根据分数从高到低排序，分数相同则日期前的在先 
{
	if(h1.score > h2.score)
		return true;
	else if(h1.score == h2.score)
	{
		if(h1.deadline < h2.deadline)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	int t, n;
	bool isFree[1001];		//记录该天是否已被作业占据 
	vector<Homework> v;
	Homework temp;
	int score;	//记录总的分数 
	cin >> t;
	int k;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		score = 0;
		fill(isFree, isFree + 1001, true); 	//填充为true
		v.clear();
		for(int j = 0; j < n; j++)
		{
			cin >> temp.deadline;
			v.push_back(temp);
		}	
		for(int j = 0; j < n; j++)
		{
			cin >> v[j].score;
		}
		
		sort(v.begin(), v.end(), compare);	//排序 
		for(int i = 0;i < v.size(); i++)		//按顺序依次处理每个作业 
		{
			for(k = v[i].deadline; k > 0; k--)		//从该deadline一直往前，寻找空的天 
			{
				if(isFree[k])			//有空的日子则将该作业放进该天去做，跳出循环 
				{
					isFree[k] = false;
					break; 
				}
			}
			if(k == 0)			//为0说明循环遍历完，说明没找到空的位置，则需要扣除该作业的分数 
			{
				score += v[i].score;
			}
		} 
		
		cout << score << endl;	
	}	
	
} 
