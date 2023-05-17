/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"
/* ----------------------------------- 宏定义 ---------------------------------- */
#define STR_LEN MAX_NAME + MAX_SEX + MAX_TEL_PHONE + MAX_MOBILE + MAX_QQ + MAX_AGE + 1  // 读取文件单行数据最大长度

int ReadIn(char *FILE_NAME, Telinf tel[], int length)
{
    // 定义指向打开的文件指针
    FILE *fp = NULL;
    // 构造待显示的错误信息
    char errMsg[100];
    // 定义临时字符串数组, 存放一行数据
    char temp[STR_LEN] = {0};

    fp = fopen(FILE_NAME, "r");

    // 若当前目录下不存在FILE_NAME, 则创建FILE_NAME
    if (fp == NULL)
    {
        fp = fopen(FILE_NAME, "w+");
    }
    else
    {
        // 将文件数据读入结构体数组
        printf("%s读取成功\n", FILE_NAME);
        // 将文件指针移向文件开头
        rewind(fp);
        while (fgets(temp, STR_LEN, fp) != NULL && length < MAXROW)
        {
            // 处理末尾的换行符
            temp[strcspn(temp, "\r\n")] = 0;

            // 检查该行数据是否有效
            if (temp[0] == '\0' || strstr(temp, "当前共有"))
            {
                continue;
            }

            char *tp = temp;
            strncpy(tel[length].name, tp, MAX_NAME);
            tel[length].name[MAX_NAME - 1] = '\0';
            tp += MAX_NAME;

            strncpy(tel[length].sex, tp, MAX_SEX);
            tel[length].sex[MAX_SEX - 1] = '\0';
            tp += MAX_SEX;

            strncpy(tel[length].tel_phone, tp, MAX_TEL_PHONE);
            tel[length].tel_phone[MAX_TEL_PHONE - 1] = '\0';
            tp += MAX_TEL_PHONE;

            strncpy(tel[length].mobile, tp, MAX_MOBILE);
            tel[length].mobile[MAX_MOBILE - 1] = '\0';
            tp += MAX_MOBILE;

            strncpy(tel[length].QQ, tp, MAX_QQ);
            tel[length].QQ[MAX_QQ - 1] = '\0';
            tp += MAX_QQ;

            strncpy(tel[length].age, tp, MAX_AGE);
            tel[length].age[MAX_AGE - 1] = '\0';
            length++;
        }
        fclose(fp);
    }
    printf("%s", "正在加载");
    for (int i = 0; i < 6; i++)
    {
        printf(".");
        Sleep(250);
    }

    return length;
}
