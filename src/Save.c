/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

void save(char *FILE_NAME, Telinf tel[], int length)
{
	printf("���ڱ�����...\n");
	FILE* fp = NULL;

	if (GetFileAttributes(FILE_NAME) == INVALID_FILE_ATTRIBUTES)
	{
        printf("���ݱ���ʧ��...\n");
        printf("ԭ��������ļ�������...\n");
        printf("�����Ƿ����%s�ļ�...\n", FILE_NAME);
	}
	else
	{
		fp = fopen(FILE_NAME, "w");

		printf("%s�򿪳ɹ�\n", FILE_NAME);

		for (int i = 0; i < length; i++)
		{
			fprintf(fp, "%-10s %-4s %-16s %-16s %-16s %-4s\n",
				tel[i].name, tel[i].sex, tel[i].tel_phone,
				tel[i].mobile, tel[i].QQ, tel[i].age);
		}

		fprintf(fp, "��ǰ����%d������\n", length - 1);
		printf("%d�����ݱ���ɹ�...\n", length - 1);

		fclose(fp);
	}
}