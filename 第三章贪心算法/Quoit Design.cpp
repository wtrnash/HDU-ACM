/***************************************************************************************************************************************************************
Problem Description
Have you ever played quoit in a playground?
Quoit is a game in which flat rings are pitched at some toys, with all the toys encircled awarded.
In the field of Cyberground, the position of each toy is fixed, and the ring is carefully designed so it can only encircle one toy at a time.
On the other hand, to make the game look more attractive, the ring is designed to have the largest radius.
Given a configuration of the field, you are supposed to find the radius of such a ring.
Assume that all the toys are points on a plane. A point is encircled by the ring if the distance between the point
and the center of the ring is strictly less than the radius of the ring. If two toys are placed at the same point, the radius of the ring is considered to be 0.
Input
The input consists of several test cases. For each case, the first line contains an integer N (2 <= N <= 100,000),
the total number of toys in the field. Then N lines follow, each contains a pair of (x, y) which are the coordinates of a toy. The input is terminated by N = 0.
Output
For each test case, print in one line the radius of the ring required by the Cyberground manager, accurate up to 2 decimal places.
Sample Input
2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0
Sample Output
0.71
0.00
0.75
******************************************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

struct Coordinate
{
	double x;
	double y;
	bool isLeft;
};

vector<Coordinate> v;

bool compareX(Coordinate c1, Coordinate c2)	//按x坐标升序排序 
{
	return c1.x < c2.x;
}

bool compareY(Coordinate c1, Coordinate c2)	//按y坐标升序排序 
{
	return c1.y < c2.y;
}

double getDistance(Coordinate c1, Coordinate c2)	//获得两点间的距离 
{
	return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

double findMinDistance(int start, int end)		//递归求出最小距离 
{
	if (start + 1 == end)	//只有两个点则直接返回两点间距离 
	{
		return getDistance(v[start], v[end]);
	}
	else if (start + 2 == end)		//三个点的话直接求出这三个点的最短距离 
	{
		double d1 = getDistance(v[start], v[start + 1]);
		double d2 = getDistance(v[start], v[start + 2]);
		double d3 = getDistance(v[start + 1], v[start + 2]);
		if (d1 < d2)
		{
			if (d1 < d3)
				return d1;
			else
				return d3;
		}
		else
		{
			if (d2 < d3)
				return d2;
			else
				return d3;
		}
	}
	else						//大于三个点则先求出左边的最小值、右边的最小值和横跨两边的最小值，再比较求出最小值 
	{
		int mid = (start + end) / 2;
		double minLeft = findMinDistance(start, mid);		//左边一半的最小距离 
		double minRight = findMinDistance(mid + 1, end);	//右边一半的最小距离
		double minDistance = minLeft < minRight ? minLeft : minRight;

		vector<Coordinate> temp;
		//求横跨两边的最小距离
		//如果两边的点到中间点的x坐标距离已经大于minDistance的话那一定不是横跨两边的最小值，可以先排除。将满足小于minDistance的点放入向量 
		//处理左边的点 
		for (int i = start; i <= mid; i++)
		{
			if (v[mid].x - v[i].x < minDistance)
			{
				v[i].isLeft = true;
				temp.push_back(v[i]);
			}
		}
		//处理右边的点 
		for (int i = mid + 1; i <= end; i++)
		{
			if (v[i].x - v[mid].x< minDistance)
			{
				v[i].isLeft = false;
				temp.push_back(v[i]);
			}
		}

		//按y坐标排序
		sort(temp.begin(), temp.end(), compareY);

		for (int i = 0; i < temp.size(); i++)
		{
			//只处理左边的点即可
			if (temp[i].isLeft)
			{
				for (int j = 1; j <= 7 && i + j < temp.size(); j++)		//每个点最多只要比较7次，具体原因可以去看最近点对问题 
				{
					//必须是和右边的点比
					if (temp[i + j].isLeft == false)
					{
						double tempDistance = getDistance(temp[i], temp[i + j]);
						if (tempDistance < minDistance)	//比当前最小值小则更新 
							minDistance = tempDistance;
					}
				}
			}
		}

		return minDistance;


	}

}
int main()
{
	Coordinate temp;
	int n;
	cin >> n;
	while (n != 0)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> temp.x >> temp.y;
			v.push_back(temp);
		}
		cout << fixed << setprecision(2) << findMinDistance(0, n - 1) / 2 << endl;
		cin >> n;
	}

	return 0;
}


