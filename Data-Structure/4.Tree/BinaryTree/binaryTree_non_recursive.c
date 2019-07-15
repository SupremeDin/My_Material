//二叉树的非递归遍历--使用堆栈

//Stack is needed!

//创建stack
//操作：创建一个头结点s(带头结点的stack)，并将其指向NULL，完成对Stack的初始化
pStack Create_Stack(){
	pStack s = NULL;//s是pStack类型的节点指针，由于是头结点指针，故将其视为指向该Stack的指针。s在这里模拟的是堆栈中的SP指针，SP==s->next。
	s = (pStack)malloc(sizeof(SNode));
	if(!s){
		printf("allocate the space failed !\n");
		exit(0);
	}
	s->next = NULL;
	return s;
}
//是否为空
//操作：直接返回next来查看是否为空,1为空
int IsEmpty_Stack(pStack s){
	return (s->next == NULL);
}
//push
//操作：类似于头插法（由于stack只能在一端进行操作，选择在链表的头部进行push、pop操作）
void Push_Stack(pStack s,stackElemType elem){
	pStack new_SNode = NULL;
	new_SNode = (pStack)malloc(sizeof(SNode));
	new_SNode->data = elem;
	new_SNode->next = NULL;

	pStack t = s->next;//将t指向堆栈中的首元节点，push操作时：将new_SNode插入到s、t之间（头插法）
	if( s ){
		new_SNode->next = t;
		s->next = new_SNode;
	}
	return;
}
//pop
//操作：1.先检查stack时候为空，不空才会执行pop操作
//      2.pop时，始终弹出首元节点，再讲第二个节点接到头结点后面去。
//	3.free()
stackElemType Pop_Stack(pStack s){
	if(IsEmpty_Stack(s)){
		printf("Empty! nothing to pop !\n");
		return NULL;
	}
	stackElemType temp = s->next->data;//temp存储即将被pop出节点的数据域。
	pStack t = s->next;
	s->next = t->next;
	free(t);
	return temp;
}


//Traverse the BianryTree (non recursive)
//先序-非递归遍历
//操作：1.创建pCur指针以期遍历二叉树的全部节点（pCur值的更新来自于两部分：节点的左子树+stack中存储的值）
//	2.使用stack，目的是更新pCur的值
void PreOrder(BTree tree){
	BTree pCur = tree;//pCur指针来按照固定路径遍历二叉树的所有节点
	pStack s = Create_Stack();//创建stack来存贮二叉树节点的指针
	printf("PreOrder (non recursive):");
	while( pCur || !IsEmpty_Stack(s)){
		while(pCur){
			printf("%d  ",pCur->data);//先序：第一次遇到即显示
			Push_Stack(s,pCur);
			pCur = pCur->left;
		}
		if( !IsEmpty_Stack(s) ){
			pCur = Pop_Stack(s);
			pCur = pCur->right;
		}
	}
	printf("\n");
	return; 
}
//中序-非递归遍历
//操作：跟先序非常类似！
void InOrder(BTree tree){
	BTree pCur = tree;//pCur指针来按照固定路径遍历二叉树的所有节点
	pStack s = Create_Stack();//创建stack来存贮二叉树节点的指针
	printf("InOrder (non recursive):");
	while( pCur || !IsEmpty_Stack(s)){
		while(pCur){
			Push_Stack(s,pCur);
			pCur = pCur->left;
		}
		if( !IsEmpty_Stack(s) ){
			pCur = Pop_Stack(s);
			printf("%d  ",pCur->data);//中序：第二次遇到即显示
			pCur = pCur->right;
		}
	}
	printf("\n");
	return; 
}
//void PostOrder(BTree tree);
