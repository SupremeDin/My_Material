//遍历二叉树的应用
//1.用来求二叉树中的叶子节点
//2.求二叉树的高度
//3.由已知的两种遍历序列求得原二叉树的结构


//求叶子节点
//操作：按照既定的路线遍历一遍二叉树，将满足叶子节点条件（既没有左儿子，有没有右儿子）的节点进行打印

void PreOrderPrintLeaves(BTree tree){
	if(tree){
		if(!tree->left && !tree->right)
			printf("%d  ",tree->data);
		PreOrderPrintLeaves(tree->left);
		PreOrderPrintLeaves(tree->right);
	}
}
