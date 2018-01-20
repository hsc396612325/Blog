#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 10
typedef int Elemtype;

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

int main(void){
	CSeQeue *qS;
	qS=InitSeQueue();
	int i,x;
	int j;
	for(i=0;i<15;i++){
		printf("%d %d %d\n",i,qS->front,qS->rear);
		InSeQueue(qS,i);
	}
	for(i=0;i<15;i++){
		QutSeQueue(qS,&x);
		QutSeQueue(qS,&x);
		InSeQueue(qS,16);
		printf("\n%d %d %d\n",x,qS->front,qS->rear);
		for(j=0;j<10;j++)
			printf("%d ",qS->date[j]);
	}
}