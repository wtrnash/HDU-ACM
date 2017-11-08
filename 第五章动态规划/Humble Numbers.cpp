/********************************************************************************************************************************************************
Problem Description
A number whose only prime factors are 2,3,5 or 7 is called a humble number. 
The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.
Write a program to find and print the nth element in this sequence
Input
The input consists of one or more test cases. 
Each test case consists of one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n.
Output
For each test case, print one line saying "The nth humble number is number.". 
Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.
Sample Input
1
2
3
4
11
12
13
21
22
23
100
1000
5842
0
Sample Output
The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000.
***********************************************************************************************************************************************************/
//��̬�滮���⣬���ǵ�ǰ����������֮ǰ�ĳ���*2����*3 ��*5 �� *7�õ��ģ�������1 Ϊ��ʼ����һ���������ǣ�1*2,1*3,1*5,1*7���е���Сֵ
//Ȼ������һ������Ϊ2��Ҳ����1 * 2����ô�±���³�2, ���¸���������(2*2, 1*3, 1*5,1*7)�е���Сֵ���Դ����ơ���������5842���������ɡ�
//���ʱ�ǵö�10��������1,2,3 �Ҷ�100����������11,12,13 ����� st,nd�Լ�rd�� 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int number[5843];
	number[1] = 1;
	int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
	//�ö�̬�滮���5842������
	for(int i = 2; i < 5843; i++)
	{
		number[i] = min(number[p2] * 2, min(number[p3] * 3, min(number[p5] * 5, number[p7] * 7)));	
		
		if(number[i] == number[p2] * 2)
			p2++;
		if(number[i] == number[p3] * 3)
			p3++;
		if(number[i] == number[p5] * 5)
			p5++;
		if(number[i] == number[p7] * 7)
			p7++;
	} 
	
	cin >> n;
	while(n != 0)
	{
		if(n % 10 == 1 && n % 100 != 11)      
			cout << "The " << n << "st humble number is " << number[n] << "." << endl;
        else if(n % 10 == 2 && n % 100 != 12)
            cout << "The " << n << "nd humble number is " << number[n] << "." << endl;
        else if(n % 10 == 3 && n % 100 != 13)
            cout << "The " << n << "rd humble number is " << number[n] << "." << endl;
        else
            cout << "The " << n << "th humble number is " << number[n] << "." << endl;
	
		cin >> n;	
	}
	return 0;	
} 
