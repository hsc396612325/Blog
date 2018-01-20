#include <stdio.h>
#define N 30
#define M 2*N-1
typedef struct{
	int weight;
	char data; 
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];
void seek(HuffmanTree ht,int n,int *s1,int *s2){  //寻找ht中i之前最小的两个元素下标，s1<s2; 
	int i,j;
	for(i=0;i<n&&ht[i].parent!=-1;i++); //s1,s2的初始化 
	j=i;
	i++;
	for(;i<n&&ht[i].parent!=-1;i++);
	*s1 = ht[i].weight<ht[j].weight?i:j;
	*s2 = ht[i].weight<ht[j].weight?j:i;
	i++;
	while(i<n){
		if(ht[i].parent!=-1){
			
		}else if(ht[i].weight<ht[*s1].weight){
			*s2 = *s1;
			*s1 = i;
		}else if(ht[i].weight<ht[*s2].weight){
			*s2 = i;
			
		}
		i++; 
	}
}
void CrtHuffmanTree(HuffmanTree	ht,int n){ //创建哈夫曼树 
	int m=2*n-1;
	int i;
	int s1,s2;
	for(i=0;i<n;i++){       //初始化 
		scanf("%d",&ht[i].weight);
		ht[i].data = 'A'+i; 
		ht[i].parent=-1;
		ht[i].Lchild=-1;
		ht[i].Rchild=-1; 
	}	
	for(i=n;i<m;i++){
		ht[i].weight=0;
		ht[i].parent=-1;
		ht[i].Lchild=-1;
		ht[i].Rchild=-1; 
	}
	
	for(i=n;i<m;i++)
	{
		seek(ht,i,&s1,&s2);	 //寻找ht中i之前最小的两个元素下标，s1<s2; 
		ht[s1].parent=i;  //更改s1和s2的双亲 
		ht[s2].parent=i;  
		ht[i].weight = ht[s1].weight+ht[s2].weight;
		ht[i].Lchild = s1;
		ht[i].Rchild = s2;
	}

}
void codinghuffman(HuffmanTree	ht,int n){ //编码所有的叶子节点 
	int i,j;
	char str[N];
	int p,q; //p当前节点，q是p的双亲节点 
	for(i=0;i<n;i++){
		p=i;
		for(j=0;ht[p].parent!=-1;j++){     
			
			q=ht[p].parent;
			if(p==ht[q].Lchild){ //如果是左节点,则为0 
				str[j]='0';
			}else{           //如果是右节点,则为1 
				str[j]='1';
			}
			p=ht[p].parent;
		}
		
		printf("%c:",ht[i].data); //打印结果 
		for(j=j-1;j>=0;j--){
			printf("%c",str[j],j);
		}
		printf("\n");
	}
} 

void aCodinghuffman(HuffmanTree	ht){ //编码字符串 
	int i,j;
	char in[N];
	char str[N];
	int p,q;
	getchar();
	gets(in);	
	for(i=0;in[i];i++){ //遍历每个字母 
		p=in[i]-'A'; //确定该叶子节点存储的位置,这句根据具体问题而定 
		for(j=0;ht[p].parent!=-1;j++){    //解码每个字母 
			
			q=ht[p].parent;
			if(p==ht[q].Lchild){ //如果是左孩子 
				str[j]='0';
			}else{            //如果是右孩子 
				str[j]='1';
			}
			p=ht[p].parent;
		} 
		for(j=j-1;j>=0;j--){  //打印结果 
			printf("%c",str[j],j);
		}
	}
	printf("\n");
} 

void decodeHuffmanTree(HuffmanTree ht,int n){ //译码 
	int i,j;
	char str[N];
	int p=2*n-2; // p当前节点，p当前节点儿子
	 
	gets(str);
	for(i=0;str[i];i++){
		if(str[i]=='1'){
			p = ht[p].Rchild;
		}else if(str[i]=='0'){
			p = ht[p].Lchild;
		}
		if(ht[p].Lchild==-1&&ht[p].Rchild==-1){  //当前字段解码完毕 
			printf("%c",ht[p].data);
			p =2*n-2; 
		}
	} 
} 
int main(){
	HuffmanTree ht[M+1];
	CrtHuffmanTree(ht,6);//创建 
	codinghuffman(ht,6);
	aCodinghuffman(ht);
	decodeHuffmanTree(ht,6);
}