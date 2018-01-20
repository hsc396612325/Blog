#include <stdio.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct{
	int row,col;           //row行号，col列号 
	ElementType value;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int rows,clos,nums;       //rows稀疏矩阵的行数，clos稀疏矩阵的列数，nues非0原的个数 
}TSMatrix; 

TSMatrix *Creation(){      //创建 
	TSMatrix *TS;
	Triple Tr;
	char c;
	TS = (TSMatrix *)malloc(sizeof(TSMatrix));
	scanf("%d%d%d",&TS->rows,&TS->clos,&TS->nums); 
	int i;
	getchar();;//这句是为了应付学校的acm
	for(i=0;i<TS->nums;i++){
		scanf("%c%d%c%d%c%d%c",&c,&Tr.row,&c,&Tr.col,&c,&Tr.value,&c);
		TS->data[i]=Tr;
	}
	return TS;
} 

void Output(TSMatrix *TS){ //输出 
	int i;
	printf("%d %d %d\n",TS->rows,TS->clos,TS->nums);
	for(i=0;i<TS->nums;i++){
		printf("(%d,%d,%d)",TS->data[i].row,TS->data[i].col,TS->data[i].value);
	}
	printf("\n");
}
TSMatrix *Add(TSMatrix *TS1,TSMatrix *TS2){ //加法 
	int i=0,j=0;
	TSMatrix *TS3;
	Triple Tr;
	TS3 = (TSMatrix *)malloc(sizeof(TSMatrix));
	TS3->nums=0;
	
	while(i<TS1->nums&&j<TS2->nums){
		if(TS1->data[i].row<TS2->data[j].row){       //TS1行号小于TS2 
			Tr=TS1->data[i];
			i++;
		}else if(TS1->data[i].row>TS2->data[j].row){ //TS1行号大于TS2 
			Tr=TS2->data[j];
			j++; 
		}else if(TS1->data[i].col<TS2->data[j].col){  //TS1行号等于TS2 TS1列号小于TS2 
			Tr=TS1->data[i];
			i++;
		}else if(TS1->data[i].col>TS2->data[j].col){  //TS1行号等于TS2 TS1列号大于TS2 
			Tr=TS2->data[j];
			j++;
		}else {         //TS1行号列号等于TS2 ,即相加 
			Tr=TS1->data[i];
			Tr.value= TS1->data[i].value+TS2->data[j].value;
			i++;
			j++;
		} 
		if(Tr.value	!=0){
				TS3->data[TS3->nums]=Tr;
				TS3->nums++;
		}	
	}
	while(i<TS1->nums){
		TS3->data[TS3->nums]=TS1->data[i];
		i++;TS3->nums++;
	}
	while(j<TS2->nums){
		TS3->data[TS3->nums]=TS2->data[j];
		j++;TS3->nums++;
	}
	TS3->rows=TS2->rows;
	TS3->clos=TS2->clos;
	return TS3;
}
 
TSMatrix *Sub(TSMatrix *TS1,TSMatrix *TS2){  //减法 
	int i=0,j=0,t;
	TSMatrix *TS3;
	Triple Tr;
	TS3 = (TSMatrix *)malloc(sizeof(TSMatrix));
	TS3->nums=0;
	while(i<TS1->nums&&j<TS2->nums){
		if(TS1->data[i].row<TS2->data[j].row){       //TS1行号小于TS2 
			Tr=TS1->data[i];
			i++;
		}else if(TS1->data[i].row>TS2->data[j].row){ //TS1行号大于TS2 
			Tr=TS2->data[j];
			Tr.value=-Tr.value;
			j++;
		}else if(TS1->data[i].col<TS2->data[j].col){  //TS1行号等于TS2 TS1列号小于TS2 
			Tr=TS1->data[i];
			i++;
		}else if(TS1->data[i].col>TS2->data[j].col){  //TS1行号等于TS2 TS1列号大于TS2 
			Tr=TS2->data[j];
			Tr.value=-Tr.value;
			j++;
		}else { 
			Tr=TS1->data[i];									//TS1行号列号等于TS2 
			Tr.value=TS1->data[i].value - TS2->data[j].value;
			i++;j++;
		} 
		
		if(Tr.value!=0){
				TS3->data[TS3->nums]=Tr;
				TS3->nums++;
		}	
	}
	while(i<TS1->nums){
		TS3->data[TS3->nums]=TS1->data[i];
		i++;TS3->nums++;
	}
	while(j<TS2->nums){
		Tr=TS2->data[j];
		Tr.value=-TS2->data[j].value;
		TS3->data[TS3->nums]=Tr;
		j++;TS3->nums++;
	}
	TS3->rows=TS2->rows;
	TS3->clos=TS2->clos;
	return TS3;
}
int main(void){
	TSMatrix *TS1;
	TSMatrix *TS2;
	TSMatrix *TS3;
	TSMatrix *TS4;
	TS1=Creation();
	TS2=Creation(); 
	TS3=Add(TS1,TS2);
	TS4=Sub(TS1,TS2); 
	Output(TS3);
	Output(TS4);
	
}