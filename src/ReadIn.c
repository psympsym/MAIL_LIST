/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

#define STR_LEN MAX_NAME + MAX_SEX + MAX_TEL_PHONE + MAX_MOBILE + MAX_TEL_OFFICE + MAX_AGE+1

int ReadIn(Telinf tel[], int length)
{
	FILE* fp = NULL;

	char temp[STR_LEN] = { 0 };

	fp = fopen(FILE_NAME, "r");

	if (fp == NULL)
	{
		fp = fopen(DESKFILE_NAME, "r");
		if (fp == NULL)
		{
    		Beep(600, 400);
			MessageBoxA(NULL, "����δ�ܶ�ȡ�ļ�\n��ȷ�ϵ�ǰĿ¼���������Ƿ����" FILE_NAME, "����", MB_OK);
			exit(0);
		}
		else
		{
			printf("%s��ȡ�ɹ�\n", DESKFILE_NAME);
			while (fgets(temp, STR_LEN, fp) != NULL && length < MAXROW)
			{
				// ����ĩβ�Ļ��з�
				temp[strcspn(temp, "\r\n")] = 0;

				// �����������Ƿ���Ч
				if (temp[0] == '\0' || strstr(temp, "��ǰ����"))
				{
					continue;
				}

				char* tp = temp;
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

				strncpy(tel[length].tel_office, tp, MAX_TEL_OFFICE);
				tel[length].tel_office[MAX_TEL_OFFICE - 1] = '\0';
				tp += MAX_TEL_OFFICE;

				strncpy(tel[length].age, tp, MAX_AGE);
				tel[length].age[MAX_AGE - 1] = '\0';
				length++;
			}
			fclose(fp);
		}
	}
	else
	{
		printf("%s��ȡ�ɹ�\n", FILE_NAME);
		while (fgets(temp, STR_LEN, fp) != NULL && length < MAXROW)
		{
			// ����ĩβ�Ļ��з�
			temp[strcspn(temp, "\r\n")] = 0;

			// �����������Ƿ���Ч
			if (temp[0] == '\0' || strstr(temp, "��ǰ����"))
			{
				continue;
			}

			char* tp = temp;
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

			strncpy(tel[length].tel_office, tp, MAX_TEL_OFFICE);
			tel[length].tel_office[MAX_TEL_OFFICE - 1] = '\0';
			tp += MAX_TEL_OFFICE;

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
		Sleep(500);
	}

	return length;
}
