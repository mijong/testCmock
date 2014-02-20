#include "unity.h"
#include "GetFileSystemInfo.h"
#include "MockGetFilePoint.h"

char *outputDf;
diskSpaceStatParce *pDiskSpaceStatParce;
FILE *pMockFile;

void setUp(void)
{
    outputDf = "Filesystem       1B-blocks        Used   Available Use% Mounted on\n\
    /dev/sda1      52760793088 14228803584 35845013504  29% /";
    pMockFile = fmemopen(outputDf, strlen(outputDf), "rw");
    pDiskSpaceStatParce = (diskSpaceStatParce *)malloc(sizeof(diskSpaceStatParce));
    strcpy(pDiskSpaceStatParce->fileSystem[0].fileSystemName, "/dev/sda1");
    strcpy(pDiskSpaceStatParce->fileSystem[0].blockSize, "52760793088");
    strcpy(pDiskSpaceStatParce->fileSystem[0].used, "14228803584");
    strcpy(pDiskSpaceStatParce->fileSystem[0].avalable, "35845013504");
    strcpy(pDiskSpaceStatParce->fileSystem[0].usagePercent, "29%");
    strcpy(pDiskSpaceStatParce->fileSystem[0].mountOn, "/");
}

void tearDown(void)
{
    free(pDiskSpaceStatParce);
}

void test_GetFileSystemsInfo(void)
{
    GetFilePoint_ExpectAndReturn("df -B 1", pMockFile);  /* make a mock for getFilePointFromPopen(); */
    diskSpaceStatParce *pCurDiskSpaceStatParce = GetFileSystemInfo();  /* get output of "df -B 1" using mocking ; */
    TEST_ASSERT_EQUAL_STRING(pDiskSpaceStatParce->fileSystem[0].fileSystemName, pCurDiskSpaceStatParce->fileSystem[0].fileSystemName);
    TEST_ASSERT_EQUAL_MEMORY(&pDiskSpaceStatParce->fileSystem[0], &pCurDiskSpaceStatParce->fileSystem[0], sizeof(diskSpaceStat));
    free(pCurDiskSpaceStatParce);
}

