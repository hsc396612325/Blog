#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 40
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
int GetSeQueue(CSeQeue *qS ,Elemtype *x){
	if(!EmptySeQueue(qS)){
		*x = qS->date[qS->front+1];
		return TRUE;
	}
	printf("队空\n");
	return FALSE; 
} 
int main(void){
	CSeQeue *qS;
	Elemtype e,s;
	qS=InitSeQueue();
	InSeQueue(qS,0);//入队 
	InSeQueue(qS,1);
	InSeQueue(qS,0);
	int i,h=8;
	for(i=0;i<h;i++){
		do{
		QutSeQueue(qS,&s);//出队 
		GetSeQueue(qS,&e);//取出队头元素（不出对） 
		if(e!=0)
			printf("%4d",e);
		else
			printf("\n");
		InSeQueue(qS,s+e);
		}while(e!=0); 
		InSeQueue(qS,e);
	}
 	while(!EmptySeQueue(qS)){
		QutSeQueue(qS,&s);
		if (s!=0) 
			printf("%4d",s);
      }
      printf("\n");

}