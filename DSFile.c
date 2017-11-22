#include<stdio.h>
#include<stdlib.h>
#include "DSFile.h"
#define SINGLEDATA_MAX_LENGTH 255
char dividChar = '\0';	//·Ö¸ô·û 
CLinkList *dsf_OpenTextFile(char *fileName)
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
int dsf_WriteBinaryFile(char *fileName, Bit *data)
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
int readHuffMapFile(char *fileName, FreLinkList *outFLL)
{
	FILE *fp;
	fp = fopen(fileName, "r");
	if(fp==NULL)
	{
		return 0;
	}
	FreLinkList *fll = fll_Create();
	int state = 1;  //1ÔÚ×Ö·û1½×¶Î 2ÔÚ×Ö·û2½×¶Î 3ÆµÊý½×¶Î 
	char ch1 = 0;
	char ch2 = 0;
	long freq = 0;
	char singleData[SINGLEDATA_MAX_LENGTH+1];
	
	char fc = fgetc(fp);
	int singleDataCharIndex = 0;
	for(int i=0;i<SINGLEDATA_MAX_LENGTH+1;i++)
	{
		singleData[i] = '\0';
	}
	while(!feof(fp))
	{
		if(fc != dividChar && state == 3)
		{
			singleData[singleDataCharIndex] = fc;
		}
		if(fc == dividChar)
		{
			if(state == 3)
			{
				char *end = NULL;
				for(end = singleData;end != '\0';end++);
				freq = strtol(singleData, &end, 10);
				for(int i=0;i<SINGLEDATA_MAX_LENGTH+1;i++)
				{
					singleData[i] = '\0';
				}
				singleDataCharIndex = 0;
				state = 1;
				printf(" %d\n",freq);
			}
			else
			{
				printf("SHIT REALLY HAPPEND");
			}
		}
		else
		{
			if(state == 1)
			{
				ch1 = fc;
				putchar(ch1);
				state = 2;
			}
			else if(state == 2)
			{
				ch2 = fc;
				putchar(ch2);
				state = 3;
			}
			else
			{
				printf("SHIT HAPPENED 222");
			}
		}
		fc = fgetc(fp);
	}
	
}
int writeHuffMapFile(char *fileName, FreLinkList *fll)
{
	FILE *fp;
	fp = fopen(fileName, "w");
	if(fp==NULL)
	{
		return 0;
	}
	char singleData[SINGLEDATA_MAX_LENGTH+1] = {0};
	for(int i=0;i<SINGLEDATA_MAX_LENGTH+1;i++)
	{
		singleData[i] = '\0';
	}
	fll_SetHead(fll);
	while(fll_MoveNext(fll))
	{
		char ch1,ch2;
		long freq;
		fll_GetData(fll,&ch1,&ch2,&freq);
		fprintf(fp,"%c", ch1);
		if(ch1>0)
		{
			ch2 = '^';
		}
		fprintf(fp,"%c", ch2);
		ltoa(freq,singleData,10);
		fprintf(fp,"%s", singleData);
		fprintf(fp,"%c", dividChar);
	}
	fclose(fp);
	return 1;
}
Bit *dsf_ReadBinaryFile(char *fileName)
{
	FILE *fp;
	fp=fopen(fileName, "rb");
	if(fp == NULL)
	{
		return NULL;
	}
	Bit *binary = bit_CreateBit();
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
			bit_Append(binary, bit);
		}
		
		fc = fgetc(fp);
	}
	fclose(fp);
	return binary;
}
Bit *cll_ToBin(CLinkList *content, FreLinkList *freLinkList)
{
	if(content == NULL || freLinkList == NULL)
	{
		return NULL;
	}
	Bit *bit = bit_CreateBit();
	cll_SetHead(content);
	while(cll_MoveNext(content))
	{
		char c1,c2;
		cll_GetData(content, &c1, &c2);
		Bit* huffCode = fll_GetHuffCode(freLinkList,c1,c2);
		bit_AppendFromBit(bit, huffCode);
	}
	return bit;
}
void saveStatisData(FreLinkList *fll)
{
	fll_SetHead(fll);
	printf("%-20s%20s%20s%20s","×Ö·û","³öÏÖ×ÖÊý","","Æµ¶È","¹þ·òÂüÂë±¾");
	long total = 0;
	while(fll_MoveNext(fll))
	{
		char c1,c2;
		long freq;
		fll_GetData(fll, &c1, &c2, &freq);
		total += freq;
	}
	printf("\n%l", total);
	fll_SetHead(fll);
	while(fll_MoveNext(fll))
	{
		char c1,c2;
		long freq;
		Bit *huffCode;
		if(c1>=0)
		{
			c2=' ';
		}
		fll_GetData(fll, &c1, &c2, &freq);
		printf("%c%-20c",c1,c2);
		printf("%-20d",freq);
		printf("%5.2f%%",(freq*100.0f)/total);
		printf("\n");
	}	
}


