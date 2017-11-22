#ifndef BIT_H
#define BIT_H
struct Bit
{
	char *string;
	short invalid;     //无效位数 
	int length;			//字符总位数 
};
typedef struct Bit Bit;
//用一个二进制位来初始化 
Bit *bit_CreateBit();
void bit_Input(Bit *bit, int num, int seat);
Bit *bit_CreateBitEmpty();
//往末尾添加一个二进制位 
void bit_Append(Bit *bit, int value);
//获取一个二进制的长度 
long bit_Length(Bit *bit);
//获取二进制的某位 
int bit_Get(Bit *bit, long pos);
void bit_Print(Bit *bit);
void bit_AppendFromString(Bit *bit, char *data);
void bit_Pop(Bit *bit);
int bit_GetUnitSize();
Bit *bit_CopyFrom(Bit *binFrom);
void bit_AppendFromBit(Bit *bit1, Bit *bit2);
#endif
