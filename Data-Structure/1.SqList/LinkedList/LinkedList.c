#include "LinkedList.h"


//Defination

//单链表的初始化
//初始化操作为：申请一个头结点，另其指针域为空
LinkedList Init_LinkedList(){
	Node *L;    //LinkedList L;
	L = (Node *)malloc(sizeof(Node));      //申请头结点空间
	if(L == NULL)
		printf("allocate head node failed!!!\n");
	L->data = 0;                           //头结点的数据域可以存储链表长度的附加信息(此处指当前单链表长度为0)，也可以不存储任何信息
	L->next = NULL;                        //指针域=NULL，说明没有其他节点
	return L;			       //L是头结点的地址，Head头指针也指向它
}

//单链表的创建：头插法head
//使用键盘输入值;形参为要创建的单链表的节点数目；函数返回创建好的单链表头指针
/*    此处的头插法理解错了
LinkedList Create_Head_LinkedList(int n){
	LinkedList Header;                 //单链表头指针 
	Node *s;                           //新创建的节点
	ElemType temp;                     //从键盘输入的值存储在temp中
	Header = Init_LinkedList();        //头指针指向头结点
	for(int i=0;i<n;i++){
		s = (Node *)malloc(sizeof(Node));
		if(s == NULL)
			printf("allocate new Node FAILED !!!\n");
		printf("input data %d\n",i+1);
		scanf("%d",&temp);
		s->data = temp;
		s->next = Header;
		Header = s;
	}
	return Header;
}                                                         */
//头插法建立单链表：
//函数传递指针、单链表中节点个数，返回建立好的头指针（头结点的地址）
LinkedList Create_Head_LinkedList(LinkedList head,int n){
	head = (Node *)malloc(sizeof(Node));      //（Node *）跟（LinkedList）都是可以的～
	head->next = NULL;
	LinkedList s = NULL;                      //定义新节点指针时最好另其=NULL 
	ElemType temp;
	for(int i=0;i<n;i++){
	      //s = (Node *)malloc(sizeof(Node));
		s = (LinkedList)malloc(sizeof(Node));
		if(s == NULL)
			printf("allocate new Node FAILED !!!\n");
		printf("input data %d\n",i+1);
		scanf("%d",&temp);
		s->data = temp;
		s->next = head->next;
		head->next = s;
	}
	return head;
}
//尾插法建立单链表：
//要点在于要创建一个指针end始终指向 终端节点
LinkedList Create_Tail_LinkedList(LinkedList head,int n){
	head = (Node *)malloc(sizeof(Node));
	LinkedList end = NULL;  
	end = head;
	LinkedList s = NULL;
	ElemType temp;
	for(int i=0;i<n;i++){
		s= (Node *)malloc(sizeof(Node));
		if(s == NULL)
			printf("allocate new Node FAILED !!!\n");
		printf("input data [%d]\n",i+1);
		scanf("%d",&temp);
		s->data = temp;
		end->next = s;
		end = s;
	}
	end->next = NULL;   //终端节点的next赋值为NULL
	return head;
}



//单链表的遍历
//用来显示(头结点不参与遍历！)，以便检查其他算法的正确性～
void Traverse_LinkedList(LinkedList head){
	printf("here is you LinkedList:\t");
	LinkedList L = head->next;
	while(L!= NULL){
		printf("%d\t",L->data);
		L = L->next;
	}
	printf("\n");
	return;
}            

//按序号找到单链表第K个节点，并返回节点指针。
LinkedList FindKth_LinkedList(LinkedList head,int K){
	LinkedList p = NULL;             //定义节点指针p指向第K个节点，若找到，返回p;没找到，返回NULL。
	p = head;
	int i = 0;    //有两种情况：1.K<=链表长度：肯定找得到！2.K>链表长度：即遍历完时，i依然小于K。（此时i代表链表长度）
	while(p->next != NULL && i < K){
		++i;
		p = p->next;
	}
	if(i == K){
	//	printf("data %dth = %d\n",K,p->data);
		return p;
	}
	else 
		printf("FAILED! there is only %d (< %d) numbers !\n",i,K);
	return NULL;
}

//按值查找：找到单链表中是否有给定值，遇到给定值相同的节点即返回节点指针(没遇到返回NULL)，程序结束。
LinkedList Find_LinkedList(LinkedList head,ElemType X){
	LinkedList p = head->next; // 此时p指向第一个节点（如果有的话）******另p指向第一个节点而非头结点，发现更容易理解
	int i = 1;
	while(p != NULL && p->data != X){
		++i;
		p = p->next;
	}
	if(p == NULL)
		printf("you wanna find %d,but no such value!\n",X);
	else
		printf("you wanna find %d,Bingo! data %dth = %d\n",X,i,X);
	return p;
}

