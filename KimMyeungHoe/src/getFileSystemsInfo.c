#include "getFileSystemsInfo.h"

#include "getFilePointFromPopen.h"


diskSpaceStatParce *getFileSystemsInfo(void)
{
    diskSpaceStatParce *pDiskSpaceStatParce = (diskSpaceStatParce*)malloc(sizeof(diskSpaceStatParce));
    char outputFromDfCommandBuffer[BUFF_SIZE] = {}; // temp buffer for fgets()
    char *pStrtok = NULL;  // pointer of strtok() 
    FILE *pfPopen = NULL; // File pointer of popen();

    pfPopen = getFilePointFromPopen("df -B 1");
    if (pfPopen == NULL)
        return NULL;

    while (fgets(outputFromDfCommandBuffer, BUFF_SIZE, pfPopen)) // read from fpPopen and save it as buffer 
    {
        if(pDiskSpaceStatParce->listCount == 0){
            pDiskSpaceStatParce->listCount++;
            continue;
        }         
        pStrtok = strtok(outputFromDfCommandBuffer, " ");  // split a string with empty space
        strcpy(pDiskSpaceStatParce->fileSystem[pDiskSpaceStatParce->listCount-1].fileSystemName, pStrtok); // string copy
        pStrtok = strtok(NULL, " ");
        strcpy(pDiskSpaceStatParce->fileSystem[pDiskSpaceStatParce->listCount-1].blockSize, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(pDiskSpaceStatParce->fileSystem[pDiskSpaceStatParce->listCount-1].used, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(pDiskSpaceStatParce->fileSystem[pDiskSpaceStatParce->listCount-1].avalable, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(pDiskSpaceStatParce->fileSystem[pDiskSpaceStatParce->listCount-1].usedPercent, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(pDiskSpaceStatParce->fileSystem[pDiskSpaceStatParce->listCount-1].mountOn, pStrtok);                        
    }		

    pclose(pfPopen);
    return pDiskSpaceStatParce;
}

