#include<stdio.h>
#include<stdlib.h>
#include "CLinkList.h"
#include "statis.h"
#include "TPQueue.h"
#include "BiTree.h"
#include "bit.h"
#include "DSFile.h"
#include "uncomp.h"

void readSourceFile();
void writeToFile(int dataLength,char* data);
CLinkList *fileContent;
int max(int a, int b);
int main()
{
	
	fileContent = openTextFile("source.txt");
	cll_Print(fileContent); 
	cll_SetHead(fileContent);
	FreLinkList *fll = sta_statis(fileContent);
	fll_Sortquick(fll);
	fll_Print(fll);
	fll_SetHead(fll);
	BiTree *tree = bt_CreHuff(fll);
	printf("\n");
	printf("%d",bt_LeaveCount(tree));
	printf("\n");
	printf("\n");
	bt_PrintPreOrder(tree);
	printf("\n");
	bt_HuffCode(tree, fll);
	fll_Print(fll);
	
	return 0;
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


