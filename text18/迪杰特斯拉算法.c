#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
#define INFINITY 65535
typedef char Vertype;
typedef struct{
	int acre[MAXVEX][MAXVEX];//邻接表
	Vertype Vex[MAXVEX];//顶点信息
	int vexnum;//顶点数量
	int acrenum;//边的数量 
}AdjMatrix;
AdjMatrix *Create(){
	AdjMatrix *adj;
	adj = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	
	printf("请输入网的顶点数和边数:");
    scanf("%d%d",&adj->vexnum,&adj->acrenum);
	
	int i;
	printf("请输入点信息:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->Vex[i]);
	} 

	
	int j,k;
	int t;
	char a[3];
	for(i=0;i<adj->vexnum;i++) // 初始化 
		for(j=0;j<adj->vexnum;j++){
			if(i==j){
				adj->acre[i][j]=0;		
			}else{
				adj->acre[i][j]=INFINITY;	
			}
		}

	getchar();
	printf("\n请输入边信息:如ab 2\n");
	for(i=0;i<adj->acrenum;i++){
		printf("请输入第%d个边和权值",i+1);
		scanf("%s %d",a,&t);		
		j=0;
		k=0;	
		while(adj->Vex[j++] != a[0]&&j<adj->acrenum);
		while(adj->Vex[k++] != a[1]&&k<adj->acrenum);
		adj->acre[j-1][k-1]=t;
		adj->acre[k-1][j-1]=t;
	}
	
	printf("\n你输入的邻接矩阵如下:\n");
	for(i=0;i<adj->vexnum;i++){
		for(j=0;j<adj->vexnum;j++){
			printf("%-6d",adj->acre[i][j]);
		}
		printf("\n");
	}
	
	return adj;
} 
//G-->图，v0-->源点，P[v]表示v前驱顶点下标,D[v]表示V0到v的最短路径长度和 
void ShortestPath_Dijkstra(AdjMatrix *G,int v0,int *P,int *D){
	int v,w,k,min;
	int book[MAXVEX]; //标记顶点v是否已找到最短路径
	
	for(v=0;v<G->vexnum;v++){  //初始化数据 
 		book[v]=0;
		P[v]=0;
		D[v]=G->acre[0][v]; 
	} 
	
	D[v0]=0; //v0到v0距离为0 
	book[v0]=1;
	
	//开始主循环，每次求得v0到某个顶点的最短距离
	for(v=1;v<G->vexnum;v++){
		min=INFINITY;
		
		for(w=0;w<G->vexnum;w++){  //寻找到达v0距离最短的点 
			if(!book[w]&&D[w]<min){
				k=w;
				min=D[w];
			}
		}
		
		book[k]=1; //将此时找到的点标记 
		for(w=0;w<G->vexnum;w++){ //根据本次找达v0最短的点，更新其他点到v0的距离 
			
			//如果经过顶点k的路径比现在路径更短的话
			if(!book[w]&&(min+G->acre[k][w]<D[w])){
				D[w]=min+G->acre[k][w];
				P[w]=k;
			} 
		} 
	} 
}

int main(void){
	AdjMatrix *adj;
	adj=Create();
	int P[MAXVEX],D[MAXVEX];
	ShortestPath_Dijkstra(adj,0,P,D); 
	
	int v,w;

	for(v=1;v<adj->vexnum;v++){
		printf("v%d",v+1);
		w=P[v]; 
		while(w>0){
			printf("<--v%d",w+1);
			w=P[w]; 
		}
		printf("<--v1  ",w+1);	
		printf("总长度:%d\n",D[v]);
	} 
}