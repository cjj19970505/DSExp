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
