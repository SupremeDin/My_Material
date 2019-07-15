//静态查找
//********************************
//1.无序顺序表
//即：用数组存储的查找表是无序的
//操作：@param 数组，要查找的元素k
//      return k在数组中的位置
//********************************

#include <stdio.h>


//由于存在两种情况：查找到&未查找到 需要分情况返回其索引值
int search(int *array,int K){
	int length = 10;
	for(int i=length;i>=1;i--){
		if(array[i] == K){  //
		printf("FOUND! array[%d] = %d\n",i,K);
		return i;
		}
	}
	printf("NOT FOUND!\n");
	return -1;	
}
//运用哨兵思想
//首先将array[0]=K,这样可以省去一个边界判断---------->只有一种情况：肯定可以查找到K！
//当返回值=0时：原有效数据中没有K
int search_sentinel(int *array,int K){
	int length = 10;
	int i;
	for(i=length;array[i] != K;i--);//由于设置了array[0]=K---->当i递减=0时，程序一定会退出。并且array[0]不是有效数据，原数组不产生影响。
	printf("FOUND![with sentinel] array[%d] = %d\n",i,K);
	return i;
}

#define Max 11
void test(){
	int array[Max] = {-1,9,4,3,8,1,6,7,2,5,0};//无序顺序表，只在1~10位置上存放有效数据
//	array1[] = {9,9,4,3,8,1,6,7,2,5,0};  //error C语言数组只有三种初始化方法：没有这种。。
	int K=-1;
	search(array,K);
	search_sentinel(array,K);
	return;
}
int main(){
	test();
	return 0;
}

