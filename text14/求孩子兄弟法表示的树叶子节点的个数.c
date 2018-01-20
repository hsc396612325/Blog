#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[]="ABD^E^F^^CG^^^^";

BiTree CreatBiTree(BiTree root){
	static int count;
	char ch = str[count];
	count++;
	if(ch=='^')
		return NULL;
		
	root = (BiTNode*)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);
	root->rChild = CreatBiTree(root->rChild);
	return root;
} 


int Statistics(BiTree	root){
	static int count;
	if(root==NULL)
		return ;
	if(root->lChild==NULL)
		count++;
		
	Statistics(root->lChild);
	Statistics(root->rChild);

	return count;
} 


int Depth(BiTree root){
	int hchild,hsibling;
	
 	if(root==NULL)
		return 0;
		
	hchild=Depth(root->lChild);
	hsibling =Depth(root->rChild);
	
	if(hchild+1>hsibling){
		return hchild+1;
	}else{
		return hsibling;
	}
}
int main(void){
	BiTree root;
	root = CreatBiTree(root);
	printf("树的叶子节点个数:%d,深度为%d\n",Statistics(root),Depth(root));	
}