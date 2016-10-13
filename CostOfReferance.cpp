/*
引用的开销计算
*/

#include <iostream>
using namespace std;

class A
{
    int& a;
    int& b;
    int& c;
    int& d;
    int e;
    int* f;
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(int&) << endl;
    cout << sizeof(int*) << endl;

    return 0;
}