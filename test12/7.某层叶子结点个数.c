#include <stdio.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[];
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

int f1(BiTree root,int k){   
	int static countlevel;
	int static countleaf;
	if(root==NULL)
		return;
	countlevel++;	
	if(countlevel == k&&root->lChild==NULL&&root->rChild==NULL)
		countleaf++;
	f1(root->lChild,k);
	f1(root->rChild,k);
	countlevel--;
	return countleaf;
}
int main(void){
	BiTree root;
	int k;
	gets(str);
	scanf("%d",&k); 
	root=CreatBiTree(root);
	printf("%d",f1(root,k));
	printf("\n"); 
}