#include <stdio.h>
#define MAX 50 
int main(void){
	int i,j;
	int a[MAX][MAX];
	int rows,cols;
	int minrows[MAX],maxcols[MAX];//存储这一行最小和这一行最大值 
	int flag=0;
	scanf("%d%d",&rows,&cols);
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<rows;i++){
		minrows[i]=a[i][0];
		for(j=1;j<cols;j++){
			if(minrows[i]>a[i][j])
				minrows[i]=a[i][j];
		}
	}	
	
	for(j=0;j<cols;j++){
		maxcols[j]=a[0][j];
		for(i=0;i<rows;i++){
			if(maxcols[j]<a[i][j])
				maxcols[j]=a[i][j];
		}
		
	}
	
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(minrows[i]==maxcols[j])
			{
				printf("(%d,%d,%d)",i+1,j+1,a[i][j]);
				flag=1;
			}	
		}
	}
	if(flag==0){
		printf("NONE");
	}
} 