/**
这道题源于剑指offer面试题43
妙哉
使用递归求解
使用规律求解
2016-10-26
*/
#include <iostream>
#include <cmath>
using namespace std;

void probability(int current, int sum, int* P)//递归求解每种点数出现的次数
{
	if(current == 1) P[sum]++;
	else for (int i = 1; i <= 6; ++i) probability(current-1, sum+i, P);
}

void printposibility(int num)
{
	if(num<1) return ;
	int total = pow(6,num);//总共可能出现的次数
	int maxSum = num * 6;
	int *P = new int[maxSum + 1];
	for (int i = 0; i <= maxSum; ++i) P[i]=0;
	for (int i = 1; i <= 6; ++i) probability(num, i, P);
	for (int i = num; i <= maxSum; ++i) cout<<i<<"\t"<<(double)P[i]/total<<endl;//输出概率
	delete []P;
}

int main()
{
	int n=3;
	printposibility(n);
	return 0;
}