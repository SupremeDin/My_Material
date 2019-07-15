//静态查找
//********************************
//2.有序顺序表
//即：用数组存储的查找表是有序的！
//*********  二分查找  ***************
//操作：@param 数组，要查找的元素k
//      return k在数组中的位置
//********************************



#include <stdio.h>
#define Max 11
//二分查找法：前提有序数组（链表也不可以）
//
int binary_search(int *array,int K){
	int left,right,mid;
	int NotFound = -1;//没有查找到时候，返回NotFound

	printf("K = %d\n",K);
	left = 0;
	right = Max-1;
//	mid = (left + right)/2 //整除：即对于0~10共11个元素来数，其中间位置mid=(0+10)/2=5;
	while(left <= right){
		mid = (left + right)/2;
		printf("left:array[%d]=%d \t mid:array[%d]=%d \t right:array[%d]=%d\n",left,array[left],mid,array[mid],right,array[right]);
		if(K > array[mid]){
		//	printf("")
			left = mid+1;
		}
		else if(K < array[mid])
			right = mid-1;
		else {
			printf("Found! array[%d] = %d\n",mid,K);
			return mid;
		}
	}
	printf("Not Found![return -1]\n");
	return NotFound;

}





void test(){
	int array[Max] = {1,3,5,7,9,10,12,15,16,20,25};//定义一个有序的数组！  在这里有效数据部分为1~10
	int K= 15;
	binary_search(array,K);
	return;
}

int main(){
	test();
	return 0;
}
