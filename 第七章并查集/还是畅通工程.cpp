/************************************************************************************************************************ 
Problem Description
某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），
并要求铺设的公路总长度为最小。请计算最小的公路总长度。
Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；
随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。
为简单起见，村庄从1到N编号。当N为0时，输入结束，该用例不被处理。
Output
对每个测试用例，在1行里输出最小的公路总长度。
Sample Input
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
Sample Output
3
5
**************************************************************************************************************************/
//还是求最小生成树，利用邻接矩阵读取数据后，使用普里姆算法计算要添加的路径和 
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
	int n, a, b, cost;
	cin >> n;
	while(n != 0)
	{
		int m = n * (n - 1) / 2; 
		for(int i = 0; i < m; i++)	//读入村庄的对应距离 
		{
			cin >> a >> b >> cost;
			dis[a][b] = cost;
			dis[b][a] = cost;
		}
		
		for(int i = 1; i <= n; i++)		//自身距离为0 
		{
			dis[i][i] = 0;
		}
		
		cout << prim(n) << endl;
		cin >> n;
	}
	return 0;
}
