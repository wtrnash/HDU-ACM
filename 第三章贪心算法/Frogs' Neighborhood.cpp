/********************************************************************************************************************************
Problem Description
δ������������N����С����L1, L2, ..., Ln(���а���δ����)��ÿ������Li��ס��һֻ����Fi(1 �� i �� N)��
�������Li��Lj֮����ˮ·������������Fi��Fj����Ϊ�ھӡ�
������֪ÿֻ���ܵ��ھ���Ŀx1, x2, ..., xn���������ÿ��������֮���������ϵ��
Input
��һ���ǲ������ݵ�����T(0 ��T ��20)��ÿ�����ݰ������У�
��һ��������N(2 < N < 10)���ڶ�����N��������x1, x2,..., xn(0 �� xi �� N)��
Output
�������ÿ��������ݣ���������ڿ��ܵ�������ϵ�����"NO"���������"YES"��
����N ��N�ľ����ʾ����������ڹ�ϵ�����������i�����j֮����ˮ·���������i�еĵ�j������Ϊ1������Ϊ0��ÿ��������֮�����һ���ո�
������ڶ��ֿ��ܣ�ֻ�����һ�ַ������������Ρ����������������֮�����һ�����С�
Sample Input
3
7
4 3 1 5 4 2 1
6
4 3 1 4 2 0
6
2 3 1 1 2 1
Sample Output
YES
0 1 0 1 1 0 1
1 0 0 1 1 0 0
0 0 0 1 0 0 0
1 1 1 0 1 1 0
1 1 0 1 0 1 0
0 0 0 1 1 0 0
1 0 0 0 0 0 0
NO
YES
0 1 0 0 1 0
1 0 0 1 1 0
0 0 0 0 0 1
0 1 0 0 0 0
1 1 0 0 0 0
0 0 1 0 0 0
*************************************************************************************************************************************/
//������֮ǰ����Degree Sequence of Graph G��Ҳ������havel������ݽ������ж��Ƿ����ͼ��ֻ����Ҫ�����þ�������������֮������������
//Ϊ�˱�֤����ľ���ÿ���±�Ͷ���˳��һ�£�������һ���ṹ������Ž���Ӧ���±��Լ��ھ������ɡ� 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Lake
{
	int index;
	int neighbor;
};

//���ݽ���ھ������н������� 
bool compare(Lake l1, Lake l2)
{
	return l1.neighbor > l2.neighbor;
}

int main()
{
	bool flag;
	vector<Lake> v;
	Lake temp;
	int t, n, sum;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		flag = true;
		sum = 0;
		v.clear();
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			temp.index = j;
			cin >> temp.neighbor;
			v.push_back(temp);
			sum += temp.neighbor;
		}

		//������Ϊż����һ������ 
		if (sum % 2)
		{
			cout << "NO" << endl;
			continue;
		}

		//��ʼ��n*n�ľ��� 
		int **matrix = new int*[n];
		for (int j = 0; j < n; j++)
		{
			matrix[j] = new int[n];
			fill(matrix[j], matrix[j] + n, 0);
		}

		//���ھ����Ӵ�С���� 
		sort(v.begin(), v.end(), compare);

		for (int j = 0; j < v.size(); j++)	//ÿ��ȥ�����ȵĵ㣬�õ��ڸö��������ĵ�ȫ����ȥ1�����Ƿ���ڷǷ��ĵ㣬�Դ����� 
		{

			for (int k = 1; k <= v[0].neighbor; k++)
			{
				matrix[v[0].index][v[k].index] = matrix[v[k].index][v[0].index] = 1;	//˵����Ϊ�ھӣ�������Ϊ1 
				v[k].neighbor--;
				if (v[k].neighbor < 0) //��ȥ1��С��0������ͼ������flagΪfalse������ѭ�� 
				{
					flag = false;
					break;
				}
			}


			if (!flag)	//flagΪ�������ѭ�� 
				break;

			v[0].neighbor = 0;	//ȥ����õ������Ϊ0 

			sort(v.begin(), v.end(), compare);	//���°��ȴӴ�С���� 

			if (v[0].neighbor == 0)	//�����ʱ������������Ѿ�Ϊ0��������ѭ�� 
				break;
		}

		if (flag)
		{
			cout << "YES" << endl;

			for (int j = 0; j < n; j++)
			{
				if (n > 0)
					cout << matrix[j][0];	//Ϊ�˴���ո񣬵�һ��������� 

				for (int k = 1; k < n; k++)
				{
					cout << " " << matrix[j][k];
				}
				cout << endl;
			}
		}
		else
			cout << "NO" << endl;

		cout << endl;
	}
	return 0;
}

