/*
 ============================================================================
 Name        : ArrayListedStack.h
 Author      : elinuxboy<elinuxboy@126.com>
 Version     : 1.0
 Copyright   : Copyright @ 2018 powered by eclipse-cpp-2018-09
 Description : 顺序栈的实现（采用数组）头文件
 ============================================================================
 */

#ifndef ARRAYLISTEDSTACK_H_
#define ARRAYLISTEDSTACK_H_

//定义栈里面数据的类型
typedef char DATA_TYPE;

//定义栈的容量
#define MAX_LEN 10

//定义成功
#define OK 0
//定义栈溢出
#define OVERFLOW -2
//定义空栈
#define EMPTY -1

/**
 * 数据元素elem进栈
 * @param  arrayListedStack    栈指针
 * @param  top  入栈前的栈顶变量
 * @param  elem 要入栈的数据
 * @return      成功则返回0，栈溢出则返回-2
 */
int push(DATA_TYPE *arrayListedStack, int *top, DATA_TYPE elem);

/**
 * 出栈
 * @param  arrayListedStack   栈指针
 * @param  top 出栈前的栈顶变量
 * @return     成功则返回0，空栈则返回-1
 */
int pop(DATA_TYPE *arrayListedStack, int *top);

/**
 * 显示当前栈的内容
 * @param  arrayListedStack 栈指针
 */
void display(DATA_TYPE *arrayListedStack, int *top);

#endif /* ARRAYLISTEDSTACK_H_ */
