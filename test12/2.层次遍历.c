#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 30
typedef char bitElemtype;
typedef struct Node{
	bitElemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;
typedef BiTree Elemtype;

typedef struct{
	Elemtype date[MAXSIZE];
	int front,rear; 
}CSeQeue;
//初始化
CSeQeue *InitSeQueue(){
	CSeQeue *qS;
	qS=(CSeQeue *)malloc(sizeof(CSeQeue));
	qS->rear=qS->front=MAXSIZE-1;
	return qS;
}
//入队
int InSeQueue(CSeQeue *qS ,Elemtype x){
	
	if((qS->rear+1)%MAXSIZE==qS->front){
		printf("队满\n");
		return FALSE;
	}
	qS->rear=(qS->rear+1)%MAXSIZE;
	qS->date[qS->rear]=x;
	return TRUE;
} 
//判空
int EmptySeQueue(CSeQeue *qS){
	
	if(qS->front == qS->rear)
		return TRUE;
	return FALSE;
} 
//出队 
int QutSeQueue(CSeQeue *qS ,Elemtype *x){
	if(!EmptySeQueue(qS)){
		qS->front=(qS->front+1)%MAXSIZE;
		*x = qS->date[qS->front];
		return TRUE;
	}
	printf("队空\n");
	return FALSE; 
} 
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
void levelOrder(BiTree root){
	BiTree p=root;
	CSeQeue *S;
	S=InitSeQueue();//创建队 
	InSeQueue(S,p);//入队 
	while(!EmptySeQueue(S)){
		QutSeQueue(S,&p);//出队 
		printf("%c",p->data);
		if(p->lChild!=NULL)
			InSeQueue(S,p->lChild);//入队 
		if(p->rChild!=NULL)
			InSeQueue(S,p->rChild);//入队 
	}
}

int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);
	levelOrder(root);
	printf("\n"); 
}