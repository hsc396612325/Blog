#include <stdio.h>
//str1-->主串，str2-->子串。
//返回子串在主串第pos个字符之后的位置。 如果不存在，返回-1 
int Index(char *str1,char *str2,int pos){
	
	int i=pos;  
	int j=0; 
	
	while(str1[i]&&str2[j]){
		
		if(str1[i]==str2[j]){ //如果此时主串和子串相等，继续向下比较 
			i++;
			j++; 
		}else{
			i=i-j+2;   //如果不相等 i回退到上次匹配的首位。
			j=0;       //j回退到子串的首位。 
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
	printf("请输入子串\n"); 
	gets(str2);
	printf("%d\n",Index(str1,str2,0));
}