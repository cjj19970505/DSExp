//µÃµ½ÃÜÂëÊ÷£¬ÃÜÂë£»½âÑ¹upcompress;
#include<stdio.h>
#include "bit.h"
#include "BiTree.h"
void uncomp(BiTree *root,Bit *bit)
{
	int i=2,j=0;
	BiTree *curr;
	curr = root;
	printf("\nBIT_LENGTH: %d",bit_Length(bit));
	putchar('\n');
	while(j <= bit_Length(bit))
	{
		while((curr->leftTree != NULL) || (curr->rightTree != NULL))
		{
			i = bit_Get(bit, j);
			j++;
			switch(i)
			{
				case 0:
					curr = curr->leftTree;
					break;
				case 1:
					curr = curr->rightTree;
					break;
				default:
					printf("ÃÜÂë´íÎó£¬·Ç01");
					break;
			}
		}
		if(j > bit_Length(bit))
		{
			return;
		}
		if(curr->c1 > 0)
		{
			printf("%c",curr->c1);
		}
		else
		{
			printf("%c%c",curr->c1,curr->c2);
		}
		curr = root;		
	}
	putchar('\n');
}
