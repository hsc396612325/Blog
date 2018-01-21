#include <stdio.h>
#define MAXVEX 30
typedef char Vertype;
typedef struct ArcNode{
	int begin;
	int end;
	int weight;//权值 
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //点 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXVEX];
	ArcNode arc[MAXVEX]; 
	int vexnum; // 顶点数
	int arcnum; //边数 
}AdjList;
AdjList *Create(){
	AdjList *adj;
	adj = (AdjList *)malloc(sizeof(AdjList));
	printf("请输入有向网的顶点的数量和边的数量:");
	scanf("%d%d",&adj->vexnum,&adj->arcnum);
	
	int i=0;
	printf("\n请输入点信息:\n");
	for(i=0;i<adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
	}
	
	getchar();
	printf("\n请输入边信息(起点,终点,权值)如:0 4 6\n");
	for(i=0;i<adj->arcnum;i++){
		printf("请输入第%d条边:",i+1);
		scanf("%d%d%d",&adj->arc[i].begin,&adj->arc[i].end,&adj->arc[i].weight);			 
	}
	
	printf("你输入的边集数组如下:\n");
	printf("顶点信息:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("%c ",adj->vertex[i]);
	} 
	printf("\n");
	printf("边信息:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("%d %d %d\n",adj->arc[i].begin,adj->arc[i].end,adj->arc[i].weight);
	}	
	return adj;
} 
void sort(AdjList *G,ArcNode *edges){
	int i,j;
	ArcNode p;
	for(i=0;i<G->arcnum;i++){
		edges[i]=G->arc[i];
	} 
	for(i=0;i<G->arcnum-1;i++){
		for(j=0;j<G->arcnum-i-1;j++){
			if(edges[j].weight>edges[j+1].weight){
				p=edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=p;
			}
		}
	}
}
int Find(int *parent,int f){
	while(parent[f]>0){
		f = parent[f];
	}
	return f;
} 
void MiniSpanTree_Kruskal(AdjList *G){
	int i,n,m;
	ArcNode edges[MAXVEX]; //定义边集数组
	int parent[MAXVEX]={0};//定义一数组来判断边与边是否形成环路
	sort(G,edges);//将G中的边赋给edges，并按权值从小到大排序 
	for(i=0;i<G->arcnum;i++){
		n=Find(parent,edges[i].begin);
		m=Find(parent,edges[i].end);
		
		if(n!=m){  //如果n和m不相等，说明此边没有与现有生成树形成环路
			parent[n]=m; //将此边的结尾顶点放在下标为n的parent，表示已经放入到生成树集合中 
			printf("(%c,%c)",G->vertex[edges[i].begin],G->vertex[edges[i].end]); 
		}
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	MiniSpanTree_Kruskal(adj);	
}  