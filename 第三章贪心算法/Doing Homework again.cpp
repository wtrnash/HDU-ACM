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
//��Ϊ���Ҫ�۳��ķ������٣������Ȱ������ߵ����򣬷�����ͬʱ��deadline�����������
//����󣬴������һ����ҵ��ʼ����������deadlineһֱ��ǰ������û�пյ��죬�оͷŽ�ȥ�������¸���ҵ�� 
//��һ����ҵdeadlineǰ��������춼�а�����ҵʱ������ҵ��û�취����ˣ��۳��ķ����ͼ��ϸ���ҵ�ķ����� 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Homework
{
	int deadline;
	int score;	
};

bool compare(Homework h1, Homework h2)	//�ȸ��ݷ����Ӹߵ������򣬷�����ͬ������ǰ������ 
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
	bool isFree[1001];		//��¼�����Ƿ��ѱ���ҵռ�� 
	vector<Homework> v;
	Homework temp;
	int score;	//��¼�ܵķ��� 
	cin >> t;
	int k;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		score = 0;
		fill(isFree, isFree + 1001, true); 	//���Ϊtrue
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
		
		sort(v.begin(), v.end(), compare);	//���� 
		for(int i = 0;i < v.size(); i++)		//��˳�����δ���ÿ����ҵ 
		{
			for(k = v[i].deadline; k > 0; k--)		//�Ӹ�deadlineһֱ��ǰ��Ѱ�ҿյ��� 
			{
				if(isFree[k])			//�пյ������򽫸���ҵ�Ž�����ȥ��������ѭ�� 
				{
					isFree[k] = false;
					break; 
				}
			}
			if(k == 0)			//Ϊ0˵��ѭ�������꣬˵��û�ҵ��յ�λ�ã�����Ҫ�۳�����ҵ�ķ��� 
			{
				score += v[i].score;
			}
		} 
		
		cout << score << endl;	
	}	
	
} 
