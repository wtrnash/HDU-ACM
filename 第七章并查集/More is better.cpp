/******************************************************************************************************************************************************************
Problem Description
Mr Wang wants some boys to help him with a project. 
Because the project is rather complex, the more boys come, the better it will be. 
Of course there are certain requirements.Mr Wang selected a room big enough to hold the boys. 
The boy who are not been chosen has to leave the room immediately. There are 10000000 boys in the room numbered from 1 to 10000000 at the very beginning. 
After Mr Wang's selection any two of them who are still in this room should be friends (direct or indirect), or there is only one boy left. 
Given all the direct friend-pairs, you should decide the best way.
Input
The first line of the input contains an integer n (0 ≤ n ≤ 100 000) - the number of direct friend-pairs. 
The following n lines each contains a pair of numbers A and B separated by a single space that suggests A and B are direct friends. (A ≠ B, 1 ≤ A, B ≤ 10000000)
Output
The output in one line contains exactly one integer equals to the maximum number of boys Mr Wang may keep. 
Sample Input
4
1 2
3 4
5 6
1 6
4
1 2
3 4
5 6
7 8
Sample Output
4
2
*********************************************************************************************************************************************************************/
//并查集，计算含最多元素的集合含元素的个数。一直超时，改成了c语言的读写也没用，最后把findSet从循环改成了递归，就过了，不是很懂，按道理循环的时间复杂度也优于递归？ 
#include <iostream>
#include <stdio.h> 
#define MAX 10000001
using namespace std;

int set[MAX];
int num[MAX];	//记录每个集合的元素数 

void initSet(int n)					// 初始化并查集，初始时每个元素的根节点都是自己，n为元素个数 
{
	for(int i = 1;i <= n; i++)
	{
		set[i] = i;
		num[i] = 1;	//初始化，每个集合只有本身，元素数为1 
	}
		
}

int findSet(int index)				//寻找一个集合的根节点，一直递归到父节点为自己为止 
{
	if(set[index] != index)
		set[index] = findSet(set[index]);
		
	return set[index];	
}

void mergeSet(int a, int b)			//合并集合，如果两个集合的根节点不是同一个，则将其中一个集合的根节点设为另一个，完成合并 
{
	int fa = findSet(a);
	int fb = findSet(b);
	if(fa != fb)
	{
		set[fa] = fb;
		num[fb] += num[fa];		
	}
		
}
int main()
{
	int n, a, b, maxNum, maxIndex;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
		{
			printf("1\n");
			continue;
		}
		
		maxNum = 1;
		maxIndex = 0;

		initSet(10000000);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&a, &b);
			mergeSet(a, b);
			
			if(a > maxIndex)	//确定最大下标数，以便后面循环不用循环到1000000 
				maxIndex = a;
			
			if(b > maxIndex)
				maxIndex = b;
		}
		
		for(int i = 1; i <= maxIndex; i++)	
		{
			if(num[i] > maxNum)	
				maxNum = num[i];
		}
		
		printf("%d\n", maxNum);
	}
	return 0;
 } 
