/* 包含头文件 */
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
			MessageBoxA(NULL, "程序未能读取文件\n请确认当前目录或桌面下是否存在" FILE_NAME, "错误", MB_OK);
			exit(0);
		}
		else
		{
			printf("%s读取成功\n", DESKFILE_NAME);
			while (fgets(temp, STR_LEN, fp) != NULL && length < MAXROW)
			{
				// 处理末尾的换行符
				temp[strcspn(temp, "\r\n")] = 0;

				// 检查该行数据是否有效
				if (temp[0] == '\0' || strstr(temp, "当前共有"))
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
		printf("%s读取成功\n", FILE_NAME);
		while (fgets(temp, STR_LEN, fp) != NULL && length < MAXROW)
		{
			// 处理末尾的换行符
			temp[strcspn(temp, "\r\n")] = 0;

			// 检查该行数据是否有效
			if (temp[0] == '\0' || strstr(temp, "当前共有"))
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
	printf("%s", "正在加载");
	for (int i = 0; i < 6; i++)
	{
		printf(".");
		Sleep(500);
	}

	return length;
}
