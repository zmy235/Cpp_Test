/**
这道题源于剑指offer面试题46
解法有：
1.利用构造函数
2.利用虚函数
3.利用函数指针
4.利用模板类（编译器对递归深度有所限制，n不允许太大）
2016-10-26 VEIZI
*/

#include <iostream>
using namespace std;

class A;
A* array[2];

class A
{
public:
	virtual int sum(int n)
	{
		return 0;
	}

};

class B: public A
{
public:
	virtual int sum(int n)
	{
		return array[!!n]->sum(n-1)+n;//!!n表示当n为0时，调用array[0],当n不为0时调用array[1]
	}
};

int main(int argc, char const *argv[])
{
	array[0]=new A();
	array[1]=new B();
	cout<<array[1]->sum(5)<<endl;
	return 0;
}