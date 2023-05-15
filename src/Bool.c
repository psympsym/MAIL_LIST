/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Input.h"

int bool()
{
    char flag[2] = { 0 };

    while (s_scanf(flag, 2) && strcmp(flag, "Y") && strcmp(flag, "y") && strcmp(flag, "N") && strcmp(flag, "n"))
    {
        printf("输入错误，请重新输入\n");
    }

    if (!strcmp(flag, "Y") || !strcmp(flag, "y"))
        return 1;
    else if (!strcmp(flag, "N") || !strcmp(flag, "n"))
        return 0;
}