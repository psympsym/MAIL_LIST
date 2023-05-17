/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"
/* ----------------------------------- �궨�� ---------------------------------- */
#define STR_LEN MAX_NAME + MAX_SEX + MAX_TEL_PHONE + MAX_MOBILE + MAX_QQ + MAX_AGE + 1  // ��ȡ�ļ�����������󳤶�

int ReadIn(char *FILE_NAME, Telinf tel[], int length)
{
    // ����ָ��򿪵��ļ�ָ��
    FILE *fp = NULL;
    // �������ʾ�Ĵ�����Ϣ
    char errMsg[100];
    // ������ʱ�ַ�������, ���һ������
    char temp[STR_LEN] = {0};

    fp = fopen(FILE_NAME, "r");

    // ����ǰĿ¼�²�����FILE_NAME, �򴴽�FILE_NAME
    if (fp == NULL)
    {
        fp = fopen(FILE_NAME, "w+");
    }
    else
    {
        // ���ļ����ݶ���ṹ������
        printf("%s��ȡ�ɹ�\n", FILE_NAME);
        // ���ļ�ָ�������ļ���ͷ
        rewind(fp);
        while (fgets(temp, STR_LEN, fp) != NULL && length < MAXROW)
        {
            // ����ĩβ�Ļ��з�
            temp[strcspn(temp, "\r\n")] = 0;

            // �����������Ƿ���Ч
            if (temp[0] == '\0' || strstr(temp, "��ǰ����"))
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
    printf("%s", "���ڼ���");
    for (int i = 0; i < 6; i++)
    {
        printf(".");
        Sleep(250);
    }

    return length;
}
