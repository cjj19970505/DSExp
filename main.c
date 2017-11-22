#include <stdio.h>
#include <string.h>
#include "DSFile.h"
#include "CLinkList.h"
#include "BiTree.h"
#include "math.h"
#define FILENAME_MAX_LENGTH 256
int mainScreen();
int compressScreen();
void readFileScreen(char *target, char *overLengthInfo);
void generateHuffCode(CLinkList *fileContent, FreLinkList **outFLL, BiTree **outHuffTree, Bit **outBin);
int inputFileNameScreen(CLinkList **outContent);
int compressScreenS1(CLinkList **content);
int readNumScreen(char *errorInfo);
int inputDataScreen(CLinkList **outContent);
int outputBinFileNameScreen(Bit *binData);
int outputHuffCodeFileNameScreen(FreLinkList *fll);
int main()
{
	int end = 0;
	while(!end)
	{
		int s = mainScreen();
		if(s == 1)
		{
			int s2 = compressScreen();
		}
	}
	return 0;
}
int mainScreen()
{
	int input;
	printf("数据结构大作业\n");
	printf("1 压缩文件\n");
	printf("2 解压文件\n");
	printf("0 退出程序\n");
	input = readNumScreen("无效指令");
	printf("\n");
	return input;
}

//返回0为返回上一级 
int compressScreen()
{
	CLinkList *content;
	int com = compressScreenS1(&content);
	printf("\n");
	if(com == 0)
	{
		return 0;
	}
	printf("文件内容：\n");
	printf("=============================================================================\n");
	cll_Print(content);
	printf("\n=============================================================================");
	printf("\n");
	FreLinkList *fll;
	Bit *contentBin;
	BiTree *huffTree;
	generateHuffCode(content,&fll,&huffTree,&contentBin);
	bit_Print(contentBin);
	printf("\n");
	saveStatisData(fll);
	printf("=========展示一下解码的内容===================");
	uncomp(huffTree, contentBin);
	char outBinFilePath[FILENAME_MAX_LENGTH+1];
	printf("\n");
	printf("储存压缩文件\n");
	com = outputBinFileNameScreen(contentBin);
	
	if(com == 0)
	{
		return 0;
	}
	/*
	printf("储存码本\n");
	com = outputHuffCodeFileNameScreen(fll);
	if(com == 0)
	{
		return 0;
	}*/
	return 0;
}
int uncompressScreen()
{
	
}
//1文件成功打开 0返回上一级 
int compressScreenS1(CLinkList **content)
{
	while(1)
	{
		printf("1-输入数据\n");
		printf("2-从文件导入\n");
		printf("0-返回主菜单\n");
		int command = readNumScreen("无效指令");
		if(command == 1)
		{
			int com2 = inputDataScreen(content);
			if(com2 == 1)
			{
				return 1;
			}
		}
		else if(command == 2)
		{
			int com2 = 0;
			com2 = inputFileNameScreen(content);
			if(com2 == 0)
			{
				continue;
			}
			if(com2 == 1)
			{
				return 1;
			}
		}
		else if(command == 0)
		{
			return 0;
		}
		
	}
}
int inputDataScreen(CLinkList **outContent)
{
	printf("请输入数据：\n");
	CLinkList *content = cll_Create();
	char c = getchar();
	char prevC = 0;
	int hasPrevC = 0;
	while(c == '\n')
	{
		c = getchar();
	}
	for(;c != '\n'; c = getchar())
	{
		if(c<0 && !hasPrevC)
		{
			prevC = c;
			hasPrevC = 1;
		}
		else
		{
			if(hasPrevC)
			{
				cll_Insert(content, prevC, c);
				hasPrevC = 0;
			}
			else
			{
				cll_Insert(content, c, 0);
			}
			cll_MoveNext(content);
		}
	}
	*outContent = content;
	return 1;
}

