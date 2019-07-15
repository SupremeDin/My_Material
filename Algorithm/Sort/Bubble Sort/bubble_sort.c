//冒泡法排序(正序) c语言实现
//假设传递的数组长度length已知


#include <stdio.h>
#define LENGTH 10
void bubble_sort(int a[]){
	int temp;
	for(int j=0;j<LENGTH-1;j++){    //j控制遍历的次数
		for(int i=0;i<LENGTH-1-j;i++){    //
			if(a[i] > a[i+1]){      //值比较
				temp = a[i+1];
				a[i+1] = a[i];
				a[i] = temp;    //完成值传递
			}	
		}
	}
	return;
}

void show(int a[]){
	for(int i=0;i<LENGTH;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return;
}
int main()
{
	int array[LENGTH] = {3,6,4,5,5,9,8,6,7,1};
	bubble_sort(array);
	show(array);
	return 0;
}
