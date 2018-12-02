/*
 ============================================================================
 Name        : TestCase.c
 Author      : elinuxboy<elinuxboy@126.com>
 Version     : 1.0
 Copyright   : Copyright @2018 Powerd by eclipse in win10
 Description : 不带头结点的单链表及其基本操作测试源文件 （C语言）, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//包含单链表头文件
#include "SinglyLinkedListNoHeadNode.h"

/**
 * 头插法测试用例
 * @param pList 单链表指针
 */
void testInsertInHead(SinglyLinkedList *pList){
	printf("头插法测试用例！\n");
    for (DataType i = 'a'; i <= 'z'; ++i)
    {
        insertDataInHead(pList, i);
    }

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(pList));

    displySinglyLinkedList(pList);

    printf("\n");
}

/**
 * 尾插法测试用例
 * @param pList 单链表指针
 */
void testInsertInTail(SinglyLinkedList *pList){
    printf("尾插法测试用例！\n");
    for (DataType i = 'A'; i <= 'Z'; ++i)
    {
        insertDataInTail(pList, i);
    }

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(pList));

    displySinglyLinkedList(pList);

    printf("\n");
}

/**
 * 在指定位置插入测试用例
 * @param pList 单链表指针
 */
void testInsertDataInPosition(SinglyLinkedList *pList){
    printf("在指定位置插入测试用例！\n");
    for (int i = 0; i < 10; ++i)
    {
        insertDataInPosition(pList, 'Z', i);
    }

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(pList));

    displySinglyLinkedList(pList);

    printf("\n");
}

/**
 * 删除指定位置结点测试用例
 * @param pList 链表指针
 */
void testDeleteDataInPosition(SinglyLinkedList *pList){
    printf("删除指定位置结点测试用例！\n");

    for (int i = 0; i < 5; ++i)
    {
        deleteDataInPosition(pList, i);
    }

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(pList));

    displySinglyLinkedList(pList);

    printf("\n");
}

/**
 * 单链表逆转测试用例
 * @param pList 链表指针
 */
void testReverseSinglyLinkedList(SinglyLinkedList *pList){
    printf("单链表逆转测试用例！\n");

    reverseSinglyLinkedList(pList);

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(pList));

    displySinglyLinkedList(pList);

    printf("\n");
}

/**
 * 清空单链表所有结点测试用例
 * @param pList 链表指针
 */
void testclearSinglyLinkedList(SinglyLinkedList* pList){
    printf("清空单链表所有结点测试用例！\n");

    clearSinglyLinkedList(pList);

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(pList));

    displySinglyLinkedList(pList);

    printf("\n");
}

/**
 * 测试用主函数
 * @return  成功返回0
 */
int main(void) {
    SinglyLinkedList List;

    //初始化
    initSinglyLinkedList(&List);

    printf("当前链表中结点个数为：%d\n", sizeOfSinglyLinkedList(&List));
    displySinglyLinkedList(&List);
    printf("\n");

    //头插法测试
    testInsertInHead(&List);
    //尾插法测试
    testInsertInTail(&List);

    //尾插法测试
    testInsertInTail(&List);
    //头插法测试
    testInsertInHead(&List);

    //头插法测试
    testInsertInHead(&List);
    //尾插法测试
    testInsertInTail(&List);

	//在指定位置插入测试
    testInsertDataInPosition(&List);

    //删除指定位置结点测试
    testDeleteDataInPosition(&List);

    //单链表逆转测试
    testReverseSinglyLinkedList(&List);

    //清空单链表所有结点测试
	testclearSinglyLinkedList(&List);

    return EXIT_SUCCESS;
}


