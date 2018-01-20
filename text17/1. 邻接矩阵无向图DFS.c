#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
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
int visited[MAXVEX]; 
void DFS(AdjMatrix *G,int i){ //i为出发点 
	int j;
	visited[i]=1;
	printf("%c",G->Vex[i]);
	for(j=0;j<G->vexnum	;j++){
		if(G->acre[i][j]==1&&!visited[j]){
			DFS(G,j);
		}
	}	 
}
void DFSTraveres(AdjMatrix *G){
	int i;
	for(i=0;i<G->vexnum;i++){
		if(!visited[i]){ //对未访问的点，进行DFS，如果是联通图，只会执行一次 
			DFS(G,i);
		}		
	}	
}
int main(void){
	AdjMatrix *adj;
	adj = Create();
	printf("对图进行DFS结果如下:");
	DFSTraveres(adj);
	printf("\n");
}


