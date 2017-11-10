struct Bit
{
	//总长度
	 
	char *string;
	short invalid;     //无效位数 
	int length;			//字符总位数 
};
typedef struct Bit Bit;
//用一个二进制位来初始化 
Bit *bit_CreateBit(int value);
void bit_Input(Bit *bit, int num, int seat);

//往末尾添加一个二进制位 
void bit_Append(Bit *bit, int value);
