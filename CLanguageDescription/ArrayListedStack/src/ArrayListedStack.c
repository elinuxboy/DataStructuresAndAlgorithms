/*
 ============================================================================
 Name        : ArrayListedStack.c
 Author      : elinuxboy<elinuxboy@126.com>
 Version     : 1.0
 Copyright   : Copyright @ 2018 powered by eclipse-cpp-2018-09
 Description : 顺序栈的实现（采用数组）源文件
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//包含顺序栈的实现（采用数组）头文件
#include "ArrayListedStack.h"

/**
 * 数据元素elem进栈
 * @param  arrayListedStack    栈指针
 * @param  top  入栈前的栈顶变量
 * @param  elem 要入栈的数据
 * @return      成功则返回0，栈溢出则返回-2
 */
int push(DATA_TYPE *arrayListedStack, int *top, DATA_TYPE elem) {
	if (!(MAX_LEN - *top - 1)) {
		printf("该栈已满！\n\n");
		return OVERFLOW;
	}

	// 只要数据元素进栈，top 就加 1 ；
	arrayListedStack[++(*top)] = elem;

	return OK;
}

/**
 * 出栈
 * @param  arrayListedStack   栈指针
 * @param  top 出栈前的栈顶变量
 * @return     成功则返回0，空栈则返回-1
 */
int pop(DATA_TYPE *arrayListedStack, int *top) {
	if (EMPTY == *top) {
		printf("该栈已空！\n\n");
		return EMPTY;
	}

	printf("弹出栈元素：%c\n", arrayListedStack[*top]);
	memset(&arrayListedStack[*top], 0, 1); //清除
	*top -= 1;

	return OK;
}

/**
 * 显示当前栈的内容
 * @param arrayListedStack 栈指针
 * @param top              栈顶
 */
void display(DATA_TYPE *arrayListedStack, int *top) {
	if (EMPTY == *top) {
		printf("\n当前栈为空栈！\n\n");
		return;
	}

	printf("\n当前栈的内容为：");
	for (int iLoop = 0; iLoop < MAX_LEN; iLoop++) {
		printf("%c ", arrayListedStack[iLoop]);
	}
	printf("\n\n");
}
