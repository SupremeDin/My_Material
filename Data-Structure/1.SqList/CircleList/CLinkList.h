//循环链表

#include <stdio.h>
#include <stdlib.h>   //malloc free 头文件

typedef int ElemType

typedef struct node{
	ElemType data;
	struct node *next;
}Node,*CLinkList;    //定义Node，以及 指向指向Node的指针类型


//Declaration
CLinkList Init_CLinkList(CLinkList head);//循环列表的初始化
