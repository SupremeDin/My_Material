#include "circularQueue.h"

//Defination


//initialize 
void Init_Queue(circularQueue q,int size){
	q->data = (ElemType *)malloc(size * sizeof(ElemType));
	if(!(q->data)){
		printf("allocate new space failed !\n");
		exit(0);//exit all program ;
	}
	q->front = 0;
	q->rear = 0;
	q->Maxsize = size;
	return;
}

//full or not 
//full-->return 1
int IsFull_Queue(circularQueue q){
	return(q->front == (q->rear+1)%q->Maxsize);
}

//empty or not
//empty-->return 1
int IsEmpty_Queue(circularQueue q){
	return(q->front == q->rear);
}


//add element
//1.add it where the 'rear' point to [assignment]
//2.update 'rear'
void Add_Queue(circularQueue q){
	if(IsFull_Queue(q)){
		printf("Queue is full! can not add element\n");
		return;
	}
	else{
		ElemType temp;
		printf("add a element:");
		scanf("%d",&temp);
		q->data[q->rear] = temp;//assignment
		q->rear = (q->rear+1) % q->Maxsize;
	}
	return;
}

//delete element
//1.save deleted_element which 'front' points to
//2.update 'front'
ElemType Delete_Queue(circularQueue q){
	if(IsEmpty_Queue(q)){
		printf("Queue is empty! can not delete element\n");
		return -1;//-1 means nothing
	}
	else{
		ElemType temp;
		temp = q->data[q->front];//save 
		printf("delete '%d'\n",temp);
		q->front = (q->front+1)%q->Maxsize;//update
		return temp;
	}
}

//traverse queue
void Traverse_Queue(circularQueue q){
	printf("now you get:\t");
	if(q->rear > q->front){
		for(int i =q->front;i<q->rear;i++){
			printf("%d\t",q->data[i]);
		}
	}
	else if(q->rear == q->front)
		printf("null !");
	else{
		for(int i = q->front;i<q->Maxsize;i++)
			printf("%d\t",q->data[i]);
		for(int i = 0;i<q->rear;i++)
			printf("%d\t",q->data[i]);
	}
	printf("\n");	
}

//test program
void test(){
	Queue queue;
	circularQueue q;
	q = &queue;
	Init_Queue(q,5);
	Add_Queue(q);
	Add_Queue(q);
	Add_Queue(q);
	Delete_Queue(q);
	Delete_Queue(q);
	Add_Queue(q);
	Add_Queue(q);
	Add_Queue(q);
	printf("front = %d,rear = %d\n",q->front,q->rear);
	Traverse_Queue(q);
	return;
}


//主函数
int main(){
	test();
	return 0;
}

