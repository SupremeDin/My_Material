#include <stdio.h>
#include <stdlib.h>   //malloc、free的头文件

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*LinkStack;              //定义LinkStack是指向节点的指针类型。


//c不支持函数重载，函数名必须不同
void Init1_LinkStack(LinkStack *head);//链栈初始化   则实参为&head,[指针的地址]
LinkStack Init2_LinkStack();//链栈初始化
void Push_LinkStack(LinkStack head);//push操作，类似与之前的 头插法[SP指针只能放在链表头部]
void Traverse_LinkStack(LinkStack head);//遍历链栈
int Is_empty(LinkStack top);//堆栈是否为空
ElemType Pop_LinkStack(LinkStack top);//pop操作，返回pop出来的值


