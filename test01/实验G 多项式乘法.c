#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int coef;
	int expn;
	struct node *next;
}LNode,*LinkList;
int ac,bc;
LinkList CreatePoly(int iCound){
	LinkList pHead;
	LNode *pNew,*pEnd;
	int i;
	char a;
	
	pEnd=pHead = (LinkList)malloc(sizeof(LinkList));
	pHead->next=NULL;

	fflush(stdin);
	for(i=0;i<iCound+1;i++){
		pNew = (LinkList)malloc(sizeof(LinkList)) ;
		scanf("%c%d%c%d%c)",&a,&pNew->coef,&a,&pNew->expn,&a);
		
		pEnd->next = pNew;
		pEnd = pNew;
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
		if(pt==pHead->next){
			if(pt->expn==0){
				printf("%d",pt->coef);
			}else if(pt->expn==1){
				printf("%dX",pt->coef);
			}else{
				printf("%dX^%d",pt->coef,pt->expn);
			}
		}
		else{
			if(pt->coef==0){
				
			}else if(pt->expn==0){
				printf("+%d",pt->coef);
			}else if(pt->expn==1){
				if(pt->coef<0){
					printf("%dX",pt->coef);
				}else{
					printf("+%dX",pt->coef);
				}
			}else if(pt->coef<0){
				printf("%dX^%d",pt->coef,pt->expn);
			}else{
				printf("+%dX^%d",pt->coef,pt->expn);
			}				
		}
		pt=pt->next;
	}	
	printf("\n");
}
 void sore(struct node *pHead) //排序 
 {
 	struct node *pt,*pt_h,*pi;
 	pt=pHead->next;
 	pt_h=pt->next;
 	pHead->next=NULL;
 	while(pt){
 		
		for(pi=pHead;pi->next&&pi->next->expn<pt->expn;pi=pi->next);
		pt_h=pt->next;
			
		pt->next=pi->next;
		pi->next=pt;
		
		pt=pt_h; 	
	}
} 
void f1(LinkList pHead){ //合并 
	LNode *ptt;
	LNode *pt=pHead->next;
	while(pt->next){
		ptt=pt;
		pt=pt->next;
		if(ptt->expn==pt->expn){
			ptt->coef=ptt->coef+pt->coef;
			ptt->next=pt->next;
		}
		
	}
	
}
LinkList time(LinkList aHead, LinkList bHead){ //相乘 
	LinkList cHead;
	LNode *La=aHead->next;
	LNode *Lb=bHead->next;
	LNode *cNew,*cEnd;
	cEnd=cHead=(LinkList)malloc(sizeof(LinkList));
	for(La=aHead->next;La;La=La->next){ // La每一项和Lb的每一项相乘（两重循环，系数相差，指数相加） 
		for(Lb=bHead->next;Lb;Lb=Lb->next){
			cNew=(LinkList)malloc(sizeof(LinkList));
			cNew->coef=La->coef*Lb->coef;
			cNew->expn=La->expn+Lb->expn;
			cEnd->next=cNew;
			cEnd=cNew;	
		}
	}
	cEnd->next=NULL;
	sore(cHead);
	f1(cHead);
	return cHead;		
}
int main(void){
	LinkList aHead,bHead,cHead;
	int aiCound,biCound;
	scanf("%d",&aiCound);
	ac=aiCound;
	aHead=CreatePoly(aiCound);
	
	scanf("%d",&biCound);
	bc=biCound;
	bHead=CreatePoly(biCound);
	cHead=time(aHead,bHead);
	PrintPolyn(cHead);
	return 0;
}