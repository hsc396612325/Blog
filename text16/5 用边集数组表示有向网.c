#include <stdio.h>
#define MAXVEX 30
typedef char Vertype;
//弧尾-->弧头  <尾，头> 
typedef struct ArcNode{
	int tailvex;//弧尾
	int headvex;//弧头 
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
		scanf("%d%d%d",&adj->arc[i].tailvex,&adj->arc[i].headvex,&adj->arc[i].weight);			 
	}
	
	printf("你输入的边集数组如下:\n");
	printf("顶点信息:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("%c\n",adj->vertex[i]);
	} 
	printf("边信息:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("%d %d %d\n",adj->arc[i].tailvex,adj->arc[i].headvex,adj->arc[i].weight);
	}	
	return adj;
} 

Statistics(AdjList *adj){
	int i,j; 
	int countA,countB;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		countA=0;
		countB=0;
		for(j=0;j<adj->arcnum;j++){
			if(adj->arc[j].tailvex==i){
				countA++;
			}
			if(adj->arc[j].headvex==i){
				countB++;
			}	
		}
		
		printf("顶点%c的出度为:%d,入度为:%d\n",adj->vertex[i],countA,countB);
	}	
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
}  