#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 30
typedef int Elemtype;
typedef char Vertype;

typedef struct{
	int acre[MAXSIZE][MAXSIZE];//邻接表
	Vertype Vex[MAXSIZE];//顶点信息
	int vexnum;//顶点数量
	int acrenum;//边的数量 
}AdjMatrix;//邻接矩阵 

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


AdjMatrix *Create(){
	AdjMatrix *adj;
	adj = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	
	printf("请输入无向图的顶点数和边数:");
	scanf("%d%d",&adj->vexnum,&adj->acrenum);
	
	int i;
	printf("请输入点信息:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->Vex[i]);
	} 

	
	int j,k;
	char a[3];
	for(i=0;i<adj->vexnum;i++) // 初始化 
		for(j=0;j<adj->vexnum;j++)
			adj->acre[i][j]=0;

	getchar();
	printf("\n请输入边信息:如ab\n");
	for(i=0;i<adj->acrenum;i++){
		printf("请输入第%d个边:",i+1);
		gets(a);
		
		j=0;
		k=0;	
		while(adj->Vex[j++] != a[0]&&j<adj->acrenum);
		while(adj->Vex[k++] != a[1]&&k<adj->acrenum);
		adj->acre[j-1][k-1]=1;
		adj->acre[k-1][j-1]=1;
	}
	
	printf("\n你输入的邻接矩阵如下:\n");
	for(i=0;i<adj->vexnum;i++){
		for(j=0;j<adj->vexnum;j++){
			printf("%4d",adj->acre[i][j]);
		}
		printf("\n");
	}
	
	return adj;
}
int visited[MAXSIZE]; 

void BFSTraveres(AdjMatrix *G){
	int i,j;
	CSeQeue *Q;//队
	Q=InitSeQueue();
	 
	for(i=0;i<G->vexnum;i++){
		if(!visited[i]){ //对未访问的点，进行DFS，如果是联通图，只会执行一次 
			visited[i]=1;
			printf("%c",G->Vex[i]);
	 		InSeQueue(Q,i);//入队
			  
	 		while(!EmptySeQueue(Q)){  //如果当前队不为空 
	 		
		 		QutSeQueue(Q,&i);//出队
				for(j=0;j<G->vexnum;j++){
					
					if(G->acre[i][j]==1&&visited[j]==0){//如果邻接点存在并未访问过
						visited[j]=1;
						printf("%c",G->Vex[j]);
						InSeQueue(Q,j);//入队  
					} 
				}  
		 	}
	 		
		}		
	}	
}
int main(void){
	AdjMatrix *adj;
	adj = Create();
	printf("对图进行BFS结果如下:");
	BFSTraveres(adj);
	printf("\n");
}



