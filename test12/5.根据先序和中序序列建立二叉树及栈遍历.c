#include <stdio.h>
#include <string.h>
#define N 20
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;


 
BiTree CreatBiTree(char *frontArray,char *centreArray,int n){
	BiTree root;
	char lfArray[N],rfArray[N];
	char lcArray[N],rcArray[N];
	int ln,rn,i,j;
	char ch;
	if(n==0)
		return NULL;
		
	ch = frontArray[0];
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;

	for(i=0;centreArray[i]!=ch;i++){        //左子树的后序 
		lcArray[i] = centreArray[i];
		
	}
	ln=i;
	i++;
	for(rn=0;i<n;rn++,i++){               //右子树的后序				          
		rcArray[rn] = centreArray[i];
	}
	
	for(i=0;i<ln;i++){                   //左子树的先序 
		lfArray[i] = frontArray[i+1];
	}
	
	for(j=0;j<rn;j++,i++){              //右子树的先序 
		rfArray[j]=frontArray[i+1];
	}  
	
	                           
	root->lChild = CreatBiTree(lfArray,lcArray,ln);//以当前节点的左指针为下一级二叉树的跟 
	root->rChild = CreatBiTree(rfArray,rcArray,rn);//以当前节点的右指针为下一级二叉树的跟	
	return root;
}

void PostOrder(BiTree root){
	if(root==NULL)
		return;
		
	PostOrder(root->lChild);
	PostOrder(root->rChild);
	printf("%c",root->data);
}

int main(void){
	BiTree root;
	char frontArray[N],centreArray[N];
	gets(frontArray);
	gets(centreArray);
	root=CreatBiTree(frontArray,centreArray,strlen(frontArray));
	PostOrder(root); 
	
}
