#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count=0;
	int m=0x00000000;//正0
	int x=0x7FFFFFFF;//正2147483647
	int n=0x80000000;//负0 -2147483648
	int y=0xFFFFFFFF;//负1

	cout<<"M:"<<m<<endl;
	cout<<"N:"<<n<<endl;
	cout<<"M==N:"<<(n==m)<<endl;//正0与负0不相等，此处的负零其实是最小的负数

	cout<<"N<<1:"<<(n<<1)<<endl;//负0左移一位变成0
	cout<<"N-1:"<<n-1<<endl;//负0减去1变成最大正数

	cout<<"X+1:"<<x+1<<endl;//正2147483647 + 1变成最小负数

	while(n)
	{
		count++;
		n=(n-1)&n;
	}

	cout<<"Count:"<<count<<endl;

	return 0;
}
