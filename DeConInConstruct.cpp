/*
在析构函数中调用构造函数
*/
#include <iostream>
using namespace std;

class Obj
{
public:
	Obj( ) 
	{ 
		cout << "Construct" << endl; 
	}
	~ Obj( )
	{ 
		cout << "Deconstruct" << endl; 
	}
	Obj( Obj& ) 
	{ 
		cout << "Construct" << endl; 
	}
};

int main(int argc, char const *argv[])
{
	Obj o;
	return 0;
}