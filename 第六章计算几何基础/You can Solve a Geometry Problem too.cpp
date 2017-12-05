/***********************************************************************************************************************************************
Problem Description
Many geometry（几何）problems were designed in the ACM/ICPC. 
And now, I also prepare a geometry problem for this final exam. 
According to the experience of many ACMers, geometry problems are always much trouble,
but this problem is very easy, after all we are now attending an exam, not a contest :)
Give you N(1 <= N <= 100) segments（线段）, please output the number of all intersections（交点）. 
You should count repeatedly if M  segments intersect at the same point.
Note:You can assume that two segments would not intersect at more than one point. 
Input
Input contains multiple test cases. Each test case contains a integer N (1=N<=100) in a line first, 
and then N lines follow. Each line describes one segment with four float values x1, y1, x2, y2 which are coordinates of the segment’s ending. 
A test case starting with 0 terminates the input and this test case is not to be processed.
Output
For each case, print the number of intersections, and one line one case.
Sample Input
2
0.00 0.00 1.00 1.00
0.00 1.00 1.00 0.00
3
0.00 0.00 1.00 1.00
0.00 1.00 1.00 0.000
0.00 0.00 1.00 0.00
0
Sample Output
1
3
**************************************************************************************************************************************************/
//思想就是运用叉乘来判断线段是否相交。
 
#include <iostream> 
#include <algorithm> 
using namespace std;

struct Segment	//线段类，存储线段的两个端点的坐标 
{
	double x1;
	double y1;
	double x2;
	double y2;	
}segments[101];		//线段数组，因为输入的线段数量范围在1到100之间 

double crossProduct(double x1, double y1, double x2, double y2) //传入两个向量进行叉乘，参数x1,y1,x2,y2不是指点坐标值，而是向量的坐标值 
{
	return x1 * y2 - x2 * y1; 
}

bool onSegment(double x1, double y1, double x2, double y2, double x3, double y3)	//判断第三个点是否在 前两个点组成的线段上。参数都为坐标值 
{
	if(min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2))	//因为已知点 
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
	if(((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) && ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0)))	   
		return true;
	else if(cp1 == 0 && onSegment(s2.x1, s2.y1, s2.x2, s2.y2, s1.x1, s1.y1))			//p3p1 与 p3p4叉乘为0 ，表示 p1在直线p3p4上，且 点 p1 在线段p3p4范围内，则也表示相交 ,下面类似 
		return true;
	else if(cp2 == 0 && onSegment(s2.x1, s2.y1, s2.x2, s2.y2, s1.x2, s1.y2))
		return true;
	else if(cp3 == 0 && onSegment(s1.x1, s1.y1, s1.x2, s1.y2, s2.x1, s2.y1))
		return true;
	else if(cp4 == 0 && onSegment(s1.x1, s1.y1, s1.x2, s1.y2, s2.x2, s2.y2))
		return true;
	else
		return false;
}

int main()
{
	int count;
	int n;
	cin >> n;
	while(n != 0)
	{
		count = 0;
		for(int i = 0; i < n; i++)	//读入数据 
		{
			cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
		}
		//每个线段和之后的所有线段一一比较，判断是否相交 
		for(int i = 0;i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(isIntersect(segments[i], segments[j]))
					count++;
			}
		}
		cout << count << endl;
		cin >> n;	
	} 
	return 0;
}
