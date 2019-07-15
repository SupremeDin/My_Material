//二叉树的层序遍历（使用队列）


//circularqueue is nedded here!
//创建循环队列
//操作：1.分配数组的空间，其大小正好为需要遍历的二叉树的节点数目（当所需空间已知时候，推荐使用循环队列） 
//	2.在这里我们规定：front为队列中第一个元素的下标，rear为队列中最后一个元素的下一个位置的下标。
#if 0
pQueue Create_Queue(int Max){
	Queue queue;
	pQueue q = &queue;
	q->data = (queueElemType *)malloc(Max * sizeof(queueElemType));
	q->front = 0;
	q->rear = 0; //初始化时候front = rear：表示此时候队列是控队列
	q->Maxsize = Max;
	return q;
}
#endif

void Create_Queue(pQueue q,int Max){
	q->data = (queueElemType *)malloc(Max * sizeof(queueElemType));
	if(!(q->data)){
		printf("allocate new space failed !\n");
		exit(0);//exit all program ;
	}
	q->front = 0;
	q->rear = 0; //初始化时候front = rear：表示此时候队列是控队列
	q->Maxsize = Max;
	return;
}

#if 1
//是否满
//1为满
int IsFull_Queue(pQueue q){
	return ( q->front == (q->rear + 1) % q->Maxsize );
}
#endif

//是否为空
//1为空
int IsEmpty_Queue(pQueue q){
	return ( q->front == q->rear );
}
#if 1
//入队
//操作：1.将新的元素放置在rear下标处的位置
//	2.更新rear
void EnQueue(pQueue q,queueElemType elem){
	if( IsFull_Queue(q) ){
		printf("Queue is FULL! cant enQueue!\n");
		return;
	}
	if( elem ){
	q->data[q->rear] = elem;//放置元素入队
	q->rear = (q->rear + 1) % q->Maxsize;
	}
	return ;
}
#endif
//出队
//操作：1.将数组中下标为front的元素出队，并将其返回(由于是数组不需要free，只需要将其值覆盖就好)
//	2.更新front
queueElemType DeQueue(pQueue q){
	if( IsEmpty_Queue(q) ){
		printf("Queue is EMPTY! cant deQueue!\n");
		return NULL;
	}
	queueElemType temp = q->data[q->front];
	q->front = (q->front + 1) % q->Maxsize;
	return temp;
}


//层序遍历
//此处依然使用pCur来指向当前的节点
void LevelOrder(BTree tree,pQueue q){
	BTree pCur = tree;
	if( !pCur){
		printf("Empty , exit!\n");
		exit(0);
	}
	EnQueue(q,pCur);
	printf("LevelOrder:");
	while( !IsEmpty_Queue(q) ){
		pCur = DeQueue(q);
		printf("%d  ",pCur->data);//访问当前节点
		EnQueue(q,pCur->left);
		EnQueue(q,pCur->right);
	}
	printf("\n");
	return;
}
