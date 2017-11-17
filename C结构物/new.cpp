//默认utf-8保存
#pragma execution_character_set("utf-8")

#include<iostream>
#include <new>
const int buf(512);
int N(5);  //数组长度;
char buffer[buf] = { 0 };  //静态区

void mainnew()
{
	double *p1, *p2;
	for (int m = 0; m < 3;m++)
	{
		std::cout << "\n\n\n";
		p1 = new double[N];
		p2 = new (buffer)double[N];    //指定区域分配内存;new的高级用法;这样指定的区域,在下次new的时候会自动覆盖掉原先的内容;

		for (int i = 0; i < N; i++)
		{
			p1[i] = p2[i] = i + 10.8;//对于数组初始化
			std::cout << "p1 =" << &p1[i] << " " << p1[i] << " ";
			std::cout << "p2 =" << &p2[i] << " " << p2[i] << std::endl;
		}
	}

	std::cin.get();
}
