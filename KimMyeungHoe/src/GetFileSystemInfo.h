#include <stdio.h>
#include <string.h>
#include "errno.h"

#define BUFF_SIZE 1024
#define STR_SIZE 100
#define STRUCT_LIST_SIZE 200

typedef struct {
    char fileSystemName[STR_SIZE];
    char blockSize[STR_SIZE];
    char used[STR_SIZE];
    char avalable[STR_SIZE];
    char usagePercent[STR_SIZE];
    char mountOn[STR_SIZE];
} diskSpaceStat;

typedef struct {
    int listCount;  /* count of dfPrintFormat list */
    diskSpaceStat fileSystem[STRUCT_LIST_SIZE];
} diskSpaceStatParce;

diskSpaceStatParce *GetFileSystemInfo(void); /* save result screen of "df -B 1" */

