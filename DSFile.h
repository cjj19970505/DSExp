#ifndef DSFILE_H
#define DSFILE_H
#include "CLinkList.h"
#include "DSFile.h"
#include "bit.h"
#include "statis.h"
CLinkList *openTextFile(char *fileName);
int writeBinaryFile(char *fileName, Bit *data);
Bit *readBinaryFile(char *fileName);
#endif
