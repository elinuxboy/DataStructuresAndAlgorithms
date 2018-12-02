/*
 ============================================================================
 Name        : TestCase.c
 Author      : elinuxboy<elinuxboy@126.com>
 Linked      : http://www.cnblogs.com/elinuxboy
 Version     : 1.0
 Copyright   : Copyright @2018 elinuxboy Powered by eclipse in win10
 Description : 数据结构与算法C语言实现之单链表(带头结点)及其基本操作测试用例源文件
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 添加单链表及其基本操作头文件
#include "SinglyLinkedListWithHeadNode.h"

int main(void) {
    //带头结点的单链表初始化
    pHead = InitSinglyLinkedList();

    //输出链表
    DispSinglyLinkedList(pHead);

    //创建如下单链表
    DataType *pData = "abcdef";

    //头插法创建链表
    pHead = CreateSinglyLinkedListFrHead(pHead, pData,  strlen(pData));

    //尾插法创建链表
//    pHead = CreateSinglyLinkedListFrTail(pHead, pData,  strlen(pData));

    printf("链表长度为：%d\n", SinglyLinkedListLength(pHead));

    //输出链表
    DispSinglyLinkedList(pHead);

    //释放存储空间
    free(pHead);

    return EXIT_SUCCESS;
}
