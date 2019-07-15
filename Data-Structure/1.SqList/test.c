#include <stdio.h>
int get_length(int *array){
	int length = sizeof(array)/sizeof(int);
	printf("array length = %d\n",length);
	return length;
}

int main(){
	int array[10];
	for(int i=0;i<10;i++){
		array[i] = i+1;
	}
	get_length(array);
	return 0;
}
