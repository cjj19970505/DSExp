#include<stdio.h>
#include<stdlib.h>
#include "bit.h"

void bit_DeleteString(Bit *bit);
Bit *bit_CreateBit(int value)
{
	Bit *bit = (Bit*)malloc(sizeof(Bit));
	if (bit == NULL)
	{
		return NULL;
	}
	char initValue = 0;
	bit->string = (char*)malloc(sizeof(char));
	
	if(value == 1)
	{
		initValue = initValue|(1<<(sizeof(char)*8-1));
	}
	else
	{
		initValue = initValue&(~(1<<(sizeof(char)*8-1)));
	}
	(bit->string)[0] = initValue;
	//printf("%d", (bit->string)[0]);
	bit->invalid = 8*sizeof(char)-1;
	bit->length = 1;
	return bit;
}
void bit_Input(Bit *bit, int num, int seat)
{
	char a = 1;
	if(seat>8)
	{
		seat=seat%8;
	}
	if(num == 1)
	{
		a = a<<(7-seat);
		*(bit->string) = *(bit->string)|a;
	}
	if(num == 0)
	{
		a = a<<(7-seat);
		a = ~a;
		*(bit->string) = *(bit->string)&a;
	}
}
void bit_Append(Bit *bit, int value)
{
	if(bit->invalid == 0)
	{
		char *newString = NULL;
		int newLength = bit->length + 1;
		
		newString = (char*)calloc(newLength,sizeof(char));
		
		if(newString == NULL)
		{
			printf("FCUIKSJDLFKJSDF");
		}
		for(int i = 0; i < newLength; i++)
		{
			newString[i] = 0;
		}
		for(int i = 0; i < bit->length; i++)
		{
			newString[i] = (bit->string)[i];
		}
		bit_DeleteString(bit);
		bit->string = newString;
		++(bit->length);
		bit->invalid = sizeof(char)*8;
	}
	char *lastChar = &((bit->string)[bit->length-1]);
	char newLastChar;
	if(value == 1)
	{
		newLastChar = (*lastChar)|(1<<(bit->invalid-1));
	}
	else
	{
		newLastChar = (*lastChar)&(~(1<<(bit->invalid-1)));
	}
	*lastChar = newLastChar;
	--(bit->invalid);	
}

void bit_DeleteString(Bit *bit)
{
	free(bit->string);
}








