/**
c++ map中按K排序
2016-10-30
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef pair<string, int> PAIR;
ostream& operator<<(ostream& out, const PAIR& p) 
{
	return out << p.first << "\t" << p.second;
}
int main() 
{
	map<string, int> myMap;
	myMap["LiMin"] = 90;
	myMap["ZiLinMi"] = 79;
	myMap["BoB"] = 92;
	myMap.insert(make_pair("Bing",99));
	myMap.insert(make_pair("Albert",86));
	for (auto i = myMap.begin(); i != myMap.end(); ++i) 
	{
		cout << *i << endl;
	}
	return 0;
}