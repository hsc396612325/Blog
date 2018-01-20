#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int coef;//系数 
	int expn;//指数 
	struct node *next;
}LNode,*LinkList;
LinkList CreatePoly(int iCound){
	LinkList pHead;
	LNode *pNew,*pEnd;
	int i;
	char a;
	
	pEnd=pHead = (LinkList)malloc(sizeof(LinkList));
	pHead->next=NULL;

	fflush(stdin);
	for(i=0;i<iCound+1;i++){
		pNew = (LinkList)malloc(sizeof(LinkList)) ;//申请空间
		scanf("%c%d%c%d%c)",&a,&pNew->coef,&a,&pNew->expn,&a);//填充数据
		
		pEnd->next = pNew;//链接到尾部
		pEnd = pNew;//尾指针移动
	}
	pNew->next =NULL;
	pHead=pHead->next;
	return pHead;
}
void PrintPolyn(LinkList pHead){
	LNode *pt;
	int i;
	
	while(pHead->next->next&&pHead->next->coef==0){
		pHead=pHead->next;	
	}
	if(pHead->next->next==NULL&&pHead->next->coef==0){
		printf("0");
		return;
	}
	pt=pHead->next;
	while(pt){
		if(pt==pHead->next){ //是否为第一项 
			if(pt->expn==0){ //指数是否为0 
				printf("%d",pt->coef);
			}else if(pt->expn==1){//指数是否为1
				printf("%dX",pt->coef);
			}else{ //正常情况 
				printf("%dX^%d",pt->coef,pt->expn);
			}
		}
		else{
			if(pt->coef==0){//系数是否为0 
				
			}else if(pt->expn==0){//指数是否为0 
				printf("+%d",pt->coef);
			}else if(pt->expn==1){//指数是否为1 
				if(pt->coef<0){//系数是否为负 
					printf("%dX",pt->coef);
				}else{
					printf("+%dX",pt->coef);
				}
			}else if(pt->coef<0){//系数是否为负
				printf("%dX^%d",pt->coef,pt->expn);
			}else{//正常情况 
				printf("+%dX^%d",pt->coef,pt->expn);
			}				
		}
		pt=pt->next;
	}	
	printf("\n");
}
int main(void){
	LinkList pHead;
	int iCound;
	scanf("%d",&iCound);
	pHead=CreatePoly(iCound);
	PrintPolyn(pHead);
	return 0;
}