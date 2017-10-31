#include<stdio.h>
#include<stdlib.h>
#include "CLinkList.h"
#include "statis.h"
#include "TPQueue.h"
void readSourceFile();
void writeToFile(int dataLength,char* data);
CLinkList fileContent;
int max(int a, int b);
int main(){
	cll_Create(&fileContent);
	
	readSourceFile();
	FreLinkList fll;
	cll_SetHead(&fileContent);
	sta_statis(&fll,&fileContent);
	fll_Print(&fll);
	BiTree t1,t2,t3,t4;
	bt_Create(&t1,0,0,45);
	bt_Create(&t2,0,0,23);
	bt_Create(&t3,0,0,2);
	bt_Create(&t4,0,0,111);
	TPQueue tpqQueue;
	
	
	
	
	return 0;
}
int max(int a, int b)
{
	return a>b?a:b;
	//==============
	//==============
}
void readSourceFile(){
	FILE *pFile;
	int charCodes[100];
	pFile=fopen("source.txt","r");
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
			cll_Insert(&fileContent, preCh, ch);
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
				cll_Insert(&fileContent, ch, 0);
			}
		}
		cll_MoveNext(&fileContent);
		ch=fgetc(pFile);
		count++;
	}
	
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


