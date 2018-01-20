#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
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
	VertexNode vertex[MAXVEX];
	int vexnum; // 顶点数
	int arcnum; //边数 
}AdjList;

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
	ArcNode *arc;
	ArcNode *p;
	printf("\n请输入边信息如ab:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("请输入第%d个边:",i+1);
		gets(a);                                                                                                                                                                                                                                  
		for(j=0;adj->vertex[j].vexdata != a[0] &&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata != a[1] &&k<adj->vexnum;k++);
		
		arc = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arc->adhVex = k;
		arc->next = adj->vertex[j].head;
		adj->vertex[j].head = arc; 
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

void Statistics(AdjList *adj){
	int i,j;
	int countA,countB;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		countA=0;
		countB=0;
		printf("顶点%c：",adj->vertex[i].vexdata);
		p=adj->vertex[i].head;	
		while(p!=NULL){
			countA++;
			p=p->next;
		}
		printf("出度:%d,",countA);
		
		for(j=0;j<adj->vexnum;j++){
			p=adj->vertex[j].head;
			while(p!=NULL){
				if(p->adhVex==i){
					countB++;
				}
				p=p->next;
			}
		}
		printf("入度:%d\n",countB);	
		
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
} 