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

//Prim算法求最小生成树 
void MiniSpanTree_Prim(AdjMatrix *G){
	int min,i,j,k;
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存相关顶点的权值
	
	lowcost[0]=0; //初始化第一个权值为0，即v0加入生成树中
	adjvex[0]=0; //初始化第一个顶点下标为0
	
	for(i=1;i<G->vexnum;i++){
		lowcost[i]=G->acre[0][i]; //将与v0顶点相关点的权值存入lowcost数组中
		adjvex[i]=0;  //都初始化为vo的下标 
	} 
	
	for(i=1;i<G->vexnum;i++){
		min = INFINITY; //初始化权值为无穷
		j=1;k=0;
		
		//寻找当前权值最小的边 
		while(j<G->vexnum){
			if(lowcost[j]!=0&&lowcost[j]<min){//如果权值不为0切小于min
				min = lowcost[j];
				k=j; 
			}	
			j++;
		} 
		
		printf("(%c,%c)",G->Vex[adjvex[k]],G->Vex[k]);//打印当前顶点中权值最小的边
		lowcost[k]=0;//将当前顶点的权值置为0，表示完成任务
		
		
		//更新lowcost和adjvex数组 
		for(j=1;j<G->vexnum;j++){
			if(lowcost[j]!=0&&G->acre[k][j]<lowcost[j]){
				lowcost[j]=G->acre[k][j];
				adjvex[j]=k;
			}
		} 
	} 
} 
int main(void){
	AdjMatrix *adj;
	adj = Create();
	MiniSpanTree_Prim(adj);
	printf("\n"); 
}


	