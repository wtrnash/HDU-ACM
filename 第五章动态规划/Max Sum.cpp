/*************************************************************************************************************************************************
Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence.
For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. 
Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
output
For each test case, you should output two lines. 
The first line is "Case #:", # means the number of the test case. 
The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. 
If there are more than one result, output the first one. Output a blank line between two cases.
Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
Sample Output
Case 1:
14 1 4
Case 2:
7 1 6
****************************************************************************************************************************************************/
//��������кͣ�������һ��˼·������sum��¼�ͣ�ֻ��֮ǰ�ĺ������ģ������ں��������Ч�ģ�����sum�ʹ�0��ʼ���¿�ʼ��¼һ�������С� 
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, n, num;
	vector<int> v;
	cin >> t;
	for(int i = 0;i < t; i++)
	{
		v.clear();
		cin >> n;
		while(n--)
		{
			cin >> num;
			v.push_back(num);
		}
		
		int max = -1001;
		int start, end ;
		int tempStart = 0;
		int sum = 0;
		
		for(int j = 0; j < v.size(); j++)
		{
			sum += v[j];
			if(sum > max)				//sum��max�������max 
			{
				start = tempStart + 1;
				end = j + 1;
				max = sum;
			}
			
			if(sum < 0)					//��ǰ��sum�Ѿ�Ϊ���ˣ����Ϻ���������ã��������¿�ʼ��һ�������С� 
			{
				sum = 0;
				if(j + 1 < v.size())
					tempStart = j + 1;
			}
			
		
		}
		
		cout << "Case " << i + 1 << ":" << endl;
		cout << max << " " << start << " " << end << endl;
		if(i < t - 1)
			cout << endl; 
		
	}
	return 0;
}
