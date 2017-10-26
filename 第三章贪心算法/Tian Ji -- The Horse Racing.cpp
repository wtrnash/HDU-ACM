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
 which is the number of horses on each side. The next n integers on the second line are the speeds of Tian’s horses.
  Then the next n integers on the third line are the speeds of the king’s horses. The input ends with a line that has a single 0 after the last test case.
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
//贪心算法
/*
先比较最快的马： 
1.如果此时田忌最快的马比王最快的快，那直接这样比，因为如果不这样比，田忌这匹马一定能赢王的别的马，但王这匹马就也有可能赢田忌别的马 
就有可能从赚200变成赚200后亏200，所以直接比掉；	
2.如果田忌最快的马比王最快的马慢，则齐王最快的马一定能赢一局，所以让田忌最慢的马输给它； 
3.如果田忌最快的马和王最快的马一样: 
3.1 比较田忌最慢的马和王最慢的马，如果田忌最慢的马比王最慢的马快，那就这样比，而如果不这样比，田忌其他马还是能赢王这匹马，但是田忌最慢的马就可能被王其他马赢了  
3.2 如果田忌最慢的马比王最慢的马要慢，那田忌最慢的马一定会输，所以输给齐王最快的马
3.3 如果田忌最慢的马和王最慢的马一样，此时要比较田忌最慢的马和齐王最快的马，因为要考虑所有马速度一样的情况，不考虑的话让田忌的慢马输给齐王的快马就会多亏200了
3.3.1 如果田忌最慢的马和齐王最快的马一样快，则当前所有没比的马速度都一样，因为田忌和齐王的最快、最慢马相互之间速度都一样，所以直接结束循环
3.3.2 如果田忌最慢的马比齐王最快的马要慢，则让它输给齐王最快的马 
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
		
		int low1 = 0, high1 = n - 1;		//表示田忌没有比的马的序列，low1表示最慢马的下标，high1表示最快马的下标 
		int low2 = 0, high2 = n - 1; 		//表示齐王没有比的马的序列，low2表示最慢马的下标，high2表示最快马的下标 
		while(n-- > 0)						//每次比一匹马，一直比到马都比完
		{
			if(tian[high1] > king[high2])	//如果此时田忌最快的马比王的快，那直接这样比，因为如果不这样比，田忌这匹马一定能赢王的别的马，但王这匹马就也有可能赢田忌别的马 
			{								//就有可能从赚200变成赚200后亏200，所以直接比掉	
				count += 200;
				high1--;
				high2--;
			}
			else if(tian[high1] < king[high2])	//如果田忌最快的马比齐王最快的马慢，则齐王最快的马一定能赢一局，所以让田忌最慢的马输给它 
			{
				count -= 200;
				low1++;
				high2--; 
			}
			else											//如果田忌最快的马和齐王最快的马一样快
			{
				
				if(tian[low1] < king[low2])			//如果当前田忌最慢的马比王最慢的马慢，那田忌这匹马一定输，让它输给王最快的马，将这两匹马排除出序列，进行下次比较 
				{
					count -= 200;
					low1++;
					high2--;
				}
				else if(tian[low1] == king[low2]) 	//如果田忌最慢的马和王最慢的马打平，则比较田忌最慢的马和齐王最快的马 
				{          
					if(tian[low1] < king[high2])	//如果小于，则用田忌最慢的马和齐王最快的马比 
					{
						count -= 200;
						low1++;
						high2--; 
					}                         
					else                        //否则，田忌最慢的马和齐王最快的马一样快，而他又和齐王最慢的马一样快，所以剩下的马速度都一样，所以直接结束 
					{
						break; 
					} 
				
				}
				else				//如果田忌最慢的马能赢王这匹最慢的马，则就这样比，而如果不这样比，田忌其他马还是能赢王这匹马，但是田忌最慢的马就可能被王其他马赢了 
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
