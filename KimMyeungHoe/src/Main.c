#include "GetFileSystemInfo.h"

void main(void)
{
    if (GetFileSystemInfo() == NULL) {
        printf("failed to get a infomation of filesystem\n");
    }
}
