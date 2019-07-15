//二叉树的链式存储---二叉链表



//Declaration：
#include <stdio.h>
#include <stdlib.h>

//定义二叉树中每个节点的结构
typedef int ElemType;
typedef struct BTNode{
	ElemType data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode,*BTree;

//这里用两种形式创建二叉树：带形参、不带形参
BTree Create_BTree();
void Create_BTree1(BTree *tree);
//***********************************
//******* Traverse (recursion) ******
//**********************************
//mathod
void PreOrderTraverse(BTree tree);
void InOrderTraverse(BTree tree);
void PostOrderTraverse(BTree tree);

//***********************************
//***** Traverse (non-recursive) ****
//***********************************
//stack is needed!
typedef BTree stackElemType;//堆栈里面存储的是（指向二叉树节点的指针）或者说（BTNode的地址）
typedef struct SNode{
	stackElemType data;
	struct SNode *next;
}SNode,*pStack;  //Stack的头节点指针（代表着整个堆栈）、及其节点都是pStack类型。

pStack Create_Stack();
int IsEmpty_Stack(pStack s);
void Push_Stack(pStack s,stackElemType elem);
stackElemType Pop_Stack(pStack s);

//mathod
void PreOrder(BTree tree);
void InOder(BTree tree);
void PostOrder(BTree tree);

//*************************************
//********* level order Traverse ******
//*************************************

//queue is needed!
//here is circularQueue!
typedef BTree queueElemType;
typedef struct Queue{
	queueElemType *data;//数组名为data，数组里存放的元素类型为queueElemType。
	int front;//队列中的第一个元素的下标
	int rear;//队列中最后一个元素的下标
	int  Maxsize;//队列中的最大元素个数
}Queue,*pQueue;

//method
//pQueue Create_Queue(int Max);
void Create_Queue(pQueue q,int Max);
int IsEmpty_Queue(pQueue q);
int IsFull_Queue(pQueue q);
void EnQueue(pQueue q,queueElemType elem);
queueElemType DeQueue(pQueue q);

//
void LevelOrder(BTree tree,pQueue q);


//二叉树的应用
//求叶子节点、二叉树高度、等等

void PreOrderPrintLeaves(BTree tree);


