/*************************************************************************************************************************************************
Problem Description
FatMouse believes that the fatter a mouse is, the faster it runs.
To disprove this, you want to take the data on a collection of mice
and put as large a subset of this data as possible into a sequence so that the weights are increasing,
but the speeds are decreasing.
Input
Input contains data for a bunch of mice, one mouse per line, terminated by end of file.
The data for a particular mouse will consist of a pair of integers:
the first representing its size in grams and the second representing its speed in centimeters per second.
Both integers are between 1 and 10000. The data in each test case will contain information for at most 1000 mice.
Two mice may have the same weight, the same speed, or even the same weight and speed.
Output
Your program should output a sequence of lines of data; the first line should contain a number n;
the remaining n lines should each contain a single positive integer (each one representing a mouse).
If these n integers are m[1], m[2],..., m[n] then it must be the case that W[m[1]] < W[m[2]] < ... < W[m[n]] and S[m[1]] > S[m[2]] > ... > S[m[n]]
In order for the answer to be correct, n should be as large as possible.
All inequalities are strict: weights must be strictly increasing, and speeds must be strictly decreasing.
There may be many correct outputs for a given input, your program only needs to find one.
Sample Input
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
Sample Output
4
4
5
9
7
********************************************************************************************************************************************************/
//��ά����������еĶ�̬�滮 
//�����ذ�����������vector<vector<int> >�洢ÿ�����е���� ������Ԫ��size��ļ��������
//�ӵ�һֻ����ʼ����һֻ���������ֻ��һ��Ԫ�ء��ڶ�ֻ�����֮ǰ������ȣ�ȡ ֮ǰ����������С���ٶȿ�� �� ������ģ������и��Ƶ���ǰ���У������ϱ���
//�Դ�����  
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Mice
{
	int weight;
	int speed;
	int index;
};

bool compare(Mice m1, Mice m2)	//������������ 
{
	if (m1.weight == m2.weight) 
		return m1.speed > m2.speed;
	return m1.weight < m2.weight;
}

int main()
{
	Mice temp;
	vector<Mice> v;
	vector<vector<int> > count;
	int weight, speed;

	int index = 1;
	while (cin >> weight >> speed)	//��ȡ���� 
	{
		temp.weight = weight;
		temp.speed = speed;
		temp.index = index++;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);	//���� 

	vector<int> v1;					//��һ������ֻ������ 
	v1.push_back(v[0].index);
	count.push_back(v1);

	vector<int> vTemp;
	for (int i = 1; i < v.size(); i++)	//�ڶ�������ʼ 
	{
		vTemp.clear();
		int length = 0;
		int index;
		for (int j = 0; j < i; j++)   //��֮ǰ���е�������бȽ� 
		{
			if (v[i].weight > v[j].weight && v[i].speed < v[j].speed)		//�����֮ǰ���ض��ұ�֮ǰ���� 
			{
				if (count[j].size() > length)                   //�ҵ�ǰ�����б�֮ǰ��ĳ�����ѡ��ǰ������   
				{
					length = count[j].size();
					index = j;
				}
			}
		}

		if (length == 0)					//�������Ϊ0������û���ҵ�֮ǰ���ʵ����� 
		{
			vTemp.push_back(v[i].index);		//���������vector 
			count.push_back(vTemp);
		}
		else		//����֮ǰ������м��ϱ������vector 
		{
			vTemp.assign(count[index].begin(), count[index].end());
			vTemp.push_back(v[i].index);
			count.push_back(vTemp);
		}
	}

	int flag = 0;
	for (int i = 1;i < count.size(); i++)		//ѡ����� 
	{
		if (count[i].size() > count[flag].size())
			flag = i;
	}

	cout << count[flag].size() << endl;			//��� 
	for (int i = 0;i < count[flag].size(); i++)
	{
		cout << count[flag][i] << endl;
	}

	 
	return 0;
}
