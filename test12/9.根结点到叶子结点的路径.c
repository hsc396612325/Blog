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
char  array[20];
void PreOrder(BiTree root){     
	int static count;
	
	int i;
	if(root==NULL)
		return;
	count++;	
	if(root->lChild==NULL&&root->rChild==NULL){
		printf("%c:",root->data);
		
		for(i=1;i<count;i++){
			printf("%c",array[i]);
		}
			
		printf("\n");
	}else{
		array[count]=root->data;
	}
	PreOrder(root->lChild);
	PreOrder(root->rChild);
	count--;
}
int main(void){
	BiTree root;
	int k;
	gets(str);
	root=CreatBiTree(root);
	PreOrder(root);
	printf("\n"); 
}