#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "BST.c"

int main(){
//先创建好BST的根节点（省去创建）
	BSTNode bst;//根节点bst，后面将其初始化
	bst.data = 10;
	bst.left = NULL;
	bst.right = NULL;
	BSTree pBST = &bst; //pBST用来指向根节点
//插入，用来创建BST
	Insert(6,pBST);
	Insert(5,pBST);
	Insert(7,pBST);
	Insert(13,pBST);
	Insert(11,pBST);
//中序遍历显示（查看是否是正确的BST）
	InOrderTraverse(pBST);
	printf("\n");
//Find
	BSTree position;
	position = Find(3,pBST);
	position = Find(10,pBST);
	printf("%p\n",position);
//Find_iteration
	BSTree current;
	current = Find_iteration(3,pBST);
	current = Find_iteration(10,pBST);
	printf("%p\n",current);
	return 0;
}
