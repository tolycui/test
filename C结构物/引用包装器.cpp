//默认utf-8保存
#pragma execution_character_set("utf-8")
#include <functional>
#include<iostream>
using std::function;
using std::cout;
using std::endl;

/*
引用包装器
一般使用在模块中，因为模板一般是不会使用引用的，若直接传入引用参数则会按值复制一份  .这时可以使用引
引用包装器进行引用。
*/
template <class T>
void com(T arg)
{
	arg++;
}
template <typename T>     //无论函数参数的类型是什么,直接传入引用 的类型, 模板不会将参数自动转化为引用类型, 而是按值传递, 复制一份参数;若使用std::ref(参数)传入参数,引用才有效;
void com222(T arg)
{
	arg++;
}


void go(int a)
{
	a++;
}

void mainTemplateRef()
{
	int count = 10;
	int &rcount = count;
	com(count);
	std::cout <<  count << std::endl;
	com(std::ref(count));  //std::ref(变量),函数模板直接引用;
	com(rcount);
	std::cout << count << std::endl;

	com222(std::ref(count));
	com222(rcount);
	std::cout << count << std::endl;

	int a = 20;
	int &ra = a;
	go(std::ref(a));
	std::cout << "a = " << a << endl;
	std::cin.get();
}