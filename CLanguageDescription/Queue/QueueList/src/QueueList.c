/*
 ============================================================================
 Name        : QueueList.c
 Author      : elinuxboy<elinuxoby@126.com>
 Version     : 1.0
 Copyright   : Copyright @2018 Powered by eclipse in win10
 Description : 顺序队列
				 使用顺序存储结构表示队列时，首先申请足够大的内存空间建立一个数组，
				 此外，为了满足队列从对位存入，从对头删除数据元素，
				 还需要定义两个指针分别作为头指针和尾指针。
				 当有数据元素进入队列时，将数据元素存放到队尾指针指向的位置，然后队尾指针增加1；
				 当删除对头元素（即使想删除的是队列中的元素，也必须从对头开始一个个删除）时，
				 只需要移动头指针的位置就可以了。
				 顺序表示是在数组中操作元素，由于数组本身有下标，
				 所以队列的头指针和尾指针合一用数组下标来代替，
				 即实现了目的，又简化了程序。
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int enQueue(int *a, int rear, int data) {
	a[rear] = data;
	rear++;

	return rear;
}

void deQueue(int *a, int front, int rear) {
	// 如果front==rear，表示对列为空
	while (front != rear) {
		printf("%d\n", a[front]);
		front++;
	}
}

int main() {
	int a[100];
	int front, rear;

	// 设置对头指针和队尾指针，当队列中没有元素时，
	// 对头指针和队尾指针指向同一块地址
	front = rear = 0;

	// 入队
	rear = enQueue(a, rear, 1);
	rear = enQueue(a, rear, 2);
	rear = enQueue(a, rear, 3);
	rear = enQueue(a, rear, 4);

	//出队
	deQueue(a, front, rear);

	return 0;
}
