#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 

typedef int Elemtype;
//节点 
typedef	 struct node{
	Elemtype date;
	struct node *next;
}QNode;

typedef struct{
	QNode *rear;
}LQueue;

//初始化
LQueue *InitLQueue(){
	LQueue *Qr;
	QNode *p;
	Qr=(LQueue *)malloc(sizeof(LQueue));
	p=(QNode *)malloc(sizeof(QNode));
	Qr->rear=p;
	p->next=p;
	return Qr; 
}

//入队
int InLQueue(LQueue *Qr ,Elemtype x){
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->date=x;
	p->next=Qr->rear->next;
	
	Qr->rear->next=p;
	Qr->rear=p;
		
	return TRUE; 
} 
 
//判空队 
int EmptyLQueue(LQueue *Qr){
	if(Qr->rear==Qr->rear->next)
		return TRUE;
	
	return FALSE;
} 

//出队
int QutLQueue(LQueue *Qr ,Elemtype *x){
	QNode *p;
	if(!EmptyLQueue(Qr)){ //栈不空 
	
		p=Qr->rear->next->next;
		*x=p->date;
		
		Qr->rear->next->next=p->next;//删除
		if(p==Qr->rear)
			Qr->rear=Qr->rear->next; 
		free(p);
		return TRUE; 		 
	}
	printf("空队\n"); 
	return FALSE; 
} 

int main(void){
	LQueue *Qr;
	Qr=InitLQueue();
	InLQueue(Qr,2);
	InLQueue(Qr,10);
	//InLQueue(Qr,10);
	int x,y,z;
	QutLQueue(Qr,&x);
	QutLQueue(Qr,&y);
	QutLQueue(Qr,&z);
	printf("%d %d %d\n",x,y,z);
}