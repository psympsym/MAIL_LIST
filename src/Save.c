/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

void save(Telinf tel[], int length)
{
	printf("���ڱ�����...\n");
	FILE* fp = NULL;

	if (GetFileAttributes(FILE_NAME) == INVALID_FILE_ATTRIBUTES)
	{
		fp = fopen(DESKFILE_NAME, "w");

		printf(FILE_NAME"�򿪳ɹ�\n");

		for (int i = 0; i < length; i++)
		{
			fprintf(fp, "%-10s %-4s %-16s %-16s %-16s %-4s\n",
				tel[i].name, tel[i].sex, tel[i].tel_phone,
				tel[i].mobile, tel[i].tel_office, tel[i].age);
		}

		fprintf(fp, "��ǰ����%d������\n", length - 1);
		printf("%d�����ݱ���ɹ�...\n", length - 1);

		fclose(fp);
		exit(0);
	}
	else
	{
		fp = fopen(FILE_NAME, "w");

		printf(FILE_NAME"�򿪳ɹ�\n");

		for (int i = 0; i < length; i++)
		{
			fprintf(fp, "%-10s %-4s %-16s %-16s %-16s %-4s\n",
				tel[i].name, tel[i].sex, tel[i].tel_phone,
				tel[i].mobile, tel[i].tel_office, tel[i].age);
		}

		fprintf(fp, "��ǰ����%d������\n", length - 1);
		printf("%d�����ݱ���ɹ�...\n", length - 1);

		fclose(fp);
		exit(0);
	}
}