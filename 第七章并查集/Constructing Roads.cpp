/*************************************************************************************************************************************
Problem Description
There are N villages, which are numbered from 1 to N, 
and you should build some roads such that every two villages can connect to each other. 
We say two village A and B are connected, if and only if there is a road between A and B, 
or there exists a village C such that there is a road between A and C, and C and B are connected. 
We know that there are already some roads between some villages and your job is the build some roads such that 
all the villages are connect and the length of all the roads built is minimum.
Input
The first line is an integer N (3 <= N <= 100), which is the number of villages. 
Then come N lines, the i-th of which contains N integers, 
and the j-th of these N integers is the distance (the distance should be an integer within [1, 1000]) between village i and village j.
Then there is an integer Q (0 <= Q <= N * (N + 1) / 2). Then come Q lines, each line contains two integers a and b (1 <= a < b <= N), 
which means the road between village a and village b has been built.
Output
You should output a line contains an integer, 
which is the length of all the roads to be built such that all the villages are connected, and this value is minimum. 
Sample Input
3
0 990 692
990 0 179
692 179 0
1
1 2
Sample Output
179
****************************************************************************************************************************************/
//������С�������� ������������ķ�㷨�� 
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int dis[MAX][MAX];

int prim(int n)	//����ķ�㷨 
{
	int sum = 0, temp, minIndex; 
	int cost[n + 1];
	bool visit[n + 1];
	fill(visit, visit + n + 1, false);	//��ʼ�����е㶼δ���뼯��S 
	visit[1] = true;				//��һ���㲢�뼯��S 
	for(int i = 1; i <= n; i++)		//����S������������ľ��ǵ�һ���㵽������ľ��� 
	{
		cost[i] = dis[1][i];		
	}

	for(int i = 1; i < n; i++)	//��ʣ��n - 1���㲢����ͨͼ 
	{
		temp = INT_MAX;
		for(int j = 1; j <= n; j++)			//�ҳ��ͼ���S����С����ĵ㣬������С�����������ʣ����õ�ͼ���S�ĸñ�һ������С�������� 
		{
			if(!visit[j] && cost[j] < temp)		
			{
				temp = cost[j];	
				minIndex = j;
			}	
		}
		
		if(temp == INT_MAX)	//û���ҵ�˵�����е㶼��ͨ�������� 
			break;
			
		sum += cost[minIndex];	//�͸��� 
		visit[minIndex] = true;		//�õ��ѷ��� 
		
		//�µĵ㲢����ͨͼ�����cost�������ϼ����µĵ�󣬸õ㵽������ľ�������ȵ�ǰ���ϵ�������ľ���С������� 
		for(int j = 1; j <= n; j++)
		{
			if(!visit[j] && dis[minIndex][j] < cost[j])		
				cost[j] = dis[minIndex][j];	
		}	
	}
	
	return sum;	
}

int main()
{
	int n, q, a, b;
	while(cin >> n)
	{
		for(int i = 1; i <= n; i++)			//�ڽӾ���ķ�ʽ�洢������Ȩͼ 
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> dis[i][j];	
			}	
		} 
	
		cin >> q;
		while(q--)
		{
			cin >> a >> b;					//�����Ѿ���ͨ�ĵ㣬���¾��� 
			dis[a][b] = dis[b][a] = 0;
		}
	
	
		cout << prim(n) << endl;
	} 

	return 0;	
} 
