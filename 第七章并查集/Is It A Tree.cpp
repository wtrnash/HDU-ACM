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
//用并查集判断是否是树。首先处理空树。然后每个节点只指向一个父节点，以及最后所有节点都是同一个父节点，这样才是树。 
#include <iostream>
#define MAX 10001
using namespace std;

int set[MAX];
int nodes[MAX];

void initSet(int n)					// 初始化并查集，初始时每个元素的根节点都是自己，n为元素个数 
{
	for(int i = 1;i <= n; i++)
		set[i] = i;
}

int findSet(int index)				//寻找一个集合的根节点，一直循环到父节点为自己为止 
{
	while(set[index] != index)
		index = set[index];
	
	return index;	
}

void mergeSet(int a, int b)			//合并集合，如果两个集合的根节点不是同一个，则将其中一个集合的根节点设为另一个，完成合并 
{
	int fa = findSet(a);
	int fb = findSet(b);
	if(fa != fb)
		set[fa] = fb;
}

int main()
{
	int x, y, count = 0, n;
	cin >> x >> y;					//读入数据 
	while(x >= 0 && y >= 0)			//判断是否非负，该循环循环一次读入一整个用例 
	{
		n = 0;
		count++;	//记录当前用例的下标 
		if(x == 0 && y == 0)	//用例开始为两个0说明是空树，是树 
		{	
			cout << "Case " << count << " is a tree." << endl;	
			cin >> x >> y;
			continue; 
		}
		else
		{
			do{
				nodes[n++] = x;			//nodes数组按顺序存放读入的所有节点,n记录节点数 
				nodes[n++] = y;
				cin >> x >> y;
			}while(x != 0 && y != 0);	//读入该组数据一直到0为止 
			
			initSet(n);	//初始化n 
			bool flag = true; 
			for(int i = 0; i < n; i += 2)	//将所有节点放入并查集 
			{
				if(findSet(nodes[i + 1]) != nodes[i + 1])	//判断该节点的父节点是不是本身，如果不是即一个节点在之前已经有父节点了，这次再有父节点则说明有两个父节点,则不是树 
				{
					flag = false;
					break;
				}
				mergeSet(nodes[i + 1], nodes[i]);	//合并，即i + 1 成为 i 的子树	
			} 
			
			if(flag == false)
			{
				cout << "Case " << count << " is not a tree." << endl;
				cin >> x >> y;
				continue;
			}
						
			int father = findSet(nodes[0]);	//找到 第一个节点的父节点。因为是树，所以也是所有节点的根节点，如果有节点的根节点不是该点，说明不是树 

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
