#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
typedef struct ArcNode{
	int ivex;//边的i顶点 
	int jvex;//边的j顶点 
	struct ArcNode *ilink;//指向同样具有i顶点的边 
	struct ArcNode *jlink;//指向同样具有j顶点的边
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //点 
	ArcNode *firstdge;//连接以它为弧尾的边 
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
		adj->vertex[i].firstdge=NULL;
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
		arc->ivex=j;
		arc->jvex=k;
		
		arc->ilink=adj->vertex[j].firstdge;
		adj->vertex[j].firstdge=arc;
		
		arc->jlink=adj->vertex[k].firstdge;
		adj->vertex[k].firstdge=arc;				 
	}
	
	printf("你输入的邻接多重表如下:\n");
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		printf("顶点:%c",adj->vertex[i].vexdata);
		p = adj->vertex[i].firstdge;	
		while(p!=NULL){
			if(p->ivex==i){
				printf("-->%d",p->jvex);
				p=p->ilink;
			}else{
				printf("-->%d",p->ivex);
				p=p->jlink;
			}
				
		}
		printf("\n");	
	} 	
	return adj;	
} 
void Statistics(AdjList *adj){
	int i; 
	int count;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		
		for(p=adj->vertex[i].firstdge,count=0;p!=NULL;count++){
			if(p->ivex==i){
				p=p->ilink;
			}else{
				p=p->jlink;
			}
		}
		printf("点%c的度为:%d\n",adj->vertex[i].vexdata,count);
	}
} 
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
}  