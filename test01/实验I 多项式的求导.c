#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int coef;
	int expn;
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
int f1(LinkList pHead){
	LinkList pt=pHead->next;
	while(pt){
		if(pt->expn==0){
			pt->coef=0;
		}else{
			pt->coef=pt->expn * pt->coef;
			pt->expn=pt->expn-1;
		}
		pt=pt->next;
	}
}
int main(void){
	LinkList pHead;
	int iCound;
	scanf("%d",&iCound);
	pHead=CreatePoly(iCound);
	f1(pHead);
	PrintPolyn(pHead);
	return 0;
}