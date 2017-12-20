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
//计算最小生成树。 我利用了普里姆算法。 
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int dis[MAX][MAX];

int prim(int n)	//普里姆算法 
{
	int sum = 0, temp, minIndex; 
	int cost[n + 1];
	bool visit[n + 1];
	fill(visit, visit + n + 1, false);	//初始化所有点都未并入集合S 
	visit[1] = true;				//第一个点并入集合S 
	for(int i = 1; i <= n; i++)		//集合S到其他点的消耗就是第一个点到其他点的距离 
	{
		cost[i] = dis[1][i];		
	}

	for(int i = 1; i < n; i++)	//将剩余n - 1个点并入连通图 
	{
		temp = INT_MAX;
		for(int j = 1; j <= n; j++)			//找出和集合S的最小距离的点，根据最小生成树的性质，连该点和集合S的该边一定在最小生成树上 
		{
			if(!visit[j] && cost[j] < temp)		
			{
				temp = cost[j];	
				minIndex = j;
			}	
		}
		
		if(temp == INT_MAX)	//没有找到说明所有点都连通，则跳出 
			break;
			
		sum += cost[minIndex];	//和更新 
		visit[minIndex] = true;		//该点已访问 
		
		//新的点并入连通图后更新cost，即集合加入新的点后，该点到其他点的距离如果比当前集合到其他点的距离小，则更新 
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
		for(int i = 1; i <= n; i++)			//邻接矩阵的方式存储整个带权图 
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> dis[i][j];	
			}	
		} 
	
		cin >> q;
		while(q--)
		{
			cin >> a >> b;					//读入已经连通的点，更新距离 
			dis[a][b] = dis[b][a] = 0;
		}
	
	
		cout << prim(n) << endl;
	} 

	return 0;	
} 
