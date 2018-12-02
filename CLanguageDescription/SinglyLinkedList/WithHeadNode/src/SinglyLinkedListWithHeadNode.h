/*
 ============================================================================
 Name        : SinglyLinkedListWithHeadNode.h
 Author      : elinuxboy<elinuxboy@126.com>
 Linked      : http://www.cnblogs.com/elinuxboy
 Version     : 1.0
 Copyright   : Copyright @2018 elinuxboy Powered by eclipse in win10
 Description : 数据结构与算法C语言实现之单链表(带头结点)及其基本操作头文件
 ============================================================================
 */
#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

//定义结点数据域的类型
typedef char DataType;

//定义结点
typedef struct Node {
    DataType data; //数据域
    struct Node *next; //指针域
} Node;

//定义SinglyLinkedList类型变量表示单链表
//注意：Node和SinglyLinkedList是不同名字的同一个类型（命名的不同是为了概念上更明确）
typedef struct Node SinglyLinkedList;

//显示定义SinglyLinkedList类型的指针变量*pHead表示它是单链表的头指针
SinglyLinkedList *pHead;

/**
 * 初始化单链表，创建一个带头结点的空链表
 * @return 链表头指针
 */
SinglyLinkedList *InitSinglyLinkedList();

/**
 * 判断链表是否为空
 * @param  pHead 链表头指针
 * @return       1为空，0不为空
 */
int IsEmpty(SinglyLinkedList *pHead);

/**
 * 头插法创建单链表
 * 如：pHead-->d-->c-->b-->a [逆序]
 * @param  pHead     链表头指针
 * @param  pData    要插入数据的指针
 * @param  dataCount 要插入数据的数量
 * @return          插入后链表的头指针
 */
SinglyLinkedList *CreateSinglyLinkedListFrHead(SinglyLinkedList *pHead, DataType *pData,
        int dataCount);

/**
 * 尾插法建立单链表
 * 例如：pHead-->a-->b-->c-->d-->NULL [顺序]
 * @param  pHead     链表头指针
 * @param  pData     要插入的数据指针
 * @param  dataCount 要插入的数据数量
 * @return           插入后的链表头指针
 */
SinglyLinkedList * CreateSinglyLinkedListFrTail(SinglyLinkedList *pHead, DataType *pData,
        int dataCount);

/**
 * 输出链表的长度
 * @param  pHead [description]
 * @return       [description]
 */
int SinglyLinkedListLength(SinglyLinkedList *pHead);

/**
 * 输出链表中的数据
 * @param pHead 链表头指针
 */
void DispSinglyLinkedList(SinglyLinkedList *pHead);

#endif /* SINGLYLINKEDLIST_H_ */
