/******************************************************************************************************************************
Problem Description
There are a lot of trees in an area. A peasant wants to buy a rope to surround all these trees.
So at first he must know the minimal required length of the rope.
However, he does not know how to calculate it. Can you help him?
The diameter and length of the trees are omitted, which means a tree can be seen as a point.
The thickness of the rope is also omitted which means a rope can be seen as a line.There are no more than 100 trees.
Input
The input contains one or more data sets.
At first line of each input data set is number of trees in this data set, it is followed by series of coordinates of the trees.
Each coordinate is a positive integer pair, and each integer is less than 32767.
Each pair is separated by blank.<br><br>Zero at line for number of trees terminates the input for your program.
Output
The minimal length of the rope. The precision should be 10^-2.
Sample Input
9
12 7
24 9
30 5
41 9
80 7
50 87
22 9
45 1
50 7
0
Sample Output
243.06
*********************************************************************************************************************************/
//计算凸包的周长。先选出纵坐标最小的点，通过叉乘比较，将其余点逆时针排序，然后通过叉乘来用是否是右转来判断之前的点是否在凸包上
//计算出所有在凸包上的点后计算周长即可 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Tree	//记录树的坐标 
{
	int x;
	int y;
}trees[101];

Tree s[101]; //模拟栈求凸包上的点
int top;

double distance(Tree t1, Tree t2)	//返回两棵树之间的距离 
{
	return 	sqrt((double)pow(t1.x - t2.x, 2) + (double)pow(t1.y - t2.y, 2));
}

int crossProduct(int x1, int y1, int x2, int y2)	//叉乘 
{
	return x1 * y2 - x2 * y1;
}

bool compare(Tree t1, Tree t2)	//选定了起始点即纵坐标最小的点后，将其余点逆时针顺序排序 
{
	//叉乘结果为正代表前一个点在后一个点的逆时针方向的前面
	//叉乘为0，代表三点共线，则比较这两个点到起始点的距离大小，距离小的在前
	int result = crossProduct(t1.x - trees[0].x, t1.y - trees[0].y, t2.x - trees[0].x, t2.y - trees[0].y);
	if (result > 0 || (result == 0 && distance(t1, trees[0]) < distance(t2, trees[0])))
		return true;
	else
		return false;
}

//graham扫描法，利用叉乘求凸包上的点 
void graham(int n)
{
	top = -1;
	s[++top] = trees[0];		//前两个点先入栈 
	s[++top] = trees[1];

	for (int i = 2; i < n; i++)
	{
		//保持第一个点一定在栈，且如果出现右转，则之前的点不应该在凸包上则弹出 
		//用叉乘来判断是左转还是右转 
		while (top >= 0 && crossProduct(s[top].x - s[top - 1].x, s[top].y - s[top - 1].y, trees[i].x - s[top].x, trees[i].y - s[top].y) < 0)
		{
			top--;
		}
		s[++top] = trees[i];	//将当前点入栈 
	}

}

int main()
{
	double sum;
	int n, min;
	cin >> n;
	while (n != 0)
	{
		sum = 0;
		for (int i = 0; i < n; i++)	//读入数据 
		{
			cin >> trees[i].x >> trees[i].y;
		}

		if (n == 1)	//只有一棵树则凸包周长一定为0 
		{
			cout << "0.00" << endl;
			cin >> n;
			continue;
		}

		if (n == 2)	//只有两棵树则凸包周长为两棵树的距离 
		{
			cout << fixed << setprecision(2) << distance(trees[0], trees[1]) << endl;
			cin >> n;
			continue;
		}

		//选取纵坐标最小的点为起始点，它一定在凸包上 
		min = 0;
		for (int i = 1; i < n; i++)
		{
			if (trees[i].y < trees[min].y)
				min = i;
		}
		//找出纵坐标最小点的下标，如果下标不为0，则和原来为0的进行交换 
		if (min != 0)
		{
			int x, y;
			x = trees[0].x;
			y = trees[0].y;
			trees[0].x = trees[min].x;
			trees[0].y = trees[min].y;
			trees[min].x = x;
			trees[min].y = y;
		}
		sort(trees + 1, trees + n, compare); //排序 
											 //求凸包上的点 
		graham(n);
		//计算凸包的周长 
		Tree temp;
		temp.x = s[top].x;
		temp.y = s[top].y;
		while (top > 0)
		{
			sum += distance(s[top], s[top - 1]);
			top--;
		}

		sum += distance(s[0], temp);
		cout << fixed << setprecision(2) << sum << endl;

		cin >> n;
	}
	return 0;
}
