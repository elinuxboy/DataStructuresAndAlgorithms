﻿# 单链表（C语言实现）学习记录
---
## 概念
---
### 链接方式存储
---
链接方式存储的线性表简称为链表（Linked List）。

链表的具体存储表示为：

1. 用一组任意的存储单元来存放线性表的结点（这组存储单元既可以是连续的，也可以是不连续的）。
2. 链表中结点的逻辑次序和物理次序不一定相同。为了能正确表示结点间的逻辑关系，在存储每个结点值的同时，还必须存储指示其后继结点的地址（或位置）信息（称为指针（pointer）或链(link)）。

链式存储是最常用的存储方式之一，它不仅可用来表示线性表，而且可用来表示各种非线性的数据结构。
### 单链表
---
> 单链表是一种**链式存取**的数据结构，用一组**地址任意**的存储单元存放线性表中的数据元素。

链表中的数据是以**结点**来表示的，每个结点的构成为：

> 元素(数据元素的映象，通常称为“**数据域**”) + 指针(指示后继元素存储位置，通常称为“**指针域**”)。

元素就是存储数据的存储单元，指针就是连接每个结点的地址数据。

如图1所示，数据域data--存放结点值的数据域；指针域next--存放结点的直接后继的地址（位置）的指针域（链域）。

