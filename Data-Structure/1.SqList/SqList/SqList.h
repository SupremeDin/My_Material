#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义ElemType类型为整型
typedef struct{
	ElemType *list;
	int current_length;  //顺序表的当前长度。大小随着insert、delete不断变化
	int store_length;  //顺序表当前分配的存储容量
}SqList;

//Declaration
SqList * Init_SqList(SqList * L,int size);//(1)初始化：动态分配一个预定义大小的数组空间，并将当前长度设置为0
SqList * Insert_SqList(SqList * L,int i,ElemType x);    //(2)插入：向顺序表中插入一个元素，同时要考虑：表是否满了？插入的位置合不合法？
ElemType Delete_SqList(SqList * L,int i);//(3)删除：顺序表中删除一个元素，同时需要考虑：有没有这个元素？删除元素其实是值的覆盖！
void DeleteValues_SqList(SqList * L,ElemType s,ElemType t);//(4)删除给定值s和t之间(要求是s<=t)的所有元素
void Traverse_SqList(SqList * L);//(5)遍历显示
void Free_SqList(SqList * L);//(6)用free()进行释放 （程序可以自动free！）


