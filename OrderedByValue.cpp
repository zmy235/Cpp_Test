/**
c++ map中按Value排序
2016-10-30
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> PAIR;
ostream& operator<<(ostream& out, const PAIR& p) 
{
	return out << p.first << "\t" << p.second;
}
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) 
{
	return lhs.second < rhs.second;
}
int main() 
{
	map<string, int> myMap;
	myMap["LiMin"] = 90;
	myMap["ZiLinMi"] = 79;
	myMap["BoB"] = 92;
	myMap.insert(make_pair("Bing",99));
	myMap.insert(make_pair("Albert",86));
	//把map中元素转存到vector中
	vector<PAIR> vec(myMap.begin(), myMap.end());
	sort(vec.begin(), vec.end(), cmp_by_value);
	// sort(vec.begin(), vec.end(), CmpByValue());//CmpByValue为一个类
	for (int i = 0; i != vec.size(); ++i) 
	{
		cout << vec[i] << endl;
	}
	return 0;
}