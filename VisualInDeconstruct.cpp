/*
析构函数中调用虚函数的结果
*/
#include <iostream>
using namespace std;

class A{
public:
	A(){cout<<"Con in A "<<endl;}
	virtual void show(){cout<<"Dec in A "<<endl;}
	virtual ~A(){show();}
};

class B:public A{
public:
	B(){cout<<"Con in B "<<endl;}
	void show(){cout<<"Dec in B"<<endl;}
	//~B(){show();}
};

int main(){
	A a;
	B b;
}