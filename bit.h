#ifndef BIT_H
#define BIT_H
struct Bit
{
	//总长度
	 
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

long bit_Length(Bit *bit);
int bit_Get(Bit *bit, long pos);
void bit_Print(Bit *bit);
void bit_AppendFromString(Bit *bit, char *data, int n);
void bit_Pop(Bit *bit);
#endif
