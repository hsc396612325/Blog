#include <stdio.h>
#define TRUE 1
#define FALSE 0 

typedef int Elemtype ; 
typedef struct Stacknode{
	Elemtype date;
	struct Stacknode *next;
}slStacktype;

//初始化 
slStacktype *InitDupStack(){
	slStacktype *Top;
	Top = (slStacktype *)malloc(sizeof(slStacktype));
	Top->next = NULL;
	return Top;
} 

//入栈 
int pushLstack(slStacktype *Top,Elemtype X){
	struct Stacknode *New;
	if((New = (slStacktype *)malloc(sizeof(slStacktype)))==NULL)
		return FALSE;
	New->date=X;
	New->next=Top->next;
	Top->next=New;
	return TRUE;
	
}
//出栈 
int PopLstack(slStacktype *Top,Elemtype &X){
	if(Top->next==NULL)
		return FALSE;
	struct Stacknode *pt=Top->next;
	*X=pt->date;
	Top->next= pt->next;
	free(pt);
	return TRUE;
} 