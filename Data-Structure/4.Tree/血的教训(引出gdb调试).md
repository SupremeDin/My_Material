一个找了一晚上的错误
=====
- 引出unix环境下的GDB调试
- 本次错误的受启发的链接： https://blog.csdn.net/quanquanyuanxin/article/details/52883895
---
错误再现：
```
#if 0
pQueue Create_Queue(int Max){
        Queue queue;
        pQueue q = &queue;
        q->data = (queueElemType *)malloc(Max * sizeof(queueElemType));
        q->front = 0;
        q->rear = 0; //初始化时候front = rear：表示此时候队列是控队列
        q->Maxsize = Max;
        return q;
}
#endif
```
这是 创建队列的子函数 （看起来没啥错误啊～）
于是在main() 中做如下调用：
```
...
	pQueue q;
	q = Create_Queue(7);//运行到这里，没有问题
	EnQueue();//问题来了，
	DeQueue();//问题来了，
	.......
...
```
上面的两段代码，编译没有问题（语法没问题）；（运行也没问题但这不是重点）
接下来加上 入队、出队操作，编译器显示：

> ./a.out
     Floating point exception (core dumped)
     
出现`浮点数异常`，参照网上教程：要么review代码，自己找错误；要么使用GDB进行调试！debug一下 找到出现问题的地方！（一般的段错误也是这样定位出错的地方。）

- **GDB调试**
	1.首先在编译时候加入 -g参数（或者其他能够生成gdb编译信息的参数）
	gcc main.c -g       (因为编译没有错误，故一定会生成a.out)
	2.进gdb模式
	gdb a.out  （或者 先输入gdb 进入gdb模式，然后输入file a.out）
	3.输入r指令
	`r` means `run`
	.............
	
-  在本例子中，输入r后，程序运行到：停止了：

> (gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/din/Study/Data-Structure/4.Tree/BinaryTree/a.out 
Breakpoint 1, 0x0000555555554eee in IsFull_Queue (q=0x7fffffffdab0) at level_order_Traverse.c:22
22		return ( q->front == (q->rear + 1) % q->Maxsize );	 

- 于是开始开始反思为什么会在22处中断？（仅仅是22行引起的吗，因为code看起来很清爽 没错误啊）
- 注释掉这个子函数，继续debug。
	发现又在其他的地方break了。
- 但是break的地方有一个共同处：都是访问了队列q。又结合 [链接](https://blog.csdn.net/quanquanyuanxin/article/details/52883895)  意识到可能是在创建的队列q的时候出现了问题。（任何数据结构的创建都有问题）
- 回到Create_Queue()子函数，分析之后发现：
```
	Queue queue;
	pQueue q = &queue;
```
这两句代码是在子函数内部定义的，（本意是创建实体的queue，将其地址赋给q）但是出了子函数以后，实体queue就不复存在了，只剩下一个q，自然这个q是满足create_Queue()函数的（使其在运行时候不出错）。但当进一步，在EnQueue()函数中需要去访问q所指向的内存的时候，错误就出现了！！！

- 修改方法：在主函数中定义queue的实体！
```
int main()
{
	Queue queue;//定义一个队列实体
	pQueue q = &queue;
	Create_Queue(q,7);
	IsEmpty_Queue(q);
	IsFull_Queue(q);
	EnQueue(q,tree);
	DeQueue(q);
	return 0;
}
```