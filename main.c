#include<stdio.h>
#include<stdlib.h>
#include "CLinkList.h"
#include "statis.h"
#include "TPQueue.h"
#include "BiTree.h"
#include "bit.h"
void readSourceFile();
void writeToFile(int dataLength,char* data);
CLinkList *fileContent;
int max(int a, int b);
int main(){
	fileContent = cll_Create();
	readSourceFile();
	
	cll_SetHead(fileContent);
	FreLinkList *fll = sta_statis(fileContent);
	fll_Sortquick(fll);
	fll_Print(fll);
	/*
	fll_SetHead(fll);
	TPQueue tpqQueue;
	BiTree *tree = bt_CreHuff(fll);
	bt_PrintPreOrder(tree);
	printf("\n=========================\n");
	
	//printf("%d",bit_Length(bit));
	//SAMPLE
	
	Bit *binaryData = bit_CreateBit();
	//bit_AppendFromString(binaryData,"10001011",8);
	printf("\n****\n");
	bit_AppendFromString(binaryData,"0010001101001100000001",22);//EBPXA
	
	bit_Print(binaryData);
	printf("\n****\n");
	uncomp(tree,binaryData);*/
	
	return 0;
}
void readSourceFile(){
	FILE *pFile;
	int charCodes[100];
	pFile=fopen("source3.txt","r");
	if(pFile==NULL)
	{
		printf("File open failed");
		exit(1);
	}
	char ch = fgetc(pFile);
	char preCh = ch;
	int isChinese = 0;
	int count = 0;
	while(ch != EOF)
	{
		if(isChinese)
		{
			cll_Insert(fileContent, preCh, ch);
			isChinese = 0;
		}
		else
		{
			if(ch < 0)
			{
				preCh = ch;
				isChinese = 1;
			}
			else
			{
				cll_Insert(fileContent, ch, 0);
			}
		}
		cll_MoveNext(fileContent);
		ch=fgetc(pFile);
		count++;
	}
	int *code;
	//getHuffCode(fileContent, code);
	
	fclose(pFile);
}
void writeToFile(int dataLength,char* data)
{
	FILE *pFile;
	int charCodes[100];
	pFile=fopen("xx.txt","at");
	if(pFile==NULL){
		printf("File open failed");
		exit(1);
	}
	int i=0;
	for(i=0;i<dataLength;i++){
		fputc(data[i],pFile);
	}
	fclose(pFile);
}


