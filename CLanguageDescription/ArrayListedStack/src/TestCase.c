/*
 ============================================================================
 Name        : TestCase.c
 Author      : elinuxboy<elinuxboy@126.com>
 Version     : 1.0
 Copyright   : Copyright @ 2018 powered by eclipse-cpp-2018-09
 Description : 顺序栈的实现（采用数组）测试用例源文件
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//包含顺序栈的实现（采用数组）头文件
#include "ArrayListedStack.h"

/**
 * 入栈测试用例
 * @param arrayListedStack 栈指针
 * @param top              栈顶
 */
void TestCasePushStack(DATA_TYPE *arrayListedStack, int *top) {
	//将小写字母逐个压栈，直到栈满。
	for (int iLoop = 0; iLoop < MAX_LEN; iLoop++) {
		for (DATA_TYPE data = 'a'; data <= 'z'; ++data) {
			if (OVERFLOW == push(arrayListedStack, top, data)) {
				printf("'%c'入栈失败，当前栈顶变量top = %d\n", data, *top);
				return; //入栈失败则退出循环
			} else {
				printf("'%c'入栈成功，当前栈顶变量top = %d\n", data, *top);
			}
		}
	}
}

/**
 * 出栈测试用例
 * @param arrayListedStack 栈指针
 * @param top              栈顶
 */
void TestCasePopStack(DATA_TYPE *arrayListedStack, int *top) {
	//逐个出栈直到栈空
	for (int iLoop = 0; iLoop < MAX_LEN; iLoop++) {
		if (EMPTY == pop(arrayListedStack, top)) {
			break; //出栈失败则退出循环
		}
	}
}

/**
 * 主函数
 * @return  成功则返回0
 */
int main(void) {
	//定义一个含有MAX_LEN个字符数据的顺序栈arrayListedStack，并初始化
	DATA_TYPE arrayListedStack[MAX_LEN];
	memset(arrayListedStack, 0, MAX_LEN); //栈初始化

	//在顺序栈中设定一个随时指向栈顶元素的变量（一般命名为 top ），从0开始。
	//当top的值为-1时，说明数组中没有数据，即栈中没有数据元素，为“空栈”；
	int top = EMPTY;

	//显示栈的内容
	display(arrayListedStack, &top);

	//入栈测试
	TestCasePushStack(arrayListedStack, &top);

	//显示栈的内容
	display(arrayListedStack, &top);

	//出栈测试
	TestCasePopStack(arrayListedStack, &top);

	//显示栈的内容
	display(arrayListedStack, &top);

	return OK;
}
