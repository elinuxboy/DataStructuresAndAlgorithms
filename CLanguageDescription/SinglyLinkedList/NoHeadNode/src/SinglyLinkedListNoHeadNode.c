/*
 ============================================================================
 Name        : SinglyLinkedListNoHeadNode.c
 Author      : elinuxboy<elinuxboy@126.com>
 Version     : 1.0
 Copyright   : Copyright @2018 Powered by eclipse in win10
 Description : 不带头结点的单链表及其基本操作实现源文件
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//包含单链表头文件
#include "SinglyLinkedListNoHeadNode.h"

/**
 * 初始化单链表
 * @param pList 链表指针
 */
void initSinglyLinkedList(SinglyLinkedList *pList){
	//先将尾指针指向头指针
    pList->pTail = pList->pHead = NULL;
    pList->nodeCount = 0;
}

/**
 * 根据提供的数据创建结点
 * @param  data 提供的数据
 * @return      已创建的结点指针
 */
Node *createNode(DataType data){
    //第一步，给结点分配内存
	Node *pNode = (Node *)malloc(sizeof(Node));
	if(NULL == pNode){
		printf("未申请到内存，结点创建失败！程序退出！\n");
        exit(-1);
        // return NULL;
	}

    //第二步，填充数据域和指针域
	pNode->data = data;
	pNode->next = NULL;

	return pNode;
}

/**
 * 头插法插入数据，向头部插入数据
 * @param pList 链表指针
 * @param data  要插入的数据
 */
void insertDataInHead(SinglyLinkedList* pList, DataType data){
    //第一步，创建一个结点，用于保存要插入的数据
    Node *pNode = createNode(data);

    //第二步，将新结点插入到头结点的位置
    if (isEmptyOfSinglyLinkedList(pList))
    {//空表
        //头指针和尾指针同时指向新结点
        pList->pHead = pList->pTail = pNode;
    }else{
        pNode->next = pList->pHead;//新结点的指针域和尾结点指向头结点
        pList->pHead = pNode;//新结点变成了头结点，头指针指向新结点
    }

    //第三步，更新结点个数，将结点个数加一
    ++pList->nodeCount;
}

/**
 * 尾插法插入数据，向尾部插入数据
 * @param pList 链表指针
 * @param data  要插入的数据
 */
void insertDataInTail(SinglyLinkedList* pList, DataType data){
    //第一步，创建一个结点，用于保存要插入的数据
    Node* pNode = createNode(data);

    //第二步，将新节点插入到单链表的末尾
    if(isEmptyOfSinglyLinkedList(pList))
    {//空表
        pList->pHead = pNode;
    }
    else
    {
        pList->pTail->next = pNode;
    }

    pList->pTail = pNode;

    //第三步，更新结点个数，将结点个数加一
    ++pList->nodeCount;
}

/**
 * 在指定的位置插入数据
 * @param pList 链表指针
 * @param data  要插入的数据
 * @param pos   指定的插入位置
 */
void insertDataInPosition(SinglyLinkedList* pList, DataType data, int pos){
    //1.判断坐标是否合法
    if (pos < 0 || pos > sizeOfSinglyLinkedList(pList))
    {
        // printf("坐标不合法，默认插入到链表的尾部\n");
        // pos = sizeOfSinglyLinkedList(pList);
        printf("插入位置不合法，插入失败！请输入正确的插入位置！\n");
        printf("正确的插入位置范围（0 ～ %d）\n", sizeOfSinglyLinkedList(pList));
        return;
    }

    //2.将新元素插入指定的位置
    if (0 == pos)
    {
        //头插
        insertDataInHead(pList, data);
        return;
    }

    if (sizeOfSinglyLinkedList(pList) == pos)
    {
        //尾插
        insertDataInTail(pList, data);
        return;
    }

    // 接下来就是插入到中间位置的情况
    Node *pNode = createNode(data);
    Node *pCurrent = pList->pHead;
    for (int i = 1; i < pos; ++i)
    {
        pCurrent = pCurrent->next;
    }

    // 接下来把pos=1时的代码写下来即可
    pNode->next = pCurrent->next;
    pCurrent->next = pNode;

    //让结点个数加1
    ++pList->nodeCount;
}

/**
 * 实现获取头结点的元素值
 * @param  pList 链表指针
 * @return       成功则返回头结点元素值，失败返回-1
 */
DataType getHeadNodeData(SinglyLinkedList* pList){
    return (isEmptyOfSinglyLinkedList(pList)?-1:pList->pHead->data);
}

/**
 * 实现获取为节点的元素值
 * @param  pList 链表指针
 * @return       成功则返回尾结点元素值，失败返回-1
 */
DataType getTailNodeData(SinglyLinkedList* pList){
    return (isEmptyOfSinglyLinkedList(pList)?-1:pList->pTail->data);
}

