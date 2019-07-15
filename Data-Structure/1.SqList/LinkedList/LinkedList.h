//单链表
#include <stdio.h>
#include <stdlib.h>       //malloc(),free()

typedef int ElemType;

//定义节点Node类型
typedef struct Node{
	ElemType data;             //单链表的数据域
	struct Node *next;        //单链表的指针域，struct中不能有自身同样的结构体，但可以包括自身类型的指针变量
}Node,*LinkedList;                //LinkedList是指向Node的指针类型



//Declaration
LinkedList Init_LinkedList();//单链表的初始化
LinkedList Create_Head_LinkedList(LinkedList head,int n);//头插法建立单链表
LinkedList Create_Tail_LinkedList(LinkedList head,int n);//尾插法建立单链表：
void Traverse_LinkedList(LinkedList head);//单链表的遍历
LinkedList FindKth_LinkedList(LinkedList head,int K);//按序号查找
LinkedList Find_LinkedList(LinkedList head,ElemType X); //按值查找
int Length_LinkedList(LinkedList head);//求表长
LinkedList Insert_LinkedList(LinkedList head,int i,ElemType X);//插入节点（元素）
LinkedList Delete_LinkedList(LinkedList head,int i);//删除节点（元素）
LinkedList Create_by_array_LinkedList(LinkedList head,ElemType array[]);//根据一维数组来建立单链表
LinkedList Contray_LinkedList(LinkedList head);//使用原有节点将链表逆序链接
LinkedList Bubble_sort_LinkedList(LinkedList head);//使用冒泡法使单链表有序
