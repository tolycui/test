//默认utf-8保存
#pragma execution_character_set("utf-8")
#include <functional>
#include<iostream>
using std::function;
using std::cout;
using std::endl;

/*
函数包装器
	1.设计执行接口;接口设计关卡,计数;
	2.函数包装器依赖于函数模板,实现通用泛型;
	3,函数代码可以内嵌在另一个函数中;
	4.函数包装器,用来管理内嵌函数和外部函数;
*/

template<typename T,typename F>
T run(T t, F f)   //函数包装器
{
	static int count = 0;   //写在函数内部, 是函数内的全局变量;可以实现计数;
	count++;
	//std::cout << "run一个参数包装器执行" << count << "次" << std::endl;
	if (count > 1)
	{
		T vx(0);
		return vx;
	}

	return f(t);//函数传入参数;
}
template<typename T,typename F>    //每一个函数模板前面都要有template语句;
T run(T t1, T t2, F f)
{
	return f(t1, t2);
}


void maintemplate()
{
	double db = 12.9; //double *2
	std::function<double(double)>fun1 = [](double u)->double{return u * 2; };   //function<返回值(参数类型)> ,fun1本质是函数指针;
	cout << run(db, fun1) << endl;
	std::function<int(int, int)> fun2 = [](int a, int b)
	{
		return a*b;
	};
	int a = 2;
	int b = 3;
	cout << run(a, b, fun2) << endl;
	std::cin.get();     //等于getchar
}
