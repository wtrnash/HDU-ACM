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
//����͹�����ܳ�����ѡ����������С�ĵ㣬ͨ����˱Ƚϣ����������ʱ������Ȼ��ͨ����������Ƿ�����ת���ж�֮ǰ�ĵ��Ƿ���͹����
//�����������͹���ϵĵ������ܳ����� 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Tree	//��¼�������� 
{
	int x;
	int y;
}trees[101];

Tree s[101]; //ģ��ջ��͹���ϵĵ�
int top;

double distance(Tree t1, Tree t2)	//����������֮��ľ��� 
{
	return 	sqrt((double)pow(t1.x - t2.x, 2) + (double)pow(t1.y - t2.y, 2));
}

int crossProduct(int x1, int y1, int x2, int y2)	//��� 
{
	return x1 * y2 - x2 * y1;
}

bool compare(Tree t1, Tree t2)	//ѡ������ʼ�㼴��������С�ĵ�󣬽��������ʱ��˳������ 
{
	//��˽��Ϊ������ǰһ�����ں�һ�������ʱ�뷽���ǰ��
	//���Ϊ0���������㹲�ߣ���Ƚ��������㵽��ʼ��ľ����С������С����ǰ
	int result = crossProduct(t1.x - trees[0].x, t1.y - trees[0].y, t2.x - trees[0].x, t2.y - trees[0].y);
	if (result > 0 || (result == 0 && distance(t1, trees[0]) < distance(t2, trees[0])))
		return true;
	else
		return false;
}

//grahamɨ�跨�����ò����͹���ϵĵ� 
void graham(int n)
{
	top = -1;
	s[++top] = trees[0];		//ǰ����������ջ 
	s[++top] = trees[1];

	for (int i = 2; i < n; i++)
	{
		//���ֵ�һ����һ����ջ�������������ת����֮ǰ�ĵ㲻Ӧ����͹�����򵯳� 
		//�ò�����ж�����ת������ת 
		while (top >= 0 && crossProduct(s[top].x - s[top - 1].x, s[top].y - s[top - 1].y, trees[i].x - s[top].x, trees[i].y - s[top].y) < 0)
		{
			top--;
		}
		s[++top] = trees[i];	//����ǰ����ջ 
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
		for (int i = 0; i < n; i++)	//�������� 
		{
			cin >> trees[i].x >> trees[i].y;
		}

		if (n == 1)	//ֻ��һ������͹���ܳ�һ��Ϊ0 
		{
			cout << "0.00" << endl;
			cin >> n;
			continue;
		}

		if (n == 2)	//ֻ����������͹���ܳ�Ϊ�������ľ��� 
		{
			cout << fixed << setprecision(2) << distance(trees[0], trees[1]) << endl;
			cin >> n;
			continue;
		}

		//ѡȡ��������С�ĵ�Ϊ��ʼ�㣬��һ����͹���� 
		min = 0;
		for (int i = 1; i < n; i++)
		{
			if (trees[i].y < trees[min].y)
				min = i;
		}
		//�ҳ���������С����±꣬����±겻Ϊ0�����ԭ��Ϊ0�Ľ��н��� 
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
		sort(trees + 1, trees + n, compare); //���� 
											 //��͹���ϵĵ� 
		graham(n);
		//����͹�����ܳ� 
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
