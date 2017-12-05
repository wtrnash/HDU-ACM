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
//�Ҷ���ε����ġ� ���ò�ˣ��Ƚ�����ηֳ�n�������Σ����ÿ�������ε�������ٸ���ÿ�������εĶ������ÿ�������ε�����
//ÿ�����������ĳ��Զ�Ӧ������ܺͳ�����������Ƕ���ε�����
//˼�������Ϊ�����ǰ�������ȷֲ�����ÿ�������ε������ǰ�����λ�÷ֲ��ģ����������ζ��������ĳ���������棬�ٳ�����������ɡ� 
#include <iostream>
#include <algorithm> 
#include <iomanip> 
using namespace std;
struct Point	//�㣬����x�����y���� 
{
	double x;
	double y;
}points[1000001];	//���1000000���� 

Point barycenter(int n)	//������ 
{
	double crossProduct;	//��¼��˽�� 
	double area = 0;		//��¼��� 
	double bcx = 0;			//��¼���ĵ�x���� 
	double bcy = 0;			//��¼���ĵ�y���� 
	Point p, s;			//p �� s���Ͻ��в����������������������������������Ρ�   Ĭ�����������Ϊ��0,0��,����p,s�ĵ���������������� 
	p.x = points[0].x;
	p.y = points[0].y;
	for(int i = 1; i <= n; i++)
	{
		if(i == n)				//iΪnʱ��pΪ���һ���㣬����s������Ϊ��һ���� 
		{
			s.x = points[0].x;
			s.y = points[0].y;
		}
		else					//i��Ϊn��sΪp֮���һ���� 
		{
			s.x = points[i].x;;
			s.y = points[i].y;
		}
		crossProduct = p.x * s.y - s.x * p.y;	//���
		area += crossProduct / 2.0;				//��˳�2Ϊ���������
		bcx += (p.x + s.x) * crossProduct;		//���������ļ��㣬���ĵ�x���꼴Ϊ���������x����ͣ���������Ϊ0,0�����Բ��üӣ� ����3 ����ʱ�ȼ���x����ͣ����������������������������ʹ����������ռ��Ȩֵ
		bcy += (p.y + s.y) * crossProduct; 		//ͬ�����y���� 
		p.x = s.x;		 //��һ�����򣬸���p��p�����꼴Ϊ֮ǰs������ 
		p.y = s.y;		
	}
	s.x = bcx /  (6 * area);			//֮ǰÿ�������ε����ĵ����������˸���������������������Գ���������ٳ���6�����ǵ�ǰ���ĵ�x����
	s.y = bcy / (6 * area);				//y����ͬ�� 
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
			cin >> points[i].x >> points[i].y;		//�������� 
		}	
		temp = barycenter(n);		//������� 
		cout << fixed << setprecision(2) << temp.x << " " << temp.y << endl;		//������λ��� 
	} 
	return 0;
}
