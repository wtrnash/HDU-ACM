/**************************************************************************************************************************************
Problem Description
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。
现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；
随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，
分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。当N为0时输入结束。
Output
每个测试用例的输出占一行，输出全省畅通需要的最低成本。
Sample Input
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0
Sample Output
3
1
0
***************************************************************************************************************************************/
//还是用普里姆算法求最小生成树。要注意数据量有点大，用cin 读会超时，所以使用scanf。 
#include <iostream>
#include <stdio.h>
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
	int n, a, b, cost, status;
	scanf("%d", &n);
	while(n != 0)
	{
		int m = n * (n - 1) / 2;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d%d", &a, &b, &cost, &status);
			if(status == 1)
			{
				dis[a][b] = dis[b][a] = 0;
			}
			else
			{
				dis[a][b] = dis[b][a] = cost;		
			}
		}
		
		for(int i = 1; i <= n; i++)
			dis[i][i] = 0;
			
		printf("%d\n", prim(n));
		scanf("%d", &n);
	}
	return 0;
}
