#include "binaryTree.h"
#include "binaryTree_recursive.c"
#include "binaryTree_non_recursive.c"
#include "level_order_Traverse.c"
#include "extra.c"

void test(){
	BTree tree = NULL;
//	tree = Create_BTree();
#if 1
	Create_BTree1(&tree);
	printf("PreOrder (recursive):");
	PreOrderTraverse(tree);	
	printf("\n");
	printf("InOrder (recursive):");
	InOrderTraverse(tree);	
	printf("\n");
	printf("PostOrder (recursive):");
	PostOrderTraverse(tree);	
	printf("\n");
#endif	
//test:if "stack" work or not~
#if 0
	pStack s;
	s = Create_Stack();
	Push_Stack(s,tree);
	Pop_Stack(s);
#endif
#if 0
	PreOrder(tree);	
	InOrder(tree);
#endif
#if 0
	Queue queue;//定义一个队列实体
	pQueue q = &queue;
	Create_Queue(q,7);
	IsEmpty_Queue(q);
	IsFull_Queue(q);
	EnQueue(q,tree);
	DeQueue(q);
#endif
#if 0
	Queue queue;//定义一个队列实体
	pQueue q = &queue;
	Create_Queue(q,10);
	LevelOrder(tree,q);
#endif
	printf("Leaves:");
	PreOrderPrintLeaves(tree);
	printf("\n");
	return;
}


int main(){
	test();
	return 0;
}

