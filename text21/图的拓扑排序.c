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
	int in;  //顶点入度 
	ArcNode *head; 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXVEX]; //顶点数组 
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
		adj->vertex[i].in=0;
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
		adj->vertex[k].in++;
		
	}
	
	printf("你输入的邻接表如下:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("顶点:%c ",adj->vertex[i].vexdata);
		p = adj->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("  入度为:%d\n",adj->vertex[i].in);
	} 
 	return adj;
}

void TopologicalSort(AdjList *GL){
	ArcNode *arc;
	int i,k,gettop;
	int top=0; //栈顶
	int count=0; //用于统计顶点的个数
	int stack[MAXVEX];	
	
	for(i=0;i<GL->vexnum;i++){
		if(GL->vertex[i].in==0){
			stack[++top]=i;
		}
	}
	
	while(top!=0){
		gettop = stack[top--]; //出栈 
		printf("%c->",GL->vertex[gettop].vexdata);
		count++; //统计输出的节点个数 
		for(arc=GL->vertex[gettop].head;arc;arc=arc->next){ //对此顶点弧表遍历 
			k=arc->adhVex;
			if(!(--GL->vertex[k].in)){  //将k顶点的邻接点度-1 
				stack[++top]=k; //如果度减为0，则入栈 
			} 
		}
	}
	
	if(count < GL->vexnum) //表示有回路 
		return 1; 
	else 
		return 0; 
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	TopologicalSort(adj);
} 