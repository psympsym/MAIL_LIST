/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

/**
* @brief 从键盘输入长度为length - 1的字符串
* @param str 写入字符串
* @param length 字符串长度
* @return char* 字符串
*/
char *s_scanf(char *str, int length)
{
    char *temp = NULL;
    int i = 0;

    temp = fgets(str, length, stdin);

    if (temp)
    {
        while (str[i] != '\n' && str[i] != '\0')
        {
            i++;
        }
        if (str[i] == '\n')
            str[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return temp;
}