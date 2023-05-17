/* ---------------------------------- 包含头文件 --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"
#include "..\inc\input.h"

int Query(Telinf tel[], int length)
{
    system("cls");
    char keyword[MAX_QQ] = {0}; // 关键字
    int count = 1;                      // 序号
    int flag = 1;                       // 标志位

    printf("请输入你要查询的关键字: ");
    s_scanf(keyword, MAX_QQ);

    printf("   \t%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[0].name, tel[0].sex, tel[0].tel_phone, tel[0].mobile, tel[0].QQ, tel[0].age);

    for (int i = 1; i <= length; i++)
    {
        if (strstr(tel[i].name, keyword) != NULL ||
            strstr(tel[i].sex, keyword) != NULL ||
            strstr(tel[i].tel_phone, keyword) != NULL ||
            strstr(tel[i].mobile, keyword) != NULL ||
            strstr(tel[i].QQ, keyword) != NULL ||
            strstr(tel[i].age, keyword) != NULL)
        {
            printf("%-3d\t", count++);
            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].QQ, tel[i].age);
        }

    }

    if (count == 1)
    {
        system("cls");
        printf("没有找到相关信息\n");
    }

    return count;
}
