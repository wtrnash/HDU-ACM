/*************************************************************************************************************************************************
Problem Description
Many years ago , in Teddy’s hometown there was a man who was called “Bone Collector”. 
This man like to collect varies of bones , such as dog’s , cow’s , also he went to the grave …
The bone collector had a big bag with a volume of V ,and along his trip of collecting there are a lot of bones , 
obviously , different bone has different value and different volume, now given the each bone’s value along his trip , 
can you calculate out the maximum of the total value the bone collector can get ?
Input
The first line contain a integer T , the number of cases. Followed by T cases , each case three lines , 
the first line contain two integer N , V, (N <= 1000 , V <= 1000 )representing the number of bones and the volume of his bag. 
And the second line contain N integers representing the value of each bone. The third line contain N integers representing the volume of each bone.
Output
One integer per line representing the maximum of the total value (this number will be less than 2^31).
Sample Input
1
5 10
1 2 3 4 5
5 4 3 2 1
Sample Output
14
****************************************************************************************************************************************************/
//动态规划，01背包问题。详细思路可以网上搜背包九讲。 
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int volumn[MAX];
int value[MAX];
int f[MAX];
int main()
{
	int t, n, v;
	cin >> t;
	while(t--)
	{
		cin >> n >> v;
		fill(f, f + MAX, 0);
		for(int i = 0; i < n; i++)
			cin >> value[i];
		for(int i = 0; i < n; i++)
			cin >> volumn[i];
		
		for(int i = 0; i < n; i++)
		{
			for(int j = v; j >= volumn[i]; j--)
				f[j] = max(f[j], f[j - volumn[i]] + value[i]);
		}
			
		cout << f[v] << endl;
		
	}
	return 0;
}
