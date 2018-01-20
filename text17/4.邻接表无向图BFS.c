#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 30
typedef int Elemtype;
typedef char Vertype;

typedef struct ArcNode{
	int adhVex;//弧尾 
	struct ArcNode *next; 
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //点 
	ArcNode *head; 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXSIZE];
	int vexnum; // 顶点数
	int arcnum; //边数 
}AdjList;
typedef struct{
	Elemtype date[MAXSIZE];
	int front,rear; 
}CSeQeue;//队列 

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


AdjList *Create(){
	AdjList *adj;
	
	adj = (AdjList *)malloc(sizeof(AdjList)); 
	printf("请输入有向图的顶点的数量和边的数量:");
	scanf("%d%d",&adj->vexnum,&adj->arcnum);
	int i;
	printf("请输入点信息:\n");
	for(i=0;i < adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
		adj->vertex[i].head = NULL;
	} 
	
	
	getchar();
	int j,k;
	char a[3];
	ArcNode *arci,*arcj;
	ArcNode *p;
	printf("\n请输入边信息如ab:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("请输入第%d个边:",i+1);
		gets(a);                                                                                                                                                                                                                                  
		for(j=0;adj->vertex[j].vexdata != a[0] &&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata != a[1] &&k<adj->vexnum;k++);
		
		arci = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arci->adhVex = k;
		arci->next = adj->vertex[j].head;
		adj->vertex[j].head = arci; 
		
		arcj = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arcj->adhVex = j;
		arcj->next = adj->vertex[k].head;
		adj->vertex[k].head = arcj;
	}
	
	printf("你输入的邻接表如下:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("顶点:%c ",adj->vertex[i].vexdata);
		p = adj->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("\n");
	} 
 	return adj;
}
int visited[MAXSIZE];
void BFSTraverse(AdjList *GL){
	int i;
	CSeQeue *Q;//队
	Q=InitSeQueue();
	ArcNode *p; 
	for(i=0;i<GL->vexnum;i++){
		if(!visited[i]){
			visited[i]=1;
			printf("%c",GL->vertex[i].vexdata);
			InitSeQueue(Q,i);//入队 
			while(!EmptySeQueue(Q)){
				QutSeQueue(Q,&i);//出队
				p=GL->vertex[i].head;
				while(p){
					if(!visited[p->adhVex]){//节点未被访问 
						visited[p->adhVex]=1;
						printf("%c",GL->vertex[p->adhVex].vexdata);
						InitSeQueue(Q,p->adhVex);//入队 
					}
					p=p->next; 
				} 
				 
			}	
		}
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	printf("对图进行DFS结果如下:");
	BFSTraverse(adj);
	printf("\n");
} 