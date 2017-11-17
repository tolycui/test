//默认utf-8保存
#pragma execution_character_set("utf-8")

#include<iostream>
#include <array>
#include <vector>
using std::array;   //静态数组,在栈上
using std::vector;  //动态数组,堆上;
//在C语言中一个数组的大小超过1M就会栈溢出;
//这里要做的就是避免栈溢出;

void  mainvector()
{
	array<int, 5>myint = { 1, 2, 3, 4, 5 };
	//array<double, 1024 * 1024> mydouble; //这个语句会造成栈溢出;
	std::vector<double>myVector;
	for (int i = 0; i < 1024 * 1024;i++)
	{
		myVector.push_back(i);
	}
	array<array<int, 5>, 3> myint2 = { myint, myint, myint };

	std::cin.get();
}