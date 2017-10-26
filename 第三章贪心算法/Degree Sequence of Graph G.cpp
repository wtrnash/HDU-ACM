/****************************************************************************************************************************************************** 
Problem Description
Wang Haiyang is a strong and optimistic Chinese youngster. 
Although born and brought up in the northern inland city Harbin, 
he has deep love and yearns for the boundless oceans. 
After graduation, he came to a coastal city and got a job in a marine transportation company.
There, he held a position as a navigator in a freighter and began his new life.
The cargo vessel, Wang Haiyang worked on, sails among 6 ports between which exist 9 routes. 
At the first sight of his navigation chart, the 6 ports and 9 routes on it reminded him of Graph Theory that he studied in class at university. 
In the way that Leonhard Euler solved The Seven Bridges of Knoigsberg, 
Wang Haiyang regarded the navigation chart as a graph of Graph Theory. 
He considered the 6 ports as 6 nodes and 9 routes as 9 edges of the graph. The graph is illustrated as below.
According to Graph Theory, the number of edges related to a node is defined as Degree number of this node.
Wang Haiyang looked at the graph and thought, If arranged, the Degree numbers of all nodes of graph G can form such a sequence: 4, 4, 3,3,2,2,
which is called the degree sequence of the graph. Of course, the degree sequence of any simple graph 
(according to Graph Theory, a graph without any parallel edge or ring is a simple graph) is a non-negative integer sequence?
Wang Haiyang is a thoughtful person and tends to think deeply over any scientific problem that grabs his interest. 
So as usual, he also gave this problem further thought, As we know, any a simple graph always corresponds with a non-negative integer sequence. 
But whether a non-negative integer sequence always corresponds with the degree sequence of a simple graph?
That is, if given a non-negative integer sequence, are we sure that we can draw a simple graph according to it.?
Let's put forward such a definition: provided that a non-negative integer sequence is the degree sequence of a graph without any parallel edge or ring, 
that is, a simple graph, the sequence is draw-possible, otherwise, non-draw-possible. 
Now the problem faced with Wang Haiyang is how to test whether a non-negative integer sequence is draw-possible or not.
Since Wang Haiyang hasn't studied Algorithm Design course, it is difficult for him to solve such a problem. Can you help him?
Input
The first line of input contains an integer T, indicates the number of test cases.
In each case, there are n+1 numbers; 
first is an integer n (n<1000), 
which indicates there are n integers in the sequence; then follow n integers, which indicate the numbers of the degree sequence.
Output
For each case, the answer should be "yes"or "no" indicating this case is "draw-possible" or "non-draw-possible"
Sample Input
2
6 4 4 3 3 2 2
4 2 1 1 1
Sample Output
yes
no
*********************************************************************************************************************************************************/
//���ж��Ƿ�Ϊ��ͼ�����ж϶������Ƿ�Ϊż�������ж����Ķ����Ƿ�С�ڽڵ���������havel����ÿ��ȥ���������Ϊd1�ĵ㣬Ȼ��di���㶼��һ��ȥ����õ�ıߣ��Դ�����ֱ�����������е� 
//��������г��ֶ���Ϊ�����ĵ����Ǽ�ͼ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)	//�������� 
{
	return a > b;
}
int main()
{
	int t, n, temp, sum;
	bool flag;
	vector<int> v;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		flag = true; 
		v.clear();
		cin >> n;
		sum = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> temp;
			sum += temp;	//��¼������ 
			v.push_back(temp);
		}
		if(sum % 2)	//�ȵĺ�һ����ż������������һ������ͼ 
		{
			cout << "no" <<  endl;
			continue;
		}
		
		sort(v.begin(), v.end(), compare);	//���ȴӴ�С���� 
		
		for(int i = 0;i < v.size(); i++)	//ÿ��ȥ�����ȵĵ㣬�õ��ڸö��������ĵ�ȫ����ȥ1�����Ƿ���ڷǷ��ĵ㣬�Դ����� 
		{
			if(v[0] >= v.size())	//����õ�Ķ�����ʣ�����е����Ŀ��Ȼ������һ�����Ǽ�ͼ 
			{
				flag = false;
				break;
			}
			
			for(int k = 1; k <= v[0]; k++)
			{
				v[k]--;
				if(v[k] < 0) //��ȥ1��С��0�����Ǽ�ͼ������flagΪfalse������ѭ�� 
				{
					flag = false;
					break;	
				}	
			}	
			
			
			if(!flag)	//flagΪ�������ѭ�� 
				break;
			
			v[0] = 0;	//ȥ����õ������Ϊ0 
			
			sort(v.begin(), v.end(), compare);	//���°��ȴӴ�С���� 
			
			if(v[0] == 0)	//�����ʱ������������Ѿ�Ϊ0��������ѭ�� 
				break; 
		} 
		
		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;		
	}	
	
	return 0;
} 
