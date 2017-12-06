/*******************************************************************************************************************************************************
Problem Description
Once upon a time there was a greedy King who ordered his chief Architect to build a wall around the King's castle.
The King was so greedy, that he would not listen to his Architect's proposals to build a beautiful brick wall with a perfect shape and nice tall towers.
Instead, he ordered to build the wall around the whole castle using the least amount of stone and labor,
but demanded that the wall should not come closer to the castle than a certain distance.
If the King finds that the Architect has used more resources to build the wall than it was absolutely necessary to satisfy those requirements,
then the Architect will loose his head.
Moreover, he demanded Architect to introduce at once a plan of the wall listing the exact amount of resources that are needed to build the wall.
Your task is to help poor Architect to save his head,
by writing a program that will find the minimum possible length of the wall that he could build around the castle to satisfy King's requirements.
The task is somewhat simplified by the fact, that the King's castle has a polygonal shape and is situated on a flat ground.
The Architect has already established a Cartesian coordinate system and has precisely measured the coordinates of all castle's vertices in feet.
Input
The first line of the input file contains two integer numbers N and L separated by a space.
N (3 <= N <= 1000) is the number of vertices in the King's castle, and L (1 <= L <= 1000) is the minimal number of feet that King allows for the wall to come close to the castle.
Next N lines describe coordinates of castle's vertices in a clockwise order.
Each line contains two integer numbers Xi and Yi separated by a space (-10000 <= Xi, Yi <= 10000) that represent the coordinates of ith vertex.
All vertices are different and the sides of the castle do not intersect anywhere except for vertices.

Output
Write to the output file the single number that represents the minimal possible length of the wall in feet that could be built around the castle to satisfy King's requirements.
You must present the integer number of feet to the King, because the floating numbers are not invented yet.
However, you must round the result in such a way, that it is accurate to 8 inches (1 foot is equal to 12 inches),
since the King will not tolerate larger error in the estimates.
This problem contains multiple test cases!
The first line of a multiple input is an integer N, then a blank line followed by N input blocks.
Each input block is in the format indicated in the problem description. There is a blank line between input blocks.
The output format consists of N output blocks. There is a blank line between output blocks.
Sample Input
1

9 100
200 400
300 400
300 300
400 300
400 400
500 400
500 200
350 200
200 200
Sample Output
1628
***********************************************************************************************************************************************************************************/
//͹�����⣬����дһ��ͨ��ģ����������е�͹�����⡣
//����������͹�����ܳ�����һ����LΪ�뾶��Բ�ܳ�
//�������˼���������뱣������ 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define N 1001
#define PI 3.1415926536
using namespace std;

struct Point	//��¼������� 
{
	int x;
	int y;
}points[N];

Point s[N]; //ģ��ջ��͹���ϵĵ�
int top;

double distance(Point p1, Point p2)	//����������֮��ľ��� 
{
	return 	sqrt((double)pow(p1.x - p2.x, 2) + (double)pow(p1.y - p2.y, 2));
}

int crossProduct(int x1, int y1, int x2, int y2)	//��� 
{
	return x1 * y2 - x2 * y1;
}

bool compare(Point p1, Point p2)	//ѡ������ʼ�㼴��������С�ĵ�󣬽��������ʱ��˳������ 
{
	//��˽��Ϊ������ǰһ�����ں�һ�������ʱ�뷽���ǰ��
	//���Ϊ0���������㹲�ߣ���Ƚ��������㵽��ʼ��ľ����С������С����ǰ
	int result = crossProduct(p1.x - points[0].x, p1.y - points[0].y, p2.x - points[0].x, p2.y - points[0].y);
	if (result > 0 || (result == 0 && distance(p1, points[0]) < distance(p2, points[0])))
		return true;
	else
		return false;
}

//grahamɨ�跨�����ò����͹���ϵĵ� 
void graham(int n)
{
	top = -1;
	s[++top] = points[0];		//ǰ����������ջ 
	s[++top] = points[1];

	for (int i = 2; i < n; i++)
	{
		//���ֵ�һ����һ����ջ�������������ת����֮ǰ�ĵ㲻Ӧ����͹�����򵯳� 
		//�ò�����ж�����ת������ת 
		while (top >= 0 && crossProduct(s[top].x - s[top - 1].x, s[top].y - s[top - 1].y, points[i].x - s[top].x, points[i].y - s[top].y) < 0)
		{
			top--;
		}
		s[++top] = points[i];	//����ǰ����ջ 
	}

}

int main()
{
	double sum;
	int t, n, l, min;
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> n >> l;
		for (int i = 0; i < n; i++)
		{
			cin >> points[i].x >> points[i].y;
		}

		//ѡȡ��������С�ĵ�Ϊ��ʼ�㣬��һ����͹���� 
		min = 0;
		for (int i = 1; i < n; i++)
		{
			if (points[i].y < points[min].y)
				min = i;
		}
		//�ҳ���������С����±꣬����±겻Ϊ0�����ԭ��Ϊ0�Ľ��н��� 
		if (min != 0)
		{
			int x, y;
			x = points[0].x;
			y = points[0].y;
			points[0].x = points[min].x;
			points[0].y = points[min].y;
			points[min].x = x;
			points[min].y = y;
		}
		sort(points + 1, points + n, compare); //���� 
											   //��͹���ϵĵ� 
		graham(n);
		//����͹�����ܳ� 
		Point temp;
		temp.x = s[top].x;
		temp.y = s[top].y;
		while (top > 0)
		{
			sum += distance(s[top], s[top - 1]);
			top--;
		}

		sum += distance(s[0], temp);
		sum += 2 * PI * l;
		cout <<  round(sum) << endl;
		if(t != 0)	//���֮���п��У����һ��������ü� 
			cout << endl;
	}

	return 0;
}
