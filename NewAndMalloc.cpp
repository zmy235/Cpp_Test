/*
new和malloc的区别
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
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
	void Initialize( )
	{ 
		cout << "Initialization" << endl; 
	}
	void Destroy( )
	{ 
		cout << "Destroy" << endl; 
	}
};

void UseMallocFree( )
{
	Obj * a = (Obj *) malloc( sizeof ( Obj ) );
	a -> Initialize();
	delete a; 
	//free(a);
	//a -> Destroy();
}

void UseNewDelete( )
{
	Obj * a = new Obj; 
	//delete a; 
	free(a);
	a -> Destroy();
}

int main(int argc, char const *argv[])
{
	UseNewDelete();
	UseMallocFree();
	return 0;
}