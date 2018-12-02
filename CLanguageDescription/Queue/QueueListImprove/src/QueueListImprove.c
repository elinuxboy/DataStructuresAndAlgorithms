/*
 ============================================================================
 Name        : QueueListImprove.c
 Author      : elinuxboy<elinuxoby@126.com>
 Version     : 1.0
 Copyright   : Copyright @2018 Powered by eclipse in win10
 Description : 顺序队列升级版
 	 	 	 	 使用数组存取数据元素时，可以将数组申请的空间想象成首位链接的环状空间使用。
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define max 5

int enQueue(int *a, int front, int rear, int data) {
	// 循环队列中，如果头指针和尾指针重合，证明数组存放的数据已满
	if ((rear + 1) % max == front) {
		printf("空间已满\n");
		return rear;
	}

	a[rear % max] = data;
	rear++;

	return rear;
}

int deQueue(int *a, int front, int rear) {
	// 如果front==rear，表示队列已空
	if (front == rear) {
		printf("队列为空\n");
		return front;
	}

	printf("%d", a[front]);
	front = (front + 1) % max;

	return front;
}

int main() {
	int a[max];
	int front, rear;

	// 设置队列头指针和尾指针，当队列中没有元素时，
	// 队列头和队列尾指向同一块地址
	front = rear = 0;

	//入队
	rear = enQueue(a, front, rear, 1);
	rear = enQueue(a, front, rear, 2);
	rear = enQueue(a, front, rear, 3);
	rear = enQueue(a, front, rear, 4);

	//出队
	front = deQueue(a, front, rear);

	rear = enQueue(a, front, rear, 5);

	front = deQueue(a, front, rear);

	rear = enQueue(a, front, rear, 6);

	front = deQueue(a, front, rear);
	front = deQueue(a, front, rear);
	front = deQueue(a, front, rear);
	front = deQueue(a, front, rear);

	return 0;
}
