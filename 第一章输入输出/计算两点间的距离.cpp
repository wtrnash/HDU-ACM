/******************************************************
Problem Description
�����������꣨X1,Y1��,��X2,Y2��,���㲢��������ľ��롣
Input:
���������ж��飬ÿ��ռһ�У���4��ʵ����ɣ�
�ֱ��ʾx1,y1,x2,y2,����֮���ÿո������
Output:
����ÿ���������ݣ����һ�У����������λС����
Sample Input:
0 0 0 1
0 1 1 0
Sample Output:
1.00
1.41
********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double distance; 
	double x1, y1, x2, y2;
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		distance = sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2));            //����cmath���е�pow��������ƽ�����㣬sqrt�����������������㣬���������ľ��빫ʽ���distance 
		cout << fixed << setprecision(2) << distance << endl;		  //c++ ����2λС���ķ��� 
	}
	return 0;
}
