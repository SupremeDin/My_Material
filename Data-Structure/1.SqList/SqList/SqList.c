#include "SqList.h"

//(1)初始化：动态分配一个预定义大小的数组空间，并将当前长度设置为0
SqList * Init_SqList(SqList * L,int size)
{
	L->list = (ElemType *)malloc(size * sizeof(ElemType)); //malloc动态分配（在程序运行时）int类型为4个字节，sizeof()以byte为单位
	L->current_length = 0;  //空表长度为0
	L->store_length = size;  //将顺序表的存储容量设置为参数输入的值
	return L;
}
//(2)插入：向顺序表中插入一个元素，同时要考虑：表是否满了？插入的位置合不合法？
SqList * Insert_SqList(SqList * L,int i,ElemType x)    //在顺序表L中的第i(1~n)个位置插入元素x
{
	if(L->current_length == L->store_length){    //第一次编程时==错写成了= 导致每次插人操作都从full退出！
		printf("FULL!\n");
	return L;
	}
	if(i < 1 || i > L->store_length ){
		printf("position illegal !\n");
	return L;
	}
	for(int j = L->current_length;j >= i; j--)
		L->list[j+1] = L->list[j];
	L->list[i] = x;
	L->current_length++;
	return L;
}
//(3)删除：顺序表中删除一个元素，同时需要考虑：有没有这个元素？删除元素其实是值的覆盖！
ElemType Delete_SqList(SqList * L,int i)
{
	if(i < 1 || i > L->current_length){
	printf("position illegal !!!\n");
	return -1;
	}
	int temp = L->list[i];
	for(int j = i;j < L->current_length;j++)
		L->list[j] = L->list[j+1];
	--L->current_length;
	return temp;
}

//(4)删除给定值s和t之间(要求是s<=t)的所有元素
//需要遍历顺序表找到值位于（s，t）之间的元素并删除之（删除=数据覆盖）
void DeleteValues_SqList(SqList * L,ElemType s,ElemType t)
{
	int j = 1;//j由1---->current length来遍历整个顺序表
	while(j < L->current_length)
	{
		if(L->list[j] > s && L->list[j] < t)
		{
			for(int temp = j;temp < L->current_length;temp++){    //此for循环对应（1，current length-1）
			L->list[temp] = L->list[temp+1];
			}
			--L->current_length;
			continue; //这里也可以用if else来实现！
		}
		j++;
	}
	//处理最后一个元素
	if(L->list[L->current_length] > s && L->list[L->current_length] < t){
	L->list[L->current_length] = -1;
	--L->current_length;
	}
}
//(5)遍历显示

void Traverse_SqList(SqList * L)
{
	if(L->current_length == 0){
	printf("current length = %d\tEMPTY!\n",L->current_length);
	return;
	}
	printf("current length = %d\tlist[] = ",L->current_length);
	for(int i = 1;i <= L->current_length;i++){
	printf(" %d\t",L->list[i]);
	}
	printf("\n");
	return;
}

//(6)用free()进行释放 （程序可以自动free！）养成良好的变成习惯是必须的啦～：
//顺序表在建立数组时使用malloc进行动态分配，用完之后需要用free()进行释放！
void Free_SqList(SqList * L)
{
	free(L->list);
	printf("free done!\n");
	return;
}








void test_SqList(){
SqList  List_; //建立自己的顺序表   此处刚开始编程时是定义了SqList * List_运行时出现段错误！！！是因为仅仅定义了指针但是没有指向任何地址。
	Init_SqList(&List_,5);
	Traverse_SqList(&List_);
	Insert_SqList(&List_,1,2);
	Insert_SqList(&List_,2,4);
	Insert_SqList(&List_,3,6);
	Insert_SqList(&List_,4,8);
	Insert_SqList(&List_,5,10);
	Traverse_SqList(&List_);
	Delete_SqList(&List_,1);
	Traverse_SqList(&List_);
	DeleteValues_SqList(&List_,7,11);
	Traverse_SqList(&List_);
	printf("space = %ld\n",sizeof(List_)/sizeof(int));
	Free_SqList(&List_);
}


int main()
{
	test_SqList();
	return 0;
}

