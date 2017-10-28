/*********************************************************************************************************************
对于幸存的灾民来说，最急待解决的显然是温饱问题，救灾部队一边在组织人员全力打通交通，一边在组织采购粮食。
现在假设下拨了一定数量的救灾经费要去市场采购大米（散装）。
如果市场有m种大米，各种大米的单价和重量已知，请问，为了满足更多灾民的需求，最多能采购多少重量的大米呢？
Input
输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m（0<n<=1000,0<m<=1000）,
分别表示经费的金额和大米的种类，然后是m行数据，每行包含2个整数p和h(1<=p<=25,1<=h<=100)，分别表示单价和对应大米的重量。
Output
对于每组测试数据，请输出能够购买大米的最多重量（你可以假设经费买不光所有的大米）。 每个实例的输出占一行，保留2位小数。
Sample Input
1
7 2
3 3
4 4
Sample Output
2.33
***********************************************************************************************************************/
//简单题，按单价进行排序，优先购买单价低的大米即可 
#include <iostream> 
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

struct Rice	//大米 
{
	int price;
	int weight;
};

bool compare(Rice r1, Rice r2)	//按大米单价升序进行排序 
{
	return r1.price < r2.price;
}
int main()
{
	int c;
 	int m, n;
 	double weight;
 	vector<Rice> v;
 	Rice temp;
 	
 	cin >> c;
 	
 	for(int i = 0; i < c; i++)
 	{
 		v.clear();
 		weight = 0;
 		cin >> m >> n;	
 		for(int j = 0; j < n; j++)
 		{
 			cin >> temp.price >> temp.weight;
 			v.push_back(temp); 	
		}
		
		sort(v.begin(), v.end(), compare);	//排序
		 
		for(int i = 0; i < v.size(); i++)
		{
			if(m > (double)v[i].weight * v[i].price)	//剩下经费能够买完整一种大米 
			{
				weight += v[i].weight;						
				m -= (double)v[i].weight * v[i].price;
			}
			else										//剩下经费不能够买完整一种大米 
			{
				weight += (double) m / v[i].price;
				break;
			}
		}
		
		cout << fixed << setprecision(2) << weight << endl;
	}
	
	return 0;
} 
