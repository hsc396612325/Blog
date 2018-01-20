#include <stdio.h>
//计算子串str2的next数组
void get_next(char *str2,int *nextval){
	int i,k;
	i=0;
	k=-1;
	nextval[0]=-1;
	while(str2[i]){
		
		if(k==-1||str2[i]==str2[k]){ //str2[i]-->后缀的单个字符 
			i++;                     //str2[j]-->前缀的单个字符  
			k++;
			if(str2[i]!=str2[k])
				nextval[i]=k;
			else
				nextval[i] = nextval[k];//当前字符和前缀字符相同，则将前缀
									    //nextval值赋给nextval在i的位置 
		}else{
			k=nextval[k];
		}
	}
} 
int Index_KMP(char *str1,char *str2,int pos){
	
	int i=pos;  
	int j=0; 
	int nextval[100]; 
	get_next(str2,nextval);//计算子串的next数组 
	
	printf("\n子串nextval数组:\n");
	int k; 
	for(k=0;str2[k];k++)
		printf("%d ",nextval[k]); 
	
	while((str1[i]&&str2[j])||j==-1){
		
		if(j==-1||str1[i]==str2[j]){ //如果此时主串和子串相等，继续向下比较 
			i++;
			j++; 
		}else{
			//i=i-j+2;   //i不需要回溯 
			//j=0;        
			j=nextval[j]; //j回退到对应的next中的值   
		}
	}
	
	if(str2[j]==0) //如果退出循环时，j指向子串末尾。则说明匹配成功 
		return i-j;
	else
		return -1; 
}
int main(void){
	char str1[100];
	char str2[30];
	printf("请输入主串:\n");
	gets(str1);
	printf("\n请输入子串\n"); 
	gets(str2);
	printf("\n\n子串在主串的%d处\n",Index_KMP(str1,str2,0));
}