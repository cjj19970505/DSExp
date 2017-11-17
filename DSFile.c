#include<stdio.h>
#include<stdlib.h>
#include "DSFile.h"


//返回值指定状态 
CLinkList *openTextFile(char *fileName)
{
	FILE *pFile;
	int charCodes[100];
	pFile=fopen(fileName,"r");
	if(pFile==NULL)
	{
		return NULL;
	}
	CLinkList *fileContent = cll_Create();
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
	fclose(pFile);
	return fileContent;
}
int writeBinaryFile(char *fileName, Bit *data)
{
	FILE *fp;
	fp = fopen(fileName, "wb");
	if(fp==NULL)
	{
		return 0;
	}
	int writeState = fwrite(data->string, bit_GetUnitSize(), data->length, fp);
	fclose(fp);
	return 1;
}
Bit *readBinaryFile(char *fileName)
{
	FILE *fp;
	fp=fopen(fileName, "rb");
	if(fp == NULL)
	{
		return NULL;
	}
	Bit *binary = bit_CreateBit();
	//=====read file==============
	char fc = fgetc(fp);
	while(!feof(fp))
	{
		char bit = 0;
		for(int i=0; i<sizeof(char)*8; i++)
		{
			char c = (1 << (7-i)) & fc;
			if(c == 0)
			{
				bit = 0;
			}
			else
			{
				bit = 1;
				
			}
			printf("%d",bit);
			bit_Append(binary, bit);
		}
		printf("-");
		printf("%c-%d| ",fc,fc);
		
		fc = fgetc(fp);
	}
	fclose(fp);
	//============================
	return binary;
	
	
}


