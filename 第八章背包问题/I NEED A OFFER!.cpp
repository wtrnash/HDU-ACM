/***************************************************************************************************************
Problem Description
Speakless很早就想出国，现在他已经考完了所有需要的考试，准备了所有要准备的材料，于是，便需要去申请学校了。
要申请国外的任何大学，你都要交纳一定的申请费用，这可是很惊人的。Speakless没有多少钱，总共只攒了n万美元。
他将在m个学校中选择若干的（当然要在他的经济承受范围内）。每个学校都有不同的申请费用a（万美元），
并且Speakless估计了他得到这个学校offer的可能性b。不同学校之间是否得到offer不会互相影响。
“I NEED A OFFER”，他大叫一声。帮帮这个可怜的人吧，帮助他计算一下，他可以收到至少一份offer的最大概率。
（如果Speakless选择了多个学校，得到任意一个学校的offer都可以）。
Input
输入有若干组数据，每组数据的第一行有两个正整数n,m(0<=n<=10000,0<=m<=10000) 
后面的m行，每行都有两个数据ai(整型),bi(实型)分别表示第i个学校的申请费用和可能拿到offer的概率。 输入的最后有两个0。
Output
每组数据都对应一个输出，表示Speakless可能得到至少一份offer的最大概率。用百分数表示，精确到小数点后一位。
Sample Input
10 3
4 0.1
4 0.2
5 0.3
0 0
Sample Output
44.0%
*******************************************************************************************************************/
//01背包问题。要把获得概率转为获不得的概率，才能用 1 - 他们的乘积 算至少获得一份的概率 
//注意m 和 n 的条件是 n || m 而不是 m != 0 && n != 0 
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int money[10001];
double chance[10001];
double dp[10001];
int main()
{
	int n, m;
	cin >> n >> m;
	double answer;
	while(n || m)
	{
		for(int i = 0; i < m; i++)
		{
			cin >> money[i] >> chance[i];
			chance[i] = 1 - chance[i];		//算至少一份，所以记录没获得的概率，1- 所有没获得的概率的积，即为至少一份offer的概率 
		}
		
		fill(dp, dp + n + 1, 1);	//用没获得的概率来做，所以初始时最大值，最大的没获得概率为1 
		
		for(int i = 0;i < m; i++)
		{
			for(int j = n; j >= money[i]; j--)
			{
				dp[j] = min(dp[j], dp[j - money[i]] * chance[i]);
			}
		}
		
		answer = 100 * (1 - dp[n]);
		cout << fixed << setprecision(1) << answer << "%" << endl;
		
		cin >> n >> m;
	}
	return 0;
}
