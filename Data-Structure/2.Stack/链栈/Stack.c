//Defination
#include "Stack.h"


//链栈初始化
//形参为指向指针的指针（注重理解）
void Init1_LinkStack(LinkStack *head){
	(*head) = (Node *)malloc(sizeof(Node));
	if(!(*head))
		printf("FAILED ! allocate head node failed!");
	(*head)->next = NULL;
}
//没有形参的时候
LinkStack Init2_LinkStack(){
	LinkStack head;
	head = (Node *)malloc(sizeof(Node));
	if(head == NULL)
		printf("FAILED !");
	head->next = NULL;
	return head;
}
//push
//即 头插法
//输入-1结束输入
void Push_LinkStack(LinkStack head){
	LinkStack p = NULL; //带插入的新节点
	ElemType temp;
	printf("input elements(enter -1 to end)!\n");
	scanf("%d",&temp);
	while(temp != -1){
		p = (Node *)malloc(sizeof(Node));
		p->data = temp;
		p->next = head->next;
		head->next = p;
		scanf("%d",&temp);
	}
	return;
}
//遍历链栈
void Traverse_LinkStack(LinkStack head){
	LinkStack p = head->next;
	printf("Here is your LinkStack :");
	if(p){
		while(p){
		printf("%d\t",p->data);
		p = p->next;
		}
		printf("\n");
	        return;
	}
	else{
		printf("NULL\n");
	        return;
	}
}

//堆栈是否为空
//返回1=空；返回0=不空
int Is_empty(LinkStack top){
	return(top->next == NULL);//
}
//pop操作，返回pop出来的值
ElemType Pop_LinkStack(LinkStack top){
	if(Is_empty(top)){
		printf("Nothing to pop(return -1)\n");
		return -1;
	}
	LinkStack p = top->next;  //p指向即将pop出来的节点（即p指向首元节点）
	ElemType temp = p->data;//存储即将pop出元素的data
	top->next = p->next;
	printf("Pop %d\n",temp);
	free(p);
	return temp;
}



//test
void Test_LinkStack(){
//	LinkStack head = NULL;
//	head = Init2_LinkStack();
	LinkStack top1 = NULL;
	Init1_LinkStack(&top1);
	Push_LinkStack(top1);
	Traverse_LinkStack(top1);
	Pop_LinkStack(top1);
	Traverse_LinkStack(top1);
}


//main函数
int main(){
	Test_LinkStack();
	return 0;
}



