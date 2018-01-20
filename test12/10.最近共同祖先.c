#include <stdio.h>
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[];
BiTree CreatBiTree(BiTree root){  //二叉树的建立(由扩展的先序序列建立的二叉树) 
	static int count;
	char ch=str[count];
	count++;
	if(ch=='#')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//以当前节点的左指针为下一级二叉树的跟 
	root->rChild = CreatBiTree(root->rChild);//以当前节点的右指针为下一级二叉树的跟	
	return root;
}

int  count;	
int  flag; //标记是否找到 
	
void PreOrder(BiTree root,char ch,char *array){  
	
	if(root==NULL)
		return ;
		
	count++;	
	if(root->data==ch){
		flag = 1;
		array[count]=0;
		return ;
	}else if(flag ==0&&root!=NULL){
		array[count]=root->data;	
	}
	
	
	
	if(flag==0){
		PreOrder(root->lChild,ch,array);
		PreOrder(root->rChild,ch,array);
	}
	
	count--;
	return;
}

int main(void){
	BiTree root;
	int k;
	char a,b;
	char arrayA[10],arrayB[10];
	int i=1,j=1;
	
	gets(str);
	scanf("%c %c",&a,&b);
	root=CreatBiTree(root);

	
	PreOrder(root,a,arrayA);
	count=0;	
  	flag=0;
	PreOrder(root,b,arrayB);

	for(i=1,j=1;arrayA[i]==arrayB[j];i++,j++);
	printf("%c",arrayA[i-1]);
}