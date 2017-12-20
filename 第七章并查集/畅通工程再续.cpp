/****************************************************************************************************************
Problem Description
���Ŵ�Ҷ���˵һ�����ٵ������ĵط��ɣ��ٵ����ľ��������ڲ�ͬ��С���У���������ȥ������С��ʱ��Ҫͨ����С����ʵ�֡�
������������������չ�ٵ�������չ����Ҫ��������⵱Ȼ�ǽ�ͨ���⣬��������ʵ�ְٵ�����ȫ��ͨ��
��������С��RPRush�԰ٵ������������˽��
�����ڷ���������С���佨���ţ���ν��������������2��С��֮��ľ��벻��С��10�ף�Ҳ���ܴ���1000�ס�
��Ȼ��Ϊ�˽�ʡ�ʽ�ֻҪ��ʵ������2��С��֮����·ͨ���ɡ�
�����ŵļ۸�Ϊ 100Ԫ/�ס�
Input
��������������ݡ��������Ȱ���һ������T(T <= 200)��������T�����ݡ�
ÿ������������һ������C(C <= 100),����С���ĸ�����
��������C�����꣬����ÿ��С�������꣬��Щ���궼�� 0 <= x, y <= 1000��������
Output
ÿ�������������һ�У������ŵ���С���ѣ��������һλС����
����޷�ʵ�ֹ����Դﵽȫ����ͨ�������oh!��.
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
//��������С��������һ��ʼ����������꣬����ת��Ϊ�ڽӾ���С��10�ʹ���1000�ľ�����Զ���ΪINT_MAX����������ķ�㷨������ 
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

double getDistance(Point a, Point b)	//��������� 
{
	return sqrt((double) (pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void prim(int n)	//����ķ�㷨 
{
	double sum = 0, temp;
	int k, minIndex; 
	double cost[n + 1];
	bool visit[n + 1];
	fill(visit, visit + n + 1, false);	//��ʼ�����е㶼δ���뼯��S 
	visit[1] = true;				//��һ���㲢�뼯��S 
	for(int i = 1; i <= n; i++)		//����S������������ľ��ǵ�һ���㵽������ľ��� 
	{
		cost[i] = dis[1][i];		
	}

	for(k = 1; k < n; k++)	//��ʣ��n - 1���㲢����ͨͼ 
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
		
		if(temp == INT_MAX)	//û���ҵ����ʵĵ������� 
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
	
	if(k != n)	//˵��û��ȫ����ͨ 
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
					dis[i][j] = temp; 	//����תΪ�ڽӾ���洢 
				else
					dis[i][j] = INT_MAX;
			}
				
		}
		
		prim(c); 
	} 
	return 0;
}
