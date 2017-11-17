//默认utf-8保存
#pragma execution_character_set("utf-8")
#include <iostream>
using namespace std;

/*改变函数指针的两种方式:
1.用指向指针的指针
2.用函数指针的引用
*/

int jia(int a, int b)
{
	return a + b;
}

int jian(int a, int b)
{
	return a - b;
}

/*
以函数指针引用为参数的函数change
*/
void change(int(* &p)(int, int))   //使用引用做参数,不会复制值,引用变量会改变地址内的值;
{
	p = jian;
}

/*
返回值是函数指针引用的函数
*/
int(*& changeb(int(*p)(int,int)))(int, int)
{
	p = jian;
	return p;
}
/*
左值引用: 
	int a = 1;
	int &ap = a;
右值引用: 
	int &&bp = 1;
变量m为左值, m+1为右值;
右值引用的好处: 
	如果对象在寄存器(缓存)中, 不在内存中,不需要拷贝到内存就可以直接操作对象
	内存优化所必须;
	*/
int getdata(int&& num)   //右值引用为参数的函数
{
	cout << num << endl;
	num += 10;
	return num;
}

void main1()
{
	//普通引用
	int b = 10;
	int bb = 20;
	int (&rb)=(b);    //初始化可以用等号;
	rb = bb;
	cout << rb<<b << endl;
	//数组引用
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	int(&ra)[10](a);  //初始化可以直接用括号
	int i = 0;
	for (auto data:ra) //注意C++11新的循环是值复制;
	{
		data = i + 5;
		std::cout << data << std::endl;
	}
	//ra和a数组的值都没被改变;
	for (int j = 0; j < 9; j++)
	{
		printf("%d\n", a[j]);
		printf("%d,\n", ra[j]);
	}
	//用cout输出数组都是输出地址,再加地址符号也是输出地址;
	std::cout << a << ra << std::endl;
	std::cout << &a << &ra << std::endl;

	//二维数组引用;
	int c[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int(&rc)[2][5](c);

	int(*p)(int a, int b)(jia);//初始化函数指针p
	std::cout << p(1, 2) << std::endl;
	int(*&rp)(int a, int b)(p);   //引用函数指针, 是函数指针的引用
	rp = jian;          //引用变量不能重定义,这里是将
	change(p);          
	std::cout<<changeb(p)(2,4)<<std::endl;
	std::cout << p(1, 2) << std::endl;

	int &&d = 1;    //右值引用
	int tempb = 4;
	cout << getdata(tempb + 1) << endl;   //tempb是左值,tempb + 1是右值
	system("pause");
}


//左值,一般可以取地址的就是左值,
//右值某些情况可以取地址,有些情况不行;
void main2()
{
	int a = 3;
	int b = a + 1;  //右值->左值;
	std::cout << getdata(std::move(a)) << endl;   //std::move()将左值转化为右值;
}


void main3()
{
	const int num = 6;
	char str[10]("hello");
	char str2[10]("hello");
	const char*pc(str);
	pc = str2;
	char *const pc2(str);
	pc2[2] = '2';

	system("pause");
}

void main4()
{
	char str[10]("hello");
	const char(&rstr)[10](str);//常量引用;
	const char(&rrstr)[10](rstr);//常量引用;
	str[4] = 'y';
	//rstr[4] = 'x'; //这个语句编译不过, 因为引用是常引用;
	std::cout << str[4] << endl;
	std::cout << rstr[4] << endl;
	std::cout << rrstr[4] << endl;
	system("pause");
}
 

void main8()
{
	int(*p)(int , int )(jia);
	std::cout << p(1, 2) << endl;
	int(*const&rp)(int a, int b)(p);//变量rp本来就不能改变, const加在&后面就没用, const加在&前面,则rp的引用值就不能改变,即指针p的值不能改变;
	//rp = jian;   //这个语句编译不过

}

