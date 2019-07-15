//*******************************************************
//*  二叉树的递归遍历，（递归本身就使用堆栈进行存储）       *
//*   下面的所有函数：创建+遍历 都用的是递归的算法去实现的  *
//*******************************************************


//创建二叉树
//在函数内部创建Tree指针 并返回指向跟节点的指针，在调用时通过赋值来改变指针。
BTree Create_BTree(){
//	printf("enter plus integer to create,0 to pass!\n");
	BTree treePtr;
	int temp;
	scanf("%d",&temp);
	//输入值不为0，则为treePtr开辟空间（形成BTNode），否则treePtr只是一个指针
	if( temp != 0){
		printf("parent:%d",temp);
		treePtr = (BTNode *)malloc(sizeof(BTNode));
		treePtr->data = temp;
		printf("\t parent node done!\n");
		printf("it's left-child:");
		treePtr->left = Create_BTree();
		printf("it's right-child:");
		treePtr->right = Create_BTree();
	}
	else
		treePtr = NULL;
	printf("one branch Done!\n");
	return treePtr;	
}
//创建二叉树
//形参为指向‘二叉树指针’的指针；这样在调用时形参为‘二叉树指针’的地址
void Create_BTree1(BTree *tree){
	int temp;
	scanf("%d",&temp);
	//每次进来之后就分配Node。
	*tree = (BTNode *)malloc(sizeof(BTNode));
	if( temp != 0 && *tree){
		printf("left child:");
		Create_BTree1(&(*tree)->left);
		printf("left----done!\n");
		
		printf("parent : %d",temp);
		(*tree)->data = temp;
//		*tree = (BTNode *)malloc(sizeof(BTNode));
		printf("\t parent done!\n");
		
		
		printf("right child:");
		Create_BTree1(&(*tree)->right);
		printf("right----done!\n");
	}
	else
		*tree = NULL;
	printf("--------------------\n");
	return;
}

//Traverse (recursion)
//(3 ways: Pre,In,Post)
void PreOrderTraverse(BTree tree){
	if(tree){
		printf("  %d",tree->data);
		PreOrderTraverse(tree->left);
		PreOrderTraverse(tree->right);
	}
	else
	return;
}
void InOrderTraverse(BTree tree){
	if(tree != NULL){
		InOrderTraverse(tree->left);
		printf("  %d",tree->data);
		InOrderTraverse(tree->right);
	}
	return;
}
void PostOrderTraverse(BTree tree){
	if(tree == NULL)
		return;
	PostOrderTraverse(tree->left);
	PostOrderTraverse(tree->right);
	printf("  %d",tree->data);
	return;
}


