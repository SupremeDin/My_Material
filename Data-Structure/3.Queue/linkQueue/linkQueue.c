#include "linkQueue.h"

//typedef struct {
//	ElemType data;
//	struct QNode *next;
//}QNode,*QueuePtr;
//typedef struct {
//	QueuePtr front;
//	QueuePtr rear;
//}linkQueue;




//Defination

//初始化
//操作：在函数内建立一个头结点，并将队列的链式结构linkQueue的两个指针指向他。
//front、rear指向同意地址 说明队列为空。
void Init_LinkQueue(linkQueue *lq){
	printf("Init Queue ...\n");
	QueuePtr nodePtr = (QueuePtr)malloc(sizeof(QNode));//创建QueuePtr类型的指针，指向新创建的节点
	if( !nodePtr ){
		printf("cant allocate space!");
		exit(0);
	}
	lq->front = nodePtr;
	lq->rear = nodePtr;
}
//进队
//操作：在rear指针的下一个位置链接一个新的QNode
void EnQueue(linkQueue *lq,ElemType temp){
	printf("EnQueue:%d...\n",temp);
	QueuePtr nodePtr = (QueuePtr)malloc(sizeof(QNode));
	nodePtr->data = temp;
	nodePtr->next = NULL;
	lq->rear->next = nodePtr;//先将新生成的QNode连接到rear指针的后一个位置；
	lq->rear = nodePtr;//更新rear，使其始终指向尾节点。
	return ;
}
//链式队列是否为空
//操作：判断front、rear是否指向头结点
int IsEmpty(linkQueue *lq){
	return(lq->front == lq->rear);
}
//遍历队列
void Traverse(linkQueue *lq){
	printf("linkQueue:\t"); 
	if(IsEmpty(lq)){     //?????parameter????
		printf("NULL\n");
		return;
	}
	else{
		QueuePtr p = lq->front->next;
		while(p){
			printf("%d\t",p->data);
			p = p->next;
		}
		printf("\n");
	}
	return;
}
//出队
//操作：将首元节点free，front仍指向头结点，但是front->next需要更新；
//当对列中只有一个元素时，DeQueue之后还需更新rear指针。（其他时候rear不需要更新）
ElemType DeQueue(linkQueue *lq){
	printf("DeQueue:");
	if(IsEmpty(lq)){
		printf("nothing to DeQueue!\n");
		return -1;
	}
	else{
		QueuePtr p = lq->front->next;
		ElemType temp = p->data;
		printf("%d...\n",temp);
		lq->front->next = p->next;
		if(p == lq->rear)
			lq->rear = lq->front;
		free(p);
		return temp;
	}
}

//test函数
void test(){
	linkQueue lq;
	Init_LinkQueue(&lq);
	EnQueue(&lq,63);
	EnQueue(&lq,9);
	EnQueue(&lq,5);
	EnQueue(&lq,6);
	EnQueue(&lq,3);
	DeQueue(&lq);
	DeQueue(&lq);
	DeQueue(&lq);
	DeQueue(&lq);
	DeQueue(&lq);
	DeQueue(&lq);
	Traverse(&lq);
	return;
}


//主函数
int main(){
	test();


	return 0;
}
