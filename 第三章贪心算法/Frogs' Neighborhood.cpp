/********************************************************************************************************************************
Problem Description
未名湖附近共有N个大小湖泊L1, L2, ..., Ln(其中包括未名湖)，每个湖泊Li里住着一只青蛙Fi(1 ≤ i ≤ N)。
如果湖泊Li和Lj之间有水路相连，则青蛙Fi和Fj互称为邻居。
现在已知每只青蛙的邻居数目x1, x2, ..., xn，请你给出每两个湖泊之间的相连关系。
Input
第一行是测试数据的组数T(0 ≤T ≤20)。每组数据包括两行，
第一行是整数N(2 < N < 10)，第二行是N个整数，x1, x2,..., xn(0 ≤ xi ≤ N)。
Output
对输入的每组测试数据，如果不存在可能的相连关系，输出"NO"。否则输出"YES"，
并用N ×N的矩阵表示湖泊间的相邻关系，即如果湖泊i与湖泊j之间有水路相连，则第i行的第j个数字为1，否则为0。每两个数字之间输出一个空格。
如果存在多种可能，只需给出一种符合条件的情形。相邻两组测试数据之间输出一个空行。
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
//类似与之前做的Degree Sequence of Graph G，也是利用havel定理根据结点度数判断是否可以图，只是需要额外用矩阵输出各个结点之间的相邻情况。
//为了保证输出的矩阵每个下标和读入顺序一致，所以用一个结构体来存放结点对应的下标以及邻居数即可。 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Lake
{
	int index;
	int neighbor;
};

//根据结点邻居数进行降序排序 
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

		//度数和为偶数则一定不对 
		if (sum % 2)
		{
			cout << "NO" << endl;
			continue;
		}

		//初始化n*n的矩阵 
		int **matrix = new int*[n];
		for (int j = 0; j < n; j++)
		{
			matrix[j] = new int[n];
			fill(matrix[j], matrix[j] + n, 0);
		}

		//按邻居数从大到小排序 
		sort(v.begin(), v.end(), compare);

		for (int j = 0; j < v.size(); j++)	//每次去掉最大度的点，让等于该度数数量的点全部减去1，看是否存在非法的点，以此类推 
		{

			for (int k = 1; k <= v[0].neighbor; k++)
			{
				matrix[v[0].index][v[k].index] = matrix[v[k].index][v[0].index] = 1;	//说明互为邻居，矩阵设为1 
				v[k].neighbor--;
				if (v[k].neighbor < 0) //减去1后小于0，则不是图，设置flag为false，跳出循环 
				{
					flag = false;
					break;
				}
			}


			if (!flag)	//flag为假则结束循环 
				break;

			v[0].neighbor = 0;	//去除后该点度数设为0 

			sort(v.begin(), v.end(), compare);	//重新按度从大到小排序 

			if (v[0].neighbor == 0)	//如果此时最大度数点度数已经为0，则跳出循环 
				break;
		}

		if (flag)
		{
			cout << "YES" << endl;

			for (int j = 0; j < n; j++)
			{
				if (n > 0)
					cout << matrix[j][0];	//为了处理空格，第一个单独输出 

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

