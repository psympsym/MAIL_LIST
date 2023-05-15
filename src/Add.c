/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"

/**
 * @brief 添加一条记录
 * @param tel[] 通讯录结构体数组
 * @param length 通讯录结构体数组实际长度
 * @return int 处理后通讯录结构体数组实际长度
 */
int add(Telinf tel[], int length)
{
    system("cls");
    
    if (length >= MAXROW)
    {
        printf("通讯录已满，无法添加新的记录\n");
    }
    else
    {
        printf("请输入姓名：");
        s_scanf(tel[length].name, MAX_NAME);
        printf("请输入性别：");
        s_scanf(tel[length].sex, MAX_SEX);
        printf("请输入家庭电话：");
        s_scanf(tel[length].tel_phone, MAX_TEL_PHONE);
        printf("请输入移动电话：");
        s_scanf(tel[length].mobile, MAX_MOBILE);
        printf("请输入办公电话：");
        s_scanf(tel[length].tel_office, MAX_TEL_OFFICE);
        printf("请输入年龄：");
        s_scanf(tel[length].age, MAX_AGE);

        length++;
        printf("添加成功, 按下任意键返回菜单\n");
    }

    return length;
}
