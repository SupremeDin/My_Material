
//1.Insert()二叉搜索树的插入函数
//操作：递归插入（其实就是按照一定规则创建二叉树）
//      BST始终指向根节点，并且函数最终返回BST
//      递归函数的函数体：1.先判断指向的节点是不是空，若是空，则直接插入该节点（申请空间）
//      		  2.节点不为空（含有data），则将带插入的值 与该节点比较 （依情况进入递归函数）
//
//************下面的Insert()函数只能插入原二叉搜索树中没有的数值***************
BSTree Insert(ElemType X,BSTree BST){
	if(!BST){
		BST = (BSTree)malloc(sizeof(BSTNode));
		BST->data = X;
		BST->left = NULL;
		BST->right = NULL;
	}
	else
		if(X < BST->data)
			BST->left = Insert(X,BST->left);
		else if(X > BST->data)
			BST->right = Insert(X,BST->right);
	return BST;
}

//2.查找
//操作：若找到 则返回节点的位置(BST类型)
//	没找到，则返回NULL
//	BST始终指向二叉搜索树的根节点
//
//******** 递归实现（实为尾递归）***************
BSTree Find(ElemType X,BSTree BST){
	if(!BST){
		printf("NO specified element(%d) was found\n",X);
		return NULL;
	}
	else if(X < BST->data)
		return Find(X,BST->left);
	else if(X > BST->data)
		return Find(X,BST->right);
	else{
		printf("Found it(%d)!\n",X);
		return BST;
	}
}

//********* 迭代实现（代替尾递归）**********************
//current所指向的位置不停地变化（迭代）
BSTree Find_iteration(ElemType X,BSTree current){
	while(current){
		if(X < current->data)
			current = current->left;
		else if(X > current->data)
			current = current->right;
		else{
			printf("Found it(%d)!\n",X);
			return current;
		}
	}
	printf("NO specified element(%d) was found\n",X);
	return NULL;
}


//中序遍历（写在这里just for checking）
void InOrderTraverse(BSTree BST){
	if(BST){
		InOrderTraverse(BST->left);
		printf("%d ",BST->data);
		InOrderTraverse(BST->right);
	}
}


// *****  Extra Method *****


//将提示写在Find函数里面更easy！
#if 0
//显示 由指针指向 节点的data域
//若 该指针 指向NULL 提示‘未找到指定元素’
void display(BSTree position){
	if(!position)
		printf("NO specified element was found!\n");
	else
		printf("Found it! %d",position->data);
	return;
}
#endif 
