#include <stdio.h>
#include <stdlib.h>
typedef enum {Link,Thread} PointerTag;//Link== 0 表示指向左右孩子的节点。
                                      //Therad == 1表示指向前驱或者后继
typedef char Elemtype;				
typedef struct BithrNode{ //二叉线索节点结构 
	Elemtype data;
	struct BithrNode *lchild,*rchild;//左右孩子指针
	PointerTag LTag; 
	PointerTag RTag; 
}BiThrNode,*BiThrTree;

char str[]="ABD^G^^^CE^^F^^";

BiThrTree CreatBiThrTree(BiThrTree	root){ //创建二叉树 
	static int count;
	char ch = str[count];
	count++; 
	if(ch == '^')
		return NULL;
	
	root = (BiThrNode *)malloc(sizeof(BiThrNode));
	root->data = ch;
	root->LTag= Link;
	root->lchild = CreatBiThrTree(root->lchild);
 	root->RTag =Link;
 	root->rchild = CreatBiThrTree(root->rchild);
 	
 	return root; 
	
} 
BiThrNode *p; // 记录前驱节点 
void InThreading (BiThrTree root){
	if(root==NULL)
		return;

	InThreading(root->lchild);//递归左子树的线索化 
	if(root->lchild==NULL){
		root->LTag =Thread;
		root->lchild = p; // 左孩子指向前驱 
	} 
	if(p!=NULL&&p->rchild == NULL){
		p->RTag = Thread;
		p->rchild = root;//前驱指向根节点 
	} 
	p = root; // 更新前驱 
	InThreading(root->rchild);//递归右子树的线索化 
}
void InOrderTraverse_Thr(BiThrTree root){
	
	BiThrNode *p;
	p=root->lchild;// p为根的左孩子
	while(p!=NULL) // 空树或者遍历结束 p == T
	{
		while(p->LTag == Link) //找到中序序列的第一个节点 
			p = p ->lchild;
		printf("%c",p->data);
		while(p->RTag==Thread && p->rchild !=NULL){
			p = p->rchild;
			printf("%c",p->data);
		} 
		p= p->rchild; 	
		
	} 
}
int main(void){
	BiThrTree root;
	root=CreatBiThrTree(root);//创建二叉树 
	InThreading(root);
	InOrderTraverse_Thr(root);//使用线索二叉树进行中序遍历 
 
}