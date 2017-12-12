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
//ʹ�ò���ж��߶��ཻ��ʹ�ò��鼯��������
#include <iostream>
#include <algorithm>
using namespace std;

struct Segment	//�߶��࣬�洢�߶ε������˵������ 
{
	double x1;
	double y1;
	double x2;
	double y2;
}segments[1001];

int father[1001], num[1001];

double crossProduct(double x1, double y1, double x2, double y2) //���������������в�ˣ�����x1,y1,x2,y2����ָ������ֵ����������������ֵ 
{
	return x1 * y2 - x2 * y1;
}

bool onSegment(double x1, double y1, double x2, double y2, double x3, double y3)	//�жϵ��������Ƿ��� ǰ��������ɵ��߶��ϡ�������Ϊ����ֵ 
{
	if (min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2))	//��Ϊ��֪�� 
		return true;
	else
		return false;
}

bool isIntersect(Segment s1, Segment s2)	//�ж��߶��Ƿ��ཻ 
{
	//�����߶�s1�������˵�Ϊ p1,p2���߶�s2�������˵�Ϊp3,p4 
	double cp1 = crossProduct(s1.x1 - s2.x1, s1.y1 - s2.y1, s2.x2 - s2.x1, s2.y2 - s2.y1);        //p3p1 �� p3p4�����	
	double cp2 = crossProduct(s1.x2 - s2.x1, s1.y2 - s2.y1, s2.x2 - s2.x1, s2.y2 - s2.y1);		//p3p2 �� p3p4����� 
	double cp3 = crossProduct(s2.x1 - s1.x1, s2.y1 - s1.y1, s1.x2 - s1.x1, s1.y2 - s1.y1);	//p1p3 �� p1p2�����		
	double cp4 = crossProduct(s2.x2 - s1.x1, s2.y2 - s1.y1, s1.x2 - s1.x1, s1.y2 - s1.y1);	//p1p4 �� p1p2�����
																							//���p3p1 �� p3p4��˵Ľ���� p3p2�� p3p4��˵Ľ����ţ������p1��p2���߶�p3p4����
																							//ͬ�����p1p3 �� p1p2��˵Ľ���� p1p4 �� p1p2��˵Ľ����ţ� �����p3��p4���߶�p1p2����
																							//ͬʱ������һ���ཻ	
	if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) && ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0)))
		return true;
	else if (cp1 == 0 && onSegment(s2.x1, s2.y1, s2.x2, s2.y2, s1.x1, s1.y1))			//p3p1 �� p3p4���Ϊ0 ����ʾ p1��ֱ��p3p4�ϣ��� �� p1 ���߶�p3p4��Χ�ڣ���Ҳ��ʾ�ཻ ,�������� 
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

//��ʼ������  
void initSet(int n)
{
	for (int i = 1;i <= n;i++)
	{
		father[i] = i;  	//һ��ʼÿ��Ԫ��һ�����ϣ������Լ������Լ��ĸ��ڵ� 
		num[i] = 1;  		//ÿ�����ϴ�СΪ1��ֻ��һ��Ԫ�� 
	}
}
//���Һ���  
int findFather(int x)
{
	while (father[x] != x)
		x = father[x];
	return x;
}
//�ϲ�����  
void combine(int a, int b)
{
	int temp_a, temp_b;
	temp_a = findFather(a);
	temp_b = findFather(b);

	// �ںϲ����ϵ�ʱ����Ӧ���������ĸ���ҲҪ�ϲ�  
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
			if (c == 'P')	//�����p����������߶� 
			{
				cin >> segments[count].x1 >> segments[count].y1 >> segments[count].x2 >> segments[count].y2;
				for (int j = 1; j < count; j++)
				{
					if (isIntersect(segments[j], segments[count]))	//�����ǰ�߶κ�֮ǰ���߶����ཻ�������Ӧ���� 
					{
						combine(count, j);	//�ϲ� 
					}
				}

				count++;
			}
			else
			{
				cin >> k;
				cout << num[findFather(k)] << endl; 	//���ҵ����ڵ��¼���߶����� 
			}
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}
