/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

void save(Telinf tel[], int length)
{
	printf("正在保存中...\n");
	FILE* fp = NULL;

	if (GetFileAttributes(FILE_NAME) == INVALID_FILE_ATTRIBUTES)
	{
		fp = fopen(DESKFILE_NAME, "w");

		printf(FILE_NAME"打开成功\n");

		for (int i = 0; i < length; i++)
		{
			fprintf(fp, "%-10s %-4s %-16s %-16s %-16s %-4s\n",
				tel[i].name, tel[i].sex, tel[i].tel_phone,
				tel[i].mobile, tel[i].tel_office, tel[i].age);
		}

		fprintf(fp, "当前共有%d条数据\n", length - 1);
		printf("%d条数据保存成功...\n", length - 1);

		fclose(fp);
		exit(0);
	}
	else
	{
		fp = fopen(FILE_NAME, "w");

		printf(FILE_NAME"打开成功\n");

		for (int i = 0; i < length; i++)
		{
			fprintf(fp, "%-10s %-4s %-16s %-16s %-16s %-4s\n",
				tel[i].name, tel[i].sex, tel[i].tel_phone,
				tel[i].mobile, tel[i].tel_office, tel[i].age);
		}

		fprintf(fp, "当前共有%d条数据\n", length - 1);
		printf("%d条数据保存成功...\n", length - 1);

		fclose(fp);
		exit(0);
	}
}