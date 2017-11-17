//默认utf-8保存
#pragma execution_character_set("utf-8")
#include<iostream>
#include<map>
// 多元数组即元组, 是一种数组结构, 使用std::get<>(元组名) 来获取特定位置的元素;  get后面的括号里面只能用常量,不能用int变量,可以用const常量;;
//常被当做结构体来使用;

void mainTuple(void)
{
	int int1 = 10;
	double double1 = 99.8;
	char ch = 'a';
	char * str = "hellochina";
	const int num = 2;
	std::tuple<int, double, char, const char *>myTuple(int1,double1,ch,str);
	auto ele0 = std::get<num>(myTuple);
	decltype(ele0) temp0;   //获取数据类型继续创建;
	//myTuple.swap(mtTuple) ;  array ,vector都有交换的功能;
}

//tuple必须是一个静态数组;