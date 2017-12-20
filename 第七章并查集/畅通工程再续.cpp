/****************************************************************************************************************
Problem Description
相信大家都听说一个“百岛湖”的地方吧，百岛湖的居民生活在不同的小岛中，当他们想去其他的小岛时都要通过划小船来实现。
现在政府决定大力发展百岛湖，发展首先要解决的问题当然是交通问题，政府决定实现百岛湖的全畅通！
经过考察小组RPRush对百岛湖的情况充分了解后，
决定在符合条件的小岛间建上桥，所谓符合条件，就是2个小岛之间的距离不能小于10米，也不能大于1000米。
当然，为了节省资金，只要求实现任意2个小岛之间有路通即可。
其中桥的价格为 100元/米。
Input
输入包括多组数据。输入首先包括一个整数T(T <= 200)，代表有T组数据。
每组数据首先是一个整数C(C <= 100),代表小岛的个数，
接下来是C组坐标，代表每个小岛的坐标，这些坐标都是 0 <= x, y <= 1000的整数。
Output
每组输入数据输出一行，代表建桥的最小花费，结果保留一位小数。
如果无法实现工程以达到全部畅通，输出”oh!”.
Sample Input
2
2
10 10
20 20
3
1 1
2 2
1000 1000
Sample Output
1414.2
oh!
****************************************************************************************************************/
//还是求最小生成树。一开始读入的是坐标，可以转换为邻接矩阵，小于10和大于1000的距离可以定义为INT_MAX，再用普里姆算法做即可 
#include <iostream>
#include <cmath>
#include <iomanip>
#define MAX 101
using namespace std;

struct Point
{
	int x;
	int y;
}points[MAX];

double dis[MAX][MAX];

double getDistance(Point a, Point b)	//求两点距离 
{
	return sqrt((double) (pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void prim(int n)	//普里姆算法 
{
	double sum = 0, temp;
	int k, minIndex; 
	double cost[n + 1];
	bool visit[n + 1];
	fill(visit, visit + n + 1, false);	//初始化所有点都未并入集合S 
	visit[1] = true;				//第一个点并入集合S 
	for(int i = 1; i <= n; i++)		//集合S到其他点的消耗就是第一个点到其他点的距离 
	{
		cost[i] = dis[1][i];		
	}

	for(k = 1; k < n; k++)	//将剩余n - 1个点并入连通图 
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
		
		if(temp == INT_MAX)	//没有找到合适的点则跳出 
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
	
	if(k != n)	//说明没有全部连通 
	{
		cout << "oh!" << endl;
	} 
	else
		cout << fixed << setprecision(1) << 100 * sum << endl;
		
	
}

int main()
{
	int t, c;
	double temp;
	cin >> t;
	while(t--)
	{
		cin >> c;
		for(int i = 1; i <= c; i++)
			cin >> points[i].x >> points[i].y;
			
		for(int i = 1; i <= c; i++)
		{
			for(int j = 1; j <= c; j++)
			{
				temp = getDistance(points[i], points[j]);	
				if(temp >= 10 && temp <= 1000)
					dis[i][j] = temp; 	//坐标转为邻接矩阵存储 
				else
					dis[i][j] = INT_MAX;
			}
				
		}
		
		prim(c); 
	} 
	return 0;
}
