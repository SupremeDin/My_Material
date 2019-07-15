#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef int ElemType;
typedef struct {
	ElemType *data;
	int top;//SP：实际为数组下标；当SP=-1时，代表堆栈为空
}Stack,*arrayStack;

void Init_arrayStack(arrayStack sptr);//初始化数组栈
int Is_full_arrayStack(arrayStack sptr);//数组栈满
int Is_empty_arrayStack(arrayStack sptr);//数组栈空
void Push_arrayStack(arrayStack sptr,ElemType temp);//push操作
void Traverse_arrayStack(arrayStack sptr);//遍历数组栈
