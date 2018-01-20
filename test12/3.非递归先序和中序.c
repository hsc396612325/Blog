#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0 
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

typedef BiTree SeqElemtype;
typedef struct
{
	SeqElemtype data[MAXSIZE]; 
	int top; 
}SeqStack; 
//新建一个空栈
SeqStack *InitStack (){
	 
	SeqStack *S;
	S=malloc(sizeof(SeqStack));
	 
	S->top =-1; 
	return S;
}


//判断是否为空栈 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//入栈
int Push (SeqStack *S,SeqElemtype e){
	if(S->top==MAXSIZE-1) 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//出栈并返回 
int Pop (SeqStack *S,SeqElemtype *e){
	if(S->top == -1) 
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
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

void PreOrder(BiTree root){
	BiTree p;
	SeqStack *S;
	S = InitStack();
	p = root;
	while(p!=NULL||StackEmpty(S)==0){
		
		while(p!=NULL){     
			printf("%c",p->data); 
			Push(S,p); //入栈 
			p=p->lChild; //遍历左子树 
		}
		if(StackEmpty(S)==0){
			Pop(S,&p);//出栈 
			p=p->rChild; //遍历右子树 
		} 
		
	}	
}
void InOrder(BiTree root){
	BiTree p;
	SeqStack *S;
	S = InitStack();
	p = root;
	while(p!=NULL||StackEmpty(S)==0){
		
		while(p!=NULL){     
			Push(S,p); //入栈 
			p=p->lChild; //遍历左子树 
		}
		if(StackEmpty(S)==0){
			Pop(S,&p);//出栈 
			printf("%c",p->data); 
			p=p->rChild; //遍历右子树 
		} 
		
	}	
}
int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);	
	PreOrder(root); 
	printf("\n");
	InOrder(root); 
	printf("\n"); 
}