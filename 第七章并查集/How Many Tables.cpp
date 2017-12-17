/************************************************************************************************************************
Problem Description
Today is Ignatius' birthday. He invites a lot of friends. 
Now it's dinner time. Ignatius wants to know how many tables he needs at least. 
You have to notice that not all the friends know each other, and all the friends do not want to stay with strangers.
One important rule for this problem is that if I tell you A knows B, and B knows C, that means A, B, C know each other, 
so they can stay in one table.For example: If I tell you A knows B, B knows C, and D knows E, 
so A, B, C can stay in one table, and D, E have to stay in the other one. So Ignatius needs 2 tables at least.
Input
The input starts with an integer T(1<=T<=25) which indicate the number of test cases. 
Then T test cases follow. Each test case starts with two integers N and M(1<=N,M<=1000). 
N indicates the number of friends, the friends are marked from 1 to N. Then M lines follow. 
Each line consists of two integers A and B(A!=B), that means friend A and friend B know each other. 
There will be a blank line between two cases.
Output
For each test case, just output how many tables Ignatius needs at least. Do NOT print any blanks.
Sample Input
2
5 3
1 2
2 3
4 5
5 1
2 5
Sample Output
2
4
**************************************************************************************************************************/
//��򵥵Ĳ��鼯��Ŀ�� 
#include <iostream>
#include <algorithm>
#define MAX 1001 
using namespace std;

int set[MAX];

void initSet(int n)					// ��ʼ�����鼯����ʼʱÿ��Ԫ�صĸ��ڵ㶼���Լ���nΪԪ�ظ��� 
{
	for(int i = 1;i <= n; i++)
		set[i] = i;
}

int findSet(int index)				//Ѱ��һ�����ϵĸ��ڵ㣬һֱѭ�������ڵ�Ϊ�Լ�Ϊֹ 
{
	while(set[index] != index)
		index = set[index];
	
	return index;	
}

void mergeSet(int a, int b)			//�ϲ����ϣ�����������ϵĸ��ڵ㲻��ͬһ����������һ�����ϵĸ��ڵ���Ϊ��һ������ɺϲ� 
{
	int fa = findSet(a);
	int fb = findSet(b);
	if(fa != fb)
		set[fa] = fb;
}

int main()
{
	int t, n, m, x, y, count;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		count = 0;
		initSet(n);	//��ʼ�����鼯 
		for(int i = 0; i < m; i++)		//�������ݲ��ϲ� 
		{
			cin >> x >> y;
			mergeSet(x, y);
		}
		
		for(int i = 1; i <= n; i++)		//���ܹ��м������ڵ㣬Ҳ�����м������� 
		{
			if(set[i] == i)
				count++;
		}
		
		cout << count << endl;
	}
	return 0;
}
