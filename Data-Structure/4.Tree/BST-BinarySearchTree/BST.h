//********** 二叉搜索树的头文件 **************
//****包括BST的1.创建 2.插入 3.删除 4.查找****
//********************************************


typedef int ElemType;
typedef struct BSTNode{
	ElemType data;
	struct BSTNode *left;
	struct BSTNode *right;
}BSTNode,*BSTree;


//Method
BSTree Insert(ElemType X,BSTree BST);   //插入=创建

BSTree Find(ElemType X,BSTree BST);  //查找，若找到 则返回节点的位置

BSTree Find_iteration(ElemType X,BSTree current);






//Traverse just for checking the upper method

void InOrderTraverse(BSTree BST);//中序遍历


//  Extra Method
//1.显示
void display(BSTree position);
