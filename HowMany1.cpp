#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


int PowerBase10(int n)
{
	int result = 1;
	for(int i=0;i<n;i++)
	{
		result*=10;
	}
	return result;

}
int numberOf1(const char* str)
{
	if(!str||*str<'0'||*str>'9'||*str=='\0')
		return 0;
	int first = *str-'0';
	int length = static_cast<int> (strlen(str));
	if(length==1&&first==0){return 0;}
	if(length==1&&first<0){return 1;}
	int numFirstDigit=0;
	if (first>1)
	{
		numFirstDigit=PowerBase10(length-1);
	}else if (first==1)
	{
		numFirstDigit=atoi(str+1)+1;
	}
	int numOtherDigit=first * (length-1)*PowerBase10(length-2);
	int numRecursive=numberOf1(str+1);
	return numFirstDigit + numOtherDigit + numRecursive;
}
int numberOf1between1andn(int n)
{
	if (n<=0)
	{
		return 0;
	}
	char str[20];
	sprintf(str,"%d",n);
	return numberOf1(str);
}



int main(int argc, char const *argv[])
{
	int i=1234;
	cout<<numberOf1between1andn(i);
	return 0;
}