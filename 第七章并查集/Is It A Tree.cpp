/*****************************************************************************************************************************************************
Problem Description
A tree is a well-known data structure that is either empty (null, void, nothing) or 
is a set of one or more nodes connected by directed edges between nodes satisfying the following properties. 
There is exactly one node, called the root, to which no directed edges point. 
Every node except the root has exactly one edge pointing to it. 
There is a unique sequence of directed edges from the root to each node. 
For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads. 
The first two of these are trees, but the last is not.
In this problem you will be given several descriptions of collections of nodes connected by directed edges. 
For each of these you are to determine if the collection satisfies the definition of a tree or not. 
Input
The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. 
Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; 
the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. 
Node numbers will always be greater than zero. 
Output
For each test case display the line ``Case k is a tree." or the line ``Case k is not a tree.", 
where k corresponds to the test case number (they are sequentially numbered starting with 1). 
Sample Input
6 8 5 3 5 2 6 4
5 6 0 0
8 1 7 3 6 2 8 9 7 5
7 4 7 8 7 6 0 0
3 8 6 8 6 4
5 3 5 6 5 2 0 0
-1 -1
Sample Output
Case 1 is a tree.
Case 2 is a tree.
Case 3 is not a tree.
*******************************************************************************************************************************************************/
//�ò��鼯�ж��Ƿ����������ȴ��������Ȼ��ÿ���ڵ�ָֻ��һ�����ڵ㣬�Լ�������нڵ㶼��ͬһ�����ڵ㣬������������ 
#include <iostream>
#define MAX 10001
using namespace std;

int set[MAX];
int nodes[MAX];

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
	int x, y, count = 0, n;
	cin >> x >> y;					//�������� 
	while(x >= 0 && y >= 0)			//�ж��Ƿ�Ǹ�����ѭ��ѭ��һ�ζ���һ�������� 
	{
		n = 0;
		count++;	//��¼��ǰ�������±� 
		if(x == 0 && y == 0)	//������ʼΪ����0˵���ǿ��������� 
		{	
			cout << "Case " << count << " is a tree." << endl;	
			cin >> x >> y;
			continue; 
		}
		else
		{
			do{
				nodes[n++] = x;			//nodes���鰴˳���Ŷ�������нڵ�,n��¼�ڵ��� 
				nodes[n++] = y;
				cin >> x >> y;
			}while(x != 0 && y != 0);	//�����������һֱ��0Ϊֹ 
			
			initSet(n);	//��ʼ��n 
			bool flag = true; 
			for(int i = 0; i < n; i += 2)	//�����нڵ���벢�鼯 
			{
				if(findSet(nodes[i + 1]) != nodes[i + 1])	//�жϸýڵ�ĸ��ڵ��ǲ��Ǳ���������Ǽ�һ���ڵ���֮ǰ�Ѿ��и��ڵ��ˣ�������и��ڵ���˵�����������ڵ�,������ 
				{
					flag = false;
					break;
				}
				mergeSet(nodes[i + 1], nodes[i]);	//�ϲ�����i + 1 ��Ϊ i ������	
			} 
			
			if(flag == false)
			{
				cout << "Case " << count << " is not a tree." << endl;
				cin >> x >> y;
				continue;
			}
						
			int father = findSet(nodes[0]);	//�ҵ� ��һ���ڵ�ĸ��ڵ㡣��Ϊ����������Ҳ�����нڵ�ĸ��ڵ㣬����нڵ�ĸ��ڵ㲻�Ǹõ㣬˵�������� 

			for(int i = 1; i < n; i++)
			{
				if(findSet(nodes[i]) != father)
				{
					flag = false;
					break;
				} 
			} 
			if(flag)
			{
				cout << "Case " << count << " is a tree." << endl;	
			}
			else
			{
				cout << "Case " << count << " is not a tree." << endl;	
			}
			
			cin >> x >> y;
		}
		
	} 
	return 0;
}
