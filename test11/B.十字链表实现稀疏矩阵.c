#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef int Elemtype;
typedef struct OLnode{
	int row,col;
	Elemtype value;
	struct OLnode *right,*down;
}OLNode,*OLink;
typedef struct {
	OLink rowhead[MAX],colhead[MAX];
	int rows,cols,nums;
}CrosList;

void Insert(CrosList *CL,OLNode *node){ //插入 
	OLNode *p;
	node->right=NULL;
	node->down=NULL;
	
	//插入到行中 
	if(CL->rowhead[node->row-1]==NULL)
		CL->rowhead[node->row-1]=node;
	else{                           //插入到行链里 
		p=CL->rowhead[node->row-1];
		while(p->right&&node->row > p->right->row){
			p=p->right;
		};
		node->right=p->right;
		p->right=node;
	}
		
	if(CL->colhead[node->col-1]==NULL)
		CL->colhead[node->col-1]=node;
	else{                           //插入到列链中 
		p=CL->colhead[node->col-1];
		while(p->down&&node->col > p->down->col){
			p=p->down;
		};
		node->down=p->down;
		p->down=node;
	}
}

CrosList *Creation(){ //创建 
	CrosList *CL;
	OLNode *node;
	OLNode *p;
	CL = (CrosList *)malloc(sizeof(CrosList));
	scanf("%d%d%d",&CL->rows,&CL->cols,&CL->nums);
	int i;
	for(i=0;i<CL->rows;i++)
		CL->rowhead[i]=NULL;
	for(i=0;i<CL->cols;i++)
		CL->colhead[i]=NULL;
		 
	 getchar();
	for(i=0;i<CL->nums;i++){
		node = (OLNode*)malloc(sizeof(OLNode));
		scanf("(%d,%d,%d)",&node->row,&node->col,&node->value);
		Insert(CL,node); //插入 
	}
	return CL;
} 
void Output(CrosList *CL){  //输出 
	int i;
	OLNode *node;
	if(CL==NULL)
		return; 
	printf("%d %d %d\n",CL->rows,CL->cols,CL->nums);
	for(i=0;i<CL->rows;i++){
		node = CL->rowhead[i];
		while(node){
			printf("(%d,%d,%d)",node->row,node->col,node->value);
			node=node->right;			
		}
		
	} 
	printf("\n");
	
	/*printf("%d %d %d",CL->rows,CL->cols,CL->nums); //列优先输出 
	for(i=0;i<CL->cols;i++){
		node = CL->colhead[i];
		while(node){
			printf("(%d,%d,%d)",node->row,node->col,node->value);
			node=node->down;			
		}
	} 
	printf("\n");*/

} 

