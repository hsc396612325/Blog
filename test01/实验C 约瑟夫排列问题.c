#include <stdio.h>
#include <stdlib.h>
struct node
{
    int NO;
    struct node *next;
};
int b[20];
struct node *create(int iCound)//链表的创建 
{
    struct node *pHead=NULL,*pEnd,*pNew;
    int i;
    pEnd =pHead=(struct node*)malloc(sizeof(struct node));
    for(i=0,pNew=pEnd;i<iCound;i++)
    {
        pEnd=pNew;
         
        pEnd->NO=i+1;
        pNew=(struct node*)malloc(sizeof(struct node)); 
        pEnd->next=pNew; 
    }
    pEnd->next=pHead;
    return pHead;
}
struct node *f1(struct node *pHead,int iCound,int M)
{
    struct node *pi=pHead,*pi_q=pHead->next;
    int i,j=0;
    while(pi_q->next!=pi)
        pi_q=pi_q->next;
    while(pi!=pi->next)
    { 
        for(i=0;i<M-1;i++)//寻找本次需要删除的节点 
        {
            pi_q=pi;
            pi=pi->next;
        }
        b[j]=pi->NO;
        j++;
              
        pi_q->next=pi->next;//删除 
        pi=pi->next;
    }
     b[j]=pi->NO;
}
int main(void)
{
    struct node *pHead;
    int iCound,k,i,a[30],m;
    scanf("%d %d",&iCound,&k); 
	for(i=0;i<k;i++)
		scanf("%d",&a[i]);
    for(m=1;m<=iCound;m++)
	{
    	pHead=create(iCound);
    	f1(pHead,iCound,m);
    	
    	
    	for(i=0;i<k&&a[i]==b[i+iCound-k];i++);
			
		if(i==k){
			printf("%d\n",m);
			break;
		} 
    }
    if(m>iCound&&i!=k)
    	printf("0");
} 