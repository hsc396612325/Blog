#include <stdio.h>
#include <string.h>
#define N 54
#define M 2*N-1
typedef struct{
	int weight;
	char data; 
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];
int bucket[54];
void seek(HuffmanTree ht,int n,int *s1,int *s2){
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
void CrtHuffmanTree(HuffmanTree	ht,int n){ //创建 
	int m=2*n-1;
	int i,j;
	int s1,s2;
	for(i=0,j=0;i<54;i++){       //初始化 
		if(bucket[i]!=0){
			ht[j].weight=bucket[i];
			ht[j].parent=-1;
			ht[j].Lchild=-1;
			ht[j].Rchild=-1; 
			
			if(i==0)
				ht[j].data = ' ';
			else if(i==1)
				ht[j].data = '.';
			else if(i<26+2)
				ht[j].data = 'A'+i-2;
			else if(i<52+2)
				ht[j].data = 'a'+i-26-2;	
			j++;
		}
	}	
	
	for(j=n;j<m;j++){
		ht[j].weight=0;
		ht[j].parent=-1;
		ht[j].Lchild=-1;
		ht[j].Rchild=-1; 
	}	
	for(j=n;j<m;j++)
	{
		seek(ht,j,&s1,&s2);	 //寻找ht中i之前最小的两个元素下标，s1<s2; 
		ht[s1].parent=j;
		ht[s2].parent=j;
		ht[j].weight = ht[s1].weight+ht[s2].weight;
		ht[j].Lchild = s1;
		ht[j].Rchild = s2;
	}
}
void codinghuffman(HuffmanTree	ht,int n,char *str2){ //编码 
	int i,j;
	int p,q; 
	int str1[200];
	for(i=0;str2[i+1];i++){
		//printf("%c ",str2[i]);
		for(p=0;ht[p].data!=str2[i]&&p<n;p++);
			//printf("%c\n",ht[p].data) ;
			
		for(j=0;ht[p].parent!=-1;j++){     
			
			q=ht[p].parent;
			if(p==ht[q].Lchild){
				str1[j]='0';
			}else{
				str1[j]='1';
			}
			p=ht[p].parent;
		}
			
		for(j=j-1;j>=0;j--){
			printf("%c",str1[j]);
		}
	}			 
}
void decodeHuffmanTree(HuffmanTree ht,int n,char *str){  //解码 
	int i,j;
	int p=2*n-2; // p当前节点，p当前节点儿子
	 
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
void statistics(char *str){  
	int i;                      //统计 
	for(i=0;str[i+1];i++){
		if(str[i]==' ')
			bucket[0]++;
		else if(str[i]=='.')
			bucket[1]++;
		else if('a'<=str[i]&&str[i]<='z')
			bucket[str[i]-'a'+2+26]++;
		else if('A'<=str[i]&&str[i]<='Z')
			bucket[str[i]-'A'+2]++;
	}
} 
int WPL(HuffmanTree ht,int n){
	int wpl=0;
	int h;
	int p;
	int i;
	for(i=0;i<n;i++){
		h=0;
		for(p=i;ht[p].parent!=-1;p=ht[p].parent){
			h++;
		}
		wpl = wpl+ h*ht[i].weight;
	}
	return wpl;
}
int main(){
	HuffmanTree ht[M+1];
	char str1[200];
	char str2[900];
	int count=0;
	int i;
	gets(str1);
	gets(str2);
	//puts(str1);
	//puts(str2);
	statistics(str1);
	
	for(i=0;i<54;i++){
		if(bucket[i]!=0)
			count++;
	}
	CrtHuffmanTree(ht,count);//创建 
	codinghuffman(ht,count,str1);//编码 
	printf("\n");
	decodeHuffmanTree(ht,count,str2);//解码 
	printf("\n");
	printf("%.2lf\n",WPL(ht,count)/1.0/(strlen(str1)-1));
}