int Inquire (CrosList *CL,OLNode *node){  //查询该位置是否有元素
	int i=node->row;
	int j=node->col;
	OLNode *p;
	if(CL->rowhead[i]==NULL||CL->colhead[j]==NULL)
		return 0;
	p=CL->rowhead[i];
	while(p&&p->row!=node->row&&p->col!=node->col){
		p=p->right;	
	} 
	if(p->row==node->row && p->col==node->col)
		return 1;
		
	return 0;
} 
CrosList *ADD(CrosList *CL1,CrosList *CL2){
	OLNode *pi,*pj,*pk;
	int i;
	CrosList *CL3;
	CL3 = (CrosList *)malloc(sizeof(CrosList));
	CL3->rows=CL1->rows;
	CL3->cols=CL2->cols;
	CL3->nums=0; 
	for(i=0;i<CL3->rows;i++)//初始化 
		CL3->rowhead[i]=NULL;
	for(i=0;i<CL3->cols;i++)
		CL3->colhead[i]=NULL;
		
	for(i=0;i<CL1->rows;i++){
		pi = CL1->rowhead[i];
		pj = CL2->rowhead[i];
		while(pi&&pj){
			pk=(OLNode*)malloc(sizeof(OLNode));
			if(pi->row < pj->row){        //CL1行号小于CL2 
				pk->row=pi->row;
				pk->col=pi->col;
				pk->value=pi->value;
				pi=pi->right;
			}else if(pi->row > pj->row){   //CL1行号大于CL2 
				pk->row=pj->row;
				pk->col=pj->col;
				pk->value=pj->value;
				pj=pj->right;
			}else if(pi->col < pj->col ){   //CL1行号等于Cl2 Cl1列号小于Cl2
				pk->row=pi->row;
				pk->col=pi->col;
				pk->value=pi->value;
				pi=pi->right;
			}else if(pi->col > pj->col ){    //CL行号等于CL2 Cl1列号大于Cl2 
				pk->row=pj->row;
				pk->col=pj->col;
				pk->value=pj->value;
				pj=pj->right;
			}else{							//CL1行号列号等于CL2 ,即相加 
				pk->row=pi->row;
				pk->col=pi->col;
				pk->value=pi->value+pj->value;
				pi=pi->right;
				pj=pj->right;
			}
			if(pk->value!=0){
				Insert(CL3,pk);//插入 
				CL3->nums++;	
			}		
						
		}
		while(pi){
			pk=(OLNode*)malloc(sizeof(OLNode));
			pk->row=pi->row;
			pk->col=pi->col;
			pk->value=pi->value;
			pi=pi->right;	
			Insert(CL3,pk);//插入 
			CL3->nums++;
		}
		while(pj){
			pk=(OLNode*)malloc(sizeof(OLNode));
			pk->row=pj->row;
			pk->col=pj->col;
			pk->value=pj->value;
			pj=pj->right;	
			Insert(CL3,pk);//插入 
			CL3->nums++;
		}
	} 
	return CL3;
} 
CrosList *Sub(CrosList *CL1,CrosList *CL2){
	OLNode *pi,*pj,*pk;
	int i;
	CrosList *CL4;
	CL4 = (CrosList *)malloc(sizeof(CrosList));
	CL4->rows=CL1->rows;
	CL4->cols=CL2->cols;
	CL4->nums=0; 
	for(i=0;i<CL4->rows;i++)//初始化 
		CL4->rowhead[i]=NULL;
	for(i=0;i<CL4->cols;i++)
		CL4->colhead[i]=NULL;
		
	for(i=0;i<CL1->rows;i++){
		pi = CL1->rowhead[i];
		pj = CL2->rowhead[i];
		while(pi&&pj){
			pk=(OLNode*)malloc(sizeof(OLNode));
			if(pi->row < pj->row){        //CL1行号小于CL2 
				pk->row=pi->row;
				pk->col=pi->col;
				pk->value=pi->value;
				pi=pi->right;
			}else if(pi->row > pj->row){   //CL1行号大于CL2 
				pk->row=pj->row;
				pk->col=pj->col;
				pk->value=-pj->value;
				pj=pj->right;
			}else if(pi->col < pj->col ){   //CL1行号等于Cl2 Cl1列号小于Cl2
				pk->row=pi->row;
				pk->col=pi->col;
				pk->value=pi->value;
				pi=pi->right;
			}else if(pi->col > pj->col ){    //CL行号等于CL2 Cl1列号大于Cl2 
				pk->row=pj->row;
				pk->col=pj->col;
				pk->value=-pj->value;
				pj=pj->right;
			}else{							//CL1行号列号等于CL2 ,即相加 
				pk->row=pi->row;
				pk->col=pi->col;
				pk->value=pi->value-pj->value;
				pi=pi->right;
				pj=pj->right;
			}
			if(pk->value!=0){
				Insert(CL4,pk);//插入 
				CL4->nums++;	
			}		
						
		}
		while(pi){
			pk=(OLNode*)malloc(sizeof(OLNode));
			pk->row=pi->row;
			pk->col=pi->col;
			pk->value=pi->value;
			pi=pi->right;	
			Insert(CL4,pk);//插入 
			CL4->nums++;
		}
		while(pj){
			pk=(OLNode*)malloc(sizeof(OLNode));
			pk->row=pj->row;
			pk->col=pj->col;
			pk->value=- pj->value;
			pj=pj->right;	
			Insert(CL4,pk);//插入 
			CL4->nums++;
		}
	} 
	return CL4;
} 
int main(void){
	CrosList *CL1=NULL;
	CrosList *CL2=NULL;
	CrosList *CL3=NULL;
	CrosList *CL4=NULL;
	CL1=Creation();
	CL2=Creation();
	CL3=ADD(CL1,CL2);
	CL4=Sub(CL1,CL2);
	Output(CL3);
	Output(CL4);
}
