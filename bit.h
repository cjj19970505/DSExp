struct Bit
{
	//�ܳ���
	 
	char *string;
	short invalid;     //��Чλ�� 
	int length;			//�ַ���λ�� 
};
typedef struct Bit Bit;
//��һ��������λ����ʼ�� 
Bit *bit_CreateBit(int value);
void bit_Input(Bit *bit, int num, int seat);

//��ĩβ���һ��������λ 
void bit_Append(Bit *bit, int value);

long bit_Length(Bit *bit);
int bit_Get(Bit *bit, long pos);
void bit_Print(Bit *bit);