/**
 * 实现删除头结点的功能函数
 * @param  pList 链表指针
 * @return       成功返回0，失败返回-1
 */
int deleteHeadNode(SinglyLinkedList* pList){
    if (isEmptyOfSinglyLinkedList(pList))
    {
        printf("当前链表为空！\n");
        return -1;
    }

    Node *pCurrent = pList->pHead;

    pList->pHead = pCurrent->next;
    free(pCurrent);
    pCurrent = NULL;

    //当链表中只有一个结点时，pTail置为空
    if (NULL == pList->pHead)
    {
        pList->pTail = NULL;
    }

    --pList->nodeCount;

    return 0;
}

//删除尾结点的功能函数
/**
 * 删除尾结点的功能函数
 * @param  pList 链表指针
 * @return       成功返回0，失败返回-1
 */
int deleteTailNode(SinglyLinkedList* pList){
    if (isEmptyOfSinglyLinkedList(pList))
    {
        printf("当前链表为空！\n");
        return -1;
    }

    //当链表中只有一个结点时
    if (1 == sizeOfSinglyLinkedList(pList))
    {

        free(pList->pHead);

        pList->pHead = pList->pTail = NULL;

        --pList->nodeCount;

        return 0;
    }

    //当链表中有更多的结点时，采用归纳法
    //先将相对于nodeCount=2时多出来的next执行完毕
    Node *pCurrent = pList->pHead;
    for (int i = 2; i < sizeOfSinglyLinkedList(pList); ++i)
    {
        pCurrent = pCurrent->next;
    }

    //接下来写nodeCount=2时的删除代码
    free(pList->pTail);
    pList->pTail = pCurrent;

    //为了避免已删除结点的地址
    pList->pTail->next = NULL;

    --pList->nodeCount;

    return 0;
}

/**
 * 删除指定位置结点的功能函数
 * @param  pList 链表指针
 * @param  pos   指定位置
 * @return       成功返回0，失败返回-1
 */
int deleteDataInPosition(SinglyLinkedList* pList, int pos){
    //判断下表是否合法
    if (pos < 0 || pos >= sizeOfSinglyLinkedList(pList))
    {
        printf("指定的位置不合法，删除失败！\n");
        printf("合法的范围是（0 ～ %d）\n", sizeOfSinglyLinkedList(pList));
        return -1;
    }

    //2.当pos=0时，删除头结点
    if (0 == pos)
    {
        return deleteHeadNode(pList);
    }

    //3.当pos=nodeCount-1时，删除尾结点
    if (sizeOfSinglyLinkedList(pList) - 1 == pos)
    {
        return deleteTailNode(pList);
    }

    //4.当pos为其他值时，删除指定结点
    Node *pCurrent = pList->pHead;

    for (int i = 1; i < pos; ++i)
    {
        pCurrent = pCurrent->next;
    }

    Node *pTempNode = pCurrent->next;
    pCurrent->next = pTempNode->next;
    free(pTempNode);
    pTempNode = NULL;

    --pList->nodeCount;

    return 0;
}

/**
 * 判断单链表是否为空
 * @param  pList 单链表指针
 * @return       返回1则为空，返回0则非空
 */
int isEmptyOfSinglyLinkedList(SinglyLinkedList *pList){
    return (NULL == pList->pHead);
}

//输出单链表的长度，返回单链表中的结点个数
int sizeOfSinglyLinkedList(SinglyLinkedList *pList){
    return pList->nodeCount;
}

//输出整个单链表中的数据
void displySinglyLinkedList(SinglyLinkedList *pList){
	if(NULL == pList->pHead){
		printf("当前链表为空！\n");
		return;
	}

    printf("链表中的元素为：");

    //定义结点搜索指针pCurrent，用于遍历链表
    Node* pCurrent = pList->pHead;
    while(NULL != pCurrent)
    {
        printf("%c ", pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}

/**
 * 实现逆转的递归函数
 * @param pNode 结点指针
 */
void reverse(Node* pNode){
    //确保链表中至少有两个结点
    if (NULL != pNode && NULL != pNode->next)
    {
        //采用递归逆转后续元素
        reverse(pNode->next);

        //逆转两个结点
        pNode->next->next = pNode;
        pNode->next = NULL;
    }
}

/**
 * 逆转单链表中所有结点
 * @param pList 链表指针
 */
void reverseSinglyLinkedList(SinglyLinkedList *pList){
    //1.调用递归函数进行逆转
    reverse(pList->pHead);

    //2.交换pHead和pTail的指向
    Node *pTempNode = pList->pHead;
    pList->pHead = pList->pTail;
    pList->pTail = pTempNode;
}

//清空链表中所有的节点
void clearSinglyLinkedList(SinglyLinkedList* pList){
    while(-1 != deleteHeadNode(pList));
}
