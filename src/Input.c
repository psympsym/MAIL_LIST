/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

/**
* @brief �Ӽ������볤��Ϊlength - 1���ַ���
* @param str д���ַ���
* @param length �ַ�������
* @return char* �ַ���
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