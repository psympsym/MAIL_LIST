/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"

/**
 * @brief ��ʾ���м�¼
 * @param tel[] ͨѶ¼�ṹ������
 * @param length ͨѶ¼�ṹ������ʵ�ʳ���
 * @return void
*/
void show(Telinf tel[], int length)
{
	system("cls");
    for (int i = 0; i < length; i++)
    {
        printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].QQ, tel[i].age);
    }
}
