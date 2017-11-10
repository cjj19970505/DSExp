#ifndef BIT_H
#define BIT_H
struct Bit
{
	//�ܳ���
	 
	char *string;
	short invalid;     //��Чλ�� 
	int length;			//�ַ���λ�� 
};
typedef struct Bit Bit;
//��һ��������λ����ʼ�� 
Bit *bit_CreateBit();
void bit_Input(Bit *bit, int num, int seat);
Bit *bit_CreateBitEmpty();
//��ĩβ���һ��������λ 
void bit_Append(Bit *bit, int value);

long bit_Length(Bit *bit);
int bit_Get(Bit *bit, long pos);
void bit_Print(Bit *bit);
void bit_AppendFromString(Bit *bit, char *data, int n);
void bit_Pop(Bit *bit);
#endif
