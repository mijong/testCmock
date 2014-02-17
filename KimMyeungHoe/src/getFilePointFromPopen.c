#include "getFilePointFromPopen.h"

FILE *getFilePointFromPopen(char *pInputCommand)
{
    FILE *pfPopen = NULL; // File pointer of popen();
    pfPopen = popen(pInputCommand, "r");  // excute a command 

    if (pfPopen == NULL)
    {
        printf("Error: open popen(): %s\n",strerror(errno));
        return NULL;
    }
    return pfPopen;
}
