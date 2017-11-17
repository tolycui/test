//默认utf-8保存
#pragma execution_character_set("utf-8")
#include <functional>
#include<iostream>
using namespace std;
using  namespace std::placeholders;


struct Mystruct2
{
	void add(int a)
	{
		cout << a << endl;
	}
	void add2(int a, int b)
	{
		cout << a + b << endl;
	}
};

void main()
{
	Mystruct2 *ms = new Mystruct2();
	int a = 10;

	auto func = bind(&Mystruct2::add, &ms, _1);  //如果别人在类内部写好了函数, 我们可以通过bind来使用它; bind返回一个函数指针;生成的函数指针的参数个数就是&Mystructs::add 函数指针地址指向的函数的参数个数;  第二个参数是绑定函数的类的实例的指针; 第三个参数是参数占位数;
	func(100);
	auto func2 = bind(&Mystruct2::add2,ms,_1,_2);
	func2(10, 20);
	std::cin.get();
}