链表通过每个结点的链域将线性表的n个结点按其逻辑顺序链接在一起的，每个结点只有一个链域的链表称为单链表（Single Linked List）。
	<div align="center"> ![](https://i.imgur.com/EHSX1WR.png)<br>图1 链表结点的结构</div>

### 头指针pHead、头结点pHeadNode、首元结点p1Node和终端结点（尾结点）pTailNode
---
- 头结点pHeadNode：

有时，在链表的第一个结点之前会额外增设一个结点，结点的数据域一般不存放数据（有些情况下也可以存放链表的长度等信息），此结点被称为头结点。

若头结点的指针域为空（NULL），表明链表是**空表**(如图2 所示)。头结点对于链表来说，不是必须的，在处理某些问题时，给链表添加头结点会使问题变得简单。
    <div align="center">![在这里插入图片描述](https://img-blog.csdnimg.cn/201811300006583.png)<br>![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130002242928.png)<br>图2 空链表</div>

- 头指针pHead：

永远指向链表中第一个结点的位置（如果链表有头结点，头指针指向头结点；否则，头指针指向首元结点）。

- 头结点和头指针的区别：

头指针是一个指针，头指针指向链表的头结点或者首元结点；头结点是一个实际存在的结点，它包含有数据域和指针域。两者在程序中的直接体现就是：头指针只声明而没有分配存储空间，头结点进行了声明并分配了一个结点的实际物理内存。

> 单链表中可以没有头结点，但是**不能没有头指针**！

>单链表中**每个结点的存储地址是存放在其前趋结点next域中**。

开始结点无前趋，故应设头指针pHead指向开始结点。

链表由头指针唯一确定，单链表可以用头指针的名字来命名。

- 首元结点p1Node：

链表中第一个元素所在的结点，如果存在头结点则它是头结点后边的第一个结点。如图 3 所示。
    <div align="center">![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130001013269.png)<br>![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130000947252.png)<br>图3 非空链表</div>

- 终端结点（尾结点）pTailNode:

终端结点（尾结点）无**后继**，故终端结点的指针域为空，即NULL。

## 单链表的定义
---
C语言使用结构体来定义单链表：

    //定义结点数据域的类型
    typedef char DataType;
    
    //定义结点
    typedef struct Node{
        DataType data;//数据域
        struct Node *next;//指针域
    }Node;
    
    //Node和SinglyLinkedList是不同名字的同一个类型（命名的不同是为了概念上更明确）
    typedef struct Node SinglyLinkedList;
    
    //显示定义SinglyLinkedList类型的指针变量*pHead表示它是单链表的头指针
    SinglyLinkedList *pHead;

## 单链表的建立
---
### 初始化
---
带头结点的单链表的初始化就是创建一个头结点，给他分配存储空间。并将头结点的指针域指向NULL。

    /**
     * 初始化单链表，创建一个带头结点的空链表
     * @return 链表头指针
     */
    SinglyLinkedList *InitSinglyLinkedList()
    {
        // 申请存储空间可使用malloc()函数实现，需设立一申请单元指针，这里是头指针pHead，
        // 但malloc()函数得到的指针并不是指向结构体的指针，因此，需使用强制类型转换，
        // 将其转换成结构体型指针。
        pHead = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
        // 刚开始时，链表还没建立，是一空链表，pHead结点的next指针为NULL。
        pHead->next = NULL;
    
        return pHead;
    }

单链表是用户不断申请存储单元和改变链接关系而得到的一种特殊数据结构，将链表的左边称为链头，右边称为*链尾*。

带头结点的单链表的创建有头插法、尾插法两种方法。
- 头插法
头插法建单链表是将链表右端看成固定的，链表不断向左延伸而得到的。头插法最先得到的是尾结点。如图 4 所示：
      <div align="center">![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130001459738.png)<br>![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130001231761.png)<br>图4 头插法</div>

由于链表的长度是随机的，故用一个for循环来控制链表中结点个数。

申请存储空间可使用malloc()函数实现，需设立一*申请单元指针*，但malloc()函数得到的指针并不是指向结构体的指针，需使用*强制类型转换*，将其转换成结构体型指针。

刚开始时，链表还没建立，是一空链表，pHead指针为NULL。

链表建立的过程是申请空间、得到数据、建立链接的循环处理过程。

头插法实现代码如下：

       /**
        * 头插法创建带头结点的单链表
        * 如：pHead-->d-->c-->b-->a-->NULL [逆序]
        * @param  pHead     链表头指针
        * @param  pData    要插入数据的指针
        * @param  dataCount 要插入数据的数量
        * @return          插入后链表的头指针
        */
        SinglyLinkedList *
        CreateListFrHead (SinglyLinkedList *pHead, DataType *pData, int dataCount)
        {
            //创建一个搜索结点，用于遍历链表
            SinglyLinkedList *pCurrent = pHead;
        
            for(int i = 0; i < dataCount; i++)
            {
        	// 创建新结点pInsertNode用于存放要插入的数据
        	SinglyLinkedList *pInsertNode = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
        	pInsertNode->data = pData[i];
        
        	// 将pInsertNode插在原结点之前,前驱结点之后
        	// 因为每个结点的地址都是存放在其前驱结点的指针域next中
        	pInsertNode->next = pCurrent->next;        //原结点之前
        	pCurrent->next = pInsertNode;        //前驱节点结点之后
            }
        
            return pHead;
        }

- 尾插法
若将链表的左端固定，链表不断向右延伸，这种建立链表的方法称为尾插法。如图 5 所示：
      <div align="center">![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130001618914.png)<br>![在这里插入图片描述](https://img-blog.csdnimg.cn/20181130001610387.png)<br>图5 尾插法</div>

尾插法建立链表时，头指针固定不动，故必须设立一个*搜索指针*，向链表右边延伸，则整个算法中应设立三个链表指针，即头指针pHead、搜索指针pCurrent、申请单元指针pInsertNode。尾插法最先得到的是头结点。

尾插法实现代码如下：

    /**
     * 尾插法建立带头结点的单链表
     * 例如：pHead-->a-->b-->c-->d-->NULL [顺序]
     * @param  pHead     链表头指针
     * @param  pData     要插入的数据指针
     * @param  dataCount 要插入的数据数量
     * @return           插入后的链表头指针
     */
    SinglyLinkedList * CreateListFrTail(SinglyLinkedList *pHead, DataType *pData,
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
完整的测试代码如下：

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
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
     * 头插法创建带头结点的单链表
     * 如：pHead-->d-->c-->b-->a [逆序]
     * @param  pHead     链表头指针
     * @param  pData    要插入数据的指针
     * @param  dataCount 要插入数据的数量
     * @return          插入后链表的头指针
     */
    SinglyLinkedList *CreateSinglyLinkedListFrHead(SinglyLinkedList *pHead, DataType *pData,
            int dataCount);
    
    /**
     * 尾插法建立带头结点的单链表
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
     * @param  pHead 链表头指针
     * @return       链表中结点个数
     */
    int SinglyLinkedListLength(SinglyLinkedList *pHead);
    
    /**
     * 输出链表中的数据
     * @param pHead 链表头指针
     */
     void DispSinglyLinkedList(SinglyLinkedList *pHead);
    
     int main(void) {
        //带头结点的单链表初始化
        pHead = InitSinglyLinkedList();
    
        //输出链表
        DispSinglyLinkedList(pHead);
    
        //创建如下单链表
        DataType *pData = "abcdefg";
    
        //头插法创建链表
        pHead = CreateSinglyLinkedListFrHead(pHead, pData, strlen(pData));
    
        //尾插法创建链表
    //    pHead = CreateSinglyLinkedListFrTail(pHead, pData, strlen(pData));
    
        printf("链表长度为：%d\n", SinglyLinkedListLength(pHead));
    
        //输出链表
        DispSinglyLinkedList(pHead);
    
        //释放存储空间
        free(pHead);
    
        return EXIT_SUCCESS;
    }
    
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
        return (pHead->next == NULL);
    }
    
    /**
     * 头插法创建带头结点的单链表
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
     * 尾插法建立带头结点的单链表
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
     * @param  pHead 链表头指针
     * @return       链表中结点个数
     */
    int SinglyLinkedListLength(SinglyLinkedList *pHead)
    {
        int ListLength = 0;
        SinglyLinkedList *pCurrent = pHead;
        while (pCurrent->next != NULL)
        {
            ListLength++;
            pCurrent = pCurrent->next;
        }
    
        return ListLength;
    }
  未完待续。。。

# 参考
---
- [《百度百科——单链表》](https://baike.baidu.com/item/%E5%8D%95%E9%93%BE%E8%A1%A8/3228368?fr=aladdin#ref_[1]_178637)
- [《数据结构：单链表基本操作》](https://www.cnblogs.com/leaver/p/6718421.html)
- [《数据结构与算法教程，数据结构C语言版教程！》](http://data.biancheng.net/)
