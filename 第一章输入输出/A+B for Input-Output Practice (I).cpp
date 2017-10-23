/****************************************************************************************
 Your task is to Calculate a + b.Too easy?! Of course! 
 I specially designed the problem for acm beginners. 
 You must have found that some problems have the same titles with this one, 
 yes, all these problems were designed for the same aim. 
 Input: 
 The input will consist of a series of pairs of integers a and b, separated by a space,
 one pair of integers per line.
 output:
 For each pair of input integers a and b you should output the sum of a and b in one line, 
 and with one line of output for each line in input.
 Sample Input:
 1 5
 10 20
 Sample Output
 6
 30
 ******************************************************************************************/
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	int a, b;
 	while(cin >> a >> b)                         //读入a,b的值直到遇到文件结束符 
 	{
 		cout << a + b << endl;	
	}
	
	return 0;
 }
 

