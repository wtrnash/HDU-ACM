/*********************************************************************************************************************
�����Ҵ��������˵������������Ȼ���±����⣬���ֲ���һ������֯��Աȫ����ͨ��ͨ��һ������֯�ɹ���ʳ��
���ڼ����²���һ�������ľ��־���Ҫȥ�г��ɹ����ף�ɢװ����
����г���m�ִ��ף����ִ��׵ĵ��ۺ�������֪�����ʣ�Ϊ����������������������ܲɹ����������Ĵ����أ�
Input
�����������Ȱ���һ��������C����ʾ��C�����������ÿ����������ĵ�һ������������n��m��0<n<=1000,0<m<=1000��,
�ֱ��ʾ���ѵĽ��ʹ��׵����࣬Ȼ����m�����ݣ�ÿ�а���2������p��h(1<=p<=25,1<=h<=100)���ֱ��ʾ���ۺͶ�Ӧ���׵�������
Output
����ÿ��������ݣ�������ܹ�������׵��������������Լ��辭���򲻹����еĴ��ף��� ÿ��ʵ�������ռһ�У�����2λС����
Sample Input
1
7 2
3 3
4 4
Sample Output
2.33
***********************************************************************************************************************/
//���⣬�����۽����������ȹ��򵥼۵͵Ĵ��׼��� 
#include <iostream> 
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

struct Rice	//���� 
{
	int price;
	int weight;
};

bool compare(Rice r1, Rice r2)	//�����׵�������������� 
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
		
		sort(v.begin(), v.end(), compare);	//����
		 
		for(int i = 0; i < v.size(); i++)
		{
			if(m > (double)v[i].weight * v[i].price)	//ʣ�¾����ܹ�������һ�ִ��� 
			{
				weight += v[i].weight;						
				m -= (double)v[i].weight * v[i].price;
			}
			else										//ʣ�¾��Ѳ��ܹ�������һ�ִ��� 
			{
				weight += (double) m / v[i].price;
				break;
			}
		}
		
		cout << fixed << setprecision(2) << weight << endl;
	}
	
	return 0;
} 
