/*************************************************************************************************************
Problem Description
经过激烈的争夺，Lele终于把那块地从Yueyue的手里抢了回来。接下来，Lele要开始建造他的灌溉系统。
通过咨询Lele的好友——化学系的TT，Lele决定在田里挖出N条沟渠，每条沟渠输送一种肥料。
每条沟渠可以看作是一条折线，也就是一系列线段首尾连接而成(除了第一条线段开头和最后一条线段的结尾)。
由于沟渠很细，你可以忽略掉它的宽度。由于不同的肥料之间混合会发生化学反应，所以修建的沟渠与沟渠之间不能相交。
现在TT给Lele画了一些设计图，Lele请你判断一下设计图中的沟渠与沟渠之间是否有相交。
Input
本题目包含多组测试，请处理到文件结束(EOF)。每组测试的第一行有一个正整数N(0<N<30)，表示管道的数目。
接下来给出这N条管道的信息。对于每条管道，第一行是一个正整数K(0<K<100)，表示这条管道是由K个端点组成。
接下来的K行给出这K个端点信息。每个端点占一行，用两个整数X和Y(0<X,Y<1000)分别表示这个端点的横坐标和纵坐标的值。
Output
对于每组测试，如果该测试管道与管道之间有相交的话，输出"Yes"，否则输出"No"。
Sample Input
2
2
0 0
1 1
2
0 1
1 0
2
2
0 0
1 1
2
1 0
2 1
2
3
0 0
1 1
2 1
2
2 0
3 0
Sample Output
Yes
No
No
****************************************************************************************************************/
//核心还是用叉乘求是否相交的模板。将读入的点化成线段来存储。用四重循环判断一个管道的一个线段与其他管道的所有线段是否相交，一旦有相交则返回true 
#include <iostream>
#include <algorithm>
using namespace std;

struct Segment	//线段类，存储线段的两个端点的坐标 
{
	double x1;
	double y1;
	double x2;
	double y2;
};

struct Pipe
{
	Segment segments[101];
	int k;
}pipes[31];

int n, k;

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

//四重循环判断管道是否相交。只要管道的一段和另外管道的任意的一段相交，都返回true。所有都不相交就返回false 
bool isPipeIntersect()
{
	for (int i = 0; i < n; i++)	//选取第i个管道 
	{
		for (int j = 0; j < pipes[i].k - 1; j++) //第i个管道的第j段 ,共k个点所以共k-1条线段，所以要小于k-1 
		{
			for (int k = i + 1; k < n; k++)		//与第 k个管道 
			{
				for (int l = 0; l < pipes[k].k - 1; l++)	//与第k个管道的第l段判断是否相交 
				{
					if (isIntersect(pipes[i].segments[j], pipes[k].segments[l]))
						return true;
				}

			}
		}
	}
	return false;
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)	//读入数据，将点存入线段 
		{
			cin >> pipes[i].k;
			cin >> pipes[i].segments[0].x1 >> pipes[i].segments[0].y1;

			for (int j = 0; j < pipes[i].k - 1;j++)
			{
				cin >> pipes[i].segments[j].x2 >> pipes[i].segments[j].y2;		
				pipes[i].segments[j + 1].x1 = pipes[i].segments[j].x2;			//读入线段x2,y2的端点同时是下一段线段的x1,y1.最后会多设一次x1,y1，但是由于有k来控制所以没事 
				pipes[i].segments[j + 1].y1 = pipes[i].segments[j].y2;
			}

		}

		if (isPipeIntersect()) 
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	return 0;
}
