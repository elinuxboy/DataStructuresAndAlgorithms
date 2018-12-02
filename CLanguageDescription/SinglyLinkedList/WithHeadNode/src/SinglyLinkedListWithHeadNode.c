/*
 ============================================================================
 Name        : SinglyLinkedListWithHeadNode.c
 Author      : elinuxboy<elinuxboy@126.com>
 Linked      : http://www.cnblogs.com/elinuxboy
 Version     : 1.0
 Copyright   : Copyright @2018 elinuxboy Powered by eclipse in win10
 Description : 数据结构与算法C语言实现之单链表(带头结点)及其基本操作源文件
 ============================================================================
 */
#include "SinglyLinkedListWithHeadNode.h"

#include <stdio.h>
#include <stdlib.h>

// 添加单链表及其基本操作头文件

/**
 * 初始化单链表，创建一个带头结点的空链表
 * @return 链表头指针
 */
SinglyLinkedList *InitSinglyLinkedList() {
    // 申请存储空间可使用malloc()函数实现，需设立一申请单元指针，这里是头指针pHead，
    // 但malloc()函数得到的指针并不是指向结构体的指针，因此，需使用强制类型转换，
    // 将其转换成结构体型指针。
    pHead = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    // 刚开始时，链表还没建立，是一空链表，pHead结点的next指针为NULL。
    pHead->next = NULL;

    return pHead;
}

/**
 * 判断链表是否为空
 * @param  pHead 链表头指针
 * @return       1为空，0不为空
 */
int IsEmpty(SinglyLinkedList *pHead)
{
    return (NULL == pHead->next);
}

/**
 * 头插法创建单链表
 * 如：pHead-->d-->c-->b-->a-->NULL [逆序]
 * @param  pHead     链表头指针
 * @param  pData    要插入数据的指针
 * @param  dataCount 要插入数据的数量
 * @return          插入后链表的头指针
 */
SinglyLinkedList *CreateSinglyLinkedListFrHead(SinglyLinkedList *pHead, DataType *pData,
        int dataCount) {
    //创建一个搜索结点，用于遍历链表
    SinglyLinkedList *pCurrent = pHead;

    for (int i = 0; i < dataCount; i++) {
        // 创建新结点pInsertNode用于存放要插入的数据
        SinglyLinkedList *pInsertNode = (SinglyLinkedList *) malloc(
                sizeof(SinglyLinkedList));
        pInsertNode->data = pData[i];

        // 将pInsertNode插在原结点之前,前驱结点之后
        // 因为每个结点的地址都是存放在其前驱结点的指针域next中
        pInsertNode->next = pCurrent->next;        //原结点之前
        pCurrent->next = pInsertNode;        //前驱节点结点之后
    }

    return pHead;
}

/**
 * 尾插法建立单链表
 * 例如：pHead-->a-->b-->c-->d-->NULL [顺序]
 * @param  pHead     链表头指针
 * @param  pData     要插入的数据指针
 * @param  dataCount 要插入的数据数量
 * @return           插入后的链表头指针
 */
SinglyLinkedList * CreateSinglyLinkedListFrTail(SinglyLinkedList *pHead, DataType *pData,
        int dataCount) {
    //创建搜索指针pCurrent用于遍历链表
    SinglyLinkedList *pCurrent = pHead;

    //遍历链表
    for (int i = 0; i < dataCount; i++) {
        //创建新结点pInsertNode用于保存要插入的数据
        SinglyLinkedList *pInsertNode = (SinglyLinkedList *) malloc(
                sizeof(SinglyLinkedList));
        pInsertNode->data = pData[i];

        //将pInsertNode插入pCurrent之后
        pCurrent->next = pInsertNode;
        //pCurrent始终指向尾结点
        pCurrent = pInsertNode;
    }

    //插入完成后，尾结点的next域置为NULL
    pCurrent->next = NULL;

    return pHead;
}

/**
 * 输出链表中的数据
 * @param pHead 链表头指针
 */
void DispSinglyLinkedList(SinglyLinkedList *pHead) {
    if (IsEmpty(pHead))
    {
        printf("链表为空！\n");
        return;
    }

    //创建搜索结点pCurrent用于遍历链表
    //因为头结点中不存放数据，所以需要跳过头结点
    SinglyLinkedList *pCurrent = pHead->next;

    //遍历链表
    while (pCurrent != NULL) {
        printf("%c ", pCurrent->data);
        pCurrent = pCurrent->next;
    }

    printf("\n");
}

/**
 * 输出链表的长度
 * @param  pHead [description]
 * @return       [description]
 */
int SinglyLinkedListLength(SinglyLinkedList *pHead)
{
    int ListLength = 0;
    SinglyLinkedList *pCurrent = pHead;
    while (NULL != pCurrent->next)
    {
        ListLength++;
        pCurrent = pCurrent->next;
    }

    return ListLength;
}

/*
void DestroySinglyLinkedList(SinglyLinkedList *pHead)
{
    SinglyLinkedList *p = pHead, *q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }

    free(p); //此时q为NULL, p指向尾结点,释放它
}*/
