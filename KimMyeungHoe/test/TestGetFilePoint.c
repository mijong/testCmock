#include "unity.h"
#include "GetFilePoint.h"

char *outputDf;

void setUp(void)
{
    outputDf = "df (GNU coreutils) 8.13\n\
Copyright (C) 2011 Free Software Foundation, Inc.\n\
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\
\n\
Written by Torbjörn Granlund, David MacKenzie, and Paul Eggert.\n";
}

void tearDown(void)
{

}

void test_GetFilePoint(void)
{
    char buffReadFile[2000];
    memset(buffReadFile, 0, 2000);
    int len;

    len = fread(buffReadFile, 2000, 2000, GetFilePoint("df --version"));
    buffReadFile[strlen(buffReadFile) - 1] = '\0';
    TEST_ASSERT_EQUAL_STRING(outputDf, buffReadFile);

}
