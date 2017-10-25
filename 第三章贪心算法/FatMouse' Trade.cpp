/***************************************************************************************************************************
Problem Description
FatMouse prepared M pounds of cat food, 
ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. 
FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans 
if he pays F[i]* a% pounds of cat food. 
Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
Input
The input consists of multiple test cases. 
Each test case begins with a line containing two non-negative integers M and N. 
Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. 
The last test case is followed by two -1's. All integers are not greater than 1000.
Output
For each test case, print in a single line a real number accurate up to 3 decimal places, 
which is the maximum amount of JavaBeans that FatMouse can obtain.
Sample Input
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
Sample Output
13.333
31.500
******************************************************************************************************************************/
//实际上就是先选择单位猫粮能换更多java beans的房间，这样最后能交换的java beans一定最多。
//所以将数据读入后对房间按交换率降序排序，之后按顺序进行交换计算总和即可。
//这里遇到一个问题，用cout 按格式输出三位小数无法AC，换成printf就成功AC 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//房间，包含总共的javaBeans数量以及交换所需的猫粮，以及交换率 
struct Room
{
	int javaBeans;
	int catFood;
	double rate;	
};

//根据交换率进行降序排序 
bool compare(Room room1, Room room2)
{
	return room1.rate > room2.rate;
}

int main() 
{
	int m, n;
	double sum;
	vector<Room> rooms;
	Room temp;
	cin >> m >> n;
	while(m != -1 || n != -1)
	{
		rooms.clear();
		sum = 0;
		for(int i = 0;i < n; i++)	//读取数据 
		{
			cin >> temp.javaBeans >> temp.catFood;
			temp.rate = (double)temp.javaBeans / temp.catFood;
			rooms.push_back(temp);
		}
		//排序
		sort(rooms.begin(),rooms.end(),compare);
		//计算总数
		 for(int i = 0; i < rooms.size(); i++)
		 {
		 	if(m <= rooms[i].catFood)
		 	{
		 		sum += m * rooms[i].rate;
				 break;	
			}
			else
			{
				sum += rooms[i].javaBeans;
				m -= rooms[i].catFood;
			}
		 }
		 printf("%.3lf\n", sum);	// 用cout 按格式输出三位小数无法AC，换成printf就成功AC  
		 cin >> m >> n;
		 	
	}
	return 0;
}
