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
	
	printf("请输入有向网的顶点数和边数:");
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
//G-->图，v0-->源点，P[v][w]表示v到其余各点w最短路径，D[v][w]表示v到其余各点w的带权路径长度和 
void ShortestPath_Floyd(AdjMatrix *G,int P[MAXVEX][MAXVEX],int D[MAXVEX][MAXVEX]){
	int v,w,k;
	
	//初始化D和P 
	for(v=0;v<G->vexnum;v++){
		for(w=0;w<G->vexnum;w++){
			D[v][w] = G->acre[v][w];
			P[v][w] = w; 
		}
	}
	
	for(k=0;k<G->vexnum;k++){
		for(v=0;v<G->vexnum;v++){
			for(w=0;w<G->vexnum;w++){
				
				if(D[v][w]>D[v][k]+D[k][w]){ //如果经过下标为k的顶点路径比原两点间的路径更短，则更新 
					D[v][w] = D[v][k]+ D[k][w];
					P[v][w] = P[v][k]; //路径设置经过下标为k的顶点 
				}
			}
		}
	}

}

int main(void){
	AdjMatrix *adj;
	adj=Create();
	int P[MAXVEX][MAXVEX],D[MAXVEX][MAXVEX];
	ShortestPath_Floyd(adj,P,D); 
	
	int v,w;

	printf("矩阵D:\n");
	for(v=0;v<adj->vexnum;v++){
		for(w=0;w<adj->vexnum;w++){
			printf("%-4d",D[v][w]);
		}
		printf("\n"); 
	} 
	
	printf("\n矩阵P:\n");
	for(v=0;v<adj->vexnum;v++){
		for(w=0;w<adj->vexnum;w++){
			printf("%-4d",P[v][w]);
		}
		printf("\n"); 
	} 
	
}