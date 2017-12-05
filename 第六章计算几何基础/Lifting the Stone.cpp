/**********************************************************************************************************************************************************
Problem Description
There are many secret openings in the floor which are covered by a big heavy stone. 
When the stone is lifted up, a special mechanism detects this and activates poisoned arrows that are shot near the opening. 
The only possibility is to lift the stone very slowly and carefully. 
The ACM team must connect a rope to the stone and then lift it using a pulley. 
Moreover, the stone must be lifted all at once; no side can rise before another. 
So it is very important to find the centre of gravity and connect the rope exactly to that point. 
The stone has a polygonal shape and its height is the same throughout the whole polygonal area. 
Your task is to find the centre of gravity for the given polygon. <br>
Input
The input consists of T test cases. The number of them (T) is given on the first line of the input file. 
Each test case begins with a line containing a single integer N (3 <= N <= 1000000) indicating the number of points that form the polygon. 
This is followed by N lines, each containing two integers Xi and Yi (|Xi|, |Yi| <= 20000). 
These numbers are the coordinates of the i-th point. 
When we connect the points in the given order, we get a polygon. 
You may assume that the edges never touch each other (except the neighboring ones) and that they never cross. 
The area of the polygon is never zero, i.e. it cannot collapse into a single line. 
Output
Print exactly one line for each test case. The line should contain exactly two numbers separated by one space. 
These numbers are the coordinates of the centre of gravity. 
Round the coordinates to the nearest number with exactly two digits after the decimal point (0.005 rounds up to 0.01). 
Note that the centre of gravity may be outside the polygon, if its shape is not convex. If there is such a case in the input data, print the centre anyway. 
Sample Input
2
4
5 0
0 5
-5 0
0 -5
4
1 1
11 1
11 11
1 11
Sample Output
0.00 0.00
6.00 6.00
***********************************************************************************************************************************************************/
//找多边形的重心。 利用叉乘，先将多边形分成n个三角形，求出每个三角形的面积，再根据每个三角形的顶点求出每个三角形的重心
//每个三角形重心乘以对应面积的总和除以总面积就是多边形的重心
//思想就是因为重心是按面积均匀分布，而每个三角形的重心是按顶点位置分布的，整块三角形都用其重心乘以面积代替，再除以总面积即可。 
#include <iostream>
#include <algorithm> 
#include <iomanip> 
using namespace std;
struct Point	//点，包含x坐标和y坐标 
{
	double x;
	double y;
}points[1000001];	//最多1000000个点 

Point barycenter(int n)	//求重心 
{
	double crossProduct;	//记录叉乘结果 
	double area = 0;		//记录面积 
	double bcx = 0;			//记录重心的x坐标 
	double bcy = 0;			//记录重心的y坐标 
	Point p, s;			//p 和 s不断进行叉乘来求三角形面积。三角形组成整个多边形。   默认设第三个点为（0,0）,所以p,s的点坐标就是向量坐标 
	p.x = points[0].x;
	p.y = points[0].y;
	for(int i = 1; i <= n; i++)
	{
		if(i == n)				//i为n时，p为最后一个点，所以s就设置为第一个点 
		{
			s.x = points[0].x;
			s.y = points[0].y;
		}
		else					//i不为n，s为p之后的一个点 
		{
			s.x = points[i].x;;
			s.y = points[i].y;
		}
		crossProduct = p.x * s.y - s.x * p.y;	//叉乘
		area += crossProduct / 2.0;				//叉乘除2为三角形面积
		bcx += (p.x + s.x) * crossProduct;		//三角形重心计算，重心的x坐标即为三个顶点的x坐标和（第三个点为0,0，所以不用加） 除以3 。此时先计算x坐标和，并乘以三角形面积的两倍。面积就代表该重心所占的权值
		bcy += (p.y + s.y) * crossProduct; 		//同理计算y坐标 
		p.x = s.x;		 //按一定方向，更新p，p的坐标即为之前s的坐标 
		p.y = s.y;		
	}
	s.x = bcx /  (6 * area);			//之前每个三角形的重心的三倍乘以了该三角形面积的两倍，所以除以总面积再除以6，就是当前重心的x坐标
	s.y = bcy / (6 * area);				//y坐标同理 
	return s; 	
}

int main()
{
	Point temp; 
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> points[i].x >> points[i].y;		//读入数据 
		}	
		temp = barycenter(n);		//求出重心 
		cout << fixed << setprecision(2) << temp.x << " " << temp.y << endl;		//保留两位输出 
	} 
	return 0;
}
