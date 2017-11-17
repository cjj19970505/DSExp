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

	fileContent = openTextFile("source3.txt");
	printf("%d",fileContent);
	cll_SetHead(fileContent);
	FreLinkList *fll = sta_statis(fileContent);
	fll_Sortquick(fll);
	fll_Print(fll);
	
	fll_SetHead(fll);
	TPQueue tpqQueue;
	BiTree *tree = bt_CreHuff(fll);
	bt_PrintPreOrder(tree);
	printf("\n=========================\n");
	
	//printf("%d",bit_Length(bit));
	//SAMPLE
	
	Bit *binaryData = bit_CreateBit();
	//bit_AppendFromString(binaryData,"10001011",8);
	printf("\nThis is what you trying to write into out.dat\n");
	bit_AppendFromString(binaryData,"011000010100110000000111111111111111010101010101100000000000000000111111111111111111111110000101101011111111");//EBPXA
	printf("\n");
	//uncomp(tree,binaryData);
	bit_Print(binaryData);
	printf("\n");
	
	writeBinaryFile("out.dat", binaryData);
	printf("\nNow, let's read our fucking file\n");
	Bit *readBin = readBinaryFile("out.dat");
	printf("\n");
	bit_Print(readBin);
	
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


