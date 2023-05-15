/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"
#include "..\inc\Add.h"
#include "..\inc\Bool.h"

/**
 * @brief 修改一条记录
 * @param tel[] 通讯录结构体数组
 * @param length 通讯录结构体数组实际长度
 * @return void
 */
void update(Telinf tel[], int length)
{
    system("cls");

    char name[MAX_NAME] = {0};

    printf("请输入你要修改的姓名\n");
    s_scanf(name, MAX_NAME);
    int flag = 0;

    for (int i = 0; i <= length; i++)
    {
        if (strstr(tel[i].name, name) != NULL)
        {
            flag = 1;

            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].tel_office, tel[i].age); // 显示信息

            printf("请输入要修改的姓名：");
            s_scanf(tel[i].name, MAX_NAME);
            printf("请输入要修改的性别：");
            s_scanf(tel[i].sex, MAX_SEX);
            printf("请输入要修改的家庭电话：");
            s_scanf(tel[i].tel_phone, MAX_TEL_PHONE);
            printf("请输入要修改的移动电话：");
            s_scanf(tel[i].mobile, MAX_MOBILE);
            printf("请输入要修改的办公电话：");
            s_scanf(tel[i].tel_office, MAX_TEL_OFFICE);
            printf("请输入要修改的年龄：");
            s_scanf(tel[i].age, MAX_AGE);

            break;
        }
    }
    
    if (flag == 0)
    {
        printf("没有找到该联系人\n");
        printf("是否添加该联系人(Y/N)？\n");
        if (bool())
        {
            add(tel, length);
        }
        else
        {
            ;
        }
    }
    else
    {
        printf("添加成功, 按下任意键返回菜单\n");
    }
}