//1文件成功打开 
int inputFileNameScreen(CLinkList **outContent)
{
	char inFilePath[FILENAME_MAX_LENGTH+1];
	printf("请输入文件路径，或者输入0返回上一级\n");
	CLinkList *content = NULL;
	while(content == NULL)
	{
		readFileScreen(inFilePath,"文件路径超长，请重新输入");
		int pathLength = strlen(inFilePath);
		if(pathLength == 1 && inFilePath[0] == '0')
		{
			printf("\n");
			return 0;
		}
		//=============================
		content = dsf_OpenTextFile(inFilePath);
		if(content == NULL)
		{
			printf("错误，输入的文件路径可能无效，请重新输入\n");
		}
	}
	*outContent = content;
	return 1;
}
int outputBinFileNameScreen(Bit *binData)
{
	char inFilePath[FILENAME_MAX_LENGTH+1];
	printf("请输入文件路径，或者输入0返回上一级\n");
	int fileState = 0;
	while(!fileState)
	{
		readFileScreen(inFilePath,"文件路径超长，请重新输入");
		int pathLength = strlen(inFilePath);
		if(pathLength == 1 && inFilePath[0] == '0')
		{
			printf("\n");
			return 0;
		}
		//=============================
		fileState = dsf_WriteBinaryFile(inFilePath,binData);
		if(fileState == 0)
		{
			printf("错误，输入的文件路径可能无效，请重新输入\n");
		}
	}
	
	return 1;
}
int outputHuffCodeFileNameScreen(FreLinkList *fll)
{
	char inFilePath[FILENAME_MAX_LENGTH+1];
	printf("请输入文件路径，或者输入0返回上一级\n");
	int fileState = 0;
	while(!fileState)
	{
		readFileScreen(inFilePath,"文件路径超长，请重新输入");
		int pathLength = strlen(inFilePath);
		if(pathLength == 1 && inFilePath[0] == '0')
		{
			printf("\n");
			return 0;
		}
		//=============================
		fileState = writeHuffMapFile(inFilePath, fll);
		if(fileState == 0)
		{
			printf("错误，输入的文件路径可能无效，请重新输入\n");
		}
	}
	FreLinkList *fll2;
	readHuffMapFile(inFilePath, fll2);
	
	return 1;
}
void readFileScreen(char *target, char *overLengthInfo)
{
	int fileNameInputOverLength = 1;
	while(fileNameInputOverLength)
	{
		for(int i=0; i<FILENAME_MAX_LENGTH+1; i++)
		{
			target[i] = '\0';
		}
		int i = 0;
		fileNameInputOverLength = 0;
		char c = getchar();
		while(c == '\n')
		{
			c = getchar();
		}
		for(;c != '\n'; c = getchar())
		{
			if(i >= FILENAME_MAX_LENGTH)
			{
				fileNameInputOverLength = 1;
				printf("%s\n",overLengthInfo);
				while(c!='\n')
				{
					c = getchar();
				}
				break;
			}
			else
			{
				target[i] = c;
				i++;
			}
		}
	}
}

//InputState:状态，如果出错的话就是1，否则是0 
int readNumScreen(char *errorInfo)
{
	const int INSTRUCTION_MAX_LENGTH = 1;
	int command = 0;
	int hasError = 1;
	while(hasError)
	{
		command = 0;
		int i = 0;
		hasError = 0;
		char c = getchar();
		while(c == '\n')
		{
			c = getchar();
		}
		for(;c != '\n'; c = getchar())
		{
			if(i >= INSTRUCTION_MAX_LENGTH || c < '0' || c > '9')
			{
				hasError = 1;
				while(c!='\n')
				{
					c = getchar();
				}
				printf("%s\n",errorInfo);
				break;
			}
			else
			{
				command = c-'0';
				i++;
			}
		}
	}
	return command;
}
void generateHuffCode(CLinkList *fileContent, FreLinkList **outFLL, BiTree **outHuffTree, Bit **outBin)
{
	cll_SetHead(fileContent);
	FreLinkList *fll = sta_statis(fileContent);
	fll_Sortquick(fll);
	fll_SetHead(fll);
	BiTree *tree = bt_CreHuff(fll);
	bt_HuffCode(tree, fll);
	Bit *fileBit = cll_ToBin(fileContent, fll);
	*outFLL = fll;
	*outHuffTree = tree;
	*outBin = fileBit;
}
char *fllToString(FreLinkList fll)
{
	
}


