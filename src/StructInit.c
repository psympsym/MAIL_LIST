/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"

/**
 * @brief 初始化结构体
 * @param tel[] 通讯录结构体数组
 * @param length 通讯录长度
 * @return int 通讯录长度
 * @note 将结构体第一项初始化为标签
*/
void StructInit(Telinf tel[]) // 初始化结构体
{
    strcpy(tel[0].name, "姓名");
    strcpy(tel[0].sex, "性别");
    strcpy(tel[0].tel_phone, "家庭电话");
    strcpy(tel[0].mobile, "移动电话");
    strcpy(tel[0].tel_office, "工作电话");
    strcpy(tel[0].age, "年龄");
}