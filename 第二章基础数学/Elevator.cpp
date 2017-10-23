/*********************************************************************************************************************************
Problem Description
The highest building in our city has only one elevator. 
A request list is made up with N positive numbers.
The numbers denote at which floors the elevator will stop, in specified order.
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. 
The elevator will stay for 5 seconds at each stop.
For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
Input:
There are multiple test cases. Each case contains a positive integer N, followed by N positive numbers. 
All the numbers in the input are less than 100. A test case with N = 0 denotes the end of input. 
This test case is not to be processed.
Output:
Print the total time on a single line for each test case. 
Sample Input:
1 2
3 2 3 1
0
Sample Output:
17
41
**********************************************************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int floor, currentFloor;          //记录下一个要去的楼层和当前的楼层 
	int time;
	cin >> n;
	while(n != 0)										//到0后结束读入 
	{
		currentFloor = 0;
		time = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> floor;
			if(floor > currentFloor)					//要去的楼层比当前的楼层高，则加上他们之间的差乘以6，否则则要下降，加上他们的差乘以4 
			{
				time += (floor - currentFloor) * 6;
			}
			else
				time += (currentFloor - floor) * 4;
			
			time += 5;									//根据题目要求，无论如何每一个层数都要停5秒，即使是连续两次停在同一楼层 
			currentFloor = floor;						//更新当前楼层 
		}
		cout << time << endl;
		cin >> n;
	}
	
	return 0;
}
