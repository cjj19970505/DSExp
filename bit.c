#include<stdio.h>
#include<stdlib.h>
#include "bit.h"

void bit_DeleteString(Bit *bit);
Bit *bit_CreateBit()
{
	Bit *bit = (Bit*)malloc(sizeof(Bit));
	if (bit == NULL)
	{
		return NULL;
	}
	bit->string = NULL;
	bit->invalid = 0;
	bit->length = 0;
	return bit;
}
void bit_Pop(Bit *bit)
{
	if(bit->invalid == sizeof(char)-1)
	{
		char *newString = NULL;
		int newLength = bit->length - 1;
		newString = (char*)calloc(newLength,sizeof(char));
		if(newString == NULL)
		{
			printf("Shit Happened!!!");
		}
		for(int i = 0; i < newLength; i++)
		{
			newString[i] = 0;
		}
		for(int i = 0; i < newLength; i++)
		{
			newString[i] = (bit->string)[i];
		}
		bit_DeleteString(bit);
		bit->string = newString;
		--(bit->length);
		bit->invalid = 0;
	}
	else
	{
		++bit->invalid;
	}
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
			printf("Shit happened!");
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
long bit_Length(Bit *bit)
{
	return bit->length * sizeof(char) * 8 - bit->invalid;
}
int bit_Get(Bit *bit, long pos)
{
	int charPos = pos / (sizeof(char)*8);	//这个位置是在第几个char上
	int invalid = (sizeof(char)*8)-((pos+1) % (sizeof(char)*8));
	invalid %= 8;
	char b = bit->string[charPos] & (1 << invalid);
	if(b == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void bit_Print(Bit *bit)
{
	long n = bit_Length(bit);
	for(int i = 0; i < n; i++)
	{
		printf("%d",bit_Get(bit,i));
	}
}
void bit_AppendFromString(Bit *bit, char *data)
{
	for(int i = 0; data[i] != '\0'; i++)
	{
		int b = 0;
		if(data[i] == '1')
		{
			b = 1;
			bit_Append(bit,b);
		}
		else if(data[i] == '0')
		{
			b = 0;
			bit_Append(bit,b);
		}
		
	}
}
int bit_GetUnitSize()
{
	return sizeof(char);
}






