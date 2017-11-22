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
//二维类似最长子序列的动态规划 
//将体重按升序排序，用vector<vector<int> >存储每个序列的序号 ，其中元素size最长的即是最长序列
//从第一只老鼠开始，第一只老鼠的序列只有一个元素。第二只老鼠和之前的老鼠比，取 之前的老鼠体重小且速度快的 且 序列最长的，将序列复制到当前序列，并加上本身
//以此类推  
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

bool compare(Mice m1, Mice m2)	//体重升序排序 
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
	while (cin >> weight >> speed)	//读取数据 
	{
		temp.weight = weight;
		temp.speed = speed;
		temp.index = index++;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);	//排序 

	vector<int> v1;					//第一个老鼠只含本身 
	v1.push_back(v[0].index);
	count.push_back(v1);

	vector<int> vTemp;
	for (int i = 1; i < v.size(); i++)	//第二个老鼠开始 
	{
		vTemp.clear();
		int length = 0;
		int index;
		for (int j = 0; j < i; j++)   //对之前所有的老鼠进行比较 
		{
			if (v[i].weight > v[j].weight && v[i].speed < v[j].speed)		//如果比之前的重而且比之前的慢 
			{
				if (count[j].size() > length)                   //且当前的序列比之前最长的长，则选择当前的序列   
				{
					length = count[j].size();
					index = j;
				}
			}
		}

		if (length == 0)					//如果长度为0，代表没有找到之前合适的老鼠 
		{
			vTemp.push_back(v[i].index);		//将本身加入vector 
			count.push_back(vTemp);
		}
		else		//否则将之前最长的序列加上本身加入vector 
		{
			vTemp.assign(count[index].begin(), count[index].end());
			vTemp.push_back(v[i].index);
			count.push_back(vTemp);
		}
	}

	int flag = 0;
	for (int i = 1;i < count.size(); i++)		//选择最长的 
	{
		if (count[i].size() > count[flag].size())
			flag = i;
	}

	cout << count[flag].size() << endl;			//输出 
	for (int i = 0;i < count[flag].size(); i++)
	{
		cout << count[flag][i] << endl;
	}

	 
	return 0;
}
