#include <stdio.h>
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[50];
BiTree CreatBiTree(BiTree root){  //二叉树的建立(由扩展的先序序列建立的二叉树) 
	static int count;
	char ch=str[count];
	count++;
	if(ch=='#')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//以当前节点的左指针为下一级二叉树的跟 
	root->rChild = CreatBiTree(root->rChild);//以当前节点的右指针为下一级二叉树的跟	
	return root;
}

void exchange(BiTree root){     //交换各节点的左右子树 
	BiTree t;
	if(root==NULL)
		return;
	t=root->lChild;
	root->lChild=root->rChild;
	root->rChild=t;
	exchange(root->lChild);
	exchange(root->rChild);
}
void PreOrder(BiTree root){
	int static count;
	if(root==NULL)
		return;
		
	printf("%c",root->data);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
}
void InOrder(BiTree root){
	if(root==NULL)
		return;
		
	InOrder(root->lChild);
	printf("%c",root->data);
	InOrder(root->rChild);
}
void PostOrder(BiTree root){
	if(root==NULL)
		return;
		
	PostOrder(root->lChild);
	PostOrder(root->rChild);
	printf("%c",root->data);
}
int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);
	exchange(root);
	
	PreOrder(root); 
	printf("\n");
	
	InOrder(root);
	printf("\n");
	
	PostOrder(root); 
	printf("\n");
	
}