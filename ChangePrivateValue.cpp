#include <iostream>
/*
篡改私有属性方式
*/
#define private public    // 万恶的宏伎俩啊

using namespace std;

class A
{
public:
    A(): i(10){}
    void print(){ cout << "A::i = " << i << endl; }

private:
    int i;
    //const int i;
};

int main()
{
    A a;

    int* p = (int*)&a;           // 突破编译器的防线
    a.print();

    a.i = 50;
    a.print();

    reinterpret_cast<int>(a.i) = 60;
    a.print();

    *p = 30;                     // 偷偷修改a 对象私有成员的值
    a.print();

    return 0;
}