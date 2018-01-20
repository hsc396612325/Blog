#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
//弧尾-->弧头  <尾，头> 
typedef struct ArcNode{
	int tailvex;//弧尾
	int headvex;//弧头 
	struct ArcNode *tailLink;//和它具有相同弧尾的边 
	struct ArcNode *headLink;//和它具有相同弧头的边
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //点 
	ArcNode *firstout;//连接以它为弧尾的边 
	ArcNode *firstin;//连接以它为弧头的边 
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
	
	int i=0;
	printf("请输入点信息:\n");
	for(i=0;i<adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
		adj->vertex[i].firstout=NULL;
		adj->vertex[i].firstin=NULL; 
	}
	
	getchar();
	int j,k;
	ArcNode *arc;
	char a[3];
	printf("\n请输入边信息如ab:\n");
	for(i=0;i<adj->arcnum;i++){
		
		printf("请输入第%d条边:",i+1);
		gets(a); 
		for(j=0;adj->vertex[j].vexdata!=a[0]&&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata!=a[1]&&k<adj->vexnum;k++);
		arc=(ArcNode *)malloc(sizeof(ArcNode));
		arc->tailvex=j;
		arc->headvex=k;
		
		arc->tailLink=adj->vertex[j].firstout;
		adj->vertex[j].firstout=arc;
		
		arc->headLink=adj->vertex[k].firstin;
		adj->vertex[k].firstin=arc;				 
	}
	
	printf("你输入的十字链表如下:\n");
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		printf("顶点:%c",adj->vertex[i].vexdata);
		p = adj->vertex[i].firstout;	
		while(p!=NULL){
			printf("-->%d",p->headvex);
			p=p->tailLink;	
		}
		printf("\n");	
		printf("顶点:%c",adj->vertex[i].vexdata);
		p = adj->vertex[i].firstin;
		while(p!=NULL){
			printf("<==%d",p->tailvex);
			p=p->headLink;	
		}
		printf("\n\n");
	} 	
	return adj;	
} 

Statistics(AdjList *adj){
	int i; 
	int countA,countB;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		
		for(p=adj->vertex[i].firstout,countA=0;p!=NULL;p=p->tailLink,countA++);
		for(p=adj->vertex[i].firstin,countB=0;p!=NULL;p=p->headLink,countB++);
		printf("点%c的出度为:%d,入度为:%d\n",adj->vertex[i].vexdata,countA,countB);
	}	
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
}  