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

//链队的头尾指针
typedef struct{
	QNode *front;
	QNode *rear;
}LQueue;

//初始化
LQueue *InitLQueue(){
	LQueue *qL;
	QNode *p;
	qL=(LQueue *)malloc(sizeof(LQueue));
	p=(QNode *)malloc(sizeof(QNode));
	p->next=NULL;
	qL->front=qL->rear=p;
	return qL; 
}

//入队
int InLQueue(LQueue *qL ,Elemtype x){
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->date=x;
	p->next=NULL;
	
	qL->rear->next=p;
	qL->rear=p;
		
	return TRUE; 
} 
 
//判空队 
int EmptyLQueue(LQueue *qL){
	if(qL->front==qL->rear)
		return TRUE;
	
	return FALSE;
} 

//出队
int QutLQueue(LQueue *qL ,Elemtype *x){
	QNode *p;
	if(!EmptyLQueue(qL)){ //栈不空 
	
		p=qL->front->next;
		*x=p->date;
		
		qL->front->next=p->next;//删除
		free(p);
		
		if(qL->front->next ==NULL)
			qL->rear = qL->front;
		return TRUE; 		 
	}
	printf("空队\n"); 
	return FALSE; 
} 

int main(void){
	LQueue *qL;
	qL=InitLQueue();
	InLQueue(qL,1);
	InLQueue(qL,10);
	int x,y;
	QutLQueue(qL,&x);
	QutLQueue(qL,&y);
	printf("%d %d\n",x,y);
}