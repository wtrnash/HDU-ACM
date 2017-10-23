/***************************************************************
Problem Description
����һ���ٷ��Ƶĳɼ�t������ת���ɶ�Ӧ�ĵȼ���
����ת���������£�90~100ΪA;80~89ΪB;70~79ΪC;60~69ΪD;0~59ΪE;
Input:
���������ж��飬ÿ��ռһ�У���һ��������ɡ�
Output:
����ÿ���������ݣ����һ�С�
����������ݲ���0~100��Χ�ڣ������һ�У���Score is error!����
Sample Input:
56
67
100
123
Sample Output:
E
D
A
Score is error!
***************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int score;
	while(cin >> score)
	{
		if(score > 100 || score < 0)
			cout << "Score is error!" << endl;
		else
			switch(score / 10)                                 //��������switch case���ģ�Ҳ������if-else������ 
			{
				case 10:
				case 9:
					cout << "A" << endl;
					break;
				case 8:
					cout << "B" << endl;
					break;
				case 7:
					cout << "C" << endl;
					break;
				case 6:
					cout << "D" << endl;
					break;
				default:
					cout << "E" << endl;
					break;
			}
	}
	return 0;	
} 
