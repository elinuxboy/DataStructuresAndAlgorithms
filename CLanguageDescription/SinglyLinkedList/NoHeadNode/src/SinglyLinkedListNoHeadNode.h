/*
 ============================================================================
 Name        : SinglyLinkedListNoHeadNode.h
 Author      : elinuxboy<elinuxboy@126.com>
 Version     : 1.0
 Copyright   : Copyright @2018 Powerd by eclipse in win10
 Description : 不带头结点的单链表及其基本操作实现头文件
 ============================================================================
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

//////////////////////////////////////////////////////////////
//  类型定义开始
//////////////////////////////////////////////////////////////
//显示定义结点数据域类型
typedef char DataType;

//定义单链表结点的数据类型
typedef struct Node
{
    DataType data;//数据域，记录数据元素本身的值
    struct Node *next;//指针域，记录下一个结点的地址
}Node;

//定义单链表的数据类型
typedef struct
{
    Node *pHead;//头指针，记录头结点的地址
    Node *pTail;//尾指针，记录尾结点的地址
    int nodeCount;//记录链表结点的个数
}SinglyLinkedList;

//////////////////////////////////////////////////////////////
//  类型定义结束
//////////////////////////////////////////////////////////////

/*
 * ============================================================
*   函数声明开始
* =============================================================
*/
//初始化单链表
void initSinglyLinkedList(SinglyLinkedList *pList);

//根据提供的数据创建结点
Node *createNode(DataType data);

//头插法插入数据，向头部插入数据
void insertDataInHead(SinglyLinkedList *pList, DataType data);

//尾插法插入数据，向尾部插入数据
void insertDataInTail(SinglyLinkedList *pList, DataType data);

//在指定的位置插入数据
void insertDataInPosition(SinglyLinkedList *pList, DataType data, int pos);

//实现获取头结点的元素值
DataType getHeadNodeData(SinglyLinkedList *pList);

//实现获取尾结点的元素值
DataType getTailNodeData(SinglyLinkedList *pList);

//实现删除头结点的功能
int deleteHeadNode(SinglyLinkedList *pList);

//删除尾结点的功能函数
int deleteTailNode(SinglyLinkedList *pList);

//删除指定位置的结点
int deleteDataInPosition(SinglyLinkedList *pList, int pos);

//判断单链表是否为空，返回1则为空，返回0则非空
int isEmptyOfSinglyLinkedList(SinglyLinkedList *pList);

//输出单链表的长度，返回单链表中的结点个数
int sizeOfSinglyLinkedList(SinglyLinkedList *pList);

//输出整个单链表中的数据
void displySinglyLinkedList(SinglyLinkedList *pList);

//逆转单链表中所有结点
void reverseSinglyLinkedList(SinglyLinkedList *pList);

//清空链表中所有的节点
void clearSinglyLinkedList(SinglyLinkedList* pList);
/*
 * ============================================================
*   函数声明结束
* =============================================================
*/

#endif /* SINGLYLINKEDLIST_H_ */

