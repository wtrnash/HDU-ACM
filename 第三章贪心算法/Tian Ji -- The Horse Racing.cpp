/* *******************************************************************************************************************************************************************************
Problem Description
Here is a famous story in Chinese history.
"That was about 2300 years ago. General Tian Ji was a high official in the country Qi. He likes to play horse racing with the king and others."
"Both of Tian and the king have three horses in different classes, namely, regular, plus, and super.
 The rule is to have three rounds in a match; each of the horses must be used in one round. The winner of a single round takes two hundred silver dollars from the loser."
"Being the most powerful man in the country, 
the king has so nice horses that in each class his horse is better than Tian's. 
As a result, each time the king takes six hundred silver dollars from Tian."
"Tian Ji was not happy about that, until he met Sun Bin, one of the most famous generals in Chinese history.
 Using a little trick due to Sun, Tian Ji brought home two hundred silver dollars and such a grace in the next match."
"It was a rather simple trick. Using his regular class horse race against the super class from the king, they will certainly lose that round. 
But then his plus beat the king's regular, and his super beat the king's plus. What a simple trick. 
And how do you think of Tian Ji, the high ranked official in China?"
Were Tian Ji lives in nowadays, he will certainly laugh at himself.
Even more, were he sitting in the ACM contest right now, he may discover that the horse racing problem can be simply viewed as finding the maximum matching in a bipartite graph.
Draw Tian's horses on one side, and the king's horses on the other. 
Whenever one of Tian's horses can beat one from the king, we draw an edge between them, meaning we wish to establish this pair.
 Then, the problem of winning as many rounds as possible is just to find the maximum matching in this graph. 
If there are ties, the problem becomes more complicated, he needs to assign weights 0, 1, or -1 to all the possible edges, and find a maximum weighted perfect matching...
However, the horse racing problem is a very special case of bipartite matching. 
The graph is decided by the speed of the horses --- a vertex of higher speed always beat a vertex of lower speed. 
In this case, the weighted bipartite matching algorithm is a too advanced tool to deal with the problem.
In this problem, you are asked to write a program to solve this special case of matching problem.
Input
The input consists of up to 50 test cases. Each case starts with a positive integer n (n <= 1000) on the first line,
 which is the number of horses on each side. The next n integers on the second line are the speeds of Tian��s horses.
  Then the next n integers on the third line are the speeds of the king��s horses. The input ends with a line that has a single 0 after the last test case.
Output
For each input case, output a line containing a single number, which is the maximum money Tian Ji will get, in silver dollars.
Sample Input
3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0
Sample Output
200
0
0
********************************************************************************************************************************************************************************/
//̰���㷨
/*
�ȱȽ������� 
1.�����ʱ���������������Ŀ죬��ֱ�������ȣ���Ϊ����������ȣ������ƥ��һ����Ӯ���ı����������ƥ���Ҳ�п���Ӯ��ɱ���� 
���п��ܴ�׬200���׬200���200������ֱ�ӱȵ���	
2.�������������������������������������һ����Ӯһ�֣������������������������� 
3.���������������������һ��: 
3.1 �Ƚ������������������������������������������������죬�Ǿ������ȣ�������������ȣ��������������Ӯ����ƥ�����������������Ϳ��ܱ���������Ӯ��  
3.2 �������������������������Ҫ�����������������һ�����䣬�����������������
3.3 �������������������������һ������ʱҪ�Ƚ�������������������������ΪҪ�����������ٶ�һ��������������ǵĻ�����ɵ�������������Ŀ���ͻ���200��
3.3.1 �������������������������һ���죬��ǰ����û�ȵ����ٶȶ�һ������Ϊ��ɺ���������졢�������໥֮���ٶȶ�һ��������ֱ�ӽ���ѭ��
3.3.2 �������������������������Ҫ����������������������� 
*/ 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int count;
	int tian[1000];
	int king[1000];
	cin >> n;
	while(n != 0)
	{
		count = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> tian[i];
		}
		
		for(int i = 0; i < n; i++)
		{
			cin >> king[i];
		}
		
		sort(tian, tian + n);
		sort(king, king + n);
		
		int low1 = 0, high1 = n - 1;		//��ʾ���û�бȵ�������У�low1��ʾ��������±꣬high1��ʾ�������±� 
		int low2 = 0, high2 = n - 1; 		//��ʾ����û�бȵ�������У�low2��ʾ��������±꣬high2��ʾ�������±� 
		while(n-- > 0)						//ÿ�α�һƥ��һֱ�ȵ�������
		{
			if(tian[high1] > king[high2])	//�����ʱ�������������Ŀ죬��ֱ�������ȣ���Ϊ����������ȣ������ƥ��һ����Ӯ���ı����������ƥ���Ҳ�п���Ӯ��ɱ���� 
			{								//���п��ܴ�׬200���׬200���200������ֱ�ӱȵ�	
				count += 200;
				high1--;
				high2--;
			}
			else if(tian[high1] < king[high2])	//���������������������������������������һ����Ӯһ�֣����������������������� 
			{
				count -= 200;
				low1++;
				high2--; 
			}
			else											//�����������������������һ����
			{
				
				if(tian[low1] < king[low2])			//�����ǰ���������������������������������ƥ��һ���䣬���������������������ƥ���ų������У������´αȽ� 
				{
					count -= 200;
					low1++;
					high2--;
				}
				else if(tian[low1] == king[low2]) 	//��������������������������ƽ����Ƚ����������������������� 
				{          
					if(tian[low1] < king[high2])	//���С�ڣ���������������������������� 
					{
						count -= 200;
						low1++;
						high2--; 
					}                         
					else                        //��������������������������һ���죬�����ֺ�������������һ���죬����ʣ�µ����ٶȶ�һ��������ֱ�ӽ��� 
					{
						break; 
					} 
				
				}
				else				//����������������Ӯ����ƥ����������������ȣ�������������ȣ��������������Ӯ����ƥ�����������������Ϳ��ܱ���������Ӯ�� 
				{
					count += 200;
					low1++;
					low2++; 
				}
			}		
		
		}
		
		cout << count << endl; 
		cin >> n;
	}
	return 0;
}
