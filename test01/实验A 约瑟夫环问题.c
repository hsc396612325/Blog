#include <stdio.h>
#include <stdlib.h>
struct node
{
    int NO;
    int num; 
    struct node *next;
};
struct node *create(int iCound)//链表的创建 
{
    struct node *pHead=NULL,*pEnd,*pNew;
    int i;
    pEnd =pHead=(struct node*)malloc(sizeof(struct node));
    srand((unsigned)time(NULL));//随机数种子 
    for(i=0,pNew=pEnd;i<iCound;i++)
    {
        pEnd=pNew;
         
        pEnd->NO=i+1;
        scanf("%d",&pEnd->num);
        pNew=(struct node*)malloc(sizeof(struct node)); 
        pEnd->next=pNew; 
    }
    pEnd->next=pHead;
    return pHead;
}
struct node *f1(struct node *pHead,int iCound,int M)
{
    struct node *pi=pHead,*pi_q=pHead->next;
    int i;
    while(pi_q->next!=pi)
        pi_q=pi_q->next;
    while(pi!=pi->next)
    { 
        for(i=0;i<M-1;i++)//寻找本次需要删除的节点 
        {
            pi_q=pi;
            pi=pi->next;
        }
        printf("%d ",pi->NO);
              
        M=pi->num;//换密码 
        pi_q->next=pi->next;//删除 
        pi=pi->next;
    }
    printf("%d\n",pi->NO); 
}
int main(void)
{
    struct node *pHead;
    int iCound,m;
    scanf("%d %d",&iCound,&m); 
    pHead=create(iCound); 
    f1(pHead,iCound,m);
} 