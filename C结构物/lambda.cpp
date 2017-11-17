//默认utf-8保存
#pragma execution_character_set("utf-8")
#include <iostream>
#include<vector>
#include<algorithm>  //算法algorihm

void mainlambda()
{
	std::vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	int res =0 ;   //结果
	std::for_each(myVector.begin(), myVector.end(), [&res](int x){res += x; });
	std::cout << res;
	std::cin.get();

}