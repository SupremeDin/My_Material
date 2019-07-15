#include "arrayStack.h"

//初始化数组栈
//操作：定义一个数组，然后令sp=-1，表示数组栈为空【即代表数组下标元素的变量 】
void Init_arrayStack(arrayStack sptr){
	sptr->data = (ElemType *)malloc(MAX*sizeof(ElemType));
	sptr->top = -1;
	return ;
}
//数组栈满
//返回值1：满；返回值0：不满
int Is_full_arrayStack(arrayStack sptr){
	return (sptr->top == MAX-1);
}
//数组栈空
//1:空；0：不空
int Is_empty_arrayStack(arrayStack sptr){
	return (sptr->top == -1);
}
//push
//操作：数组元素赋值，sp+1【数组下标+1】
void Push_arrayStack(arrayStack sptr,ElemType temp){
	if(Is_full_arrayStack(sptr)){
		printf("stack FULL! no space to push\n");
		return;
	}
	else {
		sptr->data[++(sptr->top)] = temp;
		return;
	}
}
//遍历数组栈
void Traverse_arrayStack(arrayStack sptr){
	printf("Here is your arrayStack!\t");
	if(Is_empty_arrayStack(sptr)){
		printf("NULL\n");
		return;
	}
	else{
		for(int i=0;i<=sptr->top;i++){
			printf("%d\t",sptr->data[i]);
		}
		printf("\n");
	}
}






//测试test
void test_arrayStack(){
	Stack s;
	arrayStack sptr;
	sptr = &s;
	Init_arrayStack(sptr);    //解决segementation fault 最简单的方法了 即：定义一个实体Stack类型的s
	Push_arrayStack(sptr,1);
	Push_arrayStack(sptr,2);
	Traverse_arrayStack(sptr);

	return;
}


int main(){
	test_arrayStack();
	return 0;
}
