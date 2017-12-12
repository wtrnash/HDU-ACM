/*******************************************************************************************************************************
Problem Description
A segment and all segments which are connected with it compose a segment set.
The size of a segment set is the number of segments in it.
The problem is to find the size of some segment set.
Input
In the first line there is an integer t - the number of test case.
For each test case in first line there is an integer n (n<=1000) - the number of commands.
There are two different commands described in different format shown below:
P x1 y1 x2 y2 - paint a segment whose coordinates of the two endpoints are (x1,y1),(x2,y2).
Q k - query the size of the segment set which contains the k-th segment.k is between 1 and the number of segments in the moment.
There is no segment in the plane at first, so the first command is always a P-command.
Output
For each Q-command, output the answer. There is a blank line between test cases.
Sample Input
1
10
P 1.00 1.00 4.00 2.00
P 1.00 -2.00 8.00 4.00
Q 1
P 2.00 3.00 3.00 1.00
Q 1
Q 3
P 1.00 4.00 8.00 2.00
Q 2
P 3.00 3.00 6.00 -2.00
Q 5
Sample Output
1
2
2
2
5
**********************************************************************************************************************************/
//使用叉乘判断线段相交，使用并查集来处理集合
#include <iostream>
#include <algorithm>
using namespace std;

struct Segment	//线段类，存储线段的两个端点的坐标 
{
	double x1;
	double y1;
	double x2;
	double y2;
}segments[1001];

int father[1001], num[1001];

double crossProduct(double x1, double y1, double x2, double y2) //传入两个向量进行叉乘，参数x1,y1,x2,y2不是指点坐标值，而是向量的坐标值 
{
	return x1 * y2 - x2 * y1;
}

bool onSegment(double x1, double y1, double x2, double y2, double x3, double y3)	//判断第三个点是否在 前两个点组成的线段上。参数都为坐标值 
{
	if (min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2))	//因为已知点 
		return true;
	else
		return false;
}

bool isIntersect(Segment s1, Segment s2)	//判断线段是否相交 
{
	//假设线段s1的两个端点为 p1,p2，线段s2的两个端点为p3,p4 
	double cp1 = crossProduct(s1.x1 - s2.x1, s1.y1 - s2.y1, s2.x2 - s2.x1, s2.y2 - s2.y1);        //p3p1 与 p3p4做叉乘	
	double cp2 = crossProduct(s1.x2 - s2.x1, s1.y2 - s2.y1, s2.x2 - s2.x1, s2.y2 - s2.y1);		//p3p2 与 p3p4做叉乘 
	double cp3 = crossProduct(s2.x1 - s1.x1, s2.y1 - s1.y1, s1.x2 - s1.x1, s1.y2 - s1.y1);	//p1p3 与 p1p2做叉乘		
	double cp4 = crossProduct(s2.x2 - s1.x1, s2.y2 - s1.y1, s1.x2 - s1.x1, s1.y2 - s1.y1);	//p1p4 与 p1p2做叉乘
																							//如果p3p1 和 p3p4叉乘的结果与 p3p2和 p3p4叉乘的结果异号，代表点p1、p2在线段p3p4两侧
																							//同理，如果p1p3 和 p1p2叉乘的结果与 p1p4 和 p1p2叉乘的结果异号， 代表点p3、p4在线段p1p2两侧
																							//同时满足则一定相交	
	if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) && ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0)))
		return true;
	else if (cp1 == 0 && onSegment(s2.x1, s2.y1, s2.x2, s2.y2, s1.x1, s1.y1))			//p3p1 与 p3p4叉乘为0 ，表示 p1在直线p3p4上，且 点 p1 在线段p3p4范围内，则也表示相交 ,下面类似 
		return true;
	else if (cp2 == 0 && onSegment(s2.x1, s2.y1, s2.x2, s2.y2, s1.x2, s1.y2))
		return true;
	else if (cp3 == 0 && onSegment(s1.x1, s1.y1, s1.x2, s1.y2, s2.x1, s2.y1))
		return true;
	else if (cp4 == 0 && onSegment(s1.x1, s1.y1, s1.x2, s1.y2, s2.x2, s2.y2))
		return true;
	else
		return false;
}

//初始化函数  
void initSet(int n)
{
	for (int i = 1;i <= n;i++)
	{
		father[i] = i;  	//一开始每个元素一个集合，所以自己都是自己的根节点 
		num[i] = 1;  		//每个集合大小为1，只有一个元素 
	}
}
//查找函数  
int findFather(int x)
{
	while (father[x] != x)
		x = father[x];
	return x;
}
//合并函数  
void combine(int a, int b)
{
	int temp_a, temp_b;
	temp_a = findFather(a);
	temp_b = findFather(b);

	// 在合并集合的时候，相应集合所含的个数也要合并  
	if (temp_a != temp_b)
	{
		father[temp_a] = temp_b;
		num[temp_b] += num[temp_a];
	}
}

int main()
{
	int t, n, k, count;
	char c;
	cin >> t;
	while (t--)
	{
		cin >> n;
		initSet(n);
		count = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			if (c == 'P')	//如果是p命令则读入线段 
			{
				cin >> segments[count].x1 >> segments[count].y1 >> segments[count].x2 >> segments[count].y2;
				for (int j = 1; j < count; j++)
				{
					if (isIntersect(segments[j], segments[count]))	//如果当前线段和之前的线段有相交，则并入对应集合 
					{
						combine(count, j);	//合并 
					}
				}

				count++;
			}
			else
			{
				cin >> k;
				cout << num[findFather(k)] << endl; 	//查找到父节点记录的线段数量 
			}
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}
