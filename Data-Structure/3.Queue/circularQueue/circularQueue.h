#include <stdio.h>
#include <stdlib.h>   //malloc free

typedef int ElemType;
typedef struct{
	ElemType *data;//array   
	int front;//the first element
	int rear;//the one after the last element
	int Maxsize;//array length
}Queue,*circularQueue;

//Declaration
void Init_Queue(circularQueue q,int size);//initialize
int IsFull_Queue(circularQueue q);//full---->return 1;
int IsEmpty_Queue(circularQueue q);//empty-->return 1;
void Add_Queue(circularQueue q);//add element;
ElemType Delete_Queue(circularQueue q);//delete element;
void Traverse_Queue(circularQueue q);//traverse queue
