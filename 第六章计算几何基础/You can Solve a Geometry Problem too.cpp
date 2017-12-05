/***********************************************************************************************************************************************
Problem Description
Many geometry�����Σ�problems were designed in the ACM/ICPC. 
And now, I also prepare a geometry problem for this final exam. 
According to the experience of many ACMers, geometry problems are always much trouble,
but this problem is very easy, after all we are now attending an exam, not a contest :)
Give you N(1 <= N <= 100) segments���߶Σ�, please output the number of all intersections�����㣩. 
You should count repeatedly if M  segments intersect at the same point.
Note:You can assume that two segments would not intersect at more than one point. 
Input
Input contains multiple test cases. Each test case contains a integer N (1=N<=100) in a line first, 
and then N lines follow. Each line describes one segment with four float values x1, y1, x2, y2 which are coordinates of the segment��s ending. 
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
//˼��������ò�����ж��߶��Ƿ��ཻ��
 
#include <iostream> 
#include <algorithm> 
using namespace std;

struct Segment	//�߶��࣬�洢�߶ε������˵������ 
{
	double x1;
	double y1;
	double x2;
	double y2;	
}segments[101];		//�߶����飬��Ϊ������߶�������Χ��1��100֮�� 

double crossProduct(double x1, double y1, double x2, double y2) //���������������в�ˣ�����x1,y1,x2,y2����ָ������ֵ����������������ֵ 
{
	return x1 * y2 - x2 * y1; 
}

bool onSegment(double x1, double y1, double x2, double y2, double x3, double y3)	//�жϵ��������Ƿ��� ǰ��������ɵ��߶��ϡ�������Ϊ����ֵ 
{
	if(min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2))	//��Ϊ��֪�� 
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
	if(((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) && ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0)))	   
		return true;
	else if(cp1 == 0 && onSegment(s2.x1, s2.y1, s2.x2, s2.y2, s1.x1, s1.y1))			//p3p1 �� p3p4���Ϊ0 ����ʾ p1��ֱ��p3p4�ϣ��� �� p1 ���߶�p3p4��Χ�ڣ���Ҳ��ʾ�ཻ ,�������� 
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
		for(int i = 0; i < n; i++)	//�������� 
		{
			cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
		}
		//ÿ���߶κ�֮��������߶�һһ�Ƚϣ��ж��Ƿ��ཻ 
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
