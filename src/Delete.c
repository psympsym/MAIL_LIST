/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"
#include "..\inc\Bool.h"

/**
 * @brief ɾ��һ����¼
 * @param tel[] ͨѶ¼�ṹ������
 * @param length ͨѶ¼�ṹ������ʵ�ʳ���
 * @return int �����ͨѶ¼�ṹ������ʵ�ʳ���
*/
int delete(Telinf tel[], int length)
{
    system("cls");

    char mdy_name[MAX_NAME] = { 0 }; // Ҫɾ��������
    
    int flag = 0;

    printf("��������Ҫɾ��������\n");
    s_scanf(mdy_name, MAX_NAME);
    for (int i = 0; i <= length; i++)
    {
        if (strstr(tel[i].name, mdy_name) != NULL)
        {
			flag = 1;
            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].tel_office, tel[i].age);
            printf("�����Ҫɾ����(Y/N)\n");
            if (bool())
            {
				for (int j = i; j <= length; j++)
				{
					strcpy(tel[j].age, tel[j + 1].age);
					strcpy(tel[j].mobile, tel[j + 1].mobile);
					strcpy(tel[j].name, tel[j + 1].name);
					strcpy(tel[j].sex, tel[j + 1].sex);
					strcpy(tel[j].tel_office, tel[j + 1].tel_office);
					strcpy(tel[j].tel_phone, tel[j + 1].tel_phone);
				}
				printf("ɾ���ɹ�, ������������ز˵�\n");
				length--;
				break;
            }
            else
            {
                ;
            }
        }
    }

    if (flag == 0)
    {
        printf("û���ҵ�����ϵ��\n");
    }

    return length;
}