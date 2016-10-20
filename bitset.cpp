#include <iostream>
#include <bitset>
#include <cmath>
#define N 100
using namespace std;

static bitset<N> ps;

bool isPrime(int n)
{
	if(n==2||n==3||n==5)return true;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)return false;
	}
	return true;
}

void Prime()
{
	for(int n=2;n<N;n++)
		if(isPrime(n)) ps.set(n);
}

int main ()
{
	Prime();
	cout << ps << '\n';       // 1111
	return 0;
}