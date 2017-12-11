/*************************************************************************************************************
Problem Description
�������ҵ����ᣬLele���ڰ��ǿ�ش�Yueyue���������˻�������������LeleҪ��ʼ�������Ĺ��ϵͳ��
ͨ����ѯLele�ĺ��ѡ�����ѧϵ��TT��Lele�����������ڳ�N��������ÿ����������һ�ַ��ϡ�
ÿ���������Կ�����һ�����ߣ�Ҳ����һϵ���߶���β���Ӷ���(���˵�һ���߶ο�ͷ�����һ���߶εĽ�β)��
���ڹ�����ϸ������Ժ��Ե����Ŀ�ȡ����ڲ�ͬ�ķ���֮���ϻᷢ����ѧ��Ӧ�������޽��Ĺ����빵��֮�䲻���ཻ��
����TT��Lele����һЩ���ͼ��Lele�����ж�һ�����ͼ�еĹ����빵��֮���Ƿ����ཻ��
Input
����Ŀ����������ԣ��봦���ļ�����(EOF)��ÿ����Եĵ�һ����һ��������N(0<N<30)����ʾ�ܵ�����Ŀ��
������������N���ܵ�����Ϣ������ÿ���ܵ�����һ����һ��������K(0<K<100)����ʾ�����ܵ�����K���˵���ɡ�
��������K�и�����K���˵���Ϣ��ÿ���˵�ռһ�У�����������X��Y(0<X,Y<1000)�ֱ��ʾ����˵�ĺ�������������ֵ��
Output
����ÿ����ԣ�����ò��Թܵ���ܵ�֮�����ཻ�Ļ������"Yes"���������"No"��
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
//���Ļ����ò�����Ƿ��ཻ��ģ�塣������ĵ㻯���߶����洢��������ѭ���ж�һ���ܵ���һ���߶��������ܵ��������߶��Ƿ��ཻ��һ�����ཻ�򷵻�true 
#include <iostream>
#include <algorithm>
using namespace std;

struct Segment	//�߶��࣬�洢�߶ε������˵������ 
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

//����ѭ���жϹܵ��Ƿ��ཻ��ֻҪ�ܵ���һ�κ�����ܵ��������һ���ཻ��������true�����ж����ཻ�ͷ���false 
bool isPipeIntersect()
{
	for (int i = 0; i < n; i++)	//ѡȡ��i���ܵ� 
	{
		for (int j = 0; j < pipes[i].k - 1; j++) //��i���ܵ��ĵ�j�� ,��k�������Թ�k-1���߶Σ�����ҪС��k-1 
		{
			for (int k = i + 1; k < n; k++)		//��� k���ܵ� 
			{
				for (int l = 0; l < pipes[k].k - 1; l++)	//���k���ܵ��ĵ�l���ж��Ƿ��ཻ 
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
		for (int i = 0; i < n; i++)	//�������ݣ���������߶� 
		{
			cin >> pipes[i].k;
			cin >> pipes[i].segments[0].x1 >> pipes[i].segments[0].y1;

			for (int j = 0; j < pipes[i].k - 1;j++)
			{
				cin >> pipes[i].segments[j].x2 >> pipes[i].segments[j].y2;		
				pipes[i].segments[j + 1].x1 = pipes[i].segments[j].x2;			//�����߶�x2,y2�Ķ˵�ͬʱ����һ���߶ε�x1,y1.�������һ��x1,y1������������k����������û�� 
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
