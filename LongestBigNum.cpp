#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int nums[10]={9,-5,-3,8,-8,1,-1,4,3,3};
	int value[10];
	value[0] = nums[0]>0 ? nums[0] : 0;
	int max=value[0];
	for (int i = 1; i < 10; ++i)
	{
		if(value[i-1]+nums[i]>0)
		{
			value[i]=value[i-1]+nums[i];
			max=max>value[i]?max:value[i];
		}
		else
		{
			value[i]=0;
		}
	}
	cout<<max<<endl;
	return 0;
}