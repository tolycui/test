//默认utf-8保存
#pragma execution_character_set("utf-8")
#include <functional>
#include<iostream>
using std::function;
using std::cout;
using std::endl;

/*
通用的可变参数模板
	当游戏要载入多个人物,而人物的个数和类型不限
*/
void showall()   //空函数,这里要用通用模板必须预留这个接口;因为最后一个通用数据类型会为空,为空时结束下面的递归;
{

}

template<typename T , typename...Args>//Args是通用的数据类型
void showall(const T &value, const Args &...args)
{
	std::cout << value << std::endl;
	showall(args...);//继续传递,当最后一次只传一个参数进来是args会为空;
}

//设计可以修改原来的数据的 T &value ,Args &...args
//设计不可以修改原来数据,可以修改副本   T value, Args ...args
//设计不可以修改原来数据,不可以修改副本  const T value, const Args...args
//设计引用原来的数据不可以修改   const T&value,const Args&...args;

void maintemplateArgs()
{
	int num1 = 10, num2 = 9, num3 = 11;
	int num4[4] = { 54, 25, 3, 5};
	double db1 = 10.8, db2 = 10.9;
	char str[40] = "yincheng";
	char ch = 'A';
	//showall(num1);
	showall(num1, num2, num3);
	//showall(db1, db2, num1, ch, str);
	showall(num4);   //直接传入数组的话,数组会直接被当做一个参数使用;
	std::cin.get();
}