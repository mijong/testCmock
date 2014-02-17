#include "unity.h"
#include "getFileSystemsInfo.h"
#include "MockgetFilePointFromPopen.h"

char *outputDf = NULL;
diskSpaceStatParce *pDiskSpaceStatParce = NULL;
FILE *cmockOfFpopen = NULL;

void setUp(void)
{
    outputDf = "Filesystem       1B-blocks        Used   Available Use% Mounted on\n\
/dev/sda1      52760793088 14228803584 35845013504  29% /";
    cmockOfFpopen = fmemopen(outputDf, strlen(outputDf), "rw");
    pDiskSpaceStatParce = (diskSpaceStatParce*)malloc(sizeof(diskSpaceStatParce));
    strcpy(pDiskSpaceStatParce->fileSystem[0].fileSystemName, "/dev/sda1");
    strcpy(pDiskSpaceStatParce->fileSystem[0].blockSize, "52760793088");
    strcpy(pDiskSpaceStatParce->fileSystem[0].used, "14228803584");
    strcpy(pDiskSpaceStatParce->fileSystem[0].avalable, "35845013504");
    strcpy(pDiskSpaceStatParce->fileSystem[0].usedPercent, "29%");
    strcpy(pDiskSpaceStatParce->fileSystem[0].mountOn, "/");  
}

void tearDown(void)
{
    free(pDiskSpaceStatParce);
}

void test_getFileSystemsInfo(void)
{
    getFilePointFromPopen_ExpectAndReturn("df -B 1", cmockOfFpopen);  // make a mock for getFilePointFromPopen();
    diskSpaceStatParce *pCurDiskSpaceStatParce = getFileSystemsInfo();  // get output of "df -B 1" using mocking ;
   // TEST_ASSERT_EQUAL_STRING(pDiskSpaceStatParce->fileSystem[0].fileSystemName, pCurDiskSpaceStatParce->fileSystem[0].fileSystemName);
    TEST_ASSERT_EQUAL_MEMORY(&pDiskSpaceStatParce->fileSystem[0], &pCurDiskSpaceStatParce->fileSystem[0], sizeof(diskSpaceStatUnit));
    free(pCurDiskSpaceStatParce);
}

/*
typedef struct  
{
    char fileSystemName[STR_SIZE];
    char blockSize[STR_SIZE];
    char used[STR_SIZE];
    char avalable[STR_SIZE];
    char usedPercent[STR_SIZE];
    char mountOn[STR_SIZE];
} diskSpaceStatUnit; 
*/
