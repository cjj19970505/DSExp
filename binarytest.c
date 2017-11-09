#include<stdio.h>
#include<stdlib.h>
void binary(int data);
int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen("stu.dat", "wb");
	if(fp == NULL)
	{
		printf("Cant open file");
		return 1;
	}
	int data[3] = {89, 90, 80};
	int writeState = fwrite(data, sizeof(int), 1, fp);
	//printf("WriteState: %d\n", writeState);
	fclose(fp);
	
	fp=fopen("stu.dat", "rb");
	if(fp == NULL)
	{
		printf("Cant open file\n");
		return 1;
	}
	int *readData = (int*)malloc(sizeof(int)*3);
	readData[0]=0;
	readData[1]=0;
	readData[2]=0;
	int readState = fread(readData, sizeof(int), 3, fp);
	//printf("ReadState: %d\n", readState);
	//printf("%d %d %d",readData[0],readData[1],readData[2]);
	
	binary(97);
	
	
	return 0;
}
void binary(int data)
{
	for(int i=0;i<sizeof(data)*8;i++)
	{
		//printf("%d\n",data&(1<<i));
		
		if((data & (1 << (sizeof(data)*8-1-i)))!= 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}
