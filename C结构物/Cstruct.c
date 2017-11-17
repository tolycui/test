/*

[大数乘法算法]

两个字符串格式的数相乘,得到新的字符串数

*/

//默认utf-8保存
#pragma execution_character_set("utf-8")
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//C语言结构体声明变量要加上struct
//C语言结构内部不可以有函数;
//C语言结构体没有公有,私有,继承.
struct Mystruct
{
	int num1;
	int mum2;
};

void TwoNum(char* num1, char* num2);
//void main()
//{
//	struct Mystruct struct1;
//	char num1[100] = "0";
//	char num2[100] = "0";
//	scanf("%s", num1);
//	scanf("%s", num2);
//	//printf("%s\n%s\n", num1, num2);
//	TwoNum(num1, num2);
//	system("pause");
//}


void TwoNum(char* num1, char* num2)
{
	int lengtha = strlen(num1);
	int lengthb = strlen(num2);
	int length = lengtha + lengthb;
	int *numTemp=(int*)malloc(sizeof(int)*(lengtha+lengthb));
	memset(numTemp, 0, sizeof(int)*(lengtha + lengthb));
	for (int i = 0; i < lengtha;i++)
	{
		if ((num1[i]-'0')==0)
		{
			continue;
		}
		for (int j = 0; j < lengthb;j++)
		{
			if ((num2[j] - '0') == 0)
			{
				continue;
			}
			numTemp[i + j+1] += (num1[i] - '0')*(num2[j] - '0');
		}
	}
	for (int i = length-1; i>0;i--)
	{
		numTemp[i - 1] += numTemp[i] / 10;
		numTemp[i] %= 10;
	}
	int i = 0;
	while (numTemp[i] == 0)
	{
		i++;
	}
	int j;
	char * strNum = (char*)malloc(sizeof(char)*length);
	for (j = 0; i < length;j++,i++)
	{
		strNum[j] = numTemp[i] + '0';
	}
	strNum[j] = '\0';
	printf("%s\n", strNum);
	free(strNum);
	free(numTemp);
}

