#ifndef DSFILE_H
#define DSFILE_H
#include "CLinkList.h"
#include "DSFile.h"
#include "bit.h"
#include "statis.h"
CLinkList *dsf_OpenTextFile(char *fileName);
int dsf_WriteBinaryFile(char *fileName, Bit *data);
Bit *dsf_ReadBinaryFile(char *fileName);
Bit *cll_ToBin(CLinkList *content, FreLinkList *freLinkList);
void saveStatisData(FreLinkList *fll);
int writeHuffMapFile(char *fileName, FreLinkList *fll);
int readHuffMapFile(char *fileName, FreLinkList *outFLL);
#endif
