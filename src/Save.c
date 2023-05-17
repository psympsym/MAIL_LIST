/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

void save(char *FILE_NAME, Telinf tel[], int length)
{
	printf("正在保存中...\n");
	FILE* fp = NULL;

	if (GetFileAttributes(FILE_NAME) == INVALID_FILE_ATTRIBUTES)
	{
        printf("数据保存失败...\n");
        printf("原因可能是文件不存在...\n");
        printf("请检查是否存在%s文件...\n", FILE_NAME);
	}
	else
	{
		fp = fopen(FILE_NAME, "w");

		printf("%s打开成功\n", FILE_NAME);

		for (int i = 0; i < length; i++)
		{
			fprintf(fp, "%-10s %-4s %-16s %-16s %-16s %-4s\n",
				tel[i].name, tel[i].sex, tel[i].tel_phone,
				tel[i].mobile, tel[i].QQ, tel[i].age);
		}

		fprintf(fp, "当前共有%d条数据\n", length - 1);
		printf("%d条数据保存成功...\n", length - 1);

		fclose(fp);
	}
}