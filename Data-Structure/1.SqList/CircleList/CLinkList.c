//Defination

//循环链表初始化
//实现：定义一个头结点并指向本身（循环链表为空）
CLinkList Init_CLinkList(CLinkList head){
	head = (Node *)malloc(sizeof(Node));
	if(!head)
		prinf("头结点分配失败！\n");
	head->next = head;
	return head;
}