//求表长
int Length_LinkedList(LinkedList head){
	LinkedList p = head;
	int i = 0;
	while(p->next){
		++i;
		p = p->next;
	}
//	printf("length = %d\n",i);
	return i;
}
//插入节点：在第i个位置（第i-1后）插入一个data=X节点，要考虑的情况：插在链表头？其他位置？位置不合法？
LinkedList Insert_LinkedList(LinkedList head,int i,ElemType X){
	int length = Length_LinkedList(head);     //进行位置判断
	if(i < 1 ||i > length)
		printf("insert position illegal!\n");
	else{
		LinkedList s = NULL;                 //先初始化一个新的节点s，待插入
		s = (Node *)malloc(sizeof(Node));
		s->data = X;
		s->next = NULL;
       		if(i == 1){
			s->next = head->next;
			head->next = s;
		}
		else{
			LinkedList p = FindKth_LinkedList(head,i-1);
			s->next = p->next;
			p->next = s;
		}
	}
	return head;
}
//删除节点（元素）记得要free()!!!
LinkedList Delete_LinkedList(LinkedList head,int i){
	int length = Length_LinkedList(head);     //进行位置判断
	if(i < 1 ||i > length)
		printf("delete position illegal!\n");
	else{
		LinkedList p = NULL;
		LinkedList s = NULL;    //s始终指向要删除的节点
		if(i == 1){
			p = head;
			s = p->next;   
			p->next = s->next;
			free(s);
		}
		else{
			p = FindKth_LinkedList(head,i-1);
			s = p->next;
			p->next = s->next;
			free(s);
		}
	}
	return head;
}
//根据一维数组来建立单链表
//先假设数组长度已知=5
//参数head只是一个指针，需要为其分配节点
LinkedList Create_by_array_LinkedList(LinkedList head,ElemType array[]){
	head = (Node *)malloc(sizeof(Node));
	if(head == NULL){
		printf("allocate head node FAILED !\n");
		return NULL;
	}
	head->next = NULL;
	LinkedList s = NULL;//带插入的新节点
	LinkedList end = NULL;//尾插法最关键的一步
	end = head;
	for(int i=0;i<5;i++){
		s = (Node *)malloc(sizeof(Node));
		s->data = array[i];
		s->next = NULL;
		end->next = s;
		end = s;
	}
	return head;
}

//逆序链接：使用原有节点
//思路：使用3个指针 p:遍历链表 s:指向当前需要处理的节点 L:始终指向逆序链接完成部分的第一个节点
//因为头结点最终要指向逆序完成后的首元节点，暂将其孤立讨论
LinkedList Contray_LinkedList(LinkedList head){
	LinkedList p = head->next;//将p指向首元节点（如果有的话）
	head->next = NULL;
	LinkedList s = NULL;
	LinkedList L = NULL;
	while(p){
		s = p;//s指向当前需要处理的节点
		p = p->next;//p更新值，以期遍历传递来的单链表
		s->next = L;//另当前节点的指针域 指向 已经逆序完成部分的头结点
		L = s;//更新L的值，使其指向已经逆序完成的头结点
	}
	head->next = L;
	return head;
}

//冒泡法使单链表有序
//假设单链表长度已知=length，省掉判断是不是单链表到头
LinkedList Bubble_sort_LinkedList(LinkedList head){
	int length = Length_LinkedList(head);
	printf("length = %d\n",length);
	LinkedList h = NULL;
	LinkedList p = NULL;
	LinkedList s = NULL;
	for(int i=0;i<length-1;i++){
		h = head;
		p = head->next;
		for(int j=0;j<length-1-i;j++,h = h->next){
			p = h->next;
			s = p->next;
			if(p->data > s->data){
				p->next = s->next;
				s->next = p;
				h->next = s;	
			}
		}
	}
	return head;
}

void test_LinkedList(){
	LinkedList head = NULL;//建立空指针时 指向null是最好i的
	head = Create_Head_LinkedList(head,5);   //!!!刚开始时没有用head指向create函数，本以为head会在程序内部自动更新，然后出现了segemention fault！
//	head = Create_Tail_LinkedList(head,5);
//	Traverse_LinkedList(head);
//	FindKth_LinkedList(head,10);
//	Find_LinkedList(head,10);
//	Length_LinkedList(head);
//	Insert_LinkedList(head,6,0);
//	Traverse_LinkedList(head);
//	Length_LinkedList(head);
//	printf("length = %d\n",Length_LinkedList(head));
//	Delete_LinkedList(head,6);
//	Traverse_LinkedList(head);
//	printf("length = %d\n",Length_LinkedList(head));
//	Contray_LinkedList(head);
//	Traverse_LinkedList(head);
//	ElemType array[5] = {5,4,3,2,1};
//	head = Create_by_array_LinkedList(head,array);
//	Traverse_LinkedList(head);
//	Bubble_sort_LinkedList(head);
	Traverse_LinkedList(head);
	return;
}



int main()
{
	test_LinkedList();	
	return 0;
}








