#include <stdio.h>
#include <stdlib.h>

//Declaration

typedef int ElemType;

//定义结点结构（单链表的结点）------QNode
typedef struct QNode{
	ElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

//定义队列的链式结构----linkQueue
//其由front、rear 两个(指向QNode)指针构成队列的链式结构
typedef struct linkQueue{
	QueuePtr front;
	QueuePtr rear;
}linkQueue;

//Method
void Init_LinkQueue(linkQueue * lq);//initialize
void EnQueue(linkQueue *lq,ElemType temp);//add a element!
int IsEmpty(linkQueue *lq);//empty or not?
void Traverse(linkQueue *lq);
ElemType DeQueue(linkQueue *lq);//

