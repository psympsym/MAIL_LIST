/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"

/**
 * @brief 查询一条记录
 * @param tel[] 通讯录结构体数组
 * @param length 通讯录结构体数组实际长度
 * @return void
*/
void search(Telinf tel[], int length)
{
    char name[MAX_NAME];
    int flag = 0;

    printf("请输入你要查询的姓名\n");
    s_scanf(name, MAX_NAME);
    system("cls");
    
    for (int i = 0; i < length; i++)
    {
        if (strstr(tel[i].name, name) != NULL)
        {
            if (flag == 0)
            {
                printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[0].name, tel[0].sex, tel[0].tel_phone, tel[0].mobile, tel[0].QQ, tel[0].QQ);
            }

            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].QQ, tel[i].age);

            flag = 1;
        }
    }
    if (!flag)
    {
        system("cls");
        printf("没有找到相关信息\n");
    }
}
